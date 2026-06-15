/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-05-28 21:29:01
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_A3, &&L_A4, &&L_A6, &&L_A5, &&L_A0, &&L_A1, &&L_A2
    };

	/* Initial dispatch — always start at T8 */
	goto *jump_table[8];	/* == &&L_T8 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[1] = { 13 };
		fixedpt  scores[1];

        scores[0] = P0(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 1)]];
	}

L_T1: {
		static const int next[5] = { 11, 12, 10, 13, 9 };
		fixedpt  scores[5];

        scores[0] = P1(in1, in2, in3, in4);
        scores[1] = P2(in1, in2, in3, in4);
        scores[2] = P3(in1, in2, in3, in4);
        scores[3] = P4(in1, in2, in3, in4);
        scores[4] = P5(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T2: {
		static const int next[5] = { 10, 9, 9, 11, 0 };
		fixedpt  scores[5];

        scores[0] = P3(in1, in2, in3, in4);
        scores[1] = P6(in1, in2, in3, in4);
        scores[2] = P5(in1, in2, in3, in4);
        scores[3] = P7(in1, in2, in3, in4);
        scores[4] = P8(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T3: {
		static const int next[5] = { 12, 10, 13, 9, 11 };
		fixedpt  scores[5];

        scores[0] = P9(in1, in2, in3, in4);
        scores[1] = P3(in1, in2, in3, in4);
        scores[2] = P4(in1, in2, in3, in4);
        scores[3] = P5(in1, in2, in3, in4);
        scores[4] = P10(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T4: {
		static const int next[2] = { 3, 2 };
		fixedpt  scores[2];

        scores[0] = P11(in1, in2, in3, in4);
        scores[1] = P12(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T5: {
		static const int next[6] = { 4, 12, 11, 13, 15, 12 };
		fixedpt  scores[6];

        scores[0] = P13(in1, in2, in3, in4);
        scores[1] = P14(in1, in2, in3, in4);
        scores[2] = P15(in1, in2, in3, in4);
        scores[3] = P16(in1, in2, in3, in4);
        scores[4] = P17(in1, in2, in3, in4);
        scores[5] = P18(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T6: {
		static const int next[5] = { 12, 5, 1, 12, 12 };
		fixedpt  scores[5];

        scores[0] = P19(in1, in2, in3, in4);
        scores[1] = P20(in1, in2, in3, in4);
        scores[2] = P21(in1, in2, in3, in4);
        scores[3] = P22(in1, in2, in3, in4);
        scores[4] = P23(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T7: {
		static const int next[4] = { 1, 13, 15, 6 };
		fixedpt  scores[4];

        scores[0] = P24(in1, in2, in3, in4);
        scores[1] = P25(in1, in2, in3, in4);
        scores[2] = P26(in1, in2, in3, in4);
        scores[3] = P27(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T8: {
		static const int next[3] = { 7, 14, 15 };
		fixedpt  scores[3];

        scores[0] = P28(in1, in2, in3, in4);
        scores[1] = P29(in1, in2, in3, in4);
        scores[2] = P30(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_A3: actions[0] = 3; return;
L_A4: actions[0] = 4; return;
L_A6: actions[0] = 6; return;
L_A5: actions[0] = 5; return;
L_A0: actions[0] = 0; return;
L_A1: actions[0] = 1; return;
L_A2: actions[0] = 2; return;
}
