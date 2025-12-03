/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:26
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
				const enum vertices next[1] = { A23,  };

				float T0Scores[1];

				T0Scores[0] = P0();

				int best = bestProgram(T0Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A22, T0, A25,  };

				float T1Scores[3];

				T1Scores[0] = P1();
				T1Scores[1] = P2();
				T1Scores[2] = P3();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { T1, A26, A24,  };

				float T2Scores[3];

				T2Scores[0] = P4();
				T2Scores[1] = P5();
				T2Scores[2] = P6();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { T1, A26,  };

				float T3Scores[2];

				T3Scores[0] = P7();
				T3Scores[1] = P8();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[1] = { A26,  };

				float T4Scores[1];

				T4Scores[0] = P9();

				int best = bestProgram(T4Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[5] = { T1, A27, A26, T1, A24,  };

				float T5Scores[5];

				T5Scores[0] = P4();
				T5Scores[1] = P10();
				T5Scores[2] = P11();
				T5Scores[3] = P12();
				T5Scores[4] = P13();

				int best = bestProgram(T5Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[3] = { T2, T1, T1,  };

				float T6Scores[3];

				T6Scores[0] = P14();
				T6Scores[1] = P15();
				T6Scores[2] = P16();

				int best = bestProgram(T6Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T2, T1, T1,  };

				float T7Scores[3];

				T7Scores[0] = P17();
				T7Scores[1] = P16();
				T7Scores[2] = P18();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[4] = { T7, A24, A27, A27,  };

				float T8Scores[4];

				T8Scores[0] = P19();
				T8Scores[1] = P20();
				T8Scores[2] = P21();
				T8Scores[3] = P22();

				int best = bestProgram(T8Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[4] = { T5, T1, T1, T8,  };

				float T9Scores[4];

				T9Scores[0] = P23();
				T9Scores[1] = P24();
				T9Scores[2] = P25();
				T9Scores[3] = P26();

				int best = bestProgram(T9Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[5] = { T3, T1, T1, T8, A26,  };

				float T10Scores[5];

				T10Scores[0] = P27();
				T10Scores[1] = P16();
				T10Scores[2] = P28();
				T10Scores[3] = P29();
				T10Scores[4] = P30();

				int best = bestProgram(T10Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[4] = { T5, T4, T1, T8,  };

				float T11Scores[4];

				T11Scores[0] = P31();
				T11Scores[1] = P32();
				T11Scores[2] = P16();
				T11Scores[3] = P33();

				int best = bestProgram(T11Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[6] = { T5, T1, T8, A26, T10, A29,  };

				float T12Scores[6];

				T12Scores[0] = P23();
				T12Scores[1] = P16();
				T12Scores[2] = P34();
				T12Scores[3] = P35();
				T12Scores[4] = P36();
				T12Scores[5] = P37();

				int best = bestProgram(T12Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[3] = { A27, T8, T9,  };

				float T13Scores[3];

				T13Scores[0] = P38();
				T13Scores[1] = P39();
				T13Scores[2] = P40();

				int best = bestProgram(T13Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[2] = { T10, T12,  };

				float T14Scores[2];

				T14Scores[0] = P41();
				T14Scores[1] = P42();

				int best = bestProgram(T14Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[5] = { T13, A28, T9, T1, T1,  };

				float T15Scores[5];

				T15Scores[0] = P43();
				T15Scores[1] = P44();
				T15Scores[2] = P40();
				T15Scores[3] = P16();
				T15Scores[4] = P45();

				int best = bestProgram(T15Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[5] = { T15, T12, A27, A28, T1,  };

				float T16Scores[5];

				T16Scores[0] = P46();
				T16Scores[1] = P47();
				T16Scores[2] = P48();
				T16Scores[3] = P44();
				T16Scores[4] = P49();

				int best = bestProgram(T16Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[4] = { T12, A27, T14, T9,  };

				float T17Scores[4];

				T17Scores[0] = P47();
				T17Scores[1] = P48();
				T17Scores[2] = P50();
				T17Scores[3] = P51();

				int best = bestProgram(T17Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[2] = { T16, A29,  };

				float T18Scores[2];

				T18Scores[0] = P52();
				T18Scores[1] = P53();

				int best = bestProgram(T18Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[2] = { T18, T10,  };

				float T19Scores[2];

				T19Scores[0] = P54();
				T19Scores[1] = P55();

				int best = bestProgram(T19Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[3] = { T17, T19, T18,  };

				float T20Scores[3];

				T20Scores[0] = P56();
				T20Scores[1] = P57();
				T20Scores[2] = P58();

				int best = bestProgram(T20Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[7] = { A28, T11, T20, A24, A29, T6, T1,  };

				float T21Scores[7];

				T21Scores[0] = P59();
				T21Scores[1] = P60();
				T21Scores[2] = P61();
				T21Scores[3] = P62();
				T21Scores[4] = P63();
				T21Scores[5] = P64();
				T21Scores[6] = P65();

				int best = bestProgram(T21Scores, 7);
				currentVertex = next[best];
				break;
			}
		case A22: {
				actions[0] = 4;
				return;
			}
		case A23: {
				actions[0] = 0;
				return;
			}
		case A24: {
				actions[0] = 7;
				return;
			}
		case A25: {
				actions[0] = 8;
				return;
			}
		case A26: {
				actions[0] = 5;
				return;
			}
		case A27: {
				actions[0] = 6;
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
