/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:35
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, A21, A22, A23, A24, A25, A26, A27, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T20;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A22, A23,  };

				double T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[1] = { A21,  };

				double T1Scores[1];

				T1Scores[0] = P2();

				int best = bestProgram(T1Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[5] = { T1, A26, A25, A24, T0,  };

				double T2Scores[5];

				T2Scores[0] = P3();
				T2Scores[1] = P4();
				T2Scores[2] = P5();
				T2Scores[3] = P6();
				T2Scores[4] = P7();

				int best = bestProgram(T2Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[4] = { T2, A22, A25, A24,  };

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
				const enum vertices next[6] = { A25, A24, A24, T2, A22, A21,  };

				double T4Scores[6];

				T4Scores[0] = P12();
				T4Scores[1] = P6();
				T4Scores[2] = P13();
				T4Scores[3] = P14();
				T4Scores[4] = P15();
				T4Scores[5] = P16();

				int best = bestProgram(T4Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { T4,  };

				double T5Scores[1];

				T5Scores[0] = P17();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { T5, T2,  };

				double T6Scores[2];

				T6Scores[0] = P18();
				T6Scores[1] = P14();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[2] = { T4, T3,  };

				double T7Scores[2];

				T7Scores[0] = P19();
				T7Scores[1] = P20();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[5] = { A24, A22, T6, A23, A21,  };

				double T8Scores[5];

				T8Scores[0] = P21();
				T8Scores[1] = P22();
				T8Scores[2] = P23();
				T8Scores[3] = P24();
				T8Scores[4] = P16();

				int best = bestProgram(T8Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T6,  };

				double T9Scores[1];

				T9Scores[0] = P25();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { T4, T3, A25,  };

				double T10Scores[3];

				T10Scores[0] = P26();
				T10Scores[1] = P20();
				T10Scores[2] = P27();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[5] = { T7, T4, A26, A27, T9,  };

				double T11Scores[5];

				T11Scores[0] = P28();
				T11Scores[1] = P29();
				T11Scores[2] = P4();
				T11Scores[3] = P30();
				T11Scores[4] = P31();

				int best = bestProgram(T11Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[1] = { A25,  };

				double T12Scores[1];

				T12Scores[0] = P27();

				int best = bestProgram(T12Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[3] = { T6, T12, T8,  };

				double T13Scores[3];

				T13Scores[0] = P32();
				T13Scores[1] = P33();
				T13Scores[2] = P34();

				int best = bestProgram(T13Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[2] = { T11, T8,  };

				double T14Scores[2];

				T14Scores[0] = P35();
				T14Scores[1] = P34();

				int best = bestProgram(T14Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[3] = { T8, T13, T11,  };

				double T15Scores[3];

				T15Scores[0] = P36();
				T15Scores[1] = P37();
				T15Scores[2] = P38();

				int best = bestProgram(T15Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[5] = { T7, A26, A27, T10, T8,  };

				double T16Scores[5];

				T16Scores[0] = P28();
				T16Scores[1] = P39();
				T16Scores[2] = P40();
				T16Scores[3] = P41();
				T16Scores[4] = P34();

				int best = bestProgram(T16Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[4] = { T15, T8, T14, T4,  };

				double T17Scores[4];

				T17Scores[0] = P42();
				T17Scores[1] = P43();
				T17Scores[2] = P44();
				T17Scores[3] = P29();

				int best = bestProgram(T17Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[4] = { T13, T17, T16, A25,  };

				double T18Scores[4];

				T18Scores[0] = P37();
				T18Scores[1] = P45();
				T18Scores[2] = P46();
				T18Scores[3] = P47();

				int best = bestProgram(T18Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[3] = { T18, T4, T16,  };

				double T19Scores[3];

				T19Scores[0] = P48();
				T19Scores[1] = P49();
				T19Scores[2] = P50();

				int best = bestProgram(T19Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[5] = { T18, T14, T11, T19, T16,  };

				double T20Scores[5];

				T20Scores[0] = P51();
				T20Scores[1] = P52();
				T20Scores[2] = P35();
				T20Scores[3] = P53();
				T20Scores[4] = P50();

				int best = bestProgram(T20Scores, 5);
				currentVertex = next[best];
				break;
			}
		case A21: {
				actions[0] = 4;
				return;
			}
		case A22: {
				actions[0] = 5;
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
				actions[0] = 6;
				return;
			}
		case A26: {
				actions[0] = 2;
				return;
			}
		case A27: {
				actions[0] = 1;
				return;
			}
		}
	}
}
