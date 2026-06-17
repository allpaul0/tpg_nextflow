/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:08:12
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_A3, &&L_A4, &&L_A6, &&L_A5, &&L_A0, &&L_A8, &&L_A1
    };

	/* Initial dispatch — always start at T11 */
	goto *jump_table[11];	/* == &&L_T11 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[2] = { 12, 13 };
		fixedpt  scores[2];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T1: {
		static const int next[3] = { 14, 0, 15 };
		fixedpt  scores[3];

        scores[0] = P2(in1, in2, in3, in4);
        scores[1] = P3(in1, in2, in3, in4);
        scores[2] = P4(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T2: {
		static const int next[2] = { 16, 17 };
		fixedpt  scores[2];

        scores[0] = P5(in1, in2, in3, in4);
        scores[1] = P6(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T3: {
		static const int next[3] = { 15, 1, 15 };
		fixedpt  scores[3];

        scores[0] = P7(in1, in2, in3, in4);
        scores[1] = P8(in1, in2, in3, in4);
        scores[2] = P9(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T4: {
		static const int next[2] = { 16, 3 };
		fixedpt  scores[2];

        scores[0] = P10(in1, in2, in3, in4);
        scores[1] = P11(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T5: {
		static const int next[3] = { 3, 15, 16 };
		fixedpt  scores[3];

        scores[0] = P12(in1, in2, in3, in4);
        scores[1] = P13(in1, in2, in3, in4);
        scores[2] = P10(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T6: {
		static const int next[5] = { 18, 4, 5, 2, 5 };
		fixedpt  scores[5];

        scores[0] = P14(in1, in2, in3, in4);
        scores[1] = P15(in1, in2, in3, in4);
        scores[2] = P16(in1, in2, in3, in4);
        scores[3] = P17(in1, in2, in3, in4);
        scores[4] = P18(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T7: {
		static const int next[5] = { 14, 18, 12, 6, 5 };
		fixedpt  scores[5];

        scores[0] = P19(in1, in2, in3, in4);
        scores[1] = P20(in1, in2, in3, in4);
        scores[2] = P21(in1, in2, in3, in4);
        scores[3] = P22(in1, in2, in3, in4);
        scores[4] = P23(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T8: {
		static const int next[7] = { 5, 5, 6, 18, 14, 3, 14 };
		fixedpt  scores[7];

        scores[0] = P24(in1, in2, in3, in4);
        scores[1] = P25(in1, in2, in3, in4);
        scores[2] = P26(in1, in2, in3, in4);
        scores[3] = P27(in1, in2, in3, in4);
        scores[4] = P28(in1, in2, in3, in4);
        scores[5] = P29(in1, in2, in3, in4);
        scores[6] = P30(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 7)]];
	}

L_T9: {
		static const int next[3] = { 15, 7, 12 };
		fixedpt  scores[3];

        scores[0] = P31(in1, in2, in3, in4);
        scores[1] = P32(in1, in2, in3, in4);
        scores[2] = P33(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T10: {
		static const int next[2] = { 13, 8 };
		fixedpt  scores[2];

        scores[0] = P34(in1, in2, in3, in4);
        scores[1] = P35(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T11: {
		static const int next[5] = { 5, 10, 18, 9, 13 };
		fixedpt  scores[5];

        scores[0] = P24(in1, in2, in3, in4);
        scores[1] = P36(in1, in2, in3, in4);
        scores[2] = P37(in1, in2, in3, in4);
        scores[3] = P38(in1, in2, in3, in4);
        scores[4] = P39(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_A3: actions[0] = 3; return;
L_A4: actions[0] = 4; return;
L_A6: actions[0] = 6; return;
L_A5: actions[0] = 5; return;
L_A0: actions[0] = 0; return;
L_A8: actions[0] = 8; return;
L_A1: actions[0] = 1; return;
}
