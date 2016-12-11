/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A65
 */

#include <xdc/std.h>

#include <ti/sysbios/knl/Clock.h>
extern const ti_sysbios_knl_Clock_Handle Red_ledToggleClk;

#include <ti/sysbios/knl/Clock.h>
extern const ti_sysbios_knl_Clock_Handle Green_ledToggleClk;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle Red_LEDSwi;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle Green_LEDSwi;

#define TI_DRIVERS_WIFI_INCLUDED 0

extern int xdc_runtime_Startup__EXECFXN__C;

extern int xdc_runtime_Startup__RESETFXN__C;

#ifndef ti_sysbios_knl_Task__include
#ifndef __nested__
#define __nested__
#include <ti/sysbios/knl/Task.h>
#undef __nested__
#else
#include <ti/sysbios/knl/Task.h>
#endif
#endif

extern ti_sysbios_knl_Task_Struct TSK_idle;

