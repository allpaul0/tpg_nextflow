/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:36
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

enum vertices {T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, A31, A32, A33, A34, A35, A36, A37, };

void inferenceTPG(float* actions) {

	enum vertices currentVertex = T30;
	while(1) {
		switch (currentVertex) {
		case T0: {
				const enum vertices next[2] = { A31, A32,  };

				float T0Scores[2];

				T0Scores[0] = P0();
				T0Scores[1] = P1();

				int best = bestProgram(T0Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T1: {
				const enum vertices next[3] = { A33, A34, A32,  };

				float T1Scores[3];

				T1Scores[0] = P2();
				T1Scores[1] = P3();
				T1Scores[2] = P4();

				int best = bestProgram(T1Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T2: {
				const enum vertices next[3] = { A35, A31, A32,  };

				float T2Scores[3];

				T2Scores[0] = P5();
				T2Scores[1] = P6();
				T2Scores[2] = P7();

				int best = bestProgram(T2Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T3: {
				const enum vertices next[2] = { A35, T2,  };

				float T3Scores[2];

				T3Scores[0] = P8();
				T3Scores[1] = P9();

				int best = bestProgram(T3Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T4: {
				const enum vertices next[5] = { T1, A35, A35, A33, A31,  };

				float T4Scores[5];

				T4Scores[0] = P10();
				T4Scores[1] = P11();
				T4Scores[2] = P12();
				T4Scores[3] = P13();
				T4Scores[4] = P6();

				int best = bestProgram(T4Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T5: {
				const enum vertices next[5] = { A34, T3, T1, A35, A32,  };

				float T5Scores[5];

				T5Scores[0] = P14();
				T5Scores[1] = P15();
				T5Scores[2] = P16();
				T5Scores[3] = P17();
				T5Scores[4] = P18();

				int best = bestProgram(T5Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T6: {
				const enum vertices next[5] = { T0, T1, T3, A32, A35,  };

				float T6Scores[5];

				T6Scores[0] = P19();
				T6Scores[1] = P20();
				T6Scores[2] = P15();
				T6Scores[3] = P18();
				T6Scores[4] = P21();

				int best = bestProgram(T6Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T7: {
				const enum vertices next[6] = { T3, T1, A31, T0, A35, A35,  };

				float T7Scores[6];

				T7Scores[0] = P15();
				T7Scores[1] = P16();
				T7Scores[2] = P22();
				T7Scores[3] = P19();
				T7Scores[4] = P17();
				T7Scores[5] = P23();

				int best = bestProgram(T7Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T8: {
				const enum vertices next[1] = { T5,  };

				float T8Scores[1];

				T8Scores[0] = P24();

				int best = bestProgram(T8Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T9: {
				const enum vertices next[3] = { T4, T6, A36,  };

				float T9Scores[3];

				T9Scores[0] = P25();
				T9Scores[1] = P26();
				T9Scores[2] = P27();

				int best = bestProgram(T9Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T10: {
				const enum vertices next[7] = { T1, A31, A35, T0, A35, A32, T7,  };

				float T10Scores[7];

				T10Scores[0] = P16();
				T10Scores[1] = P22();
				T10Scores[2] = P11();
				T10Scores[3] = P19();
				T10Scores[4] = P28();
				T10Scores[5] = P29();
				T10Scores[6] = P30();

				int best = bestProgram(T10Scores, 7);
				currentVertex = next[best];
				break;
			}
		case T11: {
				const enum vertices next[3] = { T8, A34, T6,  };

				float T11Scores[3];

				T11Scores[0] = P31();
				T11Scores[1] = P32();
				T11Scores[2] = P33();

				int best = bestProgram(T11Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T12: {
				const enum vertices next[4] = { A34, T11, T0, T10,  };

				float T12Scores[4];

				T12Scores[0] = P32();
				T12Scores[1] = P34();
				T12Scores[2] = P35();
				T12Scores[3] = P36();

				int best = bestProgram(T12Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T13: {
				const enum vertices next[1] = { T12,  };

				float T13Scores[1];

				T13Scores[0] = P37();

				int best = bestProgram(T13Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T14: {
				const enum vertices next[5] = { T13, T12, A36, T9, A31,  };

				float T14Scores[5];

				T14Scores[0] = P38();
				T14Scores[1] = P39();
				T14Scores[2] = P40();
				T14Scores[3] = P41();
				T14Scores[4] = P42();

				int best = bestProgram(T14Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T15: {
				const enum vertices next[6] = { T13, T12, A34, T9, A31, A34,  };

				float T15Scores[6];

				T15Scores[0] = P38();
				T15Scores[1] = P39();
				T15Scores[2] = P43();
				T15Scores[3] = P41();
				T15Scores[4] = P42();
				T15Scores[5] = P44();

				int best = bestProgram(T15Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T16: {
				const enum vertices next[5] = { T11, T0, T10, T0, T0,  };

				float T16Scores[5];

				T16Scores[0] = P45();
				T16Scores[1] = P35();
				T16Scores[2] = P36();
				T16Scores[3] = P46();
				T16Scores[4] = P47();

				int best = bestProgram(T16Scores, 5);
				currentVertex = next[best];
				break;
			}
		case T17: {
				const enum vertices next[6] = { T0, T12, T15, A34, A36, T11,  };

				float T17Scores[6];

				T17Scores[0] = P48();
				T17Scores[1] = P49();
				T17Scores[2] = P50();
				T17Scores[3] = P44();
				T17Scores[4] = P51();
				T17Scores[5] = P34();

				int best = bestProgram(T17Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T18: {
				const enum vertices next[2] = { T14, T0,  };

				float T18Scores[2];

				T18Scores[0] = P52();
				T18Scores[1] = P53();

				int best = bestProgram(T18Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T19: {
				const enum vertices next[1] = { T9,  };

				float T19Scores[1];

				T19Scores[0] = P54();

				int best = bestProgram(T19Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T20: {
				const enum vertices next[1] = { T19,  };

				float T20Scores[1];

				T20Scores[0] = P55();

				int best = bestProgram(T20Scores, 1);
				currentVertex = next[best];
				break;
			}
		case T21: {
				const enum vertices next[2] = { T0, T17,  };

				float T21Scores[2];

				T21Scores[0] = P56();
				T21Scores[1] = P57();

				int best = bestProgram(T21Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T22: {
				const enum vertices next[4] = { T13, T16, T4, T18,  };

				float T22Scores[4];

				T22Scores[0] = P38();
				T22Scores[1] = P58();
				T22Scores[2] = P59();
				T22Scores[3] = P60();

				int best = bestProgram(T22Scores, 4);
				currentVertex = next[best];
				break;
			}
		case T23: {
				const enum vertices next[3] = { T21, A32, A37,  };

				float T23Scores[3];

				T23Scores[0] = P61();
				T23Scores[1] = P62();
				T23Scores[2] = P63();

				int best = bestProgram(T23Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T24: {
				const enum vertices next[2] = { T21, T20,  };

				float T24Scores[2];

				T24Scores[0] = P64();
				T24Scores[1] = P65();

				int best = bestProgram(T24Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T25: {
				const enum vertices next[2] = { T21, A37,  };

				float T25Scores[2];

				T25Scores[0] = P61();
				T25Scores[1] = P63();

				int best = bestProgram(T25Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T26: {
				const enum vertices next[2] = { T24, T22,  };

				float T26Scores[2];

				T26Scores[0] = P66();
				T26Scores[1] = P67();

				int best = bestProgram(T26Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T27: {
				const enum vertices next[2] = { T26, T23,  };

				float T27Scores[2];

				T27Scores[0] = P68();
				T27Scores[1] = P69();

				int best = bestProgram(T27Scores, 2);
				currentVertex = next[best];
				break;
			}
		case T28: {
				const enum vertices next[6] = { T12, T12, T1, T9, T22, T12,  };

				float T28Scores[6];

				T28Scores[0] = P70();
				T28Scores[1] = P71();
				T28Scores[2] = P72();
				T28Scores[3] = P73();
				T28Scores[4] = P74();
				T28Scores[5] = P75();

				int best = bestProgram(T28Scores, 6);
				currentVertex = next[best];
				break;
			}
		case T29: {
				const enum vertices next[3] = { T22, T28, T25,  };

				float T29Scores[3];

				T29Scores[0] = P76();
				T29Scores[1] = P77();
				T29Scores[2] = P78();

				int best = bestProgram(T29Scores, 3);
				currentVertex = next[best];
				break;
			}
		case T30: {
				const enum vertices next[5] = { A31, T29, T12, T27, T23,  };

				float T30Scores[5];

				T30Scores[0] = P79();
				T30Scores[1] = P80();
				T30Scores[2] = P81();
				T30Scores[3] = P82();
				T30Scores[4] = P83();

				int best = bestProgram(T30Scores, 5);
				currentVertex = next[best];
				break;
			}
		case A31: {
				actions[0] = 5;
				return;
			}
		case A32: {
				actions[0] = 6;
				return;
			}
		case A33: {
				actions[0] = 7;
				return;
			}
		case A34: {
				actions[0] = 0;
				return;
			}
		case A35: {
				actions[0] = 4;
				return;
			}
		case A36: {
				actions[0] = 8;
				return;
			}
		case A37: {
				actions[0] = 2;
				return;
			}
		}
	}
}
