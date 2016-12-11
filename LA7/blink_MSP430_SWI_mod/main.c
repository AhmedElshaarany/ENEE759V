//----------------------------------------------------------------------------------
// Project: Blink MSP430 using BIOS Swi (STARTER)
// Author: Eric Wilbur
// Date: June 2014
//
// Follow these steps to create this project in CCSv6.0:
// 1. Project -> New CCS Project
// 2. Select Template:
//    - TI-RTOS for MSP430 -> Driver Examples -> 5529 LP -> Example Projects ->
//      Empty Project
//    - Empty Project contains full instrumentation (UIA, RTOS Analyzer) and
//      paths set up for the TI-RTOS version of MSP430Ware
// 3. Delete the following files:
//    - Board.h, empty.c, MSP_EXP4305529LP.c/h, empty_readme.txt
// 4. Add main.c from TI-RTOS Workshop Solution file for this lab
// 5. Edit empty.cfg as needed (to add/subtract) BIOS services, delete Task
// 6. Build, load, run...
//----------------------------------------------------------------------------------


//----------------------------------------
// BIOS header files
//----------------------------------------
#include <xdc/std.h>  						//mandatory - have to include first, for BIOS types
#include <ti/sysbios/BIOS.h> 				//mandatory - if you call APIs like BIOS_start()
#include <xdc/runtime/Log.h>				//needed for any Log_info() call
#include <xdc/cfg/global.h> 				//header file for statically defined objects/handles


//-----------------------------------------
// MSP430 Header Files
//-----------------------------------------
#include <driverlib.h>


//-----------------------------------------
// MSP430 MCLK frequency settings
// Used to set MCLK frequency
// Ratio = MCLK/FLLREF = 8192KHz/32KHz
//-----------------------------------------
#define UCS_MCLK_DESIRED_FREQUENCY_IN_KHZ  8192
#define UCS_MCLK_FLLREF_RATIO 250

#define GPIO_ALL	GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3| \
					GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7


//-----------------------------------------
// Prototypes
//-----------------------------------------
void hardware_init(void);
void ledToggle(void);
void Timer_ISR(void);
void ledLog(void);

//-----------------------------------------
// Globals
//-----------------------------------------
volatile int16_t i16ToggleCount = 0;


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

	// Set MCLK frequency to 8192 KHz
	// First, set DCO FLLREF to 32KHz = REF0
	UCS_clockSignalInit(UCS_FLLREF, UCS_REFOCLK_SELECT, UCS_CLOCK_DIVIDER_1);
	// Second, Set Ratio and Desired MCLK Frequency = 8192KHz and initialize DCO
	UCS_initFLLSettle(UCS_MCLK_DESIRED_FREQUENCY_IN_KHZ, UCS_MCLK_FLLREF_RATIO);

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


    // Configure Timer_A1 in Up mode - sourced by ACLK, 4700 is 1/2sec toggle, INT #49
    TIMER_A_configureUpMode(TIMER_A1_BASE, TIMER_A_CLOCKSOURCE_ACLK, TIMER_A_CLOCKSOURCE_DIVIDER_1,
        0x4000,
        TIMER_A_TAIE_INTERRUPT_DISABLE, TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE, TIMER_A_SKIP_CLEAR);

    // start Timer_A in up mode
    TIMER_A_startCounter(TIMER_A1_BASE,	TIMER_A_UP_MODE);

}


//---------------------------------------------------------------------------
// ledToggle() fxn
//
//
// Toggle LED via GPIO pin
//---------------------------------------------------------------------------
void ledToggle(void)
{
	GPIO_toggleOutputOnPin( GPIO_PORT_P1, GPIO_PIN0 );		// toggle Port1 Pin0

	i16ToggleCount += 1;									// keep track of #toggles

	Swi_post(Swi2);											// post Swi2 to call ledLog fxn

}



//---------------------------------------------------------------------------
// Timer ISR
//
//
// Post Swi1 when Timer_A1 reaches zero
//---------------------------------------------------------------------------
void Timer_ISR(void)
{
	Swi_post(Swi1);										 	//post Swi1 to call ledToggle fxn
}



//---------------------------------------------------------------------------
// ledLog() fxn
//
//
// Log the #toggles
//---------------------------------------------------------------------------
void ledLog(void)
{
	Log_info1("LED TOGGLED [%u] TIMES", i16ToggleCount);	// send results to log display
}
