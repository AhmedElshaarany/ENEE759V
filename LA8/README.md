Preparation

Start by doing the Lab 7 from the TI-RTOS Workshop TI_RTOS_Kernel_Workshop_Lab_Manual_rev2.40.pdfPreview the documentView in a new window. No need to submit solution for it. It is not going to be graded. The purpose is to get you ready for the actual project below.

Use UIA to do the measurements as described in the instructions. Configure 2048 MAU’s for execution graph buffer size when doing the measurement. It makes it easier because you would be able to see more RTOS events. Write down what you have got.


Lab Projects


P1:

Modify Lab 7 by adding second clock function to toggle the Green LED every 300ms. Keep the Red LED toggling at 500ms. Test the new code to make sure it runs properly.

Further modify Lab 7 by creating Swi’s for the Green/Red toggling clock functions. Keep the toggling rates the same.

Use the project name: blink_MSP430_CLK_mod2. Archive name: blink_MSP430_CLK_mod2_solution.zip

Provide comments regarding execution times and benchmarking of toggle operations for Red and Green LED’s.

Answer the following question:

    What is the general advantage (if any) of using Swi's when implementing clock functions?

LED and Button Mappings for MSP-EXP430F5529LP

You can find it in the LaunchPad documentation: msp-exp430f5529lp.pdfPreview the documentView in a new window. The interrupt related information may be found in the data sheet: msp430f5529.pdfPreview the documentView in a new window. Here are the mappings for your convenience:

    Red LED: P1.0
    Green LED: P4.7
    Button S1: P2.1, pull-up resistor, P2IV, #42
    Button S2: P1.1, pull-up resistor, P1IV, #47

