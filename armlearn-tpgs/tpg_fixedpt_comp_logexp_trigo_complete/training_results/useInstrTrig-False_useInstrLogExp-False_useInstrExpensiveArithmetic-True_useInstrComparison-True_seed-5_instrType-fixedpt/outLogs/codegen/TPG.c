/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:10:24
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_T14, &&L_T15, &&L_T16, &&L_T17, &&L_A3, &&L_A4, &&L_A8, &&L_A0, &&L_A6, &&L_A5, &&L_A7
    };

	/* Initial dispatch — always start at T17 */
	goto *jump_table[17];	/* == &&L_T17 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[2] = { 18, 22 };
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
		static const int next[3] = { 22, 19, 18 };
		fixedpt  scores[3];

        scores[0] = P4(in1, in2, in3, in4);
        scores[1] = P5(in1, in2, in3, in4);
        scores[2] = P6(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T3: {
		static const int next[4] = { 19, 1, 23, 22 };
		fixedpt  scores[4];

        scores[0] = P7(in1, in2, in3, in4);
        scores[1] = P8(in1, in2, in3, in4);
        scores[2] = P9(in1, in2, in3, in4);
        scores[3] = P4(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T4: {
		static const int next[4] = { 0, 2, 18, 21 };
		fixedpt  scores[4];

        scores[0] = P10(in1, in2, in3, in4);
        scores[1] = P11(in1, in2, in3, in4);
        scores[2] = P12(in1, in2, in3, in4);
        scores[3] = P13(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T5: {
		static const int next[3] = { 0, 4, 23 };
		fixedpt  scores[3];

        scores[0] = P10(in1, in2, in3, in4);
        scores[1] = P14(in1, in2, in3, in4);
        scores[2] = P15(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T6: {
		static const int next[3] = { 4, 5, 22 };
		fixedpt  scores[3];

        scores[0] = P16(in1, in2, in3, in4);
        scores[1] = P17(in1, in2, in3, in4);
        scores[2] = P4(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T7: {
		static const int next[2] = { 4, 24 };
		fixedpt  scores[2];

        scores[0] = P18(in1, in2, in3, in4);
        scores[1] = P19(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T8: {
		static const int next[6] = { 18, 4, 3, 7, 22, 24 };
		fixedpt  scores[6];

        scores[0] = P20(in1, in2, in3, in4);
        scores[1] = P21(in1, in2, in3, in4);
        scores[2] = P22(in1, in2, in3, in4);
        scores[3] = P23(in1, in2, in3, in4);
        scores[4] = P24(in1, in2, in3, in4);
        scores[5] = P19(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T9: {
		static const int next[5] = { 21, 18, 8, 6, 22 };
		fixedpt  scores[5];

        scores[0] = P25(in1, in2, in3, in4);
        scores[1] = P26(in1, in2, in3, in4);
        scores[2] = P27(in1, in2, in3, in4);
        scores[3] = P28(in1, in2, in3, in4);
        scores[4] = P29(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T10: {
		static const int next[4] = { 6, 7, 7, 3 };
		fixedpt  scores[4];

        scores[0] = P30(in1, in2, in3, in4);
        scores[1] = P31(in1, in2, in3, in4);
        scores[2] = P32(in1, in2, in3, in4);
        scores[3] = P33(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T11: {
		static const int next[4] = { 6, 10, 7, 6 };
		fixedpt  scores[4];

        scores[0] = P34(in1, in2, in3, in4);
        scores[1] = P35(in1, in2, in3, in4);
        scores[2] = P36(in1, in2, in3, in4);
        scores[3] = P37(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T12: {
		static const int next[4] = { 6, 6, 3, 7 };
		fixedpt  scores[4];

        scores[0] = P30(in1, in2, in3, in4);
        scores[1] = P38(in1, in2, in3, in4);
        scores[2] = P33(in1, in2, in3, in4);
        scores[3] = P36(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T13: {
		static const int next[4] = { 6, 10, 23, 7 };
		fixedpt  scores[4];

        scores[0] = P34(in1, in2, in3, in4);
        scores[1] = P39(in1, in2, in3, in4);
        scores[2] = P40(in1, in2, in3, in4);
        scores[3] = P36(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T14: {
		static const int next[2] = { 12, 9 };
		fixedpt  scores[2];

        scores[0] = P41(in1, in2, in3, in4);
        scores[1] = P42(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T15: {
		static const int next[4] = { 11, 9, 23, 13 };
		fixedpt  scores[4];

        scores[0] = P43(in1, in2, in3, in4);
        scores[1] = P44(in1, in2, in3, in4);
        scores[2] = P45(in1, in2, in3, in4);
        scores[3] = P46(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T16: {
		static const int next[6] = { 12, 9, 7, 9, 11, 13 };
		fixedpt  scores[6];

        scores[0] = P47(in1, in2, in3, in4);
        scores[1] = P48(in1, in2, in3, in4);
        scores[2] = P36(in1, in2, in3, in4);
        scores[3] = P49(in1, in2, in3, in4);
        scores[4] = P43(in1, in2, in3, in4);
        scores[5] = P46(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T17: {
		static const int next[4] = { 9, 16, 15, 14 };
		fixedpt  scores[4];

        scores[0] = P50(in1, in2, in3, in4);
        scores[1] = P51(in1, in2, in3, in4);
        scores[2] = P52(in1, in2, in3, in4);
        scores[3] = P53(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_A3: actions[0] = 3; return;
L_A4: actions[0] = 4; return;
L_A8: actions[0] = 8; return;
L_A0: actions[0] = 0; return;
L_A6: actions[0] = 6; return;
L_A5: actions[0] = 5; return;
L_A7: actions[0] = 7; return;
}
