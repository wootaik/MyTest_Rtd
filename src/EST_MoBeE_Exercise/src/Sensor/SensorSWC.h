/**
 * @defgroup SensorSWC SensorSWC
 * @{
 */

/******************************************************************************/
/**
 * @file         SensorSWC.h
 *
 * @brief        The header of Sensor Sofware Component
 *
 * @version 0.9  @date Jul/03/2008
 * @author       KyeongJin, Lee 
 * @warning
 * @bug
 * @note
 * <pre>
 * ---------------------------------------------------------------------------
 *               R E V I S I O N   H I S T O R Y
 * ---------------------------------------------------------------------------
 *   Date        Version  Author     Description
 *  ----------   -------  ---------  -----------------------------------------
 *  2008-07-03   0.90     KyeongJin  - Creation  Prerelease
 * </pre>
 *
 */
/******************************************************************************/

#ifndef __SENSORSWC_H__
#define __SENSORSWC_H__

/******************************************************************************/
/******************************************************************************/
/*                           MODULES USED                                     */
/******************************************************************************/
/******************************************************************************/
/* Global Include */
#include "PlatformTypes.h"          /**< Include Global Data types*/
#include "MSB_DataTypes.h"          /**< Include MSB Data Types */

/******************************************************************************/
/******************************************************************************/
/*                           DEFINITIONS AND MACROS                           */
/******************************************************************************/
/******************************************************************************/

/**< Some parameters split into num and den value due to the MISRA Rule */
#define SCALE_SUPPLY_VOLTAGE 	3
#define SCALE_MOTOR_CURRENT		4
#define SCALE_CURRENT_TENSION_NUM	150
#define SCALE_CURRENT_TENSION_DEN	20
#define SCALE_CURRENT_TENSION_OFFSET	1000

/******************************************************************************/
/******************************************************************************/
/*                           TYPEDEFS AND STRUCTURES                          */
/******************************************************************************/
/******************************************************************************/

/*! \enum enuMsbCommand_t
* enuCommandAcutal's type, Command data of MSB
*/
typedef enum
{
    CMD_UNDEFINED 	= 0x00,      	/**< This is not defined command, it is cause of error */
	CMD_FREEING 	,         /**< Freeing command */
	CMD_RELEASING 	,       	/**< Releasing command */
	CMD_UNBUCKLING 	,      	/**< Unbuckling command */
	CMD_BUCKLING 	,        	/**< buckling command */
	CMD_WARNING 	,         /**< Warning command */
	CMD_PRETENSION 	      	/**< Pretension command */
} enuMsbCommand_t;




/******************************************************************************/
/******************************************************************************/
/*                           EXPORTED VARIABLES                               */
/******************************************************************************/
/******************************************************************************/
#ifdef DEBUG
STATIC int16_t i16SupplyVoltage;
STATIC enuMsbCommand_t enuCommand;
STATIC int16_t i16BeltTension;
STATIC int16_t i16MotorCurrent;
#endif


/******************************************************************************/
/******************************************************************************/
/*                           EXPORTED FUNCTIONS                               */
/******************************************************************************/
/******************************************************************************/

/*Interface ==================================================================*/
int16_t GetSupplyVoltage(void);
enuMsbCommand_t GetCommand(void);
int16_t GetBeltTension(void);

/*Procedure ==================================================================*/

/******************************************************************************/
/**
 * @name		ReceiveCommand
 * @brief		Get command of MSB
 * @pre			none
 * @param		none
 * @return		none
 * @note @n
 *	-Global data: u8MsbCommandMessage @n
 *	-Called by	: TaskB @n
 *	-Description: Get Can message and convert to command data @n
 */
/******************************************************************************/
void ReceiveCommand(void);

/******************************************************************************/
/**
 * @name		MeasureSupplyVoltage
 * @brief		Get supply voltage info of MSB
 * @pre			none
 * @param		none
 * @return		none
 * @note @n
 *	-Global data: none @n
 *	-Called by	: TaskA @n
 *	-Description: Get Adc value of supply voltage, @n
 *                and convert to physical abstraction value @n
 */
/******************************************************************************/
void MeasureSupplyVoltage(void);

/******************************************************************************/
/**
 * @name		MeasureBeltTension
 * @brief		Get supply voltage info of MSB
 * @pre			none
 * @param		none
 * @return		none
 * @note @n
 *	-Global data: none @n
 *	-Called by	: TaskA @n
 *	-Description: Get Adc value of supply voltage, @n
 *                and convert to physical abstraction value @n
 */
/******************************************************************************/
void MeasureBeltTension(void);

/******************************************************************************/
/**
 * @name		InitSensor
 * @brief		Initialization of sensor module
 * @pre			none
 * @param		s16SupplyVoltageActual, enuCommandActual, s16BeltTensionActual,
 *              UNDEFINED_CMD
 * @return		none
 * @note @n
 *	-Global data: s16SupplyVoltageActual @n
 *	-Called by	: none
 *	-Description: Initialize datum which are used in sensor module
 */
/******************************************************************************/
void InitSensor(void);

#endif

/******************************************************************************/
/*                                                                            */
/*                            EOF                                             */
/*                                                                            */
/******************************************************************************/

/** @} */
