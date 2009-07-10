/* 
 * Copyright (C) 1999-2009 John K�ll�n.
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

using Decompiler.Core;
using Decompiler.Core.Code;
using Decompiler.Core.Lib;
using System;
using System.Diagnostics;
using System.IO;
using System.Collections.Generic;

namespace Decompiler.Structure
{
    internal enum travType
    {
        UNTRAVERSED,
        DFS_TAG,
        DFS_LNUM,
        DFS_RNUM,
        DFS_PDOM,
        DFS_CODEGEN,
    }

    public class StructureNode : GraphNode<StructureNode>
    {
        private Block block;
        private int id;
        private int ord;
        private int revOrd;

        internal travType traversed;          //$REFACTOR: use visited hashtables instead.
        public bool hllLabel;
        public string labelStr;

        private StructureNode immPDom;
        private StructureNode loopHead;
        private StructureNode caseHead;

        private StructureNode condFollow;
        private StructureNode loopFollow;
        private StructureNode latchNode;
        private structType sType;
        private UnstructuredType usType;
        private condType cType;
        private loopType lType;
        private IntNode interval;

        private int[] loopStamps;
        private int[] revLoopStamps;

        private bbType type;


        // constructor sets the identity as well as the member instructions
        public StructureNode(int id, List<Instruction> src, int first, int num)
        {
        }

        public StructureNode(Block block, int id)
        {
            if (block == null)
                throw new ArgumentNullException("block");
            this.block = block;
            this.id = id;

            ord = -1;
            revOrd = -1;

            traversed = travType.UNTRAVERSED;
            hllLabel = false;

            labelStr = null;
            immPDom = null;
            loopHead = null;
            caseHead = null;

            condFollow = null;
            loopFollow = null;
            latchNode = null;
            sType = structType.Seq;

            usType = UnstructuredType.Structured;
            interval = null;

            //initialize the two timestamp tuples
            loopStamps = new int[2];
            revLoopStamps = new int[2];
            for (int i = 0; i < 2; i++)
                loopStamps[i] = revLoopStamps[i] = -1;


            type = TypeOfBlock(block);
        }



                // Constructor used by the IntNode derived class
        protected StructureNode(int newId, bbType t)
        {
            id = newId; type = t;
        }

        // Add an edge from this node to dest. If this is a cBranch type of node and it already
        // has an edge to dest then node edge is added and the node type is changed to fall
        public void AddEdgeTo(StructureNode dest)
        {
            if (type != bbType.cBranch || !HasEdgeTo(dest))
                OutEdges.Add((StructureNode) (dest));      //$CAST
            else
                //reset the type to fall if no edge was added (i.e. this edge already existed)
                type = bbType.fall;
        }

        // Add an edge from src to this node if it doesn't already exist. NB: only interval
        // nodes need this routine as the in edges for normal nodes are built in SetLoopStamps
        public void AddEdgeFrom(StructureNode src)
        {
            if (!InEdges.Contains(src))
                InEdges.Add((StructureNode) (src));//$CAST
        }


        public Block Block
        {
            get { return block; }
        }

        public bbType BlockType
        {
            get { return type; }
        }

        public StructureNode CaseHead
        {
            get { return caseHead; }
            set { caseHead = value; }
        }

        /// <summary>
        /// The node that follows this conditional or loop.
        /// </summary>
        public StructureNode CondFollow
        {
            get { return condFollow; }
            set { condFollow = value; }
        }

        public condType CondType
        {
            get
            {
                return cType;
            }
            set
            {
                Debug.Assert(sType == structType.Cond || sType == structType.LoopCond);
                cType = value;
            }
        }

        // Do a DFS on the graph headed by this node, simply tagging the nodes visited.  //$move to GraphNode.
        public void DfsTag()
        {
            traversed = travType.DFS_TAG;
            for (int i = 0; i < OutEdges.Count; i++)
                if (OutEdges[i].traversed != travType.DFS_TAG)
                    OutEdges[i].DfsTag();
        }

        public StructureNode Then { get { return OutEdges[1]; } }

        public StructureNode Else { get { return OutEdges[0]; } }


        /// <summary>
        /// Returns true of this node has a back edge to <paramref name="dest"/>.
        /// </summary>
        /// <param name="dest">Node whose back-edgeness is to be tested.</param>
        /// <returns>True of <paramref name="dest"/> is reachable via a back edge from this node.</returns>
        public bool HasBackEdgeTo(StructureNode dest)
        {
            Debug.Assert(HasEdgeTo(dest) || dest == this);
            return (dest == this || dest.IsAncestorOf(this));
        }

        // Does this node have an edge to dest?
        public bool HasEdgeTo(StructureNode dest)
        {
            return OutEdges.Contains(dest);
        }


        public int Ident() { return id; }

        public StructureNode ImmPDom
        {
            get { return immPDom; }
            set { immPDom = value; }
        }


        public StatementList Instructions
        {
            get { return block.Statements; }
        }

        public IntNode Interval
        {
            get { return interval; }
            set { interval = value; }
        }

        // Is this node an ancestor of other?
        public bool IsAncestorOf(StructureNode other)
        {
            return ((loopStamps[0] < other.loopStamps[0] &&
                         loopStamps[1] > other.loopStamps[1]) ||
                        (revLoopStamps[0] < other.revLoopStamps[0] &&
                         revLoopStamps[1] > other.revLoopStamps[1]));
        }

        // Is this a latch node?
        public bool IsLatchNode()
        {
            return (loopHead != null && loopHead.latchNode == this);
        }


        // The latch node of a loop header
        public StructureNode LatchNode
        {
            get { return latchNode; }
            set { latchNode = value; }
        }


        public StructureNode LoopFollow
        {
            get { return loopFollow; }
            set { loopFollow = value; }
        }

        ///<summary>The header of the innermost loop this node belongs to.</summary>
        public StructureNode LoopHead
        {
            get { return loopHead; }
            set { loopHead = value; }
        }

        // Pre: the structured class of the node must be Loop or LoopCond
        // Set the loop type of this loop header node
        public void SetLoopType(loopType l)
        {
            Debug.Assert(sType == structType.Loop || sType == structType.LoopCond);
            lType = l;

            //set the structured class (back to) just Loop if the loop type is PreTested OR
            //it's PostTested and is a single block loop
            if (lType == loopType.PreTested || (lType == loopType.PostTested && this == latchNode))
                sType = structType.Loop;
        }

        // Do a DFS on the graph headed by this node, giving each node it's time stamp tuple
        // that will be used for loop structuring as well as building the structure that will
        // be used for traversing the nodes in linear time. The inedges are also built during
        // this traversal.
        public void SetLoopStamps(ref int time, List<StructureNode> order)
        {
            //timestamp the current node with the current time and set its traversed flag
            traversed = travType.DFS_LNUM;
            loopStamps[0] = time;

            //recurse on unvisited children and set inedges for all children
            for (int i = 0; i < OutEdges.Count; i++)
            {
                // set the in edge from this child to its parent (the current node)
                OutEdges[i].InEdges.Add(this);

                // recurse on this child if it hasn't already been visited
                if (OutEdges[i].traversed != travType.DFS_LNUM)
                {
                    ++time;
                    OutEdges[i].SetLoopStamps(ref time, order);
                }
            }

            //set the the second loopStamp value
            loopStamps[1] = ++time;

            //add this node to the ordering structure as well as recording its position within the ordering
            ord = order.Count;
            order.Add(this);
        }


        // This sets the reverse loop stamps for each node. The children are traversed in
        // reverse order.
        public void SetRevLoopStamps(ref int time)
        {
            //timestamp the current node with the current time and set its traversed flag
            traversed = travType.DFS_RNUM;
            revLoopStamps[0] = time;

            //recurse on the unvisited children in reverse order
            for (int i = OutEdges.Count - 1; i >= 0; i--)
            {
                // recurse on this child if it hasn't already been visited
                if (OutEdges[i].traversed != travType.DFS_RNUM)
                {
                    ++time;
                    OutEdges[i].SetRevLoopStamps(ref time);
                }
            }

            //set the the second loopStamp value
            revLoopStamps[1] = ++time;
        }

        // Build the ordering of the nodes in the reverse graph that will be used to
        // determine the immediate post dominators for each node
        public void SetRevOrder(List<StructureNode> order)
        {
            // Set this node as having been traversed during the post domimator 
            // DFS ordering traversal
            traversed = travType.DFS_PDOM;

            // recurse on unvisited children 
            for (int i = 0; i < InEdges.Count; i++)
                if (InEdges[i].traversed != travType.DFS_PDOM)
                    InEdges[i].SetRevOrder(order);

            // add this node to the ordering structure and record the post dom. order
            // of this node as its index within this ordering structure
            revOrd = order.Count;
            order.Add(this);
        }



        // Pre: this node must be a loop header and its loop type must be already set.
        // Return the loop type of this node
        public loopType GetLoopType()
        {
            Debug.Assert(sType == structType.Loop || sType == structType.LoopCond);
            return lType;
        }


        // Return the index of this node within the ordering array
        public int Order
        {
            get
            {
                Debug.Assert(ord != -1);
                return ord;
            }
            set { ord = value; }
        }

        // Return the index of this node within the post dominator ordering array
        public int RevOrder
        {
            get
            {
                Debug.Assert(revOrd != -1);
                return revOrd;
            }
            set { revOrd = value; }
        }


        // Return the structured type of this node
        public structType GetStructType() { return sType; }

        // Pre: if this is to be a cond type then the follow (if any) must have 
        // already been determined for this node
        // Set the class of structure determined for this node. 
        public void SetStructType(structType s)
        {
            // if this is a conditional header, determine exactly which type of 
            // conditional header it is (i.e. switch, if-then, if-then-else etc.)
            if (s == structType.Cond)
            {
                if (type == bbType.nway)
                    cType = condType.Case;
                else if (Else == condFollow)
                    cType = condType.IfThen;
                else if (Then == condFollow)
                    cType = condType.IfElse;
                else
                    cType = condType.IfThenElse;
            }

            sType = s;
        }

        private bbType TypeOfBlock(Block block)
        {
            Statement stm = block.Statements.Last;
            if (stm == null)
                return bbType.fall;
            Instruction i = stm.Instruction;
            if (i is Branch)
                return bbType.cBranch;
            if (i is SwitchInstruction)
                return bbType.nway;
            if (i is ReturnInstruction)
                return bbType.ret;
            return bbType.fall;
        }

        public UnstructuredType UnstructType
        {
            get { return usType; }
            set
            {
                Debug.Assert((sType == structType.Cond || sType == structType.LoopCond) && cType != condType.Case);
                usType = value;
            }
        }


        public virtual void Write(TextWriter tw)
        {
            tw.Write(Ident());
            if (Block != null)
            {
                tw.Write(" ({0})", Block.Name);
            }
        }

        public virtual string Name
        {
            get { return block.Name; }
        }
    }


    // an enumerated type for the type of loop headers
    public class loopType
    {
        public static loopType PreTested = new loopType();				// Header of a while loop
        public static loopType PostTested = new loopType();			// Header of a repeat loop
        public static loopType Endless = new loopType(); // Header of an endless loop
    }

    // an type for the class of unstructured conditional jumps
    public enum unstructType
    {
        Structured,
        JumpInOutLoop,
        JumpIntoCase
    }


    // an enumerated type for the type of conditional headers
    public enum condType
    {
        IfThen,				// conditional with only a then clause
        IfThenElse,			// conditional with a then and an else clause
        IfElse,				// conditional with only an else clause
        Case				// bbType.nway conditional header (case statement)
    }

    public enum bbType
    {
        none,
        cBranch,
        fall,
        nway,
        uBranch,
        ret,
        intNode
    }

    public enum structType
    {
        Seq,
        Cond,
        Loop,
        LoopCond,
    }

    public enum UnstructuredType
    {
        None,
        Structured,
        JumpInOutLoop,
        JumpIntoCase
    }
}
