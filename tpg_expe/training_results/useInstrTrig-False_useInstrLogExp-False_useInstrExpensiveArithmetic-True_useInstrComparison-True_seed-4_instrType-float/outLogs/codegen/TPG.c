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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, A16, A17, A18, A19, A20, A21, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T15;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[7] = { A18, A16, A19, A20, A16, A17, A17,  };

				float T0Scores[7];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();
				T0Scores[3] = P3();
				T0Scores[4] = P4();
				T0Scores[5] = P5();
				T0Scores[6] = P6();

				int best = bestProgram(T0Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { T0, A20,  };

				float T1Scores[2];

				T1Scores[0] = P7();
				T1Scores[1] = P8();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[5] = { A18, A16, A20, A16, A21,  };

				float T2Scores[5];

				T2Scores[0] = P9();
				T2Scores[1] = P10();
				T2Scores[2] = P11();
				T2Scores[3] = P12();
				T2Scores[4] = P13();

				int best = bestProgram(T2Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[5] = { A16, A21, A18, A17, T1,  };

				float T3Scores[5];

				T3Scores[0] = P12();
				T3Scores[1] = P13();
				T3Scores[2] = P0();
				T3Scores[3] = P14();
				T3Scores[4] = P15();

				int best = bestProgram(T3Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { A17, T1, A16,  };

				float T4Scores[3];

				T4Scores[0] = P16();
				T4Scores[1] = P17();
				T4Scores[2] = P18();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[4] = { T2, A17, T3, A20,  };

				float T5Scores[4];

				T5Scores[0] = P19();
				T5Scores[1] = P20();
				T5Scores[2] = P21();
				T5Scores[3] = P8();

				int best = bestProgram(T5Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { T3, A17,  };

				float T6Scores[2];

				T6Scores[0] = P21();
				T6Scores[1] = P22();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[5] = { A18, T4, A20, T6, T2,  };

				float T7Scores[5];

				T7Scores[0] = P0();
				T7Scores[1] = P23();
				T7Scores[2] = P24();
				T7Scores[3] = P25();
				T7Scores[4] = P26();

				int best = bestProgram(T7Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { T5, A21, A17,  };

				float T8Scores[3];

				T8Scores[0] = P27();
				T8Scores[1] = P28();
				T8Scores[2] = P29();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T5,  };

				float T9Scores[1];

				T9Scores[0] = P30();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[7] = { A17, T3, A21, T8, A16, A17, T5,  };

				float T10Scores[7];

				T10Scores[0] = P31();
				T10Scores[1] = P32();
				T10Scores[2] = P33();
				T10Scores[3] = P34();
				T10Scores[4] = P35();
				T10Scores[5] = P36();
				T10Scores[6] = P30();

				int best = bestProgram(T10Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[1] = { T10,  };

				float T11Scores[1];

				T11Scores[0] = P37();

				int best = bestProgram(T11Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[4] = { A17, A21, A20, T1,  };

				float T12Scores[4];

				T12Scores[0] = P38();
				T12Scores[1] = P33();
				T12Scores[2] = P39();
				T12Scores[3] = P40();

				int best = bestProgram(T12Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[3] = { A20, T9, T11,  };

				float T13Scores[3];

				T13Scores[0] = P41();
				T13Scores[1] = P42();
				T13Scores[2] = P43();

				int best = bestProgram(T13Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[3] = { T7, T13, T12,  };

				float T14Scores[3];

				T14Scores[0] = P44();
				T14Scores[1] = P45();
				T14Scores[2] = P46();

				int best = bestProgram(T14Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[4] = { T1, T14, T5, T7,  };

				float T15Scores[4];

				T15Scores[0] = P47();
				T15Scores[1] = P48();
				T15Scores[2] = P49();
				T15Scores[3] = P50();

				int best = bestProgram(T15Scores, 4);
				currentVertex = next[best];
				break;
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
				actions[0] = 0;
				return;
			}
		case A19: {
				actions[0] = 8;
				return;
			}
		case A20: {
				actions[0] = 2;
				return;
			}
		case A21: {
				actions[0] = 1;
				return;
			}
		}
	}
}
