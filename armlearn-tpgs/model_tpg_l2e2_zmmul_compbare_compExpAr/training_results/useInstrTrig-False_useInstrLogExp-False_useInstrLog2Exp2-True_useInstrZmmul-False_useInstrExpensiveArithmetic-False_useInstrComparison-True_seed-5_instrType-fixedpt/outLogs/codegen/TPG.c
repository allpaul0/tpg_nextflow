/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-05-28 19:45:53
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_T14, &&L_T15, &&L_T16, &&L_A5, &&L_A6, &&L_A4, &&L_A8, &&L_A0, &&L_A7, &&L_A2, &&L_A1
    };

	/* Initial dispatch — always start at T16 */
	goto *jump_table[16];	/* == &&L_T16 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[2] = { 17, 18 };
		fixedpt  scores[2];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T1: {
		static const int next[3] = { 0, 21, 18 };
		fixedpt  scores[3];

        scores[0] = P2(in1, in2, in3, in4);
        scores[1] = P3(in1, in2, in3, in4);
        scores[2] = P4(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T2: {
		static const int next[1] = { 1 };
		fixedpt  scores[1];

        scores[0] = P5(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 1)]];
	}

L_T3: {
		static const int next[4] = { 0, 19, 18, 20 };
		fixedpt  scores[4];

        scores[0] = P6(in1, in2, in3, in4);
        scores[1] = P7(in1, in2, in3, in4);
        scores[2] = P8(in1, in2, in3, in4);
        scores[3] = P9(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T4: {
		static const int next[2] = { 3, 22 };
		fixedpt  scores[2];

        scores[0] = P10(in1, in2, in3, in4);
        scores[1] = P11(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T5: {
		static const int next[3] = { 21, 18, 23 };
		fixedpt  scores[3];

        scores[0] = P12(in1, in2, in3, in4);
        scores[1] = P13(in1, in2, in3, in4);
        scores[2] = P14(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T6: {
		static const int next[2] = { 3, 19 };
		fixedpt  scores[2];

        scores[0] = P10(in1, in2, in3, in4);
        scores[1] = P15(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T7: {
		static const int next[2] = { 4, 21 };
		fixedpt  scores[2];

        scores[0] = P16(in1, in2, in3, in4);
        scores[1] = P17(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T8: {
		static const int next[2] = { 21, 6 };
		fixedpt  scores[2];

        scores[0] = P17(in1, in2, in3, in4);
        scores[1] = P18(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T9: {
		static const int next[2] = { 7, 22 };
		fixedpt  scores[2];

        scores[0] = P19(in1, in2, in3, in4);
        scores[1] = P20(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T10: {
		static const int next[3] = { 23, 2, 8 };
		fixedpt  scores[3];

        scores[0] = P21(in1, in2, in3, in4);
        scores[1] = P22(in1, in2, in3, in4);
        scores[2] = P23(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T11: {
		static const int next[2] = { 10, 8 };
		fixedpt  scores[2];

        scores[0] = P24(in1, in2, in3, in4);
        scores[1] = P25(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T12: {
		static const int next[2] = { 5, 11 };
		fixedpt  scores[2];

        scores[0] = P26(in1, in2, in3, in4);
        scores[1] = P27(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T13: {
		static const int next[4] = { 10, 8, 20, 9 };
		fixedpt  scores[4];

        scores[0] = P28(in1, in2, in3, in4);
        scores[1] = P29(in1, in2, in3, in4);
        scores[2] = P30(in1, in2, in3, in4);
        scores[3] = P31(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T14: {
		static const int next[3] = { 10, 22, 8 };
		fixedpt  scores[3];

        scores[0] = P28(in1, in2, in3, in4);
        scores[1] = P32(in1, in2, in3, in4);
        scores[2] = P25(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T15: {
		static const int next[5] = { 12, 14, 13, 10, 24 };
		fixedpt  scores[5];

        scores[0] = P33(in1, in2, in3, in4);
        scores[1] = P34(in1, in2, in3, in4);
        scores[2] = P35(in1, in2, in3, in4);
        scores[3] = P36(in1, in2, in3, in4);
        scores[4] = P37(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T16: {
		static const int next[4] = { 15, 24, 20, 14 };
		fixedpt  scores[4];

        scores[0] = P38(in1, in2, in3, in4);
        scores[1] = P39(in1, in2, in3, in4);
        scores[2] = P40(in1, in2, in3, in4);
        scores[3] = P41(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_A5: actions[0] = 5; return;
L_A6: actions[0] = 6; return;
L_A4: actions[0] = 4; return;
L_A8: actions[0] = 8; return;
L_A0: actions[0] = 0; return;
L_A7: actions[0] = 7; return;
L_A2: actions[0] = 2; return;
L_A1: actions[0] = 1; return;
}
