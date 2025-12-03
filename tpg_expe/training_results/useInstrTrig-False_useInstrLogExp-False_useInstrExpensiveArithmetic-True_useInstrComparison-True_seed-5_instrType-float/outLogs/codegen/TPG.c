/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:23
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, A24, A25, A26, A27, A28, A29, A30, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T23;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[1] = { A26,  };

				float T0Scores[1];

				T0Scores[0] = P0();

				int best = bestProgram(T0Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A25, A29,  };

				float T1Scores[2];

				T1Scores[0] = P1();
				T1Scores[1] = P2();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { A25, T0,  };

				float T2Scores[2];

				T2Scores[0] = P1();
				T2Scores[1] = P3();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { A26, A27, A28,  };

				float T3Scores[3];

				T3Scores[0] = P4();
				T3Scores[1] = P5();
				T3Scores[2] = P6();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[1] = { T1,  };

				float T4Scores[1];

				T4Scores[0] = P7();

				int best = bestProgram(T4Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[4] = { T2, A26, A24, A30,  };

				float T5Scores[4];

				T5Scores[0] = P8();
				T5Scores[1] = P9();
				T5Scores[2] = P10();
				T5Scores[3] = P11();

				int best = bestProgram(T5Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[4] = { T5, A28, A27, A29,  };

				float T6Scores[4];

				T6Scores[0] = P12();
				T6Scores[1] = P6();
				T6Scores[2] = P13();
				T6Scores[3] = P14();

				int best = bestProgram(T6Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T5, T4, T3,  };

				float T7Scores[3];

				T7Scores[0] = P12();
				T7Scores[1] = P15();
				T7Scores[2] = P16();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[4] = { T6, T5, A30, T6,  };

				float T8Scores[4];

				T8Scores[0] = P17();
				T8Scores[1] = P18();
				T8Scores[2] = P19();
				T8Scores[3] = P20();

				int best = bestProgram(T8Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { A24,  };

				float T9Scores[1];

				T9Scores[0] = P21();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[5] = { T7, T6, A30, T6, T6,  };

				float T10Scores[5];

				T10Scores[0] = P22();
				T10Scores[1] = P20();
				T10Scores[2] = P23();
				T10Scores[3] = P24();
				T10Scores[4] = P25();

				int best = bestProgram(T10Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[4] = { T7, T6, T6, T5,  };

				float T11Scores[4];

				T11Scores[0] = P22();
				T11Scores[1] = P26();
				T11Scores[2] = P27();
				T11Scores[3] = P12();

				int best = bestProgram(T11Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[1] = { A24,  };

				float T12Scores[1];

				T12Scores[0] = P28();

				int best = bestProgram(T12Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[1] = { T11,  };

				float T13Scores[1];

				T13Scores[0] = P29();

				int best = bestProgram(T13Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[2] = { T6, T12,  };

				float T14Scores[2];

				T14Scores[0] = P30();
				T14Scores[1] = P31();

				int best = bestProgram(T14Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[3] = { T10, T14, T5,  };

				float T15Scores[3];

				T15Scores[0] = P32();
				T15Scores[1] = P33();
				T15Scores[2] = P12();

				int best = bestProgram(T15Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[4] = { T6, T10, T8, T13,  };

				float T16Scores[4];

				T16Scores[0] = P34();
				T16Scores[1] = P32();
				T16Scores[2] = P35();
				T16Scores[3] = P36();

				int best = bestProgram(T16Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[4] = { T9, T15, T3, A30,  };

				float T17Scores[4];

				T17Scores[0] = P37();
				T17Scores[1] = P38();
				T17Scores[2] = P39();
				T17Scores[3] = P40();

				int best = bestProgram(T17Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[1] = { T16,  };

				float T18Scores[1];

				T18Scores[0] = P41();

				int best = bestProgram(T18Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[2] = { T16, A30,  };

				float T19Scores[2];

				T19Scores[0] = P42();
				T19Scores[1] = P43();

				int best = bestProgram(T19Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[2] = { T6, T10,  };

				float T20Scores[2];

				T20Scores[0] = P44();
				T20Scores[1] = P45();

				int best = bestProgram(T20Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[1] = { T20,  };

				float T21Scores[1];

				T21Scores[0] = P46();

				int best = bestProgram(T21Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T22: {
				const enum vertices next[3] = { T21, A30, T11,  };

				float T22Scores[3];

				T22Scores[0] = P47();
				T22Scores[1] = P48();
				T22Scores[2] = P49();

				int best = bestProgram(T22Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T23: {
				const enum vertices next[9] = { T6, T17, T18, T22, T6, T17, A30, A27, T19,  };

				float T23Scores[9];

				T23Scores[0] = P50();
				T23Scores[1] = P51();
				T23Scores[2] = P52();
				T23Scores[3] = P53();
				T23Scores[4] = P54();
				T23Scores[5] = P55();
				T23Scores[6] = P19();
				T23Scores[7] = P56();
				T23Scores[8] = P57();

				int best = bestProgram(T23Scores, 9);
				currentVertex = next[best];
				break;
			}
		case A24: {
				actions[0] = 5;
				return;
			}
		case A25: {
				actions[0] = 6;
				return;
			}
		case A26: {
				actions[0] = 4;
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
				actions[0] = 0;
				return;
			}
		case A30: {
				actions[0] = 1;
				return;
			}
		}
	}
}
