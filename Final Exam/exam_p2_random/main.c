// main.c (for exam_p2_random)

//----------------------------------------
// BIOS header files
//----------------------------------------
#include <xdc/std.h>  						//mandatory - have to include first, for BIOS types
#include <ti/sysbios/BIOS.h> 				//mandatory - if you call APIs like BIOS_start()
#include <xdc/runtime/Log.h>				//needed for any Log_info() call
#include <xdc/cfg/global.h> 				//header file for statically defined objects/handles
#include <stdlib.h>							//needed for using rand() fxn


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
int16_t rand_num_gen(int16_t lowerLimit, int16_t UpperLimit);


//-----------------------------------------
// Globals
//-----------------------------------------
volatile int16_t RED_i16ToggleCount = 0;
volatile int16_t GREEN_i16ToggleCount = 0;


//------------------------
// for Queue - Part B
//------------------------
typedef struct MsgObj {
	Queue_Elem	elem;
	Int	val;            	// message value
} MsgObj, *Msg;				// Use Msg as pointer to MsgObj



//---------------------------------------------------------------------------
// main()
//---------------------------------------------------------------------------
void main(void)
{

   hardware_init();				// init hardware via Xware

   BIOS_start();				// start BIOS Scheduler

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
// mailbox_queue Task() - Run by BIOS_Start(), then unblocked by Timer ISR
//
// Places random value from set {1,2,3} (msg.val) into a mailbox for ledToggle() to use
//---------------------------------------------------------------------------
void mailbox_queue(void)
{

//---------------------------------
// msg used for Mailbox and Queue
//---------------------------------
	MsgObj msg;													// create an instance of MsgObj named msg

//---------------------------------
// msgp used for Queue only
//---------------------------------
	Msg msgp;													// Queues pass POINTERS, so we need a pointer of type Msg
	msgp = &msg;												// init message pointer to address of msg


	msg.val = 1;												// set initial value of msg.val (LED state)

	while(1){


		msg.val = rand_num_gen(1,3);							// msg.val is set to a  random number from the set {1,2,3}

		Semaphore_pend(mailbox_queue_Sem, BIOS_WAIT_FOREVER);	// wait on semaphore from Timer ISR

//------------------------------
// QUEUE CODE follows...
//------------------------------
		Queue_put(LED_Queue, (Queue_Elem*)msgp);				// pass pointer to Message object via LED_Queue
		Semaphore_post (QueSem);								// unblock Queue_get to get msg

	}

}



//---------------------------------------------------------------------------
// ledToggle()  - called by BIOS_Start(), then unblocked by mailbox_queue()
//
// Toggle GREEN LED  via GPIO pin if random numbers 1 or 2 is received
// Toggle RED   LED  via GPIO pin if random number  3      is received
//---------------------------------------------------------------------------
void ledToggle(void)
{

//---------------------------------
// msg used for Mailbox and Queue
//---------------------------------
	MsgObj msg;													//define msg using MsgObj struct created earlier

//---------------------------------
// msgp used for Queue only
//---------------------------------
	Msg msgp;													//define pointer to MsgObj to use with queue put/get
	msgp = &msg;												//init msgp to point to address of msg (used for put/get)


	while(1)
	{

//------------------------------
// QUEUE CODE follows...
//------------------------------
		Semaphore_pend(QueSem, BIOS_WAIT_FOREVER);				// unblocked by mailbox_queue() when Queue has msg
		msgp = Queue_get(LED_Queue);							// read contents of queue to get value of LED state


		if(msgp->val==1 || msgp->val==2)											// QUEUE "if" - mspg->val contains random number for QUEUE's the use pointers

		{

			GPIO_toggleOutputOnPin( GPIO_PORT_P4, GPIO_PIN7 );					// toggle GREEN

			GREEN_i16ToggleCount += 1;											// keep track of Green #toggles

			Log_info1("GREEN LED TOGGLED [%u] TIMES", GREEN_i16ToggleCount);	// Log Green #toggles

		}
		else
		{
			GPIO_toggleOutputOnPin( GPIO_PORT_P1, GPIO_PIN0 );					// toggle RED

			RED_i16ToggleCount += 1;									        // keep track of Red #toggles

			Log_info1("RED LED TOGGLED [%u] TIMES", RED_i16ToggleCount);		// Log Red #toggles

		}


	}
}


//---------------------------------------------------------------------------
// rand_num_gen()
//
// Generate a random number between lowerLimit and UpperLimit inclusive.
//---------------------------------------------------------------------------
int16_t rand_num_gen(int16_t lowerLimit, int16_t UpperLimit)
{
	int16_t Rand_num = rand();										// Generate a random number from 0 to RAND_MAX

	int16_t range = UpperLimit - lowerLimit + 1; 					// Calculate Range to produce numbers in the interval [LowerLimit,UpperLimit]

	int16_t Scaled_Rand_num = (Rand_num % range) + lowerLimit;		// Scale the random number to the correct range

	return Scaled_Rand_num;
}


//*****************************************************************************
// Interrupt Service Routines
//*****************************************************************************
//---------------------------------------------------------------------------
// Timer ISR - called by BIOS Hwi (see app.cfg)
//
// Posts Sem to unblock mailbox/queue Task
//---------------------------------------------------------------------------
void Timer_ISR(void)
{
	Semaphore_post(mailbox_queue_Sem);										// post sem to unblock mailbox-queue Task
}

