/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:26
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, A13, A14, A15, A16, A17, A18, A19, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T12;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[4] = { A16, A17, A14, A13,  };

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
				const enum vertices next[1] = { A16,  };

				double T1Scores[1];

				T1Scores[0] = P4();

				int best = bestProgram(T1Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A14, A17, A13,  };

				double T2Scores[3];

				T2Scores[0] = P2();
				T2Scores[1] = P5();
				T2Scores[2] = P3();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[6] = { A15, A13, T0, A14, A14, A16,  };

				double T3Scores[6];

				T3Scores[0] = P6();
				T3Scores[1] = P7();
				T3Scores[2] = P8();
				T3Scores[3] = P9();
				T3Scores[4] = P10();
				T3Scores[5] = P11();

				int best = bestProgram(T3Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { T3, A18, T0,  };

				double T4Scores[3];

				T4Scores[0] = P12();
				T4Scores[1] = P13();
				T4Scores[2] = P14();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[5] = { T0, T3, A18, A14, A18,  };

				double T5Scores[5];

				T5Scores[0] = P15();
				T5Scores[1] = P16();
				T5Scores[2] = P13();
				T5Scores[3] = P17();
				T5Scores[4] = P18();

				int best = bestProgram(T5Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[5] = { A18, T0, T1, T0, A18,  };

				double T6Scores[5];

				T6Scores[0] = P19();
				T6Scores[1] = P20();
				T6Scores[2] = P21();
				T6Scores[3] = P22();
				T6Scores[4] = P23();

				int best = bestProgram(T6Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[2] = { T4, T5,  };

				double T7Scores[2];

				T7Scores[0] = P24();
				T7Scores[1] = P25();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[2] = { T6, T2,  };

				double T8Scores[2];

				T8Scores[0] = P26();
				T8Scores[1] = P27();

				int best = bestProgram(T8Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[5] = { T6, A18, T2, A18, A17,  };

				double T9Scores[5];

				T9Scores[0] = P28();
				T9Scores[1] = P29();
				T9Scores[2] = P30();
				T9Scores[3] = P31();
				T9Scores[4] = P32();

				int best = bestProgram(T9Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { T2, A19,  };

				double T10Scores[2];

				T10Scores[0] = P33();
				T10Scores[1] = P34();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[5] = { A13, T8, T9, T9, T0,  };

				double T11Scores[5];

				T11Scores[0] = P35();
				T11Scores[1] = P36();
				T11Scores[2] = P37();
				T11Scores[3] = P38();
				T11Scores[4] = P15();

				int best = bestProgram(T11Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[5] = { T11, T6, T10, A19, T7,  };

				double T12Scores[5];

				T12Scores[0] = P39();
				T12Scores[1] = P28();
				T12Scores[2] = P40();
				T12Scores[3] = P41();
				T12Scores[4] = P42();

				int best = bestProgram(T12Scores, 5);
				currentVertex = next[best];
				break;
			}
		case A13: {
				actions[0] = 5;
				return;
			}
		case A14: {
				actions[0] = 6;
				return;
			}
		case A15: {
				actions[0] = 8;
				return;
			}
		case A16: {
				actions[0] = 4;
				return;
			}
		case A17: {
				actions[0] = 0;
				return;
			}
		case A18: {
				actions[0] = 1;
				return;
			}
		case A19: {
				actions[0] = 2;
				return;
			}
		}
	}
}
