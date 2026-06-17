/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:10:16
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_A5, &&L_A6, &&L_A4, &&L_A0, &&L_A3, &&L_A8, &&L_A2
    };

	/* Initial dispatch — always start at T13 */
	goto *jump_table[13];	/* == &&L_T13 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[3] = { 18, 16, 15 };
		fixedpt  scores[3];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);
        scores[2] = P2(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T1: {
		static const int next[2] = { 0, 17 };
		fixedpt  scores[2];

        scores[0] = P3(in1, in2, in3, in4);
        scores[1] = P4(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T2: {
		static const int next[4] = { 14, 15, 17, 0 };
		fixedpt  scores[4];

        scores[0] = P5(in1, in2, in3, in4);
        scores[1] = P6(in1, in2, in3, in4);
        scores[2] = P7(in1, in2, in3, in4);
        scores[3] = P8(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T3: {
		static const int next[4] = { 14, 1, 15, 19 };
		fixedpt  scores[4];

        scores[0] = P9(in1, in2, in3, in4);
        scores[1] = P10(in1, in2, in3, in4);
        scores[2] = P11(in1, in2, in3, in4);
        scores[3] = P12(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T4: {
		static const int next[4] = { 14, 0, 19, 15 };
		fixedpt  scores[4];

        scores[0] = P13(in1, in2, in3, in4);
        scores[1] = P3(in1, in2, in3, in4);
        scores[2] = P12(in1, in2, in3, in4);
        scores[3] = P11(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T5: {
		static const int next[4] = { 0, 17, 2, 19 };
		fixedpt  scores[4];

        scores[0] = P3(in1, in2, in3, in4);
        scores[1] = P14(in1, in2, in3, in4);
        scores[2] = P15(in1, in2, in3, in4);
        scores[3] = P12(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T6: {
		static const int next[3] = { 5, 16, 3 };
		fixedpt  scores[3];

        scores[0] = P16(in1, in2, in3, in4);
        scores[1] = P17(in1, in2, in3, in4);
        scores[2] = P18(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T7: {
		static const int next[2] = { 4, 6 };
		fixedpt  scores[2];

        scores[0] = P19(in1, in2, in3, in4);
        scores[1] = P20(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T8: {
		static const int next[5] = { 4, 6, 3, 4, 6 };
		fixedpt  scores[5];

        scores[0] = P21(in1, in2, in3, in4);
        scores[1] = P22(in1, in2, in3, in4);
        scores[2] = P23(in1, in2, in3, in4);
        scores[3] = P24(in1, in2, in3, in4);
        scores[4] = P25(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T9: {
		static const int next[6] = { 17, 4, 17, 7, 8, 17 };
		fixedpt  scores[6];

        scores[0] = P26(in1, in2, in3, in4);
        scores[1] = P27(in1, in2, in3, in4);
        scores[2] = P28(in1, in2, in3, in4);
        scores[3] = P29(in1, in2, in3, in4);
        scores[4] = P30(in1, in2, in3, in4);
        scores[5] = P31(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T10: {
		static const int next[5] = { 9, 7, 17, 8, 15 };
		fixedpt  scores[5];

        scores[0] = P32(in1, in2, in3, in4);
        scores[1] = P33(in1, in2, in3, in4);
        scores[2] = P34(in1, in2, in3, in4);
        scores[3] = P30(in1, in2, in3, in4);
        scores[4] = P35(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T11: {
		static const int next[5] = { 10, 9, 8, 4, 4 };
		fixedpt  scores[5];

        scores[0] = P36(in1, in2, in3, in4);
        scores[1] = P37(in1, in2, in3, in4);
        scores[2] = P38(in1, in2, in3, in4);
        scores[3] = P39(in1, in2, in3, in4);
        scores[4] = P27(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T12: {
		static const int next[3] = { 7, 11, 20 };
		fixedpt  scores[3];

        scores[0] = P40(in1, in2, in3, in4);
        scores[1] = P41(in1, in2, in3, in4);
        scores[2] = P42(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T13: {
		static const int next[4] = { 8, 12, 9, 10 };
		fixedpt  scores[4];

        scores[0] = P43(in1, in2, in3, in4);
        scores[1] = P44(in1, in2, in3, in4);
        scores[2] = P45(in1, in2, in3, in4);
        scores[3] = P46(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_A5: actions[0] = 5; return;
L_A6: actions[0] = 6; return;
L_A4: actions[0] = 4; return;
L_A0: actions[0] = 0; return;
L_A3: actions[0] = 3; return;
L_A8: actions[0] = 8; return;
L_A2: actions[0] = 2; return;
}
