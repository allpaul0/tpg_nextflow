/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-07-14 09:07:03
 * With the CodeGen::TPGGenerationEngine.
 */

#include "TPG.h"

/* ------------------------------------------------------------ */
/* Helper                                                        */
/* ------------------------------------------------------------ */

static inline int bestProgram(const fixedpt *results, int nb) {
	int bestProgram = 0;
	fixedpt top = results[0];
	for (int i = 1; i < nb; i++) {
		if (results[i] >= top) { top = results[i]; bestProgram = i; }
	}
	return bestProgram;
}

/* ------------------------------------------------------------ */
/* Inference — computed goto dispatch                            */
/* ------------------------------------------------------------ */

void inferenceTPG(fixedpt *actions,
					const fixedpt * __restrict__ in1,
					const fixedpt * __restrict__ in2,
					const fixedpt * __restrict__ in3,
					const fixedpt * __restrict__ in4)
{
	/* Jump table — static const lets GCC keep it in .rodata and
	   potentially cache it in a register across iterations.       */
	static const void * const jump_table[] = {
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_T14, &&L_T15, &&L_T16, &&L_T17, &&L_T18, &&L_T19, &&L_T20, &&L_T21, &&L_T22, &&L_T23, &&L_T24, &&L_A3, &&L_A4, &&L_A5, &&L_A6, &&L_A7, &&L_A0, &&L_A8, &&L_A1
    };

	/* Initial dispatch — always start at T24 */
	goto *jump_table[24];	/* == &&L_T24 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[2] = { 26, 25 };
		fixedpt  scores[2];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T1: {
		static const int next[2] = { 29, 30 };
		fixedpt  scores[2];

        scores[0] = P2(in1, in2, in3, in4);
        scores[1] = P3(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T2: {
		static const int next[2] = { 32, 1 };
		fixedpt  scores[2];

        scores[0] = P4(in1, in2, in3, in4);
        scores[1] = P5(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T3: {
		static const int next[3] = { 28, 27, 30 };
		fixedpt  scores[3];

        scores[0] = P6(in1, in2, in3, in4);
        scores[1] = P7(in1, in2, in3, in4);
        scores[2] = P8(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T4: {
		static const int next[4] = { 27, 1, 28, 26 };
		fixedpt  scores[4];

        scores[0] = P9(in1, in2, in3, in4);
        scores[1] = P10(in1, in2, in3, in4);
        scores[2] = P11(in1, in2, in3, in4);
        scores[3] = P12(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T5: {
		static const int next[4] = { 28, 0, 3, 28 };
		fixedpt  scores[4];

        scores[0] = P13(in1, in2, in3, in4);
        scores[1] = P14(in1, in2, in3, in4);
        scores[2] = P15(in1, in2, in3, in4);
        scores[3] = P16(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T6: {
		static const int next[4] = { 0, 3, 28, 28 };
		fixedpt  scores[4];

        scores[0] = P14(in1, in2, in3, in4);
        scores[1] = P15(in1, in2, in3, in4);
        scores[2] = P17(in1, in2, in3, in4);
        scores[3] = P16(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T7: {
		static const int next[4] = { 6, 28, 0, 2 };
		fixedpt  scores[4];

        scores[0] = P18(in1, in2, in3, in4);
        scores[1] = P19(in1, in2, in3, in4);
        scores[2] = P20(in1, in2, in3, in4);
        scores[3] = P21(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T8: {
		static const int next[3] = { 6, 0, 2 };
		fixedpt  scores[3];

        scores[0] = P18(in1, in2, in3, in4);
        scores[1] = P22(in1, in2, in3, in4);
        scores[2] = P23(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T9: {
		static const int next[5] = { 6, 25, 28, 2, 27 };
		fixedpt  scores[5];

        scores[0] = P24(in1, in2, in3, in4);
        scores[1] = P25(in1, in2, in3, in4);
        scores[2] = P26(in1, in2, in3, in4);
        scores[3] = P27(in1, in2, in3, in4);
        scores[4] = P28(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T10: {
		static const int next[3] = { 9, 1, 5 };
		fixedpt  scores[3];

        scores[0] = P29(in1, in2, in3, in4);
        scores[1] = P30(in1, in2, in3, in4);
        scores[2] = P31(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T11: {
		static const int next[4] = { 8, 27, 31, 5 };
		fixedpt  scores[4];

        scores[0] = P32(in1, in2, in3, in4);
        scores[1] = P33(in1, in2, in3, in4);
        scores[2] = P34(in1, in2, in3, in4);
        scores[3] = P35(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T12: {
		static const int next[3] = { 7, 9, 25 };
		fixedpt  scores[3];

        scores[0] = P36(in1, in2, in3, in4);
        scores[1] = P37(in1, in2, in3, in4);
        scores[2] = P38(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T13: {
		static const int next[3] = { 29, 9, 8 };
		fixedpt  scores[3];

        scores[0] = P39(in1, in2, in3, in4);
        scores[1] = P40(in1, in2, in3, in4);
        scores[2] = P41(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T14: {
		static const int next[2] = { 11, 9 };
		fixedpt  scores[2];

        scores[0] = P42(in1, in2, in3, in4);
        scores[1] = P43(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T15: {
		static const int next[6] = { 9, 27, 5, 31, 9, 27 };
		fixedpt  scores[6];

        scores[0] = P44(in1, in2, in3, in4);
        scores[1] = P45(in1, in2, in3, in4);
        scores[2] = P35(in1, in2, in3, in4);
        scores[3] = P46(in1, in2, in3, in4);
        scores[4] = P29(in1, in2, in3, in4);
        scores[5] = P33(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T16: {
		static const int next[4] = { 27, 5, 0, 13 };
		fixedpt  scores[4];

        scores[0] = P47(in1, in2, in3, in4);
        scores[1] = P48(in1, in2, in3, in4);
        scores[2] = P49(in1, in2, in3, in4);
        scores[3] = P50(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T17: {
		static const int next[2] = { 5, 15 };
		fixedpt  scores[2];

        scores[0] = P35(in1, in2, in3, in4);
        scores[1] = P51(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T18: {
		static const int next[4] = { 12, 16, 5, 10 };
		fixedpt  scores[4];

        scores[0] = P52(in1, in2, in3, in4);
        scores[1] = P53(in1, in2, in3, in4);
        scores[2] = P54(in1, in2, in3, in4);
        scores[3] = P55(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T19: {
		static const int next[5] = { 17, 31, 12, 9, 18 };
		fixedpt  scores[5];

        scores[0] = P56(in1, in2, in3, in4);
        scores[1] = P34(in1, in2, in3, in4);
        scores[2] = P57(in1, in2, in3, in4);
        scores[3] = P58(in1, in2, in3, in4);
        scores[4] = P59(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T20: {
		static const int next[8] = { 16, 10, 31, 10, 14, 9, 12, 27 };
		fixedpt  scores[8];

        scores[0] = P60(in1, in2, in3, in4);
        scores[1] = P61(in1, in2, in3, in4);
        scores[2] = P62(in1, in2, in3, in4);
        scores[3] = P63(in1, in2, in3, in4);
        scores[4] = P64(in1, in2, in3, in4);
        scores[5] = P65(in1, in2, in3, in4);
        scores[6] = P57(in1, in2, in3, in4);
        scores[7] = P66(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 8)]];
	}

L_T21: {
		static const int next[8] = { 16, 10, 31, 4, 9, 12, 14, 27 };
		fixedpt  scores[8];

        scores[0] = P60(in1, in2, in3, in4);
        scores[1] = P61(in1, in2, in3, in4);
        scores[2] = P62(in1, in2, in3, in4);
        scores[3] = P67(in1, in2, in3, in4);
        scores[4] = P65(in1, in2, in3, in4);
        scores[5] = P68(in1, in2, in3, in4);
        scores[6] = P64(in1, in2, in3, in4);
        scores[7] = P69(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 8)]];
	}

L_T22: {
		static const int next[5] = { 31, 19, 14, 9, 20 };
		fixedpt  scores[5];

        scores[0] = P70(in1, in2, in3, in4);
        scores[1] = P71(in1, in2, in3, in4);
        scores[2] = P64(in1, in2, in3, in4);
        scores[3] = P65(in1, in2, in3, in4);
        scores[4] = P72(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T23: {
		static const int next[2] = { 12, 21 };
		fixedpt  scores[2];

        scores[0] = P73(in1, in2, in3, in4);
        scores[1] = P74(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T24: {
		static const int next[4] = { 23, 22, 19, 14 };
		fixedpt  scores[4];

        scores[0] = P75(in1, in2, in3, in4);
        scores[1] = P76(in1, in2, in3, in4);
        scores[2] = P71(in1, in2, in3, in4);
        scores[3] = P64(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_A3: actions[0] = 3; return;
L_A4: actions[0] = 4; return;
L_A5: actions[0] = 5; return;
L_A6: actions[0] = 6; return;
L_A7: actions[0] = 7; return;
L_A0: actions[0] = 0; return;
L_A8: actions[0] = 8; return;
L_A1: actions[0] = 1; return;
}
