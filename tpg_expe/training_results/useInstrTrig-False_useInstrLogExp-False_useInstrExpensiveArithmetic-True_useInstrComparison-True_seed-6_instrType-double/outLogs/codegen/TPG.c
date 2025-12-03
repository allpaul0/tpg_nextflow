/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:27
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
				const enum vertices next[2] = { A20, A22,  };

				double T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[1] = { A24,  };

				double T1Scores[1];

				T1Scores[0] = P2();

				int best = bestProgram(T1Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[7] = { A23, T0, A24, A21, A24, A25, A20,  };

				double T2Scores[7];

				T2Scores[0] = P3();
				T2Scores[1] = P4();
				T2Scores[2] = P5();
				T2Scores[3] = P6();
				T2Scores[4] = P7();
				T2Scores[5] = P8();
				T2Scores[6] = P9();

				int best = bestProgram(T2Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[1] = { T1,  };

				double T3Scores[1];

				T3Scores[0] = P10();

				int best = bestProgram(T3Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[4] = { A25, A21, A23, A23,  };

				double T4Scores[4];

				T4Scores[0] = P11();
				T4Scores[1] = P6();
				T4Scores[2] = P12();
				T4Scores[3] = P13();

				int best = bestProgram(T4Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { A21, A25,  };

				double T5Scores[2];

				T5Scores[0] = P6();
				T5Scores[1] = P8();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[3] = { A23, A25, A21,  };

				double T6Scores[3];

				T6Scores[0] = P14();
				T6Scores[1] = P8();
				T6Scores[2] = P6();

				int best = bestProgram(T6Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T5, T0, A24,  };

				double T7Scores[3];

				T7Scores[0] = P15();
				T7Scores[1] = P16();
				T7Scores[2] = P17();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { A24,  };

				double T8Scores[1];

				T8Scores[0] = P17();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[5] = { T8, T4, T6, A25, T2,  };

				double T9Scores[5];

				T9Scores[0] = P18();
				T9Scores[1] = P19();
				T9Scores[2] = P20();
				T9Scores[3] = P8();
				T9Scores[4] = P21();

				int best = bestProgram(T9Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[1] = { T5,  };

				double T10Scores[1];

				T10Scores[0] = P15();

				int best = bestProgram(T10Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[2] = { T7, T3,  };

				double T11Scores[2];

				T11Scores[0] = P22();
				T11Scores[1] = P23();

				int best = bestProgram(T11Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[5] = { T10, T2, A23, T0, A23,  };

				double T12Scores[5];

				T12Scores[0] = P24();
				T12Scores[1] = P25();
				T12Scores[2] = P26();
				T12Scores[3] = P27();
				T12Scores[4] = P12();

				int best = bestProgram(T12Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[2] = { T11, T9,  };

				double T13Scores[2];

				T13Scores[0] = P28();
				T13Scores[1] = P29();

				int best = bestProgram(T13Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[4] = { A26, T13, T12, T11,  };

				double T14Scores[4];

				T14Scores[0] = P30();
				T14Scores[1] = P31();
				T14Scores[2] = P32();
				T14Scores[3] = P33();

				int best = bestProgram(T14Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[7] = { A24, T12, A25, A24, T13, A26, A21,  };

				double T15Scores[7];

				T15Scores[0] = P34();
				T15Scores[1] = P35();
				T15Scores[2] = P36();
				T15Scores[3] = P5();
				T15Scores[4] = P37();
				T15Scores[5] = P38();
				T15Scores[6] = P39();

				int best = bestProgram(T15Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[3] = { T15, T9, A21,  };

				double T16Scores[3];

				T16Scores[0] = P40();
				T16Scores[1] = P41();
				T16Scores[2] = P39();

				int best = bestProgram(T16Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[2] = { T14, A25,  };

				double T17Scores[2];

				T17Scores[0] = P42();
				T17Scores[1] = P43();

				int best = bestProgram(T17Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[4] = { A20, T14, A26, A25,  };

				double T18Scores[4];

				T18Scores[0] = P44();
				T18Scores[1] = P42();
				T18Scores[2] = P45();
				T18Scores[3] = P43();

				int best = bestProgram(T18Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[9] = { A22, A26, A25, T9, A25, T16, A24, T18, T17,  };

				double T19Scores[9];

				T19Scores[0] = P46();
				T19Scores[1] = P47();
				T19Scores[2] = P48();
				T19Scores[3] = P49();
				T19Scores[4] = P8();
				T19Scores[5] = P50();
				T19Scores[6] = P51();
				T19Scores[7] = P52();
				T19Scores[8] = P53();

				int best = bestProgram(T19Scores, 9);
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
				actions[0] = 7;
				return;
			}
		case A23: {
				actions[0] = 4;
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
