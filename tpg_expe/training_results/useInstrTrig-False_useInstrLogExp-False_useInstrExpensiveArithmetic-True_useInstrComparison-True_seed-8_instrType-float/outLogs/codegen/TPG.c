/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:24
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, A29, A30, A31, A32, A33, A34, A35, A36, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T28;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A29, A30,  };

				float T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[2] = { A29, T0,  };

				float T1Scores[2];

				T1Scores[0] = P2();
				T1Scores[1] = P3();

				int best = bestProgram(T1Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A30, A34, A29,  };

				float T2Scores[3];

				T2Scores[0] = P4();
				T2Scores[1] = P5();
				T2Scores[2] = P6();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[3] = { A31, T0, A34,  };

				float T3Scores[3];

				T3Scores[0] = P7();
				T3Scores[1] = P3();
				T3Scores[2] = P8();

				int best = bestProgram(T3Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[3] = { A34, T0, A31,  };

				float T4Scores[3];

				T4Scores[0] = P5();
				T4Scores[1] = P9();
				T4Scores[2] = P10();

				int best = bestProgram(T4Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[1] = { A30,  };

				float T5Scores[1];

				T5Scores[0] = P11();

				int best = bestProgram(T5Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[5] = { A31, A29, T0, A31, A34,  };

				float T6Scores[5];

				T6Scores[0] = P12();
				T6Scores[1] = P13();
				T6Scores[2] = P3();
				T6Scores[3] = P14();
				T6Scores[4] = P15();

				int best = bestProgram(T6Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[4] = { T0, A33, T3, A29,  };

				float T7Scores[4];

				T7Scores[0] = P16();
				T7Scores[1] = P17();
				T7Scores[2] = P18();
				T7Scores[3] = P19();

				int best = bestProgram(T7Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[2] = { T3, T0,  };

				float T8Scores[2];

				T8Scores[0] = P20();
				T8Scores[1] = P21();

				int best = bestProgram(T8Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[5] = { T7, A33, T5, T6, T0,  };

				float T9Scores[5];

				T9Scores[0] = P22();
				T9Scores[1] = P23();
				T9Scores[2] = P24();
				T9Scores[3] = P25();
				T9Scores[4] = P16();

				int best = bestProgram(T9Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[5] = { A29, T3, T7, T4, T8,  };

				float T10Scores[5];

				T10Scores[0] = P26();
				T10Scores[1] = P27();
				T10Scores[2] = P22();
				T10Scores[3] = P28();
				T10Scores[4] = P29();

				int best = bestProgram(T10Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[1] = { T3,  };

				float T11Scores[1];

				T11Scores[0] = P30();

				int best = bestProgram(T11Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[1] = { T3,  };

				float T12Scores[1];

				T12Scores[0] = P31();

				int best = bestProgram(T12Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[2] = { T4, T10,  };

				float T13Scores[2];

				T13Scores[0] = P32();
				T13Scores[1] = P33();

				int best = bestProgram(T13Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[2] = { T10, T3,  };

				float T14Scores[2];

				T14Scores[0] = P33();
				T14Scores[1] = P30();

				int best = bestProgram(T14Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[2] = { T4, A35,  };

				float T15Scores[2];

				T15Scores[0] = P32();
				T15Scores[1] = P34();

				int best = bestProgram(T15Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[1] = { T4,  };

				float T16Scores[1];

				T16Scores[0] = P35();

				int best = bestProgram(T16Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[7] = { T3, T9, A36, T15, T10, A36, T10,  };

				float T17Scores[7];

				T17Scores[0] = P36();
				T17Scores[1] = P37();
				T17Scores[2] = P38();
				T17Scores[3] = P39();
				T17Scores[4] = P40();
				T17Scores[5] = P41();
				T17Scores[6] = P42();

				int best = bestProgram(T17Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[3] = { T13, A36, A32,  };

				float T18Scores[3];

				T18Scores[0] = P43();
				T18Scores[1] = P44();
				T18Scores[2] = P45();

				int best = bestProgram(T18Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[5] = { T10, T14, T6, T16, T3,  };

				float T19Scores[5];

				T19Scores[0] = P33();
				T19Scores[1] = P46();
				T19Scores[2] = P47();
				T19Scores[3] = P48();
				T19Scores[4] = P30();

				int best = bestProgram(T19Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[5] = { A36, T11, T10, T12, T18,  };

				float T20Scores[5];

				T20Scores[0] = P49();
				T20Scores[1] = P50();
				T20Scores[2] = P51();
				T20Scores[3] = P52();
				T20Scores[4] = P53();

				int best = bestProgram(T20Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[1] = { T17,  };

				float T21Scores[1];

				T21Scores[0] = P54();

				int best = bestProgram(T21Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T22: {
				const enum vertices next[4] = { A32, T20, A35, T17,  };

				float T22Scores[4];

				T22Scores[0] = P55();
				T22Scores[1] = P56();
				T22Scores[2] = P34();
				T22Scores[3] = P57();

				int best = bestProgram(T22Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T23: {
				const enum vertices next[5] = { T13, T17, T19, A35, A34,  };

				float T23Scores[5];

				T23Scores[0] = P58();
				T23Scores[1] = P54();
				T23Scores[2] = P59();
				T23Scores[3] = P34();
				T23Scores[4] = P60();

				int best = bestProgram(T23Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T24: {
				const enum vertices next[3] = { T22, T9, T2,  };

				float T24Scores[3];

				T24Scores[0] = P61();
				T24Scores[1] = P62();
				T24Scores[2] = P63();

				int best = bestProgram(T24Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T25: {
				const enum vertices next[2] = { T22, T9,  };

				float T25Scores[2];

				T25Scores[0] = P61();
				T25Scores[1] = P62();

				int best = bestProgram(T25Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T26: {
				const enum vertices next[5] = { T21, T23, T2, A35, A36,  };

				float T26Scores[5];

				T26Scores[0] = P64();
				T26Scores[1] = P65();
				T26Scores[2] = P66();
				T26Scores[3] = P67();
				T26Scores[4] = P68();

				int best = bestProgram(T26Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T27: {
				const enum vertices next[7] = { T23, T25, A34, T1, A35, T9, T13,  };

				float T27Scores[7];

				T27Scores[0] = P69();
				T27Scores[1] = P70();
				T27Scores[2] = P71();
				T27Scores[3] = P72();
				T27Scores[4] = P73();
				T27Scores[5] = P62();
				T27Scores[6] = P74();

				int best = bestProgram(T27Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T28: {
				const enum vertices next[6] = { T26, A32, T27, T24, T20, A32,  };

				float T28Scores[6];

				T28Scores[0] = P75();
				T28Scores[1] = P76();
				T28Scores[2] = P77();
				T28Scores[3] = P78();
				T28Scores[4] = P79();
				T28Scores[5] = P80();

				int best = bestProgram(T28Scores, 6);
				currentVertex = next[best];
				break;
			}
		case A29: {
				actions[0] = 5;
				return;
			}
		case A30: {
				actions[0] = 6;
				return;
			}
		case A31: {
				actions[0] = 4;
				return;
			}
		case A32: {
				actions[0] = 7;
				return;
			}
		case A33: {
				actions[0] = 8;
				return;
			}
		case A34: {
				actions[0] = 0;
				return;
			}
		case A35: {
				actions[0] = 2;
				return;
			}
		case A36: {
				actions[0] = 1;
				return;
			}
		}
	}
}
