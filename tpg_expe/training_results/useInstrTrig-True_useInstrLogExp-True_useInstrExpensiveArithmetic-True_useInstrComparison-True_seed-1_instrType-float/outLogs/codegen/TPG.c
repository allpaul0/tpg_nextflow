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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, A14, A15, A16, A17, A18, A19, A20, A21, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T13;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A14, A16,  };

				float T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A15, A19,  };

				float T1Scores[2];

				T1Scores[0] = P2();
				T1Scores[1] = P3();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[4] = { A17, A20, T0, A15,  };

				float T2Scores[4];

				T2Scores[0] = P4();
				T2Scores[1] = P5();
				T2Scores[2] = P6();
				T2Scores[3] = P7();

				int best = bestProgram(T2Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[1] = { A18,  };

				float T3Scores[1];

				T3Scores[0] = P8();

				int best = bestProgram(T3Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[5] = { A17, A15, A18, T0, A18,  };

				float T4Scores[5];

				T4Scores[0] = P9();
				T4Scores[1] = P2();
				T4Scores[2] = P10();
				T4Scores[3] = P6();
				T4Scores[4] = P11();

				int best = bestProgram(T4Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { T4,  };

				float T5Scores[1];

				T5Scores[0] = P12();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { T1, T4,  };

				float T6Scores[2];

				T6Scores[0] = P13();
				T6Scores[1] = P14();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[4] = { T1, T1, T4, T4,  };

				float T7Scores[4];

				T7Scores[0] = P15();
				T7Scores[1] = P16();
				T7Scores[2] = P12();
				T7Scores[3] = P17();

				int best = bestProgram(T7Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { T7,  };

				float T8Scores[1];

				T8Scores[0] = P18();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[4] = { A19, T8, T2, T2,  };

				float T9Scores[4];

				T9Scores[0] = P19();
				T9Scores[1] = P20();
				T9Scores[2] = P21();
				T9Scores[3] = P22();

				int best = bestProgram(T9Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { A21, T2, A19,  };

				float T10Scores[3];

				T10Scores[0] = P23();
				T10Scores[1] = P24();
				T10Scores[2] = P19();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { T5, T10, T3,  };

				float T11Scores[3];

				T11Scores[0] = P25();
				T11Scores[1] = P26();
				T11Scores[2] = P27();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[4] = { T9, T2, T6, T11,  };

				float T12Scores[4];

				T12Scores[0] = P28();
				T12Scores[1] = P29();
				T12Scores[2] = P30();
				T12Scores[3] = P31();

				int best = bestProgram(T12Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[8] = { A21, T9, T12, T10, T11, T12, T9, T9,  };

				float T13Scores[8];

				T13Scores[0] = P32();
				T13Scores[1] = P33();
				T13Scores[2] = P34();
				T13Scores[3] = P35();
				T13Scores[4] = P36();
				T13Scores[5] = P37();
				T13Scores[6] = P38();
				T13Scores[7] = P39();

				int best = bestProgram(T13Scores, 8);
				currentVertex = next[best];
				break;
			}
		case A14: {
				actions[0] = 3;
				return;
			}
		case A15: {
				actions[0] = 4;
				return;
			}
		case A16: {
				actions[0] = 6;
				return;
			}
		case A17: {
				actions[0] = 5;
				return;
			}
		case A18: {
				actions[0] = 0;
				return;
			}
		case A19: {
				actions[0] = 2;
				return;
			}
		case A20: {
				actions[0] = 7;
				return;
			}
		case A21: {
				actions[0] = 1;
				return;
			}
		}
	}
}
