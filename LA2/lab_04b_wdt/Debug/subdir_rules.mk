################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
hello.obj: ../hello.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"c:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="c:/ti/ccsv6/ccs_base/msp430/include" --include_path="c:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/include" --include_path="C:/msp430_workshop/F5529_usb/workspace/lab_04b_wdt/driverlib/MSP430F5xx_6xx" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="hello.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


