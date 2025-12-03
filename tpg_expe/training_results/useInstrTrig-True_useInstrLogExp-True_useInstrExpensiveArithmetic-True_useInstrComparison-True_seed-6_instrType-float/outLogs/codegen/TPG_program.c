/**
 * File generated with GEGELATI v2.0.0
 * On the 2025-11-24 14:17:38
 * With the CodeGen::ProgramGenerationEngine.
 */

#include "TPG_program.h"


float P0(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[2];
		reg[0] = log(op0);
	}
	return reg[0];
}

float P1(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in4[4];
		reg[0] = cos(op0);
	}
	return reg[0];
}

float P2(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	return reg[0];
}

float P3(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[1];
		reg[0] = log(op0);
	}
	return reg[0];
}

float P4(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in4[3];
		float op1 = in1[1];
		reg[0] = op0 / op1;
	}
	return reg[0];
}

float P5(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[2];
		float op1 = reg[1];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P6(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[2];
		float op1 = reg[1];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P7(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = reg[3];
		float op1 = in1[0];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P8(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	return reg[0];
}

float P9(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[2];
		float op1 = reg[1];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P10(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[1];
		float op1 = in4[4];
		reg[0] = op0 / op1;
	}
	return reg[0];
}

float P11(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[1];
		float op1 = reg[5];
		reg[1] = op0 / op1;
	}
	{
		float op0 = reg[1];
		float op1 = in4[2];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P12(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[2];
		float op1 = reg[1];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P13(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in4[1];
		float op1 = in3[1];
		reg[0] = op0 / op1;
	}
	return reg[0];
}

float P14(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[2];
		float op1 = in3[1];
		reg[0] = op0 + op1;
	}
	return reg[0];
}

float P15(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[0];
		reg[0] = log(op0);
	}
	return reg[0];
}

float P16(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in4[2];
		reg[0] = cos(op0);
	}
	return reg[0];
}

float P17(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = reg[0];
		float op1 = in3[1];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P18(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = reg[0];
		float op1 = in3[1];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P19(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[0];
		reg[0] = log(op0);
	}
	return reg[0];
}

float P20(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in4[0];
		float op1 = in3[1];
		reg[0] = op0 / op1;
	}
	return reg[0];
}

float P21(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in4[1];
		reg[0] = log(op0);
	}
	return reg[0];
}

float P22(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in1[1];
		float op1 = in3[1];
		reg[0] = fmaxf(op0, op1);
	}
	return reg[0];
}

float P23(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in4[1];
		reg[0] = log(op0);
	}
	return reg[0];
}

float P24(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in4[0];
		reg[0] = cos(op0);
	}
	{
		float op0 = reg[0];
		float op1 = in3[1];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P25(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = reg[0];
		float op1 = in3[2];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P26(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in1[1];
		float op1 = in3[1];
		reg[0] = fmaxf(op0, op1);
	}
	return reg[0];
}

float P27(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = reg[0];
		float op1 = in3[2];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P28(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in4[4];
		float op1 = reg[2];
		reg[0] = op0 / op1;
	}
	return reg[0];
}

float P29(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in4[1];
		reg[0] = log(op0);
	}
	return reg[0];
}

float P30(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[0];
		float op1 = in3[1];
		reg[0] = op0 + op1;
	}
	return reg[0];
}

float P31(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in1[2];
		reg[0] = log(op0);
	}
	{
		float op0 = reg[0];
		float op1 = in3[1];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P32(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[0];
		float op1 = reg[1];
		reg[0] = fmaxf(op0, op1);
	}
	return reg[0];
}

float P33(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = reg[5];
		reg[7] = exp(op0);
	}
	{
		float op0 = in3[2];
		float op1 = reg[7];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P34(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in1[1];
		float op1 = in3[0];
		reg[3] = op0 + op1;
	}
	{
		float op0 = in3[2];
		float op1 = reg[3];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P35(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = reg[0];
		float op1 = in3[2];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P36(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in4[0];
		reg[0] = cos(op0);
	}
	{
		float op0 = reg[0];
		float op1 = in3[1];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P37(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in4[0];
		float op1 = in2[1];
		reg[4] = fmaxf(op0, op1);
	}
	{
		float op0 = reg[4];
		reg[0] = log(op0);
	}
	return reg[0];
}

float P38(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in4[0];
		reg[0] = log(op0);
	}
	return reg[0];
}

float P39(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in1[2];
		reg[0] = log(op0);
	}
	{
		float op0 = reg[0];
		float op1 = in3[1];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P40(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = reg[6];
		reg[3] = exp(op0);
	}
	{
		float op0 = reg[3];
		float op1 = in2[0];
		reg[0] = op0 * op1;
	}
	return reg[0];
}

float P41(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in1[1];
		float op1 = in3[0];
		reg[0] = op0 * op1;
	}
	return reg[0];
}

float P42(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[0];
		float op1 = in3[1];
		reg[0] = op0 + op1;
	}
	return reg[0];
}

float P43(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = reg[0];
		float op1 = in3[2];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P44(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in1[2];
		reg[0] = log(op0);
	}
	{
		float op0 = reg[0];
		float op1 = in3[1];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P45(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = reg[2];
		float op1 = in4[2];
		reg[0] = fmaxf(op0, op1);
	}
	return reg[0];
}

float P46(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[0];
		float op1 = reg[1];
		reg[0] = fmaxf(op0, op1);
	}
	return reg[0];
}

float P47(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = reg[4];
		reg[0] = cos(op0);
	}
	return reg[0];
}

float P48(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in1[0];
		reg[0] = exp(op0);
	}
	return reg[0];
}

float P49(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in4[0];
		reg[0] = cos(op0);
	}
	{
		float op0 = reg[0];
		float op1 = in3[1];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P50(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = reg[0];
		float op1 = in3[2];
		reg[0] = op0 - op1;
	}
	return reg[0];
}

float P51(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in1[0];
		float op1 = in4[2];
		reg[0] = op0 + op1;
	}
	return reg[0];
}

float P52(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[0];
		float op1 = in2[0];
		reg[0] = op0 / op1;
	}
	return reg[0];
}

float P53(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in1[0];
		float op1 = in2[1];
		reg[0] = op0 * op1;
	}
	return reg[0];
}

float P54(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in1[2];
		reg[4] = tan(op0);
	}
	{
		float op0 = reg[4];
		float op1 = in4[0];
		reg[0] = fmaxf(op0, op1);
	}
	return reg[0];
}

float P55(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[0];
		float op1 = reg[2];
		reg[0] = op0 / op1;
	}
	return reg[0];
}

float P56(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[0];
		float op1 = reg[2];
		reg[0] = op0 / op1;
	}
	return reg[0];
}

float P57(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[1];
		float op1 = in3[1];
		reg[0] = op0 + op1;
	}
	return reg[0];
}

float P58(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in4[2];
		reg[0] = log(op0);
	}
	return reg[0];
}

float P59(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in1[1];
		float op1 = in1[0];
		reg[0] = op0 * op1;
	}
	return reg[0];
}

float P60(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[2];
		float op1 = in1[0];
		reg[0] = op0 * op1;
	}
	return reg[0];
}

float P61(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in1[0];
		float op1 = reg[2];
		reg[0] = op0 / op1;
	}
	return reg[0];
}

float P62(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[2];
		float op1 = in1[0];
		reg[0] = op0 * op1;
	}
	return reg[0];
}

float P63(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in1[2];
		float op1 = in3[2];
		reg[0] = op0 / op1;
	}
	return reg[0];
}

float P64(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in2[0];
		float op1 = reg[2];
		reg[0] = op0 / op1;
	}
	return reg[0];
}

float P65(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in4[5];
		float op1 = in3[0];
		reg[0] = op0 * op1;
	}
	return reg[0];
}

float P66(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = reg[7];
		float op1 = in1[2];
		reg[0] = fmaxf(op0, op1);
	}
	return reg[0];
}

float P67(){
	float reg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	{
		float op0 = in3[1];
		reg[0] = exp(op0);
	}
	return reg[0];
}
