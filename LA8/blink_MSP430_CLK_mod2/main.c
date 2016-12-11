//----------------------------------------------------------------------------------
// Project: Blink MSP430 using BIOS Clock Fxns (STARTER)
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
#include <xdc/runtime/Timestamp.h> 			//when using Timestamp APIs (TSCL/H), 32bit, 64bit


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
void Red_ledToggle_ISR(void);
void Green_ledToggle_ISR(void);
void Red_ledToggle(void);
void Green_ledToggle(void);


//-----------------------------------------
// Globals
//-----------------------------------------
volatile int16_t Red_i16ToggleCount = 0;
volatile int16_t Green_i16ToggleCount = 0;


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


}


//---------------------------------------------------------------------------
// Red_ledToggle() ISR
//
// Post Red_LEDSwi
//---------------------------------------------------------------------------
void Red_ledToggle_ISR(void)
{
	Swi_post(Red_LEDSwi);					// Post Red_LEDSwi
}


//---------------------------------------------------------------------------
// Green_ledToggle() ISR
//
// Post Green_LEDSwi
//---------------------------------------------------------------------------
void Green_ledToggle_ISR(void)
{
	Swi_post(Green_LEDSwi);					// Post Green_LEDSwi
}



//---------------------------------------------------------------------------
// Red_ledToggle() ISR
//
// Toggle Red LED via GPIO pin
// Keep track and log Red #toggles
// Calculate and log Red LED Benchmark
//---------------------------------------------------------------------------
void Red_ledToggle(void)
{
	static uint32_t ui32_t0, ui32_t1, ui32_t2, ui32start, ui32stop, ui32delta;	// used for Timestamp()

	ui32_t0 = Timestamp_get32();												// calculate Timestamp() overhead (ui32_t2)
	ui32_t1 = Timestamp_get32();
	ui32_t2 = ui32_t1 - ui32_t0;

	ui32start = Timestamp_get32();												// get starting Timer snapshot for LED benchmark

	GPIO_toggleOutputOnPin( GPIO_PORT_P1, GPIO_PIN0 );							// toggle Port1 Pin0

    ui32stop = Timestamp_get32();												// get ending Timer snapshot for LED benchmark

	ui32delta = ui32stop - ui32start - ui32_t2;									// calculate LED toggle benchmark

	Red_i16ToggleCount += 1;													// keep track of #toggles

	Log_info1("RED LED TOGGLED [%u] TIMES", Red_i16ToggleCount);				// send results to log display

	Log_info1("RED LED BENCHMARK = [%u] MSP430 CYCLES", ui32delta);				// send LED Benchmark to Log display

}


//---------------------------------------------------------------------------
// Green_ledToggle() ISR
//
// Toggle Green LED via GPIO pin
// Keep track and log Green #toggles
// Calculate and log Green LED Benchmark
//---------------------------------------------------------------------------
void Green_ledToggle(void)
{
	static uint32_t ui32_t0, ui32_t1, ui32_t2, ui32start, ui32stop, ui32delta;	// used for Timestamp()

	ui32_t0 = Timestamp_get32();												// calculate Timestamp() overhead (ui32_t2)
	ui32_t1 = Timestamp_get32();
	ui32_t2 = ui32_t1 - ui32_t0;

	ui32start = Timestamp_get32();												// get starting Timer snapshot for LED benchmark

	GPIO_toggleOutputOnPin( GPIO_PORT_P4, GPIO_PIN7 );							// toggle Port4 Pin7

    ui32stop = Timestamp_get32();												// get ending Timer snapshot for LED benchmark

	ui32delta = ui32stop - ui32start - ui32_t2;									// calculate LED toggle benchmark

	Green_i16ToggleCount += 1;													// keep track of #toggles

	Log_info1("GREEN LED TOGGLED [%u] TIMES", Green_i16ToggleCount);			// send results to log display

	Log_info1("GREEN LED BENCHMARK = [%u] MSP430 CYCLES", ui32delta);			// send LED Benchmark to Log display

}


