/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:08:33
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_A5, &&L_A6, &&L_A7, &&L_A0, &&L_A3, &&L_A8, &&L_A4
    };

	/* Initial dispatch — always start at T10 */
	goto *jump_table[10];	/* == &&L_T10 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[2] = { 11, 13 };
		fixedpt  scores[2];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T1: {
		static const int next[4] = { 12, 11, 17, 12 };
		fixedpt  scores[4];

        scores[0] = P2(in1, in2, in3, in4);
        scores[1] = P0(in1, in2, in3, in4);
        scores[2] = P3(in1, in2, in3, in4);
        scores[3] = P4(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T2: {
		static const int next[4] = { 12, 17, 14, 0 };
		fixedpt  scores[4];

        scores[0] = P5(in1, in2, in3, in4);
        scores[1] = P3(in1, in2, in3, in4);
        scores[2] = P6(in1, in2, in3, in4);
        scores[3] = P7(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T3: {
		static const int next[3] = { 1, 1, 2 };
		fixedpt  scores[3];

        scores[0] = P8(in1, in2, in3, in4);
        scores[1] = P9(in1, in2, in3, in4);
        scores[2] = P10(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T4: {
		static const int next[6] = { 15, 11, 1, 16, 11, 2 };
		fixedpt  scores[6];

        scores[0] = P11(in1, in2, in3, in4);
        scores[1] = P12(in1, in2, in3, in4);
        scores[2] = P13(in1, in2, in3, in4);
        scores[3] = P14(in1, in2, in3, in4);
        scores[4] = P15(in1, in2, in3, in4);
        scores[5] = P16(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T5: {
		static const int next[2] = { 2, 1 };
		fixedpt  scores[2];

        scores[0] = P17(in1, in2, in3, in4);
        scores[1] = P18(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T6: {
		static const int next[3] = { 11, 3, 15 };
		fixedpt  scores[3];

        scores[0] = P19(in1, in2, in3, in4);
        scores[1] = P20(in1, in2, in3, in4);
        scores[2] = P21(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T7: {
		static const int next[3] = { 4, 13, 16 };
		fixedpt  scores[3];

        scores[0] = P22(in1, in2, in3, in4);
        scores[1] = P23(in1, in2, in3, in4);
        scores[2] = P14(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T8: {
		static const int next[7] = { 1, 11, 15, 1, 7, 6, 5 };
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
		static const int next[6] = { 4, 8, 15, 12, 1, 1 };
		fixedpt  scores[6];

        scores[0] = P31(in1, in2, in3, in4);
        scores[1] = P32(in1, in2, in3, in4);
        scores[2] = P33(in1, in2, in3, in4);
        scores[3] = P34(in1, in2, in3, in4);
        scores[4] = P35(in1, in2, in3, in4);
        scores[5] = P36(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T10: {
		static const int next[3] = { 9, 4, 1 };
		fixedpt  scores[3];

        scores[0] = P37(in1, in2, in3, in4);
        scores[1] = P38(in1, in2, in3, in4);
        scores[2] = P39(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_A5: actions[0] = 5; return;
L_A6: actions[0] = 6; return;
L_A7: actions[0] = 7; return;
L_A0: actions[0] = 0; return;
L_A3: actions[0] = 3; return;
L_A8: actions[0] = 8; return;
L_A4: actions[0] = 4; return;
}
