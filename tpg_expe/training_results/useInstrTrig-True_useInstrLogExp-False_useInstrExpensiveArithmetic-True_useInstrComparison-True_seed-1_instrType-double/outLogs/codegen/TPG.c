/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:30
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
				const enum vertices next[4] = { A13, A17, A16, A16,  };

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
				const enum vertices next[5] = { A16, A14, A15, A18, A13,  };

				double T1Scores[5];

				T1Scores[0] = P4();
				T1Scores[1] = P5();
				T1Scores[2] = P6();
				T1Scores[3] = P7();
				T1Scores[4] = P8();

				int best = bestProgram(T1Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[1] = { A13,  };

				double T2Scores[1];

				T2Scores[0] = P9();

				int best = bestProgram(T2Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[1] = { T0,  };

				double T3Scores[1];

				T3Scores[0] = P10();

				int best = bestProgram(T3Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[4] = { T3, T1, T2, A19,  };

				double T4Scores[4];

				T4Scores[0] = P11();
				T4Scores[1] = P12();
				T4Scores[2] = P13();
				T4Scores[3] = P14();

				int best = bestProgram(T4Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[6] = { A14, A17, T3, A13, T1, A17,  };

				double T5Scores[6];

				T5Scores[0] = P15();
				T5Scores[1] = P16();
				T5Scores[2] = P11();
				T5Scores[3] = P17();
				T5Scores[4] = P18();
				T5Scores[5] = P19();

				int best = bestProgram(T5Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[1] = { T1,  };

				double T6Scores[1];

				T6Scores[0] = P20();

				int best = bestProgram(T6Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[4] = { A13, A16, A14, T5,  };

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
				const enum vertices next[7] = { T7, T4, A14, T5, A14, T6, T6,  };

				double T8Scores[7];

				T8Scores[0] = P25();
				T8Scores[1] = P26();
				T8Scores[2] = P27();
				T8Scores[3] = P28();
				T8Scores[4] = P29();
				T8Scores[5] = P30();
				T8Scores[6] = P31();

				int best = bestProgram(T8Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[4] = { T7, A14, T4, T7,  };

				double T9Scores[4];

				T9Scores[0] = P32();
				T9Scores[1] = P33();
				T9Scores[2] = P26();
				T9Scores[3] = P34();

				int best = bestProgram(T9Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[1] = { T9,  };

				double T10Scores[1];

				T10Scores[0] = P35();

				int best = bestProgram(T10Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[4] = { T9, A19, A19, A14,  };

				double T11Scores[4];

				T11Scores[0] = P36();
				T11Scores[1] = P37();
				T11Scores[2] = P38();
				T11Scores[3] = P29();

				int best = bestProgram(T11Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[7] = { T10, A15, T8, T11, T3, T3, A14,  };

				double T12Scores[7];

				T12Scores[0] = P39();
				T12Scores[1] = P40();
				T12Scores[2] = P41();
				T12Scores[3] = P42();
				T12Scores[4] = P43();
				T12Scores[5] = P44();
				T12Scores[6] = P27();

				int best = bestProgram(T12Scores, 7);
				currentVertex = next[best];
				break;
			}
		case A13: {
				actions[0] = 5;
				return;
			}
		case A14: {
				actions[0] = 1;
				return;
			}
		case A15: {
				actions[0] = 4;
				return;
			}
		case A16: {
				actions[0] = 6;
				return;
			}
		case A17: {
				actions[0] = 0;
				return;
			}
		case A18: {
				actions[0] = 7;
				return;
			}
		case A19: {
				actions[0] = 2;
				return;
			}
		}
	}
}
