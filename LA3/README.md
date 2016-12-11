Lab Projects

P1:

Do the lab 5a from the MSP430 Workshop. Use the project name: lab_05a_buttonInterrupt. Archive name: lab_05a_buttonInterrupt_solution.zip

The instructions for the lab have a wrong explanation for what was happening when the simple interrupt routine “did not work”!

The correct answer: When P1IFG is not cleared, you keep coming back into the ISR all the time no matter that the actual interrupts were not picked up! In reality, you are toggling the LED faster than you can see! The interrupts caused by additional button presses were ignored. That part was correct.

Once you implement the lab properly, answer the following questions:

    Why do you think sometimes the button may appear as if it is not working? (try pressing the button many times in a row)
    How can you check what is going on?
    What did you find?
    Why do you think it happens?


Extra credit: (40 points)

Modify your code to be in LPM3 low power mode while not servicing the interrupt. When you halt execution verify you are still within the while-loop in the main program! If not, what did you miss? Fix it!
Additional work

Do the lab 5b from the MSP430 Workshop. No need to turn it in. It will not be graded. It is a useful exercise.
