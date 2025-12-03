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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, A18, A19, A20, A21, A22, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T17;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[3] = { A18, A19, A20,  };

				fixedpt T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[1] = { T0,  };

				fixedpt T1Scores[1];

				T1Scores[0] = P3();

				int best = bestProgram(T1Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { T1, A20,  };

				fixedpt T2Scores[2];

				T2Scores[0] = P4();
				T2Scores[1] = P5();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { T1, A21,  };

				fixedpt T3Scores[2];

				T3Scores[0] = P6();
				T3Scores[1] = P7();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[2] = { T2, T3,  };

				fixedpt T4Scores[2];

				T4Scores[0] = P8();
				T4Scores[1] = P9();

				int best = bestProgram(T4Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { T1, A22,  };

				fixedpt T5Scores[2];

				T5Scores[0] = P6();
				T5Scores[1] = P10();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { A18, T5,  };

				fixedpt T6Scores[2];

				T6Scores[0] = P11();
				T6Scores[1] = P12();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[2] = { T5, A20,  };

				fixedpt T7Scores[2];

				T7Scores[0] = P13();
				T7Scores[1] = P14();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[2] = { T6, A20,  };

				fixedpt T8Scores[2];

				T8Scores[0] = P15();
				T8Scores[1] = P16();

				int best = bestProgram(T8Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[7] = { A20, T1, A22, A20, T7, A19, T4,  };

				fixedpt T9Scores[7];

				T9Scores[0] = P17();
				T9Scores[1] = P18();
				T9Scores[2] = P19();
				T9Scores[3] = P20();
				T9Scores[4] = P21();
				T9Scores[5] = P22();
				T9Scores[6] = P23();

				int best = bestProgram(T9Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[1] = { T9,  };

				fixedpt T10Scores[1];

				T10Scores[0] = P24();

				int best = bestProgram(T10Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[4] = { T9, A22, T8, A20,  };

				fixedpt T11Scores[4];

				T11Scores[0] = P25();
				T11Scores[1] = P26();
				T11Scores[2] = P27();
				T11Scores[3] = P28();

				int best = bestProgram(T11Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[6] = { A20, T1, A20, A22, A19, T10,  };

				fixedpt T12Scores[6];

				T12Scores[0] = P29();
				T12Scores[1] = P18();
				T12Scores[2] = P30();
				T12Scores[3] = P19();
				T12Scores[4] = P31();
				T12Scores[5] = P32();

				int best = bestProgram(T12Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[4] = { T12, T11, A22, A20,  };

				fixedpt T13Scores[4];

				T13Scores[0] = P33();
				T13Scores[1] = P34();
				T13Scores[2] = P35();
				T13Scores[3] = P36();

				int best = bestProgram(T13Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[3] = { A20, A22, A18,  };

				fixedpt T14Scores[3];

				T14Scores[0] = P37();
				T14Scores[1] = P38();
				T14Scores[2] = P39();

				int best = bestProgram(T14Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[3] = { T13, A22, A21,  };

				fixedpt T15Scores[3];

				T15Scores[0] = P40();
				T15Scores[1] = P35();
				T15Scores[2] = P41();

				int best = bestProgram(T15Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[2] = { T14, T15,  };

				fixedpt T16Scores[2];

				T16Scores[0] = P42();
				T16Scores[1] = P43();

				int best = bestProgram(T16Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[3] = { T16, T15, T9,  };

				fixedpt T17Scores[3];

				T17Scores[0] = P44();
				T17Scores[1] = P45();
				T17Scores[2] = P46();

				int best = bestProgram(T17Scores, 3);
				currentVertex = next[best];
				break;
			}
		case A18: {
				actions[0] = 5;
				return;
			}
		case A19: {
				actions[0] = 6;
				return;
			}
		case A20: {
				actions[0] = 4;
				return;
			}
		case A21: {
				actions[0] = 0;
				return;
			}
		case A22: {
				actions[0] = 1;
				return;
			}
		}
	}
}
