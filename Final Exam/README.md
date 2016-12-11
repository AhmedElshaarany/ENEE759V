The exam has 2 problems based on the Lab assignments that were previously given. It also has one extra credit problem (in case you have time to do it or a need to try improving your grade). There are also three questions that you will need to answer.
Problems


P1: Debouncing button press ripples

Use MSP430 Lab 5a (previous Lab assignment LA3) from MSP430_Workshop_Lab_Guide_v4_01_students.pdfPreview the documentView in a new window and implement a method to debounce (eliminate) the button ripples causing spurious interrupts. Maintain and provide statistics with the following information:

    Total number of LED toggles that were performed (Did this equal the number of times you have pressed the button?)
    Total number of spurious button press interrupts that were chosen not to be serviced
    The maximum observed ripple duration.

Explain the main idea behind your approach. Document any assumptions. Provide additional information if you had to tune any algorithm parameters. For example, what were the parameters, their purpose and the way you tuned them.

The ripples figure shows what may happen when pressing a button and configuring an interrupt to occur when the button state changes from "down" to "up". There may be "spurious" interrupts happening within a short period of time after the first interrupt. This may happen as a consequence of a ripple effect of pressing the button.


The objective of this problem is to make sure that when pressing button once, the LED is toggled only once, not multiple times due to spurious interrupts. It does not matter which of the interrupts was the one that toggled the LED, as long as it happens only once for each button press. When there is nothing to do in the background you must put the CPU in LPM3 mode. When getting out of the ISR in this case you must ensure background processing can continue until the CPU goes to LPM3 mode again.

Use the project name: exam_p1_button. Archive name: exam_p1_button_solution.zip


P2: Random selection of LED to toggle

Modify RTOS Lab 9b (queues)  from TI_RTOS_Kernel_Workshop_Lab_Manual_rev2.40.pdfPreview the documentView in a new window to toggle a random LED every 500ms. Adjust the probability to toggle GREEN LED twice as many times relative to RED LED. Count toggles for GREEN and RED LED’s. Provide counts for a 2 minute run.

Use the project name: exam_p2_random. Archive name: exam_p2_random_solution.zip
Extra credit: (20 points) Clock functions (SWI's) and Rate Monotonic priorities

Use RTOS Lab 7 from TI_RTOS_Kernel_Workshop_Lab_Manual_rev2.40.pdfPreview the documentView in a new window as a starting point. Implement three clock functions with following properties:

1) Period 200ms, duration ~30ms, toggles green LED
2) Period 500ms, duration ~10ms, toggles red LED
3) Period 1s, duration ~600ms, toggles blocking of green LED toggling (it does not stop corresponding clock function from running and simulating 30ms processing, but only blocks the LED toggling)

Use the Rate Monotonic priority assignment to determine priorities for the clock function SWI’s. To simulate clock function processing duration use a “delay” function from MSP430 C compiler intrinsics.


Answer the following questions:

    Which priorities did you assign to each of the clock function SWI's?
    What are the values of input argument to the delay function within each of the clock function SWI's?
    How did you calculate the values for the delay function?

Use the project name: exam_ec_clk. Archive name: exam_ec_clk_solution.zip
Questions
Q1:

State at least four typical types of peripherals found in microcontrollers.
Q2:

State at least four reasons for using modularization or ‘divide and conquer’ approach when developing embedded software.
Q3:

What are the RTOS timers typically used for? State at least two examples.
