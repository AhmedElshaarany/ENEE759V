lab_06a_timer

Similar to lab_05b_wdtBlink, we want to blink an LED. In this case, 
though, we'll use TIMER_A to generate an interrupt rather than using the 
watchdog interval timer. During the interrupt routine we'll toggle the 
GPIO pin that drives an LED on our Launchpad board.

Because of the Boosterpack pinout differences between the 'F5529 USB and 
'FR5969 FRAM and 'FR4133 FRAM Launchpads (which affects Lab6c), we have 
chosen to use different timers for each of the boards:
         'F5529 Launchpad uses TA0
         'FR5969 Launchpad uses TA1
         'FR4133 Launchpad uses TA1

If you compare the two solutions, you should see that the timer setup code
only differs in the function argument that indicates which timer you're using.
In other words, it's very minimal.

As we write the ISR code, you should see that TIMER_A has two interupts: 
- One is dedicated to CCR0 (Capture and Compare Register 0).
- The second handles all the other timer interrupts

This first TIMER_A lab will use the main timer/counter rollover interrupt 
(called TA0IFG or TA1IFG). As with GPIO interrupts, our timer ISR should read 
the Timer IV register (TA0IV or TA1IV) and decipher the correct response using 
a switch/case statement.

The goal is to create a timer interrupt every 2 seconds. If we toggle the LED
inside each ISR, it should take 4 seconds to blink on and off.


Basic Steps:
- Import project from previous lab solution
- Delete old, unneccessary code
- Create the Timer Setup code -- using Continuous mode
- Write the Timer ISR
- Run and observe the LED flashing


