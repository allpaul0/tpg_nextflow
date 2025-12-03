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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, A15, A16, A17, A18, A19, A20, A21, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T14;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[3] = { A15, A16, A17,  };

				float T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A19, A15, T0,  };

				float T1Scores[3];

				T1Scores[0] = P3();
				T1Scores[1] = P0();
				T1Scores[2] = P4();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[4] = { T0, A18, T1, A19,  };

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
				const enum vertices next[3] = { A20, A18, T0,  };

				float T3Scores[3];

				T3Scores[0] = P8();
				T3Scores[1] = P9();
				T3Scores[2] = P4();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[4] = { T3, A19, A20, T0,  };

				float T4Scores[4];

				T4Scores[0] = P10();
				T4Scores[1] = P11();
				T4Scores[2] = P12();
				T4Scores[3] = P4();

				int best = bestProgram(T4Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[5] = { A19, A20, T0, T2, A20,  };

				float T5Scores[5];

				T5Scores[0] = P11();
				T5Scores[1] = P13();
				T5Scores[2] = P4();
				T5Scores[3] = P14();
				T5Scores[4] = P12();

				int best = bestProgram(T5Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[1] = { T0,  };

				float T6Scores[1];

				T6Scores[0] = P15();

				int best = bestProgram(T6Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[7] = { A19, T1, A20, A21, A18, T0, T0,  };

				float T7Scores[7];

				T7Scores[0] = P11();
				T7Scores[1] = P16();
				T7Scores[2] = P17();
				T7Scores[3] = P18();
				T7Scores[4] = P19();
				T7Scores[5] = P20();
				T7Scores[6] = P21();

				int best = bestProgram(T7Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { A21,  };

				float T8Scores[1];

				T8Scores[0] = P22();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[3] = { T8, T0, T4,  };

				float T9Scores[3];

				T9Scores[0] = P23();
				T9Scores[1] = P4();
				T9Scores[2] = P24();

				int best = bestProgram(T9Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[4] = { T8, T5, T9, A21,  };

				float T10Scores[4];

				T10Scores[0] = P23();
				T10Scores[1] = P25();
				T10Scores[2] = P26();
				T10Scores[3] = P27();

				int best = bestProgram(T10Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[6] = { T7, A21, A18, T10, A21, T0,  };

				float T11Scores[6];

				T11Scores[0] = P28();
				T11Scores[1] = P29();
				T11Scores[2] = P30();
				T11Scores[3] = P31();
				T11Scores[4] = P32();
				T11Scores[5] = P33();

				int best = bestProgram(T11Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[3] = { A21, T6, T7,  };

				float T12Scores[3];

				T12Scores[0] = P29();
				T12Scores[1] = P34();
				T12Scores[2] = P35();

				int best = bestProgram(T12Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[9] = { A21, A18, T12, T0, T10, T0, A18, T1, T1,  };

				float T13Scores[9];

				T13Scores[0] = P36();
				T13Scores[1] = P37();
				T13Scores[2] = P38();
				T13Scores[3] = P39();
				T13Scores[4] = P40();
				T13Scores[5] = P41();
				T13Scores[6] = P42();
				T13Scores[7] = P43();
				T13Scores[8] = P44();

				int best = bestProgram(T13Scores, 9);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[4] = { T13, T11, A18, A21,  };

				float T14Scores[4];

				T14Scores[0] = P45();
				T14Scores[1] = P46();
				T14Scores[2] = P47();
				T14Scores[3] = P48();

				int best = bestProgram(T14Scores, 4);
				currentVertex = next[best];
				break;
			}
		case A15: {
				actions[0] = 4;
				return;
			}
		case A16: {
				actions[0] = 0;
				return;
			}
		case A17: {
				actions[0] = 6;
				return;
			}
		case A18: {
				actions[0] = 2;
				return;
			}
		case A19: {
				actions[0] = 5;
				return;
			}
		case A20: {
				actions[0] = 1;
				return;
			}
		case A21: {
				actions[0] = 7;
				return;
			}
		}
	}
}
