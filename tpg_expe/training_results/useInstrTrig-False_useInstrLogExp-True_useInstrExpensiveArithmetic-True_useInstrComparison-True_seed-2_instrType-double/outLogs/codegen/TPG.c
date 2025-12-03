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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, A23, A24, A25, A26, A27, A28, A29, A30, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T22;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[1] = { A25,  };

				double T0Scores[1];

				T0Scores[0] = P0();

				int best = bestProgram(T0Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A28, A26,  };

				double T1Scores[2];

				T1Scores[0] = P1();
				T1Scores[1] = P2();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { A26, A28,  };

				double T2Scores[2];

				T2Scores[0] = P3();
				T2Scores[1] = P4();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { A23, A28, A26,  };

				double T3Scores[3];

				T3Scores[0] = P5();
				T3Scores[1] = P6();
				T3Scores[2] = P7();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { A24, A27, T1,  };

				double T4Scores[3];

				T4Scores[0] = P8();
				T4Scores[1] = P9();
				T4Scores[2] = P10();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { A24,  };

				double T5Scores[1];

				T5Scores[0] = P11();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[3] = { A23, T2, A24,  };

				double T6Scores[3];

				T6Scores[0] = P5();
				T6Scores[1] = P12();
				T6Scores[2] = P13();

				int best = bestProgram(T6Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[6] = { A23, T2, A24, T6, A26, T3,  };

				double T7Scores[6];

				T7Scores[0] = P5();
				T7Scores[1] = P14();
				T7Scores[2] = P8();
				T7Scores[3] = P15();
				T7Scores[4] = P16();
				T7Scores[5] = P17();

				int best = bestProgram(T7Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[5] = { A23, A25, A24, T2, T4,  };

				double T8Scores[5];

				T8Scores[0] = P5();
				T8Scores[1] = P18();
				T8Scores[2] = P8();
				T8Scores[3] = P12();
				T8Scores[4] = P19();

				int best = bestProgram(T8Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[2] = { T7, T0,  };

				double T9Scores[2];

				T9Scores[0] = P20();
				T9Scores[1] = P21();

				int best = bestProgram(T9Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { A24, A23,  };

				double T10Scores[2];

				T10Scores[0] = P22();
				T10Scores[1] = P23();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { A25, T8, T9,  };

				double T11Scores[3];

				T11Scores[0] = P24();
				T11Scores[1] = P25();
				T11Scores[2] = P26();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[3] = { T4, T10, T5,  };

				double T12Scores[3];

				T12Scores[0] = P27();
				T12Scores[1] = P28();
				T12Scores[2] = P29();

				int best = bestProgram(T12Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[6] = { A24, T0, A23, T5, A25, T2,  };

				double T13Scores[6];

				T13Scores[0] = P30();
				T13Scores[1] = P21();
				T13Scores[2] = P5();
				T13Scores[3] = P29();
				T13Scores[4] = P31();
				T13Scores[5] = P32();

				int best = bestProgram(T13Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[5] = { T8, T9, A26, T8, T13,  };

				double T14Scores[5];

				T14Scores[0] = P33();
				T14Scores[1] = P34();
				T14Scores[2] = P35();
				T14Scores[3] = P36();
				T14Scores[4] = P37();

				int best = bestProgram(T14Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[1] = { T11,  };

				double T15Scores[1];

				T15Scores[0] = P38();

				int best = bestProgram(T15Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[5] = { A29, T12, T14, A25, T11,  };

				double T16Scores[5];

				T16Scores[0] = P39();
				T16Scores[1] = P40();
				T16Scores[2] = P41();
				T16Scores[3] = P42();
				T16Scores[4] = P43();

				int best = bestProgram(T16Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[2] = { T15, A29,  };

				double T17Scores[2];

				T17Scores[0] = P44();
				T17Scores[1] = P45();

				int best = bestProgram(T17Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[4] = { A29, T17, T11, T16,  };

				double T18Scores[4];

				T18Scores[0] = P46();
				T18Scores[1] = P47();
				T18Scores[2] = P48();
				T18Scores[3] = P49();

				int best = bestProgram(T18Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[5] = { A30, A29, T14, T18, T2,  };

				double T19Scores[5];

				T19Scores[0] = P50();
				T19Scores[1] = P51();
				T19Scores[2] = P52();
				T19Scores[3] = P53();
				T19Scores[4] = P54();

				int best = bestProgram(T19Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[4] = { A30, T18, A29, T14,  };

				double T20Scores[4];

				T20Scores[0] = P55();
				T20Scores[1] = P56();
				T20Scores[2] = P57();
				T20Scores[3] = P52();

				int best = bestProgram(T20Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[3] = { A30, A29, T11,  };

				double T21Scores[3];

				T21Scores[0] = P58();
				T21Scores[1] = P59();
				T21Scores[2] = P60();

				int best = bestProgram(T21Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T22: {
				const enum vertices next[4] = { T21, T20, T19, A25,  };

				double T22Scores[4];

				T22Scores[0] = P61();
				T22Scores[1] = P62();
				T22Scores[2] = P63();
				T22Scores[3] = P64();

				int best = bestProgram(T22Scores, 4);
				currentVertex = next[best];
				break;
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
				actions[0] = 8;
				return;
			}
		case A26: {
				actions[0] = 4;
				return;
			}
		case A27: {
				actions[0] = 3;
				return;
			}
		case A28: {
				actions[0] = 0;
				return;
			}
		case A29: {
				actions[0] = 1;
				return;
			}
		case A30: {
				actions[0] = 2;
				return;
			}
		}
	}
}
