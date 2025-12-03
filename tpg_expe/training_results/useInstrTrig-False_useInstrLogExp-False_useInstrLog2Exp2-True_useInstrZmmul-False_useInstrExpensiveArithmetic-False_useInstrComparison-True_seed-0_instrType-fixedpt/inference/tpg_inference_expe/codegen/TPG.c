/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:12
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, A14, A15, A16, A17, A18, A19, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T13;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[1] = { A15,  };

				fixedpt T0Scores[1];

				T0Scores[0] = P0();

				int best = bestProgram(T0Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A14, A16, A17,  };

				fixedpt T1Scores[3];

				T1Scores[0] = P1();
				T1Scores[1] = P2();
				T1Scores[2] = P3();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A15, A17, T0,  };

				fixedpt T2Scores[3];

				T2Scores[0] = P0();
				T2Scores[1] = P4();
				T2Scores[2] = P5();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[6] = { A15, A14, A18, T2, A14, T1,  };

				fixedpt T3Scores[6];

				T3Scores[0] = P6();
				T3Scores[1] = P7();
				T3Scores[2] = P8();
				T3Scores[3] = P9();
				T3Scores[4] = P10();
				T3Scores[5] = P11();

				int best = bestProgram(T3Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[1] = { T3,  };

				fixedpt T4Scores[1];

				T4Scores[0] = P12();

				int best = bestProgram(T4Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { A19, T3,  };

				fixedpt T5Scores[2];

				T5Scores[0] = P13();
				T5Scores[1] = P14();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { A19, T3,  };

				fixedpt T6Scores[2];

				T6Scores[0] = P13();
				T6Scores[1] = P14();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[2] = { T5, T4,  };

				fixedpt T7Scores[2];

				T7Scores[0] = P15();
				T7Scores[1] = P16();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[2] = { A19, T7,  };

				fixedpt T8Scores[2];

				T8Scores[0] = P17();
				T8Scores[1] = P18();

				int best = bestProgram(T8Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T3,  };

				fixedpt T9Scores[1];

				T9Scores[0] = P19();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { T9, T8,  };

				fixedpt T10Scores[2];

				T10Scores[0] = P20();
				T10Scores[1] = P21();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { T3, T8, A19,  };

				fixedpt T11Scores[3];

				T11Scores[0] = P22();
				T11Scores[1] = P23();
				T11Scores[2] = P13();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[4] = { T3, T11, T6, A19,  };

				fixedpt T12Scores[4];

				T12Scores[0] = P22();
				T12Scores[1] = P24();
				T12Scores[2] = P25();
				T12Scores[3] = P13();

				int best = bestProgram(T12Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[2] = { T12, T10,  };

				fixedpt T13Scores[2];

				T13Scores[0] = P26();
				T13Scores[1] = P27();

				int best = bestProgram(T13Scores, 2);
				currentVertex = next[best];
				break;
			}
		case A14: {
				actions[0] = 5;
				return;
			}
		case A15: {
				actions[0] = 6;
				return;
			}
		case A16: {
				actions[0] = 8;
				return;
			}
		case A17: {
				actions[0] = 4;
				return;
			}
		case A18: {
				actions[0] = 0;
				return;
			}
		case A19: {
				actions[0] = 1;
				return;
			}
		}
	}
}
