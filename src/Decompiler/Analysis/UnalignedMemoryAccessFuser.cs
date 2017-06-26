﻿#region License
/* 
 * Copyright (C) 1999-2017 John Källén.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#endregion

using Reko.Core;
using Reko.Core.Code;
using Reko.Core.Expressions;
using Reko.Core.Operators;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Reko.Analysis
{
    /// <summary>
    /// Fuses pairs of unaligned loads or stores.
    /// </summary>
    public class UnalignedMemoryAccessFuser
    {
        private SsaState ssa;

        public UnalignedMemoryAccessFuser(SsaState ssa)
        {
            this.ssa = ssa;
        }

        // On MIPS-LE the sequence
        //   lwl rx,K+3(ry)
        //   lwr rx,K(ry)
        // is an unaligned read. On MIPS-BE it instead is:
        //   lwl rx,K(ry)
        //   lwr rx,K+3(ry)
        public void FuseUnalignedLoads(Assignment assR)
        {
            var regR = assR.Dst;
            var stmR = ssa.Identifiers[regR].DefStatement;

            var appR = MatchIntrinsicApplication(assR.Src, PseudoProcedure.LwR);
            if (appR == null)
                return;

            var memR = (MemoryAccess)appR.Arguments[1];
            var binR = (BinaryExpression)memR.EffectiveAddress;
            var offR = ((Constant)binR.Right).ToInt32();

            var appL = appR.Arguments[0] as Application;
            Statement stmL = null;
            Assignment assL = null;
            if (appL == null)
            {
                var regL = (Identifier)appR.Arguments[0];
                stmL = ssa.Identifiers[regL].DefStatement;
                if (stmL == null)
                    return;
                assL = stmL.Instruction as Assignment;
                if (assL == null)
                    return;

                appL = assL.Src as Application;
            }
            appL = MatchIntrinsicApplication(appL, PseudoProcedure.LwL);
            if (appL == null)
                return;

            var memL = (MemoryAccess)appL.Arguments[1];
            var binL = (BinaryExpression)memL.EffectiveAddress;
            var offL = ((Constant)binL.Right).ToInt32();

            if (binL.Operator != binR.Operator)
                return;
            if (binL.Operator == Operator.ISub)
            {
                offL = -offL;
                offR = -offR;
            }
            MemoryAccess mem;
            if (offR + 3 == offL)
            {
                // Little endian use
                mem = memR;
            }
            else if (offL + 3 == offR)
            {
                // Big endian use
                mem = memL;
            }
            else
                return;

            ssa.RemoveUses(stmL);
            ssa.RemoveUses(stmR);
            if (assL != null)
            {
                assL.Src = appL.Arguments[0];
                ssa.AddUses(stmL);
            }
            assR.Src = mem;
            ssa.AddUses(stmR);
        }


        // On MIPS-LE the sequence
        //   swl rx,K+3(ry)
        //   swr rx,K(ry)
        // is an unaligned store.
        public Instruction FuseUnalignedStores(SideEffect se)
        {
            var appR = MatchIntrinsicApplication(se.Expression, PseudoProcedure.SwR);
            if (appR == null)
                return se;
            var sidR = ssa.Identifiers[(Identifier)appR.Arguments[1]];
            Application appL = null;
            Statement stmL = null;
            Statement stmR = null;
            foreach (var use in sidR.Uses)
            {
                var s = use.Instruction as SideEffect;
                if (s == null)
                    continue;
                var app = MatchIntrinsicApplication(s.Expression, PseudoProcedure.SwR);
                if (app != null)
                {
                    appR = app;
                    stmR = use;
                }
                app = MatchIntrinsicApplication(s.Expression, PseudoProcedure.SwL);
                if (app != null)
                {
                    appL = app;
                    stmL = use;
                }
            }
            if (stmL == null || stmR == null)
                return se;

            var memL = appL.Arguments[0];
            var offL = GetOffsetOf(memL);

            var memR = appR.Arguments[0];
            var offR = GetOffsetOf(memR);

            Expression mem;
            if (offR + 3 == offL)
            {
                // Little endian use
                mem = memR;
            }
            else if (offL + 3 == offR)
            {
                // Big endian use
                mem = memL;
            }
            else
                return se;

            ssa.RemoveUses(stmL);
            ssa.RemoveUses(stmR);
            stmR.Instruction = mem is Identifier
                ? (Instruction)new Assignment((Identifier)mem, sidR.Identifier)
                : (Instruction)new Store(mem, sidR.Identifier);
            stmL.Block.Statements.Remove(stmL);
            ssa.AddUses(stmR);
            return stmR.Instruction;
        }

        private int GetOffsetOf(Expression e)
        {
            var id = e as Identifier;
            if (id != null)
            {
                var mem = id.Storage as StackStorage;
                return mem.StackOffset;
            }
            else
            {
                var mem = (MemoryAccess)e;
                var binL = (BinaryExpression)mem.EffectiveAddress;
                var off = ((Constant)binL.Right).ToInt32();
                return off;
            }
        }

        private Application MatchIntrinsicApplication(Expression e, string name)
        {
            var app = e as Application;
            if (app == null)
                return null;
            var pc = app.Procedure as ProcedureConstant;
            if (pc == null)
                return null;
            var ppp = pc.Procedure as PseudoProcedure;
            if (ppp == null)
                return null;
            if (ppp.Name != name)
                return null;
            return app;
        }
    }
}
