// spcinv.c
// Generated by decompiling spcinv.sav
// using Reko decompiler version 0.6.2.0.

#include "spcinv.h"

void fn0200(word16 r4, Eq_3 * pc)
{
	do
	{
		PRINT(&globals->b0F9A);
		ptr16 sp_104 = fp;
		ptr16 r2_103 = 0x02;
		do
		{
			word16 r0_14;
		} while (TTYIN(out r0_14));
		ptr16 r1_152 = 3994;
		do
		{
			word16 r0_19;
		} while (TTYIN(out r0_19));
		do
		{
			word16 r0_21;
		} while (TTYIN(out r0_21));
		if (0xF0A8 == 0x00)
		{
			PRINT(&globals->b0FDA);
			do
			{
				word16 r0_376;
			} while (TTYIN(out r0_376));
			break;
		}
		r2_103 = 0x01;
		if (~0x0F50 == 0x00)
			break;
		r2_103 = 0x00;
	} while (61611 == 0x00);
	*&globals->w0244 = *&globals->w0244;
	*&globals->w0248 = *&globals->w0248;
	*&globals->w0024 = *&globals->w0024 | 0x1040;
	globals->w1166 = 0x1100;
	globals->w1168 = 4464;
	FnSubfn(&globals->w1166);
	*&globals->w0264 = *&globals->w0264;
	*&globals->w0268 = *&globals->w0268;
	globals->w1166 = 0x0101;
	globals->w1168 = 4446;
	FnSubfn(&globals->w1166);
	*&globals->w0244 = *&globals->w0244;
	*&globals->w0248 = *&globals->w0248;
	*&globals->w0024 = *&globals->w0024 | 0x1040;
	globals->w1166 = 0x1100;
	globals->w1168 = 4464;
	FnSubfn(&globals->w1166);
	*&globals->w0264 = *&globals->w0264;
	*&globals->w0268 = *&globals->w0268;
	globals->w1166 = 0x0101;
	globals->w1168 = 4446;
	FnSubfn(&globals->w1166);
	if (true)
	{
		globals->w1166 = 0x0801;
		globals->w1168 = 0x00;
		globals->w116A = 0x0B5E;
		globals->w116C = 0x01;
		globals->w116E = 0x00;
		FnSubfn(&globals->w1166);
		__syscall(0x88FC);
		globals->w1166 = 0x0801;
		globals->w1168 = 0x00;
		globals->w116A = 0x0B5E;
		globals->w116C = 0x01;
		globals->w116E = 0x00;
		FnSubfn(&globals->w1166);
		__syscall(0x88FC);
	}
	fn0BD4();
l02A0:
	fn0C1E();
l02A6:
	word16 r0_105;
	if (!TTYIN(out r0_105) && *(&globals->ptr0EFA) == 0x00)
	{
		*&globals->b02B4 = *&globals->b02B4;
		word16 * r1_319 = &globals->w02C6;
		do
		{
			r1_319 = r1_378 + 0x01;
			word16 * r1_378 = r1_319;
		} while (*r1_378 - r0_105 != 0x00);
		struct Eq_250 * r1_329 = r1_319 - 711 << 0x01;
		word16 sp_331;
		word16 r2_332;
		byte NZ_333;
		bool V_334;
		word16 r3_335;
		bool C_336;
		bool N_337;
		bool Z_338;
		word16 r0_339;
		word16 r1_340;
		byte NZVC_341;
		byte NZV_342;
		word16 pc_343;
		word16 r4_344;
		byte ZC_345;
		r1_329->ptr02CC();
		return;
	}
	globals->w1166 = 0x1100;
	globals->w1168 = 4464;
	FnSubfn(&globals->w1166);
	ci16 r0_115 = *&globals->w1170 - *(&globals->w1172);
	if (r0_115 < 0x00)
	{
		if (0x1178 - r4 == 0x00)
			goto l02A6;
		fn0AF4(wArg00);
	}
	*&globals->w031C = *&globals->w031C;
	pc->w0E52 = pc->w0E52 + 0x01;
	word16 v64_138 = ~*&globals->w0326;
	*&globals->w0326 = v64_138;
	if (v64_138 == 0x00)
		*&globals->w032C = ~*&globals->w032C;
	if (*&globals->ptr0EFA != 0x00)
	{
		word16 v70_284 = *&globals->w0336 - 0x01;
		*&globals->w0336 = v70_284;
		if (v70_284 != 0x00)
			goto l0370;
		if (*&globals->w0F18 == 0x00)
			goto l03AE;
		fn0484();
		*&globals->w0348 = *&globals->w0348;
		fn046E(r2_103, r4);
		*&globals->w0352 = *&globals->w0352;
		sp_104 = sp_104 + ~0x01;
	}
	if (*&globals->w0EF8 != 0x00)
	{
l036C:
		byte NZ_261;
		bool V_262;
		word16 r3_263;
		bool C_264;
		bool N_265;
		bool Z_266;
		word16 r0_267;
		byte NZVC_269;
		byte NZV_270;
		byte ZC_273;
		globals->ptr0EFA();
		goto l0370;
	}
	else
	{
		if (0x08 - *(&globals->w0F14) < 0x00)
		{
			ci16 v106_277 = *&globals->w0364 - 0x01;
			*&globals->w0364 = v106_277;
			if (v106_277 <= 0x00)
			{
				*&globals->w036C = *&globals->w036C;
				goto l036C;
			}
		}
l0370:
		fn049E();
		fn06D4();
		fn07A4();
		fn0996();
		if (0x1178 - r4 != 0x00)
			break;
		if (*&globals->w0F12 != 0x00)
			continue;
		if (*&globals->w0F02 != 0x00)
			continue;
		if (true)
		{
			*&globals->w03AA = *&globals->w03AA + 0x01;
			goto l02A0;
		}
l03AE:
		cu16 v82_157 = *&globals->w0B5A - *(&globals->w0B5A);
		if (v82_157 > 0x00)
		{
			*&globals->w03BC = *&globals->w03BC;
			globals->w1166 = 0x0101;
			globals->w1168 = 4446;
			FnSubfn(&globals->w1166);
			if (v82_157 >= 0x00)
			{
l03E6:
				globals->w1166 = 0x0901;
				globals->w1168 = 0x00;
				globals->w116A = 0x0B5E;
				globals->w116C = 0x01;
				globals->w116E = 0x00;
				FnSubfn(&globals->w1166);
				__syscall(0x88FC);
				goto l040A;
			}
			globals->w1166 = 0x0201;
			globals->w1168 = 4446;
			globals->w116A = 0x01;
			FnSubfn(&globals->w1166);
			if (v82_157 >= 0x00)
				goto l03E6;
		}
l040A:
		fn0484();
		struct Eq_407 * sp_173 = sp_104 - 0x01;
		sp_173->b0000 = 0x01;
		sp_173->b0001 = 0x18;
		fn0AB4();
		fn0AE6();
		*(r1_152 - 0x02) = r4;
		fn0AE6();
	}
}

void fn046E(ptr16 r2, word16 r4)
{
	fn0AB4();
	fn0AE6();
	*(r2 - 0x02) = r4;
	fn0484();
	return;
}

void fn0484()
{
	return;
}

void fn049E()
{
	return;
}

void fn06D4()
{
	return;
}

void fn07A4()
{
	return;
}

void fn0996()
{
	return;
}

void fn0AB4()
{
	__halt();
}

void fn0AE6()
{
	return;
}

void fn0AF4(word16 wArg00)
{
	word16 sp_7;
	word16 r5_8;
	r5();
	return;
}

void fn0BD4()
{
	__halt();
}

void fn0C1E()
{
	return;
}

