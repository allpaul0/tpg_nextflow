/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:20
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, A8, A9, A10, A11, A12, A13, A14, A15, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T7;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[4] = { A14, A12, A9, A13,  };

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
				const enum vertices next[5] = { A10, A14, A10, A8, A12,  };

				fixedpt T1Scores[5];

				T1Scores[0] = P4();
				T1Scores[1] = P0();
				T1Scores[2] = P5();
				T1Scores[3] = P6();
				T1Scores[4] = P7();

				int best = bestProgram(T1Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { A8, A10,  };

				fixedpt T2Scores[2];

				T2Scores[0] = P8();
				T2Scores[1] = P5();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { T0, A8, A12,  };

				fixedpt T3Scores[3];

				T3Scores[0] = P9();
				T3Scores[1] = P10();
				T3Scores[2] = P7();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { T1, A12, T2,  };

				fixedpt T4Scores[3];

				T4Scores[0] = P11();
				T4Scores[1] = P12();
				T4Scores[2] = P13();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[5] = { T3, T1, T3, T0, T4,  };

				fixedpt T5Scores[5];

				T5Scores[0] = P14();
				T5Scores[1] = P15();
				T5Scores[2] = P16();
				T5Scores[3] = P17();
				T5Scores[4] = P18();

				int best = bestProgram(T5Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[6] = { T1, A8, T5, T3, T4, T0,  };

				fixedpt T6Scores[6];

				T6Scores[0] = P19();
				T6Scores[1] = P20();
				T6Scores[2] = P21();
				T6Scores[3] = P16();
				T6Scores[4] = P22();
				T6Scores[5] = P23();

				int best = bestProgram(T6Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T6, A15, A11,  };

				fixedpt T7Scores[3];

				T7Scores[0] = P24();
				T7Scores[1] = P25();
				T7Scores[2] = P26();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case A8: {
				actions[0] = 6;
				return;
			}
		case A9: {
				actions[0] = 0;
				return;
			}
		case A10: {
				actions[0] = 8;
				return;
			}
		case A11: {
				actions[0] = 2;
				return;
			}
		case A12: {
				actions[0] = 5;
				return;
			}
		case A13: {
				actions[0] = 7;
				return;
			}
		case A14: {
				actions[0] = 4;
				return;
			}
		case A15: {
				actions[0] = 1;
				return;
			}
		}
	}
}
