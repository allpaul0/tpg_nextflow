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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, A15, A16, A17, A18, A19, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T14;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A15, A16,  };

				double T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[1] = { T0,  };

				double T1Scores[1];

				T1Scores[0] = P2();

				int best = bestProgram(T1Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A17, A16, A15,  };

				double T2Scores[3];

				T2Scores[0] = P3();
				T2Scores[1] = P4();
				T2Scores[2] = P5();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { T2, A18, A19,  };

				double T3Scores[3];

				T3Scores[0] = P6();
				T3Scores[1] = P7();
				T3Scores[2] = P8();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[1] = { T2,  };

				double T4Scores[1];

				T4Scores[0] = P9();

				int best = bestProgram(T4Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[4] = { A19, A16, A18, T2,  };

				double T5Scores[4];

				T5Scores[0] = P10();
				T5Scores[1] = P1();
				T5Scores[2] = P11();
				T5Scores[3] = P6();

				int best = bestProgram(T5Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[3] = { T4, A18, A17,  };

				double T6Scores[3];

				T6Scores[0] = P12();
				T6Scores[1] = P13();
				T6Scores[2] = P14();

				int best = bestProgram(T6Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[2] = { A15, T3,  };

				double T7Scores[2];

				T7Scores[0] = P15();
				T7Scores[1] = P16();

				int best = bestProgram(T7Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[2] = { T3, T6,  };

				double T8Scores[2];

				T8Scores[0] = P17();
				T8Scores[1] = P18();

				int best = bestProgram(T8Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[5] = { T0, T3, T5, T8, A16,  };

				double T9Scores[5];

				T9Scores[0] = P19();
				T9Scores[1] = P20();
				T9Scores[2] = P21();
				T9Scores[3] = P22();
				T9Scores[4] = P23();

				int best = bestProgram(T9Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { T6, A16, T3,  };

				double T10Scores[3];

				T10Scores[0] = P18();
				T10Scores[1] = P24();
				T10Scores[2] = P25();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { T3, A19, T10,  };

				double T11Scores[3];

				T11Scores[0] = P26();
				T11Scores[1] = P27();
				T11Scores[2] = P28();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[6] = { T0, T3, T10, T5, T3, A19,  };

				double T12Scores[6];

				T12Scores[0] = P19();
				T12Scores[1] = P29();
				T12Scores[2] = P28();
				T12Scores[3] = P21();
				T12Scores[4] = P30();
				T12Scores[5] = P31();

				int best = bestProgram(T12Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[3] = { A16, T12, T5,  };

				double T13Scores[3];

				T13Scores[0] = P32();
				T13Scores[1] = P33();
				T13Scores[2] = P34();

				int best = bestProgram(T13Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[10] = { T5, T11, T9, T7, T3, T1, A16, T13, A16, A17,  };

				double T14Scores[10];

				T14Scores[0] = P35();
				T14Scores[1] = P36();
				T14Scores[2] = P37();
				T14Scores[3] = P38();
				T14Scores[4] = P39();
				T14Scores[5] = P40();
				T14Scores[6] = P41();
				T14Scores[7] = P42();
				T14Scores[8] = P43();
				T14Scores[9] = P44();

				int best = bestProgram(T14Scores, 10);
				currentVertex = next[best];
				break;
			}
		case A15: {
				actions[0] = 4;
				return;
			}
		case A16: {
				actions[0] = 0;
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
				actions[0] = 1;
				return;
			}
		}
	}
}
