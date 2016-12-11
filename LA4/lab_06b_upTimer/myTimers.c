// ----------------------------------------------------------------------------
// myTimers.c  (for lab_06a_timer project) ('F5529 Launchpad)
// ----------------------------------------------------------------------------

//***** Header Files **********************************************************
#include <driverlib.h>
#include "myTimers.h"

//***** Defines ***************************************************************


//***** Global Variables ******************************************************


//***** Functions *************************************************************
void initTimers(void)
{
    // 	  Setup Timer (TAR, TACTL)
    //    TimerA0 in Continuous mode using ACLK
    //    Toggle LED2 (Green) on/off every 2 seconds using timer interrupt (TA0IFG)
	Timer_A_initUpModeParam initUpParam = { 0 };
		initUpParam.clockSource = 								TIMER_A_CLOCKSOURCE_ACLK;  					// Use ACLK (slower clock)
		initUpParam.clockSourceDivider = 						TIMER_A_CLOCKSOURCE_DIVIDER_1;  			// Input clock = ACLK / 1 = 32KHz
    	initUpParam.timerPeriod =								32768; 										// timer counter period	(i.e. CCRO value)
    	initUpParam.timerInterruptEnable_TAIE = 				TIMER_A_TAIE_INTERRUPT_ENABLE;  			// Enable TAR -> 0 interrupt
    	initUpParam.captureCompareInterruptEnable_CCR0_CCIE =	TIMER_A_CAPTURECOMPARE_INTERRUPT_ENABLE; 	// Enable CCR0 compare interrupt
    	initUpParam.timerClear = 								TIMER_A_DO_CLEAR;               			// Clear TAR & clock divider
    	initUpParam.startTimer = 								false;     			                        // Don't start the timer, yet


    //	Configure the timer in Up mode and initialize with initUpParam
    	Timer_A_initUpMode(TIMER_A0_BASE, &initUpParam );

    //  Clear flags
    Timer_A_clearTimerInterruptFlag (TIMER_A0_BASE);                                // Clear TA0IFG
    Timer_A_clearCaptureCompareInterruptFlag ( 	TIMER_A0_BASE,						// Clear CCR0IFG
    											TIMER_A_CAPTURECOMPARE_REGISTER_0 );

    //	Start timer in up mode
    Timer_A_startCounter( 	TIMER_A0_BASE,
    						TIMER_A_UP_MODE ); 										// up mode

}

//****** Interrupt Service Routine For TimerA Roll-over ********************************************
#pragma vector=TIMER0_A1_VECTOR
__interrupt void timer0_ISR (void)
{
    // 4. Timer ISR and vector

    switch( __even_in_range( TA0IV, 14 )) {
     case  0: break;                // None
     case  2: break;                // CCR1 IFG
     case  4: break;                // CCR2 IFG
     case  6: break;                // CCR3 IFG
     case  8: break;                // CCR4 IFG
     case 10: break;                // CCR5 IFG
     case 12: break;                // CCR6 IFG
     case 14:                       // TAR overflow
         	  GPIO_toggleOutputOnPin( GPIO_PORT_P4, GPIO_PIN7 );	 	 // Toggle LED2 (Green) LED on/off
              break;
     default: _never_executed();
    }
}


//****** Interrupt Service Routine For TimerA Capture & Compare ********************************************
#pragma vector= TIMER0_A0_VECTOR
__interrupt void ccr0_ISR (void)
{

	// Toggle the LED1 on/off
	GPIO_toggleOutputOnPin( GPIO_PORT_P1, GPIO_PIN0 );

}
