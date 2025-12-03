/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:31
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, A18, A19, A20, A21, A22, A23, A24, A25, };

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
				const enum vertices next[1] = { A19,  };

				float T1Scores[1];

				T1Scores[0] = P2();

				int best = bestProgram(T1Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { A22, A21,  };

				float T2Scores[2];

				T2Scores[0] = P3();
				T2Scores[1] = P4();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { A23, A20, A24,  };

				float T3Scores[3];

				T3Scores[0] = P5();
				T3Scores[1] = P6();
				T3Scores[2] = P7();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[2] = { A20, A22,  };

				float T4Scores[2];

				T4Scores[0] = P6();
				T4Scores[1] = P8();

				int best = bestProgram(T4Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { A24,  };

				float T5Scores[1];

				T5Scores[0] = P9();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[4] = { A25, A24, A21, A18,  };

				float T6Scores[4];

				T6Scores[0] = P10();
				T6Scores[1] = P11();
				T6Scores[2] = P4();
				T6Scores[3] = P12();

				int best = bestProgram(T6Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[5] = { A22, T0, T2, A20, T4,  };

				float T7Scores[5];

				T7Scores[0] = P13();
				T7Scores[1] = P14();
				T7Scores[2] = P15();
				T7Scores[3] = P6();
				T7Scores[4] = P16();

				int best = bestProgram(T7Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[4] = { T5, A22, A23, T2,  };

				float T8Scores[4];

				T8Scores[0] = P17();
				T8Scores[1] = P18();
				T8Scores[2] = P19();
				T8Scores[3] = P15();

				int best = bestProgram(T8Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[3] = { T6, T0, T8,  };

				float T9Scores[3];

				T9Scores[0] = P20();
				T9Scores[1] = P14();
				T9Scores[2] = P21();

				int best = bestProgram(T9Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[4] = { T6, T8, A20, A20,  };

				float T10Scores[4];

				T10Scores[0] = P22();
				T10Scores[1] = P23();
				T10Scores[2] = P24();
				T10Scores[3] = P25();

				int best = bestProgram(T10Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { T7, T10, T2,  };

				float T11Scores[3];

				T11Scores[0] = P26();
				T11Scores[1] = P27();
				T11Scores[2] = P28();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[6] = { A20, T0, T7, T0, T9, T10,  };

				float T12Scores[6];

				T12Scores[0] = P29();
				T12Scores[1] = P30();
				T12Scores[2] = P31();
				T12Scores[3] = P32();
				T12Scores[4] = P33();
				T12Scores[5] = P34();

				int best = bestProgram(T12Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[2] = { T1, T11,  };

				float T13Scores[2];

				T13Scores[0] = P35();
				T13Scores[1] = P36();

				int best = bestProgram(T13Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[7] = { T3, T12, A20, T13, T10, T10, A25,  };

				float T14Scores[7];

				T14Scores[0] = P37();
				T14Scores[1] = P38();
				T14Scores[2] = P39();
				T14Scores[3] = P40();
				T14Scores[4] = P41();
				T14Scores[5] = P42();
				T14Scores[6] = P43();

				int best = bestProgram(T14Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[1] = { T14,  };

				float T15Scores[1];

				T15Scores[0] = P44();

				int best = bestProgram(T15Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[5] = { T15, T3, A25, A20, T9,  };

				float T16Scores[5];

				T16Scores[0] = P45();
				T16Scores[1] = P46();
				T16Scores[2] = P47();
				T16Scores[3] = P25();
				T16Scores[4] = P48();

				int best = bestProgram(T16Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[6] = { T3, T14, T16, T3, T9, T15,  };

				float T17Scores[6];

				T17Scores[0] = P49();
				T17Scores[1] = P50();
				T17Scores[2] = P51();
				T17Scores[3] = P46();
				T17Scores[4] = P33();
				T17Scores[5] = P45();

				int best = bestProgram(T17Scores, 6);
				currentVertex = next[best];
				break;
			}
		case A18: {
				actions[0] = 7;
				return;
			}
		case A19: {
				actions[0] = 8;
				return;
			}
		case A20: {
				actions[0] = 0;
				return;
			}
		case A21: {
				actions[0] = 5;
				return;
			}
		case A22: {
				actions[0] = 6;
				return;
			}
		case A23: {
				actions[0] = 2;
				return;
			}
		case A24: {
				actions[0] = 4;
				return;
			}
		case A25: {
				actions[0] = 1;
				return;
			}
		}
	}
}
