/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-07-14 09:07:05
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_T14, &&L_T15, &&L_T16, &&L_T17, &&L_T18, &&L_T19, &&L_T20, &&L_T21, &&L_T22, &&L_T23, &&L_T24, &&L_A5, &&L_A6, &&L_A8, &&L_A0, &&L_A4, &&L_A2, &&L_A7
    };

	/* Initial dispatch — always start at T24 */
	goto *jump_table[24];	/* == &&L_T24 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[2] = { 27, 29 };
		fixedpt  scores[2];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T1: {
		static const int next[2] = { 26, 0 };
		fixedpt  scores[2];

        scores[0] = P2(in1, in2, in3, in4);
        scores[1] = P3(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T2: {
		static const int next[3] = { 0, 26, 25 };
		fixedpt  scores[3];

        scores[0] = P3(in1, in2, in3, in4);
        scores[1] = P4(in1, in2, in3, in4);
        scores[2] = P5(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T3: {
		static const int next[4] = { 25, 29, 31, 29 };
		fixedpt  scores[4];

        scores[0] = P5(in1, in2, in3, in4);
        scores[1] = P6(in1, in2, in3, in4);
        scores[2] = P7(in1, in2, in3, in4);
        scores[3] = P8(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T4: {
		static const int next[2] = { 26, 25 };
		fixedpt  scores[2];

        scores[0] = P2(in1, in2, in3, in4);
        scores[1] = P9(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T5: {
		static const int next[3] = { 0, 4, 26 };
		fixedpt  scores[3];

        scores[0] = P3(in1, in2, in3, in4);
        scores[1] = P10(in1, in2, in3, in4);
        scores[2] = P11(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T6: {
		static const int next[2] = { 0, 0 };
		fixedpt  scores[2];

        scores[0] = P12(in1, in2, in3, in4);
        scores[1] = P3(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T7: {
		static const int next[3] = { 31, 25, 0 };
		fixedpt  scores[3];

        scores[0] = P13(in1, in2, in3, in4);
        scores[1] = P14(in1, in2, in3, in4);
        scores[2] = P3(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T8: {
		static const int next[4] = { 26, 7, 25, 0 };
		fixedpt  scores[4];

        scores[0] = P11(in1, in2, in3, in4);
        scores[1] = P15(in1, in2, in3, in4);
        scores[2] = P16(in1, in2, in3, in4);
        scores[3] = P17(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T9: {
		static const int next[4] = { 26, 7, 0, 25 };
		fixedpt  scores[4];

        scores[0] = P11(in1, in2, in3, in4);
        scores[1] = P15(in1, in2, in3, in4);
        scores[2] = P17(in1, in2, in3, in4);
        scores[3] = P18(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T10: {
		static const int next[5] = { 25, 3, 0, 2, 26 };
		fixedpt  scores[5];

        scores[0] = P19(in1, in2, in3, in4);
        scores[1] = P20(in1, in2, in3, in4);
        scores[2] = P21(in1, in2, in3, in4);
        scores[3] = P22(in1, in2, in3, in4);
        scores[4] = P23(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T11: {
		static const int next[2] = { 6, 8 };
		fixedpt  scores[2];

        scores[0] = P24(in1, in2, in3, in4);
        scores[1] = P25(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T12: {
		static const int next[5] = { 25, 1, 3, 0, 2 };
		fixedpt  scores[5];

        scores[0] = P26(in1, in2, in3, in4);
        scores[1] = P27(in1, in2, in3, in4);
        scores[2] = P20(in1, in2, in3, in4);
        scores[3] = P28(in1, in2, in3, in4);
        scores[4] = P29(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T13: {
		static const int next[4] = { 12, 5, 9, 10 };
		fixedpt  scores[4];

        scores[0] = P30(in1, in2, in3, in4);
        scores[1] = P31(in1, in2, in3, in4);
        scores[2] = P32(in1, in2, in3, in4);
        scores[3] = P33(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T14: {
		static const int next[5] = { 0, 9, 10, 12, 28 };
		fixedpt  scores[5];

        scores[0] = P34(in1, in2, in3, in4);
        scores[1] = P35(in1, in2, in3, in4);
        scores[2] = P36(in1, in2, in3, in4);
        scores[3] = P30(in1, in2, in3, in4);
        scores[4] = P37(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T15: {
		static const int next[3] = { 11, 13, 28 };
		fixedpt  scores[3];

        scores[0] = P38(in1, in2, in3, in4);
        scores[1] = P39(in1, in2, in3, in4);
        scores[2] = P40(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T16: {
		static const int next[3] = { 12, 9, 14 };
		fixedpt  scores[3];

        scores[0] = P30(in1, in2, in3, in4);
        scores[1] = P41(in1, in2, in3, in4);
        scores[2] = P42(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T17: {
		static const int next[4] = { 14, 14, 15, 12 };
		fixedpt  scores[4];

        scores[0] = P43(in1, in2, in3, in4);
        scores[1] = P44(in1, in2, in3, in4);
        scores[2] = P45(in1, in2, in3, in4);
        scores[3] = P30(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T18: {
		static const int next[5] = { 15, 17, 15, 12, 15 };
		fixedpt  scores[5];

        scores[0] = P46(in1, in2, in3, in4);
        scores[1] = P47(in1, in2, in3, in4);
        scores[2] = P45(in1, in2, in3, in4);
        scores[3] = P30(in1, in2, in3, in4);
        scores[4] = P48(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T19: {
		static const int next[3] = { 14, 14, 18 };
		fixedpt  scores[3];

        scores[0] = P49(in1, in2, in3, in4);
        scores[1] = P50(in1, in2, in3, in4);
        scores[2] = P51(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T20: {
		static const int next[3] = { 19, 30, 16 };
		fixedpt  scores[3];

        scores[0] = P52(in1, in2, in3, in4);
        scores[1] = P53(in1, in2, in3, in4);
        scores[2] = P54(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T21: {
		static const int next[5] = { 14, 14, 7, 18, 12 };
		fixedpt  scores[5];

        scores[0] = P55(in1, in2, in3, in4);
        scores[1] = P56(in1, in2, in3, in4);
        scores[2] = P57(in1, in2, in3, in4);
        scores[3] = P51(in1, in2, in3, in4);
        scores[4] = P30(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T22: {
		static const int next[2] = { 21, 9 };
		fixedpt  scores[2];

        scores[0] = P58(in1, in2, in3, in4);
        scores[1] = P59(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T23: {
		static const int next[7] = { 14, 14, 18, 14, 12, 30, 22 };
		fixedpt  scores[7];

        scores[0] = P60(in1, in2, in3, in4);
        scores[1] = P56(in1, in2, in3, in4);
        scores[2] = P51(in1, in2, in3, in4);
        scores[3] = P43(in1, in2, in3, in4);
        scores[4] = P30(in1, in2, in3, in4);
        scores[5] = P61(in1, in2, in3, in4);
        scores[6] = P62(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 7)]];
	}

L_T24: {
		static const int next[6] = { 16, 20, 23, 14, 11, 30 };
		fixedpt  scores[6];

        scores[0] = P63(in1, in2, in3, in4);
        scores[1] = P64(in1, in2, in3, in4);
        scores[2] = P65(in1, in2, in3, in4);
        scores[3] = P66(in1, in2, in3, in4);
        scores[4] = P67(in1, in2, in3, in4);
        scores[5] = P61(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_A5: actions[0] = 5; return;
L_A6: actions[0] = 6; return;
L_A8: actions[0] = 8; return;
L_A0: actions[0] = 0; return;
L_A4: actions[0] = 4; return;
L_A2: actions[0] = 2; return;
L_A7: actions[0] = 7; return;
}
