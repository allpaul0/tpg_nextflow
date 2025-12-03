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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, A23, A24, A25, A26, A27, A28, A29, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T22;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[3] = { A24, A23, A25,  };

				fixedpt T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A25, A24, A27,  };

				fixedpt T1Scores[3];

				T1Scores[0] = P3();
				T1Scores[1] = P0();
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
				const enum vertices next[2] = { T0, T2,  };

				fixedpt T3Scores[2];

				T3Scores[0] = P6();
				T3Scores[1] = P7();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[1] = { T2,  };

				fixedpt T4Scores[1];

				T4Scores[0] = P7();

				int best = bestProgram(T4Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { T3, T4,  };

				fixedpt T5Scores[2];

				T5Scores[0] = P8();
				T5Scores[1] = P9();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[1] = { T3,  };

				fixedpt T6Scores[1];

				T6Scores[0] = P8();

				int best = bestProgram(T6Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[1] = { T0,  };

				fixedpt T7Scores[1];

				T7Scores[0] = P10();

				int best = bestProgram(T7Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { T5, A25, A28,  };

				fixedpt T8Scores[3];

				T8Scores[0] = P11();
				T8Scores[1] = P12();
				T8Scores[2] = P13();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T7,  };

				fixedpt T9Scores[1];

				T9Scores[0] = P14();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[4] = { A26, T9, T8, T6,  };

				fixedpt T10Scores[4];

				T10Scores[0] = P15();
				T10Scores[1] = P16();
				T10Scores[2] = P17();
				T10Scores[3] = P18();

				int best = bestProgram(T10Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[1] = { T9,  };

				fixedpt T11Scores[1];

				T11Scores[0] = P16();

				int best = bestProgram(T11Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[1] = { T10,  };

				fixedpt T12Scores[1];

				T12Scores[0] = P19();

				int best = bestProgram(T12Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[1] = { T10,  };

				fixedpt T13Scores[1];

				T13Scores[0] = P20();

				int best = bestProgram(T13Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[1] = { T13,  };

				fixedpt T14Scores[1];

				T14Scores[0] = P21();

				int best = bestProgram(T14Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[3] = { T8, T13, A24,  };

				fixedpt T15Scores[3];

				T15Scores[0] = P17();
				T15Scores[1] = P21();
				T15Scores[2] = P22();

				int best = bestProgram(T15Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[2] = { A28, T12,  };

				fixedpt T16Scores[2];

				T16Scores[0] = P23();
				T16Scores[1] = P24();

				int best = bestProgram(T16Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[2] = { T15, T11,  };

				fixedpt T17Scores[2];

				T17Scores[0] = P25();
				T17Scores[1] = P26();

				int best = bestProgram(T17Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[4] = { A29, T10, T16, T15,  };

				fixedpt T18Scores[4];

				T18Scores[0] = P27();
				T18Scores[1] = P28();
				T18Scores[2] = P29();
				T18Scores[3] = P25();

				int best = bestProgram(T18Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[5] = { T11, A29, T10, T14, T17,  };

				fixedpt T19Scores[5];

				T19Scores[0] = P30();
				T19Scores[1] = P27();
				T19Scores[2] = P28();
				T19Scores[3] = P31();
				T19Scores[4] = P32();

				int best = bestProgram(T19Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[4] = { T15, T18, T14, A29,  };

				fixedpt T20Scores[4];

				T20Scores[0] = P25();
				T20Scores[1] = P33();
				T20Scores[2] = P34();
				T20Scores[3] = P27();

				int best = bestProgram(T20Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[2] = { T6, T20,  };

				fixedpt T21Scores[2];

				T21Scores[0] = P35();
				T21Scores[1] = P36();

				int best = bestProgram(T21Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T22: {
				const enum vertices next[3] = { T19, T21, T15,  };

				fixedpt T22Scores[3];

				T22Scores[0] = P37();
				T22Scores[1] = P38();
				T22Scores[2] = P39();

				int best = bestProgram(T22Scores, 3);
				currentVertex = next[best];
				break;
			}
		case A23: {
				actions[0] = 0;
				return;
			}
		case A24: {
				actions[0] = 7;
				return;
			}
		case A25: {
				actions[0] = 5;
				return;
			}
		case A26: {
				actions[0] = 6;
				return;
			}
		case A27: {
				actions[0] = 4;
				return;
			}
		case A28: {
				actions[0] = 1;
				return;
			}
		case A29: {
				actions[0] = 2;
				return;
			}
		}
	}
}
