

#include "extern_variables.h"

#pragma CODE_SECTION(Gateoff, "ramfuncs");
#pragma CODE_SECTION(GateReset, "ramfuncs");
#pragma CODE_SECTION(protection, "ramfuncs");

void Gateoff(void)
{
	EALLOW;
	EPwm2Regs.TZFRC.bit.OST=1;
	EPwm6Regs.TZFRC.bit.OST=1;
	//EPwm7Regs.TZFRC.bit.OST=1;
	//EPwm8Regs.TZFRC.bit.OST=1;
	//EPwm9Regs.TZFRC.bit.OST=1;
	EPwm10Regs.TZFRC.bit.OST=1;
	//EPwm11Regs.TZFRC.bit.OST=1;
	EDIS;
}

void GateReset(void)
{
	EALLOW;
	EPwm2Regs.TZCLR.bit.OST=1;
	EPwm2Regs.TZCLR.bit.INT=1;

	EPwm6Regs.TZCLR.bit.OST=1;
	EPwm6Regs.TZCLR.bit.INT=1;

	//EPwm7Regs.TZCLR.bit.OST=1;
	//EPwm7Regs.TZCLR.bit.INT=1;

	//EPwm8Regs.TZCLR.bit.OST=1;
	//EPwm8Regs.TZCLR.bit.INT=1;

	//EPwm9Regs.TZCLR.bit.OST=1;
	//EPwm9Regs.TZCLR.bit.INT=1;

	EPwm10Regs.TZCLR.bit.OST=1;
	EPwm10Regs.TZCLR.bit.INT=1;

	//EPwm11Regs.TZCLR.bit.OST=1;
	//EPwm11Regs.TZCLR.bit.INT=1;
	EDIS;
}

void protection(float32 input, float32 max)
{
	if (input>max)
	{
		Gateoff();
	}
}
