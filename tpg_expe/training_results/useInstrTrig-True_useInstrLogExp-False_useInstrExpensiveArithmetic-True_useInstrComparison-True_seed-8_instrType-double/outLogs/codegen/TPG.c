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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, A17, A18, A19, A20, A21, A22, A23, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T16;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[3] = { A21, A19, A22,  };

				double T0Scores[3];

				T0Scores[0] = P0();
				T0Scores[1] = P1();
				T0Scores[2] = P2();

				int best = bestProgram(T0Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[5] = { A18, A18, A17, T0, A19,  };

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
				const enum vertices next[3] = { A23, A18, A17,  };

				double T2Scores[3];

				T2Scores[0] = P8();
				T2Scores[1] = P9();
				T2Scores[2] = P10();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[6] = { A23, T2, T0, A18, A19, A17,  };

				double T3Scores[6];

				T3Scores[0] = P8();
				T3Scores[1] = P11();
				T3Scores[2] = P6();
				T3Scores[3] = P12();
				T3Scores[4] = P13();
				T3Scores[5] = P14();

				int best = bestProgram(T3Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { T1, T3, T2,  };

				double T4Scores[3];

				T4Scores[0] = P15();
				T4Scores[1] = P16();
				T4Scores[2] = P17();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[3] = { T2, T1, T3,  };

				double T5Scores[3];

				T5Scores[0] = P18();
				T5Scores[1] = P19();
				T5Scores[2] = P16();

				int best = bestProgram(T5Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[4] = { T1, T5, T3, T0,  };

				double T6Scores[4];

				T6Scores[0] = P20();
				T6Scores[1] = P21();
				T6Scores[2] = P22();
				T6Scores[3] = P23();

				int best = bestProgram(T6Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[3] = { T3, T4, T1,  };

				double T7Scores[3];

				T7Scores[0] = P24();
				T7Scores[1] = P25();
				T7Scores[2] = P26();

				int best = bestProgram(T7Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[6] = { T0, A19, T3, A21, T3, T5,  };

				double T8Scores[6];

				T8Scores[0] = P27();
				T8Scores[1] = P28();
				T8Scores[2] = P16();
				T8Scores[3] = P29();
				T8Scores[4] = P30();
				T8Scores[5] = P31();

				int best = bestProgram(T8Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T7,  };

				double T9Scores[1];

				T9Scores[0] = P32();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[2] = { A20, T8,  };

				double T10Scores[2];

				T10Scores[0] = P33();
				T10Scores[1] = P34();

				int best = bestProgram(T10Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[5] = { T8, T7, T10, A22, T4,  };

				double T11Scores[5];

				T11Scores[0] = P34();
				T11Scores[1] = P35();
				T11Scores[2] = P36();
				T11Scores[3] = P37();
				T11Scores[4] = P38();

				int best = bestProgram(T11Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[2] = { T5, T0,  };

				double T12Scores[2];

				T12Scores[0] = P39();
				T12Scores[1] = P40();

				int best = bestProgram(T12Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[5] = { T8, T10, T9, T0, T7,  };

				double T13Scores[5];

				T13Scores[0] = P41();
				T13Scores[1] = P42();
				T13Scores[2] = P43();
				T13Scores[3] = P44();
				T13Scores[4] = P35();

				int best = bestProgram(T13Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[3] = { T13, T7, T1,  };

				double T14Scores[3];

				T14Scores[0] = P45();
				T14Scores[1] = P46();
				T14Scores[2] = P47();

				int best = bestProgram(T14Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[5] = { T13, T12, T14, T7, A23,  };

				double T15Scores[5];

				T15Scores[0] = P45();
				T15Scores[1] = P48();
				T15Scores[2] = P49();
				T15Scores[3] = P46();
				T15Scores[4] = P50();

				int best = bestProgram(T15Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[4] = { T15, T0, T6, T11,  };

				double T16Scores[4];

				T16Scores[0] = P51();
				T16Scores[1] = P52();
				T16Scores[2] = P53();
				T16Scores[3] = P54();

				int best = bestProgram(T16Scores, 4);
				currentVertex = next[best];
				break;
			}
		case A17: {
				actions[0] = 5;
				return;
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
				actions[0] = 2;
				return;
			}
		case A21: {
				actions[0] = 0;
				return;
			}
		case A22: {
				actions[0] = 7;
				return;
			}
		case A23: {
				actions[0] = 1;
				return;
			}
		}
	}
}
