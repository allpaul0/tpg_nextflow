/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:22
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, A10, A11, A12, A13, A14, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T9;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[1] = { A11,  };

				fixedpt T0Scores[1];

				T0Scores[0] = P0();

				int best = bestProgram(T0Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A10, A12,  };

				fixedpt T1Scores[2];

				T1Scores[0] = P1();
				T1Scores[1] = P2();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A12, A10, A10,  };

				fixedpt T2Scores[3];

				T2Scores[0] = P3();
				T2Scores[1] = P4();
				T2Scores[2] = P5();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[4] = { A10, A11, A13, A14,  };

				fixedpt T3Scores[4];

				T3Scores[0] = P6();
				T3Scores[1] = P7();
				T3Scores[2] = P8();
				T3Scores[3] = P9();

				int best = bestProgram(T3Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[5] = { A10, T2, T0, A11, A14,  };

				fixedpt T4Scores[5];

				T4Scores[0] = P5();
				T4Scores[1] = P10();
				T4Scores[2] = P11();
				T4Scores[3] = P12();
				T4Scores[4] = P13();

				int best = bestProgram(T4Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { T4,  };

				fixedpt T5Scores[1];

				T5Scores[0] = P14();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[3] = { T4, A12, T5,  };

				fixedpt T6Scores[3];

				T6Scores[0] = P15();
				T6Scores[1] = P16();
				T6Scores[2] = P17();

				int best = bestProgram(T6Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[4] = { T4, A12, T3, T6,  };

				fixedpt T7Scores[4];

				T7Scores[0] = P15();
				T7Scores[1] = P16();
				T7Scores[2] = P18();
				T7Scores[3] = P19();

				int best = bestProgram(T7Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { T4, T3, T7,  };

				fixedpt T8Scores[3];

				T8Scores[0] = P20();
				T8Scores[1] = P21();
				T8Scores[2] = P22();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[6] = { T8, T7, T1, T8, T6, T6,  };

				fixedpt T9Scores[6];

				T9Scores[0] = P23();
				T9Scores[1] = P24();
				T9Scores[2] = P25();
				T9Scores[3] = P26();
				T9Scores[4] = P27();
				T9Scores[5] = P28();

				int best = bestProgram(T9Scores, 6);
				currentVertex = next[best];
				break;
			}
		case A10: {
				actions[0] = 4;
				return;
			}
		case A11: {
				actions[0] = 5;
				return;
			}
		case A12: {
				actions[0] = 7;
				return;
			}
		case A13: {
				actions[0] = 8;
				return;
			}
		case A14: {
				actions[0] = 0;
				return;
			}
		}
	}
}
