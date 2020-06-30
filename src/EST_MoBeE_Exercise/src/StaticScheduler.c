/******************************************************************************/
/**
 * @file         StaticScheduler.c
 *
 * @brief        C file for StaticScheduler
 *
 * @version      1.00
 * @date         Feb/18/2010
 * @warning
 * @note
 * <pre>
 * ---------------------------------------------------------------------------
 *               R E V I S I O N   H I S T O R Y
 * ---------------------------------------------------------------------------
 *   Date        Version  Author  Description
 *  ----------   -------  ------  --------------------------------------------
 *  2010-02-18   1.00             - Creation Release
 * </pre>
 *
 */
/******************************************************************************/

#ifndef STATICSCHEDULER_C
#define STATICSCHEDULER_C

/**
 * @defgroup STATICSCHEDULER
 * @{
 */

/******************************************************************************/
/* HEADER FILES                                                               */
/******************************************************************************/

/**** Standard types & definitions ****/

/**** Project types & definitions ****/
#if COMPILER == MINGW32
#include "stdio.h"
#include "PlatformTypes.h"
#elif COMPILER == DAVE
#include "probe_scope.h"
#endif

/**** Miscellaneous types & definitions ****/
#include "StaticScheduler.h"
#include "ActuatorSWC.h"
#include "ControlSWC.h"
#include "SensorSWC.h"

/******************************************************************************/
/* DEFINITIONS AND MACROS (scope: file)                                       */
/******************************************************************************/


/******************************************************************************/
/* TYPEDEFS AND STRUCTURES (scope: file)                                      */
/******************************************************************************/

/**** enum type definitions ***************************************************/


/**** structures type definitions ********************************************/

/**** extra type definitions ****/

/******************************************************************************/
/* EXPORTED VARIABLES (scope: exported)                                       */
/******************************************************************************/


/******************************************************************************/
/* FILE VARIABLES (scope: file)                                               */
/******************************************************************************/
#if COMPILER == MINGW32

#elif COMPILER == DAVE
static uint32_t TaskId1ms=0;
#endif

static uint32_t TickCounter = 0;
static bool Task1msFlag = false;
static bool Task10msFlag = false;
static bool Task100msFlag = false;
static bool Task1000msFlag = false;

/******************************************************************************/
/* Function Prototype (scope: file)                                           */
/******************************************************************************/
static void TaskInit(void);
static void TaskIdle(void);
static void Task1ms(void);
static void Task10ms(void);
static void Task100ms(void);
static void Task1000ms(void);

/******************************************************************************/
/* Function Implementation (scope: file)                                  */
/******************************************************************************/

static void TaskInit(void){
    /* Initialize ProbeScope */

#if COMPILER == MINGW32

#elif COMPILER == DAVE
	ProbeScope_Init(1000); /* 1 KHz */
#endif

#ifdef DEBUG
	printf("TaskInit ");
#endif

	InitSensor();
	InitControl();
	InitActuator();

}

uint32_t Ticks1ms = 0;
static void Task1ms(void){
#ifdef DEBUG
	printf("Task1ms ");
#endif

	Ticks1ms++;
	if(Ticks1ms%1000 == 0){
		Ticks1ms = 0;
	}
#if COMPILER == MINGW32

#elif COMPILER == DAVE
	/* Take a sample of the active oscilloscope channels */
	ProbeScope_Sampling();
#endif

//	MeasureBeltTension();

	if(Ticks1ms%5 == 1){
#ifdef DEBUG
		printf("5thTask1ms ");
#endif
//		ReceiveCommand();
//		TransmitState();
	}
}

uint32_t Ticks10ms = 0;
static void Task10ms(void){
#ifdef DEBUG
		printf("Task10ms ");
#endif
	Ticks10ms++;
	if(Ticks10ms%100 == 0){
		Ticks10ms = 0;
	}

//	MeasureSupplyVoltage();
//	CheckError();
//	ControlState();
//	DriveMotor();

}

static void Task100ms(void){
#if COMPILER == MINGW32

#elif COMPILER == DAVE
	DIGITAL_IO_ToggleOutput(&dhDO_100ms);
#endif
}

static void Task1000ms(void){

}

void TaskIdle(){


}

void CallBack1ms(){
	TickCounter++;
#ifdef DEBUG
	printf("\n%4d:",TickCounter);
#endif

	if(TickCounter == 1000){
		TickCounter = 0;
	}
	if(TickCounter%1 == 0){
		Task1msFlag = true;
	}
	if(TickCounter%10 == 1){
		Task10msFlag = true;
	}
	if(TickCounter%100 == 0){
		Task100msFlag = true;
	}
	if(TickCounter%1000 == 0){
		Task1000msFlag = true;
	}
}

/******************************************************************************/
/* Function Implementation (scope: exported)                                  */
/******************************************************************************/
void StaticScheduler_Init(void){

	TaskInit();

#if COMPILER == MINGW32

#elif COMPILER == DAVE
	TaskId1ms = SYSTIMER_CreateTimer(1000, SYSTIMER_MODE_PERIODIC, CallBack1ms, NULL);
	SYSTIMER_StartTimer(TaskId1ms);
#endif


}

void StaticScheduler_Loop(void){

	if(Task1msFlag == true){
		Task1ms();
		Task1msFlag = false;
	}

	if(Task10msFlag == true){
		Task10ms();
		Task10msFlag = false;
	}

	if(Task100msFlag == true){
		Task100ms();
		Task100msFlag = false;
	}

	if(Task1000msFlag == true){
		Task1000ms();
		Task1000msFlag = false;
	}

	TaskIdle();
}


/******************************************************************************/
/*                                                                            */
/*                            EOF                                             */
/*                                                                            */
/******************************************************************************/

/** @} */
#endif
