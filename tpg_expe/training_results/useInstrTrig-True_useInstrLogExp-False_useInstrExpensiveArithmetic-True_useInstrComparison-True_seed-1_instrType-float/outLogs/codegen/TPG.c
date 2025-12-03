/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:31
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, A18, A19, A20, A21, A22, A23, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T17;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[5] = { A20, A21, A22, A22, A23,  };

				float T0Scores[5];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();
				T0Scores[3] = P3();
				T0Scores[4] = P4();

				int best = bestProgram(T0Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A20, A22,  };

				float T1Scores[2];

				T1Scores[0] = P0();
				T1Scores[1] = P5();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[1] = { T0,  };

				float T2Scores[1];

				T2Scores[0] = P6();

				int best = bestProgram(T2Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { A20, A19, A23,  };

				float T3Scores[3];

				T3Scores[0] = P0();
				T3Scores[1] = P7();
				T3Scores[2] = P4();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { A23, A20, A22,  };

				float T4Scores[3];

				T4Scores[0] = P8();
				T4Scores[1] = P9();
				T4Scores[2] = P10();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[3] = { T2, A23, T3,  };

				float T5Scores[3];

				T5Scores[0] = P11();
				T5Scores[1] = P12();
				T5Scores[2] = P13();

				int best = bestProgram(T5Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[3] = { T2, A18, T3,  };

				float T6Scores[3];

				T6Scores[0] = P11();
				T6Scores[1] = P14();
				T6Scores[2] = P15();

				int best = bestProgram(T6Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[1] = { T5,  };

				float T7Scores[1];

				T7Scores[0] = P16();

				int best = bestProgram(T7Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[2] = { T5, A18,  };

				float T8Scores[2];

				T8Scores[0] = P17();
				T8Scores[1] = P14();

				int best = bestProgram(T8Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T6,  };

				float T9Scores[1];

				T9Scores[0] = P18();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { T9, T2,  };

				float T10Scores[2];

				T10Scores[0] = P19();
				T10Scores[1] = P20();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[6] = { T6, T1, A21, A23, T2, T8,  };

				float T11Scores[6];

				T11Scores[0] = P21();
				T11Scores[1] = P22();
				T11Scores[2] = P23();
				T11Scores[3] = P4();
				T11Scores[4] = P20();
				T11Scores[5] = P24();

				int best = bestProgram(T11Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[2] = { T11, A18,  };

				float T12Scores[2];

				T12Scores[0] = P25();
				T12Scores[1] = P26();

				int best = bestProgram(T12Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[6] = { T5, T10, A21, T6, T12, T4,  };

				float T13Scores[6];

				T13Scores[0] = P27();
				T13Scores[1] = P28();
				T13Scores[2] = P29();
				T13Scores[3] = P30();
				T13Scores[4] = P31();
				T13Scores[5] = P32();

				int best = bestProgram(T13Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[4] = { T13, A18, T12, A23,  };

				float T14Scores[4];

				T14Scores[0] = P33();
				T14Scores[1] = P34();
				T14Scores[2] = P35();
				T14Scores[3] = P36();

				int best = bestProgram(T14Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[1] = { T13,  };

				float T15Scores[1];

				T15Scores[0] = P37();

				int best = bestProgram(T15Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[3] = { T14, T15, A19,  };

				float T16Scores[3];

				T16Scores[0] = P38();
				T16Scores[1] = P39();
				T16Scores[2] = P40();

				int best = bestProgram(T16Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[8] = { T14, A19, A20, A23, T14, T7, T16, A23,  };

				float T17Scores[8];

				T17Scores[0] = P41();
				T17Scores[1] = P42();
				T17Scores[2] = P43();
				T17Scores[3] = P44();
				T17Scores[4] = P45();
				T17Scores[5] = P46();
				T17Scores[6] = P47();
				T17Scores[7] = P48();

				int best = bestProgram(T17Scores, 8);
				currentVertex = next[best];
				break;
			}
		case A18: {
				actions[0] = 2;
				return;
			}
		case A19: {
				actions[0] = 0;
				return;
			}
		case A20: {
				actions[0] = 5;
				return;
			}
		case A21: {
				actions[0] = 1;
				return;
			}
		case A22: {
				actions[0] = 4;
				return;
			}
		case A23: {
				actions[0] = 6;
				return;
			}
		}
	}
}
