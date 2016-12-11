lab_03a_gpio (for 'F5529 Launchpad)

This lab creates what is often called "The Embedded Hello World" program.

While this is just simple LED blinking code, we implement with the MSP430ware 
DriverLib library. This gives us a good example for learning to use, as well as 
link in, a library. This library will become even more important as we explore 
other peripherals in later lab exercises.

Part of learning to use a library involves creating 'Portable' CCS projects. Our 
projects need to be created such that others can easily get them up-and-running 
on their own systems. (Or, we can easily migrate to a later revision of a 
library.) To this end, we will learn how to create IDE path variables - and use 
them to point to our library's files.

Finally, along with single-stepping our program, we will explore the "Registers" 
window in CCS. This lets us view the CPU registers, watching how they change 
as we step thru our code.

One last note: The FRAM devices requires an extra call to unlock the
GPIO pins. This call isn't needed for the 'F5529 (F5xx series) device.

WARNING

Our code example is a BAD way to implement a blinking light ... from an 
efficiency standpoint. The _delay_cycles() function is VERY INEFFICIENT. A 
timer, which we learn about in a later chapter, would be a much lower-power way 
to implement a delay. For our purposes in this chapter, though, this is an easy 
function to get started with.


