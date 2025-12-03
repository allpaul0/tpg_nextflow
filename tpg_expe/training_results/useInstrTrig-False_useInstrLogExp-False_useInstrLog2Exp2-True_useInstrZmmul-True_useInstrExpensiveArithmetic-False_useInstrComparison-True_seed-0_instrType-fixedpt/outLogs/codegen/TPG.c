/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:24
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, A12, A13, A14, A15, A16, A17, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T11;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[1] = { A14,  };

				fixedpt T0Scores[1];

				T0Scores[0] = P0();

				int best = bestProgram(T0Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A15, A16,  };

				fixedpt T1Scores[2];

				T1Scores[0] = P1();
				T1Scores[1] = P2();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A15, T0, A16,  };

				fixedpt T2Scores[3];

				T2Scores[0] = P3();
				T2Scores[1] = P4();
				T2Scores[2] = P2();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { A13, A16,  };

				fixedpt T3Scores[2];

				T3Scores[0] = P5();
				T3Scores[1] = P2();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[1] = { T3,  };

				fixedpt T4Scores[1];

				T4Scores[0] = P6();

				int best = bestProgram(T4Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { T3,  };

				fixedpt T5Scores[1];

				T5Scores[0] = P6();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[3] = { T2, A15, T5,  };

				fixedpt T6Scores[3];

				T6Scores[0] = P7();
				T6Scores[1] = P8();
				T6Scores[2] = P9();

				int best = bestProgram(T6Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T4, T1, T2,  };

				fixedpt T7Scores[3];

				T7Scores[0] = P10();
				T7Scores[1] = P11();
				T7Scores[2] = P12();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { A12, T2, T7,  };

				fixedpt T8Scores[3];

				T8Scores[0] = P13();
				T8Scores[1] = P14();
				T8Scores[2] = P15();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[4] = { A17, A12, A13, T6,  };

				fixedpt T9Scores[4];

				T9Scores[0] = P16();
				T9Scores[1] = P17();
				T9Scores[2] = P18();
				T9Scores[3] = P19();

				int best = bestProgram(T9Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { T6, A12, T9,  };

				fixedpt T10Scores[3];

				T10Scores[0] = P20();
				T10Scores[1] = P21();
				T10Scores[2] = P22();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[6] = { T10, A13, T6, A13, T8, T6,  };

				fixedpt T11Scores[6];

				T11Scores[0] = P23();
				T11Scores[1] = P24();
				T11Scores[2] = P25();
				T11Scores[3] = P26();
				T11Scores[4] = P27();
				T11Scores[5] = P28();

				int best = bestProgram(T11Scores, 6);
				currentVertex = next[best];
				break;
			}
		case A12: {
				actions[0] = 4;
				return;
			}
		case A13: {
				actions[0] = 5;
				return;
			}
		case A14: {
				actions[0] = 8;
				return;
			}
		case A15: {
				actions[0] = 0;
				return;
			}
		case A16: {
				actions[0] = 6;
				return;
			}
		case A17: {
				actions[0] = 2;
				return;
			}
		}
	}
}
