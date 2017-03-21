/*
 * filter.h
 *
 *  Created on: May 27, 2016
 *      Author: Siyuan
 */

#ifndef INCLUDE_FILTER_H_
#define INCLUDE_FILTER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "F28x_Project.h"
#include "extern_variables.h"
#include "math.h"

typedef struct{

	/* Parameters */
	float32	Kxn;
	float32	Kyn;
	float32 xn;
	float32	yn;

}LPF_Obj;

typedef LPF_Obj *LPF_Pointer;

extern float32 LPF(float32 x, LPF_Pointer LPF_p);
extern void LPF_initialize(LPF_Pointer LPF_p, float32 fc, float32 Ts);

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* INCLUDE_FILTER_H_ */
