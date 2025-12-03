/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:18
 * With the CodeGen::TPGGenerationEngine.
 */

#include "TPG.h"

int bestProgram(fixedpt *results, int nb) {
	int bestProgram = 0;
	fixedpt bestScore = results[0];
	for (int i = 1; i < nb; i++) {
		fixedpt challengerScore = results[i];
		if (challengerScore >= bestScore) {
			bestProgram = i;
			bestScore = challengerScore;
		}
	}
	return bestProgram;
}

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, A8, A9, A10, A11, A12, A13, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T7;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[3] = { A8, A12, A10,  };

				fixedpt T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[4] = { A12, A10, A10, A11,  };

				fixedpt T1Scores[4];

				T1Scores[0] = P3();
				T1Scores[1] = P4();
				T1Scores[2] = P5();
				T1Scores[3] = P6();

				int best = bestProgram(T1Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { T1, T0,  };

				fixedpt T2Scores[2];

				T2Scores[0] = P7();
				T2Scores[1] = P8();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { T1, T2,  };

				fixedpt T3Scores[2];

				T3Scores[0] = P9();
				T3Scores[1] = P10();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { A9, T1, T2,  };

				fixedpt T4Scores[3];

				T4Scores[0] = P11();
				T4Scores[1] = P12();
				T4Scores[2] = P13();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[3] = { T3, T4, A13,  };

				fixedpt T5Scores[3];

				T5Scores[0] = P14();
				T5Scores[1] = P15();
				T5Scores[2] = P16();

				int best = bestProgram(T5Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[3] = { A13, A13, T5,  };

				fixedpt T6Scores[3];

				T6Scores[0] = P16();
				T6Scores[1] = P17();
				T6Scores[2] = P18();

				int best = bestProgram(T6Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[2] = { T6, T5,  };

				fixedpt T7Scores[2];

				T7Scores[0] = P19();
				T7Scores[1] = P20();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case A8: {
				actions[0] = 4;
				return;
			}
		case A9: {
				actions[0] = 3;
				return;
			}
		case A10: {
				actions[0] = 6;
				return;
			}
		case A11: {
				actions[0] = 0;
				return;
			}
		case A12: {
				actions[0] = 5;
				return;
			}
		case A13: {
				actions[0] = 2;
				return;
			}
		}
	}
}
