/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:37
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
				const enum vertices next[1] = { A22,  };

				float T0Scores[1];

				T0Scores[0] = P0();

				int best = bestProgram(T0Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[6] = { A27, A23, A26, A26, A27, A22,  };

				float T1Scores[6];

				T1Scores[0] = P1();
				T1Scores[1] = P2();
				T1Scores[2] = P3();
				T1Scores[3] = P4();
				T1Scores[4] = P5();
				T1Scores[5] = P6();

				int best = bestProgram(T1Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[4] = { A24, A25, A26, A22,  };

				float T2Scores[4];

				T2Scores[0] = P7();
				T2Scores[1] = P8();
				T2Scores[2] = P9();
				T2Scores[3] = P10();

				int best = bestProgram(T2Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[4] = { A27, T0, T2, A26,  };

				float T3Scores[4];

				T3Scores[0] = P11();
				T3Scores[1] = P12();
				T3Scores[2] = P13();
				T3Scores[3] = P14();

				int best = bestProgram(T3Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { A26, T3, A26,  };

				float T4Scores[3];

				T4Scores[0] = P15();
				T4Scores[1] = P16();
				T4Scores[2] = P3();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { T1, T2,  };

				float T5Scores[2];

				T5Scores[0] = P17();
				T5Scores[1] = P18();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { T5, A22,  };

				float T6Scores[2];

				T6Scores[0] = P19();
				T6Scores[1] = P20();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[4] = { A26, A22, A25, T1,  };

				float T7Scores[4];

				T7Scores[0] = P21();
				T7Scores[1] = P22();
				T7Scores[2] = P23();
				T7Scores[3] = P24();

				int best = bestProgram(T7Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[2] = { T4, T6,  };

				float T8Scores[2];

				T8Scores[0] = P25();
				T8Scores[1] = P26();

				int best = bestProgram(T8Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[5] = { T8, A24, A22, T7, A26,  };

				float T9Scores[5];

				T9Scores[0] = P27();
				T9Scores[1] = P28();
				T9Scores[2] = P29();
				T9Scores[3] = P30();
				T9Scores[4] = P31();

				int best = bestProgram(T9Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { T9, A24,  };

				float T10Scores[2];

				T10Scores[0] = P32();
				T10Scores[1] = P33();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[1] = { T10,  };

				float T11Scores[1];

				T11Scores[0] = P34();

				int best = bestProgram(T11Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[1] = { T10,  };

				float T12Scores[1];

				T12Scores[0] = P34();

				int best = bestProgram(T12Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[2] = { T9, A25,  };

				float T13Scores[2];

				T13Scores[0] = P35();
				T13Scores[1] = P36();

				int best = bestProgram(T13Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[2] = { A29, T12,  };

				float T14Scores[2];

				T14Scores[0] = P37();
				T14Scores[1] = P38();

				int best = bestProgram(T14Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[1] = { T11,  };

				float T15Scores[1];

				T15Scores[0] = P39();

				int best = bestProgram(T15Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[3] = { T15, T12, T12,  };

				float T16Scores[3];

				T16Scores[0] = P40();
				T16Scores[1] = P41();
				T16Scores[2] = P42();

				int best = bestProgram(T16Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[1] = { T14,  };

				float T17Scores[1];

				T17Scores[0] = P43();

				int best = bestProgram(T17Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[3] = { T16, A26, T17,  };

				float T18Scores[3];

				T18Scores[0] = P44();
				T18Scores[1] = P45();
				T18Scores[2] = P46();

				int best = bestProgram(T18Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[3] = { T3, A26, T13,  };

				float T19Scores[3];

				T19Scores[0] = P47();
				T19Scores[1] = P48();
				T19Scores[2] = P49();

				int best = bestProgram(T19Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[2] = { T19, A26,  };

				float T20Scores[2];

				T20Scores[0] = P50();
				T20Scores[1] = P45();

				int best = bestProgram(T20Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[3] = { A28, T20, T18,  };

				float T21Scores[3];

				T21Scores[0] = P51();
				T21Scores[1] = P52();
				T21Scores[2] = P53();

				int best = bestProgram(T21Scores, 3);
				currentVertex = next[best];
				break;
			}
		case A22: {
				actions[0] = 6;
				return;
			}
		case A23: {
				actions[0] = 7;
				return;
			}
		case A24: {
				actions[0] = 8;
				return;
			}
		case A25: {
				actions[0] = 0;
				return;
			}
		case A26: {
				actions[0] = 5;
				return;
			}
		case A27: {
				actions[0] = 4;
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
