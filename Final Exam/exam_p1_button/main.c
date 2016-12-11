// main.c (for exam_p1_button)

// Header files
#include <driverlib.h>
#include "myClocks.h"

// Prototypes
void initGPIO(void);
void initTimers(void);
void ledTogglehandle(void);

// Globals
volatile int16_t Allow_Toggle = 1;				// Set to Allow and Reset to Disallow
volatile int16_t Sup_button_press_count = 0;	// Used to count number of spurious button presses
volatile int16_t Ripple_duration = 0;			// Used to calculate max ripple duration
volatile int16_t Temporary_duration = 0;		// Used to calculate temporary ripple duration


//*****************************************************************************
// Functions
//*****************************************************************************
int main(void) {
    WDT_A_hold (WDT_A_BASE);	// Stop watchdog timer
	
    // Init GPIO
    initGPIO();

    // Init clocks
    initClocks();

    // Initialize timers
    initTimers();

	//Enable Global Interrupt (GIE)
    __bis_SR_register (GIE);
    while (1) {

    	//Enable LPM3
    	__low_power_mode_3();
      __no_operation();
    }

	return 0;
} /* main */


// *****************************************************************************************
// initGPIO()
//
// Initialize GPIO
// *****************************************************************************************
void initGPIO(void) {

	// Prepare to toggle P1.0 (set the pin as output)
    GPIO_setOutputLowOnPin (GPIO_PORT_P1, GPIO_PIN0 );
    GPIO_setAsOutputPin ( GPIO_PORT_P1, GPIO_PIN0 );

    // Set P1.1 as input and enable INT (use LOW -> HIGH transition)
    GPIO_setAsInputPinWithPullUpResistor (
    		GPIO_PORT_P1, GPIO_PIN1 );
    GPIO_interruptEdgeSelect (
    		GPIO_PORT_P1, GPIO_PIN1,
    		GPIO_LOW_TO_HIGH_TRANSITION );
    GPIO_clearInterruptFlag (
    		GPIO_PORT_P1, GPIO_PIN1 );
    GPIO_enableInterrupt (
    		GPIO_PORT_P1, GPIO_PIN1 );

} /* initGPIO */



// *****************************************************************************************
// ledTogglehandle()
//
// Check if Allowed to Toggle (i.e. actual button press)
// Allowed: disable toggle, start timer, reset spurious count and ripple duration
// Disallowed: Increment spurious count and get ripple duration
// *****************************************************************************************
void ledTogglehandle(void)
{
	// Check if Allowed to Toggle
	if(Allow_Toggle)
	{
		// Toggle LED
		GPIO_toggleOutputOnPin( GPIO_PORT_P1, GPIO_PIN0 );

		// Disable LED Toggle
		Allow_Toggle = 0;

		// 	Start the timer in Continuous mode
		Timer_A_startCounter(
		    						TIMER_A0_BASE,
		    						TIMER_A_CONTINUOUS_MODE									// Continuous mode
		    				);

		// Reset spurious button press count
		Sup_button_press_count = 0;

		// Reset Ripple duration
		Ripple_duration = 0;

	}
	else
	{
		// Increment spurious button press count
		Sup_button_press_count += 1;

		// Store Count value for current spurious button press
		Temporary_duration = Timer_A_getCounterValue(TIMER_A0_BASE);

		// Store Temporary duration in Ripple duration if last spurious button press
		if( Temporary_duration > Ripple_duration)
		Ripple_duration = Temporary_duration;

	}


}/* ledTogglehandle() */




// *****************************************************************************************
// intiTimers()
//
// This intrinsic delays exactly the number of clock cycles (MCLK) shown
// Note: this routine burns power - other routines can be used that burn almost no power
// *****************************************************************************************
void initTimers(void)
{

	// 	  Setup Timer (TAR, TACTL)
    //    TimerA0 in Continuous mode using SMCLK
    //    Set timer to 8 msec
    Timer_A_initContinuousModeParam initContParam = { 0 };
    	initContParam.clockSource 				= 	TIMER_A_CLOCKSOURCE_SMCLK;  	// Use SMCLK (fast clock)
    	initContParam.clockSourceDivider 		= 	TIMER_A_CLOCKSOURCE_DIVIDER_1;  // Input clock = SMCLK / 1 = 8MHz
    	initContParam.timerInterruptEnable_TAIE = 	TIMER_A_TAIE_INTERRUPT_ENABLE;  // Enable TAR -> 0 interrupt
    	initContParam.timerClear 				=	TIMER_A_DO_CLEAR;               // Clear TAR & clock divider
    	initContParam.startTimer 				=	false;                          // Don't start the timer, yet


    //	Configure the timer in Continuous mode
    Timer_A_initContinuousMode(TIMER_A0_BASE, &initContParam );


    // 	Clear/enable flags
    Timer_A_clearTimerInterruptFlag (TIMER_A0_BASE);                                // Clear TA0IFG

}/* intiTimers() */



//*****************************************************************************
// Interrupt Service Routines
//*****************************************************************************
#pragma vector=PORT1_VECTOR
__interrupt void pushbutton2_ISR (void)
{
        // Call the ledTogglehandle if button pressed( in switch statement below)

     switch( __even_in_range( P1IV, 0x10 )) {
       case 0x00: break;                    // None
       case 0x02:                           // Pin 0
                  __no_operation();
                  break;
       case 0x04: 							// Pin 1
                  ledTogglehandle();		//Handle the interrupt
                  break;
       case 0x06:                           // Pin 2
                  __no_operation();
                  break;
       case 0x08:                           // Pin 3
                  __no_operation();
                  break;
       case 0x0A:                           // Pin 4
                  __no_operation();
                  break;
       case 0x0C:                           // Pin 5
                  __no_operation();
                  break;
       case 0x0E:                           // Pin 6
                  __no_operation();
                  break;
       case 0x10:                           // Pin 7
                  __no_operation();
                  break;
       default:   _never_executed();
    }

    //Force Exit from LPM3 after handling the interrupt
    __low_power_mode_off_on_exit();

} /* pushbutton2_ISR */


#pragma vector=TIMER0_A1_VECTOR
__interrupt void timer0_ISR (void)
{
    // Timer ISR and vector

    switch( __even_in_range( TA0IV, 14 )) {
     case  0: break;                // None
     case  2: break;                // CCR1 IFG
     case  4: break;                // CCR2 IFG
     case  6: break;                // CCR3 IFG
     case  8: break;                // CCR4 IFG
     case 10: break;                // CCR5 IFG
     case 12: break;                // CCR6 IFG
     case 14:                       // TAR overflow

    	 	  Allow_Toggle = 1;					// Re-enable LED Toggle
    	 	  Timer_A_stop ( TIMER_A0_BASE );	//Stop Timer
              break;
     default: _never_executed();
    }

    //Force Exit from LPM3 after handling the interrupt
    __low_power_mode_off_on_exit();

} /* timer0_ISR */



