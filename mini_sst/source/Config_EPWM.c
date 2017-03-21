#include "Mini_SST.h"

void InitEPwm1(void)
{
    EPwm1Regs.TBPRD = Period;                       // Set timer period
    EPwm1Regs.TBPHS.bit.TBPHS = 0x0000;             // Phase is 0
    EPwm1Regs.TBCTR = 0x0000;

    // Setup TBCLK
    EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;  // Count updown
    EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;         // Disable phase loading
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;        // Clock ratio to SYSCLKOUT
    EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;     // Load registers every ZERO
//  EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
//  EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // Setup compare
    EPwm1Regs.CMPA.bit.CMPA = 0;					// Duty=0.5

    // Set actions
    EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR;
    EPwm1Regs.AQCTLA.bit.CAD = AQ_SET;

//  EPwm1Regs.AQCTLB.bit.CAU = AQ_CLEAR;
//  EPwm1Regs.AQCTLB.bit.CAD = AQ_SET;


    // Active Low PWMs - Setup Deadband
    EPwm1Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm1Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm1Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm1Regs.DBRED = EPWM1_MIN_DB;
    EPwm1Regs.DBFED = EPWM1_MIN_DB;
 // EPwm1_DB_Direction = DB_UP;


// ----------------configure Trip Zone -------------------
/*
    // Select CMPSS2
    EALLOW;
    //Configure TRIP4 to be CTRIP2H
    EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX2 = 0;
    //Enable TRIP4 Mux for Output
    EPwmXbarRegs.TRIP4MUXENABLE.bit.MUX2   = 1;
    EDIS;
*/
    // Interrupt where we will change the Deadband
//    EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;    // Select INT on Zero event
//    EPwm1Regs.ETSEL.bit.INTEN = 1;               // Enable INT
//    EPwm1Regs.ETPS.bit.INTPRD = ET_1ST;          // Generate INT on 1st event

}

void InitEPwm2(void)
{
    EPwm2Regs.TBPRD = Period;                       // Set timer period
    EPwm2Regs.TBPHS.bit.TBPHS = 0x0000;           // Phase is 0
    EPwm2Regs.TBCTR = 0x0000;                     // Clear counter

    // Setup TBCLK
    EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count updown
    EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
    EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
    EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;   // Load registers every ZERO
//  EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
//  EPwm2Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // Setup compare
    EPwm2Regs.CMPA.bit.CMPA = 0;				  // Duty=0.5

    // Set actions
    EPwm2Regs.AQCTLA.bit.CAU = AQ_CLEAR;
    EPwm2Regs.AQCTLA.bit.CAD = AQ_SET;

//  EPwm2Regs.AQCTLB.bit.CAU = AQ_CLEAR;
//  EPwm2Regs.AQCTLB.bit.CAD = AQ_SET;


    // Active Low PWMs - Setup Deadband
    EPwm2Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm2Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm2Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm2Regs.DBRED = EPWM2_MIN_DB;
    EPwm2Regs.DBFED = EPWM2_MIN_DB;
//  EPwm2_DB_Direction = DB_UP;


// ----------------configure Trip Zone -------------------
    /*
    EALLOW;
    //Configure EPWM2 to output high on TZB TRIP
    EPwm2Regs.TZCTL.bit.TZA = TZ_FORCE_LO;
    EPwm2Regs.TZCTL.bit.TZB = TZ_FORCE_LO;

    //Configure DCA to be TRIP4
    EPwm2Regs.TZDCSEL.bit.DCAEVT1 = TZ_DCAH_HI;
    //EPwm2Regs.TZDCSEL.bit.DCBEVT1 = TZ_DCBH_HI;
    EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 0xF; //DCAHTRIPSEL
    //EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL    = 0xF; //DCBHTRIPSEL
    //EPwm2Regs.DCAHTRIPSEL.bit.TRIPINPUT4   = 1;
    //EPwm2Regs.DCBHTRIPSEL.bit.TRIPINPUT4   = 1;
    EPwm2Regs.DCAHTRIPSEL.bit.TRIPINPUT2   = 1;
    EPwm2Regs.DCAHTRIPSEL.bit.TRIPINPUT3   = 1;

    //Configure DCA as OST
    EPwm2Regs.TZSEL.bit.DCAEVT1            = 1;
    //EPwm2Regs.TZSEL.bit.DCBEVT1          = 1;
    EPwm2Regs.TZSEL.bit.OSHT1 = 1;
    //EPwm2Regs.TZSEL.bit.OSHT2 = 1;
    //EPwm2Regs.TZSEL.bit.OSHT3 = 1;

    //Configure DCA path to be unfiltered & async
    EPwm2Regs.DCACTL.bit.EVT1SRCSEL        = DC_EVT1;
    //EPwm2Regs.DCBCTL.bit.EVT1SRCSEL        = DC_EVT1;
    EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL    = DC_EVT_ASYNC;
    //EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL    = DC_EVT_ASYNC;


    // Clear trip flags
    EPwm2Regs.TZCLR.bit.OST                = 1;
    EPwm2Regs.TZCLR.bit.INT                = 1;
    //Enable DCA interrupt
    EPwm2Regs.TZEINT.bit.OST               = 1;
    EDIS;

*/
    // Interrupt where we will change the Deadband
    EPwm2Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;    // Select INT on Zero event
    EPwm2Regs.ETSEL.bit.INTEN = 1;               // Enable INT
    EPwm2Regs.ETPS.bit.INTPRD = ET_1ST;          // Generate INT on 3rd event

}

void InitEPwm6(void)
{
    EPwm6Regs.TBPRD = Period;                       // Set timer period
    EPwm6Regs.TBPHS.bit.TBPHS = 0x0000;           // Phase is 0
    EPwm6Regs.TBCTR = 0x0000;                     // Clear counter

    // Setup TBCLK
    EPwm6Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    EPwm6Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
    EPwm6Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
    EPwm6Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    EPwm6Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;   // Load registers every ZERO
//  EPwm6Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm6Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
//  EPwm6Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // Setup compare
    EPwm6Regs.CMPA.bit.CMPA = 0;				  // Duty=0.5

    // Set actions
    EPwm6Regs.AQCTLA.bit.CAU = AQ_SET;
    EPwm6Regs.AQCTLA.bit.CAD = AQ_CLEAR;

//  EPwm6Regs.AQCTLB.bit.CAU = AQ_CLEAR;
//  EPwm6Regs.AQCTLB.bit.CAD = AQ_SET;


    // Active Low PWMs - Setup Deadband
    EPwm6Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm6Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm6Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm6Regs.DBRED = EPWM6_MIN_DB;
    EPwm6Regs.DBFED = EPWM6_MIN_DB;
//  EPwm6_DB_Direction = DB_UP;


// ----------------configure Trip Zone -------------------
/*
    EALLOW;
    //Configure EPWM6 to output high on TZB TRIP
    EPwm6Regs.TZCTL.bit.TZA = TZ_FORCE_LO;
    EPwm6Regs.TZCTL.bit.TZB = TZ_FORCE_LO;

    //Configure DCA to be TRIP4
    EPwm6Regs.TZDCSEL.bit.DCAEVT1 = TZ_DCAH_HI;
    //EPwm6Regs.TZDCSEL.bit.DCBEVT1 = TZ_DCBH_HI;
    EPwm6Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 0xF; //DCAHTRIPSEL
    //EPwm6Regs.DCTRIPSEL.bit.DCBHCOMPSEL    = 0xF; //DCBHTRIPSEL
    //EPwm6Regs.DCAHTRIPSEL.bit.TRIPINPUT4   = 1;
    //EPwm6Regs.DCBHTRIPSEL.bit.TRIPINPUT4   = 1;
    EPwm6Regs.DCAHTRIPSEL.bit.TRIPINPUT2   = 1;
    EPwm6Regs.DCAHTRIPSEL.bit.TRIPINPUT3   = 1;

    //Configure DCA as OST
    EPwm6Regs.TZSEL.bit.DCAEVT1            = 1;
    //EPwm6Regs.TZSEL.bit.DCBEVT1          = 1;
    EPwm6Regs.TZSEL.bit.OSHT1 = 1;
    //EPwm6Regs.TZSEL.bit.OSHT2 = 1;
    //EPwm6Regs.TZSEL.bit.OSHT3 = 1;

    //Configure DCA path to be unfiltered & async
    EPwm6Regs.DCACTL.bit.EVT1SRCSEL        = DC_EVT1;
    //EPwm6Regs.DCBCTL.bit.EVT1SRCSEL        = DC_EVT1;
    EPwm6Regs.DCACTL.bit.EVT1FRCSYNCSEL    = DC_EVT_ASYNC;
    //EPwm6Regs.DCBCTL.bit.EVT1FRCSYNCSEL    = DC_EVT_ASYNC;


    // Clear trip flags
    EPwm6Regs.TZCLR.bit.OST                = 1;
    EPwm6Regs.TZCLR.bit.INT                = 1;
    //Enable DCA interrupt
    EPwm6Regs.TZEINT.bit.OST               = 1;
    EDIS;


    // Interrupt where we will change the Deadband
//    EPwm6Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;    // Select INT on Zero event
//    EPwm6Regs.ETSEL.bit.INTEN = 1;               // Enable INT
//    EPwm6Regs.ETPS.bit.INTPRD = ET_1ST;          // Generate INT on 1st event
*/
}

void InitEPwm7(void)
{
    EPwm7Regs.TBPRD = Period;                       // Set timer period
    EPwm7Regs.TBPHS.bit.TBPHS = 0x0000;           // Phase is 0
    EPwm7Regs.TBCTR = 0x0000;                     // Clear counter

    // Setup TBCLK
    EPwm7Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    EPwm7Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
    EPwm7Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
    EPwm7Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    EPwm7Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;   // Load registers every ZERO
//  EPwm7Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm7Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
//  EPwm7Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // Setup compare
    EPwm7Regs.CMPA.bit.CMPA = 0;				  // Duty=0.5

    // Set actions
    EPwm7Regs.AQCTLA.bit.CAU = AQ_CLEAR;
    EPwm7Regs.AQCTLA.bit.CAD = AQ_SET;

//  EPwm7Regs.AQCTLB.bit.CAU = AQ_CLEAR;
//  EPwm7Regs.AQCTLB.bit.CAD = AQ_SET;


    // Active Low PWMs - Setup Deadband
    EPwm7Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm7Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm7Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm7Regs.DBRED = EPWM7_MIN_DB;
    EPwm7Regs.DBFED = EPWM7_MIN_DB;
//  EPwm7_DB_Direction = DB_UP;


// ----------------configure Trip Zone -------------------
/*
    EALLOW;
    //Configure EPWM7 to output high on TZB TRIP
    EPwm7Regs.TZCTL.bit.TZA = TZ_FORCE_LO;
    EPwm7Regs.TZCTL.bit.TZB = TZ_FORCE_LO;

    //Configure DCA to be TRIP4
    EPwm7Regs.TZDCSEL.bit.DCAEVT1 = TZ_DCAH_HI;
    //EPwm7Regs.TZDCSEL.bit.DCBEVT1 = TZ_DCBH_HI;
    EPwm7Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 0xF; //DCAHTRIPSEL
    //EPwm7Regs.DCTRIPSEL.bit.DCBHCOMPSEL    = 0xF; //DCBHTRIPSEL
    EPwm7Regs.DCAHTRIPSEL.bit.TRIPINPUT4   = 1;
    //EPwm7Regs.DCBHTRIPSEL.bit.TRIPINPUT4   = 1;

    //Configure DCA as OST
    EPwm7Regs.TZSEL.bit.DCAEVT1            = 1;
    //EPwm7Regs.TZSEL.bit.DCBEVT1          = 1;
    EPwm7Regs.TZSEL.bit.OSHT1 = 1;
    EPwm7Regs.TZSEL.bit.OSHT2 = 1;
    EPwm7Regs.TZSEL.bit.OSHT3 = 1;

    //Configure DCA path to be unfiltered & async
    EPwm7Regs.DCACTL.bit.EVT1SRCSEL        = DC_EVT1;
    //EPwm7Regs.DCBCTL.bit.EVT1SRCSEL        = DC_EVT1;
    EPwm7Regs.DCACTL.bit.EVT1FRCSYNCSEL    = DC_EVT_ASYNC;
    //EPwm7Regs.DCBCTL.bit.EVT1FRCSYNCSEL    = DC_EVT_ASYNC;

    //Configure TRIP4 to be CTRIP1H
//    EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX0 = 0;
    //Enable TRIP4 Mux for Output
//    EPwmXbarRegs.TRIP4MUXENABLE.bit.MUX0   = 1;


    // Clear trip flags
    EPwm7Regs.TZCLR.bit.OST                = 1;
    EPwm7Regs.TZCLR.bit.INT                = 1;
    //Enable DCA interrupt
    EPwm7Regs.TZEINT.bit.OST               = 1;
    EDIS;
*/


    // Interrupt where we will change the Deadband
//    EPwm7Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;    // Select INT on Zero event
//    EPwm7Regs.ETSEL.bit.INTEN = 1;               // Enable INT
//    EPwm7Regs.ETPS.bit.INTPRD = ET_1ST;          // Generate INT on 3rd event

}

void InitEPwm8(void)
{
    EPwm8Regs.TBPRD = Period;                       // Set timer period
    EPwm8Regs.TBPHS.bit.TBPHS = 0x0000;           // Phase is 0
    EPwm8Regs.TBCTR = 0x0000;                     // Clear counter

    // Setup TBCLK
    EPwm8Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    EPwm8Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
    EPwm8Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
    EPwm8Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    EPwm8Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;   // Load registers every ZERO
//  EPwm8Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm8Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
//  EPwm8Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // Setup compare
    EPwm8Regs.CMPA.bit.CMPA = 0;				  // Duty=0.5

    // Set actions
    EPwm8Regs.AQCTLA.bit.CAU = AQ_CLEAR;
    EPwm8Regs.AQCTLA.bit.CAD = AQ_SET;

//  EPwm8Regs.AQCTLB.bit.CAU = AQ_CLEAR;
//  EPwm8Regs.AQCTLB.bit.CAD = AQ_SET;


    // Active Low PWMs - Setup Deadband
    EPwm8Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm8Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm8Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm8Regs.DBRED = EPWM8_MIN_DB;
    EPwm8Regs.DBFED = EPWM8_MIN_DB;
//  EPwm8_DB_Direction = DB_UP;


// ----------------configure Trip Zone -------------------

    EALLOW;
    //Configure EPWM8 to output high on TZB TRIP
    EPwm8Regs.TZCTL.bit.TZA = TZ_FORCE_LO;
    EPwm8Regs.TZCTL.bit.TZB = TZ_FORCE_LO;

    //Configure DCA to be TRIP4
    EPwm8Regs.TZDCSEL.bit.DCAEVT1 = TZ_DCAH_HI;
    //EPwm8Regs.TZDCSEL.bit.DCBEVT1 = TZ_DCBH_HI;
    EPwm8Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 0xF; //DCAHTRIPSEL
    //EPwm8Regs.DCTRIPSEL.bit.DCBHCOMPSEL    = 0xF; //DCBHTRIPSEL
    EPwm8Regs.DCAHTRIPSEL.bit.TRIPINPUT4   = 1;
    //EPwm8Regs.DCBHTRIPSEL.bit.TRIPINPUT4   = 1;

    //Configure DCA as OST
    EPwm8Regs.TZSEL.bit.DCAEVT1            = 1;
    //EPwm8Regs.TZSEL.bit.DCBEVT1          = 1;
    EPwm8Regs.TZSEL.bit.OSHT1 = 1;
    EPwm8Regs.TZSEL.bit.OSHT2 = 1;
    EPwm8Regs.TZSEL.bit.OSHT3 = 1;

    //Configure DCB path to be unfiltered & async
    EPwm8Regs.DCACTL.bit.EVT1SRCSEL        = DC_EVT1;
    //EPwm8Regs.DCBCTL.bit.EVT1SRCSEL        = DC_EVT1;
    EPwm8Regs.DCACTL.bit.EVT1FRCSYNCSEL    = DC_EVT_ASYNC;
    //EPwm8Regs.DCBCTL.bit.EVT1FRCSYNCSEL    = DC_EVT_ASYNC;

    //Configure TRIP4 to be CTRIP1H
//    EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX0 = 0;
    //Enable TRIP4 Mux for Output
//    EPwmXbarRegs.TRIP4MUXENABLE.bit.MUX0   = 1;


    // Clear trip flags
    EPwm8Regs.TZCLR.bit.OST                = 1;
    EPwm8Regs.TZCLR.bit.INT                = 1;
    //Enable DCA interrupt
    EPwm8Regs.TZEINT.bit.OST               = 1;
    EDIS;

    // Interrupt where we will change the Deadband
//    EPwm8Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;    // Select INT on Zero event
//    EPwm8Regs.ETSEL.bit.INTEN = 1;               // Enable INT
//    EPwm8Regs.ETPS.bit.INTPRD = ET_1ST;          // Generate INT on 3rd event
}

void InitEPwm9(void)
{
    EPwm9Regs.TBPRD = Period;                       // Set timer period
    EPwm9Regs.TBPHS.bit.TBPHS = 0x0000;           // Phase is 0
    EPwm9Regs.TBCTR = 0x0000;                     // Clear counter

    // Setup TBCLK
    EPwm9Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    EPwm9Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
    EPwm9Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
    EPwm9Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    EPwm9Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;   // Load registers every ZERO
//  EPwm9Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm9Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
//  EPwm9Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // Setup compare
    EPwm9Regs.CMPA.bit.CMPA = 0;				  // Duty=0.5

    // Set actions
    EPwm9Regs.AQCTLA.bit.CAU = AQ_CLEAR;
    EPwm9Regs.AQCTLA.bit.CAD = AQ_SET;

//  EPwm9Regs.AQCTLB.bit.CAU = AQ_CLEAR;
//  EPwm9Regs.AQCTLB.bit.CAD = AQ_SET;


    // Active Low PWMs - Setup Deadband
    EPwm9Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm9Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm9Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm9Regs.DBRED = EPWM9_MIN_DB;
    EPwm9Regs.DBFED = EPWM9_MIN_DB;
//  EPwm9_DB_Direction = DB_UP;


// ----------------configure Trip Zone -------------------
/*
    EALLOW;
    //Configure EPWM9 to output high on TZB TRIP
    EPwm9Regs.TZCTL.bit.TZA = TZ_FORCE_LO;
    EPwm9Regs.TZCTL.bit.TZB = TZ_FORCE_LO;

    //Configure DCA to be TRIP4
    EPwm9Regs.TZDCSEL.bit.DCAEVT1 = TZ_DCAH_HI;
    //EPwm9Regs.TZDCSEL.bit.DCBEVT1 = TZ_DCBH_HI;
    EPwm9Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 0xF; //DCAHTRIPSEL
    //EPwm9Regs.DCTRIPSEL.bit.DCBHCOMPSEL    = 0xF; //DCBHTRIPSEL
    EPwm9Regs.DCAHTRIPSEL.bit.TRIPINPUT4   = 1;
    //EPwm9Regs.DCBHTRIPSEL.bit.TRIPINPUT4   = 1;

    //Configure DCA as OST
    EPwm9Regs.TZSEL.bit.DCAEVT1            = 1;
    //EPwm9Regs.TZSEL.bit.DCBEVT1          = 1;
    EPwm9Regs.TZSEL.bit.OSHT1 = 1;
    EPwm9Regs.TZSEL.bit.OSHT2 = 1;
    EPwm9Regs.TZSEL.bit.OSHT3 = 1;

    //Configure DCB path to be unfiltered & async
    EPwm9Regs.DCACTL.bit.EVT1SRCSEL        = DC_EVT1;
    //EPwm9Regs.DCBCTL.bit.EVT1SRCSEL        = DC_EVT1;
    EPwm9Regs.DCACTL.bit.EVT1FRCSYNCSEL    = DC_EVT_ASYNC;
    //EPwm9Regs.DCBCTL.bit.EVT1FRCSYNCSEL    = DC_EVT_ASYNC;

    //Configure TRIP4 to be CTRIP1H
//    EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX0 = 0;
    //Enable TRIP4 Mux for Output
//    EPwmXbarRegs.TRIP4MUXENABLE.bit.MUX0   = 1;


    // Clear trip flags
    EPwm9Regs.TZCLR.bit.OST                = 1;
    EPwm9Regs.TZCLR.bit.INT                = 1;
    //Enable DCA interrupt
    EPwm9Regs.TZEINT.bit.OST               = 1;
    EDIS;
*/

    // Interrupt where we will change the Deadband
//    EPwm9Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;    // Select INT on Zero event
//    EPwm9Regs.ETSEL.bit.INTEN = 1;               // Enable INT
//    EPwm9Regs.ETPS.bit.INTPRD = ET_1ST;          // Generate INT on 3rd event
}

void InitEPwm10(void)
{
    EPwm10Regs.TBPRD = Period;                       // Set timer period
    EPwm10Regs.TBPHS.bit.TBPHS = 0x0000;           // Phase is 0
    EPwm10Regs.TBCTR = 0x0000;                     // Clear counter

    // Setup TBCLK
    EPwm10Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    EPwm10Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
    EPwm10Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
    EPwm10Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    EPwm10Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;   // Load registers every ZERO
//  EPwm10Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm10Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
//  EPwm10Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // Setup compare
    EPwm10Regs.CMPA.bit.CMPA = 0;				  // Duty=0.5

    // Set actions
    EPwm10Regs.AQCTLA.bit.CAU = AQ_CLEAR;
    EPwm10Regs.AQCTLA.bit.CAD = AQ_SET;

//  EPwm10Regs.AQCTLB.bit.CAU = AQ_CLEAR;
//  EPwm10Regs.AQCTLB.bit.CAD = AQ_SET;


    // Active Low PWMs - Setup Deadband
    EPwm10Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm10Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm10Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm10Regs.DBRED = EPWM10_MIN_DB;
    EPwm10Regs.DBFED = EPWM10_MIN_DB;
//  EPwm10_DB_Direction = DB_UP;


// ----------------configure Trip Zone -------------------
/*
    EALLOW;
    //Configure EPWM10 to output high on TZB TRIP
    EPwm10Regs.TZCTL.bit.TZA = TZ_FORCE_LO;
    EPwm10Regs.TZCTL.bit.TZB = TZ_FORCE_LO;

    //Configure DCA to be TRIP4
    EPwm10Regs.TZDCSEL.bit.DCAEVT1 = TZ_DCAH_HI;
    //EPwm10Regs.TZDCSEL.bit.DCBEVT1 = TZ_DCBH_HI;
    EPwm10Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 0xF; //DCAHTRIPSEL
    //EPwm10Regs.DCTRIPSEL.bit.DCBHCOMPSEL    = 0xF; //DCBHTRIPSEL
    //EPwm10Regs.DCAHTRIPSEL.bit.TRIPINPUT4   = 1;
    //EPwm10Regs.DCBHTRIPSEL.bit.TRIPINPUT4   = 1;
    EPwm10Regs.DCAHTRIPSEL.bit.TRIPINPUT2   = 1;
    EPwm10Regs.DCAHTRIPSEL.bit.TRIPINPUT3   = 1;

    //Configure DCA as OST
    EPwm10Regs.TZSEL.bit.DCAEVT1            = 1;
    //EPwm10Regs.TZSEL.bit.DCBEVT1          = 1;
    EPwm10Regs.TZSEL.bit.OSHT1 = 1;
    //EPwm10Regs.TZSEL.bit.OSHT2 = 1;
    //EPwm10Regs.TZSEL.bit.OSHT3 = 1;

    //Configure DCA path to be unfiltered & async
    EPwm10Regs.DCACTL.bit.EVT1SRCSEL        = DC_EVT1;
    //EPwm10Regs.DCBCTL.bit.EVT1SRCSEL        = DC_EVT1;
    EPwm10Regs.DCACTL.bit.EVT1FRCSYNCSEL    = DC_EVT_ASYNC;
    //EPwm10Regs.DCBCTL.bit.EVT1FRCSYNCSEL    = DC_EVT_ASYNC;


    // Clear trip flags
    EPwm10Regs.TZCLR.bit.OST                = 1;
    EPwm10Regs.TZCLR.bit.INT                = 1;
    //Enable DCA interrupt
    EPwm10Regs.TZEINT.bit.OST               = 1;
    EDIS;


    // Interrupt where we will change the Deadband
//    EPwm10Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;    // Select INT on Zero event
//    EPwm10Regs.ETSEL.bit.INTEN = 1;               // Enable INT
//    EPwm10Regs.ETPS.bit.INTPRD = ET_1ST;          // Generate INT on 3rd event
*/
}

void InitEPwm11(void)
{
    EPwm11Regs.TBPRD = Period;                       // Set timer period
    EPwm11Regs.TBPHS.bit.TBPHS= 0x0000;           // Phase is 0
    EPwm11Regs.TBCTR = 0x0000;                     // Clear counter

    // Setup TBCLK
    EPwm11Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
    EPwm11Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
    EPwm11Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
    EPwm11Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    EPwm11Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;   // Load registers every ZERO
//  EPwm11Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm11Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
//  EPwm11Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // Setup compare
    EPwm11Regs.CMPA.bit.CMPA = 0;				  // Duty=0.5

    // Set actions
    EPwm11Regs.AQCTLA.bit.CAU = AQ_CLEAR;
    EPwm11Regs.AQCTLA.bit.CAD = AQ_SET;

//  EPwm11Regs.AQCTLB.bit.CAU = AQ_CLEAR;
//  EPwm11Regs.AQCTLB.bit.CAD = AQ_SET;


    // Active Low PWMs - Setup Deadband
    EPwm11Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm11Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm11Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm11Regs.DBRED = EPWM11_MIN_DB;
    EPwm11Regs.DBFED = EPWM11_MIN_DB;
//  EPwm11_DB_Direction = DB_UP;


// ----------------configure Trip Zone -------------------
/*
	EALLOW;
    //Configure EPWM11 to output high on TZB TRIP
    EPwm11Regs.TZCTL.bit.TZA = TZ_FORCE_LO;
    EPwm11Regs.TZCTL.bit.TZB = TZ_FORCE_LO;

    //Configure DCA to be TRIP4
    EPwm11Regs.TZDCSEL.bit.DCAEVT1 = TZ_DCAH_HI;
    //EPwm10Regs.TZDCSEL.bit.DCBEVT1 = TZ_DCBH_HI;
    EPwm11Regs.DCTRIPSEL.bit.DCAHCOMPSEL    = 0xF; //DCAHTRIPSEL
    //EPwm10Regs.DCTRIPSEL.bit.DCBHCOMPSEL    = 0xF; //DCBHTRIPSEL
    EPwm11Regs.DCAHTRIPSEL.bit.TRIPINPUT4   = 1;
    //EPwm10Regs.DCBHTRIPSEL.bit.TRIPINPUT4   = 1;

    //Configure DCA as OST
    EPwm11Regs.TZSEL.bit.DCAEVT1            = 1;
    //EPwm10Regs.TZSEL.bit.DCBEVT1          = 1;
    EPwm11Regs.TZSEL.bit.OSHT1 = 1;
    EPwm11Regs.TZSEL.bit.OSHT2 = 1;
    EPwm11Regs.TZSEL.bit.OSHT3 = 1;

    //Configure DCA path to be unfiltered & async
    EPwm11Regs.DCACTL.bit.EVT1SRCSEL        = DC_EVT1;
    //EPwm11Regs.DCBCTL.bit.EVT1SRCSEL        = DC_EVT1;
    EPwm11Regs.DCACTL.bit.EVT1FRCSYNCSEL    = DC_EVT_ASYNC;
    //EPwm11Regs.DCBCTL.bit.EVT1FRCSYNCSEL    = DC_EVT_ASYNC;

    //Configure TRIP4 to be CTRIP1H
//    EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX0 = 0;
    //Enable TRIP4 Mux for Output
//    EPwmXbarRegs.TRIP4MUXENABLE.bit.MUX0   = 1;


    // Clear trip flags
    EPwm11Regs.TZCLR.bit.OST                = 1;
    EPwm11Regs.TZCLR.bit.INT                = 1;
    //Enable DCA interrupt
    EPwm11Regs.TZEINT.bit.OST               = 1;
    EDIS;
*/

    // Interrupt where we will change the Deadband
//    EPwm11Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;    // Select INT on Zero event
//    EPwm11Regs.ETSEL.bit.INTEN = 1;               // Enable INT
//    EPwm11Regs.ETPS.bit.INTPRD = ET_1ST;          // Generate INT on 3rd event

}
