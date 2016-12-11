lab_04a_clock

This lab explores system initialization, of which setting up the clocks are a
big part. After adding code to configure the clocks, we'll run it and verify
that we're seeing the expected clock rates.

An optional step has us reconfigure MCLK to use a slower oscillator, which 
makes our LED blink very, very slowly.

General procedure:
- Import lab_03a_gpio
- Create myClocks.c to hold our clock init code
- Reorganize the system init code in main() to fit our chapter's 'template'
- Debug the code using Watch Expressions to view the various clock rates
  of our MSP430
- Change MCLK to run slowly ... and wait very patiently for the LED to
  turn on & off

