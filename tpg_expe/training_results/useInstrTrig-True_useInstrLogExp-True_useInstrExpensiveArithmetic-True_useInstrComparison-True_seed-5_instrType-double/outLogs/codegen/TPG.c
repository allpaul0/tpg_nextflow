/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:25
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
				const enum vertices next[2] = { A20, A21,  };

				double T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[4] = { A22, A23, A21, A24,  };

				double T1Scores[4];

				T1Scores[0] = P2();
				T1Scores[1] = P3();
				T1Scores[2] = P4();
				T1Scores[3] = P5();

				int best = bestProgram(T1Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[1] = { T1,  };

				double T2Scores[1];

				T2Scores[0] = P6();

				int best = bestProgram(T2Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { A25, A21,  };

				double T3Scores[2];

				T3Scores[0] = P7();
				T3Scores[1] = P8();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[1] = { A23,  };

				double T4Scores[1];

				T4Scores[0] = P9();

				int best = bestProgram(T4Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { A23, A24,  };

				double T5Scores[2];

				T5Scores[0] = P10();
				T5Scores[1] = P11();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[7] = { A25, T2, T3, A23, A24, T2, T0,  };

				double T6Scores[7];

				T6Scores[0] = P7();
				T6Scores[1] = P12();
				T6Scores[2] = P13();
				T6Scores[3] = P14();
				T6Scores[4] = P11();
				T6Scores[5] = P15();
				T6Scores[6] = P16();

				int best = bestProgram(T6Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[2] = { T6, A23,  };

				double T7Scores[2];

				T7Scores[0] = P17();
				T7Scores[1] = P18();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { T4,  };

				double T8Scores[1];

				T8Scores[0] = P19();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[5] = { A19, A24, T6, A23, T0,  };

				double T9Scores[5];

				T9Scores[0] = P20();
				T9Scores[1] = P21();
				T9Scores[2] = P22();
				T9Scores[3] = P3();
				T9Scores[4] = P23();

				int best = bestProgram(T9Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { T0, A24, T7,  };

				double T10Scores[3];

				T10Scores[0] = P24();
				T10Scores[1] = P25();
				T10Scores[2] = P26();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[2] = { T9, T8,  };

				double T11Scores[2];

				T11Scores[0] = P27();
				T11Scores[1] = P28();

				int best = bestProgram(T11Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[3] = { T10, A25, T5,  };

				double T12Scores[3];

				T12Scores[0] = P29();
				T12Scores[1] = P30();
				T12Scores[2] = P31();

				int best = bestProgram(T12Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[1] = { T9,  };

				double T13Scores[1];

				T13Scores[0] = P32();

				int best = bestProgram(T13Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[4] = { A19, A23, T6, T0,  };

				double T14Scores[4];

				T14Scores[0] = P20();
				T14Scores[1] = P33();
				T14Scores[2] = P22();
				T14Scores[3] = P34();

				int best = bestProgram(T14Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[4] = { A19, A23, T6, T0,  };

				double T15Scores[4];

				T15Scores[0] = P20();
				T15Scores[1] = P35();
				T15Scores[2] = P22();
				T15Scores[3] = P36();

				int best = bestProgram(T15Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[3] = { A19, T6, T11,  };

				double T16Scores[3];

				T16Scores[0] = P20();
				T16Scores[1] = P37();
				T16Scores[2] = P38();

				int best = bestProgram(T16Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[4] = { T9, A22, A25, T12,  };

				double T17Scores[4];

				T17Scores[0] = P39();
				T17Scores[1] = P40();
				T17Scores[2] = P41();
				T17Scores[3] = P42();

				int best = bestProgram(T17Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[6] = { T14, T16, T12, T13, T15, T17,  };

				double T18Scores[6];

				T18Scores[0] = P43();
				T18Scores[1] = P44();
				T18Scores[2] = P42();
				T18Scores[3] = P45();
				T18Scores[4] = P46();
				T18Scores[5] = P47();

				int best = bestProgram(T18Scores, 6);
				currentVertex = next[best];
				break;
			}
		case A19: {
				actions[0] = 2;
				return;
			}
		case A20: {
				actions[0] = 3;
				return;
			}
		case A21: {
				actions[0] = 4;
				return;
			}
		case A22: {
				actions[0] = 1;
				return;
			}
		case A23: {
				actions[0] = 5;
				return;
			}
		case A24: {
				actions[0] = 6;
				return;
			}
		case A25: {
				actions[0] = 0;
				return;
			}
		}
	}
}
