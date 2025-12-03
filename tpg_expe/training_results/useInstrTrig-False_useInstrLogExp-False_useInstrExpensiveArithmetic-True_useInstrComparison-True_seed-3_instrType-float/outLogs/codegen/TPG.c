/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:25
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, A22, A23, A24, A25, A26, A27, A28, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T21;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A22, A24,  };

				float T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[1] = { A23,  };

				float T1Scores[1];

				T1Scores[0] = P2();

				int best = bestProgram(T1Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { A25, A24,  };

				float T2Scores[2];

				T2Scores[0] = P3();
				T2Scores[1] = P4();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { T0, T1,  };

				float T3Scores[2];

				T3Scores[0] = P5();
				T3Scores[1] = P6();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[5] = { A24, A26, A27, A28, A26,  };

				float T4Scores[5];

				T4Scores[0] = P7();
				T4Scores[1] = P8();
				T4Scores[2] = P9();
				T4Scores[3] = P10();
				T4Scores[4] = P11();

				int best = bestProgram(T4Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { T2,  };

				float T5Scores[1];

				T5Scores[0] = P12();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[1] = { A24,  };

				float T6Scores[1];

				T6Scores[0] = P13();

				int best = bestProgram(T6Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[1] = { A27,  };

				float T7Scores[1];

				T7Scores[0] = P14();

				int best = bestProgram(T7Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { A23, T4, A28,  };

				float T8Scores[3];

				T8Scores[0] = P15();
				T8Scores[1] = P16();
				T8Scores[2] = P17();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[4] = { T7, A28, T6, T4,  };

				float T9Scores[4];

				T9Scores[0] = P18();
				T9Scores[1] = P19();
				T9Scores[2] = P20();
				T9Scores[3] = P21();

				int best = bestProgram(T9Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { T5, A27, T4,  };

				float T10Scores[3];

				T10Scores[0] = P22();
				T10Scores[1] = P23();
				T10Scores[2] = P24();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { A28, A24, T4,  };

				float T11Scores[3];

				T11Scores[0] = P25();
				T11Scores[1] = P26();
				T11Scores[2] = P27();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[3] = { A23, T9, T4,  };

				float T12Scores[3];

				T12Scores[0] = P28();
				T12Scores[1] = P29();
				T12Scores[2] = P30();

				int best = bestProgram(T12Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[4] = { T8, T9, A22, T12,  };

				float T13Scores[4];

				T13Scores[0] = P31();
				T13Scores[1] = P32();
				T13Scores[2] = P33();
				T13Scores[3] = P34();

				int best = bestProgram(T13Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[3] = { A22, T8, T9,  };

				float T14Scores[3];

				T14Scores[0] = P35();
				T14Scores[1] = P36();
				T14Scores[2] = P37();

				int best = bestProgram(T14Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[5] = { T8, T9, A22, T12, T8,  };

				float T15Scores[5];

				T15Scores[0] = P31();
				T15Scores[1] = P32();
				T15Scores[2] = P33();
				T15Scores[3] = P34();
				T15Scores[4] = P38();

				int best = bestProgram(T15Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[5] = { T9, T8, T13, T10, A28,  };

				float T16Scores[5];

				T16Scores[0] = P32();
				T16Scores[1] = P39();
				T16Scores[2] = P40();
				T16Scores[3] = P41();
				T16Scores[4] = P42();

				int best = bestProgram(T16Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[6] = { A25, T9, T8, T10, T15, T3,  };

				float T17Scores[6];

				T17Scores[0] = P43();
				T17Scores[1] = P32();
				T17Scores[2] = P44();
				T17Scores[3] = P45();
				T17Scores[4] = P46();
				T17Scores[5] = P47();

				int best = bestProgram(T17Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[2] = { T13, T17,  };

				float T18Scores[2];

				T18Scores[0] = P40();
				T18Scores[1] = P48();

				int best = bestProgram(T18Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[5] = { T13, T10, A24, T17, T9,  };

				float T19Scores[5];

				T19Scores[0] = P49();
				T19Scores[1] = P50();
				T19Scores[2] = P51();
				T19Scores[3] = P48();
				T19Scores[4] = P32();

				int best = bestProgram(T19Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[3] = { T11, T10, T19,  };

				float T20Scores[3];

				T20Scores[0] = P52();
				T20Scores[1] = P53();
				T20Scores[2] = P54();

				int best = bestProgram(T20Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[7] = { T11, T14, T16, T19, T10, T20, T18,  };

				float T21Scores[7];

				T21Scores[0] = P55();
				T21Scores[1] = P56();
				T21Scores[2] = P57();
				T21Scores[3] = P58();
				T21Scores[4] = P53();
				T21Scores[5] = P59();
				T21Scores[6] = P60();

				int best = bestProgram(T21Scores, 7);
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
				actions[0] = 7;
				return;
			}
		case A26: {
				actions[0] = 3;
				return;
			}
		case A27: {
				actions[0] = 0;
				return;
			}
		case A28: {
				actions[0] = 1;
				return;
			}
		}
	}
}
