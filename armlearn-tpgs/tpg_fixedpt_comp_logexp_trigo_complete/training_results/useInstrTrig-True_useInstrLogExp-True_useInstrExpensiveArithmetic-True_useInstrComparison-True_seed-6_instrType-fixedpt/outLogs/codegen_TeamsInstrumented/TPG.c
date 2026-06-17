/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:09:54
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_A5, &&L_A7, &&L_A4, &&L_A6, &&L_A3, &&L_A0, &&L_A8
    };

	/* Initial dispatch — always start at T9 */
	goto *jump_table[9];	/* == &&L_T9 */

	uint32_t start, end;

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[5] = { 10, 11, 12, 12, 11 };
		fixedpt  scores[5];

		__asm__ volatile("T0_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P1(in1, in2, in3, in4);
        scores[2] = P2(in1, in2, in3, in4);
        scores[3] = P3(in1, in2, in3, in4);
        scores[4] = P4(in1, in2, in3, in4);

		__asm__ volatile("T0_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[0] = end - start;

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T1: {
		static const int next[3] = { 13, 10, 15 };
		fixedpt  scores[3];

		__asm__ volatile("T1_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P5(in1, in2, in3, in4);
        scores[1] = P6(in1, in2, in3, in4);
        scores[2] = P7(in1, in2, in3, in4);

		__asm__ volatile("T1_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[1] = end - start;

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T2: {
		static const int next[5] = { 13, 12, 1, 12, 10 };
		fixedpt  scores[5];

		__asm__ volatile("T2_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P8(in1, in2, in3, in4);
        scores[1] = P9(in1, in2, in3, in4);
        scores[2] = P10(in1, in2, in3, in4);
        scores[3] = P11(in1, in2, in3, in4);
        scores[4] = P12(in1, in2, in3, in4);

		__asm__ volatile("T2_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[2] = end - start;

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T3: {
		static const int next[2] = { 0, 2 };
		fixedpt  scores[2];

		__asm__ volatile("T3_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P13(in1, in2, in3, in4);
        scores[1] = P14(in1, in2, in3, in4);

		__asm__ volatile("T3_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[3] = end - start;

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T4: {
		static const int next[5] = { 0, 13, 2, 16, 0 };
		fixedpt  scores[5];

		__asm__ volatile("T4_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P13(in1, in2, in3, in4);
        scores[1] = P15(in1, in2, in3, in4);
        scores[2] = P14(in1, in2, in3, in4);
        scores[3] = P16(in1, in2, in3, in4);
        scores[4] = P17(in1, in2, in3, in4);

		__asm__ volatile("T4_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[4] = end - start;

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T5: {
		static const int next[7] = { 0, 13, 14, 16, 0, 2, 0 };
		fixedpt  scores[7];

		__asm__ volatile("T5_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P13(in1, in2, in3, in4);
        scores[1] = P15(in1, in2, in3, in4);
        scores[2] = P18(in1, in2, in3, in4);
        scores[3] = P16(in1, in2, in3, in4);
        scores[4] = P19(in1, in2, in3, in4);
        scores[5] = P14(in1, in2, in3, in4);
        scores[6] = P20(in1, in2, in3, in4);

		__asm__ volatile("T5_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[5] = end - start;

		goto *jump_table[next[bestProgram(scores, 7)]];
	}

L_T6: {
		static const int next[2] = { 5, 16 };
		fixedpt  scores[2];

		__asm__ volatile("T6_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P21(in1, in2, in3, in4);
        scores[1] = P22(in1, in2, in3, in4);

		__asm__ volatile("T6_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[6] = end - start;

		goto *jump_table[next[bestProgram(scores, 2)]];
	}

L_T7: {
		static const int next[3] = { 3, 5, 16 };
		fixedpt  scores[3];

		__asm__ volatile("T7_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P23(in1, in2, in3, in4);
        scores[1] = P21(in1, in2, in3, in4);
        scores[2] = P22(in1, in2, in3, in4);

		__asm__ volatile("T7_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[7] = end - start;

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T8: {
		static const int next[7] = { 3, 5, 16, 14, 6, 4, 14 };
		fixedpt  scores[7];

		__asm__ volatile("T8_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P24(in1, in2, in3, in4);
        scores[1] = P21(in1, in2, in3, in4);
        scores[2] = P22(in1, in2, in3, in4);
        scores[3] = P18(in1, in2, in3, in4);
        scores[4] = P25(in1, in2, in3, in4);
        scores[5] = P26(in1, in2, in3, in4);
        scores[6] = P27(in1, in2, in3, in4);

		__asm__ volatile("T8_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[8] = end - start;

		goto *jump_table[next[bestProgram(scores, 7)]];
	}

L_T9: {
		static const int next[5] = { 8, 14, 14, 3, 7 };
		fixedpt  scores[5];

		__asm__ volatile("T9_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P28(in1, in2, in3, in4);
        scores[1] = P27(in1, in2, in3, in4);
        scores[2] = P18(in1, in2, in3, in4);
        scores[3] = P29(in1, in2, in3, in4);
        scores[4] = P30(in1, in2, in3, in4);

		__asm__ volatile("T9_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[9] = end - start;

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_A5: actions[0] = 5; return;
L_A7: actions[0] = 7; return;
L_A4: actions[0] = 4; return;
L_A6: actions[0] = 6; return;
L_A3: actions[0] = 3; return;
L_A0: actions[0] = 0; return;
L_A8: actions[0] = 8; return;
}
