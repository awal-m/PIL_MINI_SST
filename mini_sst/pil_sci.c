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

/*
 * Initializes serial interface (SCI) 
 */
void SCIInit (uint16_t mode, // parity, bits, and stop-bit
				uint32_t baudrate,  // baudrate
				uint32_t clk // low-speed clk frequency
				){
	int16_t brr;

	asm(" eallow");

	CpuSysRegs.PCLKCR7.bit.SCI_A = 1;

    SciaRegs.SCICTL1.all = 0;        // reset SCI 
    SciaRegs.SCICCR.all = mode;
    SciaRegs.SCICTL1.all = 0x0013;    // enable TX, RX, Internal SCICLK,disable RX ERR, SLEEP, TXWAKE

 	brr = (Uint16)(clk /8l /baudrate) - 1;
    SciaRegs.SCIHBAUD.all = 0xFF & (brr>>8);
    SciaRegs.SCILBAUD.all = 0xFF & brr;

#ifdef USE_SCI_FIFO
    // setup FIFO
    SciaRegs.SCIFFTX.all=0xC000;
    SciaRegs.SCIFFRX.all=0x0000;
    SciaRegs.SCIFFCT.all=0x00;
#endif

    SciaRegs.SCICTL1.all = 0x0033;         // relinquish SCI from Reset */
#ifdef USE_SCI_FIFO
    SciaRegs.SCIFFTX.bit.TXFIFOXRESET=1;
    SciaRegs.SCIFFRX.bit.RXFIFORESET=1;
#endif

	/* enable pins
	 * GPIO84/SCITXDA/MDXB/MDXA
	 * GPIO85/EM1D0/SCIRXDA/MDRB/MDR
	 *
	 * */
	GpioCtrlRegs.GPCPUD.bit.GPIO85 = 0;    // enable pull-up for GPIO85 (SCIRXDA)
	GpioCtrlRegs.GPCPUD.bit.GPIO84 = 0;	   // enable pull-up for GPIO84 (SCITXDA)
	GpioCtrlRegs.GPCQSEL2.bit.GPIO85 = 3;  // asynch input GPIO85 (SCIRXDA)

	GpioCtrlRegs.GPCMUX2.bit.GPIO85 = 1;   // configure GPIO85 for SCIRXDA operation
	GpioCtrlRegs.GPCGMUX2.bit.GPIO85 = 1;
	GpioCtrlRegs.GPCMUX2.bit.GPIO84 = 1;   // configure GPIO84 for SCITXDA operation
	GpioCtrlRegs.GPCGMUX2.bit.GPIO84 = 1;

	asm(" edis");
}

/*
 * Receive character 
 */
int16_t SCIGetChar(void){
#ifdef USE_SCI_FIFO
	if(SciaRegs.SCIFFRX.bit.RXFFST == 0){
#else
	if(SciaRegs.SCIRXST.bit.RXRDY == 0){
#endif
    	// nothing there...
        return(-1);
    }else{
		return((int16)SciaRegs.SCIRXBUF.all);
    }
}

/*
 * Transmit character 
 */
void SCIPutChar(char c){
	// make sure transmit buffer is ready
    while(SciaRegs.SCICTL2.bit.TXRDY == 0){
		continue;
    }

	SciaRegs.SCITXBUF.all = (uint16_t)c;
}

/*
 * Write string
 */
void SCIWriteString(const char *s){
	uint16_t sc;

	sc = (char)(*s);
	while(sc != 0){
		SCIPutChar(sc);
		s++;
		sc = (char)(*s);
	}
}

#ifndef USE_SCI_FIFO
#error SCIPoll() implementation assumes use of FIFO!
#endif
void SCIPoll()
{
	if((SciaRegs.SCIRXST.all & 0x0080) != 0){
		// break condition occurred - need for TI boards powered by USB
		EALLOW;
		SciaRegs.SCICTL1.all = 0;       // reset
		SciaRegs.SCICTL1.all = 0x0013;  // enable tx, rx
		SciaRegs.SCICTL1.all = 0x0033;  // relinquish from reset
	    EDIS;
	}

	while(SciaRegs.SCIFFRX.bit.RXFFST != 0)
	{
		// assuming that there will be a "break" when FIFO is empty
		PIL_RA_serialIn((int16)SciaRegs.SCIRXBUF.all);
	}

	int16_t ch;
	if(SciaRegs.SCICTL2.bit.TXRDY == 1){
		if(PIL_RA_serialOut(&ch))
		{
			SciaRegs.SCITXBUF.all = ch;
		}
	}
}

