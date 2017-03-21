################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
mini_sst.obj: ../mini_sst.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 --cla_support=cla1 --vcu_support=vcu2 --fp_mode=relaxed --include_path="C:/Users/Dunedaine/Desktop/New folder/mini_sst/mini_sst/include" --include_path="C:/ti/controlSUITE/libs/app_libs/solar/v1.2/float/lib" --include_path="C:/ti/controlSUITE/libs/app_libs/solar/v1.2/float/include" --include_path="C:/ti/controlSUITE/libs/app_libs/solar/v1.2/float" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="mini_sst.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


