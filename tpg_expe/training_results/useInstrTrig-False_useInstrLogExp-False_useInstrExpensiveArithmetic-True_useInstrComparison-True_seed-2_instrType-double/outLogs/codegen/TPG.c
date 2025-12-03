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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, A19, A20, A21, A22, A23, A24, A25, A26, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T18;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[3] = { A19, A20, A21,  };

				double T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A21, A19,  };

				double T1Scores[2];

				T1Scores[0] = P3();
				T1Scores[1] = P4();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A19, A22, A20,  };

				double T2Scores[3];

				T2Scores[0] = P5();
				T2Scores[1] = P6();
				T2Scores[2] = P1();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { T1, A22, T0,  };

				double T3Scores[3];

				T3Scores[0] = P7();
				T3Scores[1] = P6();
				T3Scores[2] = P8();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[4] = { A21, A22, A19, A20,  };

				double T4Scores[4];

				T4Scores[0] = P3();
				T4Scores[1] = P6();
				T4Scores[2] = P9();
				T4Scores[3] = P1();

				int best = bestProgram(T4Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[6] = { T2, A20, A23, A22, A21, T0,  };

				double T5Scores[6];

				T5Scores[0] = P10();
				T5Scores[1] = P11();
				T5Scores[2] = P12();
				T5Scores[3] = P13();
				T5Scores[4] = P14();
				T5Scores[5] = P15();

				int best = bestProgram(T5Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { T4, T3,  };

				double T6Scores[2];

				T6Scores[0] = P16();
				T6Scores[1] = P17();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T3, T4, T6,  };

				double T7Scores[3];

				T7Scores[0] = P18();
				T7Scores[1] = P19();
				T7Scores[2] = P20();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { T5, T7, A24,  };

				double T8Scores[3];

				T8Scores[0] = P21();
				T8Scores[1] = P22();
				T8Scores[2] = P23();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[2] = { T5, T7,  };

				double T9Scores[2];

				T9Scores[0] = P21();
				T9Scores[1] = P24();

				int best = bestProgram(T9Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[1] = { A21,  };

				double T10Scores[1];

				T10Scores[0] = P14();

				int best = bestProgram(T10Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[4] = { T5, T9, T8, A22,  };

				double T11Scores[4];

				T11Scores[0] = P25();
				T11Scores[1] = P26();
				T11Scores[2] = P27();
				T11Scores[3] = P28();

				int best = bestProgram(T11Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[3] = { A26, T5, T11,  };

				double T12Scores[3];

				T12Scores[0] = P29();
				T12Scores[1] = P30();
				T12Scores[2] = P31();

				int best = bestProgram(T12Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[5] = { T11, T5, A26, T10, T5,  };

				double T13Scores[5];

				T13Scores[0] = P32();
				T13Scores[1] = P33();
				T13Scores[2] = P34();
				T13Scores[3] = P35();
				T13Scores[4] = P36();

				int best = bestProgram(T13Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[1] = { T11,  };

				double T14Scores[1];

				T14Scores[0] = P37();

				int best = bestProgram(T14Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[2] = { T14, T5,  };

				double T15Scores[2];

				T15Scores[0] = P38();
				T15Scores[1] = P33();

				int best = bestProgram(T15Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[5] = { A25, T11, A26, T15, T3,  };

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
				const enum vertices next[4] = { T5, T5, T16, T13,  };

				double T17Scores[4];

				T17Scores[0] = P44();
				T17Scores[1] = P45();
				T17Scores[2] = P46();
				T17Scores[3] = P47();

				int best = bestProgram(T17Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[8] = { T12, T3, A26, A22, A25, A22, T5, T17,  };

				double T18Scores[8];

				T18Scores[0] = P48();
				T18Scores[1] = P49();
				T18Scores[2] = P50();
				T18Scores[3] = P51();
				T18Scores[4] = P52();
				T18Scores[5] = P53();
				T18Scores[6] = P54();
				T18Scores[7] = P55();

				int best = bestProgram(T18Scores, 8);
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
				actions[0] = 0;
				return;
			}
		case A23: {
				actions[0] = 8;
				return;
			}
		case A24: {
				actions[0] = 7;
				return;
			}
		case A25: {
				actions[0] = 1;
				return;
			}
		case A26: {
				actions[0] = 2;
				return;
			}
		}
	}
}
