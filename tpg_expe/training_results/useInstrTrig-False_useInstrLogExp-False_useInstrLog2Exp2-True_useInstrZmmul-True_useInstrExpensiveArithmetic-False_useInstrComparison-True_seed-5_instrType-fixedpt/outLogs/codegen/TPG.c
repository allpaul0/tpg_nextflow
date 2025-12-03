/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:23
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, A18, A19, A20, A21, A22, A23, };

void inferenceTPG(fixedpt* actions) {

	enum vertices currentVertex = T17;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[4] = { A18, A19, A20, A21,  };

				fixedpt T0Scores[4];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();
				T0Scores[3] = P3();

				int best = bestProgram(T0Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A23, A18, A20,  };

				fixedpt T1Scores[3];

				T1Scores[0] = P4();
				T1Scores[1] = P0();
				T1Scores[2] = P5();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A18, A19, A23,  };

				fixedpt T2Scores[3];

				T2Scores[0] = P0();
				T2Scores[1] = P6();
				T2Scores[2] = P7();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { A18, T1,  };

				fixedpt T3Scores[2];

				T3Scores[0] = P0();
				T3Scores[1] = P8();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[5] = { A19, A18, T0, A18, A20,  };

				fixedpt T4Scores[5];

				T4Scores[0] = P9();
				T4Scores[1] = P10();
				T4Scores[2] = P11();
				T4Scores[3] = P0();
				T4Scores[4] = P5();

				int best = bestProgram(T4Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[6] = { T2, A20, A18, A19, A18, T4,  };

				fixedpt T5Scores[6];

				T5Scores[0] = P12();
				T5Scores[1] = P13();
				T5Scores[2] = P14();
				T5Scores[3] = P15();
				T5Scores[4] = P0();
				T5Scores[5] = P16();

				int best = bestProgram(T5Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[5] = { A19, T2, A19, A23, T4,  };

				fixedpt T6Scores[5];

				T6Scores[0] = P17();
				T6Scores[1] = P12();
				T6Scores[2] = P18();
				T6Scores[3] = P19();
				T6Scores[4] = P16();

				int best = bestProgram(T6Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[6] = { T6, T4, T5, A20, A22, A19,  };

				fixedpt T7Scores[6];

				T7Scores[0] = P20();
				T7Scores[1] = P21();
				T7Scores[2] = P22();
				T7Scores[3] = P23();
				T7Scores[4] = P24();
				T7Scores[5] = P25();

				int best = bestProgram(T7Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[7] = { T2, T4, T1, T5, A20, T2, T6,  };

				fixedpt T8Scores[7];

				T8Scores[0] = P12();
				T8Scores[1] = P26();
				T8Scores[2] = P27();
				T8Scores[3] = P28();
				T8Scores[4] = P29();
				T8Scores[5] = P30();
				T8Scores[6] = P31();

				int best = bestProgram(T8Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[2] = { A23, T4,  };

				fixedpt T9Scores[2];

				T9Scores[0] = P19();
				T9Scores[1] = P26();

				int best = bestProgram(T9Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[4] = { A23, A22, A19, T3,  };

				fixedpt T10Scores[4];

				T10Scores[0] = P19();
				T10Scores[1] = P32();
				T10Scores[2] = P33();
				T10Scores[3] = P34();

				int best = bestProgram(T10Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[2] = { T9, T7,  };

				fixedpt T11Scores[2];

				T11Scores[0] = P35();
				T11Scores[1] = P36();

				int best = bestProgram(T11Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[3] = { T10, T7, T3,  };

				fixedpt T12Scores[3];

				T12Scores[0] = P37();
				T12Scores[1] = P38();
				T12Scores[2] = P39();

				int best = bestProgram(T12Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[2] = { T10, T11,  };

				fixedpt T13Scores[2];

				T13Scores[0] = P40();
				T13Scores[1] = P41();

				int best = bestProgram(T13Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[6] = { T12, T7, A20, A19, T7, T8,  };

				fixedpt T14Scores[6];

				T14Scores[0] = P42();
				T14Scores[1] = P43();
				T14Scores[2] = P44();
				T14Scores[3] = P45();
				T14Scores[4] = P46();
				T14Scores[5] = P47();

				int best = bestProgram(T14Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[5] = { T11, T8, T13, A20, A19,  };

				fixedpt T15Scores[5];

				T15Scores[0] = P41();
				T15Scores[1] = P48();
				T15Scores[2] = P49();
				T15Scores[3] = P44();
				T15Scores[4] = P50();

				int best = bestProgram(T15Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[1] = { T15,  };

				fixedpt T16Scores[1];

				T16Scores[0] = P51();

				int best = bestProgram(T16Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[3] = { T16, T14, A20,  };

				fixedpt T17Scores[3];

				T17Scores[0] = P52();
				T17Scores[1] = P53();
				T17Scores[2] = P44();

				int best = bestProgram(T17Scores, 3);
				currentVertex = next[best];
				break;
			}
		case A18: {
				actions[0] = 4;
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
				actions[0] = 1;
				return;
			}
		case A22: {
				actions[0] = 7;
				return;
			}
		case A23: {
				actions[0] = 0;
				return;
			}
		}
	}
}
