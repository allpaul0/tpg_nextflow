/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:30
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, A14, A15, A16, A17, A18, A19, A20, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T13;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[3] = { A14, A16, A17,  };

				float T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[4] = { A14, A15, A17, A16,  };

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
				const enum vertices next[3] = { A20, T1, T0,  };

				float T2Scores[3];

				T2Scores[0] = P7();
				T2Scores[1] = P8();
				T2Scores[2] = P9();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[9] = { T1, T1, A20, A20, T2, T0, T0, A18, A20,  };

				float T3Scores[9];

				T3Scores[0] = P10();
				T3Scores[1] = P11();
				T3Scores[2] = P12();
				T3Scores[3] = P13();
				T3Scores[4] = P14();
				T3Scores[5] = P15();
				T3Scores[6] = P16();
				T3Scores[7] = P17();
				T3Scores[8] = P18();

				int best = bestProgram(T3Scores, 9);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { T1, A20, T0,  };

				float T4Scores[3];

				T4Scores[0] = P19();
				T4Scores[1] = P20();
				T4Scores[2] = P21();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[3] = { T2, A15, A20,  };

				float T5Scores[3];

				T5Scores[0] = P14();
				T5Scores[1] = P22();
				T5Scores[2] = P13();

				int best = bestProgram(T5Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[6] = { T0, A20, A18, T3, T4, A20,  };

				float T6Scores[6];

				T6Scores[0] = P23();
				T6Scores[1] = P24();
				T6Scores[2] = P25();
				T6Scores[3] = P26();
				T6Scores[4] = P27();
				T6Scores[5] = P20();

				int best = bestProgram(T6Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[2] = { T6, T4,  };

				float T7Scores[2];

				T7Scores[0] = P28();
				T7Scores[1] = P27();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[7] = { T0, A20, A18, T3, A15, T0, A20,  };

				float T8Scores[7];

				T8Scores[0] = P23();
				T8Scores[1] = P29();
				T8Scores[2] = P30();
				T8Scores[3] = P26();
				T8Scores[4] = P31();
				T8Scores[5] = P16();
				T8Scores[6] = P20();

				int best = bestProgram(T8Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[2] = { A20, T8,  };

				float T9Scores[2];

				T9Scores[0] = P12();
				T9Scores[1] = P32();

				int best = bestProgram(T9Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { T5, T9,  };

				float T10Scores[2];

				T10Scores[0] = P33();
				T10Scores[1] = P34();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[7] = { T0, T3, A18, T10, A18, A20, T0,  };

				float T11Scores[7];

				T11Scores[0] = P23();
				T11Scores[1] = P26();
				T11Scores[2] = P35();
				T11Scores[3] = P36();
				T11Scores[4] = P37();
				T11Scores[5] = P7();
				T11Scores[6] = P38();

				int best = bestProgram(T11Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[1] = { T11,  };

				float T12Scores[1];

				T12Scores[0] = P39();

				int best = bestProgram(T12Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[9] = { A19, T7, T3, A18, T11, A16, T3, A18, T12,  };

				float T13Scores[9];

				T13Scores[0] = P40();
				T13Scores[1] = P41();
				T13Scores[2] = P42();
				T13Scores[3] = P37();
				T13Scores[4] = P39();
				T13Scores[5] = P43();
				T13Scores[6] = P26();
				T13Scores[7] = P44();
				T13Scores[8] = P45();

				int best = bestProgram(T13Scores, 9);
				currentVertex = next[best];
				break;
			}
		case A14: {
				actions[0] = 4;
				return;
			}
		case A15: {
				actions[0] = 0;
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
				actions[0] = 1;
				return;
			}
		case A19: {
				actions[0] = 7;
				return;
			}
		case A20: {
				actions[0] = 2;
				return;
			}
		}
	}
}
