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

	//Enable Global Interrupt (GIE)
	__bis_SR_register( GIE );


	while (1) {

		//Enable LPM3  to save power and Global Interrupt (GIE)
		__bis_SR_register(LPM3_bits + GIE);

			   }

	return 0;
}


//******************************************************************
void initGPIO(void) {
// Set pin P1.0 to output direction and initialize low
GPIO_setAsOutputPin( GPIO_PORT_P1, GPIO_PIN0 );
GPIO_setOutputLowOnPin( GPIO_PORT_P1, GPIO_PIN0 );

// Enable the Interrupt for push-button S2
GPIO_setAsInputPinWithPullUpResistor( GPIO_PORT_P1 , GPIO_PIN1 ); // setup P1.1 as input PullUpResistor
GPIO_interruptEdgeSelect( GPIO_PORT_P1 , GPIO_PIN1 , GPIO_LOW_TO_HIGH_TRANSITION ); // set edge select
GPIO_clearInterruptFlag( GPIO_PORT_P1 , GPIO_PIN1 ); // clear individual flag
GPIO_enableInterrupt( GPIO_PORT_P1 , GPIO_PIN1 ); // enable individual interrupt
}


//*********************************************************************
// Interrupt Service Routines
//*********************************************************************
#pragma vector=PORT1_VECTOR
__interrupt void pushbutton_ISR (void) {
switch(__even_in_range( P1IV, 0x10 )) {
case 0x00: break; // None
case 0x02: break; // Pin 0
case 0x04: GPIO_toggleOutputOnPin( GPIO_PORT_P1, GPIO_PIN0 );// Pin 1
		   break;
case 0x06: break; // Pin 2
case 0x08: break; // Pin 3
case 0x0A: break; // Pin 4
case 0x0C: break; // Pin 5
case 0x0E: break; // Pin 6
case 0x10: break; // Pin 7
default: _never_executed();
}

//Force Exit from LPM3 after handling the interrupt
__bic_SR_register_on_exit(LPM3_bits);

}
