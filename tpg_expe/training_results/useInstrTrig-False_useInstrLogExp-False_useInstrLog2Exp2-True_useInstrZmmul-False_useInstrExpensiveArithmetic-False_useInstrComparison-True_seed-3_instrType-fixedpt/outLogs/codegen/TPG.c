/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:09
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, A13, A14, A15, A16, A17, A18, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T12;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A16, A13,  };

				fixedpt T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A14, A15, T0,  };

				fixedpt T1Scores[3];

				T1Scores[0] = P2();
				T1Scores[1] = P3();
				T1Scores[2] = P4();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[1] = { T1,  };

				fixedpt T2Scores[1];

				T2Scores[0] = P5();

				int best = bestProgram(T2Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[1] = { T1,  };

				fixedpt T3Scores[1];

				T3Scores[0] = P6();

				int best = bestProgram(T3Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[2] = { T1, T3,  };

				fixedpt T4Scores[2];

				T4Scores[0] = P5();
				T4Scores[1] = P7();

				int best = bestProgram(T4Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { T2, T1,  };

				fixedpt T5Scores[2];

				T5Scores[0] = P8();
				T5Scores[1] = P9();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[4] = { A17, T5, T4, T1,  };

				fixedpt T6Scores[4];

				T6Scores[0] = P10();
				T6Scores[1] = P11();
				T6Scores[2] = P12();
				T6Scores[3] = P6();

				int best = bestProgram(T6Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[1] = { T6,  };

				fixedpt T7Scores[1];

				T7Scores[0] = P13();

				int best = bestProgram(T7Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { A17, T1, T4,  };

				fixedpt T8Scores[3];

				T8Scores[0] = P14();
				T8Scores[1] = P15();
				T8Scores[2] = P16();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[3] = { T1, T8, A16,  };

				fixedpt T9Scores[3];

				T9Scores[0] = P17();
				T9Scores[1] = P18();
				T9Scores[2] = P19();

				int best = bestProgram(T9Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[5] = { T1, T8, T7, A18, T4,  };

				fixedpt T10Scores[5];

				T10Scores[0] = P20();
				T10Scores[1] = P18();
				T10Scores[2] = P21();
				T10Scores[3] = P22();
				T10Scores[4] = P23();

				int best = bestProgram(T10Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[6] = { T7, T10, A16, T9, T7, T7,  };

				fixedpt T11Scores[6];

				T11Scores[0] = P24();
				T11Scores[1] = P25();
				T11Scores[2] = P19();
				T11Scores[3] = P26();
				T11Scores[4] = P27();
				T11Scores[5] = P28();

				int best = bestProgram(T11Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[4] = { A18, T7, T11, T10,  };

				fixedpt T12Scores[4];

				T12Scores[0] = P29();
				T12Scores[1] = P30();
				T12Scores[2] = P31();
				T12Scores[3] = P32();

				int best = bestProgram(T12Scores, 4);
				currentVertex = next[best];
				break;
			}
		case A13: {
				actions[0] = 0;
				return;
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
				actions[0] = 4;
				return;
			}
		case A17: {
				actions[0] = 2;
				return;
			}
		case A18: {
				actions[0] = 1;
				return;
			}
		}
	}
}
