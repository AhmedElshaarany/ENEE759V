// ----------------------------------------------------------------------------
// main.c  (for lab_06a_timer project) ('F5529 Launchpad)
// ----------------------------------------------------------------------------

//***** Header Files **********************************************************
#include <driverlib.h>
#include "myGpio.h"
#include "myClocks.h"
#include "myTimers.h"

//***** Prototypes ************************************************************


//***** Defines ***************************************************************


//***** Global Variables ******************************************************


//***** Main Function *********************************************************
void main (void)
{
    // Stop watchdog timer
    WDT_A_hold( WDT_A_BASE );

    // Initialize GPIO
    initGPIO();

    // Initialize clocks
    initClocks();

    // Initialize timers
    initTimers();

    // Enable interrupts globally
    __bis_SR_register( GIE );

    while(1) {
        __no_operation();             // Placeholder for while loop (not required)
    }
}

