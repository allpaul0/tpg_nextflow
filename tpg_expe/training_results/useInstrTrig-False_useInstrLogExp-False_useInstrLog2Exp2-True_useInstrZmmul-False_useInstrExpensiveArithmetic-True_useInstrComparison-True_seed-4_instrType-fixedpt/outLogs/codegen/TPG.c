/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:21
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
				const enum vertices next[4] = { A17, A12, A16, A13,  };

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
				const enum vertices next[3] = { A16, A14, A12,  };

				fixedpt T1Scores[3];

				T1Scores[0] = P2();
				T1Scores[1] = P4();
				T1Scores[2] = P1();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[4] = { A14, A16, A12, A15,  };

				fixedpt T2Scores[4];

				T2Scores[0] = P5();
				T2Scores[1] = P6();
				T2Scores[2] = P7();
				T2Scores[3] = P8();

				int best = bestProgram(T2Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[4] = { A12, A16, A15, A17,  };

				fixedpt T3Scores[4];

				T3Scores[0] = P9();
				T3Scores[1] = P10();
				T3Scores[2] = P11();
				T3Scores[3] = P12();

				int best = bestProgram(T3Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { T1, T0, T2,  };

				fixedpt T4Scores[3];

				T4Scores[0] = P13();
				T4Scores[1] = P14();
				T4Scores[2] = P15();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { T2, T0,  };

				fixedpt T5Scores[2];

				T5Scores[0] = P16();
				T5Scores[1] = P17();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[1] = { T4,  };

				fixedpt T6Scores[1];

				T6Scores[0] = P18();

				int best = bestProgram(T6Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[2] = { T0, T4,  };

				fixedpt T7Scores[2];

				T7Scores[0] = P19();
				T7Scores[1] = P20();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[4] = { T0, A17, T4, T5,  };

				fixedpt T8Scores[4];

				T8Scores[0] = P21();
				T8Scores[1] = P22();
				T8Scores[2] = P23();
				T8Scores[3] = P24();

				int best = bestProgram(T8Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[4] = { T5, T7, T4, T6,  };

				fixedpt T9Scores[4];

				T9Scores[0] = P25();
				T9Scores[1] = P26();
				T9Scores[2] = P23();
				T9Scores[3] = P27();

				int best = bestProgram(T9Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[4] = { T0, T9, T4, T8,  };

				fixedpt T10Scores[4];

				T10Scores[0] = P21();
				T10Scores[1] = P28();
				T10Scores[2] = P29();
				T10Scores[3] = P30();

				int best = bestProgram(T10Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[6] = { T4, T10, T3, T0, T9, T10,  };

				fixedpt T11Scores[6];

				T11Scores[0] = P29();
				T11Scores[1] = P31();
				T11Scores[2] = P32();
				T11Scores[3] = P33();
				T11Scores[4] = P34();
				T11Scores[5] = P35();

				int best = bestProgram(T11Scores, 6);
				currentVertex = next[best];
				break;
			}
		case A12: {
				actions[0] = 5;
				return;
			}
		case A13: {
				actions[0] = 6;
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
				actions[0] = 4;
				return;
			}
		case A17: {
				actions[0] = 7;
				return;
			}
		}
	}
}
