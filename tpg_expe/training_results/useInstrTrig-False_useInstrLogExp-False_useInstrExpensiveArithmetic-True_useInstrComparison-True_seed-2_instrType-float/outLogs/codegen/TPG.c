/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:29
 * With the CodeGen::TPGGenerationEngine.
 */

#include "TPG.h"

int bestProgram(float *results, int nb) {
	int bestProgram = 0;
	float bestScore = (isnan(results[0]))? -INFINITY : results[0];
	for (int i = 1; i < nb; i++) {
		float challengerScore = (isnan(results[i]))? -INFINITY : results[i];
		if (challengerScore >= bestScore) {
			bestProgram = i;
			bestScore = challengerScore;
		}
	}
	return bestProgram;
}

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, A19, A20, A21, A22, A23, A24, A25, A26, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T18;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[3] = { A19, A20, A21,  };

				float T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[4] = { A22, A24, A20, A19,  };

				float T1Scores[4];

				T1Scores[0] = P3();
				T1Scores[1] = P4();
				T1Scores[2] = P5();
				T1Scores[3] = P6();

				int best = bestProgram(T1Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[4] = { T0, A24, A20, A22,  };

				float T2Scores[4];

				T2Scores[0] = P7();
				T2Scores[1] = P8();
				T2Scores[2] = P5();
				T2Scores[3] = P9();

				int best = bestProgram(T2Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[5] = { A20, A25, A22, T0, T1,  };

				float T3Scores[5];

				T3Scores[0] = P1();
				T3Scores[1] = P10();
				T3Scores[2] = P11();
				T3Scores[3] = P12();
				T3Scores[4] = P13();

				int best = bestProgram(T3Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[4] = { A23, T1, T0, A22,  };

				float T4Scores[4];

				T4Scores[0] = P14();
				T4Scores[1] = P13();
				T4Scores[2] = P15();
				T4Scores[3] = P16();

				int best = bestProgram(T4Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { T3,  };

				float T5Scores[1];

				T5Scores[0] = P17();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[6] = { T2, T5, A19, A22, A21, T0,  };

				float T6Scores[6];

				T6Scores[0] = P18();
				T6Scores[1] = P19();
				T6Scores[2] = P20();
				T6Scores[3] = P21();
				T6Scores[4] = P22();
				T6Scores[5] = P23();

				int best = bestProgram(T6Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[1] = { A21,  };

				float T7Scores[1];

				T7Scores[0] = P24();

				int best = bestProgram(T7Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[5] = { T4, T5, T7, A20, T6,  };

				float T8Scores[5];

				T8Scores[0] = P25();
				T8Scores[1] = P26();
				T8Scores[2] = P27();
				T8Scores[3] = P28();
				T8Scores[4] = P29();

				int best = bestProgram(T8Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[4] = { T8, T6, T5, T6,  };

				float T9Scores[4];

				T9Scores[0] = P30();
				T9Scores[1] = P29();
				T9Scores[2] = P31();
				T9Scores[3] = P32();

				int best = bestProgram(T9Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[4] = { T6, A21, A20, T8,  };

				float T10Scores[4];

				T10Scores[0] = P33();
				T10Scores[1] = P34();
				T10Scores[2] = P35();
				T10Scores[3] = P36();

				int best = bestProgram(T10Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[1] = { T0,  };

				float T11Scores[1];

				T11Scores[0] = P37();

				int best = bestProgram(T11Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[4] = { T4, A21, T9, T8,  };

				float T12Scores[4];

				T12Scores[0] = P38();
				T12Scores[1] = P39();
				T12Scores[2] = P40();
				T12Scores[3] = P41();

				int best = bestProgram(T12Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[2] = { T6, T10,  };

				float T13Scores[2];

				T13Scores[0] = P42();
				T13Scores[1] = P43();

				int best = bestProgram(T13Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[3] = { T8, A25, A21,  };

				float T14Scores[3];

				T14Scores[0] = P44();
				T14Scores[1] = P45();
				T14Scores[2] = P46();

				int best = bestProgram(T14Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[5] = { T11, A21, T6, T8, T4,  };

				float T15Scores[5];

				T15Scores[0] = P47();
				T15Scores[1] = P46();
				T15Scores[2] = P48();
				T15Scores[3] = P49();
				T15Scores[4] = P38();

				int best = bestProgram(T15Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[5] = { T12, T15, T14, T8, T13,  };

				float T16Scores[5];

				T16Scores[0] = P50();
				T16Scores[1] = P51();
				T16Scores[2] = P52();
				T16Scores[3] = P53();
				T16Scores[4] = P54();

				int best = bestProgram(T16Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[2] = { T10, A26,  };

				float T17Scores[2];

				T17Scores[0] = P55();
				T17Scores[1] = P56();

				int best = bestProgram(T17Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[8] = { T8, T6, T6, T16, A26, A21, T17, T8,  };

				float T18Scores[8];

				T18Scores[0] = P57();
				T18Scores[1] = P58();
				T18Scores[2] = P59();
				T18Scores[3] = P60();
				T18Scores[4] = P61();
				T18Scores[5] = P46();
				T18Scores[6] = P62();
				T18Scores[7] = P63();

				int best = bestProgram(T18Scores, 8);
				currentVertex = next[best];
				break;
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
				actions[0] = 4;
				return;
			}
		case A22: {
				actions[0] = 0;
				return;
			}
		case A23: {
				actions[0] = 8;
				return;
			}
		case A24: {
				actions[0] = 3;
				return;
			}
		case A25: {
				actions[0] = 2;
				return;
			}
		case A26: {
				actions[0] = 1;
				return;
			}
		}
	}
}
