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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, A22, A23, A24, A25, A26, A27, A28, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T21;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[4] = { A24, A23, A22, A25,  };

				double T0Scores[4];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();
				T0Scores[3] = P3();

				int best = bestProgram(T0Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A24, A27, A25,  };

				double T1Scores[3];

				T1Scores[0] = P4();
				T1Scores[1] = P5();
				T1Scores[2] = P3();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[1] = { A26,  };

				double T2Scores[1];

				T2Scores[0] = P6();

				int best = bestProgram(T2Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { A24, T0, T1,  };

				double T3Scores[3];

				T3Scores[0] = P0();
				T3Scores[1] = P7();
				T3Scores[2] = P8();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[4] = { A23, A27, A26, A23,  };

				double T4Scores[4];

				T4Scores[0] = P9();
				T4Scores[1] = P5();
				T4Scores[2] = P10();
				T4Scores[3] = P11();

				int best = bestProgram(T4Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { T3,  };

				double T5Scores[1];

				T5Scores[0] = P12();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[6] = { A22, T2, A25, T1, A24, A28,  };

				double T6Scores[6];

				T6Scores[0] = P13();
				T6Scores[1] = P14();
				T6Scores[2] = P15();
				T6Scores[3] = P8();
				T6Scores[4] = P16();
				T6Scores[5] = P17();

				int best = bestProgram(T6Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[4] = { A26, T1, A23, A25,  };

				double T7Scores[4];

				T7Scores[0] = P18();
				T7Scores[1] = P8();
				T7Scores[2] = P19();
				T7Scores[3] = P3();

				int best = bestProgram(T7Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[2] = { A25, A24,  };

				double T8Scores[2];

				T8Scores[0] = P15();
				T8Scores[1] = P16();

				int best = bestProgram(T8Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[2] = { T7, T5,  };

				double T9Scores[2];

				T9Scores[0] = P20();
				T9Scores[1] = P21();

				int best = bestProgram(T9Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[5] = { A26, A23, A25, T5, T1,  };

				double T10Scores[5];

				T10Scores[0] = P18();
				T10Scores[1] = P22();
				T10Scores[2] = P23();
				T10Scores[3] = P24();
				T10Scores[4] = P8();

				int best = bestProgram(T10Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[1] = { T8,  };

				double T11Scores[1];

				T11Scores[0] = P25();

				int best = bestProgram(T11Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[4] = { T10, T4, T6, A25,  };

				double T12Scores[4];

				T12Scores[0] = P26();
				T12Scores[1] = P27();
				T12Scores[2] = P28();
				T12Scores[3] = P23();

				int best = bestProgram(T12Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[3] = { T9, T11, T12,  };

				double T13Scores[3];

				T13Scores[0] = P29();
				T13Scores[1] = P30();
				T13Scores[2] = P31();

				int best = bestProgram(T13Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[1] = { T13,  };

				double T14Scores[1];

				T14Scores[0] = P32();

				int best = bestProgram(T14Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[1] = { T13,  };

				double T15Scores[1];

				T15Scores[0] = P32();

				int best = bestProgram(T15Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[11] = { T9, T13, T1, T12, A27, T9, T12, A28, A27, A27, A25,  };

				double T16Scores[11];

				T16Scores[0] = P33();
				T16Scores[1] = P32();
				T16Scores[2] = P34();
				T16Scores[3] = P35();
				T16Scores[4] = P36();
				T16Scores[5] = P37();
				T16Scores[6] = P38();
				T16Scores[7] = P17();
				T16Scores[8] = P39();
				T16Scores[9] = P40();
				T16Scores[10] = P41();

				int best = bestProgram(T16Scores, 11);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[1] = { T4,  };

				double T17Scores[1];

				T17Scores[0] = P42();

				int best = bestProgram(T17Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[3] = { A27, A28, T12,  };

				double T18Scores[3];

				T18Scores[0] = P43();
				T18Scores[1] = P44();
				T18Scores[2] = P45();

				int best = bestProgram(T18Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[2] = { T12, T10,  };

				double T19Scores[2];

				T19Scores[0] = P46();
				T19Scores[1] = P47();

				int best = bestProgram(T19Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[3] = { T15, T14, T17,  };

				double T20Scores[3];

				T20Scores[0] = P48();
				T20Scores[1] = P49();
				T20Scores[2] = P50();

				int best = bestProgram(T20Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[6] = { A27, T19, T18, T16, T20, T12,  };

				double T21Scores[6];

				T21Scores[0] = P51();
				T21Scores[1] = P52();
				T21Scores[2] = P53();
				T21Scores[3] = P54();
				T21Scores[4] = P55();
				T21Scores[5] = P56();

				int best = bestProgram(T21Scores, 6);
				currentVertex = next[best];
				break;
			}
		case A22: {
				actions[0] = 7;
				return;
			}
		case A23: {
				actions[0] = 4;
				return;
			}
		case A24: {
				actions[0] = 5;
				return;
			}
		case A25: {
				actions[0] = 0;
				return;
			}
		case A26: {
				actions[0] = 6;
				return;
			}
		case A27: {
				actions[0] = 1;
				return;
			}
		case A28: {
				actions[0] = 2;
				return;
			}
		}
	}
}
