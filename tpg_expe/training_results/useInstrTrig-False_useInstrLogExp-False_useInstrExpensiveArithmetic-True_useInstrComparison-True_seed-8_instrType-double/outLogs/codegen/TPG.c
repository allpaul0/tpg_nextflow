/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:26
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, A21, A22, A23, A24, A25, A26, A27, A28, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T20;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A21, A22,  };

				double T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[4] = { A22, A26, A21, A23,  };

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
				const enum vertices next[3] = { A23, T0, A26,  };

				double T2Scores[3];

				T2Scores[0] = P6();
				T2Scores[1] = P7();
				T2Scores[2] = P8();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { A26, T0, A23,  };

				double T3Scores[3];

				T3Scores[0] = P3();
				T3Scores[1] = P9();
				T3Scores[2] = P10();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[5] = { A23, A21, T0, A23, A26,  };

				double T4Scores[5];

				T4Scores[0] = P11();
				T4Scores[1] = P12();
				T4Scores[2] = P7();
				T4Scores[3] = P13();
				T4Scores[4] = P14();

				int best = bestProgram(T4Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[4] = { T0, A25, T2, A21,  };

				double T5Scores[4];

				T5Scores[0] = P15();
				T5Scores[1] = P16();
				T5Scores[2] = P17();
				T5Scores[3] = P18();

				int best = bestProgram(T5Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[3] = { A25, T2, T0,  };

				double T6Scores[3];

				T6Scores[0] = P16();
				T6Scores[1] = P19();
				T6Scores[2] = P20();

				int best = bestProgram(T6Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T5, A25, T4,  };

				double T7Scores[3];

				T7Scores[0] = P21();
				T7Scores[1] = P22();
				T7Scores[2] = P23();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[5] = { A21, T2, T5, T3, T6,  };

				double T8Scores[5];

				T8Scores[0] = P24();
				T8Scores[1] = P25();
				T8Scores[2] = P21();
				T8Scores[3] = P26();
				T8Scores[4] = P27();

				int best = bestProgram(T8Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T2,  };

				double T9Scores[1];

				T9Scores[0] = P28();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[1] = { T8,  };

				double T10Scores[1];

				T10Scores[0] = P29();

				int best = bestProgram(T10Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[2] = { T8, T2,  };

				double T11Scores[2];

				T11Scores[0] = P29();
				T11Scores[1] = P30();

				int best = bestProgram(T11Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[4] = { T7, T3, T8, A28,  };

				double T12Scores[4];

				T12Scores[0] = P31();
				T12Scores[1] = P32();
				T12Scores[2] = P33();
				T12Scores[3] = P34();

				int best = bestProgram(T12Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[3] = { T10, A28, A24,  };

				double T13Scores[3];

				T13Scores[0] = P35();
				T13Scores[1] = P36();
				T13Scores[2] = P37();

				int best = bestProgram(T13Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[5] = { T7, A28, T8, T4, T12,  };

				double T14Scores[5];

				T14Scores[0] = P38();
				T14Scores[1] = P34();
				T14Scores[2] = P29();
				T14Scores[3] = P39();
				T14Scores[4] = P40();

				int best = bestProgram(T14Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[8] = { A28, T3, T8, A27, T8, T9, T13, T11,  };

				double T15Scores[8];

				T15Scores[0] = P34();
				T15Scores[1] = P32();
				T15Scores[2] = P33();
				T15Scores[3] = P41();
				T15Scores[4] = P42();
				T15Scores[5] = P43();
				T15Scores[6] = P44();
				T15Scores[7] = P45();

				int best = bestProgram(T15Scores, 8);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[5] = { A27, A28, A27, T1, T14,  };

				double T16Scores[5];

				T16Scores[0] = P46();
				T16Scores[1] = P47();
				T16Scores[2] = P41();
				T16Scores[3] = P48();
				T16Scores[4] = P49();

				int best = bestProgram(T16Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[1] = { T1,  };

				double T17Scores[1];

				T17Scores[0] = P50();

				int best = bestProgram(T17Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[4] = { T15, A26, A27, T16,  };

				double T18Scores[4];

				T18Scores[0] = P51();
				T18Scores[1] = P52();
				T18Scores[2] = P53();
				T18Scores[3] = P54();

				int best = bestProgram(T18Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[3] = { T15, T17, A24,  };

				double T19Scores[3];

				T19Scores[0] = P55();
				T19Scores[1] = P56();
				T19Scores[2] = P57();

				int best = bestProgram(T19Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[2] = { T18, T19,  };

				double T20Scores[2];

				T20Scores[0] = P58();
				T20Scores[1] = P59();

				int best = bestProgram(T20Scores, 2);
				currentVertex = next[best];
				break;
			}
		case A21: {
				actions[0] = 5;
				return;
			}
		case A22: {
				actions[0] = 6;
				return;
			}
		case A23: {
				actions[0] = 4;
				return;
			}
		case A24: {
				actions[0] = 7;
				return;
			}
		case A25: {
				actions[0] = 8;
				return;
			}
		case A26: {
				actions[0] = 0;
				return;
			}
		case A27: {
				actions[0] = 2;
				return;
			}
		case A28: {
				actions[0] = 1;
				return;
			}
		}
	}
}
