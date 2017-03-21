################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../source/F2837xS_CodeStartBranch.asm \
../source/F2837xS_DBGIER.asm \
../source/F2837xS_usDelay.asm 

C_SRCS += \
../source/Config_ADC_PeriClks.c \
../source/Config_EPWM.c \
../source/Config_GPIO.c \
../source/Config_SCI_C.c \
../source/F2837xS_Adc.c \
../source/F2837xS_CpuTimers.c \
../source/F2837xS_DefaultISR.c \
../source/F2837xS_Dma.c \
../source/F2837xS_ECap.c \
../source/F2837xS_EPwm.c \
../source/F2837xS_EQep.c \
../source/F2837xS_Emif.c \
../source/F2837xS_GlobalVariableDefs.c \
../source/F2837xS_Gpio.c \
../source/F2837xS_I2C.c \
../source/F2837xS_Mcbsp.c \
../source/F2837xS_MemCopy.c \
../source/F2837xS_PieCtrl.c \
../source/F2837xS_PieVect.c \
../source/F2837xS_Sci.c \
../source/F2837xS_Spi.c \
../source/F2837xS_SysCtrl.c \
../source/F2837xS_Upp.c \
../source/F2837xS_sci_io.c \
../source/F2837xS_sdfm_drivers.c \
../source/F2837xS_struct.c \
../source/fabs.c \
../source/filter.c \
../source/fmod.c \
../source/modf.c \
../source/protection.c \
../source/variables.c 

C_DEPS += \
./source/Config_ADC_PeriClks.d \
./source/Config_EPWM.d \
./source/Config_GPIO.d \
./source/Config_SCI_C.d \
./source/F2837xS_Adc.d \
./source/F2837xS_CpuTimers.d \
./source/F2837xS_DefaultISR.d \
./source/F2837xS_Dma.d \
./source/F2837xS_ECap.d \
./source/F2837xS_EPwm.d \
./source/F2837xS_EQep.d \
./source/F2837xS_Emif.d \
./source/F2837xS_GlobalVariableDefs.d \
./source/F2837xS_Gpio.d \
./source/F2837xS_I2C.d \
./source/F2837xS_Mcbsp.d \
./source/F2837xS_MemCopy.d \
./source/F2837xS_PieCtrl.d \
./source/F2837xS_PieVect.d \
./source/F2837xS_Sci.d \
./source/F2837xS_Spi.d \
./source/F2837xS_SysCtrl.d \
./source/F2837xS_Upp.d \
./source/F2837xS_sci_io.d \
./source/F2837xS_sdfm_drivers.d \
./source/F2837xS_struct.d \
./source/fabs.d \
./source/filter.d \
./source/fmod.d \
./source/modf.d \
./source/protection.d \
./source/variables.d 

OBJS += \
./source/Config_ADC_PeriClks.obj \
./source/Config_EPWM.obj \
./source/Config_GPIO.obj \
./source/Config_SCI_C.obj \
./source/F2837xS_Adc.obj \
./source/F2837xS_CodeStartBranch.obj \
./source/F2837xS_CpuTimers.obj \
./source/F2837xS_DBGIER.obj \
./source/F2837xS_DefaultISR.obj \
./source/F2837xS_Dma.obj \
./source/F2837xS_ECap.obj \
./source/F2837xS_EPwm.obj \
./source/F2837xS_EQep.obj \
./source/F2837xS_Emif.obj \
./source/F2837xS_GlobalVariableDefs.obj \
./source/F2837xS_Gpio.obj \
./source/F2837xS_I2C.obj \
./source/F2837xS_Mcbsp.obj \
./source/F2837xS_MemCopy.obj \
./source/F2837xS_PieCtrl.obj \
./source/F2837xS_PieVect.obj \
./source/F2837xS_Sci.obj \
./source/F2837xS_Spi.obj \
./source/F2837xS_SysCtrl.obj \
./source/F2837xS_Upp.obj \
./source/F2837xS_sci_io.obj \
./source/F2837xS_sdfm_drivers.obj \
./source/F2837xS_struct.obj \
./source/F2837xS_usDelay.obj \
./source/fabs.obj \
./source/filter.obj \
./source/fmod.obj \
./source/modf.obj \
./source/protection.obj \
./source/variables.obj 

ASM_DEPS += \
./source/F2837xS_CodeStartBranch.d \
./source/F2837xS_DBGIER.d \
./source/F2837xS_usDelay.d 

OBJS__QUOTED += \
"source\Config_ADC_PeriClks.obj" \
"source\Config_EPWM.obj" \
"source\Config_GPIO.obj" \
"source\Config_SCI_C.obj" \
"source\F2837xS_Adc.obj" \
"source\F2837xS_CodeStartBranch.obj" \
"source\F2837xS_CpuTimers.obj" \
"source\F2837xS_DBGIER.obj" \
"source\F2837xS_DefaultISR.obj" \
"source\F2837xS_Dma.obj" \
"source\F2837xS_ECap.obj" \
"source\F2837xS_EPwm.obj" \
"source\F2837xS_EQep.obj" \
"source\F2837xS_Emif.obj" \
"source\F2837xS_GlobalVariableDefs.obj" \
"source\F2837xS_Gpio.obj" \
"source\F2837xS_I2C.obj" \
"source\F2837xS_Mcbsp.obj" \
"source\F2837xS_MemCopy.obj" \
"source\F2837xS_PieCtrl.obj" \
"source\F2837xS_PieVect.obj" \
"source\F2837xS_Sci.obj" \
"source\F2837xS_Spi.obj" \
"source\F2837xS_SysCtrl.obj" \
"source\F2837xS_Upp.obj" \
"source\F2837xS_sci_io.obj" \
"source\F2837xS_sdfm_drivers.obj" \
"source\F2837xS_struct.obj" \
"source\F2837xS_usDelay.obj" \
"source\fabs.obj" \
"source\filter.obj" \
"source\fmod.obj" \
"source\modf.obj" \
"source\protection.obj" \
"source\variables.obj" 

C_DEPS__QUOTED += \
"source\Config_ADC_PeriClks.d" \
"source\Config_EPWM.d" \
"source\Config_GPIO.d" \
"source\Config_SCI_C.d" \
"source\F2837xS_Adc.d" \
"source\F2837xS_CpuTimers.d" \
"source\F2837xS_DefaultISR.d" \
"source\F2837xS_Dma.d" \
"source\F2837xS_ECap.d" \
"source\F2837xS_EPwm.d" \
"source\F2837xS_EQep.d" \
"source\F2837xS_Emif.d" \
"source\F2837xS_GlobalVariableDefs.d" \
"source\F2837xS_Gpio.d" \
"source\F2837xS_I2C.d" \
"source\F2837xS_Mcbsp.d" \
"source\F2837xS_MemCopy.d" \
"source\F2837xS_PieCtrl.d" \
"source\F2837xS_PieVect.d" \
"source\F2837xS_Sci.d" \
"source\F2837xS_Spi.d" \
"source\F2837xS_SysCtrl.d" \
"source\F2837xS_Upp.d" \
"source\F2837xS_sci_io.d" \
"source\F2837xS_sdfm_drivers.d" \
"source\F2837xS_struct.d" \
"source\fabs.d" \
"source\filter.d" \
"source\fmod.d" \
"source\modf.d" \
"source\protection.d" \
"source\variables.d" 

ASM_DEPS__QUOTED += \
"source\F2837xS_CodeStartBranch.d" \
"source\F2837xS_DBGIER.d" \
"source\F2837xS_usDelay.d" 

C_SRCS__QUOTED += \
"../source/Config_ADC_PeriClks.c" \
"../source/Config_EPWM.c" \
"../source/Config_GPIO.c" \
"../source/Config_SCI_C.c" \
"../source/F2837xS_Adc.c" \
"../source/F2837xS_CpuTimers.c" \
"../source/F2837xS_DefaultISR.c" \
"../source/F2837xS_Dma.c" \
"../source/F2837xS_ECap.c" \
"../source/F2837xS_EPwm.c" \
"../source/F2837xS_EQep.c" \
"../source/F2837xS_Emif.c" \
"../source/F2837xS_GlobalVariableDefs.c" \
"../source/F2837xS_Gpio.c" \
"../source/F2837xS_I2C.c" \
"../source/F2837xS_Mcbsp.c" \
"../source/F2837xS_MemCopy.c" \
"../source/F2837xS_PieCtrl.c" \
"../source/F2837xS_PieVect.c" \
"../source/F2837xS_Sci.c" \
"../source/F2837xS_Spi.c" \
"../source/F2837xS_SysCtrl.c" \
"../source/F2837xS_Upp.c" \
"../source/F2837xS_sci_io.c" \
"../source/F2837xS_sdfm_drivers.c" \
"../source/F2837xS_struct.c" \
"../source/fabs.c" \
"../source/filter.c" \
"../source/fmod.c" \
"../source/modf.c" \
"../source/protection.c" \
"../source/variables.c" 

ASM_SRCS__QUOTED += \
"../source/F2837xS_CodeStartBranch.asm" \
"../source/F2837xS_DBGIER.asm" \
"../source/F2837xS_usDelay.asm" 


