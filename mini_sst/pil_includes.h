#ifndef PIL_INCLUDES_H_
#define PIL_INCLUDES_H_

#define SYSCLK_HZ 200000000L
#define LSPCLK_HZ (SYSCLK_HZ / 4L)

// Baudrate for serial link
#define BAUD_RATE 115200L

#include "F2837xS_Device.h"
#include "F2837xS_SysCtrl.h"
#include "F2837xS_sci.h"

// PIL includes
#include "pil.h"
#include "pil_sci.h"

#endif // PIL_INCLUDES_H_
