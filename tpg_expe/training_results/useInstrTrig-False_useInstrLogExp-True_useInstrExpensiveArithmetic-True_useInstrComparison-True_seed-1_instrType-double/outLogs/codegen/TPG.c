/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:24
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, A16, A17, A18, A19, A20, A21, A22, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T15;
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
				const enum vertices next[2] = { A17, A19,  };

				double T1Scores[2];

				T1Scores[0] = P1();
				T1Scores[1] = P2();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[2] = { T0, A20,  };

				double T2Scores[2];

				T2Scores[0] = P3();
				T2Scores[1] = P4();

				int best = bestProgram(T2Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { A20, A16,  };

				double T3Scores[2];

				T3Scores[0] = P5();
				T3Scores[1] = P6();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[1] = { A22,  };

				double T4Scores[1];

				T4Scores[0] = P7();

				int best = bestProgram(T4Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[4] = { A21, T2, A18, A17,  };

				double T5Scores[4];

				T5Scores[0] = P8();
				T5Scores[1] = P9();
				T5Scores[2] = P10();
				T5Scores[3] = P11();

				int best = bestProgram(T5Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[4] = { A21, T4, A18, A21,  };

				double T6Scores[4];

				T6Scores[0] = P12();
				T6Scores[1] = P13();
				T6Scores[2] = P10();
				T6Scores[3] = P14();

				int best = bestProgram(T6Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { A17, T5, T3,  };

				double T7Scores[3];

				T7Scores[0] = P11();
				T7Scores[1] = P15();
				T7Scores[2] = P16();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[2] = { T6, T5,  };

				double T8Scores[2];

				T8Scores[0] = P17();
				T8Scores[1] = P15();

				int best = bestProgram(T8Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[3] = { A22, T5, T3,  };

				double T9Scores[3];

				T9Scores[0] = P18();
				T9Scores[1] = P19();
				T9Scores[2] = P20();

				int best = bestProgram(T9Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { T6, T5,  };

				double T10Scores[2];

				T10Scores[0] = P21();
				T10Scores[1] = P22();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { T8, T1, A16,  };

				double T11Scores[3];

				T11Scores[0] = P23();
				T11Scores[1] = P24();
				T11Scores[2] = P25();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[3] = { T10, T11, T7,  };

				double T12Scores[3];

				T12Scores[0] = P26();
				T12Scores[1] = P27();
				T12Scores[2] = P28();

				int best = bestProgram(T12Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[4] = { T7, T10, T5, T12,  };

				double T13Scores[4];

				T13Scores[0] = P28();
				T13Scores[1] = P29();
				T13Scores[2] = P30();
				T13Scores[3] = P31();

				int best = bestProgram(T13Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[3] = { T8, A18, A17,  };

				double T14Scores[3];

				T14Scores[0] = P32();
				T14Scores[1] = P10();
				T14Scores[2] = P33();

				int best = bestProgram(T14Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[5] = { T7, T13, T9, T14, T1,  };

				double T15Scores[5];

				T15Scores[0] = P28();
				T15Scores[1] = P34();
				T15Scores[2] = P35();
				T15Scores[3] = P36();
				T15Scores[4] = P37();

				int best = bestProgram(T15Scores, 5);
				currentVertex = next[best];
				break;
			}
		case A16: {
				actions[0] = 4;
				return;
			}
		case A17: {
				actions[0] = 1;
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
				actions[0] = 0;
				return;
			}
		case A21: {
				actions[0] = 6;
				return;
			}
		case A22: {
				actions[0] = 7;
				return;
			}
		}
	}
}
