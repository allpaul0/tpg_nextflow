/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:35
 * With the CodeGen::TPGGenerationEngine.
 */

#include "TPG.h"

int bestProgram(float *results, int nb) {
	int bestProgram = 0;
	float bestScore = (isnan(results[0]))? -INFINITY : results[0];
	for (int i = 1; i < nb; i++) {
		float challengerScore = (isnan(results[i]))? -INFINITY : results[i];
		if (challengerScore >= bestScore) {
			bestProgram = i;
			bestScore = challengerScore;
		}
	}
	return bestProgram;
}

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, A21, A22, A23, A24, A25, A26, A27, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T20;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[1] = { A21,  };

				float T0Scores[1];

				T0Scores[0] = P0();

				int best = bestProgram(T0Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { T0, A26,  };

				float T1Scores[2];

				T1Scores[0] = P1();
				T1Scores[1] = P2();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[6] = { A26, A24, A21, A24, A21, A25,  };

				float T2Scores[6];

				T2Scores[0] = P3();
				T2Scores[1] = P4();
				T2Scores[2] = P5();
				T2Scores[3] = P6();
				T2Scores[4] = P7();
				T2Scores[5] = P8();

				int best = bestProgram(T2Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[1] = { A21,  };

				float T3Scores[1];

				T3Scores[0] = P9();

				int best = bestProgram(T3Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[5] = { A25, A26, A21, A22, A22,  };

				float T4Scores[5];

				T4Scores[0] = P10();
				T4Scores[1] = P2();
				T4Scores[2] = P11();
				T4Scores[3] = P12();
				T4Scores[4] = P13();

				int best = bestProgram(T4Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[6] = { A25, A24, T0, A23, A24, A26,  };

				float T5Scores[6];

				T5Scores[0] = P14();
				T5Scores[1] = P15();
				T5Scores[2] = P16();
				T5Scores[3] = P17();
				T5Scores[4] = P18();
				T5Scores[5] = P2();

				int best = bestProgram(T5Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[7] = { T3, A23, A24, A26, T1, A24, A24,  };

				float T6Scores[7];

				T6Scores[0] = P19();
				T6Scores[1] = P17();
				T6Scores[2] = P18();
				T6Scores[3] = P3();
				T6Scores[4] = P20();
				T6Scores[5] = P15();
				T6Scores[6] = P21();

				int best = bestProgram(T6Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[5] = { A24, A26, A26, A25, A26,  };

				float T7Scores[5];

				T7Scores[0] = P15();
				T7Scores[1] = P22();
				T7Scores[2] = P23();
				T7Scores[3] = P24();
				T7Scores[4] = P25();

				int best = bestProgram(T7Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[5] = { A24, T4, T7, T5, T1,  };

				float T8Scores[5];

				T8Scores[0] = P26();
				T8Scores[1] = P27();
				T8Scores[2] = P28();
				T8Scores[3] = P29();
				T8Scores[4] = P20();

				int best = bestProgram(T8Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[1] = { T8,  };

				float T9Scores[1];

				T9Scores[0] = P30();

				int best = bestProgram(T9Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[5] = { A24, T8, A23, T2, A25,  };

				float T10Scores[5];

				T10Scores[0] = P31();
				T10Scores[1] = P30();
				T10Scores[2] = P32();
				T10Scores[3] = P33();
				T10Scores[4] = P24();

				int best = bestProgram(T10Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[5] = { T10, T8, T4, A23, A24,  };

				float T11Scores[5];

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
				const enum vertices next[2] = { T8, T7,  };

				float T12Scores[2];

				T12Scores[0] = P35();
				T12Scores[1] = P39();

				int best = bestProgram(T12Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[3] = { T9, T11, A22,  };

				float T13Scores[3];

				T13Scores[0] = P40();
				T13Scores[1] = P41();
				T13Scores[2] = P42();

				int best = bestProgram(T13Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[6] = { T10, T4, A23, A24, T12, T10,  };

				float T14Scores[6];

				T14Scores[0] = P43();
				T14Scores[1] = P44();
				T14Scores[2] = P45();
				T14Scores[3] = P38();
				T14Scores[4] = P46();
				T14Scores[5] = P47();

				int best = bestProgram(T14Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[1] = { T11,  };

				float T15Scores[1];

				T15Scores[0] = P48();

				int best = bestProgram(T15Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[1] = { T11,  };

				float T16Scores[1];

				T16Scores[0] = P48();

				int best = bestProgram(T16Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[3] = { A22, T14, T7,  };

				float T17Scores[3];

				T17Scores[0] = P49();
				T17Scores[1] = P50();
				T17Scores[2] = P51();

				int best = bestProgram(T17Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[5] = { T13, T10, T13, T6, T16,  };

				float T18Scores[5];

				T18Scores[0] = P52();
				T18Scores[1] = P53();
				T18Scores[2] = P54();
				T18Scores[3] = P55();
				T18Scores[4] = P56();

				int best = bestProgram(T18Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[7] = { T13, T4, A26, T7, T13, T10, T15,  };

				float T19Scores[7];

				T19Scores[0] = P52();
				T19Scores[1] = P57();
				T19Scores[2] = P58();
				T19Scores[3] = P39();
				T19Scores[4] = P54();
				T19Scores[5] = P34();
				T19Scores[6] = P59();

				int best = bestProgram(T19Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[6] = { A27, T18, T17, T4, T7, T19,  };

				float T20Scores[6];

				T20Scores[0] = P60();
				T20Scores[1] = P61();
				T20Scores[2] = P62();
				T20Scores[3] = P44();
				T20Scores[4] = P63();
				T20Scores[5] = P64();

				int best = bestProgram(T20Scores, 6);
				currentVertex = next[best];
				break;
			}
		case A21: {
				actions[0] = 4;
				return;
			}
		case A22: {
				actions[0] = 7;
				return;
			}
		case A23: {
				actions[0] = 5;
				return;
			}
		case A24: {
				actions[0] = 6;
				return;
			}
		case A25: {
				actions[0] = 2;
				return;
			}
		case A26: {
				actions[0] = 0;
				return;
			}
		case A27: {
				actions[0] = 1;
				return;
			}
		}
	}
}
