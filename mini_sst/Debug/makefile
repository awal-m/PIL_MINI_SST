################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./mini_sst.obj" \
"./source/Config_ADC_PeriClks.obj" \
"./source/Config_EPWM.obj" \
"./source/Config_GPIO.obj" \
"./source/Config_SCI_C.obj" \
"./source/F2837xS_Adc.obj" \
"./source/F2837xS_CodeStartBranch.obj" \
"./source/F2837xS_CpuTimers.obj" \
"./source/F2837xS_DBGIER.obj" \
"./source/F2837xS_DefaultISR.obj" \
"./source/F2837xS_Dma.obj" \
"./source/F2837xS_ECap.obj" \
"./source/F2837xS_EPwm.obj" \
"./source/F2837xS_EQep.obj" \
"./source/F2837xS_Emif.obj" \
"./source/F2837xS_GlobalVariableDefs.obj" \
"./source/F2837xS_Gpio.obj" \
"./source/F2837xS_I2C.obj" \
"./source/F2837xS_Mcbsp.obj" \
"./source/F2837xS_MemCopy.obj" \
"./source/F2837xS_PieCtrl.obj" \
"./source/F2837xS_PieVect.obj" \
"./source/F2837xS_Sci.obj" \
"./source/F2837xS_Spi.obj" \
"./source/F2837xS_SysCtrl.obj" \
"./source/F2837xS_Upp.obj" \
"./source/F2837xS_sci_io.obj" \
"./source/F2837xS_sdfm_drivers.obj" \
"./source/F2837xS_struct.obj" \
"./source/F2837xS_usDelay.obj" \
"./source/fabs.obj" \
"./source/filter.obj" \
"./source/fmod.obj" \
"./source/modf.obj" \
"./source/protection.obj" \
"./source/variables.obj" \
"../cmd/2837xS_FLASH_TMU_lnk_cpu1.cmd" \
"../cmd/F2837xS_Headers_nonBIOS.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \
-l"C:/ti/controlSUITE/libs/app_libs/solar/v1.2/float/lib/Solar_Lib_Float.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include cmd/subdir_vars.mk
-include source/subdir_vars.mk
-include subdir_rules.mk
-include cmd/subdir_rules.mk
-include source/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
Mini_SST.out \

EXE_OUTPUTS__QUOTED += \
"Mini_SST.out" \

BIN_OUTPUTS += \
Mini_SST.hex \

BIN_OUTPUTS__QUOTED += \
"Mini_SST.hex" \


# All Target
all: Mini_SST.out

# Tool invocations
Mini_SST.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 --cla_support=cla1 --vcu_support=vcu2 --fp_mode=relaxed -g --diag_warning=225 --display_error_number --diag_wrap=off -z -m"Mini_SST.map" --stack_size=0x200 --warn_sections -i"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/lib" -i"C:/ti/controlSUITE/libs/app_libs/solar/v1.2/float/lib" -i"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --reread_libs --display_error_number --diag_wrap=off --xml_link_info="Mini_SST_linkInfo.xml" --rom_model -o "Mini_SST.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

Mini_SST.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C2000 Hex Utility'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/hex2000"  -o "Mini_SST.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "mini_sst.obj" "source\Config_ADC_PeriClks.obj" "source\Config_EPWM.obj" "source\Config_GPIO.obj" "source\Config_SCI_C.obj" "source\F2837xS_Adc.obj" "source\F2837xS_CodeStartBranch.obj" "source\F2837xS_CpuTimers.obj" "source\F2837xS_DBGIER.obj" "source\F2837xS_DefaultISR.obj" "source\F2837xS_Dma.obj" "source\F2837xS_ECap.obj" "source\F2837xS_EPwm.obj" "source\F2837xS_EQep.obj" "source\F2837xS_Emif.obj" "source\F2837xS_GlobalVariableDefs.obj" "source\F2837xS_Gpio.obj" "source\F2837xS_I2C.obj" "source\F2837xS_Mcbsp.obj" "source\F2837xS_MemCopy.obj" "source\F2837xS_PieCtrl.obj" "source\F2837xS_PieVect.obj" "source\F2837xS_Sci.obj" "source\F2837xS_Spi.obj" "source\F2837xS_SysCtrl.obj" "source\F2837xS_Upp.obj" "source\F2837xS_sci_io.obj" "source\F2837xS_sdfm_drivers.obj" "source\F2837xS_struct.obj" "source\F2837xS_usDelay.obj" "source\fabs.obj" "source\filter.obj" "source\fmod.obj" "source\modf.obj" "source\protection.obj" "source\variables.obj" 
	-$(RM) "mini_sst.d" "source\Config_ADC_PeriClks.d" "source\Config_EPWM.d" "source\Config_GPIO.d" "source\Config_SCI_C.d" "source\F2837xS_Adc.d" "source\F2837xS_CpuTimers.d" "source\F2837xS_DefaultISR.d" "source\F2837xS_Dma.d" "source\F2837xS_ECap.d" "source\F2837xS_EPwm.d" "source\F2837xS_EQep.d" "source\F2837xS_Emif.d" "source\F2837xS_GlobalVariableDefs.d" "source\F2837xS_Gpio.d" "source\F2837xS_I2C.d" "source\F2837xS_Mcbsp.d" "source\F2837xS_MemCopy.d" "source\F2837xS_PieCtrl.d" "source\F2837xS_PieVect.d" "source\F2837xS_Sci.d" "source\F2837xS_Spi.d" "source\F2837xS_SysCtrl.d" "source\F2837xS_Upp.d" "source\F2837xS_sci_io.d" "source\F2837xS_sdfm_drivers.d" "source\F2837xS_struct.d" "source\fabs.d" "source\filter.d" "source\fmod.d" "source\modf.d" "source\protection.d" "source\variables.d" 
	-$(RM) "source\F2837xS_CodeStartBranch.d" "source\F2837xS_DBGIER.d" "source\F2837xS_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

