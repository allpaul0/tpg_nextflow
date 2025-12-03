/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:41
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
				const enum vertices next[1] = { A24,  };

				float T0Scores[1];

				T0Scores[0] = P0();

				int best = bestProgram(T0Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[1] = { A25,  };

				float T1Scores[1];

				T1Scores[0] = P1();

				int best = bestProgram(T1Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { A24, T1,  };

				float T2Scores[2];

				T2Scores[0] = P0();
				T2Scores[1] = P2();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { A26, T0, A25,  };

				float T3Scores[3];

				T3Scores[0] = P3();
				T3Scores[1] = P4();
				T3Scores[2] = P5();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[2] = { A23, A27,  };

				float T4Scores[2];

				T4Scores[0] = P6();
				T4Scores[1] = P7();

				int best = bestProgram(T4Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[3] = { T2, A26, T0,  };

				float T5Scores[3];

				T5Scores[0] = P8();
				T5Scores[1] = P9();
				T5Scores[2] = P10();

				int best = bestProgram(T5Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { T4, A23,  };

				float T6Scores[2];

				T6Scores[0] = P11();
				T6Scores[1] = P12();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[5] = { A23, A27, T4, A22, A26,  };

				float T7Scores[5];

				T7Scores[0] = P13();
				T7Scores[1] = P14();
				T7Scores[2] = P15();
				T7Scores[3] = P16();
				T7Scores[4] = P17();

				int best = bestProgram(T7Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { T5,  };

				float T8Scores[1];

				T8Scores[0] = P18();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[3] = { A25, A27, T4,  };

				float T9Scores[3];

				T9Scores[0] = P19();
				T9Scores[1] = P14();
				T9Scores[2] = P15();

				int best = bestProgram(T9Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[5] = { T6, A25, A27, T4, A22,  };

				float T10Scores[5];

				T10Scores[0] = P20();
				T10Scores[1] = P21();
				T10Scores[2] = P14();
				T10Scores[3] = P11();
				T10Scores[4] = P22();

				int best = bestProgram(T10Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[5] = { T7, T3, A28, A23, A27,  };

				float T11Scores[5];

				T11Scores[0] = P23();
				T11Scores[1] = P24();
				T11Scores[2] = P25();
				T11Scores[3] = P26();
				T11Scores[4] = P14();

				int best = bestProgram(T11Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[2] = { T10, T11,  };

				float T12Scores[2];

				T12Scores[0] = P27();
				T12Scores[1] = P28();

				int best = bestProgram(T12Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[7] = { T3, A28, T4, T7, A27, A23, T12,  };

				float T13Scores[7];

				T13Scores[0] = P29();
				T13Scores[1] = P30();
				T13Scores[2] = P31();
				T13Scores[3] = P32();
				T13Scores[4] = P33();
				T13Scores[5] = P34();
				T13Scores[6] = P35();

				int best = bestProgram(T13Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[2] = { T8, T12,  };

				float T14Scores[2];

				T14Scores[0] = P36();
				T14Scores[1] = P35();

				int best = bestProgram(T14Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[4] = { T10, T3, T14, T11,  };

				float T15Scores[4];

				T15Scores[0] = P37();
				T15Scores[1] = P29();
				T15Scores[2] = P38();
				T15Scores[3] = P28();

				int best = bestProgram(T15Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[5] = { A22, T15, T13, T9, T12,  };

				float T16Scores[5];

				T16Scores[0] = P39();
				T16Scores[1] = P40();
				T16Scores[2] = P41();
				T16Scores[3] = P42();
				T16Scores[4] = P35();

				int best = bestProgram(T16Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[5] = { T10, T15, T13, A22, T6,  };

				float T17Scores[5];

				T17Scores[0] = P27();
				T17Scores[1] = P43();
				T17Scores[2] = P44();
				T17Scores[3] = P45();
				T17Scores[4] = P46();

				int best = bestProgram(T17Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[3] = { T10, T15, T13,  };

				float T18Scores[3];

				T18Scores[0] = P47();
				T18Scores[1] = P43();
				T18Scores[2] = P44();

				int best = bestProgram(T18Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[4] = { A29, T17, T15, A22,  };

				float T19Scores[4];

				T19Scores[0] = P48();
				T19Scores[1] = P49();
				T19Scores[2] = P50();
				T19Scores[3] = P51();

				int best = bestProgram(T19Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[1] = { T18,  };

				float T20Scores[1];

				T20Scores[0] = P52();

				int best = bestProgram(T20Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[5] = { T20, T19, T16, T5, A29,  };

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
				actions[0] = 3;
				return;
			}
		case A25: {
				actions[0] = 4;
				return;
			}
		case A26: {
				actions[0] = 0;
				return;
			}
		case A27: {
				actions[0] = 7;
				return;
			}
		case A28: {
				actions[0] = 1;
				return;
			}
		case A29: {
				actions[0] = 2;
				return;
			}
		}
	}
}
