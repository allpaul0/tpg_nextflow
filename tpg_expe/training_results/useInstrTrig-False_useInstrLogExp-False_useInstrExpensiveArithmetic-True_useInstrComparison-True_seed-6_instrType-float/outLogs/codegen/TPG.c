/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:19
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
				const enum vertices next[2] = { A14, A16,  };

				float T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A14, A15, A14,  };

				float T1Scores[3];

				T1Scores[0] = P2();
				T1Scores[1] = P3();
				T1Scores[2] = P0();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A16, A17, A14,  };

				float T2Scores[3];

				T2Scores[0] = P4();
				T2Scores[1] = P5();
				T2Scores[2] = P0();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { A15, A17,  };

				float T3Scores[2];

				T3Scores[0] = P6();
				T3Scores[1] = P7();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[9] = { T0, A18, A17, A19, A15, T0, A18, T0, A17,  };

				float T4Scores[9];

				T4Scores[0] = P8();
				T4Scores[1] = P9();
				T4Scores[2] = P10();
				T4Scores[3] = P11();
				T4Scores[4] = P6();
				T4Scores[5] = P12();
				T4Scores[6] = P13();
				T4Scores[7] = P14();
				T4Scores[8] = P15();

				int best = bestProgram(T4Scores, 9);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[4] = { T3, T1, A17, A15,  };

				float T5Scores[4];

				T5Scores[0] = P16();
				T5Scores[1] = P17();
				T5Scores[2] = P18();
				T5Scores[3] = P19();

				int best = bestProgram(T5Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[1] = { T4,  };

				float T6Scores[1];

				T6Scores[0] = P20();

				int best = bestProgram(T6Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T0, A18, T2,  };

				float T7Scores[3];

				T7Scores[0] = P21();
				T7Scores[1] = P22();
				T7Scores[2] = P23();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[6] = { T5, T0, T4, T2, A18, A15,  };

				float T8Scores[6];

				T8Scores[0] = P24();
				T8Scores[1] = P25();
				T8Scores[2] = P26();
				T8Scores[3] = P23();
				T8Scores[4] = P22();
				T8Scores[5] = P27();

				int best = bestProgram(T8Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[3] = { T7, T5, T4,  };

				float T9Scores[3];

				T9Scores[0] = P28();
				T9Scores[1] = P29();
				T9Scores[2] = P26();

				int best = bestProgram(T9Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[4] = { T4, A20, T8, T6,  };

				float T10Scores[4];

				T10Scores[0] = P30();
				T10Scores[1] = P31();
				T10Scores[2] = P32();
				T10Scores[3] = P33();

				int best = bestProgram(T10Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { A20, T8, T4,  };

				float T11Scores[3];

				T11Scores[0] = P34();
				T11Scores[1] = P35();
				T11Scores[2] = P36();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[7] = { T11, A20, T10, T4, T9, T4, T4,  };

				float T12Scores[7];

				T12Scores[0] = P37();
				T12Scores[1] = P34();
				T12Scores[2] = P38();
				T12Scores[3] = P39();
				T12Scores[4] = P40();
				T12Scores[5] = P41();
				T12Scores[6] = P42();

				int best = bestProgram(T12Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[6] = { T12, T8, A20, T8, T4, T9,  };

				float T13Scores[6];

				T13Scores[0] = P43();
				T13Scores[1] = P44();
				T13Scores[2] = P45();
				T13Scores[3] = P46();
				T13Scores[4] = P42();
				T13Scores[5] = P47();

				int best = bestProgram(T13Scores, 6);
				currentVertex = next[best];
				break;
			}
		case A14: {
				actions[0] = 5;
				return;
			}
		case A15: {
				actions[0] = 6;
				return;
			}
		case A16: {
				actions[0] = 7;
				return;
			}
		case A17: {
				actions[0] = 4;
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
				actions[0] = 1;
				return;
			}
		}
	}
}
