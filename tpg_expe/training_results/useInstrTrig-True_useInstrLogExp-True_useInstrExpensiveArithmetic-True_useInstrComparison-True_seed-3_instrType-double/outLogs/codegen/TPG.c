/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:15
 * With the CodeGen::TPGGenerationEngine.
 */

#include "TPG.h"

int bestProgram(double *results, int nb) {
	int bestProgram = 0;
	double bestScore = (isnan(results[0]))? -INFINITY : results[0];
	for (int i = 1; i < nb; i++) {
		double challengerScore = (isnan(results[i]))? -INFINITY : results[i];
		if (challengerScore >= bestScore) {
			bestProgram = i;
			bestScore = challengerScore;
		}
	}
	return bestProgram;
}

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, A12, A13, A14, A15, A16, A17, A18, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T11;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[3] = { A12, A13, A13,  };

				double T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[6] = { A14, A12, A15, A12, A16, A12,  };

				double T1Scores[6];

				T1Scores[0] = P3();
				T1Scores[1] = P4();
				T1Scores[2] = P5();
				T1Scores[3] = P6();
				T1Scores[4] = P7();
				T1Scores[5] = P8();

				int best = bestProgram(T1Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[5] = { A12, T0, A17, A14, A12,  };

				double T2Scores[5];

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
				const enum vertices next[1] = { A12,  };

				double T3Scores[1];

				T3Scores[0] = P9();

				int best = bestProgram(T3Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[4] = { A15, A16, A14, T2,  };

				double T4Scores[4];

				T4Scores[0] = P14();
				T4Scores[1] = P15();
				T4Scores[2] = P12();
				T4Scores[3] = P16();

				int best = bestProgram(T4Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[4] = { A17, T3, A15, A14,  };

				double T5Scores[4];

				T5Scores[0] = P17();
				T5Scores[1] = P18();
				T5Scores[2] = P19();
				T5Scores[3] = P12();

				int best = bestProgram(T5Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[6] = { T1, T4, A15, A18, A17, A13,  };

				double T6Scores[6];

				T6Scores[0] = P20();
				T6Scores[1] = P21();
				T6Scores[2] = P22();
				T6Scores[3] = P23();
				T6Scores[4] = P24();
				T6Scores[5] = P25();

				int best = bestProgram(T6Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T1, T4, A15,  };

				double T7Scores[3];

				T7Scores[0] = P26();
				T7Scores[1] = P21();
				T7Scores[2] = P22();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { T5,  };

				double T8Scores[1];

				T8Scores[0] = P27();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[5] = { A17, T8, A14, A18, A15,  };

				double T9Scores[5];

				T9Scores[0] = P28();
				T9Scores[1] = P29();
				T9Scores[2] = P30();
				T9Scores[3] = P31();
				T9Scores[4] = P22();

				int best = bestProgram(T9Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[1] = { T9,  };

				double T10Scores[1];

				T10Scores[0] = P32();

				int best = bestProgram(T10Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[5] = { T7, T10, A13, T6, T1,  };

				double T11Scores[5];

				T11Scores[0] = P33();
				T11Scores[1] = P34();
				T11Scores[2] = P35();
				T11Scores[3] = P36();
				T11Scores[4] = P37();

				int best = bestProgram(T11Scores, 5);
				currentVertex = next[best];
				break;
			}
		case A12: {
				actions[0] = 0;
				return;
			}
		case A13: {
				actions[0] = 4;
				return;
			}
		case A14: {
				actions[0] = 3;
				return;
			}
		case A15: {
				actions[0] = 5;
				return;
			}
		case A16: {
				actions[0] = 6;
				return;
			}
		case A17: {
				actions[0] = 1;
				return;
			}
		case A18: {
				actions[0] = 7;
				return;
			}
		}
	}
}
