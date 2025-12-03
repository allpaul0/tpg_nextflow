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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, A15, A16, A17, A18, A19, A20, A21, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T14;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[3] = { A18, A19, A17,  };

				fixedpt T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { T0, A20, A17,  };

				fixedpt T1Scores[3];

				T1Scores[0] = P3();
				T1Scores[1] = P4();
				T1Scores[2] = P5();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { A17, A17,  };

				fixedpt T2Scores[2];

				T2Scores[0] = P6();
				T2Scores[1] = P7();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { T0, T2,  };

				fixedpt T3Scores[2];

				T3Scores[0] = P3();
				T3Scores[1] = P8();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[5] = { A15, A19, T1, A20, T3,  };

				fixedpt T4Scores[5];

				T4Scores[0] = P9();
				T4Scores[1] = P10();
				T4Scores[2] = P11();
				T4Scores[3] = P12();
				T4Scores[4] = P13();

				int best = bestProgram(T4Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { A21, A17,  };

				fixedpt T5Scores[2];

				T5Scores[0] = P14();
				T5Scores[1] = P15();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[7] = { A21, A19, A16, A21, T0, A18, T1,  };

				fixedpt T6Scores[7];

				T6Scores[0] = P16();
				T6Scores[1] = P17();
				T6Scores[2] = P18();
				T6Scores[3] = P19();
				T6Scores[4] = P3();
				T6Scores[5] = P20();
				T6Scores[6] = P21();

				int best = bestProgram(T6Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T5, A19, T4,  };

				fixedpt T7Scores[3];

				T7Scores[0] = P22();
				T7Scores[1] = P23();
				T7Scores[2] = P24();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { A21, T0, A21,  };

				fixedpt T8Scores[3];

				T8Scores[0] = P16();
				T8Scores[1] = P3();
				T8Scores[2] = P25();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[5] = { T6, A16, T8, T7, T6,  };

				fixedpt T9Scores[5];

				T9Scores[0] = P26();
				T9Scores[1] = P27();
				T9Scores[2] = P28();
				T9Scores[3] = P29();
				T9Scores[4] = P30();

				int best = bestProgram(T9Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[1] = { T4,  };

				fixedpt T10Scores[1];

				T10Scores[0] = P31();

				int best = bestProgram(T10Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[2] = { T7, T9,  };

				fixedpt T11Scores[2];

				T11Scores[0] = P32();
				T11Scores[1] = P33();

				int best = bestProgram(T11Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[2] = { T9, T6,  };

				fixedpt T12Scores[2];

				T12Scores[0] = P34();
				T12Scores[1] = P35();

				int best = bestProgram(T12Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[4] = { T10, A18, A20, T0,  };

				fixedpt T13Scores[4];

				T13Scores[0] = P36();
				T13Scores[1] = P37();
				T13Scores[2] = P38();
				T13Scores[3] = P3();

				int best = bestProgram(T13Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[3] = { T13, T11, T12,  };

				fixedpt T14Scores[3];

				T14Scores[0] = P39();
				T14Scores[1] = P40();
				T14Scores[2] = P41();

				int best = bestProgram(T14Scores, 3);
				currentVertex = next[best];
				break;
			}
		case A15: {
				actions[0] = 5;
				return;
			}
		case A16: {
				actions[0] = 7;
				return;
			}
		case A17: {
				actions[0] = 4;
				return;
			}
		case A18: {
				actions[0] = 3;
				return;
			}
		case A19: {
				actions[0] = 6;
				return;
			}
		case A20: {
				actions[0] = 8;
				return;
			}
		case A21: {
				actions[0] = 0;
				return;
			}
		}
	}
}
