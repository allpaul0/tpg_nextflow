/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:38
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, A18, A19, A20, A21, A22, A23, A24, A25, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T17;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[3] = { A20, A21, A19,  };

				double T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A22, T0, A18,  };

				double T1Scores[3];

				T1Scores[0] = P3();
				T1Scores[1] = P4();
				T1Scores[2] = P5();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[4] = { A21, A22, A19, A20,  };

				double T2Scores[4];

				T2Scores[0] = P6();
				T2Scores[1] = P7();
				T2Scores[2] = P8();
				T2Scores[3] = P9();

				int best = bestProgram(T2Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[8] = { A19, T1, A18, A21, A20, T0, A19, T2,  };

				double T3Scores[8];

				T3Scores[0] = P10();
				T3Scores[1] = P11();
				T3Scores[2] = P12();
				T3Scores[3] = P13();
				T3Scores[4] = P14();
				T3Scores[5] = P15();
				T3Scores[6] = P16();
				T3Scores[7] = P17();

				int best = bestProgram(T3Scores, 8);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { A19, T1, T0,  };

				double T4Scores[3];

				T4Scores[0] = P10();
				T4Scores[1] = P18();
				T4Scores[2] = P15();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[7] = { T2, A18, A21, T1, T4, A19, A19,  };

				double T5Scores[7];

				T5Scores[0] = P19();
				T5Scores[1] = P20();
				T5Scores[2] = P21();
				T5Scores[3] = P22();
				T5Scores[4] = P23();
				T5Scores[5] = P16();
				T5Scores[6] = P24();

				int best = bestProgram(T5Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[1] = { T5,  };

				double T6Scores[1];

				T6Scores[0] = P25();

				int best = bestProgram(T6Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[1] = { A24,  };

				double T7Scores[1];

				T7Scores[0] = P26();

				int best = bestProgram(T7Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[4] = { A25, T3, A24, T5,  };

				double T8Scores[4];

				T8Scores[0] = P27();
				T8Scores[1] = P28();
				T8Scores[2] = P29();
				T8Scores[3] = P30();

				int best = bestProgram(T8Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[2] = { T7, T6,  };

				double T9Scores[2];

				T9Scores[0] = P31();
				T9Scores[1] = P32();

				int best = bestProgram(T9Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { T5, A23,  };

				double T10Scores[2];

				T10Scores[0] = P25();
				T10Scores[1] = P33();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[4] = { T3, T7, A23, T8,  };

				double T11Scores[4];

				T11Scores[0] = P34();
				T11Scores[1] = P31();
				T11Scores[2] = P35();
				T11Scores[3] = P36();

				int best = bestProgram(T11Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[3] = { T9, A23, T8,  };

				double T12Scores[3];

				T12Scores[0] = P37();
				T12Scores[1] = P35();
				T12Scores[2] = P38();

				int best = bestProgram(T12Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[4] = { T11, A23, T12, T5,  };

				double T13Scores[4];

				T13Scores[0] = P39();
				T13Scores[1] = P40();
				T13Scores[2] = P41();
				T13Scores[3] = P25();

				int best = bestProgram(T13Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[4] = { T12, T10, T5, A23,  };

				double T14Scores[4];

				T14Scores[0] = P41();
				T14Scores[1] = P42();
				T14Scores[2] = P25();
				T14Scores[3] = P43();

				int best = bestProgram(T14Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[1] = { T11,  };

				double T15Scores[1];

				T15Scores[0] = P44();

				int best = bestProgram(T15Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[5] = { T11, T13, A24, T5, A23,  };

				double T16Scores[5];

				T16Scores[0] = P45();
				T16Scores[1] = P46();
				T16Scores[2] = P47();
				T16Scores[3] = P48();
				T16Scores[4] = P49();

				int best = bestProgram(T16Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[5] = { T15, T14, T16, A23, T11,  };

				double T17Scores[5];

				T17Scores[0] = P50();
				T17Scores[1] = P51();
				T17Scores[2] = P52();
				T17Scores[3] = P53();
				T17Scores[4] = P54();

				int best = bestProgram(T17Scores, 5);
				currentVertex = next[best];
				break;
			}
		case A18: {
				actions[0] = 5;
				return;
			}
		case A19: {
				actions[0] = 6;
				return;
			}
		case A20: {
				actions[0] = 3;
				return;
			}
		case A21: {
				actions[0] = 4;
				return;
			}
		case A22: {
				actions[0] = 0;
				return;
			}
		case A23: {
				actions[0] = 7;
				return;
			}
		case A24: {
				actions[0] = 1;
				return;
			}
		case A25: {
				actions[0] = 2;
				return;
			}
		}
	}
}
