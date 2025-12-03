/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:36
 * With the CodeGen::TPGGenerationEngine.
 */

#include "TPG.h"

int bestProgram(float *results, int nb) {
	int bestProgram = 0;
	float bestScore = (isnan(results[0]))? -INFINITY : results[0];
	for (int i = 1; i < nb; i++) {
		float challengerScore = (isnan(results[i]))? -INFINITY : results[i];
		if (challengerScore >= bestScore) {
			bestProgram = i;
			bestScore = challengerScore;
		}
	}
	return bestProgram;
}

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, A9, A10, A11, A12, A13, A14, A15, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T8;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[4] = { A11, A12, A9, A10,  };

				float T0Scores[4];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();
				T0Scores[3] = P3();

				int best = bestProgram(T0Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[4] = { A11, A14, A9, A10,  };

				float T1Scores[4];

				T1Scores[0] = P4();
				T1Scores[1] = P5();
				T1Scores[2] = P2();
				T1Scores[3] = P6();

				int best = bestProgram(T1Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { A12, T0,  };

				float T2Scores[2];

				T2Scores[0] = P7();
				T2Scores[1] = P8();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { T0, A11, T1,  };

				float T3Scores[3];

				T3Scores[0] = P9();
				T3Scores[1] = P10();
				T3Scores[2] = P11();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[1] = { T3,  };

				float T4Scores[1];

				T4Scores[0] = P12();

				int best = bestProgram(T4Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[6] = { T0, T1, T2, A11, A13, A12,  };

				float T5Scores[6];

				T5Scores[0] = P9();
				T5Scores[1] = P11();
				T5Scores[2] = P13();
				T5Scores[3] = P14();
				T5Scores[4] = P15();
				T5Scores[5] = P16();

				int best = bestProgram(T5Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[4] = { T4, A15, T4, T5,  };

				float T6Scores[4];

				T6Scores[0] = P17();
				T6Scores[1] = P18();
				T6Scores[2] = P19();
				T6Scores[3] = P20();

				int best = bestProgram(T6Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[5] = { T4, T1, A15, A13, T0,  };

				float T7Scores[5];

				T7Scores[0] = P21();
				T7Scores[1] = P22();
				T7Scores[2] = P23();
				T7Scores[3] = P24();
				T7Scores[4] = P25();

				int best = bestProgram(T7Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[6] = { T6, A13, A14, A15, T7, A13,  };

				float T8Scores[6];

				T8Scores[0] = P26();
				T8Scores[1] = P27();
				T8Scores[2] = P28();
				T8Scores[3] = P23();
				T8Scores[4] = P29();
				T8Scores[5] = P30();

				int best = bestProgram(T8Scores, 6);
				currentVertex = next[best];
				break;
			}
		case A9: {
				actions[0] = 4;
				return;
			}
		case A10: {
				actions[0] = 0;
				return;
			}
		case A11: {
				actions[0] = 5;
				return;
			}
		case A12: {
				actions[0] = 6;
				return;
			}
		case A13: {
				actions[0] = 7;
				return;
			}
		case A14: {
				actions[0] = 1;
				return;
			}
		case A15: {
				actions[0] = 2;
				return;
			}
		}
	}
}
