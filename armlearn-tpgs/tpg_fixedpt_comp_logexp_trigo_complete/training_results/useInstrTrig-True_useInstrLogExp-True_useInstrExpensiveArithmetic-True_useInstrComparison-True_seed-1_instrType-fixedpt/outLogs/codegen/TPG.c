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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_T14, &&L_T15, &&L_T16, &&L_T17, &&L_T18, &&L_T19, &&L_A5, &&L_A6, &&L_A4, &&L_A0, &&L_A3, &&L_A2, &&L_A1
    };

	/* Initial dispatch — always start at T19 */
	goto *jump_table[19];	/* == &&L_T19 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[4] = { 22, 23, 24, 24 };
		fixedpt  scores[4];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);
        scores[2] = P2(in1, in2, in3, in4);
        scores[3] = P3(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T1: {
		static const int next[4] = { 22, 23, 21, 24 };
		fixedpt  scores[4];

        scores[0] = P4(in1, in2, in3, in4);
        scores[1] = P5(in1, in2, in3, in4);
        scores[2] = P6(in1, in2, in3, in4);
        scores[3] = P7(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T2: {
		static const int next[3] = { 1, 24, 21 };
		fixedpt  scores[3];

        scores[0] = P8(in1, in2, in3, in4);
        scores[1] = P9(in1, in2, in3, in4);
        scores[2] = P10(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T3: {
		static const int next[2] = { 1, 0 };
		fixedpt  scores[2];

        scores[0] = P11(in1, in2, in3, in4);
        scores[1] = P12(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T4: {
		static const int next[2] = { 1, 24 };
		fixedpt  scores[2];

        scores[0] = P11(in1, in2, in3, in4);
        scores[1] = P13(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T5: {
		static const int next[4] = { 1, 21, 25, 2 };
		fixedpt  scores[4];

        scores[0] = P11(in1, in2, in3, in4);
        scores[1] = P14(in1, in2, in3, in4);
        scores[2] = P15(in1, in2, in3, in4);
        scores[3] = P16(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T6: {
		static const int next[4] = { 1, 24, 21, 21 };
		fixedpt  scores[4];

        scores[0] = P17(in1, in2, in3, in4);
        scores[1] = P18(in1, in2, in3, in4);
        scores[2] = P19(in1, in2, in3, in4);
        scores[3] = P20(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T7: {
		static const int next[3] = { 25, 1, 4 };
		fixedpt  scores[3];

        scores[0] = P15(in1, in2, in3, in4);
        scores[1] = P21(in1, in2, in3, in4);
        scores[2] = P22(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T8: {
		static const int next[2] = { 1, 4 };
		fixedpt  scores[2];

        scores[0] = P23(in1, in2, in3, in4);
        scores[1] = P22(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T9: {
		static const int next[4] = { 7, 6, 1, 25 };
		fixedpt  scores[4];

        scores[0] = P24(in1, in2, in3, in4);
        scores[1] = P25(in1, in2, in3, in4);
        scores[2] = P11(in1, in2, in3, in4);
        scores[3] = P26(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T10: {
		static const int next[4] = { 3, 25, 7, 5 };
		fixedpt  scores[4];

        scores[0] = P27(in1, in2, in3, in4);
        scores[1] = P28(in1, in2, in3, in4);
        scores[2] = P24(in1, in2, in3, in4);
        scores[3] = P29(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T11: {
		static const int next[4] = { 3, 9, 24, 7 };
		fixedpt  scores[4];

        scores[0] = P30(in1, in2, in3, in4);
        scores[1] = P31(in1, in2, in3, in4);
        scores[2] = P32(in1, in2, in3, in4);
        scores[3] = P24(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T12: {
		static const int next[6] = { 5, 5, 10, 7, 1, 25 };
		fixedpt  scores[6];

        scores[0] = P33(in1, in2, in3, in4);
        scores[1] = P34(in1, in2, in3, in4);
        scores[2] = P35(in1, in2, in3, in4);
        scores[3] = P36(in1, in2, in3, in4);
        scores[4] = P37(in1, in2, in3, in4);
        scores[5] = P15(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T13: {
		static const int next[7] = { 3, 9, 8, 20, 7, 7, 11 };
		fixedpt  scores[7];

        scores[0] = P30(in1, in2, in3, in4);
        scores[1] = P38(in1, in2, in3, in4);
        scores[2] = P39(in1, in2, in3, in4);
        scores[3] = P40(in1, in2, in3, in4);
        scores[4] = P41(in1, in2, in3, in4);
        scores[5] = P24(in1, in2, in3, in4);
        scores[6] = P42(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 7)]];
	}

L_T14: {
		static const int next[4] = { 3, 12, 2, 9 };
		fixedpt  scores[4];

        scores[0] = P27(in1, in2, in3, in4);
        scores[1] = P43(in1, in2, in3, in4);
        scores[2] = P44(in1, in2, in3, in4);
        scores[3] = P31(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T15: {
		static const int next[4] = { 3, 12, 20, 9 };
		fixedpt  scores[4];

        scores[0] = P27(in1, in2, in3, in4);
        scores[1] = P43(in1, in2, in3, in4);
        scores[2] = P45(in1, in2, in3, in4);
        scores[3] = P31(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T16: {
		static const int next[2] = { 14, 24 };
		fixedpt  scores[2];

        scores[0] = P46(in1, in2, in3, in4);
        scores[1] = P32(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T17: {
		static const int next[3] = { 16, 15, 13 };
		fixedpt  scores[3];

        scores[0] = P47(in1, in2, in3, in4);
        scores[1] = P48(in1, in2, in3, in4);
        scores[2] = P49(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T18: {
		static const int next[6] = { 9, 14, 26, 12, 20, 15 };
		fixedpt  scores[6];

        scores[0] = P50(in1, in2, in3, in4);
        scores[1] = P51(in1, in2, in3, in4);
        scores[2] = P52(in1, in2, in3, in4);
        scores[3] = P53(in1, in2, in3, in4);
        scores[4] = P54(in1, in2, in3, in4);
        scores[5] = P55(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T19: {
		static const int next[9] = { 18, 1, 20, 21, 20, 9, 1, 17, 15 };
		fixedpt  scores[9];

        scores[0] = P56(in1, in2, in3, in4);
        scores[1] = P57(in1, in2, in3, in4);
        scores[2] = P58(in1, in2, in3, in4);
        scores[3] = P59(in1, in2, in3, in4);
        scores[4] = P60(in1, in2, in3, in4);
        scores[5] = P61(in1, in2, in3, in4);
        scores[6] = P11(in1, in2, in3, in4);
        scores[7] = P62(in1, in2, in3, in4);
        scores[8] = P55(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 9)]];
	}

L_A5: actions[0] = 5; return;
L_A6: actions[0] = 6; return;
L_A4: actions[0] = 4; return;
L_A0: actions[0] = 0; return;
L_A3: actions[0] = 3; return;
L_A2: actions[0] = 2; return;
L_A1: actions[0] = 1; return;
}
