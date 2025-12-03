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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, A17, A18, A19, A20, A21, A22, A23, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T16;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[3] = { A17, A22, A18,  };

				float T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[4] = { A20, A22, A21, T0,  };

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
				const enum vertices next[4] = { A21, A18, T0, A20,  };

				float T2Scores[4];

				T2Scores[0] = P7();
				T2Scores[1] = P8();
				T2Scores[2] = P9();
				T2Scores[3] = P10();

				int best = bestProgram(T2Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { A21, T2,  };

				float T3Scores[2];

				T3Scores[0] = P11();
				T3Scores[1] = P12();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[4] = { T3, A20, A21, A20,  };

				float T4Scores[4];

				T4Scores[0] = P13();
				T4Scores[1] = P14();
				T4Scores[2] = P15();
				T4Scores[3] = P16();

				int best = bestProgram(T4Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[3] = { T2, T4, A20,  };

				float T5Scores[3];

				T5Scores[0] = P17();
				T5Scores[1] = P18();
				T5Scores[2] = P19();

				int best = bestProgram(T5Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[1] = { T2,  };

				float T6Scores[1];

				T6Scores[0] = P20();

				int best = bestProgram(T6Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T2, T4, A23,  };

				float T7Scores[3];

				T7Scores[0] = P17();
				T7Scores[1] = P18();
				T7Scores[2] = P21();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[6] = { T4, A20, A23, A21, T2, A17,  };

				float T8Scores[6];

				T8Scores[0] = P22();
				T8Scores[1] = P23();
				T8Scores[2] = P21();
				T8Scores[3] = P15();
				T8Scores[4] = P24();
				T8Scores[5] = P25();

				int best = bestProgram(T8Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[8] = { A20, A21, T4, A23, T2, T8, T6, A20,  };

				float T9Scores[8];

				T9Scores[0] = P26();
				T9Scores[1] = P5();
				T9Scores[2] = P27();
				T9Scores[3] = P21();
				T9Scores[4] = P28();
				T9Scores[5] = P29();
				T9Scores[6] = P30();
				T9Scores[7] = P31();

				int best = bestProgram(T9Scores, 8);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[5] = { A22, A17, A20, T5, T9,  };

				float T10Scores[5];

				T10Scores[0] = P32();
				T10Scores[1] = P33();
				T10Scores[2] = P34();
				T10Scores[3] = P35();
				T10Scores[4] = P36();

				int best = bestProgram(T10Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[2] = { T9, A23,  };

				float T11Scores[2];

				T11Scores[0] = P37();
				T11Scores[1] = P21();

				int best = bestProgram(T11Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[5] = { T5, T10, T7, A23, A19,  };

				float T12Scores[5];

				T12Scores[0] = P38();
				T12Scores[1] = P39();
				T12Scores[2] = P40();
				T12Scores[3] = P41();
				T12Scores[4] = P42();

				int best = bestProgram(T12Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[3] = { T4, T12, A23,  };

				float T13Scores[3];

				T13Scores[0] = P43();
				T13Scores[1] = P44();
				T13Scores[2] = P21();

				int best = bestProgram(T13Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[4] = { T12, A17, A17, A20,  };

				float T14Scores[4];

				T14Scores[0] = P45();
				T14Scores[1] = P33();
				T14Scores[2] = P46();
				T14Scores[3] = P47();

				int best = bestProgram(T14Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[5] = { T13, T11, T1, T10, T4,  };

				float T15Scores[5];

				T15Scores[0] = P48();
				T15Scores[1] = P49();
				T15Scores[2] = P50();
				T15Scores[3] = P51();
				T15Scores[4] = P52();

				int best = bestProgram(T15Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[6] = { T15, A22, T12, T14, A23, A21,  };

				float T16Scores[6];

				T16Scores[0] = P53();
				T16Scores[1] = P54();
				T16Scores[2] = P55();
				T16Scores[3] = P56();
				T16Scores[4] = P57();
				T16Scores[5] = P58();

				int best = bestProgram(T16Scores, 6);
				currentVertex = next[best];
				break;
			}
		case A17: {
				actions[0] = 0;
				return;
			}
		case A18: {
				actions[0] = 4;
				return;
			}
		case A19: {
				actions[0] = 1;
				return;
			}
		case A20: {
				actions[0] = 6;
				return;
			}
		case A21: {
				actions[0] = 5;
				return;
			}
		case A22: {
				actions[0] = 7;
				return;
			}
		case A23: {
				actions[0] = 2;
				return;
			}
		}
	}
}
