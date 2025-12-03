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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, A16, A17, A18, A19, A20, A21, A22, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T15;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A16, A17,  };

				fixedpt T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A20, A21, A18,  };

				fixedpt T1Scores[3];

				T1Scores[0] = P2();
				T1Scores[1] = P3();
				T1Scores[2] = P4();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A20, A22, A18,  };

				fixedpt T2Scores[3];

				T2Scores[0] = P5();
				T2Scores[1] = P6();
				T2Scores[2] = P7();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { T1, T0,  };

				fixedpt T3Scores[2];

				T3Scores[0] = P8();
				T3Scores[1] = P9();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[5] = { T1, A19, A18, T3, A20,  };

				fixedpt T4Scores[5];

				T4Scores[0] = P10();
				T4Scores[1] = P11();
				T4Scores[2] = P12();
				T4Scores[3] = P13();
				T4Scores[4] = P14();

				int best = bestProgram(T4Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[4] = { A17, T1, A16, A18,  };

				fixedpt T5Scores[4];

				T5Scores[0] = P15();
				T5Scores[1] = P16();
				T5Scores[2] = P17();
				T5Scores[3] = P18();

				int best = bestProgram(T5Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { T5, T3,  };

				fixedpt T6Scores[2];

				T6Scores[0] = P19();
				T6Scores[1] = P20();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[2] = { T1, A22,  };

				fixedpt T7Scores[2];

				T7Scores[0] = P21();
				T7Scores[1] = P22();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { T5, T3, T4,  };

				fixedpt T8Scores[3];

				T8Scores[0] = P19();
				T8Scores[1] = P20();
				T8Scores[2] = P23();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[4] = { T3, T1, T5, T6,  };

				fixedpt T9Scores[4];

				T9Scores[0] = P20();
				T9Scores[1] = P24();
				T9Scores[2] = P19();
				T9Scores[3] = P25();

				int best = bestProgram(T9Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { A22, A18,  };

				fixedpt T10Scores[2];

				T10Scores[0] = P26();
				T10Scores[1] = P27();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { A18, T7, T8,  };

				fixedpt T11Scores[3];

				T11Scores[0] = P28();
				T11Scores[1] = P29();
				T11Scores[2] = P30();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[1] = { T11,  };

				fixedpt T12Scores[1];

				T12Scores[0] = P31();

				int best = bestProgram(T12Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[5] = { T10, A18, T8, T11, T2,  };

				fixedpt T13Scores[5];

				T13Scores[0] = P32();
				T13Scores[1] = P33();
				T13Scores[2] = P30();
				T13Scores[3] = P34();
				T13Scores[4] = P35();

				int best = bestProgram(T13Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[7] = { T12, T8, T13, T10, T9, T10, T8,  };

				fixedpt T14Scores[7];

				T14Scores[0] = P36();
				T14Scores[1] = P30();
				T14Scores[2] = P37();
				T14Scores[3] = P38();
				T14Scores[4] = P39();
				T14Scores[5] = P40();
				T14Scores[6] = P41();

				int best = bestProgram(T14Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[1] = { T14,  };

				fixedpt T15Scores[1];

				T15Scores[0] = P42();

				int best = bestProgram(T15Scores, 1);
				currentVertex = next[best];
				break;
			}
		case A16: {
				actions[0] = 3;
				return;
			}
		case A17: {
				actions[0] = 4;
				return;
			}
		case A18: {
				actions[0] = 6;
				return;
			}
		case A19: {
				actions[0] = 7;
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
		case A22: {
				actions[0] = 5;
				return;
			}
		}
	}
}
