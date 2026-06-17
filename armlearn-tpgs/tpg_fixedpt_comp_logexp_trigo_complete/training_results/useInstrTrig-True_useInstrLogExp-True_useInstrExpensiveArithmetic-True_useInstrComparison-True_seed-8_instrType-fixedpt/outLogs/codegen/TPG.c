/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:10:09
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_T14, &&L_T15, &&L_A0, &&L_A6, &&L_A5, &&L_A4, &&L_A3, &&L_A1, &&L_A7, &&L_A2
    };

	/* Initial dispatch — always start at T15 */
	goto *jump_table[15];	/* == &&L_T15 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[2] = { 18, 19 };
		fixedpt  scores[2];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T1: {
		static const int next[5] = { 19, 16, 17, 18, 18 };
		fixedpt  scores[5];

        scores[0] = P1(in1, in2, in3, in4);
        scores[1] = P2(in1, in2, in3, in4);
        scores[2] = P3(in1, in2, in3, in4);
        scores[3] = P4(in1, in2, in3, in4);
        scores[4] = P5(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T2: {
		static const int next[3] = { 0, 17, 16 };
		fixedpt  scores[3];

        scores[0] = P6(in1, in2, in3, in4);
        scores[1] = P7(in1, in2, in3, in4);
        scores[2] = P8(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T3: {
		static const int next[3] = { 18, 1, 17 };
		fixedpt  scores[3];

        scores[0] = P9(in1, in2, in3, in4);
        scores[1] = P10(in1, in2, in3, in4);
        scores[2] = P11(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T4: {
		static const int next[2] = { 18, 20 };
		fixedpt  scores[2];

        scores[0] = P12(in1, in2, in3, in4);
        scores[1] = P13(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T5: {
		static const int next[2] = { 3, 18 };
		fixedpt  scores[2];

        scores[0] = P14(in1, in2, in3, in4);
        scores[1] = P9(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T6: {
		static const int next[2] = { 21, 3 };
		fixedpt  scores[2];

        scores[0] = P15(in1, in2, in3, in4);
        scores[1] = P16(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T7: {
		static const int next[9] = { 17, 6, 21, 18, 3, 16, 17, 21, 17 };
		fixedpt  scores[9];

        scores[0] = P17(in1, in2, in3, in4);
        scores[1] = P18(in1, in2, in3, in4);
        scores[2] = P19(in1, in2, in3, in4);
        scores[3] = P20(in1, in2, in3, in4);
        scores[4] = P21(in1, in2, in3, in4);
        scores[5] = P22(in1, in2, in3, in4);
        scores[6] = P23(in1, in2, in3, in4);
        scores[7] = P15(in1, in2, in3, in4);
        scores[8] = P24(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 9)]];
	}

L_T8: {
		static const int next[7] = { 21, 18, 3, 16, 17, 21, 1 };
		fixedpt  scores[7];

        scores[0] = P19(in1, in2, in3, in4);
        scores[1] = P20(in1, in2, in3, in4);
        scores[2] = P21(in1, in2, in3, in4);
        scores[3] = P22(in1, in2, in3, in4);
        scores[4] = P23(in1, in2, in3, in4);
        scores[5] = P15(in1, in2, in3, in4);
        scores[6] = P25(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 7)]];
	}

L_T9: {
		static const int next[8] = { 20, 6, 21, 5, 16, 17, 21, 16 };
		fixedpt  scores[8];

        scores[0] = P26(in1, in2, in3, in4);
        scores[1] = P18(in1, in2, in3, in4);
        scores[2] = P19(in1, in2, in3, in4);
        scores[3] = P27(in1, in2, in3, in4);
        scores[4] = P22(in1, in2, in3, in4);
        scores[5] = P28(in1, in2, in3, in4);
        scores[6] = P29(in1, in2, in3, in4);
        scores[7] = P30(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 8)]];
	}

L_T10: {
		static const int next[4] = { 23, 18, 3, 7 };
		fixedpt  scores[4];

        scores[0] = P31(in1, in2, in3, in4);
        scores[1] = P32(in1, in2, in3, in4);
        scores[2] = P16(in1, in2, in3, in4);
        scores[3] = P33(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T11: {
		static const int next[6] = { 23, 18, 3, 18, 7, 8 };
		fixedpt  scores[6];

        scores[0] = P31(in1, in2, in3, in4);
        scores[1] = P32(in1, in2, in3, in4);
        scores[2] = P34(in1, in2, in3, in4);
        scores[3] = P20(in1, in2, in3, in4);
        scores[4] = P35(in1, in2, in3, in4);
        scores[5] = P36(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T12: {
		static const int next[2] = { 11, 22 };
		fixedpt  scores[2];

        scores[0] = P37(in1, in2, in3, in4);
        scores[1] = P38(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T13: {
		static const int next[3] = { 10, 16, 9 };
		fixedpt  scores[3];

        scores[0] = P39(in1, in2, in3, in4);
        scores[1] = P40(in1, in2, in3, in4);
        scores[2] = P41(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T14: {
		static const int next[3] = { 10, 16, 9 };
		fixedpt  scores[3];

        scores[0] = P42(in1, in2, in3, in4);
        scores[1] = P40(in1, in2, in3, in4);
        scores[2] = P41(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T15: {
		static const int next[6] = { 4, 14, 12, 2, 11, 13 };
		fixedpt  scores[6];

        scores[0] = P43(in1, in2, in3, in4);
        scores[1] = P44(in1, in2, in3, in4);
        scores[2] = P45(in1, in2, in3, in4);
        scores[3] = P46(in1, in2, in3, in4);
        scores[4] = P47(in1, in2, in3, in4);
        scores[5] = P48(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_A0: actions[0] = 0; return;
L_A6: actions[0] = 6; return;
L_A5: actions[0] = 5; return;
L_A4: actions[0] = 4; return;
L_A3: actions[0] = 3; return;
L_A1: actions[0] = 1; return;
L_A7: actions[0] = 7; return;
L_A2: actions[0] = 2; return;
}
