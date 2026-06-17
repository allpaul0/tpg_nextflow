/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:08:25
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_A6, &&L_A7, &&L_A0, &&L_A5, &&L_A8, &&L_A2, &&L_A4, &&L_A1
    };

	/* Initial dispatch — always start at T9 */
	goto *jump_table[9];	/* == &&L_T9 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[4] = { 11, 13, 10, 12 };
		fixedpt  scores[4];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);
        scores[2] = P2(in1, in2, in3, in4);
        scores[3] = P3(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T1: {
		static const int next[6] = { 12, 0, 14, 14, 0, 14 };
		fixedpt  scores[6];

        scores[0] = P4(in1, in2, in3, in4);
        scores[1] = P5(in1, in2, in3, in4);
        scores[2] = P6(in1, in2, in3, in4);
        scores[3] = P7(in1, in2, in3, in4);
        scores[4] = P8(in1, in2, in3, in4);
        scores[5] = P9(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T2: {
		static const int next[2] = { 0, 14 };
		fixedpt  scores[2];

        scores[0] = P10(in1, in2, in3, in4);
        scores[1] = P11(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T3: {
		static const int next[5] = { 0, 14, 0, 12, 16 };
		fixedpt  scores[5];

        scores[0] = P10(in1, in2, in3, in4);
        scores[1] = P12(in1, in2, in3, in4);
        scores[2] = P13(in1, in2, in3, in4);
        scores[3] = P14(in1, in2, in3, in4);
        scores[4] = P15(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T4: {
		static const int next[4] = { 3, 2, 0, 1 };
		fixedpt  scores[4];

        scores[0] = P16(in1, in2, in3, in4);
        scores[1] = P17(in1, in2, in3, in4);
        scores[2] = P18(in1, in2, in3, in4);
        scores[3] = P19(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T5: {
		static const int next[7] = { 3, 16, 2, 3, 1, 15, 12 };
		fixedpt  scores[7];

        scores[0] = P20(in1, in2, in3, in4);
        scores[1] = P15(in1, in2, in3, in4);
        scores[2] = P21(in1, in2, in3, in4);
        scores[3] = P22(in1, in2, in3, in4);
        scores[4] = P23(in1, in2, in3, in4);
        scores[5] = P24(in1, in2, in3, in4);
        scores[6] = P14(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 7)]];
	}

L_T6: {
		static const int next[5] = { 3, 2, 16, 1, 15 };
		fixedpt  scores[5];

        scores[0] = P16(in1, in2, in3, in4);
        scores[1] = P25(in1, in2, in3, in4);
        scores[2] = P15(in1, in2, in3, in4);
        scores[3] = P19(in1, in2, in3, in4);
        scores[4] = P26(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T7: {
		static const int next[2] = { 4, 5 };
		fixedpt  scores[2];

        scores[0] = P27(in1, in2, in3, in4);
        scores[1] = P28(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T8: {
		static const int next[2] = { 1, 6 };
		fixedpt  scores[2];

        scores[0] = P29(in1, in2, in3, in4);
        scores[1] = P30(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T9: {
		static const int next[4] = { 8, 17, 5, 7 };
		fixedpt  scores[4];

        scores[0] = P31(in1, in2, in3, in4);
        scores[1] = P32(in1, in2, in3, in4);
        scores[2] = P33(in1, in2, in3, in4);
        scores[3] = P34(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_A6: actions[0] = 6; return;
L_A7: actions[0] = 7; return;
L_A0: actions[0] = 0; return;
L_A5: actions[0] = 5; return;
L_A8: actions[0] = 8; return;
L_A2: actions[0] = 2; return;
L_A4: actions[0] = 4; return;
L_A1: actions[0] = 1; return;
}
