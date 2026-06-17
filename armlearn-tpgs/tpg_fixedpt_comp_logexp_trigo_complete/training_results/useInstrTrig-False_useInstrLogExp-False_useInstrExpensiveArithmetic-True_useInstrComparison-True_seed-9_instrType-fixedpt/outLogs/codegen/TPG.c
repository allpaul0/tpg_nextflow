/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:08:31
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_A6, &&L_A7, &&L_A0, &&L_A5, &&L_A4, &&L_A2, &&L_A1
    };

	/* Initial dispatch — always start at T12 */
	goto *jump_table[12];	/* == &&L_T12 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[3] = { 15, 16, 17 };
		fixedpt  scores[3];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);
        scores[2] = P2(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T1: {
		static const int next[3] = { 0, 18, 13 };
		fixedpt  scores[3];

        scores[0] = P3(in1, in2, in3, in4);
        scores[1] = P4(in1, in2, in3, in4);
        scores[2] = P5(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T2: {
		static const int next[3] = { 13, 16, 0 };
		fixedpt  scores[3];

        scores[0] = P6(in1, in2, in3, in4);
        scores[1] = P7(in1, in2, in3, in4);
        scores[2] = P8(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T3: {
		static const int next[2] = { 1, 0 };
		fixedpt  scores[2];

        scores[0] = P9(in1, in2, in3, in4);
        scores[1] = P10(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T4: {
		static const int next[3] = { 1, 0, 2 };
		fixedpt  scores[3];

        scores[0] = P11(in1, in2, in3, in4);
        scores[1] = P12(in1, in2, in3, in4);
        scores[2] = P13(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T5: {
		static const int next[2] = { 1, 4 };
		fixedpt  scores[2];

        scores[0] = P14(in1, in2, in3, in4);
        scores[1] = P15(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T6: {
		static const int next[2] = { 4, 3 };
		fixedpt  scores[2];

        scores[0] = P16(in1, in2, in3, in4);
        scores[1] = P17(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T7: {
		static const int next[3] = { 14, 1, 4 };
		fixedpt  scores[3];

        scores[0] = P18(in1, in2, in3, in4);
        scores[1] = P19(in1, in2, in3, in4);
        scores[2] = P20(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T8: {
		static const int next[2] = { 5, 3 };
		fixedpt  scores[2];

        scores[0] = P21(in1, in2, in3, in4);
        scores[1] = P22(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T9: {
		static const int next[8] = { 18, 5, 6, 8, 19, 4, 4, 3 };
		fixedpt  scores[8];

        scores[0] = P23(in1, in2, in3, in4);
        scores[1] = P24(in1, in2, in3, in4);
        scores[2] = P25(in1, in2, in3, in4);
        scores[3] = P26(in1, in2, in3, in4);
        scores[4] = P27(in1, in2, in3, in4);
        scores[5] = P28(in1, in2, in3, in4);
        scores[6] = P29(in1, in2, in3, in4);
        scores[7] = P30(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 8)]];
	}

L_T10: {
		static const int next[3] = { 9, 19, 7 };
		fixedpt  scores[3];

        scores[0] = P31(in1, in2, in3, in4);
        scores[1] = P27(in1, in2, in3, in4);
        scores[2] = P32(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T11: {
		static const int next[6] = { 9, 19, 7, 7, 18, 10 };
		fixedpt  scores[6];

        scores[0] = P31(in1, in2, in3, in4);
        scores[1] = P27(in1, in2, in3, in4);
        scores[2] = P33(in1, in2, in3, in4);
        scores[3] = P32(in1, in2, in3, in4);
        scores[4] = P34(in1, in2, in3, in4);
        scores[5] = P35(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T12: {
		static const int next[5] = { 9, 19, 18, 6, 11 };
		fixedpt  scores[5];

        scores[0] = P31(in1, in2, in3, in4);
        scores[1] = P27(in1, in2, in3, in4);
        scores[2] = P34(in1, in2, in3, in4);
        scores[3] = P36(in1, in2, in3, in4);
        scores[4] = P37(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_A6: actions[0] = 6; return;
L_A7: actions[0] = 7; return;
L_A0: actions[0] = 0; return;
L_A5: actions[0] = 5; return;
L_A4: actions[0] = 4; return;
L_A2: actions[0] = 2; return;
L_A1: actions[0] = 1; return;
}
