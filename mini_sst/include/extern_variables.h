/*
 * extern_variables.h
 *
 *  Created on: May 12, 2016
 *      Author: Siyuan
 */

#ifndef INCLUDE_EXTERN_VARIABLES_H_
#define INCLUDE_EXTERN_VARIABLES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "F28x_Project.h"

#define pi 3.141592653589793

#define sqrt3div2   0.8660254038
#define   sqrt2     1.414213562
#define divsqrt3    0.5773502692  //  (1/sqrt3)
#define div3		0.3333333333  //   1/3

#define freq 60
#define Period 1334
#define StepNumber 533

extern float32 sin_result[100];

extern void InitVariable();
extern void Gateoff();
extern void GateReset();


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* INCLUDE_EXTERN_VARIABLES_H_ */
