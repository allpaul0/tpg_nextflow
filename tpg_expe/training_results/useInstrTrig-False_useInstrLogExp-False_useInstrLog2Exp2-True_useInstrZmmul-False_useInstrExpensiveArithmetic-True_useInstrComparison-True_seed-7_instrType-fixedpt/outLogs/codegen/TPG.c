/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:26
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, A15, A16, A17, A18, A19, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T14;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A15, A16,  };

				fixedpt T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A18, A19, A16,  };

				fixedpt T1Scores[3];

				T1Scores[0] = P2();
				T1Scores[1] = P3();
				T1Scores[2] = P4();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { T0, A16, A18,  };

				fixedpt T2Scores[3];

				T2Scores[0] = P5();
				T2Scores[1] = P6();
				T2Scores[2] = P7();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { T1, A15, A17,  };

				fixedpt T3Scores[3];

				T3Scores[0] = P8();
				T3Scores[1] = P9();
				T3Scores[2] = P10();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[4] = { A16, T1, A18, A17,  };

				fixedpt T4Scores[4];

				T4Scores[0] = P11();
				T4Scores[1] = P8();
				T4Scores[2] = P12();
				T4Scores[3] = P13();

				int best = bestProgram(T4Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[3] = { A17, A16, T1,  };

				fixedpt T5Scores[3];

				T5Scores[0] = P14();
				T5Scores[1] = P15();
				T5Scores[2] = P16();

				int best = bestProgram(T5Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[1] = { T4,  };

				fixedpt T6Scores[1];

				T6Scores[0] = P17();

				int best = bestProgram(T6Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[1] = { T4,  };

				fixedpt T7Scores[1];

				T7Scores[0] = P17();

				int best = bestProgram(T7Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { T4,  };

				fixedpt T8Scores[1];

				T8Scores[0] = P17();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T5,  };

				fixedpt T9Scores[1];

				T9Scores[0] = P18();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { T2, T9, T6,  };

				fixedpt T10Scores[3];

				T10Scores[0] = P19();
				T10Scores[1] = P20();
				T10Scores[2] = P21();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[4] = { T10, T7, T8, T2,  };

				fixedpt T11Scores[4];

				T11Scores[0] = P22();
				T11Scores[1] = P23();
				T11Scores[2] = P24();
				T11Scores[3] = P19();

				int best = bestProgram(T11Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[3] = { A18, T3, T11,  };

				fixedpt T12Scores[3];

				T12Scores[0] = P25();
				T12Scores[1] = P26();
				T12Scores[2] = P27();

				int best = bestProgram(T12Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[2] = { A18, T11,  };

				fixedpt T13Scores[2];

				T13Scores[0] = P25();
				T13Scores[1] = P27();

				int best = bestProgram(T13Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[2] = { T13, T12,  };

				fixedpt T14Scores[2];

				T14Scores[0] = P28();
				T14Scores[1] = P29();

				int best = bestProgram(T14Scores, 2);
				currentVertex = next[best];
				break;
			}
		case A15: {
				actions[0] = 5;
				return;
			}
		case A16: {
				actions[0] = 6;
				return;
			}
		case A17: {
				actions[0] = 3;
				return;
			}
		case A18: {
				actions[0] = 4;
				return;
			}
		case A19: {
				actions[0] = 0;
				return;
			}
		}
	}
}
