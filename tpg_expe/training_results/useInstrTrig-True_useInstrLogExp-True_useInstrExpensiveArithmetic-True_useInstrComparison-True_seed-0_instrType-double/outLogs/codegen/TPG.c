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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, A20, A21, A22, A23, A24, A25, A26, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T19;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[3] = { A21, A22, A20,  };

				double T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[1] = { A22,  };

				double T1Scores[1];

				T1Scores[0] = P3();

				int best = bestProgram(T1Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { T0, A22,  };

				double T2Scores[2];

				T2Scores[0] = P4();
				T2Scores[1] = P3();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { A23, A20, A24,  };

				double T3Scores[3];

				T3Scores[0] = P5();
				T3Scores[1] = P2();
				T3Scores[2] = P6();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[4] = { A23, A24, T1, A20,  };

				double T4Scores[4];

				T4Scores[0] = P7();
				T4Scores[1] = P8();
				T4Scores[2] = P9();
				T4Scores[3] = P10();

				int best = bestProgram(T4Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { T3, T2,  };

				double T5Scores[2];

				T5Scores[0] = P11();
				T5Scores[1] = P12();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[1] = { T4,  };

				double T6Scores[1];

				T6Scores[0] = P13();

				int best = bestProgram(T6Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[2] = { T3, T2,  };

				double T7Scores[2];

				T7Scores[0] = P14();
				T7Scores[1] = P15();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { T7,  };

				double T8Scores[1];

				T8Scores[0] = P16();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[4] = { T5, A24, A23, A25,  };

				double T9Scores[4];

				T9Scores[0] = P17();
				T9Scores[1] = P18();
				T9Scores[2] = P19();
				T9Scores[3] = P20();

				int best = bestProgram(T9Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { T5, A24,  };

				double T10Scores[2];

				T10Scores[0] = P21();
				T10Scores[1] = P22();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[1] = { T9,  };

				double T11Scores[1];

				T11Scores[0] = P23();

				int best = bestProgram(T11Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[4] = { T5, T10, A25, A26,  };

				double T12Scores[4];

				T12Scores[0] = P24();
				T12Scores[1] = P25();
				T12Scores[2] = P26();
				T12Scores[3] = P27();

				int best = bestProgram(T12Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[5] = { A26, T9, T5, T10, A26,  };

				double T13Scores[5];

				T13Scores[0] = P28();
				T13Scores[1] = P29();
				T13Scores[2] = P24();
				T13Scores[3] = P30();
				T13Scores[4] = P31();

				int best = bestProgram(T13Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[2] = { T12, T9,  };

				double T14Scores[2];

				T14Scores[0] = P32();
				T14Scores[1] = P33();

				int best = bestProgram(T14Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[4] = { T8, A24, A25, T13,  };

				double T15Scores[4];

				T15Scores[0] = P34();
				T15Scores[1] = P35();
				T15Scores[2] = P36();
				T15Scores[3] = P37();

				int best = bestProgram(T15Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[2] = { T15, T14,  };

				double T16Scores[2];

				T16Scores[0] = P38();
				T16Scores[1] = P39();

				int best = bestProgram(T16Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[3] = { T11, T13, T6,  };

				double T17Scores[3];

				T17Scores[0] = P40();
				T17Scores[1] = P37();
				T17Scores[2] = P41();

				int best = bestProgram(T17Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[7] = { T16, A26, T17, T14, T14, A25, A20,  };

				double T18Scores[7];

				T18Scores[0] = P42();
				T18Scores[1] = P43();
				T18Scores[2] = P44();
				T18Scores[3] = P45();
				T18Scores[4] = P46();
				T18Scores[5] = P36();
				T18Scores[6] = P47();

				int best = bestProgram(T18Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[5] = { T14, T18, A20, T5, A25,  };

				double T19Scores[5];

				T19Scores[0] = P48();
				T19Scores[1] = P49();
				T19Scores[2] = P47();
				T19Scores[3] = P50();
				T19Scores[4] = P51();

				int best = bestProgram(T19Scores, 5);
				currentVertex = next[best];
				break;
			}
		case A20: {
				actions[0] = 5;
				return;
			}
		case A21: {
				actions[0] = 6;
				return;
			}
		case A22: {
				actions[0] = 4;
				return;
			}
		case A23: {
				actions[0] = 7;
				return;
			}
		case A24: {
				actions[0] = 0;
				return;
			}
		case A25: {
				actions[0] = 2;
				return;
			}
		case A26: {
				actions[0] = 1;
				return;
			}
		}
	}
}
