Lab Projects

P1:

Do the lab 3a from the MSP430 Workshop. Use the project name: lab_03a_gpio. Archive name: lab_03a_gpio_solution.zip

P2:

Do the lab 3b from the MSP430 Workshop. Use the project name: lab_03b_button. Archive name: lab_03b_button_solution.zip

P3:

Use lab 3b to create a modified version. Use the project name: lab_3b_button_mod. Archive name: lab_03b_button_mod_solution.zip

Change main.c so it would do the following:

    When button S1 pressed, turn off LED2 (green), when button S1 up, turn on LED2
    When button S2 pressed, turn on LED1 (red), when button S2 up, turn off LED1

Documentation for MSP430ware

In case you cannot find it, the documentation for the MSP430ware should be here:

C:\ti\msp430\MSP430ware_1_97_00_47\driverlib\doc\MSP430F5xx_6xx
LED and Button Mappings for MSP-EXP430F5529LP

You can find it in the LaunchPad documentation: msp-exp430f5529lp.pdfPreview the documentView in a new window. The interrupt related information (not required for these labs) may be found in the MSP430F5529 datasheet: msp430f5529.pdfPreview the documentView in a new window. Here they are for your convenience:

    Red LED: P1.0
    Green LED: P4.7
    Button S1: P2.1, pull-up resistor, P2IV, #42
    Button S2: P1.1, pull-up resistor, P1IV, #47
