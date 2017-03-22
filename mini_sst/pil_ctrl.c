/*
   Copyright (c) 2014-2016 by Plexim GmbH
   All rights reserved.

   A free license is granted to anyone to use this software for any legal
   non safety-critical purpose, including commercial applications, provided
   that:
   1) IT IS NOT USED TO DIRECTLY OR INDIRECTLY COMPETE WITH PLEXIM, and
   2) THIS COPYRIGHT NOTICE IS PRESERVED in its entirety.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
 */

#include "pil_includes.h"

void PilCallback(PIL_CtrlCallbackReq_t aCallbackReq)
{
	switch(aCallbackReq)
	{
		case  PIL_CLBK_ENTER_NORMAL_OPERATION_REQ:
			// enabling the hardware actuation (if desired by user)
			PIL_inhibitPilSimulation();
			return;

		case PIL_CLBK_LEAVE_NORMAL_OPERATION_REQ:
			// stopping the hardware actuation or invoking a transfer to a safe system state
			PIL_allowPilSimulation();
			return;

		case PIL_CLBK_INITIALIZE_SIMULATION:
			// reset and initialize controls here
			return;

		case PIL_CLBK_TERMINATE_SIMULATION:
		     break;

		case PIL_CLBK_STOP_TIMERS:
			EALLOW;
			CpuSysRegs.PCLKCR2.bit.EPWM1 = 0; // ePWM1
			CpuSysRegs.PCLKCR2.bit.EPWM2 = 0; // ePWM2
			CpuSysRegs.PCLKCR2.bit.EPWM3 = 0; // ePWM3
			CpuSysRegs.PCLKCR2.bit.EPWM4 = 0; // ePWM4
			CpuSysRegs.PCLKCR2.bit.EPWM5 = 0; // ePWM5
			CpuSysRegs.PCLKCR2.bit.EPWM6 = 0; // ePWM6
			CpuSysRegs.PCLKCR2.bit.EPWM7 = 0; // ePWM7
			CpuSysRegs.PCLKCR2.bit.EPWM8 = 0; // ePWM8
			EDIS;
			return;

		case PIL_CLBK_START_TIMERS:
			EALLOW;
			CpuSysRegs.PCLKCR2.bit.EPWM1 = 1; // ePWM1
			CpuSysRegs.PCLKCR2.bit.EPWM2 = 1; // ePWM2
			CpuSysRegs.PCLKCR2.bit.EPWM3 = 1; // ePWM3
			CpuSysRegs.PCLKCR2.bit.EPWM4 = 1; // ePWM4
			CpuSysRegs.PCLKCR2.bit.EPWM5 = 1; // ePWM5
			CpuSysRegs.PCLKCR2.bit.EPWM6 = 1; // ePWM6
			CpuSysRegs.PCLKCR2.bit.EPWM7 = 1; // ePWM7
			CpuSysRegs.PCLKCR2.bit.EPWM8 = 1; // ePWM8
			EDIS;
			return;
   }
}

