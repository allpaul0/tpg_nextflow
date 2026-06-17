/**
 * File generated with GEGELATI v2.0.0
 * On the 2026-06-16 18:10:21
 * With the CodeGen::GotoProgramGenerationEngine.
 */
#ifndef C_TPG_program_H
#define C_TPG_program_H

#include "externHeader.h"


inline __attribute__((always_inline)) fixedpt P0(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in3[2];
		fixedpt op1 = reg[1];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P1(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = reg[0];
		fixedpt op1 = in3[1];
		reg[0] = op0 + op1;
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P2(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in3[0];
		fixedpt op1 = in3[1];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P3(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in3[1];
		fixedpt op1 = in1[1];
		reg[0] = protected_fixedpt_div(op0,op1);
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P4(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in3[1];
		fixedpt op1 = reg[0];
		reg[0] = fixedpt_mul(op0,op1);
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P5(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in3[1];
		fixedpt op1 = in3[0];
		reg[0] = op0 + op1;
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P6(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in2[2];
		reg[2] = fixedpt_exp(op0);
	}
	{
		fixedpt op0 = in3[2];
		fixedpt op1 = reg[2];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P7(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P8(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in4[5];
		fixedpt op1 = in3[1];
		reg[0] = protected_fixedpt_div(op0,op1);
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P9(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in1[2];
		fixedpt op1 = in1[0];
		reg[0] = protected_fixedpt_div(op0,op1);
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P10(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in1[0];
		fixedpt op1 = reg[2];
		reg[0] = protected_fixedpt_div(op0,op1);
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P11(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in4[0];
		fixedpt op1 = in3[1];
		reg[0] = protected_fixedpt_div(op0,op1);
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P12(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in3[2];
		fixedpt op1 = reg[7];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P13(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in4[2];
		fixedpt op1 = reg[4];
		reg[0] = (op0 > op1) ? op0 : op1;
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P14(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in4[0];
		fixedpt op1 = in3[1];
		reg[0] = (op0 > op1) ? op0 : op1;
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P15(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in3[1];
		fixedpt op1 = in3[2];
		reg[0] = fixedpt_mul(op0,op1);
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P16(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = reg[6];
		fixedpt op1 = in3[1];
		reg[6] = (op0 > op1) ? op0 : op1;
	}
	{
		fixedpt op0 = reg[6];
		reg[0] = fixedpt_exp(op0);
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P17(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in4[1];
		fixedpt op1 = in1[2];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P18(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = reg[5];
		fixedpt op1 = in3[2];
		reg[3] = (op0 > op1) ? op0 : op1;
	}
	{
		fixedpt op0 = reg[3];
		fixedpt op1 = in3[1];
		reg[0] = fixedpt_mul(op0,op1);
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P19(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in4[1];
		fixedpt op1 = in1[2];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P20(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in4[1];
		fixedpt op1 = in3[0];
		reg[0] = op0 + op1;
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P21(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in4[0];
		fixedpt op1 = in3[1];
		reg[0] = (op0 > op1) ? op0 : op1;
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P22(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in2[0];
		fixedpt op1 = in1[0];
		reg[0] = op0 + op1;
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P23(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in3[1];
		reg[0] = fixedpt_tan(op0);
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P24(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in3[1];
		reg[0] = fixedpt_tan(op0);
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P25(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = reg[2];
		fixedpt op1 = in1[1];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P26(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in4[0];
		fixedpt op1 = in3[1];
		reg[0] = fixedpt_mul(op0,op1);
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P27(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in3[2];
		reg[0] = fixedpt_exp(op0);
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P28(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in4[3];
		fixedpt op1 = in3[0];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P29(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in3[1];
		reg[0] = fixedpt_tan(op0);
	}
	return reg[0];
}

inline __attribute__((always_inline)) fixedpt P30(const fixedpt * __restrict__ in1, const fixedpt * __restrict__ in2, const fixedpt * __restrict__ in3, const fixedpt * __restrict__ in4) {
	fixedpt reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		fixedpt op0 = in2[0];
		fixedpt op1 = in4[0];
		reg[0] = fixedpt_mul(op0,op1);
	}
	return reg[0];
}

#endif
