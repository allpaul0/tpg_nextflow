/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:31
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, A14, A15, A16, A17, A18, A19, A20, };

void inferenceTPG(double* actions) {

	enum vertices currentVertex = T13;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[1] = { A14,  };

				double T0Scores[1];

				T0Scores[0] = P0();

				int best = bestProgram(T0Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[4] = { A15, A15, T0, A17,  };

				double T1Scores[4];

				T1Scores[0] = P1();
				T1Scores[1] = P2();
				T1Scores[2] = P3();
				T1Scores[3] = P4();

				int best = bestProgram(T1Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A19, A16, A17,  };

				double T2Scores[3];

				T2Scores[0] = P5();
				T2Scores[1] = P6();
				T2Scores[2] = P7();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[6] = { A14, A15, A18, A16, A14, T1,  };

				double T3Scores[6];

				T3Scores[0] = P8();
				T3Scores[1] = P2();
				T3Scores[2] = P9();
				T3Scores[3] = P10();
				T3Scores[4] = P11();
				T3Scores[5] = P12();

				int best = bestProgram(T3Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[2] = { T2, A16,  };

				double T4Scores[2];

				T4Scores[0] = P13();
				T4Scores[1] = P14();

				int best = bestProgram(T4Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { A17,  };

				double T5Scores[1];

				T5Scores[0] = P15();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[4] = { T2, A15, A14, T3,  };

				double T6Scores[4];

				T6Scores[0] = P16();
				T6Scores[1] = P17();
				T6Scores[2] = P18();
				T6Scores[3] = P19();

				int best = bestProgram(T6Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[4] = { T2, A18, A14, T3,  };

				double T7Scores[4];

				T7Scores[0] = P20();
				T7Scores[1] = P21();
				T7Scores[2] = P22();
				T7Scores[3] = P23();

				int best = bestProgram(T7Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[4] = { A15, A14, T2, T3,  };

				double T8Scores[4];

				T8Scores[0] = P24();
				T8Scores[1] = P25();
				T8Scores[2] = P26();
				T8Scores[3] = P27();

				int best = bestProgram(T8Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[4] = { T3, T7, A14, T6,  };

				double T9Scores[4];

				T9Scores[0] = P28();
				T9Scores[1] = P29();
				T9Scores[2] = P25();
				T9Scores[3] = P30();

				int best = bestProgram(T9Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[3] = { T4, A14, T9,  };

				double T10Scores[3];

				T10Scores[0] = P31();
				T10Scores[1] = P32();
				T10Scores[2] = P33();

				int best = bestProgram(T10Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[4] = { A16, T5, T8, A16,  };

				double T11Scores[4];

				T11Scores[0] = P34();
				T11Scores[1] = P35();
				T11Scores[2] = P36();
				T11Scores[3] = P37();

				int best = bestProgram(T11Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[7] = { A18, T4, A16, A16, T10, A16, T4,  };

				double T12Scores[7];

				T12Scores[0] = P38();
				T12Scores[1] = P31();
				T12Scores[2] = P37();
				T12Scores[3] = P39();
				T12Scores[4] = P40();
				T12Scores[5] = P41();
				T12Scores[6] = P42();

				int best = bestProgram(T12Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[7] = { T11, A16, A16, T4, A18, A20, T12,  };

				double T13Scores[7];

				T13Scores[0] = P43();
				T13Scores[1] = P44();
				T13Scores[2] = P45();
				T13Scores[3] = P42();
				T13Scores[4] = P46();
				T13Scores[5] = P47();
				T13Scores[6] = P48();

				int best = bestProgram(T13Scores, 7);
				currentVertex = next[best];
				break;
			}
		case A14: {
				actions[0] = 7;
				return;
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
				actions[0] = 2;
				return;
			}
		case A19: {
				actions[0] = 0;
				return;
			}
		case A20: {
				actions[0] = 1;
				return;
			}
		}
	}
}
