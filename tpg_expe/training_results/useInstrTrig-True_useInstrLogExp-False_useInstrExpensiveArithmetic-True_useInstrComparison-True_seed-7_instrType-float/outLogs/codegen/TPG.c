/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:28
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, A22, A23, A24, A25, A26, A27, A28, A29, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T21;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[4] = { A22, A23, A24, A26,  };

				float T0Scores[4];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();
				T0Scores[3] = P3();

				int best = bestProgram(T0Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[1] = { A22,  };

				float T1Scores[1];

				T1Scores[0] = P4();

				int best = bestProgram(T1Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { A24, A23,  };

				float T2Scores[2];

				T2Scores[0] = P5();
				T2Scores[1] = P6();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { A24, A25, A23,  };

				float T3Scores[3];

				T3Scores[0] = P5();
				T3Scores[1] = P7();
				T3Scores[2] = P8();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[1] = { A23,  };

				float T4Scores[1];

				T4Scores[0] = P9();

				int best = bestProgram(T4Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[5] = { A25, A23, A24, T2, T0,  };

				float T5Scores[5];

				T5Scores[0] = P7();
				T5Scores[1] = P8();
				T5Scores[2] = P5();
				T5Scores[3] = P10();
				T5Scores[4] = P11();

				int best = bestProgram(T5Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[4] = { A25, A23, A24, A23,  };

				float T6Scores[4];

				T6Scores[0] = P7();
				T6Scores[1] = P12();
				T6Scores[2] = P5();
				T6Scores[3] = P8();

				int best = bestProgram(T6Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T5, T0, A25,  };

				float T7Scores[3];

				T7Scores[0] = P13();
				T7Scores[1] = P11();
				T7Scores[2] = P14();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[2] = { T3, A23,  };

				float T8Scores[2];

				T8Scores[0] = P15();
				T8Scores[1] = P16();

				int best = bestProgram(T8Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { A28,  };

				float T9Scores[1];

				T9Scores[0] = P17();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[1] = { T7,  };

				float T10Scores[1];

				T10Scores[0] = P18();

				int best = bestProgram(T10Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[1] = { T8,  };

				float T11Scores[1];

				T11Scores[0] = P19();

				int best = bestProgram(T11Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[3] = { A29, A25, T4,  };

				float T12Scores[3];

				T12Scores[0] = P20();
				T12Scores[1] = P7();
				T12Scores[2] = P21();

				int best = bestProgram(T12Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[1] = { A24,  };

				float T13Scores[1];

				T13Scores[0] = P22();

				int best = bestProgram(T13Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[4] = { T9, T1, A25, T0,  };

				float T14Scores[4];

				T14Scores[0] = P23();
				T14Scores[1] = P24();
				T14Scores[2] = P7();
				T14Scores[3] = P25();

				int best = bestProgram(T14Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[2] = { T11, T14,  };

				float T15Scores[2];

				T15Scores[0] = P26();
				T15Scores[1] = P27();

				int best = bestProgram(T15Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[6] = { T10, T0, A25, T14, T11, T12,  };

				float T16Scores[6];

				T16Scores[0] = P28();
				T16Scores[1] = P11();
				T16Scores[2] = P7();
				T16Scores[3] = P29();
				T16Scores[4] = P30();
				T16Scores[5] = P31();

				int best = bestProgram(T16Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[6] = { T16, A29, A27, A25, T13, T13,  };

				float T17Scores[6];

				T17Scores[0] = P32();
				T17Scores[1] = P33();
				T17Scores[2] = P34();
				T17Scores[3] = P35();
				T17Scores[4] = P36();
				T17Scores[5] = P37();

				int best = bestProgram(T17Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[6] = { T14, A29, T5, T17, A25, T16,  };

				float T18Scores[6];

				T18Scores[0] = P38();
				T18Scores[1] = P39();
				T18Scores[2] = P40();
				T18Scores[3] = P41();
				T18Scores[4] = P42();
				T18Scores[5] = P43();

				int best = bestProgram(T18Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[7] = { T16, T5, T17, A25, T15, T15, A29,  };

				float T19Scores[7];

				T19Scores[0] = P44();
				T19Scores[1] = P40();
				T19Scores[2] = P45();
				T19Scores[3] = P42();
				T19Scores[4] = P46();
				T19Scores[5] = P47();
				T19Scores[6] = P39();

				int best = bestProgram(T19Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[5] = { T18, T15, T16, T6, A29,  };

				float T20Scores[5];

				T20Scores[0] = P48();
				T20Scores[1] = P49();
				T20Scores[2] = P50();
				T20Scores[3] = P51();
				T20Scores[4] = P52();

				int best = bestProgram(T20Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[5] = { T20, T16, T19, A28, T18,  };

				float T21Scores[5];

				T21Scores[0] = P53();
				T21Scores[1] = P54();
				T21Scores[2] = P55();
				T21Scores[3] = P56();
				T21Scores[4] = P57();

				int best = bestProgram(T21Scores, 5);
				currentVertex = next[best];
				break;
			}
		case A22: {
				actions[0] = 5;
				return;
			}
		case A23: {
				actions[0] = 6;
				return;
			}
		case A24: {
				actions[0] = 4;
				return;
			}
		case A25: {
				actions[0] = 0;
				return;
			}
		case A26: {
				actions[0] = 3;
				return;
			}
		case A27: {
				actions[0] = 7;
				return;
			}
		case A28: {
				actions[0] = 2;
				return;
			}
		case A29: {
				actions[0] = 1;
				return;
			}
		}
	}
}
