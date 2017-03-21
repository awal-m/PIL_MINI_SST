/*
 * variables.c
 *
 *  Created on: May 9, 2016
 *      Author: GridBridgeUser
 */


#include "extern_variables.h"

float32 sin_result[100];


void InitVariable(void)
{
	int32 i;
	for(i=0;i<100;i++)
	{
		sin_result[i]=0;
	}
}



