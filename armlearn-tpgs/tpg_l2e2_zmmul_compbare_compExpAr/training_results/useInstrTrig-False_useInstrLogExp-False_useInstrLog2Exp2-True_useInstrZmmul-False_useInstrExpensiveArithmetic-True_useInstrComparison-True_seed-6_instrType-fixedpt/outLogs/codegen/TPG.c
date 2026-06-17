/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-05-28 21:30:38
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_T14, &&L_T15, &&L_T16, &&L_T17, &&L_A4, &&L_A5, &&L_A6, &&L_A3, &&L_A8, &&L_A0, &&L_A1
    };

	/* Initial dispatch — always start at T17 */
	goto *jump_table[17];	/* == &&L_T17 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[2] = { 19, 20 };
		fixedpt  scores[2];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T1: {
		static const int next[2] = { 20, 21 };
		fixedpt  scores[2];

        scores[0] = P2(in1, in2, in3, in4);
        scores[1] = P3(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T2: {
		static const int next[3] = { 0, 18, 22 };
		fixedpt  scores[3];

        scores[0] = P4(in1, in2, in3, in4);
        scores[1] = P5(in1, in2, in3, in4);
        scores[2] = P6(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T3: {
		static const int next[4] = { 23, 0, 18, 20 };
		fixedpt  scores[4];

        scores[0] = P7(in1, in2, in3, in4);
        scores[1] = P8(in1, in2, in3, in4);
        scores[2] = P9(in1, in2, in3, in4);
        scores[3] = P2(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T4: {
		static const int next[1] = { 3 };
		fixedpt  scores[1];

        scores[0] = P10(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 1)]];
	}

L_T5: {
		static const int next[1] = { 3 };
		fixedpt  scores[1];

        scores[0] = P11(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 1)]];
	}

L_T6: {
		static const int next[5] = { 20, 21, 23, 18, 23 };
		fixedpt  scores[5];

        scores[0] = P12(in1, in2, in3, in4);
        scores[1] = P13(in1, in2, in3, in4);
        scores[2] = P7(in1, in2, in3, in4);
        scores[3] = P9(in1, in2, in3, in4);
        scores[4] = P14(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T7: {
		static const int next[2] = { 5, 1 };
		fixedpt  scores[2];

        scores[0] = P15(in1, in2, in3, in4);
        scores[1] = P16(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T8: {
		static const int next[2] = { 4, 1 };
		fixedpt  scores[2];

        scores[0] = P17(in1, in2, in3, in4);
        scores[1] = P16(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T9: {
		static const int next[4] = { 18, 6, 0, 3 };
		fixedpt  scores[4];

        scores[0] = P18(in1, in2, in3, in4);
        scores[1] = P19(in1, in2, in3, in4);
        scores[2] = P20(in1, in2, in3, in4);
        scores[3] = P11(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T10: {
		static const int next[3] = { 7, 18, 19 };
		fixedpt  scores[3];

        scores[0] = P21(in1, in2, in3, in4);
        scores[1] = P18(in1, in2, in3, in4);
        scores[2] = P22(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T11: {
		static const int next[5] = { 7, 19, 23, 8, 18 };
		fixedpt  scores[5];

        scores[0] = P23(in1, in2, in3, in4);
        scores[1] = P22(in1, in2, in3, in4);
        scores[2] = P24(in1, in2, in3, in4);
        scores[3] = P25(in1, in2, in3, in4);
        scores[4] = P18(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T12: {
		static const int next[5] = { 11, 2, 10, 2, 23 };
		fixedpt  scores[5];

        scores[0] = P26(in1, in2, in3, in4);
        scores[1] = P27(in1, in2, in3, in4);
        scores[2] = P28(in1, in2, in3, in4);
        scores[3] = P29(in1, in2, in3, in4);
        scores[4] = P30(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T13: {
		static const int next[6] = { 2, 9, 6, 8, 11, 6 };
		fixedpt  scores[6];

        scores[0] = P31(in1, in2, in3, in4);
        scores[1] = P32(in1, in2, in3, in4);
        scores[2] = P33(in1, in2, in3, in4);
        scores[3] = P34(in1, in2, in3, in4);
        scores[4] = P35(in1, in2, in3, in4);
        scores[5] = P36(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T14: {
		static const int next[5] = { 2, 8, 10, 12, 18 };
		fixedpt  scores[5];

        scores[0] = P27(in1, in2, in3, in4);
        scores[1] = P34(in1, in2, in3, in4);
        scores[2] = P37(in1, in2, in3, in4);
        scores[3] = P38(in1, in2, in3, in4);
        scores[4] = P39(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T15: {
		static const int next[2] = { 3, 8 };
		fixedpt  scores[2];

        scores[0] = P40(in1, in2, in3, in4);
        scores[1] = P34(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T16: {
		static const int next[7] = { 2, 14, 6, 13, 15, 13, 24 };
		fixedpt  scores[7];

        scores[0] = P41(in1, in2, in3, in4);
        scores[1] = P42(in1, in2, in3, in4);
        scores[2] = P43(in1, in2, in3, in4);
        scores[3] = P44(in1, in2, in3, in4);
        scores[4] = P45(in1, in2, in3, in4);
        scores[5] = P46(in1, in2, in3, in4);
        scores[6] = P47(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 7)]];
	}

L_T17: {
		static const int next[5] = { 6, 24, 16, 14, 0 };
		fixedpt  scores[5];

        scores[0] = P48(in1, in2, in3, in4);
        scores[1] = P49(in1, in2, in3, in4);
        scores[2] = P50(in1, in2, in3, in4);
        scores[3] = P42(in1, in2, in3, in4);
        scores[4] = P51(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_A4: actions[0] = 4; return;
L_A5: actions[0] = 5; return;
L_A6: actions[0] = 6; return;
L_A3: actions[0] = 3; return;
L_A8: actions[0] = 8; return;
L_A0: actions[0] = 0; return;
L_A1: actions[0] = 1; return;
}
