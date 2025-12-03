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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, A16, A17, A18, A19, A20, A21, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T15;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[1] = { A20,  };

				fixedpt T0Scores[1];

				T0Scores[0] = P0();

				int best = bestProgram(T0Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A21, A20,  };

				fixedpt T1Scores[2];

				T1Scores[0] = P1();
				T1Scores[1] = P2();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A19, A17, A16,  };

				fixedpt T2Scores[3];

				T2Scores[0] = P3();
				T2Scores[1] = P4();
				T2Scores[2] = P5();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { T2, A16,  };

				fixedpt T3Scores[2];

				T3Scores[0] = P6();
				T3Scores[1] = P7();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { A21, A16, T0,  };

				fixedpt T4Scores[3];

				T4Scores[0] = P8();
				T4Scores[1] = P9();
				T4Scores[2] = P10();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[4] = { A16, A17, T1, A16,  };

				fixedpt T5Scores[4];

				T5Scores[0] = P11();
				T5Scores[1] = P12();
				T5Scores[2] = P13();
				T5Scores[3] = P14();

				int best = bestProgram(T5Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[3] = { T4, T5, T2,  };

				fixedpt T6Scores[3];

				T6Scores[0] = P15();
				T6Scores[1] = P16();
				T6Scores[2] = P6();

				int best = bestProgram(T6Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T4, T2, T5,  };

				fixedpt T7Scores[3];

				T7Scores[0] = P17();
				T7Scores[1] = P18();
				T7Scores[2] = P16();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[5] = { T2, T3, T4, T5, T2,  };

				fixedpt T8Scores[5];

				T8Scores[0] = P19();
				T8Scores[1] = P20();
				T8Scores[2] = P21();
				T8Scores[3] = P22();
				T8Scores[4] = P6();

				int best = bestProgram(T8Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[3] = { T2, T4, T5,  };

				fixedpt T9Scores[3];

				T9Scores[0] = P19();
				T9Scores[1] = P23();
				T9Scores[2] = P16();

				int best = bestProgram(T9Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[5] = { T4, T7, A16, T2, T8,  };

				fixedpt T10Scores[5];

				T10Scores[0] = P23();
				T10Scores[1] = P24();
				T10Scores[2] = P25();
				T10Scores[3] = P26();
				T10Scores[4] = P27();

				int best = bestProgram(T10Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { T2, T4, T9,  };

				fixedpt T11Scores[3];

				T11Scores[0] = P28();
				T11Scores[1] = P23();
				T11Scores[2] = P29();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[4] = { T4, T2, T4, T9,  };

				fixedpt T12Scores[4];

				T12Scores[0] = P30();
				T12Scores[1] = P31();
				T12Scores[2] = P23();
				T12Scores[3] = P29();

				int best = bestProgram(T12Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[4] = { T4, T9, T11, T5,  };

				fixedpt T13Scores[4];

				T13Scores[0] = P30();
				T13Scores[1] = P29();
				T13Scores[2] = P32();
				T13Scores[3] = P33();

				int best = bestProgram(T13Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[2] = { T13, T12,  };

				fixedpt T14Scores[2];

				T14Scores[0] = P34();
				T14Scores[1] = P35();

				int best = bestProgram(T14Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[8] = { A18, T14, A16, T6, A20, T10, A20, A20,  };

				fixedpt T15Scores[8];

				T15Scores[0] = P36();
				T15Scores[1] = P37();
				T15Scores[2] = P38();
				T15Scores[3] = P39();
				T15Scores[4] = P40();
				T15Scores[5] = P41();
				T15Scores[6] = P42();
				T15Scores[7] = P43();

				int best = bestProgram(T15Scores, 8);
				currentVertex = next[best];
				break;
			}
		case A16: {
				actions[0] = 5;
				return;
			}
		case A17: {
				actions[0] = 6;
				return;
			}
		case A18: {
				actions[0] = 3;
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
				actions[0] = 8;
				return;
			}
		}
	}
}
