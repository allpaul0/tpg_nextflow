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
				const enum vertices next[1] = { A19,  };

				float T1Scores[1];

				T1Scores[0] = P2();

				int best = bestProgram(T1Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { A18, T1,  };

				float T2Scores[2];

				T2Scores[0] = P3();
				T2Scores[1] = P4();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { A18, T1,  };

				float T3Scores[2];

				T3Scores[0] = P5();
				T3Scores[1] = P4();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[1] = { T3,  };

				float T4Scores[1];

				T4Scores[0] = P6();

				int best = bestProgram(T4Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[4] = { T1, T0, A21, A18,  };

				float T5Scores[4];

				T5Scores[0] = P4();
				T5Scores[1] = P7();
				T5Scores[2] = P8();
				T5Scores[3] = P9();

				int best = bestProgram(T5Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[3] = { T4, T0, A21,  };

				float T6Scores[3];

				T6Scores[0] = P10();
				T6Scores[1] = P11();
				T6Scores[2] = P12();

				int best = bestProgram(T6Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[4] = { T2, A17, A16, T5,  };

				float T7Scores[4];

				T7Scores[0] = P13();
				T7Scores[1] = P14();
				T7Scores[2] = P15();
				T7Scores[3] = P16();

				int best = bestProgram(T7Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { T7,  };

				float T8Scores[1];

				T8Scores[0] = P17();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T7,  };

				float T9Scores[1];

				T9Scores[0] = P18();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { T4, T9,  };

				float T10Scores[2];

				T10Scores[0] = P19();
				T10Scores[1] = P20();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[2] = { T8, T6,  };

				float T11Scores[2];

				T11Scores[0] = P21();
				T11Scores[1] = P22();

				int best = bestProgram(T11Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[1] = { T10,  };

				float T12Scores[1];

				T12Scores[0] = P23();

				int best = bestProgram(T12Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[7] = { T12, T9, T6, A18, A17, T0, A21,  };

				float T13Scores[7];

				T13Scores[0] = P24();
				T13Scores[1] = P25();
				T13Scores[2] = P26();
				T13Scores[3] = P27();
				T13Scores[4] = P28();
				T13Scores[5] = P29();
				T13Scores[6] = P30();

				int best = bestProgram(T13Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[4] = { T13, T7, T11, A18,  };

				float T14Scores[4];

				T14Scores[0] = P31();
				T14Scores[1] = P32();
				T14Scores[2] = P33();
				T14Scores[3] = P34();

				int best = bestProgram(T14Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[4] = { T14, A20, A21, T6,  };

				float T15Scores[4];

				T15Scores[0] = P35();
				T15Scores[1] = P36();
				T15Scores[2] = P30();
				T15Scores[3] = P37();

				int best = bestProgram(T15Scores, 4);
				currentVertex = next[best];
				break;
			}
		case A16: {
				actions[0] = 5;
				return;
			}
		case A17: {
				actions[0] = 6;
				return;
			}
		case A18: {
				actions[0] = 0;
				return;
			}
		case A19: {
				actions[0] = 4;
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
