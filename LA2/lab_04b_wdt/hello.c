// --------------------------------------------------------------------
// hello.c (for lab_04b_wdt project)
// --------------------------------------------------------------------

//***** Header Files **************************************************
#include <stdio.h>
#include <driverlib.h>


//***** Global Variables **************************************************
uint16_t count = 0;


/*
 * hello.c
 */
int main(void) {
	// WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer


	WDT_A_watchdogTimerInit( WDT_A_BASE,			   // Initialize the WDT
							 WDT_A_CLOCKSOURCE_ACLK,   // Use the ACLK for the WDT
							 WDT_A_CLOCKDIVIDER_64 );
						   //WDT_A_CLOCKDIVIDER_512 ); // Here are 3 (of 8) different div choices
						   //WDT_A_CLOCKDIVIDER_32K );

	WDT_A_start ( WDT_A_BASE ); // Start the watchdog

	
    while (1) {

    	count++;

    	printf("I called this %d times\n", count);

    	// WDT_A_resetTimer ( WDT_A_BASE ); // Reset the watchdog, Uncomment for step 21

    		  }
	
	return 0;
}
