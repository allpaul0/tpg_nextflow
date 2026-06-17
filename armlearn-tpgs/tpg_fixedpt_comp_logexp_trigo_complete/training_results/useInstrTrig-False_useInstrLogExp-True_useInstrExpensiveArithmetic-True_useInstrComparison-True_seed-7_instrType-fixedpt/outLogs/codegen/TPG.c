/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:09:58
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_A5, &&L_A6, &&L_A3, &&L_A4, &&L_A7, &&L_A2, &&L_A0
    };

	/* Initial dispatch — always start at T13 */
	goto *jump_table[13];	/* == &&L_T13 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[2] = { 14, 15 };
		fixedpt  scores[2];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T1: {
		static const int next[3] = { 16, 18, 17 };
		fixedpt  scores[3];

        scores[0] = P2(in1, in2, in3, in4);
        scores[1] = P3(in1, in2, in3, in4);
        scores[2] = P4(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T2: {
		static const int next[5] = { 17, 14, 16, 1, 15 };
		fixedpt  scores[5];

        scores[0] = P5(in1, in2, in3, in4);
        scores[1] = P6(in1, in2, in3, in4);
        scores[2] = P7(in1, in2, in3, in4);
        scores[3] = P8(in1, in2, in3, in4);
        scores[4] = P9(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T3: {
		static const int next[4] = { 17, 20, 14, 15 };
		fixedpt  scores[4];

        scores[0] = P10(in1, in2, in3, in4);
        scores[1] = P11(in1, in2, in3, in4);
        scores[2] = P12(in1, in2, in3, in4);
        scores[3] = P13(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T4: {
		static const int next[4] = { 1, 0, 15, 17 };
		fixedpt  scores[4];

        scores[0] = P14(in1, in2, in3, in4);
        scores[1] = P15(in1, in2, in3, in4);
        scores[2] = P16(in1, in2, in3, in4);
        scores[3] = P17(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T5: {
		static const int next[5] = { 1, 14, 3, 16, 15 };
		fixedpt  scores[5];

        scores[0] = P18(in1, in2, in3, in4);
        scores[1] = P19(in1, in2, in3, in4);
        scores[2] = P20(in1, in2, in3, in4);
        scores[3] = P7(in1, in2, in3, in4);
        scores[4] = P21(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T6: {
		static const int next[4] = { 2, 15, 3, 16 };
		fixedpt  scores[4];

        scores[0] = P22(in1, in2, in3, in4);
        scores[1] = P23(in1, in2, in3, in4);
        scores[2] = P20(in1, in2, in3, in4);
        scores[3] = P24(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T7: {
		static const int next[5] = { 14, 18, 16, 15, 3 };
		fixedpt  scores[5];

        scores[0] = P25(in1, in2, in3, in4);
        scores[1] = P26(in1, in2, in3, in4);
        scores[2] = P27(in1, in2, in3, in4);
        scores[3] = P28(in1, in2, in3, in4);
        scores[4] = P29(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T8: {
		static const int next[2] = { 6, 5 };
		fixedpt  scores[2];

        scores[0] = P30(in1, in2, in3, in4);
        scores[1] = P31(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T9: {
		static const int next[4] = { 4, 7, 7, 5 };
		fixedpt  scores[4];

        scores[0] = P32(in1, in2, in3, in4);
        scores[1] = P33(in1, in2, in3, in4);
        scores[2] = P34(in1, in2, in3, in4);
        scores[3] = P35(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T10: {
		static const int next[6] = { 9, 6, 7, 8, 4, 5 };
		fixedpt  scores[6];

        scores[0] = P36(in1, in2, in3, in4);
        scores[1] = P37(in1, in2, in3, in4);
        scores[2] = P38(in1, in2, in3, in4);
        scores[3] = P39(in1, in2, in3, in4);
        scores[4] = P32(in1, in2, in3, in4);
        scores[5] = P35(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T11: {
		static const int next[5] = { 17, 3, 10, 18, 5 };
		fixedpt  scores[5];

        scores[0] = P40(in1, in2, in3, in4);
        scores[1] = P41(in1, in2, in3, in4);
        scores[2] = P42(in1, in2, in3, in4);
        scores[3] = P26(in1, in2, in3, in4);
        scores[4] = P43(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T12: {
		static const int next[3] = { 17, 10, 19 };
		fixedpt  scores[3];

        scores[0] = P40(in1, in2, in3, in4);
        scores[1] = P42(in1, in2, in3, in4);
        scores[2] = P44(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T13: {
		static const int next[4] = { 11, 12, 19, 11 };
		fixedpt  scores[4];

        scores[0] = P45(in1, in2, in3, in4);
        scores[1] = P46(in1, in2, in3, in4);
        scores[2] = P47(in1, in2, in3, in4);
        scores[3] = P48(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_A5: actions[0] = 5; return;
L_A6: actions[0] = 6; return;
L_A3: actions[0] = 3; return;
L_A4: actions[0] = 4; return;
L_A7: actions[0] = 7; return;
L_A2: actions[0] = 2; return;
L_A0: actions[0] = 0; return;
}
