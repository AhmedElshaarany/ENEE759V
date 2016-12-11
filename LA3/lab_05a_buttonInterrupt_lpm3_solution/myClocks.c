// ----------------------------------------------------------------------------
// myClocks.c  (for lab_04a_clock project)  ('F5529 Launchpad)
//
// This routine sets up the Low Frequency crystal (LFXT) and high-freq
// internal clock source (DCO). Then configures:
//    ACLK  = 32KHz
//    SMCLK =  8MHz
//    MCLK  =  8MHz
// ----------------------------------------------------------------------------

//***** Header Files **********************************************************
//#include <stdbool.h>
#include <driverlib.h>
#include "myClocks.h"


//***** Defines ***************************************************************
#define LF_CRYSTAL_FREQUENCY_IN_HZ     32768
#define HF_CRYSTAL_FREQUENCY_IN_HZ     4000000
#define MCLK_DESIRED_FREQUENCY_IN_KHZ  8000
#define MCLK_FLLREF_RATIO              (MCLK_DESIRED_FREQUENCY_IN_KHZ*124928) / ( UCS_REFOCLK_FREQUENCY*125 )   // ratio = 244


//***** Global Variables ******************************************************
uint32_t myACLK  = 0;
uint32_t mySMCLK = 0;
uint32_t myMCLK  = 0;


//***** Functions **************************************************************
void initClocks(void) {
     // Set core voltage level to handle 8MHz clock rate
     PMM_setVCore(PMM_CORE_LEVEL_0);

    //**************************************************************************
    // Configure Oscillators
    //**************************************************************************
    // Initialize the XT1 and XT2 crystal frequencies being used
	//  so driverlib knows how fast they are
     UCS_setExternalClockSource ( LF_CRYSTAL_FREQUENCY_IN_HZ, HF_CRYSTAL_FREQUENCY_IN_HZ );

    // Verify if the default clock settings are as expected
    myACLK  = UCS_getACLK();
    mySMCLK = UCS_getSMCLK();
    myMCLK  = UCS_getMCLK();

    //**************************************************************************
    // Configure Clocks
    //**************************************************************************
    // Setup ACLK to use REFO as its oscillator source  (32KHz)
    UCS_clockSignalInit(
            UCS_ACLK,                                    // Clock you're configuring
            UCS_REFOCLK_SELECT,                         // Clock source
            UCS_CLOCK_DIVIDER_1                          // Divide down clock source by this much
    );

    // Set the FLL's reference clock source
    UCS_clockSignalInit(
            UCS_FLLREF,                                  // Clock you're configuring
            UCS_REFOCLK_SELECT,                         // Clock source
            UCS_CLOCK_DIVIDER_1                          // Divide down clock source by this much
    );

    // Configure the FLL's frequency and set MCLK & SMCLK to use the FLL as their source (8MHz)
    UCS_initFLLSettle(
            MCLK_DESIRED_FREQUENCY_IN_KHZ,               // MCLK frequency
            MCLK_FLLREF_RATIO                          // Ratio between MCLK and FLL's reference clock source
    );



    // Verify that the modified clock settings are as expected
    myACLK  = UCS_getACLK();
    mySMCLK = UCS_getSMCLK();
    myMCLK  = UCS_getMCLK();
}

