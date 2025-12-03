/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:27
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, A18, A19, A20, A21, A22, A23, A24, A25, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T17;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[3] = { A18, A20, A22,  };

				fixedpt T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A21, A22, T0,  };

				fixedpt T1Scores[3];

				T1Scores[0] = P3();
				T1Scores[1] = P4();
				T1Scores[2] = P5();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { T0, A22, A21,  };

				fixedpt T2Scores[3];

				T2Scores[0] = P6();
				T2Scores[1] = P2();
				T2Scores[2] = P7();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[5] = { T2, A21, A23, T1, T0,  };

				fixedpt T3Scores[5];

				T3Scores[0] = P8();
				T3Scores[1] = P3();
				T3Scores[2] = P9();
				T3Scores[3] = P10();
				T3Scores[4] = P11();

				int best = bestProgram(T3Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[4] = { T2, A24, T0, A21,  };

				fixedpt T4Scores[4];

				T4Scores[0] = P12();
				T4Scores[1] = P13();
				T4Scores[2] = P6();
				T4Scores[3] = P14();

				int best = bestProgram(T4Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[7] = { T2, A24, A21, A18, A22, A23, T3,  };

				fixedpt T5Scores[7];

				T5Scores[0] = P15();
				T5Scores[1] = P16();
				T5Scores[2] = P3();
				T5Scores[3] = P17();
				T5Scores[4] = P18();
				T5Scores[5] = P19();
				T5Scores[6] = P20();

				int best = bestProgram(T5Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { T2, T4,  };

				fixedpt T6Scores[2];

				T6Scores[0] = P21();
				T6Scores[1] = P22();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[2] = { T4, T5,  };

				fixedpt T7Scores[2];

				T7Scores[0] = P22();
				T7Scores[1] = P23();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { A19, T2, T7,  };

				fixedpt T8Scores[3];

				T8Scores[0] = P24();
				T8Scores[1] = P25();
				T8Scores[2] = P26();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[2] = { T5, T8,  };

				fixedpt T9Scores[2];

				T9Scores[0] = P27();
				T9Scores[1] = P28();

				int best = bestProgram(T9Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[4] = { T4, T5, T8, A24,  };

				fixedpt T10Scores[4];

				T10Scores[0] = P22();
				T10Scores[1] = P27();
				T10Scores[2] = P28();
				T10Scores[3] = P29();

				int best = bestProgram(T10Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[2] = { T5, T9,  };

				fixedpt T11Scores[2];

				T11Scores[0] = P30();
				T11Scores[1] = P31();

				int best = bestProgram(T11Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[1] = { T11,  };

				fixedpt T12Scores[1];

				T12Scores[0] = P32();

				int best = bestProgram(T12Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[2] = { A18, T10,  };

				fixedpt T13Scores[2];

				T13Scores[0] = P33();
				T13Scores[1] = P34();

				int best = bestProgram(T13Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[2] = { T10, T5,  };

				fixedpt T14Scores[2];

				T14Scores[0] = P34();
				T14Scores[1] = P27();

				int best = bestProgram(T14Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[4] = { T14, T10, T5, T6,  };

				fixedpt T15Scores[4];

				T15Scores[0] = P35();
				T15Scores[1] = P36();
				T15Scores[2] = P37();
				T15Scores[3] = P38();

				int best = bestProgram(T15Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[3] = { T13, T9, T15,  };

				fixedpt T16Scores[3];

				T16Scores[0] = P39();
				T16Scores[1] = P40();
				T16Scores[2] = P41();

				int best = bestProgram(T16Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[4] = { T12, A25, T16, T8,  };

				fixedpt T17Scores[4];

				T17Scores[0] = P42();
				T17Scores[1] = P43();
				T17Scores[2] = P44();
				T17Scores[3] = P45();

				int best = bestProgram(T17Scores, 4);
				currentVertex = next[best];
				break;
			}
		case A18: {
				actions[0] = 4;
				return;
			}
		case A19: {
				actions[0] = 8;
				return;
			}
		case A20: {
				actions[0] = 0;
				return;
			}
		case A21: {
				actions[0] = 6;
				return;
			}
		case A22: {
				actions[0] = 3;
				return;
			}
		case A23: {
				actions[0] = 5;
				return;
			}
		case A24: {
				actions[0] = 1;
				return;
			}
		case A25: {
				actions[0] = 2;
				return;
			}
		}
	}
}
