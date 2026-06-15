/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-05-28 21:30:48
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_T14, &&L_T15, &&L_T16, &&L_T17, &&L_T18, &&L_T19, &&L_T20, &&L_T21, &&L_T22, &&L_T23, &&L_A0, &&L_A8, &&L_A5, &&L_A3, &&L_A6, &&L_A4, &&L_A1
    };

	/* Initial dispatch — always start at T23 */
	goto *jump_table[23];	/* == &&L_T23 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[3] = { 26, 28, 29 };
		fixedpt  scores[3];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);
        scores[2] = P2(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T1: {
		static const int next[1] = { 0 };
		fixedpt  scores[1];

        scores[0] = P3(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 1)]];
	}

L_T2: {
		static const int next[2] = { 29, 1 };
		fixedpt  scores[2];

        scores[0] = P4(in1, in2, in3, in4);
        scores[1] = P5(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T3: {
		static const int next[4] = { 26, 24, 28, 30 };
		fixedpt  scores[4];

        scores[0] = P6(in1, in2, in3, in4);
        scores[1] = P7(in1, in2, in3, in4);
        scores[2] = P8(in1, in2, in3, in4);
        scores[3] = P9(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T4: {
		static const int next[2] = { 26, 28 };
		fixedpt  scores[2];

        scores[0] = P10(in1, in2, in3, in4);
        scores[1] = P11(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T5: {
		static const int next[1] = { 3 };
		fixedpt  scores[1];

        scores[0] = P12(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 1)]];
	}

L_T6: {
		static const int next[1] = { 5 };
		fixedpt  scores[1];

        scores[0] = P13(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 1)]];
	}

L_T7: {
		static const int next[2] = { 2, 4 };
		fixedpt  scores[2];

        scores[0] = P14(in1, in2, in3, in4);
        scores[1] = P15(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T8: {
		static const int next[3] = { 30, 7, 6 };
		fixedpt  scores[3];

        scores[0] = P16(in1, in2, in3, in4);
        scores[1] = P17(in1, in2, in3, in4);
        scores[2] = P18(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T9: {
		static const int next[3] = { 7, 30, 6 };
		fixedpt  scores[3];

        scores[0] = P19(in1, in2, in3, in4);
        scores[1] = P20(in1, in2, in3, in4);
        scores[2] = P18(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T10: {
		static const int next[4] = { 6, 7, 30, 7 };
		fixedpt  scores[4];

        scores[0] = P18(in1, in2, in3, in4);
        scores[1] = P21(in1, in2, in3, in4);
        scores[2] = P22(in1, in2, in3, in4);
        scores[3] = P23(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T11: {
		static const int next[3] = { 10, 30, 24 };
		fixedpt  scores[3];

        scores[0] = P24(in1, in2, in3, in4);
        scores[1] = P25(in1, in2, in3, in4);
        scores[2] = P26(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T12: {
		static const int next[3] = { 11, 30, 6 };
		fixedpt  scores[3];

        scores[0] = P27(in1, in2, in3, in4);
        scores[1] = P28(in1, in2, in3, in4);
        scores[2] = P29(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T13: {
		static const int next[3] = { 12, 11, 24 };
		fixedpt  scores[3];

        scores[0] = P30(in1, in2, in3, in4);
        scores[1] = P31(in1, in2, in3, in4);
        scores[2] = P32(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T14: {
		static const int next[2] = { 24, 6 };
		fixedpt  scores[2];

        scores[0] = P33(in1, in2, in3, in4);
        scores[1] = P34(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T15: {
		static const int next[4] = { 11, 27, 11, 8 };
		fixedpt  scores[4];

        scores[0] = P35(in1, in2, in3, in4);
        scores[1] = P36(in1, in2, in3, in4);
        scores[2] = P37(in1, in2, in3, in4);
        scores[3] = P38(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T16: {
		static const int next[3] = { 9, 15, 14 };
		fixedpt  scores[3];

        scores[0] = P39(in1, in2, in3, in4);
        scores[1] = P40(in1, in2, in3, in4);
        scores[2] = P41(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T17: {
		static const int next[2] = { 15, 14 };
		fixedpt  scores[2];

        scores[0] = P40(in1, in2, in3, in4);
        scores[1] = P41(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T18: {
		static const int next[1] = { 12 };
		fixedpt  scores[1];

        scores[0] = P42(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 1)]];
	}

L_T19: {
		static const int next[3] = { 27, 13, 16 };
		fixedpt  scores[3];

        scores[0] = P36(in1, in2, in3, in4);
        scores[1] = P43(in1, in2, in3, in4);
        scores[2] = P44(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T20: {
		static const int next[2] = { 27, 6 };
		fixedpt  scores[2];

        scores[0] = P36(in1, in2, in3, in4);
        scores[1] = P45(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T21: {
		static const int next[3] = { 20, 12, 16 };
		fixedpt  scores[3];

        scores[0] = P46(in1, in2, in3, in4);
        scores[1] = P42(in1, in2, in3, in4);
        scores[2] = P44(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T22: {
		static const int next[3] = { 21, 16, 17 };
		fixedpt  scores[3];

        scores[0] = P47(in1, in2, in3, in4);
        scores[1] = P44(in1, in2, in3, in4);
        scores[2] = P48(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T23: {
		static const int next[6] = { 16, 18, 25, 19, 27, 22 };
		fixedpt  scores[6];

        scores[0] = P49(in1, in2, in3, in4);
        scores[1] = P50(in1, in2, in3, in4);
        scores[2] = P51(in1, in2, in3, in4);
        scores[3] = P52(in1, in2, in3, in4);
        scores[4] = P53(in1, in2, in3, in4);
        scores[5] = P54(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_A0: actions[0] = 0; return;
L_A8: actions[0] = 8; return;
L_A5: actions[0] = 5; return;
L_A3: actions[0] = 3; return;
L_A6: actions[0] = 6; return;
L_A4: actions[0] = 4; return;
L_A1: actions[0] = 1; return;
}
