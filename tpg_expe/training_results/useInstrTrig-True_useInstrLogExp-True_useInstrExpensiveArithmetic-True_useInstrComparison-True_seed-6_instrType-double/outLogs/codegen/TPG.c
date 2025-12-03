/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:40
 * With the CodeGen::TPGGenerationEngine.
 */

#include "TPG.h"

int bestProgram(double *results, int nb) {
	int bestProgram = 0;
	double bestScore = (isnan(results[0]))? -INFINITY : results[0];
	for (int i = 1; i < nb; i++) {
		double challengerScore = (isnan(results[i]))? -INFINITY : results[i];
		if (challengerScore >= bestScore) {
			bestProgram = i;
			bestScore = challengerScore;
		}
	}
	return bestProgram;
}

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, A26, A27, A28, A29, A30, A31, A32, A33, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T25;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A26, A27,  };

				double T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[1] = { A26,  };

				double T1Scores[1];

				T1Scores[0] = P2();

				int best = bestProgram(T1Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[1] = { A29,  };

				double T2Scores[1];

				T2Scores[0] = P3();

				int best = bestProgram(T2Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { T2, A31,  };

				double T3Scores[2];

				T3Scores[0] = P4();
				T3Scores[1] = P5();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { A26, A30, A28,  };

				double T4Scores[3];

				T4Scores[0] = P6();
				T4Scores[1] = P7();
				T4Scores[2] = P8();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { T4, T0,  };

				double T5Scores[2];

				T5Scores[0] = P9();
				T5Scores[1] = P10();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { T4, A26,  };

				double T6Scores[2];

				T6Scores[0] = P11();
				T6Scores[1] = P12();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[4] = { T6, T0, A27, T1,  };

				double T7Scores[4];

				T7Scores[0] = P13();
				T7Scores[1] = P10();
				T7Scores[2] = P14();
				T7Scores[3] = P15();

				int best = bestProgram(T7Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { T6,  };

				double T8Scores[1];

				T8Scores[0] = P13();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[4] = { T4, T0, T0, A26,  };

				double T9Scores[4];

				T9Scores[0] = P16();
				T9Scores[1] = P17();
				T9Scores[2] = P18();
				T9Scores[3] = P19();

				int best = bestProgram(T9Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { T0, A32, T4,  };

				double T10Scores[3];

				T10Scores[0] = P10();
				T10Scores[1] = P20();
				T10Scores[2] = P21();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { T3, T9, T6,  };

				double T11Scores[3];

				T11Scores[0] = P22();
				T11Scores[1] = P23();
				T11Scores[2] = P24();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[2] = { A28, T4,  };

				double T12Scores[2];

				T12Scores[0] = P25();
				T12Scores[1] = P26();

				int best = bestProgram(T12Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[5] = { A33, T3, T4, A30, T5,  };

				double T13Scores[5];

				T13Scores[0] = P27();
				T13Scores[1] = P28();
				T13Scores[2] = P29();
				T13Scores[3] = P30();
				T13Scores[4] = P31();

				int best = bestProgram(T13Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[8] = { T3, T4, A33, A30, T5, A28, T10, A33,  };

				double T14Scores[8];

				T14Scores[0] = P28();
				T14Scores[1] = P29();
				T14Scores[2] = P32();
				T14Scores[3] = P33();
				T14Scores[4] = P34();
				T14Scores[5] = P35();
				T14Scores[6] = P36();
				T14Scores[7] = P37();

				int best = bestProgram(T14Scores, 8);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[1] = { T11,  };

				double T15Scores[1];

				T15Scores[0] = P38();

				int best = bestProgram(T15Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[2] = { T14, T11,  };

				double T16Scores[2];

				T16Scores[0] = P39();
				T16Scores[1] = P38();

				int best = bestProgram(T16Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[4] = { T14, T12, T11, T5,  };

				double T17Scores[4];

				T17Scores[0] = P40();
				T17Scores[1] = P41();
				T17Scores[2] = P42();
				T17Scores[3] = P43();

				int best = bestProgram(T17Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[3] = { T14, T16, T13,  };

				double T18Scores[3];

				T18Scores[0] = P44();
				T18Scores[1] = P45();
				T18Scores[2] = P46();

				int best = bestProgram(T18Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[2] = { T9, T18,  };

				double T19Scores[2];

				T19Scores[0] = P47();
				T19Scores[1] = P48();

				int best = bestProgram(T19Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[3] = { T17, T7, T5,  };

				double T20Scores[3];

				T20Scores[0] = P49();
				T20Scores[1] = P50();
				T20Scores[2] = P51();

				int best = bestProgram(T20Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[2] = { T9, T17,  };

				double T21Scores[2];

				T21Scores[0] = P52();
				T21Scores[1] = P53();

				int best = bestProgram(T21Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T22: {
				const enum vertices next[7] = { T19, T15, T7, T9, T8, T7, T17,  };

				double T22Scores[7];

				T22Scores[0] = P54();
				T22Scores[1] = P55();
				T22Scores[2] = P56();
				T22Scores[3] = P57();
				T22Scores[4] = P58();
				T22Scores[5] = P59();
				T22Scores[6] = P60();

				int best = bestProgram(T22Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T23: {
				const enum vertices next[3] = { T20, A30, T9,  };

				double T23Scores[3];

				T23Scores[0] = P61();
				T23Scores[1] = P62();
				T23Scores[2] = P47();

				int best = bestProgram(T23Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T24: {
				const enum vertices next[1] = { T14,  };

				double T24Scores[1];

				T24Scores[0] = P63();

				int best = bestProgram(T24Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T25: {
				const enum vertices next[6] = { A33, T21, T24, T5, T22, T23,  };

				double T25Scores[6];

				T25Scores[0] = P64();
				T25Scores[1] = P65();
				T25Scores[2] = P66();
				T25Scores[3] = P67();
				T25Scores[4] = P68();
				T25Scores[5] = P69();

				int best = bestProgram(T25Scores, 6);
				currentVertex = next[best];
				break;
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
				actions[0] = 4;
				return;
			}
		case A29: {
				actions[0] = 7;
				return;
			}
		case A30: {
				actions[0] = 0;
				return;
			}
		case A31: {
				actions[0] = 8;
				return;
			}
		case A32: {
				actions[0] = 2;
				return;
			}
		case A33: {
				actions[0] = 1;
				return;
			}
		}
	}
}
