/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:27
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, A14, A15, A16, A17, A18, A19, A20, A21, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T13;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[1] = { A16,  };

				double T0Scores[1];

				T0Scores[0] = P0();

				int best = bestProgram(T0Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[7] = { A19, A15, A18, A18, A19, A14, T0,  };

				double T1Scores[7];

				T1Scores[0] = P1();
				T1Scores[1] = P2();
				T1Scores[2] = P3();
				T1Scores[3] = P4();
				T1Scores[4] = P5();
				T1Scores[5] = P6();
				T1Scores[6] = P7();

				int best = bestProgram(T1Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A17, A18, A14,  };

				double T2Scores[3];

				T2Scores[0] = P8();
				T2Scores[1] = P9();
				T2Scores[2] = P10();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { A14, A18, T1,  };

				double T3Scores[3];

				T3Scores[0] = P11();
				T3Scores[1] = P12();
				T3Scores[2] = P13();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[2] = { T1, T3,  };

				double T4Scores[2];

				T4Scores[0] = P13();
				T4Scores[1] = P14();

				int best = bestProgram(T4Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[5] = { T1, T2, A18, T4, A18,  };

				double T5Scores[5];

				T5Scores[0] = P13();
				T5Scores[1] = P15();
				T5Scores[2] = P3();
				T5Scores[3] = P16();
				T5Scores[4] = P17();

				int best = bestProgram(T5Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[3] = { A18, T1, A20,  };

				double T6Scores[3];

				T6Scores[0] = P12();
				T6Scores[1] = P18();
				T6Scores[2] = P19();

				int best = bestProgram(T6Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { A17, A20, A18,  };

				double T7Scores[3];

				T7Scores[0] = P20();
				T7Scores[1] = P21();
				T7Scores[2] = P12();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { T1, T7, A20,  };

				double T8Scores[3];

				T8Scores[0] = P22();
				T8Scores[1] = P23();
				T8Scores[2] = P24();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[5] = { T3, T8, T6, A21, A20,  };

				double T9Scores[5];

				T9Scores[0] = P25();
				T9Scores[1] = P26();
				T9Scores[2] = P27();
				T9Scores[3] = P28();
				T9Scores[4] = P29();

				int best = bestProgram(T9Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[1] = { T8,  };

				double T10Scores[1];

				T10Scores[0] = P30();

				int best = bestProgram(T10Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[1] = { A20,  };

				double T11Scores[1];

				T11Scores[0] = P31();

				int best = bestProgram(T11Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[1] = { T11,  };

				double T12Scores[1];

				T12Scores[0] = P32();

				int best = bestProgram(T12Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[6] = { T9, T5, A21, T12, T10, A18,  };

				double T13Scores[6];

				T13Scores[0] = P33();
				T13Scores[1] = P34();
				T13Scores[2] = P28();
				T13Scores[3] = P35();
				T13Scores[4] = P36();
				T13Scores[5] = P37();

				int best = bestProgram(T13Scores, 6);
				currentVertex = next[best];
				break;
			}
		case A14: {
				actions[0] = 6;
				return;
			}
		case A15: {
				actions[0] = 7;
				return;
			}
		case A16: {
				actions[0] = 8;
				return;
			}
		case A17: {
				actions[0] = 0;
				return;
			}
		case A18: {
				actions[0] = 5;
				return;
			}
		case A19: {
				actions[0] = 4;
				return;
			}
		case A20: {
				actions[0] = 1;
				return;
			}
		case A21: {
				actions[0] = 2;
				return;
			}
		}
	}
}
