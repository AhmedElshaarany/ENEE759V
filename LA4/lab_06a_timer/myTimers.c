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
    Timer_A_initContinuousModeParam initContParam = { 0 };
    	initContParam.clockSource 				= 	TIMER_A_CLOCKSOURCE_ACLK;  		// Use ACLK (slower clock)
    	initContParam.clockSourceDivider 		= 	TIMER_A_CLOCKSOURCE_DIVIDER_1;  // Input clock = ACLK / 1 = 32KHz
    	initContParam.timerInterruptEnable_TAIE = 	TIMER_A_TAIE_INTERRUPT_ENABLE;  // Enable TAR -> 0 interrupt
    	initContParam.timerClear 				=	TIMER_A_DO_CLEAR;               // Clear TAR & clock divider
    	initContParam.startTimer 				=	false;                          // Don't start the timer, yet


    //	Configure the timer in Up mode
    Timer_A_initContinuousMode(TIMER_A0_BASE, &initContParam );


    // 	Clear/enable flags
    Timer_A_clearTimerInterruptFlag (TIMER_A0_BASE);                                // Clear TA0IFG


    // 	Start the timer in Continuous mode
    Timer_A_startCounter(
    						TIMER_A0_BASE,
    						TIMER_A_CONTINUOUS_MODE									// Continuous mode
    					);
}

//****** Interrupt Service Routine ********************************************
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
         	  GPIO_toggleOutputOnPin( GPIO_PORT_P4, GPIO_PIN7 );	 	 // Toggle LED2 (Green) LED on/off
              break;
     default: _never_executed();
    }
}

