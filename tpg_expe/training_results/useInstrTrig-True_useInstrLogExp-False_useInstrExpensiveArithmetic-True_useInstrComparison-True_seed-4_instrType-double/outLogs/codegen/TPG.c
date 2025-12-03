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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, A11, A12, A13, A14, A15, A16, A17, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T10;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[4] = { A11, A12, A13, A14,  };

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
				const enum vertices next[4] = { A15, A16, A11, T0,  };

				double T1Scores[4];

				T1Scores[0] = P4();
				T1Scores[1] = P5();
				T1Scores[2] = P0();
				T1Scores[3] = P6();

				int best = bestProgram(T1Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[8] = { T0, A14, A17, T0, A15, A14, T1, A17,  };

				double T2Scores[8];

				T2Scores[0] = P6();
				T2Scores[1] = P7();
				T2Scores[2] = P8();
				T2Scores[3] = P9();
				T2Scores[4] = P10();
				T2Scores[5] = P11();
				T2Scores[6] = P12();
				T2Scores[7] = P13();

				int best = bestProgram(T2Scores, 8);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[6] = { T0, T0, A15, A17, T1, A14,  };

				double T3Scores[6];

				T3Scores[0] = P14();
				T3Scores[1] = P6();
				T3Scores[2] = P10();
				T3Scores[3] = P15();
				T3Scores[4] = P16();
				T3Scores[5] = P7();

				int best = bestProgram(T3Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[7] = { A17, A17, A15, T2, A17, A17, T1,  };

				double T4Scores[7];

				T4Scores[0] = P17();
				T4Scores[1] = P15();
				T4Scores[2] = P10();
				T4Scores[3] = P18();
				T4Scores[4] = P19();
				T4Scores[5] = P20();
				T4Scores[6] = P21();

				int best = bestProgram(T4Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[3] = { T4, T0, T2,  };

				double T5Scores[3];

				T5Scores[0] = P22();
				T5Scores[1] = P23();
				T5Scores[2] = P24();

				int best = bestProgram(T5Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[5] = { T4, A15, T0, T2, T3,  };

				double T6Scores[5];

				T6Scores[0] = P22();
				T6Scores[1] = P25();
				T6Scores[2] = P23();
				T6Scores[3] = P24();
				T6Scores[4] = P26();

				int best = bestProgram(T6Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[4] = { A15, A15, T6, A17,  };

				double T7Scores[4];

				T7Scores[0] = P27();
				T7Scores[1] = P10();
				T7Scores[2] = P28();
				T7Scores[3] = P29();

				int best = bestProgram(T7Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[6] = { T0, T3, T4, T2, T2, T3,  };

				double T8Scores[6];

				T8Scores[0] = P30();
				T8Scores[1] = P26();
				T8Scores[2] = P31();
				T8Scores[3] = P32();
				T8Scores[4] = P33();
				T8Scores[5] = P34();

				int best = bestProgram(T8Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[5] = { T3, T4, T2, T1, T0,  };

				double T9Scores[5];

				T9Scores[0] = P35();
				T9Scores[1] = P22();
				T9Scores[2] = P24();
				T9Scores[3] = P36();
				T9Scores[4] = P23();

				int best = bestProgram(T9Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[7] = { T8, T5, T7, T0, T4, T9, A14,  };

				double T10Scores[7];

				T10Scores[0] = P37();
				T10Scores[1] = P38();
				T10Scores[2] = P39();
				T10Scores[3] = P30();
				T10Scores[4] = P40();
				T10Scores[5] = P41();
				T10Scores[6] = P11();

				int best = bestProgram(T10Scores, 7);
				currentVertex = next[best];
				break;
			}
		case A11: {
				actions[0] = 4;
				return;
			}
		case A12: {
				actions[0] = 0;
				return;
			}
		case A13: {
				actions[0] = 6;
				return;
			}
		case A14: {
				actions[0] = 3;
				return;
			}
		case A15: {
				actions[0] = 2;
				return;
			}
		case A16: {
				actions[0] = 5;
				return;
			}
		case A17: {
				actions[0] = 1;
				return;
			}
		}
	}
}
