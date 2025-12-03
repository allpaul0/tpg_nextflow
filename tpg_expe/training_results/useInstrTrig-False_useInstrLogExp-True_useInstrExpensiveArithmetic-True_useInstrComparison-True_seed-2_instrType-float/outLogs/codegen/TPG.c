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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, A17, A18, A19, A20, A21, A22, A23, A24, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T16;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[4] = { A17, A20, A18, A21,  };

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
				const enum vertices next[3] = { A17, A18, A19,  };

				float T1Scores[3];

				T1Scores[0] = P0();
				T1Scores[1] = P4();
				T1Scores[2] = P5();

				int best = bestProgram(T1Scores, 3);
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
				const enum vertices next[5] = { A20, T1, A22, A21, A23,  };

				float T3Scores[5];

				T3Scores[0] = P7();
				T3Scores[1] = P8();
				T3Scores[2] = P9();
				T3Scores[3] = P10();
				T3Scores[4] = P11();

				int best = bestProgram(T3Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[1] = { T3,  };

				float T4Scores[1];

				T4Scores[0] = P12();

				int best = bestProgram(T4Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { T4,  };

				float T5Scores[1];

				T5Scores[0] = P13();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { T3, A21,  };

				float T6Scores[2];

				T6Scores[0] = P14();
				T6Scores[1] = P15();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[6] = { T2, A21, A23, A20, T5, A18,  };

				float T7Scores[6];

				T7Scores[0] = P16();
				T7Scores[1] = P17();
				T7Scores[2] = P18();
				T7Scores[3] = P19();
				T7Scores[4] = P20();
				T7Scores[5] = P21();

				int best = bestProgram(T7Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[4] = { T2, T6, T3, A20,  };

				float T8Scores[4];

				T8Scores[0] = P22();
				T8Scores[1] = P23();
				T8Scores[2] = P24();
				T8Scores[3] = P19();

				int best = bestProgram(T8Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[2] = { T1, T8,  };

				float T9Scores[2];

				T9Scores[0] = P8();
				T9Scores[1] = P25();

				int best = bestProgram(T9Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { T7, A24,  };

				float T10Scores[2];

				T10Scores[0] = P26();
				T10Scores[1] = P27();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[2] = { T7, A24,  };

				float T11Scores[2];

				T11Scores[0] = P28();
				T11Scores[1] = P27();

				int best = bestProgram(T11Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[2] = { T11, T10,  };

				float T12Scores[2];

				T12Scores[0] = P29();
				T12Scores[1] = P30();

				int best = bestProgram(T12Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[3] = { T7, A24, T10,  };

				float T13Scores[3];

				T13Scores[0] = P28();
				T13Scores[1] = P31();
				T13Scores[2] = P30();

				int best = bestProgram(T13Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[1] = { T12,  };

				float T14Scores[1];

				T14Scores[0] = P32();

				int best = bestProgram(T14Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[3] = { T14, T13, A22,  };

				float T15Scores[3];

				T15Scores[0] = P33();
				T15Scores[1] = P34();
				T15Scores[2] = P35();

				int best = bestProgram(T15Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[3] = { T9, T15, T9,  };

				float T16Scores[3];

				T16Scores[0] = P36();
				T16Scores[1] = P37();
				T16Scores[2] = P38();

				int best = bestProgram(T16Scores, 3);
				currentVertex = next[best];
				break;
			}
		case A17: {
				actions[0] = 4;
				return;
			}
		case A18: {
				actions[0] = 6;
				return;
			}
		case A19: {
				actions[0] = 8;
				return;
			}
		case A20: {
				actions[0] = 0;
				return;
			}
		case A21: {
				actions[0] = 5;
				return;
			}
		case A22: {
				actions[0] = 1;
				return;
			}
		case A23: {
				actions[0] = 7;
				return;
			}
		case A24: {
				actions[0] = 2;
				return;
			}
		}
	}
}
