/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:10:18
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_T14, &&L_T15, &&L_T16, &&L_T17, &&L_T18, &&L_T19, &&L_A4, &&L_A5, &&L_A6, &&L_A2, &&L_A0, &&L_A8
    };

	/* Initial dispatch — always start at T19 */
	goto *jump_table[19];	/* == &&L_T19 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[3] = { 22, 23, 20 };
		fixedpt  scores[3];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);
        scores[2] = P2(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T1: {
		static const int next[3] = { 21, 25, 23 };
		fixedpt  scores[3];

        scores[0] = P3(in1, in2, in3, in4);
        scores[1] = P4(in1, in2, in3, in4);
        scores[2] = P5(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T2: {
		static const int next[5] = { 22, 25, 21, 20, 22 };
		fixedpt  scores[5];

        scores[0] = P6(in1, in2, in3, in4);
        scores[1] = P7(in1, in2, in3, in4);
        scores[2] = P8(in1, in2, in3, in4);
        scores[3] = P9(in1, in2, in3, in4);
        scores[4] = P10(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T3: {
		static const int next[4] = { 22, 0, 24, 21 };
		fixedpt  scores[4];

        scores[0] = P11(in1, in2, in3, in4);
        scores[1] = P12(in1, in2, in3, in4);
        scores[2] = P13(in1, in2, in3, in4);
        scores[3] = P14(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T4: {
		static const int next[3] = { 1, 22, 3 };
		fixedpt  scores[3];

        scores[0] = P15(in1, in2, in3, in4);
        scores[1] = P16(in1, in2, in3, in4);
        scores[2] = P17(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T5: {
		static const int next[4] = { 22, 0, 21, 24 };
		fixedpt  scores[4];

        scores[0] = P18(in1, in2, in3, in4);
        scores[1] = P19(in1, in2, in3, in4);
        scores[2] = P20(in1, in2, in3, in4);
        scores[3] = P21(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T6: {
		static const int next[2] = { 23, 5 };
		fixedpt  scores[2];

        scores[0] = P22(in1, in2, in3, in4);
        scores[1] = P23(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T7: {
		static const int next[4] = { 21, 5, 23, 20 };
		fixedpt  scores[4];

        scores[0] = P24(in1, in2, in3, in4);
        scores[1] = P23(in1, in2, in3, in4);
        scores[2] = P22(in1, in2, in3, in4);
        scores[3] = P25(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T8: {
		static const int next[5] = { 24, 4, 20, 21, 6 };
		fixedpt  scores[5];

        scores[0] = P26(in1, in2, in3, in4);
        scores[1] = P27(in1, in2, in3, in4);
        scores[2] = P25(in1, in2, in3, in4);
        scores[3] = P8(in1, in2, in3, in4);
        scores[4] = P28(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T9: {
		static const int next[3] = { 2, 4, 7 };
		fixedpt  scores[3];

        scores[0] = P29(in1, in2, in3, in4);
        scores[1] = P30(in1, in2, in3, in4);
        scores[2] = P31(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T10: {
		static const int next[3] = { 4, 7, 2 };
		fixedpt  scores[3];

        scores[0] = P32(in1, in2, in3, in4);
        scores[1] = P31(in1, in2, in3, in4);
        scores[2] = P33(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T11: {
		static const int next[3] = { 10, 8, 7 };
		fixedpt  scores[3];

        scores[0] = P34(in1, in2, in3, in4);
        scores[1] = P35(in1, in2, in3, in4);
        scores[2] = P31(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T12: {
		static const int next[2] = { 10, 7 };
		fixedpt  scores[2];

        scores[0] = P36(in1, in2, in3, in4);
        scores[1] = P31(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T13: {
		static const int next[2] = { 7, 7 };
		fixedpt  scores[2];

        scores[0] = P37(in1, in2, in3, in4);
        scores[1] = P31(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T14: {
		static const int next[4] = { 8, 8, 7, 11 };
		fixedpt  scores[4];

        scores[0] = P38(in1, in2, in3, in4);
        scores[1] = P39(in1, in2, in3, in4);
        scores[2] = P31(in1, in2, in3, in4);
        scores[3] = P40(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T15: {
		static const int next[4] = { 9, 8, 7, 12 };
		fixedpt  scores[4];

        scores[0] = P41(in1, in2, in3, in4);
        scores[1] = P38(in1, in2, in3, in4);
        scores[2] = P31(in1, in2, in3, in4);
        scores[3] = P42(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T16: {
		static const int next[7] = { 4, 12, 20, 11, 15, 2, 11 };
		fixedpt  scores[7];

        scores[0] = P43(in1, in2, in3, in4);
        scores[1] = P44(in1, in2, in3, in4);
        scores[2] = P25(in1, in2, in3, in4);
        scores[3] = P40(in1, in2, in3, in4);
        scores[4] = P45(in1, in2, in3, in4);
        scores[5] = P33(in1, in2, in3, in4);
        scores[6] = P46(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 7)]];
	}

L_T17: {
		static const int next[5] = { 20, 14, 12, 10, 11 };
		fixedpt  scores[5];

        scores[0] = P47(in1, in2, in3, in4);
        scores[1] = P48(in1, in2, in3, in4);
        scores[2] = P42(in1, in2, in3, in4);
        scores[3] = P34(in1, in2, in3, in4);
        scores[4] = P49(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T18: {
		static const int next[4] = { 7, 4, 17, 7 };
		fixedpt  scores[4];

        scores[0] = P50(in1, in2, in3, in4);
        scores[1] = P51(in1, in2, in3, in4);
        scores[2] = P52(in1, in2, in3, in4);
        scores[3] = P31(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T19: {
		static const int next[6] = { 4, 18, 17, 16, 8, 13 };
		fixedpt  scores[6];

        scores[0] = P53(in1, in2, in3, in4);
        scores[1] = P54(in1, in2, in3, in4);
        scores[2] = P55(in1, in2, in3, in4);
        scores[3] = P56(in1, in2, in3, in4);
        scores[4] = P57(in1, in2, in3, in4);
        scores[5] = P58(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_A4: actions[0] = 4; return;
L_A5: actions[0] = 5; return;
L_A6: actions[0] = 6; return;
L_A2: actions[0] = 2; return;
L_A0: actions[0] = 0; return;
L_A8: actions[0] = 8; return;
}
