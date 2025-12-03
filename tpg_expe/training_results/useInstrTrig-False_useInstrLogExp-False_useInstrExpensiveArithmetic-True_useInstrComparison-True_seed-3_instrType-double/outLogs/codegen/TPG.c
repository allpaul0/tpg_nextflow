/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:23
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
				const enum vertices next[3] = { A16, A17, A16,  };

				double T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[5] = { A19, A18, A15, T0, A17,  };

				double T1Scores[5];

				T1Scores[0] = P3();
				T1Scores[1] = P4();
				T1Scores[2] = P5();
				T1Scores[3] = P6();
				T1Scores[4] = P7();

				int best = bestProgram(T1Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[5] = { A20, A15, A17, A19, A19,  };

				double T2Scores[5];

				T2Scores[0] = P8();
				T2Scores[1] = P9();
				T2Scores[2] = P10();
				T2Scores[3] = P11();
				T2Scores[4] = P12();

				int best = bestProgram(T2Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[5] = { A17, A20, A15, A16, A18,  };

				double T3Scores[5];

				T3Scores[0] = P13();
				T3Scores[1] = P14();
				T3Scores[2] = P15();
				T3Scores[3] = P16();
				T3Scores[4] = P17();

				int best = bestProgram(T3Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[1] = { T3,  };

				double T4Scores[1];

				T4Scores[0] = P18();

				int best = bestProgram(T4Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[3] = { T3, A17, T2,  };

				double T5Scores[3];

				T5Scores[0] = P18();
				T5Scores[1] = P19();
				T5Scores[2] = P20();

				int best = bestProgram(T5Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[2] = { A17, T2,  };

				double T6Scores[2];

				T6Scores[0] = P21();
				T6Scores[1] = P20();

				int best = bestProgram(T6Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T3, A17, T2,  };

				double T7Scores[3];

				T7Scores[0] = P18();
				T7Scores[1] = P21();
				T7Scores[2] = P22();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[4] = { T4, A21, T6, T3,  };

				double T8Scores[4];

				T8Scores[0] = P23();
				T8Scores[1] = P24();
				T8Scores[2] = P25();
				T8Scores[3] = P18();

				int best = bestProgram(T8Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[3] = { A21, A20, T7,  };

				double T9Scores[3];

				T9Scores[0] = P24();
				T9Scores[1] = P26();
				T9Scores[2] = P27();

				int best = bestProgram(T9Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { T6, T5, T8,  };

				double T10Scores[3];

				T10Scores[0] = P28();
				T10Scores[1] = P29();
				T10Scores[2] = P30();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[1] = { T9,  };

				double T11Scores[1];

				T11Scores[0] = P31();

				int best = bestProgram(T11Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[3] = { T9, T1, T10,  };

				double T12Scores[3];

				T12Scores[0] = P32();
				T12Scores[1] = P33();
				T12Scores[2] = P34();

				int best = bestProgram(T12Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[5] = { T10, T11, T1, T1, T10,  };

				double T13Scores[5];

				T13Scores[0] = P35();
				T13Scores[1] = P36();
				T13Scores[2] = P37();
				T13Scores[3] = P38();
				T13Scores[4] = P39();

				int best = bestProgram(T13Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[6] = { T9, T12, T10, T10, T1, T13,  };

				double T14Scores[6];

				T14Scores[0] = P40();
				T14Scores[1] = P41();
				T14Scores[2] = P42();
				T14Scores[3] = P43();
				T14Scores[4] = P44();
				T14Scores[5] = P45();

				int best = bestProgram(T14Scores, 6);
				currentVertex = next[best];
				break;
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
				actions[0] = 4;
				return;
			}
		case A18: {
				actions[0] = 0;
				return;
			}
		case A19: {
				actions[0] = 7;
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
