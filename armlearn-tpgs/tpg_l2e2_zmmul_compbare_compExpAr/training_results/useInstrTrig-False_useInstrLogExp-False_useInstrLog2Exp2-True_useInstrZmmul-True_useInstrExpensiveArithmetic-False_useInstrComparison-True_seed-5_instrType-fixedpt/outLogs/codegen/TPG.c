/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-07-14 09:07:04
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_A5, &&L_A6, &&L_A8, &&L_A0, &&L_A4, &&L_A7, &&L_A2, &&L_A1
    };

	/* Initial dispatch — always start at T8 */
	goto *jump_table[8];	/* == &&L_T8 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[2] = { 9, 10 };
		fixedpt  scores[2];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T1: {
		static const int next[4] = { 12, 9, 10, 13 };
		fixedpt  scores[4];

        scores[0] = P2(in1, in2, in3, in4);
        scores[1] = P0(in1, in2, in3, in4);
        scores[2] = P1(in1, in2, in3, in4);
        scores[3] = P3(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T2: {
		static const int next[3] = { 1, 11, 13 };
		fixedpt  scores[3];

        scores[0] = P4(in1, in2, in3, in4);
        scores[1] = P5(in1, in2, in3, in4);
        scores[2] = P6(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T3: {
		static const int next[6] = { 13, 13, 2, 12, 0, 13 };
		fixedpt  scores[6];

        scores[0] = P7(in1, in2, in3, in4);
        scores[1] = P8(in1, in2, in3, in4);
        scores[2] = P9(in1, in2, in3, in4);
        scores[3] = P10(in1, in2, in3, in4);
        scores[4] = P11(in1, in2, in3, in4);
        scores[5] = P12(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T4: {
		static const int next[4] = { 0, 14, 2, 0 };
		fixedpt  scores[4];

        scores[0] = P13(in1, in2, in3, in4);
        scores[1] = P14(in1, in2, in3, in4);
        scores[2] = P15(in1, in2, in3, in4);
        scores[3] = P16(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T5: {
		static const int next[5] = { 16, 15, 2, 0, 4 };
		fixedpt  scores[5];

        scores[0] = P17(in1, in2, in3, in4);
        scores[1] = P18(in1, in2, in3, in4);
        scores[2] = P19(in1, in2, in3, in4);
        scores[3] = P20(in1, in2, in3, in4);
        scores[4] = P21(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T6: {
		static const int next[6] = { 16, 15, 2, 15, 5, 3 };
		fixedpt  scores[6];

        scores[0] = P17(in1, in2, in3, in4);
        scores[1] = P18(in1, in2, in3, in4);
        scores[2] = P22(in1, in2, in3, in4);
        scores[3] = P23(in1, in2, in3, in4);
        scores[4] = P24(in1, in2, in3, in4);
        scores[5] = P25(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T7: {
		static const int next[5] = { 4, 3, 15, 15, 2 };
		fixedpt  scores[5];

        scores[0] = P26(in1, in2, in3, in4);
        scores[1] = P25(in1, in2, in3, in4);
        scores[2] = P27(in1, in2, in3, in4);
        scores[3] = P18(in1, in2, in3, in4);
        scores[4] = P19(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T8: {
		static const int next[8] = { 16, 0, 15, 7, 2, 6, 2, 15 };
		fixedpt  scores[8];

        scores[0] = P28(in1, in2, in3, in4);
        scores[1] = P29(in1, in2, in3, in4);
        scores[2] = P30(in1, in2, in3, in4);
        scores[3] = P31(in1, in2, in3, in4);
        scores[4] = P22(in1, in2, in3, in4);
        scores[5] = P32(in1, in2, in3, in4);
        scores[6] = P33(in1, in2, in3, in4);
        scores[7] = P27(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 8)]];
	}

L_A5: actions[0] = 5; return;
L_A6: actions[0] = 6; return;
L_A8: actions[0] = 8; return;
L_A0: actions[0] = 0; return;
L_A4: actions[0] = 4; return;
L_A7: actions[0] = 7; return;
L_A2: actions[0] = 2; return;
L_A1: actions[0] = 1; return;
}
