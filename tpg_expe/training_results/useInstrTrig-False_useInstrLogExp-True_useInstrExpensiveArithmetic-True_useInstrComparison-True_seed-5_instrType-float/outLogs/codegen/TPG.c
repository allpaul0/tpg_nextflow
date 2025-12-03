/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:28
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, A13, A14, A15, A16, A17, A18, A19, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T12;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[3] = { A13, A14, A16,  };

				float T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[4] = { A13, A16, A14, A17,  };

				float T1Scores[4];

				T1Scores[0] = P3();
				T1Scores[1] = P4();
				T1Scores[2] = P5();
				T1Scores[3] = P6();

				int best = bestProgram(T1Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { A17, A14,  };

				float T2Scores[2];

				T2Scores[0] = P7();
				T2Scores[1] = P8();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { A17, A16, A13,  };

				float T3Scores[3];

				T3Scores[0] = P9();
				T3Scores[1] = P10();
				T3Scores[2] = P11();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[4] = { A15, A13, T2, A14,  };

				float T4Scores[4];

				T4Scores[0] = P12();
				T4Scores[1] = P13();
				T4Scores[2] = P14();
				T4Scores[3] = P15();

				int best = bestProgram(T4Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[4] = { T1, A18, A15, A13,  };

				float T5Scores[4];

				T5Scores[0] = P16();
				T5Scores[1] = P17();
				T5Scores[2] = P18();
				T5Scores[3] = P3();

				int best = bestProgram(T5Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[5] = { A17, A14, A16, A13, A16,  };

				float T6Scores[5];

				T6Scores[0] = P9();
				T6Scores[1] = P5();
				T6Scores[2] = P10();
				T6Scores[3] = P11();
				T6Scores[4] = P19();

				int best = bestProgram(T6Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[5] = { T5, T4, T6, A13, T0,  };

				float T7Scores[5];

				T7Scores[0] = P20();
				T7Scores[1] = P21();
				T7Scores[2] = P22();
				T7Scores[3] = P23();
				T7Scores[4] = P24();

				int best = bestProgram(T7Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[6] = { A14, T3, T5, T0, T6, A14,  };

				float T8Scores[6];

				T8Scores[0] = P5();
				T8Scores[1] = P25();
				T8Scores[2] = P20();
				T8Scores[3] = P24();
				T8Scores[4] = P22();
				T8Scores[5] = P26();

				int best = bestProgram(T8Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[3] = { T7, T8, A18,  };

				float T9Scores[3];

				T9Scores[0] = P27();
				T9Scores[1] = P28();
				T9Scores[2] = P29();

				int best = bestProgram(T9Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[5] = { T9, T5, T7, A13, A19,  };

				float T10Scores[5];

				T10Scores[0] = P30();
				T10Scores[1] = P20();
				T10Scores[2] = P31();
				T10Scores[3] = P3();
				T10Scores[4] = P32();

				int best = bestProgram(T10Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { T10, A18, T7,  };

				float T11Scores[3];

				T11Scores[0] = P33();
				T11Scores[1] = P34();
				T11Scores[2] = P35();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[3] = { A19, A19, T11,  };

				float T12Scores[3];

				T12Scores[0] = P36();
				T12Scores[1] = P37();
				T12Scores[2] = P38();

				int best = bestProgram(T12Scores, 3);
				currentVertex = next[best];
				break;
			}
		case A13: {
				actions[0] = 5;
				return;
			}
		case A14: {
				actions[0] = 6;
				return;
			}
		case A15: {
				actions[0] = 0;
				return;
			}
		case A16: {
				actions[0] = 4;
				return;
			}
		case A17: {
				actions[0] = 7;
				return;
			}
		case A18: {
				actions[0] = 1;
				return;
			}
		case A19: {
				actions[0] = 2;
				return;
			}
		}
	}
}
