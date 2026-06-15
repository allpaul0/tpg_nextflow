/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-05-28 21:29:07
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_T14, &&L_T15, &&L_T16, &&L_T17, &&L_T18, &&L_T19, &&L_T20, &&L_T21, &&L_T22, &&L_A5, &&L_A6, &&L_A4, &&L_A3, &&L_A0, &&L_A1
    };

	/* Initial dispatch — always start at T22 */
	goto *jump_table[22];	/* == &&L_T22 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[5] = { 24, 26, 25, 23, 27 };
		fixedpt  scores[5];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);
        scores[2] = P2(in1, in2, in3, in4);
        scores[3] = P3(in1, in2, in3, in4);
        scores[4] = P4(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T1: {
		static const int next[3] = { 24, 23, 25 };
		fixedpt  scores[3];

        scores[0] = P5(in1, in2, in3, in4);
        scores[1] = P6(in1, in2, in3, in4);
        scores[2] = P7(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T2: {
		static const int next[4] = { 24, 25, 27, 23 };
		fixedpt  scores[4];

        scores[0] = P8(in1, in2, in3, in4);
        scores[1] = P2(in1, in2, in3, in4);
        scores[2] = P9(in1, in2, in3, in4);
        scores[3] = P10(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T3: {
		static const int next[5] = { 24, 25, 26, 27, 0 };
		fixedpt  scores[5];

        scores[0] = P8(in1, in2, in3, in4);
        scores[1] = P2(in1, in2, in3, in4);
        scores[2] = P11(in1, in2, in3, in4);
        scores[3] = P9(in1, in2, in3, in4);
        scores[4] = P12(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T4: {
		static const int next[3] = { 3, 0, 24 };
		fixedpt  scores[3];

        scores[0] = P13(in1, in2, in3, in4);
        scores[1] = P14(in1, in2, in3, in4);
        scores[2] = P15(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T5: {
		static const int next[3] = { 28, 4, 1 };
		fixedpt  scores[3];

        scores[0] = P16(in1, in2, in3, in4);
        scores[1] = P17(in1, in2, in3, in4);
        scores[2] = P18(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T6: {
		static const int next[3] = { 4, 1, 28 };
		fixedpt  scores[3];

        scores[0] = P19(in1, in2, in3, in4);
        scores[1] = P20(in1, in2, in3, in4);
        scores[2] = P21(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T7: {
		static const int next[1] = { 6 };
		fixedpt  scores[1];

        scores[0] = P22(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 1)]];
	}

L_T8: {
		static const int next[4] = { 1, 28, 5, 0 };
		fixedpt  scores[4];

        scores[0] = P23(in1, in2, in3, in4);
        scores[1] = P24(in1, in2, in3, in4);
        scores[2] = P25(in1, in2, in3, in4);
        scores[3] = P14(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T9: {
		static const int next[5] = { 4, 28, 2, 26, 24 };
		fixedpt  scores[5];

        scores[0] = P26(in1, in2, in3, in4);
        scores[1] = P24(in1, in2, in3, in4);
        scores[2] = P27(in1, in2, in3, in4);
        scores[3] = P11(in1, in2, in3, in4);
        scores[4] = P28(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T10: {
		static const int next[5] = { 4, 23, 2, 28, 28 };
		fixedpt  scores[5];

        scores[0] = P26(in1, in2, in3, in4);
        scores[1] = P29(in1, in2, in3, in4);
        scores[2] = P30(in1, in2, in3, in4);
        scores[3] = P31(in1, in2, in3, in4);
        scores[4] = P24(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T11: {
		static const int next[4] = { 4, 10, 7, 8 };
		fixedpt  scores[4];

        scores[0] = P32(in1, in2, in3, in4);
        scores[1] = P33(in1, in2, in3, in4);
        scores[2] = P34(in1, in2, in3, in4);
        scores[3] = P35(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T12: {
		static const int next[4] = { 9, 8, 7, 10 };
		fixedpt  scores[4];

        scores[0] = P36(in1, in2, in3, in4);
        scores[1] = P37(in1, in2, in3, in4);
        scores[2] = P34(in1, in2, in3, in4);
        scores[3] = P33(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T13: {
		static const int next[5] = { 8, 27, 1, 10, 0 };
		fixedpt  scores[5];

        scores[0] = P38(in1, in2, in3, in4);
        scores[1] = P39(in1, in2, in3, in4);
        scores[2] = P40(in1, in2, in3, in4);
        scores[3] = P33(in1, in2, in3, in4);
        scores[4] = P41(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T14: {
		static const int next[4] = { 27, 1, 10, 8 };
		fixedpt  scores[4];

        scores[0] = P39(in1, in2, in3, in4);
        scores[1] = P40(in1, in2, in3, in4);
        scores[2] = P42(in1, in2, in3, in4);
        scores[3] = P35(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T15: {
		static const int next[3] = { 6, 11, 13 };
		fixedpt  scores[3];

        scores[0] = P43(in1, in2, in3, in4);
        scores[1] = P44(in1, in2, in3, in4);
        scores[2] = P45(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T16: {
		static const int next[2] = { 13, 9 };
		fixedpt  scores[2];

        scores[0] = P46(in1, in2, in3, in4);
        scores[1] = P47(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T17: {
		static const int next[2] = { 9, 12 };
		fixedpt  scores[2];

        scores[0] = P48(in1, in2, in3, in4);
        scores[1] = P49(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T18: {
		static const int next[2] = { 15, 17 };
		fixedpt  scores[2];

        scores[0] = P50(in1, in2, in3, in4);
        scores[1] = P51(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T19: {
		static const int next[3] = { 13, 14, 16 };
		fixedpt  scores[3];

        scores[0] = P52(in1, in2, in3, in4);
        scores[1] = P53(in1, in2, in3, in4);
        scores[2] = P54(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T20: {
		static const int next[2] = { 15, 9 };
		fixedpt  scores[2];

        scores[0] = P55(in1, in2, in3, in4);
        scores[1] = P56(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T21: {
		static const int next[3] = { 18, 12, 19 };
		fixedpt  scores[3];

        scores[0] = P57(in1, in2, in3, in4);
        scores[1] = P58(in1, in2, in3, in4);
        scores[2] = P59(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T22: {
		static const int next[5] = { 26, 21, 20, 28, 18 };
		fixedpt  scores[5];

        scores[0] = P60(in1, in2, in3, in4);
        scores[1] = P61(in1, in2, in3, in4);
        scores[2] = P62(in1, in2, in3, in4);
        scores[3] = P63(in1, in2, in3, in4);
        scores[4] = P64(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_A5: actions[0] = 5; return;
L_A6: actions[0] = 6; return;
L_A4: actions[0] = 4; return;
L_A3: actions[0] = 3; return;
L_A0: actions[0] = 0; return;
L_A1: actions[0] = 1; return;
}
