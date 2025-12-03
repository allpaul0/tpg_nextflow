/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:34
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, A16, A17, A18, A19, A20, A21, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T15;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A16, A17,  };

				float T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A18, A17, A16,  };

				float T1Scores[3];

				T1Scores[0] = P2();
				T1Scores[1] = P3();
				T1Scores[2] = P4();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { T1, A19, A20,  };

				float T2Scores[3];

				T2Scores[0] = P5();
				T2Scores[1] = P6();
				T2Scores[2] = P7();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[1] = { T1,  };

				float T3Scores[1];

				T3Scores[0] = P8();

				int best = bestProgram(T3Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[5] = { A20, A20, A17, A19, T1,  };

				float T4Scores[5];

				T4Scores[0] = P9();
				T4Scores[1] = P7();
				T4Scores[2] = P1();
				T4Scores[3] = P10();
				T4Scores[4] = P5();

				int best = bestProgram(T4Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[3] = { T3, A19, A18,  };

				float T5Scores[3];

				T5Scores[0] = P11();
				T5Scores[1] = P12();
				T5Scores[2] = P13();

				int best = bestProgram(T5Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { T0, T5,  };

				float T6Scores[2];

				T6Scores[0] = P14();
				T6Scores[1] = P15();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[2] = { T0, T4,  };

				float T7Scores[2];

				T7Scores[0] = P14();
				T7Scores[1] = P16();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { T0, T5, T4,  };

				float T8Scores[3];

				T8Scores[0] = P17();
				T8Scores[1] = P18();
				T8Scores[2] = P16();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[2] = { T8, T6,  };

				float T9Scores[2];

				T9Scores[0] = P19();
				T9Scores[1] = P20();

				int best = bestProgram(T9Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { T0, T2,  };

				float T10Scores[2];

				T10Scores[0] = P21();
				T10Scores[1] = P22();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[4] = { T2, A20, A21, T8,  };

				float T11Scores[4];

				T11Scores[0] = P23();
				T11Scores[1] = P24();
				T11Scores[2] = P25();
				T11Scores[3] = P19();

				int best = bestProgram(T11Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[5] = { T7, A17, T9, T0, A20,  };

				float T12Scores[5];

				T12Scores[0] = P26();
				T12Scores[1] = P27();
				T12Scores[2] = P28();
				T12Scores[3] = P29();
				T12Scores[4] = P30();

				int best = bestProgram(T12Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[4] = { T8, T10, T2, A20,  };

				float T13Scores[4];

				T13Scores[0] = P31();
				T13Scores[1] = P32();
				T13Scores[2] = P33();
				T13Scores[3] = P34();

				int best = bestProgram(T13Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[2] = { T11, A20,  };

				float T14Scores[2];

				T14Scores[0] = P35();
				T14Scores[1] = P36();

				int best = bestProgram(T14Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[4] = { T12, T8, T13, T14,  };

				float T15Scores[4];

				T15Scores[0] = P37();
				T15Scores[1] = P38();
				T15Scores[2] = P39();
				T15Scores[3] = P40();

				int best = bestProgram(T15Scores, 4);
				currentVertex = next[best];
				break;
			}
		case A16: {
				actions[0] = 4;
				return;
			}
		case A17: {
				actions[0] = 0;
				return;
			}
		case A18: {
				actions[0] = 6;
				return;
			}
		case A19: {
				actions[0] = 5;
				return;
			}
		case A20: {
				actions[0] = 1;
				return;
			}
		case A21: {
				actions[0] = 2;
				return;
			}
		}
	}
}
