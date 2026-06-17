/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:08:28
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_T14, &&L_A5, &&L_A6, &&L_A4, &&L_A0, &&L_A1, &&L_A3
    };

	/* Initial dispatch — always start at T14 */
	goto *jump_table[14];	/* == &&L_T14 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[3] = { 15, 16, 17 };
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
		static const int next[2] = { 1, 0 };
		fixedpt  scores[2];

        scores[0] = P5(in1, in2, in3, in4);
        scores[1] = P6(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T3: {
		static const int next[2] = { 0, 19 };
		fixedpt  scores[2];

        scores[0] = P7(in1, in2, in3, in4);
        scores[1] = P8(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T4: {
		static const int next[3] = { 18, 17, 3 };
		fixedpt  scores[3];

        scores[0] = P9(in1, in2, in3, in4);
        scores[1] = P10(in1, in2, in3, in4);
        scores[2] = P11(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T5: {
		static const int next[2] = { 3, 17 };
		fixedpt  scores[2];

        scores[0] = P12(in1, in2, in3, in4);
        scores[1] = P13(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T6: {
		static const int next[4] = { 4, 17, 18, 17 };
		fixedpt  scores[4];

        scores[0] = P14(in1, in2, in3, in4);
        scores[1] = P15(in1, in2, in3, in4);
        scores[2] = P16(in1, in2, in3, in4);
        scores[3] = P17(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T7: {
		static const int next[9] = { 17, 0, 19, 17, 5, 16, 18, 2, 17 };
		fixedpt  scores[9];

        scores[0] = P18(in1, in2, in3, in4);
        scores[1] = P19(in1, in2, in3, in4);
        scores[2] = P20(in1, in2, in3, in4);
        scores[3] = P21(in1, in2, in3, in4);
        scores[4] = P22(in1, in2, in3, in4);
        scores[5] = P23(in1, in2, in3, in4);
        scores[6] = P24(in1, in2, in3, in4);
        scores[7] = P25(in1, in2, in3, in4);
        scores[8] = P26(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 9)]];
	}

L_T8: {
		static const int next[4] = { 7, 19, 6, 17 };
		fixedpt  scores[4];

        scores[0] = P27(in1, in2, in3, in4);
        scores[1] = P28(in1, in2, in3, in4);
        scores[2] = P29(in1, in2, in3, in4);
        scores[3] = P30(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T9: {
		static const int next[11] = { 17, 0, 19, 5, 16, 17, 18, 15, 2, 17, 7 };
		fixedpt  scores[11];

        scores[0] = P31(in1, in2, in3, in4);
        scores[1] = P19(in1, in2, in3, in4);
        scores[2] = P20(in1, in2, in3, in4);
        scores[3] = P32(in1, in2, in3, in4);
        scores[4] = P33(in1, in2, in3, in4);
        scores[5] = P34(in1, in2, in3, in4);
        scores[6] = P24(in1, in2, in3, in4);
        scores[7] = P35(in1, in2, in3, in4);
        scores[8] = P36(in1, in2, in3, in4);
        scores[9] = P37(in1, in2, in3, in4);
        scores[10] = P38(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 11)]];
	}

L_T10: {
		static const int next[6] = { 9, 8, 17, 20, 19, 17 };
		fixedpt  scores[6];

        scores[0] = P39(in1, in2, in3, in4);
        scores[1] = P40(in1, in2, in3, in4);
        scores[2] = P41(in1, in2, in3, in4);
        scores[3] = P42(in1, in2, in3, in4);
        scores[4] = P43(in1, in2, in3, in4);
        scores[5] = P44(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T11: {
		static const int next[5] = { 20, 18, 17, 19, 15 };
		fixedpt  scores[5];

        scores[0] = P45(in1, in2, in3, in4);
        scores[1] = P46(in1, in2, in3, in4);
        scores[2] = P47(in1, in2, in3, in4);
        scores[3] = P48(in1, in2, in3, in4);
        scores[4] = P49(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T12: {
		static const int next[4] = { 10, 20, 19, 18 };
		fixedpt  scores[4];

        scores[0] = P50(in1, in2, in3, in4);
        scores[1] = P51(in1, in2, in3, in4);
        scores[2] = P43(in1, in2, in3, in4);
        scores[3] = P52(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T13: {
		static const int next[3] = { 11, 12, 20 };
		fixedpt  scores[3];

        scores[0] = P53(in1, in2, in3, in4);
        scores[1] = P54(in1, in2, in3, in4);
        scores[2] = P55(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T14: {
		static const int next[4] = { 13, 12, 7, 12 };
		fixedpt  scores[4];

        scores[0] = P56(in1, in2, in3, in4);
        scores[1] = P57(in1, in2, in3, in4);
        scores[2] = P58(in1, in2, in3, in4);
        scores[3] = P59(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_A5: actions[0] = 5; return;
L_A6: actions[0] = 6; return;
L_A4: actions[0] = 4; return;
L_A0: actions[0] = 0; return;
L_A1: actions[0] = 1; return;
L_A3: actions[0] = 3; return;
}
