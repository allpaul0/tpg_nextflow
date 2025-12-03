/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:20
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
				const enum vertices next[2] = { A16, A17,  };

				fixedpt T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A16, A17,  };

				fixedpt T1Scores[2];

				T1Scores[0] = P2();
				T1Scores[1] = P3();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[1] = { A17,  };

				fixedpt T2Scores[1];

				T2Scores[0] = P4();

				int best = bestProgram(T2Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { T2, A19, A19,  };

				fixedpt T3Scores[3];

				T3Scores[0] = P5();
				T3Scores[1] = P6();
				T3Scores[2] = P7();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[5] = { A18, T0, A19, T0, A17,  };

				fixedpt T4Scores[5];

				T4Scores[0] = P8();
				T4Scores[1] = P9();
				T4Scores[2] = P10();
				T4Scores[3] = P11();
				T4Scores[4] = P12();

				int best = bestProgram(T4Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { T0,  };

				fixedpt T5Scores[1];

				T5Scores[0] = P13();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { T3, T4,  };

				fixedpt T6Scores[2];

				T6Scores[0] = P14();
				T6Scores[1] = P15();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[6] = { A20, A21, T4, T1, T0, T0,  };

				fixedpt T7Scores[6];

				T7Scores[0] = P16();
				T7Scores[1] = P17();
				T7Scores[2] = P15();
				T7Scores[3] = P18();
				T7Scores[4] = P19();
				T7Scores[5] = P20();

				int best = bestProgram(T7Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[5] = { A20, T0, T4, T3, T0,  };

				fixedpt T8Scores[5];

				T8Scores[0] = P21();
				T8Scores[1] = P22();
				T8Scores[2] = P15();
				T8Scores[3] = P23();
				T8Scores[4] = P24();

				int best = bestProgram(T8Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T8,  };

				fixedpt T9Scores[1];

				T9Scores[0] = P25();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[4] = { T9, T5, T7, A21,  };

				fixedpt T10Scores[4];

				T10Scores[0] = P26();
				T10Scores[1] = P27();
				T10Scores[2] = P28();
				T10Scores[3] = P29();

				int best = bestProgram(T10Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[1] = { T10,  };

				fixedpt T11Scores[1];

				T11Scores[0] = P30();

				int best = bestProgram(T11Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[6] = { T9, T5, T8, A21, T0, T7,  };

				fixedpt T12Scores[6];

				T12Scores[0] = P26();
				T12Scores[1] = P31();
				T12Scores[2] = P32();
				T12Scores[3] = P33();
				T12Scores[4] = P34();
				T12Scores[5] = P28();

				int best = bestProgram(T12Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[2] = { T7, T12,  };

				fixedpt T13Scores[2];

				T13Scores[0] = P35();
				T13Scores[1] = P36();

				int best = bestProgram(T13Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[3] = { T7, T13, T6,  };

				fixedpt T14Scores[3];

				T14Scores[0] = P37();
				T14Scores[1] = P38();
				T14Scores[2] = P39();

				int best = bestProgram(T14Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[3] = { T11, T14, T8,  };

				fixedpt T15Scores[3];

				T15Scores[0] = P40();
				T15Scores[1] = P41();
				T15Scores[2] = P42();

				int best = bestProgram(T15Scores, 3);
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
