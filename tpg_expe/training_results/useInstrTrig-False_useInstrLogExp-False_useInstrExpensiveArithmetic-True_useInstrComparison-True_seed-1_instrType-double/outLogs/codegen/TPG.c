/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:28
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, A19, A20, A21, A22, A23, A24, A25, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T18;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[1] = { A22,  };

				double T0Scores[1];

				T0Scores[0] = P0();

				int best = bestProgram(T0Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A23, A20, A19,  };

				double T1Scores[3];

				T1Scores[0] = P1();
				T1Scores[1] = P2();
				T1Scores[2] = P3();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { A20, A21,  };

				double T2Scores[2];

				T2Scores[0] = P4();
				T2Scores[1] = P5();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[6] = { A20, A22, A23, A21, A22, A19,  };

				double T3Scores[6];

				T3Scores[0] = P6();
				T3Scores[1] = P7();
				T3Scores[2] = P8();
				T3Scores[3] = P9();
				T3Scores[4] = P10();
				T3Scores[5] = P11();

				int best = bestProgram(T3Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { T3, A21, T2,  };

				double T4Scores[3];

				T4Scores[0] = P12();
				T4Scores[1] = P13();
				T4Scores[2] = P14();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { T3, A22,  };

				double T5Scores[2];

				T5Scores[0] = P12();
				T5Scores[1] = P15();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[4] = { T2, A21, T2, T3,  };

				double T6Scores[4];

				T6Scores[0] = P16();
				T6Scores[1] = P17();
				T6Scores[2] = P18();
				T6Scores[3] = P12();

				int best = bestProgram(T6Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[5] = { T5, T1, A23, A19, A21,  };

				double T7Scores[5];

				T7Scores[0] = P19();
				T7Scores[1] = P20();
				T7Scores[2] = P21();
				T7Scores[3] = P22();
				T7Scores[4] = P23();

				int best = bestProgram(T7Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { T3,  };

				double T8Scores[1];

				T8Scores[0] = P24();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[4] = { T0, A25, A22, A20,  };

				double T9Scores[4];

				T9Scores[0] = P25();
				T9Scores[1] = P26();
				T9Scores[2] = P27();
				T9Scores[3] = P28();

				int best = bestProgram(T9Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { A25, A20, A22,  };

				double T10Scores[3];

				T10Scores[0] = P29();
				T10Scores[1] = P28();
				T10Scores[2] = P30();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[5] = { T6, T10, T9, T8, A19,  };

				double T11Scores[5];

				T11Scores[0] = P31();
				T11Scores[1] = P32();
				T11Scores[2] = P33();
				T11Scores[3] = P34();
				T11Scores[4] = P35();

				int best = bestProgram(T11Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[2] = { T11, T10,  };

				double T12Scores[2];

				T12Scores[0] = P36();
				T12Scores[1] = P37();

				int best = bestProgram(T12Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[7] = { T11, T6, A25, A25, T11, T6, T4,  };

				double T13Scores[7];

				T13Scores[0] = P38();
				T13Scores[1] = P39();
				T13Scores[2] = P40();
				T13Scores[3] = P41();
				T13Scores[4] = P42();
				T13Scores[5] = P43();
				T13Scores[6] = P44();

				int best = bestProgram(T13Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[5] = { T11, A20, A25, T11, T12,  };

				double T14Scores[5];

				T14Scores[0] = P45();
				T14Scores[1] = P46();
				T14Scores[2] = P47();
				T14Scores[3] = P48();
				T14Scores[4] = P49();

				int best = bestProgram(T14Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[5] = { T13, A20, T14, A25, A20,  };

				double T15Scores[5];

				T15Scores[0] = P50();
				T15Scores[1] = P51();
				T15Scores[2] = P52();
				T15Scores[3] = P53();
				T15Scores[4] = P4();

				int best = bestProgram(T15Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[1] = { T7,  };

				double T16Scores[1];

				T16Scores[0] = P54();

				int best = bestProgram(T16Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[3] = { T15, T13, A20,  };

				double T17Scores[3];

				T17Scores[0] = P55();
				T17Scores[1] = P56();
				T17Scores[2] = P57();

				int best = bestProgram(T17Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[5] = { T15, T13, T16, A24, T17,  };

				double T18Scores[5];

				T18Scores[0] = P55();
				T18Scores[1] = P50();
				T18Scores[2] = P58();
				T18Scores[3] = P59();
				T18Scores[4] = P60();

				int best = bestProgram(T18Scores, 5);
				currentVertex = next[best];
				break;
			}
		case A19: {
				actions[0] = 5;
				return;
			}
		case A20: {
				actions[0] = 6;
				return;
			}
		case A21: {
				actions[0] = 4;
				return;
			}
		case A22: {
				actions[0] = 7;
				return;
			}
		case A23: {
				actions[0] = 2;
				return;
			}
		case A24: {
				actions[0] = 1;
				return;
			}
		case A25: {
				actions[0] = 0;
				return;
			}
		}
	}
}
