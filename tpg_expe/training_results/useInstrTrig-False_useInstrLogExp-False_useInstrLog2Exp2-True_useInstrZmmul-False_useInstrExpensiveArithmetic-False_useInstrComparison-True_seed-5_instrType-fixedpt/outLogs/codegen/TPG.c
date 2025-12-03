/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:15
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, A9, A10, A11, A12, A13, A14, A15, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T8;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[4] = { A9, A12, A10, A13,  };

				fixedpt T0Scores[4];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();
				T0Scores[3] = P3();

				int best = bestProgram(T0Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A11, A10, A14,  };

				fixedpt T1Scores[3];

				T1Scores[0] = P4();
				T1Scores[1] = P2();
				T1Scores[2] = P5();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A9, A13, A12,  };

				fixedpt T2Scores[3];

				T2Scores[0] = P6();
				T2Scores[1] = P7();
				T2Scores[2] = P8();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { A14, T2, A11,  };

				fixedpt T3Scores[3];

				T3Scores[0] = P9();
				T3Scores[1] = P10();
				T3Scores[2] = P4();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { A15, T3, T1,  };

				fixedpt T4Scores[3];

				T4Scores[0] = P11();
				T4Scores[1] = P12();
				T4Scores[2] = P13();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { T4, A9,  };

				fixedpt T5Scores[2];

				T5Scores[0] = P14();
				T5Scores[1] = P15();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[3] = { T5, A15, T1,  };

				fixedpt T6Scores[3];

				T6Scores[0] = P16();
				T6Scores[1] = P11();
				T6Scores[2] = P17();

				int best = bestProgram(T6Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T0, T6, T5,  };

				fixedpt T7Scores[3];

				T7Scores[0] = P18();
				T7Scores[1] = P19();
				T7Scores[2] = P16();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { T6, T7, T6,  };

				fixedpt T8Scores[3];

				T8Scores[0] = P20();
				T8Scores[1] = P21();
				T8Scores[2] = P22();

				int best = bestProgram(T8Scores, 3);
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
				actions[0] = 6;
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
				actions[0] = 2;
				return;
			}
		case A15: {
				actions[0] = 1;
				return;
			}
		}
	}
}
