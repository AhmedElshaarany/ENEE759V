Preparation

Start by doing the Lab 6 from the TI-RTOS Workshop TI_RTOS_Kernel_Workshop_Lab_Manual_rev2.40.pdfPreview the documentView in a new window. No need to submit solution for it. It is not going to be graded. The purpose is to get you ready for the actual project below.

Make sure you use UIA to measure the duration (in micro-seconds) of the SWI as described in the instructions. Configure 2048 MAU’s for execution graph buffer size when doing the measurement. It makes it easier because you would be able to see more RTOS events. Write down what you have got.

Lab Projects


P1:

Modify Lab 6 to create an additional Swi by splitting the original.

    The first Swi (Swi1) should implement LED toggling, counting of toggles and should post the second Swi for execution.
    The second Swi (Swi2) should only implement logging of the LED toggles.

Use the project name: blink_MSP430_SWI_mod. Archive name: blink_MSP430_SWI_mod_solution.zip

Using the Execution graph of UIA, measure time between the start of Swi1 and the end of Swi2. Do this for the following three cases:
 Swi1 Priority  	 Swi2 Priority  	 Swi2End - Swi1Start (us) 
	3 			1		 	?
	3		 	3 			?
	3		 	5 			?

 

Answer the following questions:

    How does your measurement compare against the measurement done as part of original Lab 6 (ledToggle benchmark, single Swi)? Explain.
    How does the single Swi measurement you got compares against the value provided in the Lab manual? Explain.
    Explain similarities or differences in behavior (scheduling) and measurements in the above table.

LED and Button Mappings for MSP-EXP430F5529LP

You can find it in the LaunchPad documentation: msp-exp430f5529lp.pdfPreview the documentView in a new window. The interrupt related information may be found in the data sheet: msp430f5529.pdfPreview the documentView in a new window. Here are the mappings for your convenience:

    Red LED: P1.0
    Green LED: P4.7
    Button S1: P2.1, pull-up resistor, P2IV, #42
    Button S2: P1.1, pull-up resistor, P1IV, #47

