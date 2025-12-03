/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:26
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, A15, A16, A17, A18, A19, A20, A21, A22, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T14;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[1] = { A15,  };

				float T0Scores[1];

				T0Scores[0] = P0();

				int best = bestProgram(T0Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A16, A17,  };

				float T1Scores[2];

				T1Scores[0] = P1();
				T1Scores[1] = P2();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[6] = { A16, A18, A19, A15, A15, T1,  };

				float T2Scores[6];

				T2Scores[0] = P1();
				T2Scores[1] = P3();
				T2Scores[2] = P4();
				T2Scores[3] = P5();
				T2Scores[4] = P6();
				T2Scores[5] = P7();

				int best = bestProgram(T2Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { T1, A20, A16,  };

				float T3Scores[3];

				T3Scores[0] = P8();
				T3Scores[1] = P9();
				T3Scores[2] = P10();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[5] = { A18, A19, T1, T0, A16,  };

				float T4Scores[5];

				T4Scores[0] = P11();
				T4Scores[1] = P12();
				T4Scores[2] = P13();
				T4Scores[3] = P14();
				T4Scores[4] = P15();

				int best = bestProgram(T4Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[3] = { T2, A20, T4,  };

				float T5Scores[3];

				T5Scores[0] = P16();
				T5Scores[1] = P17();
				T5Scores[2] = P18();

				int best = bestProgram(T5Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { T3, T4,  };

				float T6Scores[2];

				T6Scores[0] = P19();
				T6Scores[1] = P20();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[4] = { A16, A20, T4, T4,  };

				float T7Scores[4];

				T7Scores[0] = P21();
				T7Scores[1] = P22();
				T7Scores[2] = P23();
				T7Scores[3] = P24();

				int best = bestProgram(T7Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { T3, T5, T6,  };

				float T8Scores[3];

				T8Scores[0] = P25();
				T8Scores[1] = P26();
				T8Scores[2] = P27();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[2] = { T3, T8,  };

				float T9Scores[2];

				T9Scores[0] = P28();
				T9Scores[1] = P29();

				int best = bestProgram(T9Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[5] = { A22, T3, T8, T7, T3,  };

				float T10Scores[5];

				T10Scores[0] = P30();
				T10Scores[1] = P28();
				T10Scores[2] = P29();
				T10Scores[3] = P31();
				T10Scores[4] = P32();

				int best = bestProgram(T10Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[4] = { T3, T10, A22, A22,  };

				float T11Scores[4];

				T11Scores[0] = P28();
				T11Scores[1] = P33();
				T11Scores[2] = P34();
				T11Scores[3] = P35();

				int best = bestProgram(T11Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[4] = { A22, T3, T7, T11,  };

				float T12Scores[4];

				T12Scores[0] = P36();
				T12Scores[1] = P37();
				T12Scores[2] = P38();
				T12Scores[3] = P39();

				int best = bestProgram(T12Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[3] = { T12, A17, T9,  };

				float T13Scores[3];

				T13Scores[0] = P40();
				T13Scores[1] = P41();
				T13Scores[2] = P42();

				int best = bestProgram(T13Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[5] = { A21, T13, T11, T8, A22,  };

				float T14Scores[5];

				T14Scores[0] = P43();
				T14Scores[1] = P44();
				T14Scores[2] = P45();
				T14Scores[3] = P46();
				T14Scores[4] = P47();

				int best = bestProgram(T14Scores, 5);
				currentVertex = next[best];
				break;
			}
		case A15: {
				actions[0] = 4;
				return;
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
				actions[0] = 7;
				return;
			}
		case A19: {
				actions[0] = 0;
				return;
			}
		case A20: {
				actions[0] = 8;
				return;
			}
		case A21: {
				actions[0] = 2;
				return;
			}
		case A22: {
				actions[0] = 1;
				return;
			}
		}
	}
}
