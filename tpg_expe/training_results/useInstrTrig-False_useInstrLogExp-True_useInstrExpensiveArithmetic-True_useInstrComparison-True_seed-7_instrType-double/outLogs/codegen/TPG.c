/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:30
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, A25, A26, A27, A28, A29, A30, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T24;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A25, A26,  };

				double T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A25, A27,  };

				double T1Scores[2];

				T1Scores[0] = P0();
				T1Scores[1] = P2();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[4] = { T0, A26, T1, A27,  };

				double T2Scores[4];

				T2Scores[0] = P3();
				T2Scores[1] = P4();
				T2Scores[2] = P5();
				T2Scores[3] = P6();

				int best = bestProgram(T2Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { T0, A28, A27,  };

				double T3Scores[3];

				T3Scores[0] = P7();
				T3Scores[1] = P8();
				T3Scores[2] = P9();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[4] = { T0, A28, A27, A26,  };

				double T4Scores[4];

				T4Scores[0] = P10();
				T4Scores[1] = P11();
				T4Scores[2] = P9();
				T4Scores[3] = P12();

				int best = bestProgram(T4Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { T3,  };

				double T5Scores[1];

				T5Scores[0] = P13();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { A28, A27,  };

				double T6Scores[2];

				T6Scores[0] = P14();
				T6Scores[1] = P9();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[1] = { T4,  };

				double T7Scores[1];

				T7Scores[0] = P15();

				int best = bestProgram(T7Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { T5,  };

				double T8Scores[1];

				T8Scores[0] = P16();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[2] = { T2, T6,  };

				double T9Scores[2];

				T9Scores[0] = P17();
				T9Scores[1] = P18();

				int best = bestProgram(T9Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { A26, A29, T7,  };

				double T10Scores[3];

				T10Scores[0] = P12();
				T10Scores[1] = P19();
				T10Scores[2] = P20();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { A28, T9, T2,  };

				double T11Scores[3];

				T11Scores[0] = P21();
				T11Scores[1] = P22();
				T11Scores[2] = P17();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[1] = { T9,  };

				double T12Scores[1];

				T12Scores[0] = P22();

				int best = bestProgram(T12Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[3] = { T5, A29, T11,  };

				double T13Scores[3];

				T13Scores[0] = P23();
				T13Scores[1] = P19();
				T13Scores[2] = P24();

				int best = bestProgram(T13Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[1] = { T13,  };

				double T14Scores[1];

				T14Scores[0] = P25();

				int best = bestProgram(T14Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[3] = { T11, T10, T14,  };

				double T15Scores[3];

				T15Scores[0] = P26();
				T15Scores[1] = P27();
				T15Scores[2] = P28();

				int best = bestProgram(T15Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[2] = { T11, T10,  };

				double T16Scores[2];

				T16Scores[0] = P24();
				T16Scores[1] = P29();

				int best = bestProgram(T16Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[1] = { T12,  };

				double T17Scores[1];

				T17Scores[0] = P30();

				int best = bestProgram(T17Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[4] = { T11, T7, T10, A30,  };

				double T18Scores[4];

				T18Scores[0] = P31();
				T18Scores[1] = P32();
				T18Scores[2] = P33();
				T18Scores[3] = P34();

				int best = bestProgram(T18Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[4] = { T7, A27, T17, T5,  };

				double T19Scores[4];

				T19Scores[0] = P35();
				T19Scores[1] = P9();
				T19Scores[2] = P36();
				T19Scores[3] = P37();

				int best = bestProgram(T19Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[5] = { T10, T8, A30, T15, T5,  };

				double T20Scores[5];

				T20Scores[0] = P38();
				T20Scores[1] = P39();
				T20Scores[2] = P34();
				T20Scores[3] = P40();
				T20Scores[4] = P41();

				int best = bestProgram(T20Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[3] = { A30, T20, T16,  };

				double T21Scores[3];

				T21Scores[0] = P42();
				T21Scores[1] = P43();
				T21Scores[2] = P44();

				int best = bestProgram(T21Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T22: {
				const enum vertices next[3] = { T20, T18, T21,  };

				double T22Scores[3];

				T22Scores[0] = P45();
				T22Scores[1] = P46();
				T22Scores[2] = P47();

				int best = bestProgram(T22Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T23: {
				const enum vertices next[2] = { A30, T20,  };

				double T23Scores[2];

				T23Scores[0] = P48();
				T23Scores[1] = P49();

				int best = bestProgram(T23Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T24: {
				const enum vertices next[4] = { T19, T22, T23, T20,  };

				double T24Scores[4];

				T24Scores[0] = P50();
				T24Scores[1] = P51();
				T24Scores[2] = P52();
				T24Scores[3] = P53();

				int best = bestProgram(T24Scores, 4);
				currentVertex = next[best];
				break;
			}
		case A25: {
				actions[0] = 5;
				return;
			}
		case A26: {
				actions[0] = 6;
				return;
			}
		case A27: {
				actions[0] = 4;
				return;
			}
		case A28: {
				actions[0] = 0;
				return;
			}
		case A29: {
				actions[0] = 2;
				return;
			}
		case A30: {
				actions[0] = 1;
				return;
			}
		}
	}
}
