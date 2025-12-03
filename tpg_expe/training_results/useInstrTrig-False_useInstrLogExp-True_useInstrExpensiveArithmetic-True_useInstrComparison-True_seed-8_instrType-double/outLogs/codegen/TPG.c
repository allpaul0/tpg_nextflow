/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:38
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, A19, A20, A21, A22, A23, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T18;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A19, A20,  };

				double T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { T0, A21,  };

				double T1Scores[2];

				T1Scores[0] = P2();
				T1Scores[1] = P3();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[1] = { A21,  };

				double T2Scores[1];

				T2Scores[0] = P3();

				int best = bestProgram(T2Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[6] = { A20, A20, A20, A19, A20, A21,  };

				double T3Scores[6];

				T3Scores[0] = P4();
				T3Scores[1] = P5();
				T3Scores[2] = P6();
				T3Scores[3] = P0();
				T3Scores[4] = P7();
				T3Scores[5] = P3();

				int best = bestProgram(T3Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { T3, A19, A20,  };

				double T4Scores[3];

				T4Scores[0] = P8();
				T4Scores[1] = P9();
				T4Scores[2] = P10();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[3] = { T3, A19, T4,  };

				double T5Scores[3];

				T5Scores[0] = P11();
				T5Scores[1] = P9();
				T5Scores[2] = P12();

				int best = bestProgram(T5Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[3] = { A20, T3, A22,  };

				double T6Scores[3];

				T6Scores[0] = P13();
				T6Scores[1] = P8();
				T6Scores[2] = P14();

				int best = bestProgram(T6Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[6] = { A22, T1, T2, A20, A19, T6,  };

				double T7Scores[6];

				T7Scores[0] = P15();
				T7Scores[1] = P16();
				T7Scores[2] = P17();
				T7Scores[3] = P18();
				T7Scores[4] = P9();
				T7Scores[5] = P19();

				int best = bestProgram(T7Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { A20, T3, A19,  };

				double T8Scores[3];

				T8Scores[0] = P18();
				T8Scores[1] = P8();
				T8Scores[2] = P0();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T8,  };

				double T9Scores[1];

				T9Scores[0] = P20();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[4] = { A22, T5, T9, A20,  };

				double T10Scores[4];

				T10Scores[0] = P15();
				T10Scores[1] = P21();
				T10Scores[2] = P22();
				T10Scores[3] = P23();

				int best = bestProgram(T10Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[1] = { T10,  };

				double T11Scores[1];

				T11Scores[0] = P24();

				int best = bestProgram(T11Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[2] = { T7, T11,  };

				double T12Scores[2];

				T12Scores[0] = P25();
				T12Scores[1] = P26();

				int best = bestProgram(T12Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[1] = { T10,  };

				double T13Scores[1];

				T13Scores[0] = P27();

				int best = bestProgram(T13Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[1] = { T12,  };

				double T14Scores[1];

				T14Scores[0] = P28();

				int best = bestProgram(T14Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[1] = { T13,  };

				double T15Scores[1];

				T15Scores[0] = P29();

				int best = bestProgram(T15Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[4] = { A23, A22, T15, A20,  };

				double T16Scores[4];

				T16Scores[0] = P30();
				T16Scores[1] = P31();
				T16Scores[2] = P32();
				T16Scores[3] = P33();

				int best = bestProgram(T16Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[5] = { A23, A23, A21, T14, A22,  };

				double T17Scores[5];

				T17Scores[0] = P34();
				T17Scores[1] = P35();
				T17Scores[2] = P36();
				T17Scores[3] = P37();
				T17Scores[4] = P15();

				int best = bestProgram(T17Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[3] = { T16, T14, T17,  };

				double T18Scores[3];

				T18Scores[0] = P38();
				T18Scores[1] = P39();
				T18Scores[2] = P40();

				int best = bestProgram(T18Scores, 3);
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
				actions[0] = 2;
				return;
			}
		case A23: {
				actions[0] = 1;
				return;
			}
		}
	}
}
