Lab Projects

P1:

Do the lab 4a from the MSP430 Workshop. Use the project name: lab_04a_clock. Archive name: lab_04a_clock_solution.zip

For the watch expressions use:

(float)<clock>/1000

This lab has a few things that could be considered as minor “bugs” – fix them!

Hints:

    LF clock is 32768Hz! (figure 40 schematics of LaunchPad User’s Guide)
    Properly calculate FLLREF_RATIO for configuring MCLK & SMCLK to be as close as possible to 8MHz

Answer the following questions:

    What is the FLLREF ratio?
    What is the actual MCLK & SMCLK frequency after the correction?

Provide answers to steps 19, 20 from the instructions (use floating point).
Extra credit: (20 points)

In lab 4a, when using REFO oscillator as MCLK source, what should be the delay count to get LED to blink at 10s intervals? Test and verify (measure time between blinks).


P2:

Do the lab 4b from the MSP430 Workshop. Use the project name: lab_04b_wdt. Archive name: lab_04b_wdt_solution.zip

Answer the following question:

    How many times did you get to see the message for the three settings of the watchdog timer?


P3:

Do the DriverLib Watchdog Example #3 as outlined in the MSP430 Workshop. Use the project name: wdt_a_ex3_watchdogACLK. Archive name: wdt_a_ex3_wdACLK_solution.zip

The provided example does not blink at a proper rate. Fix it and make it toggle every 0.5s.
