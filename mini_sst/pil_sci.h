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

#ifndef PIL_SCI_H_
#define PIL_SCI_H_

// bit-masks for "mode"
#define ONE_STOPBIT 0x00
#define TWO_STOPBITS 0x80
#define NO_PARITY 0x00
#define ODD_PARITY 0x20
#define EVEN_PARITY 0x60
#define SEVEN_BITS 0x06
#define EIGHT_BITS 0x07
#define SCI_LOOPBACK 0x10

// compile options
#define USE_SCI_FIFO

// receive character
extern int16_t SCIGetChar(void);
// send character
extern void SCIPutChar(char c);
// initialize serial interface
extern void SCIInit (uint16_t mode, uint32_t baudrate, uint32_t clk);
// write string
extern void SCIWriteString(const char *s);

extern void SCIPoll();

#endif /* PIL_SCI_H_ */
