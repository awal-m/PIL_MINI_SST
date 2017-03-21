#include "Mini_SST.h"

void InitEPwmGpio_TZ(void)
{

	InitEPwm1Gpio();
	InitEPwm2Gpio();
	InitEPwm6Gpio();
	//InitEPwm7Gpio();
	//InitEPwm8Gpio();
	//InitEPwm9Gpio();
	InitEPwm10Gpio();
	//InitEPwm11Gpio();

	/* GPIO for Relays */

    EALLOW;
    GpioCtrlRegs.GPCPUD.bit.GPIO65 = 0;   // Enable pullup on GPIO86
    GpioDataRegs.GPCCLEAR.bit.GPIO65 = 1;   // Load output latch
    GpioCtrlRegs.GPCMUX1.bit.GPIO65= 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO65 = 1; // output

    GpioCtrlRegs.GPCPUD.bit.GPIO69 = 0;   // Enable pullup on GPIO87
    GpioDataRegs.GPCCLEAR.bit.GPIO69 = 1;   // Load output latch
    GpioCtrlRegs.GPCMUX1.bit.GPIO69= 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO69 = 1; // output
    EDIS;

    // For Trigger Signal
    EALLOW;
    GpioCtrlRegs.GPCPUD.bit.GPIO71 = 0;   // Enable pullup on GPIO86
    GpioDataRegs.GPCCLEAR.bit.GPIO71 = 1;   // Load output latch
    GpioCtrlRegs.GPCMUX1.bit.GPIO71= 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO71 = 1; // output
    EDIS;

    EALLOW;
    GpioCtrlRegs.GPBPUD.bit.GPIO61 = 0;   // Enable pullup on GPIO89
    GpioDataRegs.GPBCLEAR.bit.GPIO61 = 1;   // Load output latch
    GpioCtrlRegs.GPBMUX2.bit.GPIO61= 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO61 = 1; // output

    GpioCtrlRegs.GPBPUD.bit.GPIO41 = 0;   // Enable pullup on GPIO90
    GpioDataRegs.GPBCLEAR.bit.GPIO41 = 1;   // Load output latch
    GpioCtrlRegs.GPBMUX1.bit.GPIO41= 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO41 = 1; // output
    EDIS;

	/* GPIO for RST */

    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 0;   // Enable pullup on GPIO89
    GpioDataRegs.GPASET.bit.GPIO4 = 1;   // Load output latch
    GpioCtrlRegs.GPAMUX1.bit.GPIO4= 0;
    GpioCtrlRegs.GPADIR.bit.GPIO4 = 1; // output
    EDIS;

    /* GPIO for RDY */

	EALLOW;
	GpioCtrlRegs.GPCPUD.bit.GPIO78 = 0;    // Enable pull-up on GPIO99 (TZ1)

	GpioCtrlRegs.GPCQSEL1.bit.GPIO78 = 3;  // Asynch input GPIO99 (TZ1)

	InputXbarRegs.INPUT1SELECT = 78;
	EDIS;
    /* GPIO for OverTemp */

	EALLOW;
	GpioCtrlRegs.GPCPUD.bit.GPIO72 = 0;    // Enable pull-up on GPIO99 (TZ2)

	GpioCtrlRegs.GPCQSEL1.bit.GPIO72 = 3;  // Asynch input GPIO99 (TZ2)

	InputXbarRegs.INPUT2SELECT = 72;
	EDIS;

    /* GPIO for DESAT */

	EALLOW;
	GpioCtrlRegs.GPCPUD.bit.GPIO73 = 0;    // Enable pull-up on GPIO99 (TZ3)

	GpioCtrlRegs.GPCQSEL1.bit.GPIO73 = 3;  // Asynch input GPIO99 (TZ3)

	InputXbarRegs.INPUT3SELECT = 73;
	EDIS;

}
