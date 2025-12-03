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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, A18, A19, A20, A21, A22, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T17;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[1] = { A19,  };

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
				const enum vertices next[2] = { A20, A21,  };

				fixedpt T2Scores[2];

				T2Scores[0] = P3();
				T2Scores[1] = P4();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { A22, A21,  };

				fixedpt T3Scores[2];

				T3Scores[0] = P5();
				T3Scores[1] = P6();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[2] = { A19, A22,  };

				fixedpt T4Scores[2];

				T4Scores[0] = P0();
				T4Scores[1] = P5();

				int best = bestProgram(T4Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[3] = { T3, A21, T4,  };

				fixedpt T5Scores[3];

				T5Scores[0] = P7();
				T5Scores[1] = P8();
				T5Scores[2] = P9();

				int best = bestProgram(T5Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { T3, A19,  };

				fixedpt T6Scores[2];

				T6Scores[0] = P10();
				T6Scores[1] = P11();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { A18, A22, T5,  };

				fixedpt T7Scores[3];

				T7Scores[0] = P12();
				T7Scores[1] = P13();
				T7Scores[2] = P14();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[4] = { A18, T0, T6, A21,  };

				fixedpt T8Scores[4];

				T8Scores[0] = P15();
				T8Scores[1] = P16();
				T8Scores[2] = P17();
				T8Scores[3] = P18();

				int best = bestProgram(T8Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T8,  };

				fixedpt T9Scores[1];

				T9Scores[0] = P19();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { T9, T7, T8,  };

				fixedpt T10Scores[3];

				T10Scores[0] = P20();
				T10Scores[1] = P21();
				T10Scores[2] = P22();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { T9, T7, T4,  };

				fixedpt T11Scores[3];

				T11Scores[0] = P23();
				T11Scores[1] = P24();
				T11Scores[2] = P25();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[5] = { T7, T10, T4, A21, T2,  };

				fixedpt T12Scores[5];

				T12Scores[0] = P21();
				T12Scores[1] = P26();
				T12Scores[2] = P27();
				T12Scores[3] = P28();
				T12Scores[4] = P29();

				int best = bestProgram(T12Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[6] = { A20, T4, T12, T11, T1, T9,  };

				fixedpt T13Scores[6];

				T13Scores[0] = P30();
				T13Scores[1] = P31();
				T13Scores[2] = P32();
				T13Scores[3] = P33();
				T13Scores[4] = P34();
				T13Scores[5] = P20();

				int best = bestProgram(T13Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[2] = { T12, T4,  };

				fixedpt T14Scores[2];

				T14Scores[0] = P35();
				T14Scores[1] = P31();

				int best = bestProgram(T14Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[6] = { T4, T11, T4, T10, T12, A20,  };

				fixedpt T15Scores[6];

				T15Scores[0] = P36();
				T15Scores[1] = P37();
				T15Scores[2] = P38();
				T15Scores[3] = P39();
				T15Scores[4] = P35();
				T15Scores[5] = P40();

				int best = bestProgram(T15Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[5] = { A20, T13, T15, T10, T14,  };

				fixedpt T16Scores[5];

				T16Scores[0] = P41();
				T16Scores[1] = P42();
				T16Scores[2] = P43();
				T16Scores[3] = P44();
				T16Scores[4] = P45();

				int best = bestProgram(T16Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[2] = { T16, A20,  };

				fixedpt T17Scores[2];

				T17Scores[0] = P46();
				T17Scores[1] = P47();

				int best = bestProgram(T17Scores, 2);
				currentVertex = next[best];
				break;
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
				actions[0] = 5;
				return;
			}
		case A21: {
				actions[0] = 6;
				return;
			}
		case A22: {
				actions[0] = 0;
				return;
			}
		}
	}
}
