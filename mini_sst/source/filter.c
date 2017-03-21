/*
 * filter.c
 *
 *  Created on: May 27, 2016
 *      Author: Siyuan
 */


#include "filter.h"

#pragma CODE_SECTION(LPF, "ramfuncs");

float32 LPF(float32 x, LPF_Pointer LPF_p)
{
	float32 y;

	y=LPF_p->Kxn*x+LPF_p->Kxn*LPF_p->xn+LPF_p->Kyn*LPF_p->yn;
	LPF_p->yn=y;
	LPF_p->xn=x;

	return y;
}

void LPF_initialize(LPF_Pointer LPF_p, float32 fc, float32 Ts)
{
	float32 a;
	float32 Wc;
	Wc=2*pi*fc;

	a=1.0/(2.0+Ts*Wc);
	LPF_p->Kxn=Ts*Wc*a;
	LPF_p->Kyn=(2.0-Ts*Wc)*a;
	LPF_p->yn=0.0;
	LPF_p->xn=0.0;

}
