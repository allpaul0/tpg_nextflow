/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:10:24
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_T14, &&L_A5, &&L_A6, &&L_A3, &&L_A4, &&L_A0, &&L_A8
    };

	/* Initial dispatch — always start at T14 */
	goto *jump_table[14];	/* == &&L_T14 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[2] = { 16, 19 };
		fixedpt  scores[2];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T1: {
		static const int next[2] = { 20, 19 };
		fixedpt  scores[2];

        scores[0] = P2(in1, in2, in3, in4);
        scores[1] = P3(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T2: {
		static const int next[3] = { 18, 16, 15 };
		fixedpt  scores[3];

        scores[0] = P4(in1, in2, in3, in4);
        scores[1] = P5(in1, in2, in3, in4);
        scores[2] = P6(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T3: {
		static const int next[2] = { 15, 0 };
		fixedpt  scores[2];

        scores[0] = P7(in1, in2, in3, in4);
        scores[1] = P8(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T4: {
		static const int next[5] = { 19, 15, 16, 1, 15 };
		fixedpt  scores[5];

        scores[0] = P9(in1, in2, in3, in4);
        scores[1] = P10(in1, in2, in3, in4);
        scores[2] = P11(in1, in2, in3, in4);
        scores[3] = P12(in1, in2, in3, in4);
        scores[4] = P13(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T5: {
		static const int next[2] = { 4, 2 };
		fixedpt  scores[2];

        scores[0] = P14(in1, in2, in3, in4);
        scores[1] = P15(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T6: {
		static const int next[4] = { 3, 19, 2, 4 };
		fixedpt  scores[4];

        scores[0] = P16(in1, in2, in3, in4);
        scores[1] = P17(in1, in2, in3, in4);
        scores[2] = P18(in1, in2, in3, in4);
        scores[3] = P14(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T7: {
		static const int next[5] = { 2, 15, 3, 4, 2 };
		fixedpt  scores[5];

        scores[0] = P19(in1, in2, in3, in4);
        scores[1] = P20(in1, in2, in3, in4);
        scores[2] = P21(in1, in2, in3, in4);
        scores[3] = P22(in1, in2, in3, in4);
        scores[4] = P15(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T8: {
		static const int next[2] = { 3, 4 };
		fixedpt  scores[2];

        scores[0] = P23(in1, in2, in3, in4);
        scores[1] = P14(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T9: {
		static const int next[6] = { 3, 19, 6, 15, 2, 7 };
		fixedpt  scores[6];

        scores[0] = P23(in1, in2, in3, in4);
        scores[1] = P24(in1, in2, in3, in4);
        scores[2] = P25(in1, in2, in3, in4);
        scores[3] = P26(in1, in2, in3, in4);
        scores[4] = P27(in1, in2, in3, in4);
        scores[5] = P28(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T10: {
		static const int next[3] = { 2, 3, 8 };
		fixedpt  scores[3];

        scores[0] = P29(in1, in2, in3, in4);
        scores[1] = P23(in1, in2, in3, in4);
        scores[2] = P30(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T11: {
		static const int next[4] = { 3, 2, 3, 8 };
		fixedpt  scores[4];

        scores[0] = P31(in1, in2, in3, in4);
        scores[1] = P32(in1, in2, in3, in4);
        scores[2] = P23(in1, in2, in3, in4);
        scores[3] = P30(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T12: {
		static const int next[4] = { 3, 8, 10, 4 };
		fixedpt  scores[4];

        scores[0] = P31(in1, in2, in3, in4);
        scores[1] = P30(in1, in2, in3, in4);
        scores[2] = P33(in1, in2, in3, in4);
        scores[3] = P34(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T13: {
		static const int next[3] = { 9, 12, 11 };
		fixedpt  scores[3];

        scores[0] = P35(in1, in2, in3, in4);
        scores[1] = P36(in1, in2, in3, in4);
        scores[2] = P37(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T14: {
		static const int next[9] = { 17, 13, 15, 5, 17, 19, 9, 19, 19 };
		fixedpt  scores[9];

        scores[0] = P38(in1, in2, in3, in4);
        scores[1] = P39(in1, in2, in3, in4);
        scores[2] = P40(in1, in2, in3, in4);
        scores[3] = P41(in1, in2, in3, in4);
        scores[4] = P42(in1, in2, in3, in4);
        scores[5] = P43(in1, in2, in3, in4);
        scores[6] = P44(in1, in2, in3, in4);
        scores[7] = P45(in1, in2, in3, in4);
        scores[8] = P46(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 9)]];
	}

L_A5: actions[0] = 5; return;
L_A6: actions[0] = 6; return;
L_A3: actions[0] = 3; return;
L_A4: actions[0] = 4; return;
L_A0: actions[0] = 0; return;
L_A8: actions[0] = 8; return;
}
