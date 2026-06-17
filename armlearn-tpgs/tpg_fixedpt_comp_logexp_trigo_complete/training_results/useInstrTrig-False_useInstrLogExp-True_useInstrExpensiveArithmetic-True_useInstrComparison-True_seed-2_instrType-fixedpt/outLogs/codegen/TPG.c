/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:08:20
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_A3, &&L_A4, &&L_A5, &&L_A6, &&L_A1, &&L_A8, &&L_A0
    };

	/* Initial dispatch — always start at T13 */
	goto *jump_table[13];	/* == &&L_T13 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[3] = { 16, 17, 16 };
		fixedpt  scores[3];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);
        scores[2] = P2(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T1: {
		static const int next[5] = { 17, 14, 15, 19, 16 };
		fixedpt  scores[5];

        scores[0] = P3(in1, in2, in3, in4);
        scores[1] = P4(in1, in2, in3, in4);
        scores[2] = P5(in1, in2, in3, in4);
        scores[3] = P6(in1, in2, in3, in4);
        scores[4] = P7(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T2: {
		static const int next[5] = { 17, 14, 15, 19, 16 };
		fixedpt  scores[5];

        scores[0] = P3(in1, in2, in3, in4);
        scores[1] = P4(in1, in2, in3, in4);
        scores[2] = P8(in1, in2, in3, in4);
        scores[3] = P6(in1, in2, in3, in4);
        scores[4] = P7(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T3: {
		static const int next[4] = { 15, 20, 19, 17 };
		fixedpt  scores[4];

        scores[0] = P9(in1, in2, in3, in4);
        scores[1] = P10(in1, in2, in3, in4);
        scores[2] = P11(in1, in2, in3, in4);
        scores[3] = P3(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T4: {
		static const int next[3] = { 2, 0, 19 };
		fixedpt  scores[3];

        scores[0] = P12(in1, in2, in3, in4);
        scores[1] = P13(in1, in2, in3, in4);
        scores[2] = P6(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T5: {
		static const int next[4] = { 1, 3, 19, 14 };
		fixedpt  scores[4];

        scores[0] = P14(in1, in2, in3, in4);
        scores[1] = P15(in1, in2, in3, in4);
        scores[2] = P16(in1, in2, in3, in4);
        scores[3] = P17(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T6: {
		static const int next[6] = { 20, 2, 14, 14, 1, 1 };
		fixedpt  scores[6];

        scores[0] = P18(in1, in2, in3, in4);
        scores[1] = P19(in1, in2, in3, in4);
        scores[2] = P20(in1, in2, in3, in4);
        scores[3] = P21(in1, in2, in3, in4);
        scores[4] = P22(in1, in2, in3, in4);
        scores[5] = P14(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T7: {
		static const int next[2] = { 3, 6 };
		fixedpt  scores[2];

        scores[0] = P23(in1, in2, in3, in4);
        scores[1] = P24(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T8: {
		static const int next[5] = { 6, 2, 5, 1, 14 };
		fixedpt  scores[5];

        scores[0] = P25(in1, in2, in3, in4);
        scores[1] = P19(in1, in2, in3, in4);
        scores[2] = P26(in1, in2, in3, in4);
        scores[3] = P22(in1, in2, in3, in4);
        scores[4] = P27(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T9: {
		static const int next[5] = { 1, 2, 7, 14, 3 };
		fixedpt  scores[5];

        scores[0] = P28(in1, in2, in3, in4);
        scores[1] = P19(in1, in2, in3, in4);
        scores[2] = P29(in1, in2, in3, in4);
        scores[3] = P30(in1, in2, in3, in4);
        scores[4] = P31(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T10: {
		static const int next[6] = { 8, 20, 14, 18, 14, 1 };
		fixedpt  scores[6];

        scores[0] = P32(in1, in2, in3, in4);
        scores[1] = P18(in1, in2, in3, in4);
        scores[2] = P33(in1, in2, in3, in4);
        scores[3] = P34(in1, in2, in3, in4);
        scores[4] = P35(in1, in2, in3, in4);
        scores[5] = P28(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T11: {
		static const int next[6] = { 6, 1, 2, 14, 9, 3 };
		fixedpt  scores[6];

        scores[0] = P36(in1, in2, in3, in4);
        scores[1] = P22(in1, in2, in3, in4);
        scores[2] = P19(in1, in2, in3, in4);
        scores[3] = P27(in1, in2, in3, in4);
        scores[4] = P37(in1, in2, in3, in4);
        scores[5] = P38(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T12: {
		static const int next[6] = { 10, 9, 7, 14, 3, 4 };
		fixedpt  scores[6];

        scores[0] = P39(in1, in2, in3, in4);
        scores[1] = P40(in1, in2, in3, in4);
        scores[2] = P41(in1, in2, in3, in4);
        scores[3] = P42(in1, in2, in3, in4);
        scores[4] = P43(in1, in2, in3, in4);
        scores[5] = P44(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T13: {
		static const int next[6] = { 12, 5, 11, 2, 11, 20 };
		fixedpt  scores[6];

        scores[0] = P45(in1, in2, in3, in4);
        scores[1] = P46(in1, in2, in3, in4);
        scores[2] = P47(in1, in2, in3, in4);
        scores[3] = P19(in1, in2, in3, in4);
        scores[4] = P48(in1, in2, in3, in4);
        scores[5] = P18(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_A3: actions[0] = 3; return;
L_A4: actions[0] = 4; return;
L_A5: actions[0] = 5; return;
L_A6: actions[0] = 6; return;
L_A1: actions[0] = 1; return;
L_A8: actions[0] = 8; return;
L_A0: actions[0] = 0; return;
}
