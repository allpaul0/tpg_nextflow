/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:21
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, A13, A14, A15, A16, A17, A18, A19, A20, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T12;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A17, A18,  };

				float T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[5] = { A13, A14, T0, A17, A18,  };

				float T1Scores[5];

				T1Scores[0] = P2();
				T1Scores[1] = P3();
				T1Scores[2] = P4();
				T1Scores[3] = P5();
				T1Scores[4] = P6();

				int best = bestProgram(T1Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[4] = { T0, A14, A17, A13,  };

				float T2Scores[4];

				T2Scores[0] = P4();
				T2Scores[1] = P7();
				T2Scores[2] = P8();
				T2Scores[3] = P9();

				int best = bestProgram(T2Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[1] = { A19,  };

				float T3Scores[1];

				T3Scores[0] = P10();

				int best = bestProgram(T3Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[4] = { A14, A17, A16, A13,  };

				float T4Scores[4];

				T4Scores[0] = P11();
				T4Scores[1] = P12();
				T4Scores[2] = P13();
				T4Scores[3] = P9();

				int best = bestProgram(T4Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[5] = { T3, T1, T4, A19, A13,  };

				float T5Scores[5];

				T5Scores[0] = P14();
				T5Scores[1] = P15();
				T5Scores[2] = P16();
				T5Scores[3] = P17();
				T5Scores[4] = P9();

				int best = bestProgram(T5Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[6] = { A19, T2, T2, A13, A19, T2,  };

				float T6Scores[6];

				T6Scores[0] = P18();
				T6Scores[1] = P19();
				T6Scores[2] = P20();
				T6Scores[3] = P21();
				T6Scores[4] = P22();
				T6Scores[5] = P23();

				int best = bestProgram(T6Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[2] = { T6, T4,  };

				float T7Scores[2];

				T7Scores[0] = P24();
				T7Scores[1] = P25();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[4] = { A20, T5, T7, A20,  };

				float T8Scores[4];

				T8Scores[0] = P26();
				T8Scores[1] = P27();
				T8Scores[2] = P28();
				T8Scores[3] = P29();

				int best = bestProgram(T8Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T5,  };

				float T9Scores[1];

				T9Scores[0] = P27();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[7] = { A20, T5, T1, T7, A19, A20, A20,  };

				float T10Scores[7];

				T10Scores[0] = P30();
				T10Scores[1] = P31();
				T10Scores[2] = P32();
				T10Scores[3] = P28();
				T10Scores[4] = P33();
				T10Scores[5] = P34();
				T10Scores[6] = P35();

				int best = bestProgram(T10Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[4] = { T9, T7, A20, T10,  };

				float T11Scores[4];

				T11Scores[0] = P36();
				T11Scores[1] = P37();
				T11Scores[2] = P38();
				T11Scores[3] = P39();

				int best = bestProgram(T11Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[5] = { T11, A15, T9, T8, A19,  };

				float T12Scores[5];

				T12Scores[0] = P40();
				T12Scores[1] = P41();
				T12Scores[2] = P36();
				T12Scores[3] = P42();
				T12Scores[4] = P43();

				int best = bestProgram(T12Scores, 5);
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
				actions[0] = 2;
				return;
			}
		case A16: {
				actions[0] = 8;
				return;
			}
		case A17: {
				actions[0] = 4;
				return;
			}
		case A18: {
				actions[0] = 7;
				return;
			}
		case A19: {
				actions[0] = 1;
				return;
			}
		case A20: {
				actions[0] = 0;
				return;
			}
		}
	}
}
