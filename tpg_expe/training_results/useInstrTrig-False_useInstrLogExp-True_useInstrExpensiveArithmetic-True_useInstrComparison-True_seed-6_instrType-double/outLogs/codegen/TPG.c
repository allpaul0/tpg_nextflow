/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:31
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, A11, A12, A13, A14, A15, A16, A17, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T10;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[1] = { A14,  };

				double T0Scores[1];

				T0Scores[0] = P0();

				int best = bestProgram(T0Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A13, A12, A14,  };

				double T1Scores[3];

				T1Scores[0] = P1();
				T1Scores[1] = P2();
				T1Scores[2] = P3();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[4] = { A15, A13, A11, A12,  };

				double T2Scores[4];

				T2Scores[0] = P4();
				T2Scores[1] = P5();
				T2Scores[2] = P6();
				T2Scores[3] = P7();

				int best = bestProgram(T2Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { T2, T0,  };

				double T3Scores[2];

				T3Scores[0] = P8();
				T3Scores[1] = P9();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[5] = { A16, T2, T1, A15, A11,  };

				double T4Scores[5];

				T4Scores[0] = P10();
				T4Scores[1] = P11();
				T4Scores[2] = P12();
				T4Scores[3] = P13();
				T4Scores[4] = P14();

				int best = bestProgram(T4Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { T2, T2,  };

				double T5Scores[2];

				T5Scores[0] = P15();
				T5Scores[1] = P16();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[8] = { T4, T1, T1, T2, A15, T2, A17, A15,  };

				double T6Scores[8];

				T6Scores[0] = P17();
				T6Scores[1] = P18();
				T6Scores[2] = P19();
				T6Scores[3] = P20();
				T6Scores[4] = P21();
				T6Scores[5] = P22();
				T6Scores[6] = P23();
				T6Scores[7] = P24();

				int best = bestProgram(T6Scores, 8);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[7] = { A15, T1, T2, T2, T5, T3, A16,  };

				double T7Scores[7];

				T7Scores[0] = P25();
				T7Scores[1] = P19();
				T7Scores[2] = P26();
				T7Scores[3] = P22();
				T7Scores[4] = P27();
				T7Scores[5] = P28();
				T7Scores[6] = P29();

				int best = bestProgram(T7Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { T6, A13, T1,  };

				double T8Scores[3];

				T8Scores[0] = P30();
				T8Scores[1] = P31();
				T8Scores[2] = P32();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[4] = { T6, T2, T8, A17,  };

				double T9Scores[4];

				T9Scores[0] = P33();
				T9Scores[1] = P34();
				T9Scores[2] = P35();
				T9Scores[3] = P36();

				int best = bestProgram(T9Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[10] = { A17, A13, T9, T8, A16, A12, T1, T6, T7, A16,  };

				double T10Scores[10];

				T10Scores[0] = P37();
				T10Scores[1] = P38();
				T10Scores[2] = P39();
				T10Scores[3] = P40();
				T10Scores[4] = P41();
				T10Scores[5] = P42();
				T10Scores[6] = P43();
				T10Scores[7] = P44();
				T10Scores[8] = P45();
				T10Scores[9] = P46();

				int best = bestProgram(T10Scores, 10);
				currentVertex = next[best];
				break;
			}
		case A11: {
				actions[0] = 5;
				return;
			}
		case A12: {
				actions[0] = 6;
				return;
			}
		case A13: {
				actions[0] = 0;
				return;
			}
		case A14: {
				actions[0] = 3;
				return;
			}
		case A15: {
				actions[0] = 4;
				return;
			}
		case A16: {
				actions[0] = 1;
				return;
			}
		case A17: {
				actions[0] = 2;
				return;
			}
		}
	}
}
