//###########################################################################
// FILE:   mini_sst.c
// TITLE:  Control code for front end bidirectional rectifier and 380VDC buck port
// Author: M A Awal
//
//###########################################################################
//
// Hardware Description
//
// PWM:
// PWM2, PWM6 and PWM10 for PWM
// PWM2 interrupt is used for control updating

// Sensing- ADC :
// A2, A5
// B1, B2, B4, B5
//


// Relay:
// P61, P41
// P65, P69
//
// OverTemp:
// P72
//
// RST:
// P4
//
// RDY:
// P78
//
// DESAT:
// P73
//

//###########################################################################

#include "Mini_SST.h"
#include "Solar_F.h"
#include "Control.h"

#include "pil_includes.h"

GlobalVars_t GVars;

#pragma CODE_SECTION(epwm2_isr, "ramfuncs");// Copy the code from flash to RAM


void InitEPwm2(void);
void InitEPwm6(void);
void InitEPwm10(void);

__interrupt void epwm2_isr(void);
void InitEPwmGpio_TZ(void);
void ConfigureADC(void);
void SetupADCSoftware(void);
void InitPeripheralClks();
void BlinkLED(void);

void MemCopy(Uint16 *SourceAddr, Uint16* SourceEndAddr, Uint16* DestAddr);		// For Copying the code from flash to RAM

//void scic_init(void);
//void scic_fifo_init(void);
//void scic_xmit(int x);

// Test Variables
Uint32 i=0;
int32 control_c=0;
int32 Relay1_c=0;
int32 Relay2_c=0;
int32 Relay3_c=0;
int32 Relay4_c=0;
float32 x_DB[1250];

// Control variables
float32 Vg,Vac,Vdc,VDCLK,Iac,Idc;
float32 m_ac=0;
float32 m_dc=0;
float32 Iac_pref=0;
float32 Iac_pref_old=0;

// Filter and compensator states
float32 V1s[2]={0,0};
float32 V1f[2]={0,0};

float32 V2s[2]={0,0};
float32 V2f[2]={0,0};

float32 V3s[2]={0,0};
float32 V3f[2]={0,0};

float32 V4s[2]={0,0};
float32 V4f[2]={0,0};

float32 I1s[2]={0,0};
float32 I1f[2]={0,0};

float32 I2s[2]={0,0};
float32 I2f[2]={0,0};

float32 Iac_err[3]={0,0,0};
float32 Iac_PR[3]={0,0,0};

float32 DCLK_err[2]={0,0};
float32 DCLK_PI[2]={0,0};

float32 DC_err[2]={0,0};
float32 DC_PI[2]={0,0};

//Startup flags
int StartUp=0;
int DB=1;
float32 SUtimer=0;
float32 x=0;



SPLL_1ph_SOGI_F	SPLL_Vg; // SOGI PLL object
NOTCH_COEFF_F NF_f2;        //Notch filter@120Hz coefficients
NOTCH_VARS_F VDCLK_f;       //Notch Filter@120Hz object for DC bus voltage

// For blinking Launchpad LED
volatile uint16_t LEDTimer = 0;

void main(void)
{

    InitSysCtrl();
    InitPeripheralClks();

    InitGpio();
    InitEPwmGpio_TZ();

    DINT;
    InitPieCtrl();
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();
	EALLOW;
	PieVectTable.EPWM2_INT = &epwm2_isr;
	EDIS;

	MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);

	EALLOW;
	CpuSysRegs.PCLKCR0.bit.TBCLKSYNC =0;
	ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = 0;		// SYSCLKOUT equals EPWMCLK
	EDIS;

	// Configure GPIO12 to Blink LED onboard
	GPIO_SetupPinMux(12, GPIO_MUX_CPU1, 0);
	GPIO_SetupPinOptions(12, GPIO_OUTPUT, GPIO_PUSHPULL);
	//#####################################################


	SPLL_1ph_SOGI_F_init(GRID_FREQ,((float)(1.0/ISR_FREQUENCY)),&SPLL_Vg);
	SPLL_1ph_SOGI_F_coeff_update(((float)(1.0/ISR_FREQUENCY)),(float)(2*PI*GRID_FREQ),&SPLL_Vg);
	NOTCH_FLTR_F_VARS_init(&VDCLK_f);
	NOTCH_FLTR_F_COEFF_Update(((float)(1.0/ISR_FREQUENCY)), (float)(2*PI*GRID_FREQ*2),(float)c2,(float)c1, &NF_f2);


	InitEPwm2();
 	InitEPwm6();
 	InitEPwm10();

	EALLOW;
	CpuSysRegs.PCLKCR0.bit.TBCLKSYNC =1;
	EDIS;

	ConfigureADC();
	SetupADCSoftware();

	// configure serial line
	SCIInit(ONE_STOPBIT+ NO_PARITY + EIGHT_BITS, BAUD_RATE, LSPCLK_HZ);
	SCIWriteString("\n\rSerial link initialized.\n\r");

	// initialize PIL framework
	PIL_init();
	PIL_setLinkParams((unsigned char*)&PIL_D_Guid[0], (PIL_CommCallbackPtr_t)SCIPoll);
	PIL_setCtrlCallback((PIL_CtrlCallbackPtr_t)PilCallback);

	PilInitOverrideProbes();

	IER |= M_INT3;
	PieCtrlRegs.PIEIER3.bit.INTx2 = 1;
    EINT;  // Enable Global interrupt INTM
    ERTM;  // Enable Global realtime interrupt DBGM

    for(;;)
    {
        BlinkLED();
		PIL_backgroundCall();
    }
}

__interrupt void epwm2_isr(void)
{
	PIL_beginInterruptCall();

	GVars.stepCtr++;

    //start conversions immediately via software, ADCA and ADCB
	AdcaRegs.ADCSOCFRC1.all = 0x0003;   //SOC0, SOC1
	AdcbRegs.ADCSOCFRC1.all = 0x000F;   //SOC0, SOC1, SOC2, SOC3

	while(AdcaRegs.ADCINTFLG.bit.ADCINT1 == 0 || AdcbRegs.ADCINTFLG.bit.ADCINT1 == 0);

	/*		 Read ADC Result		*/
	V1s[0]=AdcbResultRegs.ADCRESULT0;
	V2s[0]=AdcbResultRegs.ADCRESULT1;
	V3s[0]=AdcaResultRegs.ADCRESULT0;
	V4s[0]=AdcaResultRegs.ADCRESULT1;
	I1s[0]=AdcbResultRegs.ADCRESULT2;
	I2s[0]=AdcbResultRegs.ADCRESULT3;
	//End of ADC reading

	SET_OPROBE(GVars.inF, 1.0);
	GVars.outF = 2.0 * GVars.inF;

	if (control_c==1)
	{
		Gateoff();
		control_c=0;
	}

	else if(control_c==2)
	{
		GateReset();
		control_c=0;
	}


/*      1st Order LPF      */
	V1f[0]=FLPF_b0*V1s[0]+FLPF_b1*V1s[1]-FLPF_a1*V1f[1];
	V1s[1]=V1s[0];
	V1f[1]=V1f[0];

	V2f[0]=FLPF_b0*V2s[0]+FLPF_b1*V2s[1]-FLPF_a1*V2f[1];
	V2s[1]=V2s[0];
	V2f[1]=V2f[0];

	V3f[0]=FLPF_b0*V3s[0]+FLPF_b1*V3s[1]-FLPF_a1*V3f[1];
	V3s[1]=V3s[0];
	V3f[1]=V3f[0];

	V4f[0]=FLPF_b0*V4s[0]+FLPF_b1*V4s[1]-FLPF_a1*V4f[1];
	V4s[1]=V4s[0];
	V4f[1]=V4f[0];

	I1f[0]=FLPF_b0*I1s[0]+FLPF_b1*I1s[1]-FLPF_a1*I1f[1];
	I1s[1]=I1s[0];
	I1f[1]=I1f[0];

	I2f[0]=FLPF_b0*I2s[0]+FLPF_b1*I2s[1]-FLPF_a1*I2f[1];
	I2s[1]=I2s[0];
	I2f[1]=I2f[0];
// End of LPF of ADC results

// Sensor and ADC gain scaling
	Vac=V3_b0+V3_b1*V3f[0];
	Vg=V4_b0+V4_b1*V4f[0];
	Vdc=V2_b0+V2_b1*V2f[0];
	VDCLK=V1_b0+V1_b1*V1f[0];
	Iac=-I2_b0-I2_b1*I2f[0];
	Idc=I1_b0+I1_b1*I1f[0];
// End of sensor and ADC gain scaling

// Run PLL on grid voltage
	SPLL_Vg.u[0]=(float32) Vg/450;
	SPLL_1ph_SOGI_F_MACRO(SPLL_Vg);
// End of PLL on grid voltage

	// ##################################### Soft start-up #################################
	/*if(StartUp==0)
	{
	    if(SUtimer<75000)
	        SUtimer++;
	    else if(fabs(SPLL_Vg.u_Q[0])>353)  //90% of rated 277VAC
	        StartUp=1;
	    else if(Vdc>342)                //90% of rated 380VDC
	        StartUp=2;
	}
	else if(StartUp==1)
	{
	    GpioDataRegs.GPCSET.bit.GPIO65 = 1;
	    StartUp=3;
	}
	else if(StartUp==2)
	{
	    GpioDataRegs.GPBSET.bit.GPIO61 = 1;
	    StartUp=4;
	}
	else if(StartUp==3 || StartUp==4)
	{
	    if(SUtimer<150000)
	        SUtimer++;
	    else if((StartUp==3) && (VDCLK>.98*fabs(SPLL_Vg.u_Q[0])))
	    {
	        StartUp=5;
	        GpioDataRegs.GPCSET.bit.GPIO69 = 1;
	    }
	    else if((StartUp==4) && (VDCLK>.98*Vdc))
	    {
	        StartUp=6;
	        GpioDataRegs.GPBSET.bit.GPIO41 = 1;
	    }
	}*/
// ###################################################################

	if(StartUp>4)
	{
	    // Run notch filter to remove 2nd harmonic from DC link voltage
	        VDCLK_f.In=400+15*sin(2*W*i);//VDCLK;
	        NOTCH_FLTR_F_run(&VDCLK_f,&NF_f2);
	    // End of notch filter

	    // VDCLK PI calculations
	        DCLK_err[0]=VDCBUS-VDCLK_f.Out;
	        DCLK_PI[0]=DCLK_PI_b0*DCLK_err[0]+DCLK_PI_b1*DCLK_err[1]-DCLK_PI_a1*DCLK_PI[1];
	        DCLK_err[1]=DCLK_err[0];
	        DCLK_PI[1]=DCLK_PI[0];
	        Iac_pref=DCLK_PI[0];
	    // End of VDCLK PI calculations
	    // 380VDC buck port PI calculations
	        DC_err[0]=VDCsetpoint-Vdc;
	        DC_PI[0]=DC_PI_b0*DC_err[0]+DC_PI_b1*DC_err[1]-DC_PI_a1*DC_PI[1];
	        DC_err[1]=DC_err[0];
	        DC_PI[1]=DC_PI[0];
	        m_dc=(DC_PI[0]-Idc)*0.007018451672913; // Gc_inner/470
	     // End of 380VDC buck port PI calculations


	    // Saturation for Iac reference
	        if(Iac_pref>Iac_max)
	            Iac_pref=Iac_max;
	        if(Iac_pref<-Iac_max)
	            Iac_pref=-Iac_max;
	    //End of saturation for Iac reference

	    // PR compensator calculations
	        Iac_err[0]=Iac_pref*sin(SPLL_Vg.theta[0])-Iac;
	        Iac_PR[0]=PR_b0*Iac_err[0]+PR_b1*Iac_err[1]+PR_b2*Iac_err[2]-PR_a1*Iac_PR[1]-PR_a2*Iac_PR[2];
	        Iac_err[2]=Iac_err[1];
	        Iac_err[1]=Iac_err[0];
	        Iac_PR[2]=Iac_PR[1];
	        Iac_PR[1]=Iac_PR[0];
	        //m_ac=Iac_PR[0];
	    // End of PR calculations

	    // Saturation for Iac modulation
	        if(m_ac>m_max)
	            m_ac=m_max;
	        else if(m_ac<-m_max)
	            m_ac=-m_max;
	    // End of saturation for Iac modulation

	    // CCS debug plot
	        /*
	        if(DB==1)
	        {
	            x_DB[i]=Vc;
	        }
	        else if(DB==2)
	        {
	            x_DB[i]=Vg;
	        }
	        i++;
            if(i==1249) i=0;
	     */
	    // End of CCS Debug plot







	        //m_ac=.9*sin(W*i);

	        EPwm2Regs.CMPA.bit.CMPA= (int) Period*(.5+m_ac/2);
	        EPwm6Regs.CMPA.bit.CMPA= (int) Period*(.5+m_ac/2);
	        EPwm10Regs.CMPA.bit.CMPA=(int) Period*(m_dc);



	}
	LEDTimer++;
	AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;
	AdcbRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;

    // Clear INT flag for this timer
    EPwm2Regs.ETCLR.bit.INT = 1;

    // Acknowledge this interrupt to receive more interrupts from group 3
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}





void BlinkLED(void)
{
    static _Bool LED;
    if(LEDTimer>37499)
    {
        if(LED)
        {
            GPIO_WritePin(12, 0);
            LED=0;
        }
        else{
            GPIO_WritePin(12, 1);
            LED=1;
        }
        LEDTimer=0;
    }

}



