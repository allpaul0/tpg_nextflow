/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:31
 * With the CodeGen::TPGGenerationEngine.
 */

#include "TPG.h"

int bestProgram(double *results, int nb) {
	int bestProgram = 0;
	double bestScore = (isnan(results[0]))? -INFINITY : results[0];
	for (int i = 1; i < nb; i++) {
		double challengerScore = (isnan(results[i]))? -INFINITY : results[i];
		if (challengerScore >= bestScore) {
			bestProgram = i;
			bestScore = challengerScore;
		}
	}
	return bestProgram;
}

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, A18, A19, A20, A21, A22, A23, A24, A25, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T17;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A18, A19,  };

				double T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A20, A18,  };

				double T1Scores[2];

				T1Scores[0] = P2();
				T1Scores[1] = P3();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[4] = { A18, A20, A22, A19,  };

				double T2Scores[4];

				T2Scores[0] = P4();
				T2Scores[1] = P5();
				T2Scores[2] = P6();
				T2Scores[3] = P7();

				int best = bestProgram(T2Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { T2, A23,  };

				double T3Scores[2];

				T3Scores[0] = P8();
				T3Scores[1] = P9();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[1] = { A20,  };

				double T4Scores[1];

				T4Scores[0] = P10();

				int best = bestProgram(T4Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[6] = { T2, A18, A19, A20, T0, A21,  };

				double T5Scores[6];

				T5Scores[0] = P11();
				T5Scores[1] = P4();
				T5Scores[2] = P7();
				T5Scores[3] = P12();
				T5Scores[4] = P13();
				T5Scores[5] = P14();

				int best = bestProgram(T5Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[4] = { A18, T2, A21, A18,  };

				double T6Scores[4];

				T6Scores[0] = P15();
				T6Scores[1] = P11();
				T6Scores[2] = P16();
				T6Scores[3] = P17();

				int best = bestProgram(T6Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[4] = { A19, T5, A18, A19,  };

				double T7Scores[4];

				T7Scores[0] = P18();
				T7Scores[1] = P19();
				T7Scores[2] = P4();
				T7Scores[3] = P20();

				int best = bestProgram(T7Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[5] = { A19, A19, T3, A24, T1,  };

				double T8Scores[5];

				T8Scores[0] = P7();
				T8Scores[1] = P21();
				T8Scores[2] = P22();
				T8Scores[3] = P23();
				T8Scores[4] = P24();

				int best = bestProgram(T8Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[2] = { T8, A23,  };

				double T9Scores[2];

				T9Scores[0] = P25();
				T9Scores[1] = P26();

				int best = bestProgram(T9Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[9] = { T8, T7, T0, A18, A20, A23, A20, T0, T6,  };

				double T10Scores[9];

				T10Scores[0] = P25();
				T10Scores[1] = P27();
				T10Scores[2] = P28();
				T10Scores[3] = P29();
				T10Scores[4] = P30();
				T10Scores[5] = P26();
				T10Scores[6] = P2();
				T10Scores[7] = P31();
				T10Scores[8] = P32();

				int best = bestProgram(T10Scores, 9);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { A22, T10, T2,  };

				double T11Scores[3];

				T11Scores[0] = P33();
				T11Scores[1] = P34();
				T11Scores[2] = P35();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[7] = { A18, A19, A22, T10, A24, T2, A19,  };

				double T12Scores[7];

				T12Scores[0] = P36();
				T12Scores[1] = P37();
				T12Scores[2] = P33();
				T12Scores[3] = P34();
				T12Scores[4] = P38();
				T12Scores[5] = P39();
				T12Scores[6] = P40();

				int best = bestProgram(T12Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[4] = { A22, T10, T4, T12,  };

				double T13Scores[4];

				T13Scores[0] = P33();
				T13Scores[1] = P41();
				T13Scores[2] = P42();
				T13Scores[3] = P43();

				int best = bestProgram(T13Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[6] = { T13, A18, A19, T12, A23, T9,  };

				double T14Scores[6];

				T14Scores[0] = P44();
				T14Scores[1] = P4();
				T14Scores[2] = P45();
				T14Scores[3] = P46();
				T14Scores[4] = P47();
				T14Scores[5] = P48();

				int best = bestProgram(T14Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[4] = { A25, A19, T14, A24,  };

				double T15Scores[4];

				T15Scores[0] = P49();
				T15Scores[1] = P50();
				T15Scores[2] = P51();
				T15Scores[3] = P52();

				int best = bestProgram(T15Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[2] = { A25, T14,  };

				double T16Scores[2];

				T16Scores[0] = P53();
				T16Scores[1] = P51();

				int best = bestProgram(T16Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[5] = { T16, T14, A24, T15, T11,  };

				double T17Scores[5];

				T17Scores[0] = P54();
				T17Scores[1] = P55();
				T17Scores[2] = P56();
				T17Scores[3] = P57();
				T17Scores[4] = P58();

				int best = bestProgram(T17Scores, 5);
				currentVertex = next[best];
				break;
			}
		case A18: {
				actions[0] = 5;
				return;
			}
		case A19: {
				actions[0] = 6;
				return;
			}
		case A20: {
				actions[0] = 4;
				return;
			}
		case A21: {
				actions[0] = 7;
				return;
			}
		case A22: {
				actions[0] = 0;
				return;
			}
		case A23: {
				actions[0] = 8;
				return;
			}
		case A24: {
				actions[0] = 1;
				return;
			}
		case A25: {
				actions[0] = 2;
				return;
			}
		}
	}
}
