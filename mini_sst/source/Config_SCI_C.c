#include "Mini_SST.h"
#pragma CODE_SECTION(scic_xmit, "ramfuncs");

void scic_init(void)
{
	ScicRegs.SCICCR.all = 0x0007;   // 1 stop bit,  No loopback
	                                   // No parity,8 char bits,
	                                   // async mode, idle-line protocol
	ScicRegs.SCICTL1.all = 0x0003;  // enable TX, RX, internal SCICLK,
	                                   // Disable RX ERR, SLEEP, TXWAKE
	ScicRegs.SCICTL2.bit.TXINTENA = 1;
	ScicRegs.SCICTL2.bit.RXBKINTENA = 1;


	ScicRegs.SCIHBAUD.bit.BAUD    = 0x0000;  //LSPCLK = 50MHz (200 MHz SYSCLK).
	ScicRegs.SCILBAUD.bit.BAUD    = 0x0035;	 //Async BAUD=LSPCLK/((BRR+1)*8);
											 //BRR=LSPCLK/(Async_BAUD*8)-1;

	ScicRegs.SCICTL1.all = 0x0023;  // Relinquish SCI from Reset

	ScicRegs.SCIFFTX.bit.TXFIFOXRESET =1;
	ScicRegs.SCIFFRX.bit.RXFIFORESET=1;
}

void scic_xmit(int x)
{
	while (ScicRegs.SCIFFTX.bit.TXFFST != 0) {}
	    ScicRegs.SCITXBUF.bit.TXDT=x;
}


void scic_fifo_init()
{
    ScicRegs.SCIFFTX.all=0xE040;
    ScicRegs.SCIFFRX.all=0x2044;
    ScicRegs.SCIFFCT.all=0x0;

}
