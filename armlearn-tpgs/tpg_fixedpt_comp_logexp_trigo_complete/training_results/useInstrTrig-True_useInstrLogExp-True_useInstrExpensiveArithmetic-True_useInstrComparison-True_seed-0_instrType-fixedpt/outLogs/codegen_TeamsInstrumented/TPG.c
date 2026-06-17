/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:09:40
 * With the CodeGen::TPGGenerationEngine.
 */

#include "csr.h"
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
					const fixedpt * __restrict__ in4,
					uint32_t * team_cycles)
{
	/* Jump table — static const lets GCC keep it in .rodata and
	   potentially cache it in a register across iterations.       */
	static const void * const jump_table[] = {
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_T14, &&L_T15, &&L_T16, &&L_T17, &&L_A4, &&L_A5, &&L_A6, &&L_A7, &&L_A0, &&L_A8, &&L_A3
    };

	/* Initial dispatch — always start at T17 */
	goto *jump_table[17];	/* == &&L_T17 */

	uint32_t start, end;

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[2] = { 20, 19 };
		fixedpt  scores[2];

		__asm__ volatile("T0_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);

		__asm__ volatile("T0_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[0] = end - start;

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T1: {
		static const int next[2] = { 20, 19 };
		fixedpt  scores[2];

		__asm__ volatile("T1_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P2(in1, in2, in3, in4);
        scores[1] = P3(in1, in2, in3, in4);

		__asm__ volatile("T1_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[1] = end - start;

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T2: {
		static const int next[4] = { 0, 22, 19, 20 };
		fixedpt  scores[4];

		__asm__ volatile("T2_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P4(in1, in2, in3, in4);
        scores[1] = P5(in1, in2, in3, in4);
        scores[2] = P1(in1, in2, in3, in4);
        scores[3] = P6(in1, in2, in3, in4);

		__asm__ volatile("T2_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[2] = end - start;

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T3: {
		static const int next[4] = { 23, 1, 20, 22 };
		fixedpt  scores[4];

		__asm__ volatile("T3_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P7(in1, in2, in3, in4);
        scores[1] = P8(in1, in2, in3, in4);
        scores[2] = P9(in1, in2, in3, in4);
        scores[3] = P5(in1, in2, in3, in4);

		__asm__ volatile("T3_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[3] = end - start;

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T4: {
		static const int next[2] = { 2, 3 };
		fixedpt  scores[2];

		__asm__ volatile("T4_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P10(in1, in2, in3, in4);
        scores[1] = P11(in1, in2, in3, in4);

		__asm__ volatile("T4_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[4] = end - start;

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T5: {
		static const int next[4] = { 22, 19, 18, 21 };
		fixedpt  scores[4];

		__asm__ volatile("T5_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P12(in1, in2, in3, in4);
        scores[1] = P13(in1, in2, in3, in4);
        scores[2] = P14(in1, in2, in3, in4);
        scores[3] = P15(in1, in2, in3, in4);

		__asm__ volatile("T5_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[5] = end - start;

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T6: {
		static const int next[3] = { 23, 18, 3 };
		fixedpt  scores[3];

		__asm__ volatile("T6_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P16(in1, in2, in3, in4);
        scores[1] = P14(in1, in2, in3, in4);
        scores[2] = P17(in1, in2, in3, in4);

		__asm__ volatile("T6_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[6] = end - start;

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T7: {
		static const int next[3] = { 22, 3, 2 };
		fixedpt  scores[3];

		__asm__ volatile("T7_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P18(in1, in2, in3, in4);
        scores[1] = P19(in1, in2, in3, in4);
        scores[2] = P20(in1, in2, in3, in4);

		__asm__ volatile("T7_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[7] = end - start;

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T8: {
		static const int next[3] = { 2, 6, 19 };
		fixedpt  scores[3];

		__asm__ volatile("T8_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P21(in1, in2, in3, in4);
        scores[1] = P22(in1, in2, in3, in4);
        scores[2] = P23(in1, in2, in3, in4);

		__asm__ volatile("T8_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[8] = end - start;

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T9: {
		static const int next[2] = { 5, 7 };
		fixedpt  scores[2];

		__asm__ volatile("T9_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P24(in1, in2, in3, in4);
        scores[1] = P25(in1, in2, in3, in4);

		__asm__ volatile("T9_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[9] = end - start;

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T10: {
		static const int next[3] = { 24, 8, 4 };
		fixedpt  scores[3];

		__asm__ volatile("T10_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P26(in1, in2, in3, in4);
        scores[1] = P27(in1, in2, in3, in4);
        scores[2] = P28(in1, in2, in3, in4);

		__asm__ volatile("T10_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[10] = end - start;

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T11: {
		static const int next[4] = { 10, 22, 18, 5 };
		fixedpt  scores[4];

		__asm__ volatile("T11_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P29(in1, in2, in3, in4);
        scores[1] = P30(in1, in2, in3, in4);
        scores[2] = P31(in1, in2, in3, in4);
        scores[3] = P24(in1, in2, in3, in4);

		__asm__ volatile("T11_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[11] = end - start;

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T12: {
		static const int next[4] = { 8, 18, 9, 10 };
		fixedpt  scores[4];

		__asm__ volatile("T12_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P27(in1, in2, in3, in4);
        scores[1] = P32(in1, in2, in3, in4);
        scores[2] = P33(in1, in2, in3, in4);
        scores[3] = P29(in1, in2, in3, in4);

		__asm__ volatile("T12_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[12] = end - start;

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T13: {
		static const int next[3] = { 8, 18, 9 };
		fixedpt  scores[3];

		__asm__ volatile("T13_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P27(in1, in2, in3, in4);
        scores[1] = P34(in1, in2, in3, in4);
        scores[2] = P35(in1, in2, in3, in4);

		__asm__ volatile("T13_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[13] = end - start;

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T14: {
		static const int next[7] = { 10, 22, 18, 12, 24, 8, 9 };
		fixedpt  scores[7];

		__asm__ volatile("T14_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P36(in1, in2, in3, in4);
        scores[1] = P30(in1, in2, in3, in4);
        scores[2] = P31(in1, in2, in3, in4);
        scores[3] = P37(in1, in2, in3, in4);
        scores[4] = P26(in1, in2, in3, in4);
        scores[5] = P38(in1, in2, in3, in4);
        scores[6] = P33(in1, in2, in3, in4);

		__asm__ volatile("T14_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[14] = end - start;

		goto *jump_table[next[bestProgram(scores, 7)]];
	}

L_T15: {
		static const int next[4] = { 10, 11, 8, 13 };
		fixedpt  scores[4];

		__asm__ volatile("T15_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P39(in1, in2, in3, in4);
        scores[1] = P40(in1, in2, in3, in4);
        scores[2] = P27(in1, in2, in3, in4);
        scores[3] = P41(in1, in2, in3, in4);

		__asm__ volatile("T15_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[15] = end - start;

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T16: {
		static const int next[3] = { 24, 8, 11 };
		fixedpt  scores[3];

		__asm__ volatile("T16_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P42(in1, in2, in3, in4);
        scores[1] = P43(in1, in2, in3, in4);
        scores[2] = P40(in1, in2, in3, in4);

		__asm__ volatile("T16_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[16] = end - start;

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T17: {
		static const int next[7] = { 14, 21, 11, 8, 16, 15, 24 };
		fixedpt  scores[7];

		__asm__ volatile("T17_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P44(in1, in2, in3, in4);
        scores[1] = P45(in1, in2, in3, in4);
        scores[2] = P40(in1, in2, in3, in4);
        scores[3] = P27(in1, in2, in3, in4);
        scores[4] = P46(in1, in2, in3, in4);
        scores[5] = P47(in1, in2, in3, in4);
        scores[6] = P48(in1, in2, in3, in4);

		__asm__ volatile("T17_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[17] = end - start;

		goto *jump_table[next[bestProgram(scores, 7)]];
	}

L_A4: actions[0] = 4; return;
L_A5: actions[0] = 5; return;
L_A6: actions[0] = 6; return;
L_A7: actions[0] = 7; return;
L_A0: actions[0] = 0; return;
L_A8: actions[0] = 8; return;
L_A3: actions[0] = 3; return;
}
