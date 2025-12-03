/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:23
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, A20, A21, A22, A23, A24, A25, A26, A27, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T19;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[1] = { A21,  };

				float T0Scores[1];

				T0Scores[0] = P0();

				int best = bestProgram(T0Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A22, A21,  };

				float T1Scores[2];

				T1Scores[0] = P1();
				T1Scores[1] = P2();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[5] = { A22, A25, A22, A26, A22,  };

				float T2Scores[5];

				T2Scores[0] = P3();
				T2Scores[1] = P4();
				T2Scores[2] = P5();
				T2Scores[3] = P6();
				T2Scores[4] = P7();

				int best = bestProgram(T2Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { A24, A22, T0,  };

				float T3Scores[3];

				T3Scores[0] = P8();
				T3Scores[1] = P7();
				T3Scores[2] = P9();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[2] = { A20, A24,  };

				float T4Scores[2];

				T4Scores[0] = P10();
				T4Scores[1] = P11();

				int best = bestProgram(T4Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[5] = { A26, A20, T2, A24, A21,  };

				float T5Scores[5];

				T5Scores[0] = P12();
				T5Scores[1] = P13();
				T5Scores[2] = P14();
				T5Scores[3] = P15();
				T5Scores[4] = P16();

				int best = bestProgram(T5Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[4] = { A21, T1, T2, A25,  };

				float T6Scores[4];

				T6Scores[0] = P17();
				T6Scores[1] = P18();
				T6Scores[2] = P19();
				T6Scores[3] = P20();

				int best = bestProgram(T6Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[4] = { T4, A21, T3, A25,  };

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
				const enum vertices next[6] = { T4, A21, T5, A22, A25, T3,  };

				float T8Scores[6];

				T8Scores[0] = P21();
				T8Scores[1] = P25();
				T8Scores[2] = P26();
				T8Scores[3] = P27();
				T8Scores[4] = P28();
				T8Scores[5] = P29();

				int best = bestProgram(T8Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[2] = { A25, T4,  };

				float T9Scores[2];

				T9Scores[0] = P28();
				T9Scores[1] = P30();

				int best = bestProgram(T9Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { T6, T9,  };

				float T10Scores[2];

				T10Scores[0] = P31();
				T10Scores[1] = P32();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[4] = { T5, A21, A25, T10,  };

				float T11Scores[4];

				T11Scores[0] = P33();
				T11Scores[1] = P34();
				T11Scores[2] = P28();
				T11Scores[3] = P35();

				int best = bestProgram(T11Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[2] = { T6, T7,  };

				float T12Scores[2];

				T12Scores[0] = P36();
				T12Scores[1] = P37();

				int best = bestProgram(T12Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[2] = { T8, T12,  };

				float T13Scores[2];

				T13Scores[0] = P38();
				T13Scores[1] = P39();

				int best = bestProgram(T13Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[6] = { T8, T12, A22, T11, T5, A27,  };

				float T14Scores[6];

				T14Scores[0] = P40();
				T14Scores[1] = P41();
				T14Scores[2] = P42();
				T14Scores[3] = P43();
				T14Scores[4] = P44();
				T14Scores[5] = P45();

				int best = bestProgram(T14Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[1] = { T12,  };

				float T15Scores[1];

				T15Scores[0] = P41();

				int best = bestProgram(T15Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[3] = { T13, T8, T14,  };

				float T16Scores[3];

				T16Scores[0] = P46();
				T16Scores[1] = P47();
				T16Scores[2] = P48();

				int best = bestProgram(T16Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[3] = { T12, T16, A27,  };

				float T17Scores[3];

				T17Scores[0] = P41();
				T17Scores[1] = P49();
				T17Scores[2] = P45();

				int best = bestProgram(T17Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[5] = { T13, T14, T15, A27, A23,  };

				float T18Scores[5];

				T18Scores[0] = P46();
				T18Scores[1] = P50();
				T18Scores[2] = P51();
				T18Scores[3] = P52();
				T18Scores[4] = P53();

				int best = bestProgram(T18Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[4] = { A20, T17, T18, T14,  };

				float T19Scores[4];

				T19Scores[0] = P54();
				T19Scores[1] = P55();
				T19Scores[2] = P56();
				T19Scores[3] = P57();

				int best = bestProgram(T19Scores, 4);
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
				actions[0] = 0;
				return;
			}
		case A23: {
				actions[0] = 8;
				return;
			}
		case A24: {
				actions[0] = 7;
				return;
			}
		case A25: {
				actions[0] = 5;
				return;
			}
		case A26: {
				actions[0] = 6;
				return;
			}
		case A27: {
				actions[0] = 1;
				return;
			}
		}
	}
}
