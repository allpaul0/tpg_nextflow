/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:29
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, A24, A25, A26, A27, A28, A29, A30, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T23;
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
				const enum vertices next[3] = { A24, A28, A25,  };

				double T1Scores[3];

				T1Scores[0] = P2();
				T1Scores[1] = P3();
				T1Scores[2] = P4();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[5] = { A25, T0, A29, A28, T1,  };

				double T2Scores[5];

				T2Scores[0] = P5();
				T2Scores[1] = P6();
				T2Scores[2] = P7();
				T2Scores[3] = P8();
				T2Scores[4] = P9();

				int best = bestProgram(T2Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[5] = { A25, A29, A28, T1, A28,  };

				double T3Scores[5];

				T3Scores[0] = P10();
				T3Scores[1] = P11();
				T3Scores[2] = P12();
				T3Scores[3] = P13();
				T3Scores[4] = P14();

				int best = bestProgram(T3Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { T2, T0, A28,  };

				double T4Scores[3];

				T4Scores[0] = P15();
				T4Scores[1] = P16();
				T4Scores[2] = P17();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { T4,  };

				double T5Scores[1];

				T5Scores[0] = P18();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[1] = { T3,  };

				double T6Scores[1];

				T6Scores[0] = P19();

				int best = bestProgram(T6Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T5, A25, A28,  };

				double T7Scores[3];

				T7Scores[0] = P20();
				T7Scores[1] = P21();
				T7Scores[2] = P22();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[2] = { T5, T6,  };

				double T8Scores[2];

				T8Scores[0] = P23();
				T8Scores[1] = P24();

				int best = bestProgram(T8Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[3] = { T8, T5, A29,  };

				double T9Scores[3];

				T9Scores[0] = P25();
				T9Scores[1] = P23();
				T9Scores[2] = P26();

				int best = bestProgram(T9Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[7] = { T8, A29, T5, T1, A28, A27, A29,  };

				double T10Scores[7];

				T10Scores[0] = P27();
				T10Scores[1] = P28();
				T10Scores[2] = P23();
				T10Scores[3] = P29();
				T10Scores[4] = P30();
				T10Scores[5] = P31();
				T10Scores[6] = P32();

				int best = bestProgram(T10Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[1] = { T8,  };

				double T11Scores[1];

				T11Scores[0] = P33();

				int best = bestProgram(T11Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[3] = { T9, T1, T10,  };

				double T12Scores[3];

				T12Scores[0] = P34();
				T12Scores[1] = P35();
				T12Scores[2] = P36();

				int best = bestProgram(T12Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[4] = { T8, T7, T11, T5,  };

				double T13Scores[4];

				T13Scores[0] = P37();
				T13Scores[1] = P38();
				T13Scores[2] = P39();
				T13Scores[3] = P23();

				int best = bestProgram(T13Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[5] = { T5, T7, A28, T10, A29,  };

				double T14Scores[5];

				T14Scores[0] = P23();
				T14Scores[1] = P40();
				T14Scores[2] = P41();
				T14Scores[3] = P36();
				T14Scores[4] = P42();

				int best = bestProgram(T14Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[1] = { T14,  };

				double T15Scores[1];

				T15Scores[0] = P43();

				int best = bestProgram(T15Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[2] = { T14, T12,  };

				double T16Scores[2];

				T16Scores[0] = P44();
				T16Scores[1] = P45();

				int best = bestProgram(T16Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[2] = { T14, T13,  };

				double T17Scores[2];

				T17Scores[0] = P46();
				T17Scores[1] = P47();

				int best = bestProgram(T17Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[5] = { T10, T5, T16, A25, T15,  };

				double T18Scores[5];

				T18Scores[0] = P48();
				T18Scores[1] = P49();
				T18Scores[2] = P50();
				T18Scores[3] = P51();
				T18Scores[4] = P52();

				int best = bestProgram(T18Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[5] = { T17, T10, T18, T16, T7,  };

				double T19Scores[5];

				T19Scores[0] = P53();
				T19Scores[1] = P54();
				T19Scores[2] = P55();
				T19Scores[3] = P56();
				T19Scores[4] = P57();

				int best = bestProgram(T19Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[2] = { T19, T1,  };

				double T20Scores[2];

				T20Scores[0] = P58();
				T20Scores[1] = P59();

				int best = bestProgram(T20Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[5] = { T20, T18, T10, T5, T17,  };

				double T21Scores[5];

				T21Scores[0] = P60();
				T21Scores[1] = P61();
				T21Scores[2] = P36();
				T21Scores[3] = P49();
				T21Scores[4] = P62();

				int best = bestProgram(T21Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T22: {
				const enum vertices next[3] = { A30, T21, T8,  };

				double T22Scores[3];

				T22Scores[0] = P63();
				T22Scores[1] = P64();
				T22Scores[2] = P65();

				int best = bestProgram(T22Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T23: {
				const enum vertices next[3] = { A24, T22, T1,  };

				double T23Scores[3];

				T23Scores[0] = P66();
				T23Scores[1] = P67();
				T23Scores[2] = P68();

				int best = bestProgram(T23Scores, 3);
				currentVertex = next[best];
				break;
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
				actions[0] = 8;
				return;
			}
		case A27: {
				actions[0] = 0;
				return;
			}
		case A28: {
				actions[0] = 6;
				return;
			}
		case A29: {
				actions[0] = 5;
				return;
			}
		case A30: {
				actions[0] = 1;
				return;
			}
		}
	}
}
