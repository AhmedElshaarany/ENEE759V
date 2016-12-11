// --------------------------------------------------------------------
// main.c (for lab_04a_clock project)
// --------------------------------------------------------------------
//***** Header Files **************************************************
#include <driverlib.h>
#include "myClocks.h"


//***** Prototypes ****************************************************
void initGPIO(void);


//***** Defines *******************************************************
#define ONE_SECOND 8000000
#define HALF_SECOND 4000000
#define TEN_SECONDS 327680
/*
 * main.c
 */
int main(void) {

	// Stop Watchdog timer
	WDT_A_hold(WDT_A_BASE);

	//Initialize GPIO
	initGPIO();

	//Initialize clocks
	initClocks();


	while (1) {

		//Set pin to “1” (hint, see question 4)
		GPIO_setOutputHighOnPin (GPIO_PORT_P1,GPIO_PIN0);

		//Wait for one second
		_delay_cycles( TEN_SECONDS );

		// Set pin to “0”
		GPIO_setOutputLowOnPin (GPIO_PORT_P1,GPIO_PIN0);

		//Wait for one second
		_delay_cycles( TEN_SECONDS );

			   }

	return 0;
}


//******************************************************************
void initGPIO(void) {
// Set pin P1.0 to output direction and initialize low
GPIO_setAsOutputPin( GPIO_PORT_P1, GPIO_PIN0 );
GPIO_setOutputLowOnPin( GPIO_PORT_P1, GPIO_PIN0 );
}
