/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:08:23
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_A4, &&L_A5, &&L_A3, &&L_A7, &&L_A6, &&L_A1, &&L_A2, &&L_A0
    };

	/* Initial dispatch — always start at T12 */
	goto *jump_table[12];	/* == &&L_T12 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[2] = { 13, 14 };
		fixedpt  scores[2];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T1: {
		static const int next[3] = { 17, 16, 0 };
		fixedpt  scores[3];

        scores[0] = P2(in1, in2, in3, in4);
        scores[1] = P3(in1, in2, in3, in4);
        scores[2] = P4(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T2: {
		static const int next[3] = { 19, 17, 13 };
		fixedpt  scores[3];

        scores[0] = P5(in1, in2, in3, in4);
        scores[1] = P6(in1, in2, in3, in4);
        scores[2] = P7(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T3: {
		static const int next[3] = { 17, 20, 14 };
		fixedpt  scores[3];

        scores[0] = P8(in1, in2, in3, in4);
        scores[1] = P9(in1, in2, in3, in4);
        scores[2] = P10(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T4: {
		static const int next[3] = { 3, 19, 2 };
		fixedpt  scores[3];

        scores[0] = P11(in1, in2, in3, in4);
        scores[1] = P5(in1, in2, in3, in4);
        scores[2] = P12(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T5: {
		static const int next[3] = { 19, 2, 3 };
		fixedpt  scores[3];

        scores[0] = P13(in1, in2, in3, in4);
        scores[1] = P14(in1, in2, in3, in4);
        scores[2] = P15(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T6: {
		static const int next[5] = { 3, 4, 3, 2, 14 };
		fixedpt  scores[5];

        scores[0] = P11(in1, in2, in3, in4);
        scores[1] = P16(in1, in2, in3, in4);
        scores[2] = P17(in1, in2, in3, in4);
        scores[3] = P18(in1, in2, in3, in4);
        scores[4] = P19(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T7: {
		static const int next[6] = { 1, 6, 19, 6, 19, 4 };
		fixedpt  scores[6];

        scores[0] = P20(in1, in2, in3, in4);
        scores[1] = P21(in1, in2, in3, in4);
        scores[2] = P22(in1, in2, in3, in4);
        scores[3] = P23(in1, in2, in3, in4);
        scores[4] = P24(in1, in2, in3, in4);
        scores[5] = P25(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T8: {
		static const int next[4] = { 14, 4, 15, 6 };
		fixedpt  scores[4];

        scores[0] = P26(in1, in2, in3, in4);
        scores[1] = P27(in1, in2, in3, in4);
        scores[2] = P28(in1, in2, in3, in4);
        scores[3] = P29(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T9: {
		static const int next[6] = { 8, 4, 14, 5, 7, 6 };
		fixedpt  scores[6];

        scores[0] = P30(in1, in2, in3, in4);
        scores[1] = P25(in1, in2, in3, in4);
        scores[2] = P31(in1, in2, in3, in4);
        scores[3] = P32(in1, in2, in3, in4);
        scores[4] = P33(in1, in2, in3, in4);
        scores[5] = P23(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T10: {
		static const int next[4] = { 7, 14, 16, 9 };
		fixedpt  scores[4];

        scores[0] = P34(in1, in2, in3, in4);
        scores[1] = P35(in1, in2, in3, in4);
        scores[2] = P36(in1, in2, in3, in4);
        scores[3] = P37(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T11: {
		static const int next[7] = { 2, 16, 9, 19, 19, 14, 8 };
		fixedpt  scores[7];

        scores[0] = P18(in1, in2, in3, in4);
        scores[1] = P36(in1, in2, in3, in4);
        scores[2] = P38(in1, in2, in3, in4);
        scores[3] = P22(in1, in2, in3, in4);
        scores[4] = P39(in1, in2, in3, in4);
        scores[5] = P40(in1, in2, in3, in4);
        scores[6] = P41(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 7)]];
	}

L_T12: {
		static const int next[5] = { 18, 16, 10, 11, 8 };
		fixedpt  scores[5];

        scores[0] = P42(in1, in2, in3, in4);
        scores[1] = P43(in1, in2, in3, in4);
        scores[2] = P44(in1, in2, in3, in4);
        scores[3] = P45(in1, in2, in3, in4);
        scores[4] = P46(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_A4: actions[0] = 4; return;
L_A5: actions[0] = 5; return;
L_A3: actions[0] = 3; return;
L_A7: actions[0] = 7; return;
L_A6: actions[0] = 6; return;
L_A1: actions[0] = 1; return;
L_A2: actions[0] = 2; return;
L_A0: actions[0] = 0; return;
}
