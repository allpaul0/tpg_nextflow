/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:29
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, A18, A19, A20, A21, A22, A23, A24, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T17;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[3] = { A18, A19, A20,  };

				double T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A18, A19, A22,  };

				double T1Scores[3];

				T1Scores[0] = P3();
				T1Scores[1] = P4();
				T1Scores[2] = P5();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { T0, A21,  };

				double T2Scores[2];

				T2Scores[0] = P6();
				T2Scores[1] = P7();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[4] = { A21, A21, T1, A19,  };

				double T3Scores[4];

				T3Scores[0] = P8();
				T3Scores[1] = P9();
				T3Scores[2] = P10();
				T3Scores[3] = P11();

				int best = bestProgram(T3Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { A19, A18, T3,  };

				double T4Scores[3];

				T4Scores[0] = P12();
				T4Scores[1] = P13();
				T4Scores[2] = P14();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { A23, A18,  };

				double T5Scores[2];

				T5Scores[0] = P15();
				T5Scores[1] = P0();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[6] = { A23, T4, A19, A18, T1, A21,  };

				double T6Scores[6];

				T6Scores[0] = P16();
				T6Scores[1] = P17();
				T6Scores[2] = P18();
				T6Scores[3] = P19();
				T6Scores[4] = P20();
				T6Scores[5] = P21();

				int best = bestProgram(T6Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[2] = { T1, T6,  };

				double T7Scores[2];

				T7Scores[0] = P22();
				T7Scores[1] = P23();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { T5, T2, A19,  };

				double T8Scores[3];

				T8Scores[0] = P24();
				T8Scores[1] = P25();
				T8Scores[2] = P11();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[4] = { T2, T6, A23, A24,  };

				double T9Scores[4];

				T9Scores[0] = P26();
				T9Scores[1] = P27();
				T9Scores[2] = P28();
				T9Scores[3] = P29();

				int best = bestProgram(T9Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[4] = { T1, A24, T2, T6,  };

				double T10Scores[4];

				T10Scores[0] = P30();
				T10Scores[1] = P31();
				T10Scores[2] = P32();
				T10Scores[3] = P33();

				int best = bestProgram(T10Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[5] = { T6, T1, T6, T8, A24,  };

				double T11Scores[5];

				T11Scores[0] = P34();
				T11Scores[1] = P35();
				T11Scores[2] = P33();
				T11Scores[3] = P36();
				T11Scores[4] = P37();

				int best = bestProgram(T11Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[4] = { T10, T1, A24, T7,  };

				double T12Scores[4];

				T12Scores[0] = P38();
				T12Scores[1] = P39();
				T12Scores[2] = P31();
				T12Scores[3] = P40();

				int best = bestProgram(T12Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[4] = { A23, A24, T4, T6,  };

				double T13Scores[4];

				T13Scores[0] = P41();
				T13Scores[1] = P31();
				T13Scores[2] = P42();
				T13Scores[3] = P33();

				int best = bestProgram(T13Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[1] = { A23,  };

				double T14Scores[1];

				T14Scores[0] = P43();

				int best = bestProgram(T14Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[5] = { T11, T9, T13, T12, T11,  };

				double T15Scores[5];

				T15Scores[0] = P44();
				T15Scores[1] = P45();
				T15Scores[2] = P46();
				T15Scores[3] = P47();
				T15Scores[4] = P48();

				int best = bestProgram(T15Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[1] = { T14,  };

				double T16Scores[1];

				T16Scores[0] = P49();

				int best = bestProgram(T16Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[7] = { T16, T12, T9, T15, A24, T2, T1,  };

				double T17Scores[7];

				T17Scores[0] = P50();
				T17Scores[1] = P51();
				T17Scores[2] = P52();
				T17Scores[3] = P53();
				T17Scores[4] = P54();
				T17Scores[5] = P55();
				T17Scores[6] = P56();

				int best = bestProgram(T17Scores, 7);
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
				actions[0] = 7;
				return;
			}
		case A21: {
				actions[0] = 0;
				return;
			}
		case A22: {
				actions[0] = 4;
				return;
			}
		case A23: {
				actions[0] = 1;
				return;
			}
		case A24: {
				actions[0] = 2;
				return;
			}
		}
	}
}
