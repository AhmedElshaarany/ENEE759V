// main.c (for exam_ec_clk)

//----------------------------------------
// BIOS header files
//----------------------------------------
#include <xdc/std.h>  						//mandatory - have to include first, for BIOS types
#include <ti/sysbios/BIOS.h> 				//mandatory - if you call APIs like BIOS_start()
#include <xdc/runtime/Log.h>				//needed for any Log_info() call
#include <xdc/cfg/global.h> 				//header file for statically defined objects/handles
#include <xdc/runtime/Timestamp.h> 			//when using Timestamp APIs (TSCL/H), 32bit, 64bit

//-----------------------------------------
// MSP430 Header Files
//-----------------------------------------
#include <driverlib.h>
#include "myClocks.h"

//-----------------------------------------
// Defines
//-----------------------------------------
#define GPIO_ALL	GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3| \
					GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7


//-----------------------------------------
// Prototypes
//-----------------------------------------
void hardware_init(void);
void RedledToggle(void);
void GreenledToggle(void);
void GreenledToggleBlk(void);



//-----------------------------------------
// Globals
//-----------------------------------------
volatile int16_t Allow_GreenLED_Toggle = 1;			// Set to Allow and Reset to Disallow


//---------------------------------------------------------------------------
// main()
//---------------------------------------------------------------------------
void main(void)
{

   hardware_init();							// init hardware via Xware

   BIOS_start();							// Start BIOS Scheduler

}


//-----------------------------------------------------------------------------
// hardware_init()
//-----------------------------------------------------------------------------
void hardware_init(void)					//called by main
{
	// Disable the Watchdog Timer (important, as this is enabled by default)
	WDT_A_hold( WDT_A_BASE );

	// Init clocks
	initClocks();

	// Set GPIO ports to low-level outputs
    GPIO_setAsOutputPin( GPIO_PORT_P1, GPIO_ALL );
    GPIO_setAsOutputPin( GPIO_PORT_P2, GPIO_ALL );
    GPIO_setAsOutputPin( GPIO_PORT_P3, GPIO_ALL );
    GPIO_setAsOutputPin( GPIO_PORT_P4, GPIO_ALL );
    GPIO_setAsOutputPin( GPIO_PORT_P5, GPIO_ALL );
    GPIO_setAsOutputPin( GPIO_PORT_P6, GPIO_ALL );
    GPIO_setAsOutputPin( GPIO_PORT_PJ, GPIO_ALL );

    GPIO_setOutputLowOnPin( GPIO_PORT_P1, GPIO_ALL );
    GPIO_setOutputLowOnPin( GPIO_PORT_P2, GPIO_ALL );
    GPIO_setOutputLowOnPin( GPIO_PORT_P3, GPIO_ALL );
    GPIO_setOutputLowOnPin( GPIO_PORT_P4, GPIO_ALL );
    GPIO_setOutputLowOnPin( GPIO_PORT_P5, GPIO_ALL );
    GPIO_setOutputLowOnPin( GPIO_PORT_P6, GPIO_ALL );
    GPIO_setOutputLowOnPin( GPIO_PORT_PJ, GPIO_ALL );

}




//---------------------------------------------------------------------------
// RedledToggle() fxn
//
// Toggle RED LED via GPIO pin
// Delay for 10 msec
//---------------------------------------------------------------------------
void RedledToggle(void)
{

	GPIO_toggleOutputOnPin( GPIO_PORT_P1, GPIO_PIN0 );				// toggle Port1 Pin0 (RED LED)

	__delay_cycles(80000);											// ~10 msec delay

}



//---------------------------------------------------------------------------
// GreenledToggle() fxn
//
// Toggle GREEN LED via GPIO pin
// Delay for 30 msec
//---------------------------------------------------------------------------
void GreenledToggle(void)
{

	if(Allow_GreenLED_Toggle)
	GPIO_toggleOutputOnPin( GPIO_PORT_P4, GPIO_PIN7 );				// toggle Port4 Pin7 (GREEN LED)

	__delay_cycles(240000);											// ~30 msec delay

}


//---------------------------------------------------------------------------
// GreenledToggleBlk() fxn
//
// Toggle Blocking GREEN LED
// Delay for 600 msec
//---------------------------------------------------------------------------
void GreenledToggleBlk(void)
{

	Allow_GreenLED_Toggle ^= 1;										// Toggle Green LED Blocking

	__delay_cycles(4800000);										// ~600 msec delay

}




//*****************************************************************************
// Interrupt Service Routines
//*****************************************************************************

void RedledToggle_ISR(void)
{
	Swi_post(RED_LEDSwi);				// Post RED_LEDSwi
} /* RedledToogle_ISR */

void GreenledToggle_ISR(void)
{
	Swi_post(GREEN_LEDSwi);				// Post Green_LEDSwi
} /* GreenledToogle_ISR */

void GreenledToggleBlk_ISR(void)
{
	Swi_post(GREEN_LEDBlkSwi);			// Post Green_LEDBlkSwi
} /* GreenledToogleBlk_ISR */
