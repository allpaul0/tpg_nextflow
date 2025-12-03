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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, A25, A26, A27, A28, A29, A30, A31, A32, A33, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T24;
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
				const enum vertices next[3] = { A25, A26, A27,  };

				float T1Scores[3];

				T1Scores[0] = P2();
				T1Scores[1] = P1();
				T1Scores[2] = P3();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A29, A30, T0,  };

				float T2Scores[3];

				T2Scores[0] = P4();
				T2Scores[1] = P5();
				T2Scores[2] = P6();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[1] = { T2,  };

				float T3Scores[1];

				T3Scores[0] = P7();

				int best = bestProgram(T3Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[5] = { A26, A31, A30, A25, A27,  };

				float T4Scores[5];

				T4Scores[0] = P8();
				T4Scores[1] = P9();
				T4Scores[2] = P10();
				T4Scores[3] = P11();
				T4Scores[4] = P3();

				int best = bestProgram(T4Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { A31, T2,  };

				float T5Scores[2];

				T5Scores[0] = P12();
				T5Scores[1] = P13();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[3] = { T5, T1, T4,  };

				float T6Scores[3];

				T6Scores[0] = P14();
				T6Scores[1] = P15();
				T6Scores[2] = P16();

				int best = bestProgram(T6Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[1] = { T4,  };

				float T7Scores[1];

				T7Scores[0] = P16();

				int best = bestProgram(T7Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { A32, A31, T4,  };

				float T8Scores[3];

				T8Scores[0] = P17();
				T8Scores[1] = P12();
				T8Scores[2] = P16();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[5] = { T1, T2, T1, T3, A26,  };

				float T9Scores[5];

				T9Scores[0] = P18();
				T9Scores[1] = P13();
				T9Scores[2] = P19();
				T9Scores[3] = P20();
				T9Scores[4] = P21();

				int best = bestProgram(T9Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[1] = { T6,  };

				float T10Scores[1];

				T10Scores[0] = P22();

				int best = bestProgram(T10Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[4] = { T2, T1, A26, T10,  };

				float T11Scores[4];

				T11Scores[0] = P23();
				T11Scores[1] = P24();
				T11Scores[2] = P21();
				T11Scores[3] = P25();

				int best = bestProgram(T11Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[3] = { T11, T9, T10,  };

				float T12Scores[3];

				T12Scores[0] = P26();
				T12Scores[1] = P27();
				T12Scores[2] = P25();

				int best = bestProgram(T12Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[6] = { T5, T8, T6, A27, T1, T1,  };

				float T13Scores[6];

				T13Scores[0] = P28();
				T13Scores[1] = P29();
				T13Scores[2] = P30();
				T13Scores[3] = P31();
				T13Scores[4] = P32();
				T13Scores[5] = P33();

				int best = bestProgram(T13Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[4] = { T10, T8, A29, T9,  };

				float T14Scores[4];

				T14Scores[0] = P34();
				T14Scores[1] = P35();
				T14Scores[2] = P36();
				T14Scores[3] = P37();

				int best = bestProgram(T14Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[4] = { A33, T12, T1, T9,  };

				float T15Scores[4];

				T15Scores[0] = P38();
				T15Scores[1] = P39();
				T15Scores[2] = P40();
				T15Scores[3] = P41();

				int best = bestProgram(T15Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[6] = { T8, T10, T15, T9, T13, T14,  };

				float T16Scores[6];

				T16Scores[0] = P42();
				T16Scores[1] = P43();
				T16Scores[2] = P44();
				T16Scores[3] = P45();
				T16Scores[4] = P46();
				T16Scores[5] = P47();

				int best = bestProgram(T16Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[4] = { T9, T9, T13, T14,  };

				float T17Scores[4];

				T17Scores[0] = P48();
				T17Scores[1] = P49();
				T17Scores[2] = P50();
				T17Scores[3] = P47();

				int best = bestProgram(T17Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[3] = { T13, T4, T7,  };

				float T18Scores[3];

				T18Scores[0] = P50();
				T18Scores[1] = P51();
				T18Scores[2] = P52();

				int best = bestProgram(T18Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[2] = { T13, T17,  };

				float T19Scores[2];

				T19Scores[0] = P50();
				T19Scores[1] = P53();

				int best = bestProgram(T19Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[6] = { T13, A27, T16, T8, A31, T18,  };

				float T20Scores[6];

				T20Scores[0] = P54();
				T20Scores[1] = P55();
				T20Scores[2] = P56();
				T20Scores[3] = P57();
				T20Scores[4] = P12();
				T20Scores[5] = P58();

				int best = bestProgram(T20Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[10] = { T13, T18, A29, T13, T16, A28, A31, A27, A26, T13,  };

				float T21Scores[10];

				T21Scores[0] = P50();
				T21Scores[1] = P58();
				T21Scores[2] = P59();
				T21Scores[3] = P54();
				T21Scores[4] = P60();
				T21Scores[5] = P61();
				T21Scores[6] = P9();
				T21Scores[7] = P62();
				T21Scores[8] = P21();
				T21Scores[9] = P63();

				int best = bestProgram(T21Scores, 10);
				currentVertex = next[best];
				break;
			}
		case T22: {
				const enum vertices next[5] = { A33, T20, A31, T16, T19,  };

				float T22Scores[5];

				T22Scores[0] = P64();
				T22Scores[1] = P65();
				T22Scores[2] = P9();
				T22Scores[3] = P66();
				T22Scores[4] = P67();

				int best = bestProgram(T22Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T23: {
				const enum vertices next[2] = { T22, A32,  };

				float T23Scores[2];

				T23Scores[0] = P68();
				T23Scores[1] = P69();

				int best = bestProgram(T23Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T24: {
				const enum vertices next[4] = { T21, T16, A31, T23,  };

				float T24Scores[4];

				T24Scores[0] = P70();
				T24Scores[1] = P71();
				T24Scores[2] = P12();
				T24Scores[3] = P72();

				int best = bestProgram(T24Scores, 4);
				currentVertex = next[best];
				break;
			}
		case A25: {
				actions[0] = 3;
				return;
			}
		case A26: {
				actions[0] = 4;
				return;
			}
		case A27: {
				actions[0] = 6;
				return;
			}
		case A28: {
				actions[0] = 8;
				return;
			}
		case A29: {
				actions[0] = 5;
				return;
			}
		case A30: {
				actions[0] = 0;
				return;
			}
		case A31: {
				actions[0] = 2;
				return;
			}
		case A32: {
				actions[0] = 7;
				return;
			}
		case A33: {
				actions[0] = 1;
				return;
			}
		}
	}
}
