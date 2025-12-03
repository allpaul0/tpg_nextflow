/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:38
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, A28, A29, A30, A31, A32, A33, A34, A35, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T27;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A28, A29,  };

				float T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A28, A29,  };

				float T1Scores[2];

				T1Scores[0] = P2();
				T1Scores[1] = P3();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { T1, A28,  };

				float T2Scores[2];

				T2Scores[0] = P4();
				T2Scores[1] = P5();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { A28, A31, A30,  };

				float T3Scores[3];

				T3Scores[0] = P6();
				T3Scores[1] = P7();
				T3Scores[2] = P8();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[2] = { T2, A29,  };

				float T4Scores[2];

				T4Scores[0] = P9();
				T4Scores[1] = P10();

				int best = bestProgram(T4Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { A32,  };

				float T5Scores[1];

				T5Scores[0] = P11();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[1] = { A33,  };

				float T6Scores[1];

				T6Scores[0] = P12();

				int best = bestProgram(T6Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[6] = { T4, T5, A28, A31, A30, T3,  };

				float T7Scores[6];

				T7Scores[0] = P13();
				T7Scores[1] = P14();
				T7Scores[2] = P5();
				T7Scores[3] = P15();
				T7Scores[4] = P16();
				T7Scores[5] = P17();

				int best = bestProgram(T7Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[4] = { T3, T5, T0, T4,  };

				float T8Scores[4];

				T8Scores[0] = P18();
				T8Scores[1] = P14();
				T8Scores[2] = P19();
				T8Scores[3] = P20();

				int best = bestProgram(T8Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[2] = { T7, A33,  };

				float T9Scores[2];

				T9Scores[0] = P21();
				T9Scores[1] = P12();

				int best = bestProgram(T9Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { T3, T7, A28,  };

				float T10Scores[3];

				T10Scores[0] = P18();
				T10Scores[1] = P21();
				T10Scores[2] = P5();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { T8, T7, A33,  };

				float T11Scores[3];

				T11Scores[0] = P22();
				T11Scores[1] = P21();
				T11Scores[2] = P12();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[3] = { T7, T9, A34,  };

				float T12Scores[3];

				T12Scores[0] = P23();
				T12Scores[1] = P24();
				T12Scores[2] = P25();

				int best = bestProgram(T12Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[4] = { T8, A33, T7, A34,  };

				float T13Scores[4];

				T13Scores[0] = P26();
				T13Scores[1] = P12();
				T13Scores[2] = P23();
				T13Scores[3] = P27();

				int best = bestProgram(T13Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[1] = { T12,  };

				float T14Scores[1];

				T14Scores[0] = P28();

				int best = bestProgram(T14Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[2] = { T7, T11,  };

				float T15Scores[2];

				T15Scores[0] = P29();
				T15Scores[1] = P30();

				int best = bestProgram(T15Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[3] = { T9, A34, T7,  };

				float T16Scores[3];

				T16Scores[0] = P31();
				T16Scores[1] = P25();
				T16Scores[2] = P21();

				int best = bestProgram(T16Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[6] = { T11, A34, T3, T6, T13, T7,  };

				float T17Scores[6];

				T17Scores[0] = P32();
				T17Scores[1] = P25();
				T17Scores[2] = P18();
				T17Scores[3] = P33();
				T17Scores[4] = P34();
				T17Scores[5] = P21();

				int best = bestProgram(T17Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[3] = { A34, T9, A33,  };

				float T18Scores[3];

				T18Scores[0] = P35();
				T18Scores[1] = P36();
				T18Scores[2] = P37();

				int best = bestProgram(T18Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[5] = { T15, T9, T10, A34, T17,  };

				float T19Scores[5];

				T19Scores[0] = P38();
				T19Scores[1] = P39();
				T19Scores[2] = P40();
				T19Scores[3] = P35();
				T19Scores[4] = P41();

				int best = bestProgram(T19Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[5] = { T7, T11, A34, T9, A28,  };

				float T20Scores[5];

				T20Scores[0] = P29();
				T20Scores[1] = P42();
				T20Scores[2] = P43();
				T20Scores[3] = P44();
				T20Scores[4] = P5();

				int best = bestProgram(T20Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[1] = { T19,  };

				float T21Scores[1];

				T21Scores[0] = P45();

				int best = bestProgram(T21Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T22: {
				const enum vertices next[7] = { T11, A35, T20, T6, T13, T9, A34,  };

				float T22Scores[7];

				T22Scores[0] = P46();
				T22Scores[1] = P47();
				T22Scores[2] = P48();
				T22Scores[3] = P33();
				T22Scores[4] = P34();
				T22Scores[5] = P49();
				T22Scores[6] = P50();

				int best = bestProgram(T22Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T23: {
				const enum vertices next[3] = { T22, T14, T21,  };

				float T23Scores[3];

				T23Scores[0] = P51();
				T23Scores[1] = P52();
				T23Scores[2] = P53();

				int best = bestProgram(T23Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T24: {
				const enum vertices next[2] = { T18, T16,  };

				float T24Scores[2];

				T24Scores[0] = P54();
				T24Scores[1] = P55();

				int best = bestProgram(T24Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T25: {
				const enum vertices next[1] = { T23,  };

				float T25Scores[1];

				T25Scores[0] = P56();

				int best = bestProgram(T25Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T26: {
				const enum vertices next[5] = { A30, A28, T25, T24, T23,  };

				float T26Scores[5];

				T26Scores[0] = P57();
				T26Scores[1] = P58();
				T26Scores[2] = P59();
				T26Scores[3] = P60();
				T26Scores[4] = P61();

				int best = bestProgram(T26Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T27: {
				const enum vertices next[6] = { T24, A35, T23, T26, T23, A30,  };

				float T27Scores[6];

				T27Scores[0] = P62();
				T27Scores[1] = P63();
				T27Scores[2] = P64();
				T27Scores[3] = P65();
				T27Scores[4] = P66();
				T27Scores[5] = P67();

				int best = bestProgram(T27Scores, 6);
				currentVertex = next[best];
				break;
			}
		case A28: {
				actions[0] = 5;
				return;
			}
		case A29: {
				actions[0] = 6;
				return;
			}
		case A30: {
				actions[0] = 4;
				return;
			}
		case A31: {
				actions[0] = 0;
				return;
			}
		case A32: {
				actions[0] = 8;
				return;
			}
		case A33: {
				actions[0] = 2;
				return;
			}
		case A34: {
				actions[0] = 1;
				return;
			}
		case A35: {
				actions[0] = 3;
				return;
			}
		}
	}
}
