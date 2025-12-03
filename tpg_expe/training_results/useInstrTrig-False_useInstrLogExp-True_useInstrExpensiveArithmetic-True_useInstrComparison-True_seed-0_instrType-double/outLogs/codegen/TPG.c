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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, A13, A14, A15, A16, A17, A18, A19, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T12;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[4] = { A13, A14, A15, A16,  };

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
				const enum vertices next[4] = { A14, A14, A16, A13,  };

				double T1Scores[4];

				T1Scores[0] = P4();
				T1Scores[1] = P5();
				T1Scores[2] = P6();
				T1Scores[3] = P0();

				int best = bestProgram(T1Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[5] = { A17, T0, A18, T1, A13,  };

				double T2Scores[5];

				T2Scores[0] = P7();
				T2Scores[1] = P8();
				T2Scores[2] = P9();
				T2Scores[3] = P10();
				T2Scores[4] = P11();

				int best = bestProgram(T2Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[5] = { A13, T0, A17, A16, A18,  };

				double T3Scores[5];

				T3Scores[0] = P12();
				T3Scores[1] = P13();
				T3Scores[2] = P14();
				T3Scores[3] = P15();
				T3Scores[4] = P16();

				int best = bestProgram(T3Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[2] = { T2, T3,  };

				double T4Scores[2];

				T4Scores[0] = P17();
				T4Scores[1] = P18();

				int best = bestProgram(T4Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[2] = { T2, T3,  };

				double T5Scores[2];

				T5Scores[0] = P17();
				T5Scores[1] = P19();

				int best = bestProgram(T5Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[6] = { A17, A14, T3, A18, T4, A13,  };

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
				const enum vertices next[2] = { T6, A13,  };

				double T7Scores[2];

				T7Scores[0] = P26();
				T7Scores[1] = P27();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[3] = { T6, A18, A19,  };

				double T8Scores[3];

				T8Scores[0] = P28();
				T8Scores[1] = P29();
				T8Scores[2] = P30();

				int best = bestProgram(T8Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T8,  };

				double T9Scores[1];

				T9Scores[0] = P31();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[4] = { T7, T9, A18, T2,  };

				double T10Scores[4];

				T10Scores[0] = P32();
				T10Scores[1] = P33();
				T10Scores[2] = P34();
				T10Scores[3] = P35();

				int best = bestProgram(T10Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[1] = { T10,  };

				double T11Scores[1];

				T11Scores[0] = P36();

				int best = bestProgram(T11Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[8] = { T6, A18, T11, T2, A19, T5, A19, A16,  };

				double T12Scores[8];

				T12Scores[0] = P37();
				T12Scores[1] = P38();
				T12Scores[2] = P39();
				T12Scores[3] = P40();
				T12Scores[4] = P41();
				T12Scores[5] = P42();
				T12Scores[6] = P43();
				T12Scores[7] = P44();

				int best = bestProgram(T12Scores, 8);
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
				actions[0] = 7;
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
