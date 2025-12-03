/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:32
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, A23, A24, A25, A26, A27, A28, A29, A30, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T22;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A23, A24,  };

				float T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A25, A23, A26,  };

				float T1Scores[3];

				T1Scores[0] = P2();
				T1Scores[1] = P3();
				T1Scores[2] = P4();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[4] = { A23, A25, A27, A24,  };

				float T2Scores[4];

				T2Scores[0] = P5();
				T2Scores[1] = P6();
				T2Scores[2] = P7();
				T2Scores[3] = P8();

				int best = bestProgram(T2Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { T1, A26,  };

				float T3Scores[2];

				T3Scores[0] = P9();
				T3Scores[1] = P10();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[2] = { T2, A28,  };

				float T4Scores[2];

				T4Scores[0] = P11();
				T4Scores[1] = P12();

				int best = bestProgram(T4Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[4] = { A24, A29, A25, T0,  };

				float T5Scores[4];

				T5Scores[0] = P1();
				T5Scores[1] = P13();
				T5Scores[2] = P14();
				T5Scores[3] = P15();

				int best = bestProgram(T5Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[5] = { A26, T2, T0, A25, A23,  };

				float T6Scores[5];

				T6Scores[0] = P16();
				T6Scores[1] = P17();
				T6Scores[2] = P18();
				T6Scores[3] = P19();
				T6Scores[4] = P0();

				int best = bestProgram(T6Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[4] = { T1, A25, A26, A28,  };

				float T7Scores[4];

				T7Scores[0] = P9();
				T7Scores[1] = P20();
				T7Scores[2] = P21();
				T7Scores[3] = P22();

				int best = bestProgram(T7Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { T4, T6, T2,  };

				float T8Scores[3];

				T8Scores[0] = P23();
				T8Scores[1] = P24();
				T8Scores[2] = P25();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T5,  };

				float T9Scores[1];

				T9Scores[0] = P26();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[7] = { A24, A26, T2, A25, A23, T2, T7,  };

				float T10Scores[7];

				T10Scores[0] = P27();
				T10Scores[1] = P28();
				T10Scores[2] = P25();
				T10Scores[3] = P29();
				T10Scores[4] = P0();
				T10Scores[5] = P30();
				T10Scores[6] = P31();

				int best = bestProgram(T10Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { T9, T4, T8,  };

				float T11Scores[3];

				T11Scores[0] = P32();
				T11Scores[1] = P33();
				T11Scores[2] = P34();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[1] = { T10,  };

				float T12Scores[1];

				T12Scores[0] = P35();

				int best = bestProgram(T12Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[5] = { A29, T8, T10, T0, T3,  };

				float T13Scores[5];

				T13Scores[0] = P36();
				T13Scores[1] = P37();
				T13Scores[2] = P38();
				T13Scores[3] = P39();
				T13Scores[4] = P40();

				int best = bestProgram(T13Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[6] = { T8, T0, T10, T0, T11, T8,  };

				float T14Scores[6];

				T14Scores[0] = P37();
				T14Scores[1] = P41();
				T14Scores[2] = P35();
				T14Scores[3] = P42();
				T14Scores[4] = P43();
				T14Scores[5] = P44();

				int best = bestProgram(T14Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[1] = { T13,  };

				float T15Scores[1];

				T15Scores[0] = P45();

				int best = bestProgram(T15Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[1] = { A30,  };

				float T16Scores[1];

				T16Scores[0] = P46();

				int best = bestProgram(T16Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[2] = { T14, T2,  };

				float T17Scores[2];

				T17Scores[0] = P47();
				T17Scores[1] = P48();

				int best = bestProgram(T17Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[2] = { T14, T16,  };

				float T18Scores[2];

				T18Scores[0] = P49();
				T18Scores[1] = P50();

				int best = bestProgram(T18Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[6] = { T10, T8, T15, T17, T0, T12,  };

				float T19Scores[6];

				T19Scores[0] = P51();
				T19Scores[1] = P52();
				T19Scores[2] = P53();
				T19Scores[3] = P54();
				T19Scores[4] = P55();
				T19Scores[5] = P56();

				int best = bestProgram(T19Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[4] = { A29, T14, T10, T17,  };

				float T20Scores[4];

				T20Scores[0] = P57();
				T20Scores[1] = P58();
				T20Scores[2] = P59();
				T20Scores[3] = P54();

				int best = bestProgram(T20Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[8] = { T4, T17, A29, T20, T10, T14, T10, A24,  };

				float T21Scores[8];

				T21Scores[0] = P60();
				T21Scores[1] = P61();
				T21Scores[2] = P57();
				T21Scores[3] = P62();
				T21Scores[4] = P35();
				T21Scores[5] = P63();
				T21Scores[6] = P64();
				T21Scores[7] = P65();

				int best = bestProgram(T21Scores, 8);
				currentVertex = next[best];
				break;
			}
		case T22: {
				const enum vertices next[8] = { T20, T19, T20, T21, T10, T10, T18, T19,  };

				float T22Scores[8];

				T22Scores[0] = P66();
				T22Scores[1] = P67();
				T22Scores[2] = P68();
				T22Scores[3] = P69();
				T22Scores[4] = P35();
				T22Scores[5] = P70();
				T22Scores[6] = P71();
				T22Scores[7] = P72();

				int best = bestProgram(T22Scores, 8);
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
				actions[0] = 4;
				return;
			}
		case A26: {
				actions[0] = 7;
				return;
			}
		case A27: {
				actions[0] = 0;
				return;
			}
		case A28: {
				actions[0] = 8;
				return;
			}
		case A29: {
				actions[0] = 1;
				return;
			}
		case A30: {
				actions[0] = 2;
				return;
			}
		}
	}
}
