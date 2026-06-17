/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:07:58
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
		&&L_T0, &&L_T1, &&L_T2, &&L_T3, &&L_T4, &&L_T5, &&L_T6, &&L_T7, &&L_T8, &&L_T9, &&L_T10, &&L_T11, &&L_T12, &&L_T13, &&L_T14, &&L_T15, &&L_T16, &&L_T17, &&L_T18, &&L_T19, &&L_T20, &&L_T21, &&L_T22, &&L_T23, &&L_T24, &&L_T25, &&L_A5, &&L_A6, &&L_A7, &&L_A0, &&L_A4, &&L_A1, &&L_A3
    };

	/* Initial dispatch — always start at T25 */
	goto *jump_table[25];	/* == &&L_T25 */

	uint32_t start, end;

	/* ---- Team nodes ----------------------------------------- */

L_T0: {
		static const int next[2] = { 26, 27 };
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
		static const int next[3] = { 27, 26, 29 };
		fixedpt  scores[3];

		__asm__ volatile("T1_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P2(in1, in2, in3, in4);
        scores[1] = P3(in1, in2, in3, in4);
        scores[2] = P4(in1, in2, in3, in4);

		__asm__ volatile("T1_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[1] = end - start;

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T2: {
		static const int next[4] = { 26, 28, 28, 30 };
		fixedpt  scores[4];

		__asm__ volatile("T2_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P3(in1, in2, in3, in4);
        scores[1] = P5(in1, in2, in3, in4);
        scores[2] = P6(in1, in2, in3, in4);
        scores[3] = P7(in1, in2, in3, in4);

		__asm__ volatile("T2_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[2] = end - start;

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T3: {
		static const int next[4] = { 0, 30, 29, 26 };
		fixedpt  scores[4];

		__asm__ volatile("T3_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P8(in1, in2, in3, in4);
        scores[1] = P9(in1, in2, in3, in4);
        scores[2] = P10(in1, in2, in3, in4);
        scores[3] = P11(in1, in2, in3, in4);

		__asm__ volatile("T3_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[3] = end - start;

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T4: {
		static const int next[4] = { 0, 1, 31, 2 };
		fixedpt  scores[4];

		__asm__ volatile("T4_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P12(in1, in2, in3, in4);
        scores[1] = P13(in1, in2, in3, in4);
        scores[2] = P14(in1, in2, in3, in4);
        scores[3] = P15(in1, in2, in3, in4);

		__asm__ volatile("T4_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[4] = end - start;

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T5: {
		static const int next[6] = { 0, 29, 28, 30, 31, 1 };
		fixedpt  scores[6];

		__asm__ volatile("T5_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P12(in1, in2, in3, in4);
        scores[1] = P16(in1, in2, in3, in4);
        scores[2] = P6(in1, in2, in3, in4);
        scores[3] = P17(in1, in2, in3, in4);
        scores[4] = P18(in1, in2, in3, in4);
        scores[5] = P19(in1, in2, in3, in4);

		__asm__ volatile("T5_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[5] = end - start;

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T6: {
		static const int next[5] = { 26, 1, 0, 30, 31 };
		fixedpt  scores[5];

		__asm__ volatile("T6_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P0(in1, in2, in3, in4);
        scores[1] = P20(in1, in2, in3, in4);
        scores[2] = P21(in1, in2, in3, in4);
        scores[3] = P22(in1, in2, in3, in4);
        scores[4] = P23(in1, in2, in3, in4);

		__asm__ volatile("T6_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[6] = end - start;

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T7: {
		static const int next[6] = { 0, 30, 1, 31, 0, 26 };
		fixedpt  scores[6];

		__asm__ volatile("T7_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P12(in1, in2, in3, in4);
        scores[1] = P17(in1, in2, in3, in4);
        scores[2] = P13(in1, in2, in3, in4);
        scores[3] = P18(in1, in2, in3, in4);
        scores[4] = P24(in1, in2, in3, in4);
        scores[5] = P0(in1, in2, in3, in4);

		__asm__ volatile("T7_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[7] = end - start;

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T8: {
		static const int next[3] = { 30, 2, 0 };
		fixedpt  scores[3];

		__asm__ volatile("T8_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P17(in1, in2, in3, in4);
        scores[1] = P25(in1, in2, in3, in4);
        scores[2] = P26(in1, in2, in3, in4);

		__asm__ volatile("T8_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[8] = end - start;

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T9: {
		static const int next[8] = { 4, 30, 1, 2, 28, 29, 0, 26 };
		fixedpt  scores[8];

		__asm__ volatile("T9_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P27(in1, in2, in3, in4);
        scores[1] = P17(in1, in2, in3, in4);
        scores[2] = P28(in1, in2, in3, in4);
        scores[3] = P25(in1, in2, in3, in4);
        scores[4] = P6(in1, in2, in3, in4);
        scores[5] = P29(in1, in2, in3, in4);
        scores[6] = P12(in1, in2, in3, in4);
        scores[7] = P30(in1, in2, in3, in4);

		__asm__ volatile("T9_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[9] = end - start;

		goto *jump_table[next[bestProgram(scores, 8)]];
	}

L_T10: {
		static const int next[3] = { 9, 31, 0 };
		fixedpt  scores[3];

		__asm__ volatile("T10_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P31(in1, in2, in3, in4);
        scores[1] = P32(in1, in2, in3, in4);
        scores[2] = P33(in1, in2, in3, in4);

		__asm__ volatile("T10_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[10] = end - start;

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T11: {
		static const int next[3] = { 5, 0, 2 };
		fixedpt  scores[3];

		__asm__ volatile("T11_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P34(in1, in2, in3, in4);
        scores[1] = P35(in1, in2, in3, in4);
        scores[2] = P15(in1, in2, in3, in4);

		__asm__ volatile("T11_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[11] = end - start;

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T12: {
		static const int next[5] = { 0, 29, 31, 2, 30 };
		fixedpt  scores[5];

		__asm__ volatile("T12_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P12(in1, in2, in3, in4);
        scores[1] = P36(in1, in2, in3, in4);
        scores[2] = P37(in1, in2, in3, in4);
        scores[3] = P15(in1, in2, in3, in4);
        scores[4] = P38(in1, in2, in3, in4);

		__asm__ volatile("T12_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[12] = end - start;

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T13: {
		static const int next[6] = { 7, 0, 31, 6, 26, 3 };
		fixedpt  scores[6];

		__asm__ volatile("T13_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P39(in1, in2, in3, in4);
        scores[1] = P40(in1, in2, in3, in4);
        scores[2] = P41(in1, in2, in3, in4);
        scores[3] = P42(in1, in2, in3, in4);
        scores[4] = P43(in1, in2, in3, in4);
        scores[5] = P44(in1, in2, in3, in4);

		__asm__ volatile("T13_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[13] = end - start;

		goto *jump_table[next[bestProgram(scores, 6)]];
	}

L_T14: {
		static const int next[3] = { 10, 10, 12 };
		fixedpt  scores[3];

		__asm__ volatile("T14_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P45(in1, in2, in3, in4);
        scores[1] = P46(in1, in2, in3, in4);
        scores[2] = P47(in1, in2, in3, in4);

		__asm__ volatile("T14_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[14] = end - start;

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T15: {
		static const int next[3] = { 11, 0, 8 };
		fixedpt  scores[3];

		__asm__ volatile("T15_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P48(in1, in2, in3, in4);
        scores[1] = P49(in1, in2, in3, in4);
        scores[2] = P50(in1, in2, in3, in4);

		__asm__ volatile("T15_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[15] = end - start;

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T16: {
		static const int next[7] = { 4, 7, 31, 29, 26, 28, 0 };
		fixedpt  scores[7];

		__asm__ volatile("T16_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P51(in1, in2, in3, in4);
        scores[1] = P52(in1, in2, in3, in4);
        scores[2] = P53(in1, in2, in3, in4);
        scores[3] = P54(in1, in2, in3, in4);
        scores[4] = P55(in1, in2, in3, in4);
        scores[5] = P56(in1, in2, in3, in4);
        scores[6] = P57(in1, in2, in3, in4);

		__asm__ volatile("T16_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[16] = end - start;

		goto *jump_table[next[bestProgram(scores, 7)]];
	}

L_T17: {
		static const int next[8] = { 14, 6, 16, 26, 28, 0, 11, 26 };
		fixedpt  scores[8];

		__asm__ volatile("T17_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P58(in1, in2, in3, in4);
        scores[1] = P59(in1, in2, in3, in4);
        scores[2] = P60(in1, in2, in3, in4);
        scores[3] = P61(in1, in2, in3, in4);
        scores[4] = P6(in1, in2, in3, in4);
        scores[5] = P62(in1, in2, in3, in4);
        scores[6] = P48(in1, in2, in3, in4);
        scores[7] = P0(in1, in2, in3, in4);

		__asm__ volatile("T17_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[17] = end - start;

		goto *jump_table[next[bestProgram(scores, 8)]];
	}

L_T18: {
		static const int next[3] = { 17, 0, 15 };
		fixedpt  scores[3];

		__asm__ volatile("T18_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P63(in1, in2, in3, in4);
        scores[1] = P24(in1, in2, in3, in4);
        scores[2] = P64(in1, in2, in3, in4);

		__asm__ volatile("T18_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[18] = end - start;

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T19: {
		static const int next[3] = { 13, 10, 18 };
		fixedpt  scores[3];

		__asm__ volatile("T19_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P65(in1, in2, in3, in4);
        scores[1] = P66(in1, in2, in3, in4);
        scores[2] = P67(in1, in2, in3, in4);

		__asm__ volatile("T19_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[19] = end - start;

		goto *jump_table[next[bestProgram(scores, 3)]];
	}

L_T20: {
		static const int next[5] = { 26, 12, 0, 29, 17 };
		fixedpt  scores[5];

		__asm__ volatile("T20_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P68(in1, in2, in3, in4);
        scores[1] = P69(in1, in2, in3, in4);
        scores[2] = P40(in1, in2, in3, in4);
        scores[3] = P70(in1, in2, in3, in4);
        scores[4] = P71(in1, in2, in3, in4);

		__asm__ volatile("T20_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[20] = end - start;

		goto *jump_table[next[bestProgram(scores, 5)]];
	}

L_T21: {
		static const int next[4] = { 17, 20, 3, 29 };
		fixedpt  scores[4];

		__asm__ volatile("T21_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P72(in1, in2, in3, in4);
        scores[1] = P73(in1, in2, in3, in4);
        scores[2] = P74(in1, in2, in3, in4);
        scores[3] = P70(in1, in2, in3, in4);

		__asm__ volatile("T21_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[21] = end - start;

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T22: {
		static const int next[4] = { 7, 19, 21, 3 };
		fixedpt  scores[4];

		__asm__ volatile("T22_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P75(in1, in2, in3, in4);
        scores[1] = P76(in1, in2, in3, in4);
        scores[2] = P77(in1, in2, in3, in4);
        scores[3] = P78(in1, in2, in3, in4);

		__asm__ volatile("T22_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[22] = end - start;

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T23: {
		static const int next[4] = { 7, 19, 21, 3 };
		fixedpt  scores[4];

		__asm__ volatile("T23_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P75(in1, in2, in3, in4);
        scores[1] = P76(in1, in2, in3, in4);
        scores[2] = P77(in1, in2, in3, in4);
        scores[3] = P79(in1, in2, in3, in4);

		__asm__ volatile("T23_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[23] = end - start;

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T24: {
		static const int next[4] = { 19, 3, 20, 17 };
		fixedpt  scores[4];

		__asm__ volatile("T24_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P76(in1, in2, in3, in4);
        scores[1] = P80(in1, in2, in3, in4);
        scores[2] = P81(in1, in2, in3, in4);
        scores[3] = P82(in1, in2, in3, in4);

		__asm__ volatile("T24_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[24] = end - start;

		goto *jump_table[next[bestProgram(scores, 4)]];
	}

L_T25: {
		static const int next[7] = { 20, 24, 23, 22, 26, 19, 32 };
		fixedpt  scores[7];

		__asm__ volatile("T25_start:");
		CSR_READ(CSR_REG_MCYCLE, &start);

        scores[0] = P83(in1, in2, in3, in4);
        scores[1] = P84(in1, in2, in3, in4);
        scores[2] = P85(in1, in2, in3, in4);
        scores[3] = P86(in1, in2, in3, in4);
        scores[4] = P68(in1, in2, in3, in4);
        scores[5] = P87(in1, in2, in3, in4);
        scores[6] = P88(in1, in2, in3, in4);

		__asm__ volatile("T25_end:");
		CSR_READ(CSR_REG_MCYCLE, &end);

		team_cycles[25] = end - start;

		goto *jump_table[next[bestProgram(scores, 7)]];
	}

L_A5: actions[0] = 5; return;
L_A6: actions[0] = 6; return;
L_A7: actions[0] = 7; return;
L_A0: actions[0] = 0; return;
L_A4: actions[0] = 4; return;
L_A1: actions[0] = 1; return;
L_A3: actions[0] = 3; return;
}
