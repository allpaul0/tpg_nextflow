/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:25
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, A15, A16, A17, A18, A19, A20, A21, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T14;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[3] = { A15, A16, A17,  };

				double T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[4] = { A16, A15, A18, A17,  };

				double T1Scores[4];

				T1Scores[0] = P3();
				T1Scores[1] = P4();
				T1Scores[2] = P5();
				T1Scores[3] = P6();

				int best = bestProgram(T1Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[4] = { A18, A19, A17, A19,  };

				double T2Scores[4];

				T2Scores[0] = P7();
				T2Scores[1] = P8();
				T2Scores[2] = P9();
				T2Scores[3] = P10();

				int best = bestProgram(T2Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { T0, A20, A18,  };

				double T3Scores[3];

				T3Scores[0] = P11();
				T3Scores[1] = P12();
				T3Scores[2] = P13();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { A18, A19, A17,  };

				double T4Scores[3];

				T4Scores[0] = P14();
				T4Scores[1] = P8();
				T4Scores[2] = P15();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { T3,  };

				double T5Scores[1];

				T5Scores[0] = P16();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[4] = { A19, A17, T1, T4,  };

				double T6Scores[4];

				T6Scores[0] = P17();
				T6Scores[1] = P18();
				T6Scores[2] = P19();
				T6Scores[3] = P20();

				int best = bestProgram(T6Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[4] = { T2, A19, T5, A20,  };

				double T7Scores[4];

				T7Scores[0] = P21();
				T7Scores[1] = P22();
				T7Scores[2] = P23();
				T7Scores[3] = P24();

				int best = bestProgram(T7Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { A18,  };

				double T8Scores[1];

				T8Scores[0] = P25();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T7,  };

				double T9Scores[1];

				T9Scores[0] = P26();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { T8, T7,  };

				double T10Scores[2];

				T10Scores[0] = P27();
				T10Scores[1] = P26();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { T7, A21, T10,  };

				double T11Scores[3];

				T11Scores[0] = P28();
				T11Scores[1] = P29();
				T11Scores[2] = P30();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[4] = { T7, T9, T11, A20,  };

				double T12Scores[4];

				T12Scores[0] = P31();
				T12Scores[1] = P32();
				T12Scores[2] = P33();
				T12Scores[3] = P34();

				int best = bestProgram(T12Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[2] = { T11, T12,  };

				double T13Scores[2];

				T13Scores[0] = P35();
				T13Scores[1] = P36();

				int best = bestProgram(T13Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[5] = { A20, T13, T6, T7, A21,  };

				double T14Scores[5];

				T14Scores[0] = P37();
				T14Scores[1] = P38();
				T14Scores[2] = P39();
				T14Scores[3] = P31();
				T14Scores[4] = P29();

				int best = bestProgram(T14Scores, 5);
				currentVertex = next[best];
				break;
			}
		case A15: {
				actions[0] = 3;
				return;
			}
		case A16: {
				actions[0] = 4;
				return;
			}
		case A17: {
				actions[0] = 6;
				return;
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
