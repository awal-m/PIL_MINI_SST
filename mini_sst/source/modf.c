/****************************************************************************/
/*  modf  v6.4.10                                                           */
/*                                                                          */
/* Copyright (c) 1995-2016 Texas Instruments Incorporated                   */
/* http://www.ti.com/                                                       */
/*                                                                          */
/*  Redistribution and  use in source  and binary forms, with  or without   */
/*  modification,  are permitted provided  that the  following conditions   */
/*  are met:                                                                */
/*                                                                          */
/*     Redistributions  of source  code must  retain the  above copyright   */
/*     notice, this list of conditions and the following disclaimer.        */
/*                                                                          */
/*     Redistributions in binary form  must reproduce the above copyright   */
/*     notice, this  list of conditions  and the following  disclaimer in   */
/*     the  documentation  and/or   other  materials  provided  with  the   */
/*     distribution.                                                        */
/*                                                                          */
/*     Neither the  name of Texas Instruments Incorporated  nor the names   */
/*     of its  contributors may  be used to  endorse or  promote products   */
/*     derived  from   this  software  without   specific  prior  written   */
/*     permission.                                                          */
/*                                                                          */
/*  THIS SOFTWARE  IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS   */
/*  "AS IS"  AND ANY  EXPRESS OR IMPLIED  WARRANTIES, INCLUDING,  BUT NOT   */
/*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR   */
/*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT   */
/*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   */
/*  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL  DAMAGES  (INCLUDING, BUT  NOT   */
/*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,   */
/*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY   */
/*  THEORY OF  LIABILITY, WHETHER IN CONTRACT, STRICT  LIABILITY, OR TORT   */
/*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE   */
/*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.    */
/*                                                                          */
/****************************************************************************/
#include <math.h>
#include <values.h>

/****************************************************************************/
/*  MODF() - break into integer and fractional parts                        */
/*                                                                          */
/*  if x < -2 ^ 23 or x > 2 ^ 23, modf will return 0, and x -> memory       */
/*                                                                          */
/*  else result = x - int(x), int(x) -> memory location                     */
/*                                                                          */
/****************************************************************************/
 
#pragma CODE_SECTION(modf, "ramfuncs");// Copy the code from flash to RAM

double modf(double value, double *iptr)
{
    double mid; /* the integral part of x */
 
    /**********************************************************************/
    /* for values >2^(bits in mantissa) or values <-2^(bits in mantissa)  */
    /**********************************************************************/
 
    if (value > TWO23 || value < - TWO23 || value == 0.0)
    {
        *iptr = value;
 
        /******************************************************************/
        /* fraction = 0                                                   */
        /******************************************************************/
 
        return 0.0;
    }
    else
    {
        /******************************************************************/
	/* This will be incorrect for values larger than 32-bits.         */
        /******************************************************************/
        mid = (long) value;     /* since (long) -1.5 = -1.0 */
 
        /******************************************************************/
        /* save the integer part of value where iptr points               */
        /******************************************************************/
 
        *iptr = mid;
 
        /******************************************************************/
        /* return the fractional part of value                            */
        /******************************************************************/
 
        return (value - mid);
    }
}
