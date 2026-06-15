/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-05-28 19:45:48
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_T14, &&L_T15, &&L_T16, &&L_T17, &&L_T18, &&L_A4, &&L_A0, &&L_A6, &&L_A7, &&L_A5, &&L_A8, &&L_A1
    };

	/* Initial dispatch — always start at T18 */
	goto *jump_table[18];	/* == &&L_T18 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[1] = { 20 };
		fixedpt  scores[1];

        scores[0] = P0(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 1)]];
	}

L_T1: {
		static const int next[5] = { 21, 19, 22, 19, 23 };
		fixedpt  scores[5];

        scores[0] = P1(in1, in2, in3, in4);
        scores[1] = P2(in1, in2, in3, in4);
        scores[2] = P3(in1, in2, in3, in4);
        scores[3] = P4(in1, in2, in3, in4);
        scores[4] = P5(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T2: {
		static const int next[3] = { 22, 23, 19 };
		fixedpt  scores[3];

        scores[0] = P3(in1, in2, in3, in4);
        scores[1] = P6(in1, in2, in3, in4);
        scores[2] = P7(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T3: {
		static const int next[2] = { 23, 22 };
		fixedpt  scores[2];

        scores[0] = P8(in1, in2, in3, in4);
        scores[1] = P9(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T4: {
		static const int next[3] = { 0, 22, 23 };
		fixedpt  scores[3];

        scores[0] = P10(in1, in2, in3, in4);
        scores[1] = P11(in1, in2, in3, in4);
        scores[2] = P5(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T5: {
		static const int next[2] = { 24, 2 };
		fixedpt  scores[2];

        scores[0] = P12(in1, in2, in3, in4);
        scores[1] = P13(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T6: {
		static const int next[5] = { 19, 22, 20, 23, 1 };
		fixedpt  scores[5];

        scores[0] = P2(in1, in2, in3, in4);
        scores[1] = P14(in1, in2, in3, in4);
        scores[2] = P15(in1, in2, in3, in4);
        scores[3] = P8(in1, in2, in3, in4);
        scores[4] = P16(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T7: {
		static const int next[2] = { 6, 5 };
		fixedpt  scores[2];

        scores[0] = P17(in1, in2, in3, in4);
        scores[1] = P18(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T8: {
		static const int next[3] = { 5, 21, 6 };
		fixedpt  scores[3];

        scores[0] = P19(in1, in2, in3, in4);
        scores[1] = P20(in1, in2, in3, in4);
        scores[2] = P21(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T9: {
		static const int next[2] = { 6, 5 };
		fixedpt  scores[2];

        scores[0] = P22(in1, in2, in3, in4);
        scores[1] = P23(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T10: {
		static const int next[2] = { 5, 8 };
		fixedpt  scores[2];

        scores[0] = P24(in1, in2, in3, in4);
        scores[1] = P25(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T11: {
		static const int next[3] = { 9, 6, 10 };
		fixedpt  scores[3];

        scores[0] = P26(in1, in2, in3, in4);
        scores[1] = P27(in1, in2, in3, in4);
        scores[2] = P28(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T12: {
		static const int next[3] = { 10, 9, 6 };
		fixedpt  scores[3];

        scores[0] = P28(in1, in2, in3, in4);
        scores[1] = P29(in1, in2, in3, in4);
        scores[2] = P30(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T13: {
		static const int next[3] = { 10, 5, 9 };
		fixedpt  scores[3];

        scores[0] = P28(in1, in2, in3, in4);
        scores[1] = P31(in1, in2, in3, in4);
        scores[2] = P29(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T14: {
		static const int next[4] = { 10, 25, 5, 9 };
		fixedpt  scores[4];

        scores[0] = P28(in1, in2, in3, in4);
        scores[1] = P32(in1, in2, in3, in4);
        scores[2] = P33(in1, in2, in3, in4);
        scores[3] = P29(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T15: {
		static const int next[2] = { 14, 11 };
		fixedpt  scores[2];

        scores[0] = P34(in1, in2, in3, in4);
        scores[1] = P35(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T16: {
		static const int next[4] = { 3, 13, 7, 11 };
		fixedpt  scores[4];

        scores[0] = P36(in1, in2, in3, in4);
        scores[1] = P37(in1, in2, in3, in4);
        scores[2] = P38(in1, in2, in3, in4);
        scores[3] = P39(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T17: {
		static const int next[3] = { 9, 15, 4 };
		fixedpt  scores[3];

        scores[0] = P29(in1, in2, in3, in4);
        scores[1] = P40(in1, in2, in3, in4);
        scores[2] = P41(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T18: {
		static const int next[3] = { 17, 16, 12 };
		fixedpt  scores[3];

        scores[0] = P42(in1, in2, in3, in4);
        scores[1] = P43(in1, in2, in3, in4);
        scores[2] = P44(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_A4: actions[0] = 4; return;
L_A0: actions[0] = 0; return;
L_A6: actions[0] = 6; return;
L_A7: actions[0] = 7; return;
L_A5: actions[0] = 5; return;
L_A8: actions[0] = 8; return;
L_A1: actions[0] = 1; return;
}
