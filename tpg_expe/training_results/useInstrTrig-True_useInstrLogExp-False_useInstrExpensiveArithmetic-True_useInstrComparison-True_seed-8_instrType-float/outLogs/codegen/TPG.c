/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:27
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, A23, A24, A25, A26, A27, A28, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T22;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A25, A26,  };

				float T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[5] = { A24, A24, A23, T0, A26,  };

				float T1Scores[5];

				T1Scores[0] = P2();
				T1Scores[1] = P3();
				T1Scores[2] = P4();
				T1Scores[3] = P5();
				T1Scores[4] = P6();

				int best = bestProgram(T1Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[1] = { A24,  };

				float T2Scores[1];

				T2Scores[0] = P7();

				int best = bestProgram(T2Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[5] = { A27, T2, T0, A24, A26,  };

				float T3Scores[5];

				T3Scores[0] = P8();
				T3Scores[1] = P9();
				T3Scores[2] = P5();
				T3Scores[3] = P10();
				T3Scores[4] = P11();

				int best = bestProgram(T3Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[4] = { T3, T1, A24, A23,  };

				float T4Scores[4];

				T4Scores[0] = P12();
				T4Scores[1] = P13();
				T4Scores[2] = P14();
				T4Scores[3] = P15();

				int best = bestProgram(T4Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { T1,  };

				float T5Scores[1];

				T5Scores[0] = P13();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[6] = { A27, A26, A24, A23, T0, A24,  };

				float T6Scores[6];

				T6Scores[0] = P8();
				T6Scores[1] = P16();
				T6Scores[2] = P17();
				T6Scores[3] = P18();
				T6Scores[4] = P5();
				T6Scores[5] = P19();

				int best = bestProgram(T6Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[1] = { T6,  };

				float T7Scores[1];

				T7Scores[0] = P20();

				int best = bestProgram(T7Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[4] = { A27, A26, A24, T0,  };

				float T8Scores[4];

				T8Scores[0] = P8();
				T8Scores[1] = P16();
				T8Scores[2] = P17();
				T8Scores[3] = P21();

				int best = bestProgram(T8Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[8] = { A27, T0, A26, A24, A24, T3, A23, T8,  };

				float T9Scores[8];

				T9Scores[0] = P22();
				T9Scores[1] = P23();
				T9Scores[2] = P16();
				T9Scores[3] = P17();
				T9Scores[4] = P24();
				T9Scores[5] = P25();
				T9Scores[6] = P26();
				T9Scores[7] = P27();

				int best = bestProgram(T9Scores, 8);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { T6, T9,  };

				float T10Scores[2];

				T10Scores[0] = P28();
				T10Scores[1] = P29();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[1] = { T7,  };

				float T11Scores[1];

				T11Scores[0] = P30();

				int best = bestProgram(T11Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[2] = { T10, T3,  };

				float T12Scores[2];

				T12Scores[0] = P31();
				T12Scores[1] = P32();

				int best = bestProgram(T12Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[1] = { T10,  };

				float T13Scores[1];

				T13Scores[0] = P33();

				int best = bestProgram(T13Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[1] = { T4,  };

				float T14Scores[1];

				T14Scores[0] = P34();

				int best = bestProgram(T14Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[5] = { T9, A27, T10, A28, T5,  };

				float T15Scores[5];

				T15Scores[0] = P35();
				T15Scores[1] = P36();
				T15Scores[2] = P31();
				T15Scores[3] = P37();
				T15Scores[4] = P38();

				int best = bestProgram(T15Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[3] = { T13, A27, T14,  };

				float T16Scores[3];

				T16Scores[0] = P39();
				T16Scores[1] = P40();
				T16Scores[2] = P41();

				int best = bestProgram(T16Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[4] = { T12, T15, T4, T7,  };

				float T17Scores[4];

				T17Scores[0] = P42();
				T17Scores[1] = P43();
				T17Scores[2] = P44();
				T17Scores[3] = P45();

				int best = bestProgram(T17Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[4] = { T17, T9, A28, T7,  };

				float T18Scores[4];

				T18Scores[0] = P46();
				T18Scores[1] = P47();
				T18Scores[2] = P48();
				T18Scores[3] = P49();

				int best = bestProgram(T18Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[3] = { T9, T11, T17,  };

				float T19Scores[3];

				T19Scores[0] = P50();
				T19Scores[1] = P51();
				T19Scores[2] = P46();

				int best = bestProgram(T19Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[2] = { T19, T17,  };

				float T20Scores[2];

				T20Scores[0] = P52();
				T20Scores[1] = P53();

				int best = bestProgram(T20Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[4] = { T17, T9, A27, T20,  };

				float T21Scores[4];

				T21Scores[0] = P46();
				T21Scores[1] = P50();
				T21Scores[2] = P54();
				T21Scores[3] = P55();

				int best = bestProgram(T21Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T22: {
				const enum vertices next[5] = { T16, T21, A27, T18, A27,  };

				float T22Scores[5];

				T22Scores[0] = P56();
				T22Scores[1] = P57();
				T22Scores[2] = P58();
				T22Scores[3] = P59();
				T22Scores[4] = P60();

				int best = bestProgram(T22Scores, 5);
				currentVertex = next[best];
				break;
			}
		case A23: {
				actions[0] = 5;
				return;
			}
		case A24: {
				actions[0] = 6;
				return;
			}
		case A25: {
				actions[0] = 0;
				return;
			}
		case A26: {
				actions[0] = 4;
				return;
			}
		case A27: {
				actions[0] = 1;
				return;
			}
		case A28: {
				actions[0] = 2;
				return;
			}
		}
	}
}
