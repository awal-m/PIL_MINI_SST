// References 
#define Iac_max         45
#define m_max           0.95
#define VDCBUS          450
#define VDCsetpoint     380

// PLL Parameters
#define	PI		        3.14159265359
#define GRID_FREQ		60
#define	ISR_FREQUENCY	75000	//=1/T_PWM

// Notch Filter Parameters
#define c1	0.1
#define c2	0.00001

#define W		0.005026548245744

// First order LPF
/*#define FLPF_b0 0.295218277550778
#define FLPF_b1 0.295218277550778
#define FLPF_a1 -0.409563444898444 //BW=15kHz
*/
#define FLPF_b0 0.094793050123664
#define FLPF_b1 0.094793050123664
#define FLPF_a1 -0.810413899752672

// Sensor and ADC gains
#define	V1_b0	-510.9599073624481
#define	V1_b1	0.3125088986410

#define	V2_b0	-516.5982623771416
#define	V2_b1	0.3575687731730

#define	V3_b0	-508.3701660091357
#define	V3_b1	0.3122801941164

#define	V4_b0	-503.0871215391882
#define	V4_b1	0.3265597423460

#define	I1_b0	66.406490493061895
#define	I1_b1	-0.027975957251376

#define	I2_b0	65.462869378587641
#define	I2_b1	-0.029012336094684

// DC Link voltage PI controller gains
#define DCLK_PI_b0  0.062015818285826
#define DCLK_PI_b1  -0.062014259677899
#define DCLK_PI_a1  -1

// DC Port PI controller gains
#define DC_PI_b0  0.046666666666667
#define DC_PI_b1  -0.033333333333333
#define DC_PI_a1  -1

// AC current control PR gains
#define PR_b0	3.350484927405215
#define PR_b1	-6.597263191929562
#define PR_b2	3.246857681397085

#define PR_a1	-1.999974733972327
#define PR_a2	1
