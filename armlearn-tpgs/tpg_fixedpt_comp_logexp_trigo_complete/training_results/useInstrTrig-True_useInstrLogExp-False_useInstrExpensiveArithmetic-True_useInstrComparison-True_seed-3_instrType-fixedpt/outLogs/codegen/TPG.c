/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:10:30
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_T14, &&L_T15, &&L_T16, &&L_T17, &&L_T18, &&L_T19, &&L_A5, &&L_A4, &&L_A8, &&L_A6, &&L_A3, &&L_A7, &&L_A1, &&L_A2, &&L_A0
    };

	/* Initial dispatch — always start at T19 */
	goto *jump_table[19];	/* == &&L_T19 */

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[3] = { 20, 22, 21 };
		fixedpt  scores[3];

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);
        scores[2] = P2(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T1: {
		static const int next[3] = { 23, 21, 20 };
		fixedpt  scores[3];

        scores[0] = P3(in1, in2, in3, in4);
        scores[1] = P4(in1, in2, in3, in4);
        scores[2] = P5(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T2: {
		static const int next[3] = { 22, 21, 0 };
		fixedpt  scores[3];

        scores[0] = P1(in1, in2, in3, in4);
        scores[1] = P6(in1, in2, in3, in4);
        scores[2] = P7(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T3: {
		static const int next[3] = { 0, 25, 23 };
		fixedpt  scores[3];

        scores[0] = P8(in1, in2, in3, in4);
        scores[1] = P9(in1, in2, in3, in4);
        scores[2] = P10(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T4: {
		static const int next[8] = { 25, 21, 23, 0, 25, 1, 23, 24 };
		fixedpt  scores[8];

        scores[0] = P11(in1, in2, in3, in4);
        scores[1] = P12(in1, in2, in3, in4);
        scores[2] = P13(in1, in2, in3, in4);
        scores[3] = P14(in1, in2, in3, in4);
        scores[4] = P15(in1, in2, in3, in4);
        scores[5] = P16(in1, in2, in3, in4);
        scores[6] = P17(in1, in2, in3, in4);
        scores[7] = P18(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 8)]];
	}

L_T5: {
		static const int next[5] = { 23, 25, 4, 21, 2 };
		fixedpt  scores[5];

        scores[0] = P19(in1, in2, in3, in4);
        scores[1] = P20(in1, in2, in3, in4);
        scores[2] = P21(in1, in2, in3, in4);
        scores[3] = P12(in1, in2, in3, in4);
        scores[4] = P22(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T6: {
		static const int next[4] = { 25, 2, 3, 21 };
		fixedpt  scores[4];

        scores[0] = P23(in1, in2, in3, in4);
        scores[1] = P24(in1, in2, in3, in4);
        scores[2] = P25(in1, in2, in3, in4);
        scores[3] = P26(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T7: {
		static const int next[2] = { 4, 21 };
		fixedpt  scores[2];

        scores[0] = P27(in1, in2, in3, in4);
        scores[1] = P2(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T8: {
		static const int next[4] = { 21, 3, 2, 25 };
		fixedpt  scores[4];

        scores[0] = P26(in1, in2, in3, in4);
        scores[1] = P28(in1, in2, in3, in4);
        scores[2] = P29(in1, in2, in3, in4);
        scores[3] = P30(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T9: {
		static const int next[3] = { 6, 2, 3 };
		fixedpt  scores[3];

        scores[0] = P31(in1, in2, in3, in4);
        scores[1] = P32(in1, in2, in3, in4);
        scores[2] = P33(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T10: {
		static const int next[6] = { 6, 3, 8, 9, 0, 2 };
		fixedpt  scores[6];

        scores[0] = P34(in1, in2, in3, in4);
        scores[1] = P25(in1, in2, in3, in4);
        scores[2] = P35(in1, in2, in3, in4);
        scores[3] = P36(in1, in2, in3, in4);
        scores[4] = P14(in1, in2, in3, in4);
        scores[5] = P24(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T11: {
		static const int next[3] = { 6, 22, 2 };
		fixedpt  scores[3];

        scores[0] = P37(in1, in2, in3, in4);
        scores[1] = P38(in1, in2, in3, in4);
        scores[2] = P24(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T12: {
		static const int next[2] = { 6, 2 };
		fixedpt  scores[2];

        scores[0] = P31(in1, in2, in3, in4);
        scores[1] = P39(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T13: {
		static const int next[4] = { 11, 12, 21, 7 };
		fixedpt  scores[4];

        scores[0] = P40(in1, in2, in3, in4);
        scores[1] = P41(in1, in2, in3, in4);
        scores[2] = P42(in1, in2, in3, in4);
        scores[3] = P43(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T14: {
		static const int next[9] = { 6, 22, 0, 25, 3, 21, 0, 5, 25 };
		fixedpt  scores[9];

        scores[0] = P44(in1, in2, in3, in4);
        scores[1] = P38(in1, in2, in3, in4);
        scores[2] = P45(in1, in2, in3, in4);
        scores[3] = P46(in1, in2, in3, in4);
        scores[4] = P47(in1, in2, in3, in4);
        scores[5] = P26(in1, in2, in3, in4);
        scores[6] = P14(in1, in2, in3, in4);
        scores[7] = P48(in1, in2, in3, in4);
        scores[8] = P11(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 9)]];
	}

L_T15: {
		static const int next[2] = { 5, 6 };
		fixedpt  scores[2];

        scores[0] = P49(in1, in2, in3, in4);
        scores[1] = P50(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T16: {
		static const int next[13] = { 21, 21, 14, 6, 5, 10, 3, 0, 21, 28, 21, 3, 3 };
		fixedpt  scores[13];

        scores[0] = P51(in1, in2, in3, in4);
        scores[1] = P52(in1, in2, in3, in4);
        scores[2] = P53(in1, in2, in3, in4);
        scores[3] = P54(in1, in2, in3, in4);
        scores[4] = P55(in1, in2, in3, in4);
        scores[5] = P56(in1, in2, in3, in4);
        scores[6] = P57(in1, in2, in3, in4);
        scores[7] = P58(in1, in2, in3, in4);
        scores[8] = P2(in1, in2, in3, in4);
        scores[9] = P59(in1, in2, in3, in4);
        scores[10] = P60(in1, in2, in3, in4);
        scores[11] = P61(in1, in2, in3, in4);
        scores[12] = P62(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 13)]];
	}

L_T17: {
		static const int next[7] = { 27, 21, 16, 16, 4, 15, 8 };
		fixedpt  scores[7];

        scores[0] = P63(in1, in2, in3, in4);
        scores[1] = P64(in1, in2, in3, in4);
        scores[2] = P65(in1, in2, in3, in4);
        scores[3] = P66(in1, in2, in3, in4);
        scores[4] = P67(in1, in2, in3, in4);
        scores[5] = P68(in1, in2, in3, in4);
        scores[6] = P69(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 7)]];
	}

L_T18: {
		static const int next[8] = { 17, 13, 0, 5, 26, 21, 0, 4 };
		fixedpt  scores[8];

        scores[0] = P70(in1, in2, in3, in4);
        scores[1] = P71(in1, in2, in3, in4);
        scores[2] = P72(in1, in2, in3, in4);
        scores[3] = P73(in1, in2, in3, in4);
        scores[4] = P74(in1, in2, in3, in4);
        scores[5] = P51(in1, in2, in3, in4);
        scores[6] = P75(in1, in2, in3, in4);
        scores[7] = P21(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 8)]];
	}

L_T19: {
		static const int next[2] = { 18, 27 };
		fixedpt  scores[2];

        scores[0] = P76(in1, in2, in3, in4);
        scores[1] = P77(in1, in2, in3, in4);

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_A5: actions[0] = 5; return;
L_A4: actions[0] = 4; return;
L_A8: actions[0] = 8; return;
L_A6: actions[0] = 6; return;
L_A3: actions[0] = 3; return;
L_A7: actions[0] = 7; return;
L_A1: actions[0] = 1; return;
L_A2: actions[0] = 2; return;
L_A0: actions[0] = 0; return;
}
