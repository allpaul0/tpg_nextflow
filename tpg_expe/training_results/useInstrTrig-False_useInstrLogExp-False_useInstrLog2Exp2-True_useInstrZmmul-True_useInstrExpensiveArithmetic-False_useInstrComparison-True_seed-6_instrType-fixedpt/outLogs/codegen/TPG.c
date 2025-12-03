/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:22
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, A18, A19, A20, A21, A22, A23, A24, };

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
				const enum vertices next[2] = { A19, A18,  };

				fixedpt T1Scores[2];

				T1Scores[0] = P1();
				T1Scores[1] = P2();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { T1, A23, A21,  };

				fixedpt T2Scores[3];

				T2Scores[0] = P3();
				T2Scores[1] = P4();
				T2Scores[2] = P5();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { A19, T1, T0,  };

				fixedpt T3Scores[3];

				T3Scores[0] = P6();
				T3Scores[1] = P7();
				T3Scores[2] = P8();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[5] = { T3, A20, A20, A23, A21,  };

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
				const enum vertices next[1] = { T1,  };

				fixedpt T5Scores[1];

				T5Scores[0] = P14();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[7] = { T5, A20, A19, A23, A21, A19, A21,  };

				fixedpt T6Scores[7];

				T6Scores[0] = P15();
				T6Scores[1] = P16();
				T6Scores[2] = P17();
				T6Scores[3] = P18();
				T6Scores[4] = P5();
				T6Scores[5] = P19();
				T6Scores[6] = P20();

				int best = bestProgram(T6Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T4, A20, T6,  };

				fixedpt T7Scores[3];

				T7Scores[0] = P21();
				T7Scores[1] = P22();
				T7Scores[2] = P23();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { T6,  };

				fixedpt T8Scores[1];

				T8Scores[0] = P23();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T8,  };

				fixedpt T9Scores[1];

				T9Scores[0] = P24();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { T7, A22, T4,  };

				fixedpt T10Scores[3];

				T10Scores[0] = P25();
				T10Scores[1] = P26();
				T10Scores[2] = P21();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { T9, T6, T7,  };

				fixedpt T11Scores[3];

				T11Scores[0] = P27();
				T11Scores[1] = P28();
				T11Scores[2] = P29();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[3] = { T11, T10, A22,  };

				fixedpt T12Scores[3];

				T12Scores[0] = P30();
				T12Scores[1] = P31();
				T12Scores[2] = P32();

				int best = bestProgram(T12Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[3] = { T11, T10, A22,  };

				fixedpt T13Scores[3];

				T13Scores[0] = P33();
				T13Scores[1] = P34();
				T13Scores[2] = P35();

				int best = bestProgram(T13Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[5] = { T12, T13, A22, T2, A24,  };

				fixedpt T14Scores[5];

				T14Scores[0] = P36();
				T14Scores[1] = P37();
				T14Scores[2] = P38();
				T14Scores[3] = P39();
				T14Scores[4] = P40();

				int best = bestProgram(T14Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[5] = { T14, A24, A22, A22, T12,  };

				fixedpt T15Scores[5];

				T15Scores[0] = P41();
				T15Scores[1] = P40();
				T15Scores[2] = P42();
				T15Scores[3] = P35();
				T15Scores[4] = P43();

				int best = bestProgram(T15Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[6] = { A22, T14, T14, A24, T15, A22,  };

				fixedpt T16Scores[6];

				T16Scores[0] = P35();
				T16Scores[1] = P44();
				T16Scores[2] = P41();
				T16Scores[3] = P40();
				T16Scores[4] = P45();
				T16Scores[5] = P46();

				int best = bestProgram(T16Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[4] = { A22, T16, T14, A24,  };

				fixedpt T17Scores[4];

				T17Scores[0] = P47();
				T17Scores[1] = P48();
				T17Scores[2] = P49();
				T17Scores[3] = P40();

				int best = bestProgram(T17Scores, 4);
				currentVertex = next[best];
				break;
			}
		case A18: {
				actions[0] = 7;
				return;
			}
		case A19: {
				actions[0] = 5;
				return;
			}
		case A20: {
				actions[0] = 6;
				return;
			}
		case A21: {
				actions[0] = 0;
				return;
			}
		case A22: {
				actions[0] = 2;
				return;
			}
		case A23: {
				actions[0] = 4;
				return;
			}
		case A24: {
				actions[0] = 1;
				return;
			}
		}
	}
}
