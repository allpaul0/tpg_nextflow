/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:27
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, A18, A19, A20, A21, A22, A23, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T17;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A19, A21,  };

				float T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A18, A19,  };

				float T1Scores[2];

				T1Scores[0] = P2();
				T1Scores[1] = P3();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[1] = { T0,  };

				float T2Scores[1];

				T2Scores[0] = P4();

				int best = bestProgram(T2Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[4] = { A18, A20, A19, A21,  };

				float T3Scores[4];

				T3Scores[0] = P5();
				T3Scores[1] = P6();
				T3Scores[2] = P3();
				T3Scores[3] = P7();

				int best = bestProgram(T3Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[6] = { T2, A18, A18, A19, A20, A22,  };

				float T4Scores[6];

				T4Scores[0] = P8();
				T4Scores[1] = P9();
				T4Scores[2] = P10();
				T4Scores[3] = P3();
				T4Scores[4] = P11();
				T4Scores[5] = P12();

				int best = bestProgram(T4Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { T1,  };

				float T5Scores[1];

				T5Scores[0] = P13();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[1] = { T5,  };

				float T6Scores[1];

				T6Scores[0] = P14();

				int best = bestProgram(T6Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[1] = { T1,  };

				float T7Scores[1];

				T7Scores[0] = P15();

				int best = bestProgram(T7Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { T7,  };

				float T8Scores[1];

				T8Scores[0] = P16();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[7] = { A22, T3, A23, T4, A19, A20, A22,  };

				float T9Scores[7];

				T9Scores[0] = P17();
				T9Scores[1] = P18();
				T9Scores[2] = P19();
				T9Scores[3] = P20();
				T9Scores[4] = P3();
				T9Scores[5] = P21();
				T9Scores[6] = P22();

				int best = bestProgram(T9Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { T3, A23,  };

				float T10Scores[2];

				T10Scores[0] = P23();
				T10Scores[1] = P24();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[4] = { A23, T3, T8, A23,  };

				float T11Scores[4];

				T11Scores[0] = P24();
				T11Scores[1] = P25();
				T11Scores[2] = P26();
				T11Scores[3] = P27();

				int best = bestProgram(T11Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[2] = { T6, T9,  };

				float T12Scores[2];

				T12Scores[0] = P28();
				T12Scores[1] = P29();

				int best = bestProgram(T12Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[6] = { A19, A23, A22, A20, A22, T12,  };

				float T13Scores[6];

				T13Scores[0] = P3();
				T13Scores[1] = P30();
				T13Scores[2] = P31();
				T13Scores[3] = P21();
				T13Scores[4] = P17();
				T13Scores[5] = P32();

				int best = bestProgram(T13Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[2] = { T9, T10,  };

				float T14Scores[2];

				T14Scores[0] = P33();
				T14Scores[1] = P34();

				int best = bestProgram(T14Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[4] = { T3, T10, A21, T13,  };

				float T15Scores[4];

				T15Scores[0] = P35();
				T15Scores[1] = P36();
				T15Scores[2] = P37();
				T15Scores[3] = P38();

				int best = bestProgram(T15Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[4] = { T14, T4, T11, T9,  };

				float T16Scores[4];

				T16Scores[0] = P39();
				T16Scores[1] = P40();
				T16Scores[2] = P41();
				T16Scores[3] = P42();

				int best = bestProgram(T16Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[4] = { T15, T4, T9, T16,  };

				float T17Scores[4];

				T17Scores[0] = P43();
				T17Scores[1] = P44();
				T17Scores[2] = P45();
				T17Scores[3] = P46();

				int best = bestProgram(T17Scores, 4);
				currentVertex = next[best];
				break;
			}
		case A18: {
				actions[0] = 5;
				return;
			}
		case A19: {
				actions[0] = 0;
				return;
			}
		case A20: {
				actions[0] = 4;
				return;
			}
		case A21: {
				actions[0] = 6;
				return;
			}
		case A22: {
				actions[0] = 1;
				return;
			}
		case A23: {
				actions[0] = 2;
				return;
			}
		}
	}
}
