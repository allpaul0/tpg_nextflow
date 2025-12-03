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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, A16, A17, A18, A19, A20, A21, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T15;
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
				const enum vertices next[4] = { A20, A18, A16, A20,  };

				float T1Scores[4];

				T1Scores[0] = P2();
				T1Scores[1] = P3();
				T1Scores[2] = P4();
				T1Scores[3] = P5();

				int best = bestProgram(T1Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[4] = { A18, A16, A17, A20,  };

				float T2Scores[4];

				T2Scores[0] = P3();
				T2Scores[1] = P4();
				T2Scores[2] = P6();
				T2Scores[3] = P7();

				int best = bestProgram(T2Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[1] = { T2,  };

				float T3Scores[1];

				T3Scores[0] = P8();

				int best = bestProgram(T3Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[5] = { A18, A19, A20, A19, A17,  };

				float T4Scores[5];

				T4Scores[0] = P9();
				T4Scores[1] = P10();
				T4Scores[2] = P11();
				T4Scores[3] = P12();
				T4Scores[4] = P6();

				int best = bestProgram(T4Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { A16, T2,  };

				float T5Scores[2];

				T5Scores[0] = P13();
				T5Scores[1] = P14();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[7] = { T0, A17, T4, T2, A16, T5, A17,  };

				float T6Scores[7];

				T6Scores[0] = P15();
				T6Scores[1] = P16();
				T6Scores[2] = P17();
				T6Scores[3] = P18();
				T6Scores[4] = P19();
				T6Scores[5] = P20();
				T6Scores[6] = P6();

				int best = bestProgram(T6Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[2] = { T1, T6,  };

				float T7Scores[2];

				T7Scores[0] = P21();
				T7Scores[1] = P22();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[2] = { T7, T0,  };

				float T8Scores[2];

				T8Scores[0] = P23();
				T8Scores[1] = P24();

				int best = bestProgram(T8Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[4] = { T0, T0, T7, T3,  };

				float T9Scores[4];

				T9Scores[0] = P25();
				T9Scores[1] = P24();
				T9Scores[2] = P23();
				T9Scores[3] = P26();

				int best = bestProgram(T9Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { T8, T4, T1,  };

				float T10Scores[3];

				T10Scores[0] = P27();
				T10Scores[1] = P28();
				T10Scores[2] = P21();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { T9, T1, T4,  };

				float T11Scores[3];

				T11Scores[0] = P29();
				T11Scores[1] = P21();
				T11Scores[2] = P28();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[2] = { T11, A21,  };

				float T12Scores[2];

				T12Scores[0] = P30();
				T12Scores[1] = P31();

				int best = bestProgram(T12Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[5] = { A16, T12, T4, A16, A21,  };

				float T13Scores[5];

				T13Scores[0] = P32();
				T13Scores[1] = P33();
				T13Scores[2] = P34();
				T13Scores[3] = P35();
				T13Scores[4] = P36();

				int best = bestProgram(T13Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[3] = { T13, A21, T10,  };

				float T14Scores[3];

				T14Scores[0] = P37();
				T14Scores[1] = P38();
				T14Scores[2] = P39();

				int best = bestProgram(T14Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[4] = { T9, T4, T0, T14,  };

				float T15Scores[4];

				T15Scores[0] = P40();
				T15Scores[1] = P41();
				T15Scores[2] = P42();
				T15Scores[3] = P43();

				int best = bestProgram(T15Scores, 4);
				currentVertex = next[best];
				break;
			}
		case A16: {
				actions[0] = 2;
				return;
			}
		case A17: {
				actions[0] = 5;
				return;
			}
		case A18: {
				actions[0] = 6;
				return;
			}
		case A19: {
				actions[0] = 7;
				return;
			}
		case A20: {
				actions[0] = 4;
				return;
			}
		case A21: {
				actions[0] = 0;
				return;
			}
		}
	}
}
