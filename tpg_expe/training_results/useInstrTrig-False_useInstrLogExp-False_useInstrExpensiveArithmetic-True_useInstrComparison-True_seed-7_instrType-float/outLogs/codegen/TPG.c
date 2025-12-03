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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, A20, A21, A22, A23, A24, A25, A26, A27, A28, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T19;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A22, A23,  };

				float T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A20, A25, A21,  };

				float T1Scores[3];

				T1Scores[0] = P2();
				T1Scores[1] = P3();
				T1Scores[2] = P4();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[4] = { T1, A21, A25, A24,  };

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
				const enum vertices next[1] = { T0,  };

				float T3Scores[1];

				T3Scores[0] = P9();

				int best = bestProgram(T3Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[4] = { A21, A25, T0, A24,  };

				float T4Scores[4];

				T4Scores[0] = P10();
				T4Scores[1] = P11();
				T4Scores[2] = P12();
				T4Scores[3] = P13();

				int best = bestProgram(T4Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { T0,  };

				float T5Scores[1];

				T5Scores[0] = P14();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[1] = { T3,  };

				float T6Scores[1];

				T6Scores[0] = P15();

				int best = bestProgram(T6Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[4] = { A25, T0, T4, A24,  };

				float T7Scores[4];

				T7Scores[0] = P16();
				T7Scores[1] = P17();
				T7Scores[2] = P18();
				T7Scores[3] = P8();

				int best = bestProgram(T7Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { T2,  };

				float T8Scores[1];

				T8Scores[0] = P19();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { A25,  };

				float T9Scores[1];

				T9Scores[0] = P3();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[9] = { T0, T5, A25, T2, A25, T0, A24, A23, A24,  };

				float T10Scores[9];

				T10Scores[0] = P20();
				T10Scores[1] = P21();
				T10Scores[2] = P22();
				T10Scores[3] = P19();
				T10Scores[4] = P3();
				T10Scores[5] = P23();
				T10Scores[6] = P24();
				T10Scores[7] = P25();
				T10Scores[8] = P26();

				int best = bestProgram(T10Scores, 9);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[4] = { A24, T2, A25, T0,  };

				float T11Scores[4];

				T11Scores[0] = P27();
				T11Scores[1] = P19();
				T11Scores[2] = P28();
				T11Scores[3] = P29();

				int best = bestProgram(T11Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[8] = { T0, T6, A25, T0, A25, A21, T10, T9,  };

				float T12Scores[8];

				T12Scores[0] = P30();
				T12Scores[1] = P31();
				T12Scores[2] = P32();
				T12Scores[3] = P33();
				T12Scores[4] = P34();
				T12Scores[5] = P35();
				T12Scores[6] = P36();
				T12Scores[7] = P37();

				int best = bestProgram(T12Scores, 8);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[1] = { T12,  };

				float T13Scores[1];

				T13Scores[0] = P38();

				int best = bestProgram(T13Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[5] = { T7, T5, T2, A24, T0,  };

				float T14Scores[5];

				T14Scores[0] = P39();
				T14Scores[1] = P40();
				T14Scores[2] = P19();
				T14Scores[3] = P41();
				T14Scores[4] = P23();

				int best = bestProgram(T14Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[1] = { T14,  };

				float T15Scores[1];

				T15Scores[0] = P42();

				int best = bestProgram(T15Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[6] = { A28, T10, T10, A23, T2, A21,  };

				float T16Scores[6];

				T16Scores[0] = P43();
				T16Scores[1] = P44();
				T16Scores[2] = P45();
				T16Scores[3] = P46();
				T16Scores[4] = P19();
				T16Scores[5] = P35();

				int best = bestProgram(T16Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[9] = { A26, T10, T12, A26, T8, A27, T2, A23, A28,  };

				float T17Scores[9];

				T17Scores[0] = P47();
				T17Scores[1] = P36();
				T17Scores[2] = P48();
				T17Scores[3] = P49();
				T17Scores[4] = P50();
				T17Scores[5] = P51();
				T17Scores[6] = P52();
				T17Scores[7] = P53();
				T17Scores[8] = P43();

				int best = bestProgram(T17Scores, 9);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[5] = { A26, T16, T15, T11, T13,  };

				float T18Scores[5];

				T18Scores[0] = P54();
				T18Scores[1] = P55();
				T18Scores[2] = P56();
				T18Scores[3] = P57();
				T18Scores[4] = P58();

				int best = bestProgram(T18Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[5] = { A27, T10, T17, T18, A26,  };

				float T19Scores[5];

				T19Scores[0] = P59();
				T19Scores[1] = P60();
				T19Scores[2] = P61();
				T19Scores[3] = P62();
				T19Scores[4] = P63();

				int best = bestProgram(T19Scores, 5);
				currentVertex = next[best];
				break;
			}
		case A20: {
				actions[0] = 3;
				return;
			}
		case A21: {
				actions[0] = 4;
				return;
			}
		case A22: {
				actions[0] = 8;
				return;
			}
		case A23: {
				actions[0] = 0;
				return;
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
				actions[0] = 2;
				return;
			}
		case A27: {
				actions[0] = 1;
				return;
			}
		case A28: {
				actions[0] = 7;
				return;
			}
		}
	}
}
