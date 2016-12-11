#include <driverlib.h>
#define ONE_SECOND 800000
/*
 * main.c
 */
volatile unsigned short usiButton1 = 0;
volatile unsigned short usiButton2 = 0;
int main(void) {
	WDT_A_hold(WDT_A_BASE); // Stop Watchdog timer
	//Set P1.0 as an output pin
	GPIO_setAsOutputPin (GPIO_PORT_P1,GPIO_PIN0);
	//Set P4.7 as an output pin
	GPIO_setAsOutputPin (GPIO_PORT_P4,GPIO_PIN7);

	//Set P1.1 as an input pin tied to a Pull up resistor
	GPIO_setAsInputPinWithPullUpResistor (GPIO_PORT_P1,GPIO_PIN1);
	//Set P2.1 as an input pin tied to a Pull up resistor
	GPIO_setAsInputPinWithPullUpResistor (GPIO_PORT_P2,GPIO_PIN1);


	while(1) {
	// Read the pin for push-button 2
	usiButton2 = GPIO_getInputPinValue (GPIO_PORT_P1,GPIO_PIN1);
	if ( usiButton2 == GPIO_INPUT_PIN_LOW ) {
	// If button is down, turn on LED
	GPIO_setOutputHighOnPin( GPIO_PORT_P1, GPIO_PIN0 );
	}
	else {
	// Otherwise, if button is up, turn off LED
	GPIO_setOutputLowOnPin( GPIO_PORT_P1, GPIO_PIN0 );
		 }
	// Read the pin for push-button 1
	usiButton1 = GPIO_getInputPinValue (GPIO_PORT_P2,GPIO_PIN1);
	if ( usiButton1 == GPIO_INPUT_PIN_LOW ) {
	// If button is down, turn off LED
	GPIO_setOutputLowOnPin( GPIO_PORT_P4, GPIO_PIN7 );
	}
	else {
	// Otherwise, if button is up, turn on LED
	GPIO_setOutputHighOnPin( GPIO_PORT_P4, GPIO_PIN7 );
	   }
			}

	return 0;
}
