################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
epwm_trip_zone.obj: ../epwm_trip_zone.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.9/bin/cl2000" -v28 -mt -ml --vcu_support=vcu2 --cla_support=cla1 --tmu_support=tmu0 --float_support=fpu32 --opt_for_speed=2 --include_path="C:/Users/Siyuan/Desktop/DSP_test/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.9/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="epwm_trip_zone.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

