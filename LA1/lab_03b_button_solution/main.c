#include <driverlib.h>
#define ONE_SECOND 800000
/*
 * main.c
 */
volatile unsigned short usiButton1 = 0;
int main(void) {
	// Stop Watchdog timer
	WDT_A_hold(WDT_A_BASE);
	//Set P1.0 as an output pin
	GPIO_setAsOutputPin (GPIO_PORT_P1,GPIO_PIN0);
	//Tie P1.1 to a PullUp Resistor
	GPIO_setAsInputPinWithPullUpResistor (GPIO_PORT_P1,GPIO_PIN1);
	while(1) {
	// Read the pin for push-button 2
	usiButton1 = GPIO_getInputPinValue (GPIO_PORT_P1,GPIO_PIN1);
	if ( usiButton1 == GPIO_INPUT_PIN_LOW ) {
	// If button is down, turn on LED
	GPIO_setOutputHighOnPin( GPIO_PORT_P1, GPIO_PIN0 );
	}
	else {
	// Otherwise, if button is up, turn off LED
	GPIO_setOutputLowOnPin( GPIO_PORT_P1, GPIO_PIN0 );
	   } }

	return 0;
}
