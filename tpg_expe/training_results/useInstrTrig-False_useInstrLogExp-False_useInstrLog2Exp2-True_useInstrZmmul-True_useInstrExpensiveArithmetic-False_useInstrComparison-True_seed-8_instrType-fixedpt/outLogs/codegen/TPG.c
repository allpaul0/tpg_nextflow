/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:28
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, A17, A18, A19, A20, A21, A22, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T16;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A17, A18,  };

				fixedpt T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A18, A19, A17,  };

				fixedpt T1Scores[3];

				T1Scores[0] = P2();
				T1Scores[1] = P3();
				T1Scores[2] = P0();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { T1, A21, A20,  };

				fixedpt T2Scores[3];

				T2Scores[0] = P4();
				T2Scores[1] = P5();
				T2Scores[2] = P6();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[4] = { A21, T1, A20, A17,  };

				fixedpt T3Scores[4];

				T3Scores[0] = P7();
				T3Scores[1] = P8();
				T3Scores[2] = P9();
				T3Scores[3] = P10();

				int best = bestProgram(T3Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { T1, A22, T2,  };

				fixedpt T4Scores[3];

				T4Scores[0] = P11();
				T4Scores[1] = P12();
				T4Scores[2] = P13();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[3] = { T0, T4, T3,  };

				fixedpt T5Scores[3];

				T5Scores[0] = P14();
				T5Scores[1] = P15();
				T5Scores[2] = P16();

				int best = bestProgram(T5Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[4] = { T3, T0, A19, T3,  };

				fixedpt T6Scores[4];

				T6Scores[0] = P17();
				T6Scores[1] = P18();
				T6Scores[2] = P19();
				T6Scores[3] = P20();

				int best = bestProgram(T6Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T0, T3, A19,  };

				fixedpt T7Scores[3];

				T7Scores[0] = P21();
				T7Scores[1] = P20();
				T7Scores[2] = P19();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[5] = { T0, T3, T0, T4, T3,  };

				fixedpt T8Scores[5];

				T8Scores[0] = P22();
				T8Scores[1] = P23();
				T8Scores[2] = P18();
				T8Scores[3] = P24();
				T8Scores[4] = P20();

				int best = bestProgram(T8Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T6,  };

				fixedpt T9Scores[1];

				T9Scores[0] = P25();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[4] = { T3, T9, T3, T0,  };

				fixedpt T10Scores[4];

				T10Scores[0] = P26();
				T10Scores[1] = P27();
				T10Scores[2] = P20();
				T10Scores[3] = P21();

				int best = bestProgram(T10Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[2] = { T10, T5,  };

				fixedpt T11Scores[2];

				T11Scores[0] = P28();
				T11Scores[1] = P29();

				int best = bestProgram(T11Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[2] = { T11, T1,  };

				fixedpt T12Scores[2];

				T12Scores[0] = P30();
				T12Scores[1] = P31();

				int best = bestProgram(T12Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[1] = { T6,  };

				fixedpt T13Scores[1];

				T13Scores[0] = P25();

				int best = bestProgram(T13Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[2] = { T11, T12,  };

				fixedpt T14Scores[2];

				T14Scores[0] = P30();
				T14Scores[1] = P32();

				int best = bestProgram(T14Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[2] = { T13, T14,  };

				fixedpt T15Scores[2];

				T15Scores[0] = P33();
				T15Scores[1] = P34();

				int best = bestProgram(T15Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[5] = { T8, T15, T12, T7, T12,  };

				fixedpt T16Scores[5];

				T16Scores[0] = P35();
				T16Scores[1] = P36();
				T16Scores[2] = P37();
				T16Scores[3] = P38();
				T16Scores[4] = P39();

				int best = bestProgram(T16Scores, 5);
				currentVertex = next[best];
				break;
			}
		case A17: {
				actions[0] = 5;
				return;
			}
		case A18: {
				actions[0] = 6;
				return;
			}
		case A19: {
				actions[0] = 4;
				return;
			}
		case A20: {
				actions[0] = 0;
				return;
			}
		case A21: {
				actions[0] = 7;
				return;
			}
		case A22: {
				actions[0] = 8;
				return;
			}
		}
	}
}
