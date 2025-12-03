/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:25
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, A9, A10, A11, A12, A13, A14, A15, A16, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T8;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[4] = { A10, A11, A12, A9,  };

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
				const enum vertices next[5] = { T0, A9, A9, A12, A9,  };

				double T1Scores[5];

				T1Scores[0] = P4();
				T1Scores[1] = P5();
				T1Scores[2] = P6();
				T1Scores[3] = P7();
				T1Scores[4] = P8();

				int best = bestProgram(T1Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[4] = { A9, A13, T0, A10,  };

				double T2Scores[4];

				T2Scores[0] = P9();
				T2Scores[1] = P10();
				T2Scores[2] = P11();
				T2Scores[3] = P12();

				int best = bestProgram(T2Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[4] = { A13, T0, A11, T1,  };

				double T3Scores[4];

				T3Scores[0] = P13();
				T3Scores[1] = P14();
				T3Scores[2] = P1();
				T3Scores[3] = P15();

				int best = bestProgram(T3Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[1] = { T3,  };

				double T4Scores[1];

				T4Scores[0] = P16();

				int best = bestProgram(T4Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[8] = { A9, A9, A15, T3, A11, T3, A14, T4,  };

				double T5Scores[8];

				T5Scores[0] = P17();
				T5Scores[1] = P18();
				T5Scores[2] = P19();
				T5Scores[3] = P20();
				T5Scores[4] = P21();
				T5Scores[5] = P22();
				T5Scores[6] = P23();
				T5Scores[7] = P24();

				int best = bestProgram(T5Scores, 8);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[5] = { T5, A16, T3, T3, A15,  };

				double T6Scores[5];

				T6Scores[0] = P25();
				T6Scores[1] = P26();
				T6Scores[2] = P27();
				T6Scores[3] = P28();
				T6Scores[4] = P19();

				int best = bestProgram(T6Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[5] = { T5, A10, T2, A9, T5,  };

				double T7Scores[5];

				T7Scores[0] = P29();
				T7Scores[1] = P30();
				T7Scores[2] = P31();
				T7Scores[3] = P32();
				T7Scores[4] = P33();

				int best = bestProgram(T7Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[9] = { T5, A14, A15, T6, A14, T5, T7, T3, T3,  };

				double T8Scores[9];

				T8Scores[0] = P29();
				T8Scores[1] = P23();
				T8Scores[2] = P34();
				T8Scores[3] = P35();
				T8Scores[4] = P36();
				T8Scores[5] = P37();
				T8Scores[6] = P38();
				T8Scores[7] = P39();
				T8Scores[8] = P40();

				int best = bestProgram(T8Scores, 9);
				currentVertex = next[best];
				break;
			}
		case A9: {
				actions[0] = 0;
				return;
			}
		case A10: {
				actions[0] = 5;
				return;
			}
		case A11: {
				actions[0] = 8;
				return;
			}
		case A12: {
				actions[0] = 7;
				return;
			}
		case A13: {
				actions[0] = 4;
				return;
			}
		case A14: {
				actions[0] = 6;
				return;
			}
		case A15: {
				actions[0] = 2;
				return;
			}
		case A16: {
				actions[0] = 1;
				return;
			}
		}
	}
}
