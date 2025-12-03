/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:33
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, A18, A19, A20, A21, A22, A23, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T17;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A18, A20,  };

				double T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[1] = { A21,  };

				double T1Scores[1];

				T1Scores[0] = P2();

				int best = bestProgram(T1Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[5] = { T0, A19, A21, A20, A20,  };

				double T2Scores[5];

				T2Scores[0] = P3();
				T2Scores[1] = P4();
				T2Scores[2] = P5();
				T2Scores[3] = P1();
				T2Scores[4] = P6();

				int best = bestProgram(T2Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { T0, A20, T1,  };

				double T3Scores[3];

				T3Scores[0] = P3();
				T3Scores[1] = P7();
				T3Scores[2] = P8();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[2] = { A21, T2,  };

				double T4Scores[2];

				T4Scores[0] = P9();
				T4Scores[1] = P10();

				int best = bestProgram(T4Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { T2,  };

				double T5Scores[1];

				T5Scores[0] = P11();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[6] = { T4, T2, A18, A20, T5, A22,  };

				double T6Scores[6];

				T6Scores[0] = P12();
				T6Scores[1] = P11();
				T6Scores[2] = P13();
				T6Scores[3] = P14();
				T6Scores[4] = P15();
				T6Scores[5] = P16();

				int best = bestProgram(T6Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[6] = { T6, A22, A23, A20, T3, A20,  };

				double T7Scores[6];

				T7Scores[0] = P17();
				T7Scores[1] = P18();
				T7Scores[2] = P19();
				T7Scores[3] = P20();
				T7Scores[4] = P21();
				T7Scores[5] = P1();

				int best = bestProgram(T7Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { T7,  };

				double T8Scores[1];

				T8Scores[0] = P22();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T4,  };

				double T9Scores[1];

				T9Scores[0] = P23();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[4] = { T8, T4, A22, T6,  };

				double T10Scores[4];

				T10Scores[0] = P24();
				T10Scores[1] = P23();
				T10Scores[2] = P25();
				T10Scores[3] = P26();

				int best = bestProgram(T10Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { T9, A22, T8,  };

				double T11Scores[3];

				T11Scores[0] = P27();
				T11Scores[1] = P28();
				T11Scores[2] = P29();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[4] = { A22, T4, A22, T2,  };

				double T12Scores[4];

				T12Scores[0] = P25();
				T12Scores[1] = P30();
				T12Scores[2] = P31();
				T12Scores[3] = P10();

				int best = bestProgram(T12Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[4] = { T8, A22, T4, T6,  };

				double T13Scores[4];

				T13Scores[0] = P32();
				T13Scores[1] = P33();
				T13Scores[2] = P34();
				T13Scores[3] = P35();

				int best = bestProgram(T13Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[1] = { T12,  };

				double T14Scores[1];

				T14Scores[0] = P36();

				int best = bestProgram(T14Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[3] = { T14, T3, A22,  };

				double T15Scores[3];

				T15Scores[0] = P37();
				T15Scores[1] = P38();
				T15Scores[2] = P39();

				int best = bestProgram(T15Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[4] = { A19, T11, T15, A19,  };

				double T16Scores[4];

				T16Scores[0] = P40();
				T16Scores[1] = P41();
				T16Scores[2] = P42();
				T16Scores[3] = P43();

				int best = bestProgram(T16Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[6] = { A19, T16, T13, T10, T6, T3,  };

				double T17Scores[6];

				T17Scores[0] = P44();
				T17Scores[1] = P45();
				T17Scores[2] = P46();
				T17Scores[3] = P47();
				T17Scores[4] = P48();
				T17Scores[5] = P49();

				int best = bestProgram(T17Scores, 6);
				currentVertex = next[best];
				break;
			}
		case A18: {
				actions[0] = 6;
				return;
			}
		case A19: {
				actions[0] = 4;
				return;
			}
		case A20: {
				actions[0] = 5;
				return;
			}
		case A21: {
				actions[0] = 0;
				return;
			}
		case A22: {
				actions[0] = 1;
				return;
			}
		case A23: {
				actions[0] = 2;
				return;
			}
		}
	}
}
