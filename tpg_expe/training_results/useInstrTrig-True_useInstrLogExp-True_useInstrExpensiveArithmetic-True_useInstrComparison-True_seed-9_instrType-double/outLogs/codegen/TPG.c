/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:39
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
				const enum vertices next[2] = { A16, A17,  };

				double T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A18, A19,  };

				double T1Scores[2];

				T1Scores[0] = P2();
				T1Scores[1] = P3();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[4] = { A16, A17, A21, A19,  };

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
				const enum vertices next[6] = { A21, A19, A19, A20, T0, T2,  };

				double T3Scores[6];

				T3Scores[0] = P8();
				T3Scores[1] = P9();
				T3Scores[2] = P10();
				T3Scores[3] = P11();
				T3Scores[4] = P12();
				T3Scores[5] = P13();

				int best = bestProgram(T3Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[1] = { T3,  };

				double T4Scores[1];

				T4Scores[0] = P14();

				int best = bestProgram(T4Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[3] = { A22, T3, T1,  };

				double T5Scores[3];

				T5Scores[0] = P15();
				T5Scores[1] = P16();
				T5Scores[2] = P17();

				int best = bestProgram(T5Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[5] = { A21, T0, T4, T1, A22,  };

				double T6Scores[5];

				T6Scores[0] = P18();
				T6Scores[1] = P19();
				T6Scores[2] = P20();
				T6Scores[3] = P21();
				T6Scores[4] = P22();

				int best = bestProgram(T6Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T0, T4, A21,  };

				double T7Scores[3];

				T7Scores[0] = P23();
				T7Scores[1] = P24();
				T7Scores[2] = P25();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[5] = { T0, A22, A21, T4, T1,  };

				double T8Scores[5];

				T8Scores[0] = P26();
				T8Scores[1] = P15();
				T8Scores[2] = P18();
				T8Scores[3] = P27();
				T8Scores[4] = P28();

				int best = bestProgram(T8Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[4] = { A22, T0, T1, T8,  };

				double T9Scores[4];

				T9Scores[0] = P22();
				T9Scores[1] = P23();
				T9Scores[2] = P29();
				T9Scores[3] = P30();

				int best = bestProgram(T9Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { T9, T7, A21,  };

				double T10Scores[3];

				T10Scores[0] = P31();
				T10Scores[1] = P32();
				T10Scores[2] = P18();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[2] = { T10, T8,  };

				double T11Scores[2];

				T11Scores[0] = P33();
				T11Scores[1] = P30();

				int best = bestProgram(T11Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[4] = { T6, T9, T4, T5,  };

				double T12Scores[4];

				T12Scores[0] = P34();
				T12Scores[1] = P35();
				T12Scores[2] = P36();
				T12Scores[3] = P37();

				int best = bestProgram(T12Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[2] = { T12, T10,  };

				double T13Scores[2];

				T13Scores[0] = P38();
				T13Scores[1] = P39();

				int best = bestProgram(T13Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[5] = { T10, T11, T12, T13, T5,  };

				double T14Scores[5];

				T14Scores[0] = P40();
				T14Scores[1] = P41();
				T14Scores[2] = P38();
				T14Scores[3] = P42();
				T14Scores[4] = P43();

				int best = bestProgram(T14Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[4] = { T13, T5, T14, T0,  };

				double T15Scores[4];

				T15Scores[0] = P44();
				T15Scores[1] = P43();
				T15Scores[2] = P45();
				T15Scores[3] = P19();

				int best = bestProgram(T15Scores, 4);
				currentVertex = next[best];
				break;
			}
		case A16: {
				actions[0] = 5;
				return;
			}
		case A17: {
				actions[0] = 6;
				return;
			}
		case A18: {
				actions[0] = 8;
				return;
			}
		case A19: {
				actions[0] = 0;
				return;
			}
		case A20: {
				actions[0] = 7;
				return;
			}
		case A21: {
				actions[0] = 2;
				return;
			}
		case A22: {
				actions[0] = 4;
				return;
			}
		}
	}
}
