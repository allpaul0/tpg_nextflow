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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, A22, A23, A24, A25, A26, A27, A28, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T21;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[1] = { A24,  };

				fixedpt T0Scores[1];

				T0Scores[0] = P0();

				int best = bestProgram(T0Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[4] = { A22, A26, A25, A27,  };

				fixedpt T1Scores[4];

				T1Scores[0] = P1();
				T1Scores[1] = P2();
				T1Scores[2] = P3();
				T1Scores[3] = P4();

				int best = bestProgram(T1Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[4] = { T0, A26, A27, A25,  };

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
				const enum vertices next[1] = { A23,  };

				fixedpt T3Scores[1];

				T3Scores[0] = P9();

				int best = bestProgram(T3Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[2] = { T1, A24,  };

				fixedpt T4Scores[2];

				T4Scores[0] = P10();
				T4Scores[1] = P11();

				int best = bestProgram(T4Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[4] = { A24, A23, A27, T2,  };

				fixedpt T5Scores[4];

				T5Scores[0] = P12();
				T5Scores[1] = P13();
				T5Scores[2] = P4();
				T5Scores[3] = P14();

				int best = bestProgram(T5Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[3] = { A27, T2, A24,  };

				fixedpt T6Scores[3];

				T6Scores[0] = P7();
				T6Scores[1] = P15();
				T6Scores[2] = P16();

				int best = bestProgram(T6Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[2] = { A24, A27,  };

				fixedpt T7Scores[2];

				T7Scores[0] = P17();
				T7Scores[1] = P4();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[4] = { T4, A23, T2, T7,  };

				fixedpt T8Scores[4];

				T8Scores[0] = P18();
				T8Scores[1] = P19();
				T8Scores[2] = P20();
				T8Scores[3] = P21();

				int best = bestProgram(T8Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[2] = { T5, A28,  };

				fixedpt T9Scores[2];

				T9Scores[0] = P22();
				T9Scores[1] = P23();

				int best = bestProgram(T9Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { A28, T5,  };

				fixedpt T10Scores[2];

				T10Scores[0] = P23();
				T10Scores[1] = P22();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { T3, T5, T2,  };

				fixedpt T11Scores[3];

				T11Scores[0] = P24();
				T11Scores[1] = P25();
				T11Scores[2] = P26();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[2] = { T6, T10,  };

				fixedpt T12Scores[2];

				T12Scores[0] = P27();
				T12Scores[1] = P28();

				int best = bestProgram(T12Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[2] = { T8, T9,  };

				fixedpt T13Scores[2];

				T13Scores[0] = P29();
				T13Scores[1] = P30();

				int best = bestProgram(T13Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[2] = { T9, T8,  };

				fixedpt T14Scores[2];

				T14Scores[0] = P31();
				T14Scores[1] = P32();

				int best = bestProgram(T14Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[3] = { T6, T14, T9,  };

				fixedpt T15Scores[3];

				T15Scores[0] = P33();
				T15Scores[1] = P34();
				T15Scores[2] = P30();

				int best = bestProgram(T15Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[2] = { T8, T14,  };

				fixedpt T16Scores[2];

				T16Scores[0] = P35();
				T16Scores[1] = P36();

				int best = bestProgram(T16Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[6] = { T8, T10, T16, T14, A22, T5,  };

				fixedpt T17Scores[6];

				T17Scores[0] = P37();
				T17Scores[1] = P38();
				T17Scores[2] = P39();
				T17Scores[3] = P40();
				T17Scores[4] = P41();
				T17Scores[5] = P42();

				int best = bestProgram(T17Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[6] = { T11, T12, T14, T17, T13, T12,  };

				fixedpt T18Scores[6];

				T18Scores[0] = P43();
				T18Scores[1] = P44();
				T18Scores[2] = P45();
				T18Scores[3] = P46();
				T18Scores[4] = P47();
				T18Scores[5] = P48();

				int best = bestProgram(T18Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[4] = { T8, T15, T12, T11,  };

				fixedpt T19Scores[4];

				T19Scores[0] = P49();
				T19Scores[1] = P50();
				T19Scores[2] = P44();
				T19Scores[3] = P51();

				int best = bestProgram(T19Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[2] = { T19, T6,  };

				fixedpt T20Scores[2];

				T20Scores[0] = P52();
				T20Scores[1] = P33();

				int best = bestProgram(T20Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[7] = { T18, T15, T15, T14, T11, T19, T20,  };

				fixedpt T21Scores[7];

				T21Scores[0] = P53();
				T21Scores[1] = P54();
				T21Scores[2] = P55();
				T21Scores[3] = P45();
				T21Scores[4] = P56();
				T21Scores[5] = P52();
				T21Scores[6] = P57();

				int best = bestProgram(T21Scores, 7);
				currentVertex = next[best];
				break;
			}
		case A22: {
				actions[0] = 6;
				return;
			}
		case A23: {
				actions[0] = 7;
				return;
			}
		case A24: {
				actions[0] = 5;
				return;
			}
		case A25: {
				actions[0] = 4;
				return;
			}
		case A26: {
				actions[0] = 0;
				return;
			}
		case A27: {
				actions[0] = 3;
				return;
			}
		case A28: {
				actions[0] = 2;
				return;
			}
		}
	}
}
