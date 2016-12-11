#include <driverlib.h>
#define ONE_SECOND 800000
/*
 * main.c
 */
int main(void) {
	WDT_A_hold(WDT_A_BASE); // Stop Watchdog timer
	//Set P1.0 as an output pin
	GPIO_setAsOutputPin (GPIO_PORT_P1,GPIO_PIN0);
	while (1) {
	//Set pin to “1” (hint, see question 4)
	GPIO_setOutputHighOnPin (GPIO_PORT_P1,GPIO_PIN0);
	//Wait for one second
	_delay_cycles( ONE_SECOND );
	// Set pin to “0”
	GPIO_setOutputLowOnPin (GPIO_PORT_P1,GPIO_PIN0);
	//Wait for one second
	_delay_cycles( ONE_SECOND );
	    }

	return 0;
}
