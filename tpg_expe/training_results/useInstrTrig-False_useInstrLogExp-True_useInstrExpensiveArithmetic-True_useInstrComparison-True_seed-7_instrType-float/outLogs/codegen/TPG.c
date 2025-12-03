/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:36
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, A19, A20, A21, A22, A23, A24, A25, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T18;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[4] = { A19, A20, A21, A22,  };

				float T0Scores[4];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();
				T0Scores[3] = P3();

				int best = bestProgram(T0Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A21, A20,  };

				float T1Scores[2];

				T1Scores[0] = P4();
				T1Scores[1] = P5();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A20, A21, A22,  };

				float T2Scores[3];

				T2Scores[0] = P6();
				T2Scores[1] = P7();
				T2Scores[2] = P8();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[4] = { A22, T1, T2, A22,  };

				float T3Scores[4];

				T3Scores[0] = P9();
				T3Scores[1] = P10();
				T3Scores[2] = P11();
				T3Scores[3] = P12();

				int best = bestProgram(T3Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { T0, A23, A21,  };

				float T4Scores[3];

				T4Scores[0] = P13();
				T4Scores[1] = P14();
				T4Scores[2] = P15();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { T3,  };

				float T5Scores[1];

				T5Scores[0] = P16();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[5] = { T3, T4, A20, A20, T5,  };

				float T6Scores[5];

				T6Scores[0] = P17();
				T6Scores[1] = P18();
				T6Scores[2] = P19();
				T6Scores[3] = P20();
				T6Scores[4] = P21();

				int best = bestProgram(T6Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[1] = { T6,  };

				float T7Scores[1];

				T7Scores[0] = P22();

				int best = bestProgram(T7Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[2] = { A25, T6,  };

				float T8Scores[2];

				T8Scores[0] = P23();
				T8Scores[1] = P24();

				int best = bestProgram(T8Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[3] = { T7, T4, A24,  };

				float T9Scores[3];

				T9Scores[0] = P25();
				T9Scores[1] = P26();
				T9Scores[2] = P27();

				int best = bestProgram(T9Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { T3, T7, A24,  };

				float T10Scores[3];

				T10Scores[0] = P28();
				T10Scores[1] = P29();
				T10Scores[2] = P27();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[7] = { A23, T9, T10, A25, T8, A25, T9,  };

				float T11Scores[7];

				T11Scores[0] = P30();
				T11Scores[1] = P31();
				T11Scores[2] = P32();
				T11Scores[3] = P33();
				T11Scores[4] = P34();
				T11Scores[5] = P35();
				T11Scores[6] = P36();

				int best = bestProgram(T11Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[5] = { A23, T10, A25, A25, T9,  };

				float T12Scores[5];

				T12Scores[0] = P37();
				T12Scores[1] = P32();
				T12Scores[2] = P38();
				T12Scores[3] = P39();
				T12Scores[4] = P31();

				int best = bestProgram(T12Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[1] = { T11,  };

				float T13Scores[1];

				T13Scores[0] = P40();

				int best = bestProgram(T13Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[4] = { T12, T10, A25, A25,  };

				float T14Scores[4];

				T14Scores[0] = P41();
				T14Scores[1] = P42();
				T14Scores[2] = P43();
				T14Scores[3] = P38();

				int best = bestProgram(T14Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[6] = { T10, A25, A23, T8, A25, T9,  };

				float T15Scores[6];

				T15Scores[0] = P42();
				T15Scores[1] = P38();
				T15Scores[2] = P44();
				T15Scores[3] = P45();
				T15Scores[4] = P43();
				T15Scores[5] = P46();

				int best = bestProgram(T15Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[3] = { T13, T14, T15,  };

				float T16Scores[3];

				T16Scores[0] = P47();
				T16Scores[1] = P48();
				T16Scores[2] = P49();

				int best = bestProgram(T16Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[3] = { T15, T11, T9,  };

				float T17Scores[3];

				T17Scores[0] = P49();
				T17Scores[1] = P40();
				T17Scores[2] = P50();

				int best = bestProgram(T17Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[4] = { T16, T17, A23, T16,  };

				float T18Scores[4];

				T18Scores[0] = P51();
				T18Scores[1] = P52();
				T18Scores[2] = P44();
				T18Scores[3] = P53();

				int best = bestProgram(T18Scores, 4);
				currentVertex = next[best];
				break;
			}
		case A19: {
				actions[0] = 3;
				return;
			}
		case A20: {
				actions[0] = 4;
				return;
			}
		case A21: {
				actions[0] = 5;
				return;
			}
		case A22: {
				actions[0] = 6;
				return;
			}
		case A23: {
				actions[0] = 1;
				return;
			}
		case A24: {
				actions[0] = 0;
				return;
			}
		case A25: {
				actions[0] = 2;
				return;
			}
		}
	}
}
