/**
 * @defgroup ActuatorSWC ActuatorSWC
 * @{
 */

/******************************************************************************/
/**
 * @file         ActuatorSWC.h
 *
 * @brief        The header of Control software component
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

#ifndef __ACTUATORSWC_H__
#define __ACTUATORSWC_H__

/******************************************************************************/
/******************************************************************************/
/*                           MODULES USED                                     */
/******************************************************************************/
/******************************************************************************/
/* Global Include */
#include "PlatformTypes.h"          /**< Include Global Data types*/
#include "MSB_DataTypes.h"          /**< Include MSB Data Types */
#include "ControlSWC.h"
/******************************************************************************/
/******************************************************************************/
/*                           DEFINITIONS AND MACROS                           */
/******************************************************************************/
/******************************************************************************/
#define POS_DIRECTION        1           /**< Rotate in positive direction */
#define NEG_DIRECTION        0           /**< Rotate in negative direction */
#define MOTOR_ENABLE         1           /**< Enable Motor */
#define MOTOR_DISABLE        0           /**< Disable Motor */

#define SCALE_MOTOR_VOL_NUM		1
#define SCALE_MOTOR_VOL_DEN		20
#define SCALE_MOTOR_VOL_OFFSET	7500

/******************************************************************************/
/******************************************************************************/
/*                           TYPEDEFS AND STRUCTURES                          */
/******************************************************************************/
/******************************************************************************/




/******************************************************************************/
/******************************************************************************/
/*                           EXPORTED VARIABLES                               */
/******************************************************************************/
/******************************************************************************/
#ifdef DEBUG
STATIC uint16_t u16MotorDuty;
STATIC uint16_t u16MotorVoltage;
STATIC uint8_t u8MotorEnable;
STATIC uint8_t u8MotorDirection;
STATIC enuMsbState_t enuStateMessage;
#endif

/******************************************************************************/
/******************************************************************************/
/*                           EXPORTED FUNCTIONS                               */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/**
 * @name		InitActuator
 * @brief	  Reset ActuatorSWC
 * @pre			none
 * @param		none
 * @return	    none
 * @note @n
 *	-Global data: none @n
 *	-Called by	:  @n
 *	-Description:
 *
 */
/******************************************************************************/
void InitActuator(void);

/******************************************************************************/
/**
 * @name		DriveMotor
 * @brief		Drive DC Motor of MSB Body
 * @pre			none
 * @param
 * @return
 * @note @n
 *	-Global data: u16MotorVoltage, u8Dio_Direction @n
 *	-Called by	:  none
 *	-Description: Decide u8MotorDirection, u8MotorEnable, u16Motor_Voltage by @n
 *                s16BeltTensionRef. If s16BeltTensionRef is positive value, @n
 *                direction of DC Motor is 1 and s16BeltTensionRef is negative value,
 *                direction of DC Motor is 0
 */
/******************************************************************************/
void DriveMotor(void);

/******************************************************************************/
/**
 * @name		TransmitState
 * @brief		Transmit MSB State information
 * @pre			none
 * @param
 * @return
 * @note @n
 *	-Global data: u16MotorVoltage, u8Dio_Direction @n
 *	-Called by	:  none
 *	-Description:
 */
/******************************************************************************/
void TransmitState(void);

#endif

/******************************************************************************/
/*                                                                            */
/*                            EOF                                             */
/*                                                                            */
/******************************************************************************/

/** @} */
