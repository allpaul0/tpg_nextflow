/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:21
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, A13, A14, A15, A16, A17, A18, A19, A20, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T12;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[4] = { A14, A14, A18, A15,  };

				double T0Scores[4];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();
				T0Scores[3] = P3();

				int best = bestProgram(T0Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[4] = { A16, A14, A13, A15,  };

				double T1Scores[4];

				T1Scores[0] = P4();
				T1Scores[1] = P0();
				T1Scores[2] = P5();
				T1Scores[3] = P6();

				int best = bestProgram(T1Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A14, A14, A16,  };

				double T2Scores[3];

				T2Scores[0] = P0();
				T2Scores[1] = P7();
				T2Scores[2] = P8();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { A14, T1, A15,  };

				double T3Scores[3];

				T3Scores[0] = P0();
				T3Scores[1] = P9();
				T3Scores[2] = P10();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[5] = { A14, A19, T2, A15, A16,  };

				double T4Scores[5];

				T4Scores[0] = P0();
				T4Scores[1] = P11();
				T4Scores[2] = P12();
				T4Scores[3] = P6();
				T4Scores[4] = P13();

				int best = bestProgram(T4Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[4] = { A19, A17, T0, T3,  };

				double T5Scores[4];

				T5Scores[0] = P14();
				T5Scores[1] = P15();
				T5Scores[2] = P16();
				T5Scores[3] = P17();

				int best = bestProgram(T5Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[4] = { T3, T5, A20, T0,  };

				double T6Scores[4];

				T6Scores[0] = P18();
				T6Scores[1] = P19();
				T6Scores[2] = P20();
				T6Scores[3] = P21();

				int best = bestProgram(T6Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T5, T0, T4,  };

				double T7Scores[3];

				T7Scores[0] = P22();
				T7Scores[1] = P23();
				T7Scores[2] = P24();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[2] = { A20, T7,  };

				double T8Scores[2];

				T8Scores[0] = P25();
				T8Scores[1] = P26();

				int best = bestProgram(T8Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[3] = { A18, T5, A17,  };

				double T9Scores[3];

				T9Scores[0] = P2();
				T9Scores[1] = P22();
				T9Scores[2] = P27();

				int best = bestProgram(T9Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { A20, T7, A18,  };

				double T10Scores[3];

				T10Scores[0] = P28();
				T10Scores[1] = P29();
				T10Scores[2] = P2();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[5] = { A19, T8, A20, T9, T6,  };

				double T11Scores[5];

				T11Scores[0] = P30();
				T11Scores[1] = P31();
				T11Scores[2] = P32();
				T11Scores[3] = P33();
				T11Scores[4] = P34();

				int best = bestProgram(T11Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[5] = { T6, T5, T11, T10, T8,  };

				double T12Scores[5];

				T12Scores[0] = P35();
				T12Scores[1] = P36();
				T12Scores[2] = P37();
				T12Scores[3] = P38();
				T12Scores[4] = P31();

				int best = bestProgram(T12Scores, 5);
				currentVertex = next[best];
				break;
			}
		case A13: {
				actions[0] = 3;
				return;
			}
		case A14: {
				actions[0] = 4;
				return;
			}
		case A15: {
				actions[0] = 0;
				return;
			}
		case A16: {
				actions[0] = 8;
				return;
			}
		case A17: {
				actions[0] = 5;
				return;
			}
		case A18: {
				actions[0] = 2;
				return;
			}
		case A19: {
				actions[0] = 6;
				return;
			}
		case A20: {
				actions[0] = 1;
				return;
			}
		}
	}
}
