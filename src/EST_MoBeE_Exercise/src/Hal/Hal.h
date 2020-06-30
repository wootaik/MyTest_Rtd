/**
 * @defgroup Hal Hal
 * @{
 */

/******************************************************************************/
/**
 * @file         Hal.h
 *
 * @brief        the header of HAL
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
 *  Date        Version  Author     Description
 *  ----------   -------  ---------  -----------------------------------------
 *  2008-07-03   0.90     KyeongJin  - Creation  Prerelease
 * </pre>
 *
 */
/******************************************************************************/

#ifndef __HAL_H__
#define __HAL_H__

/******************************************************************************/
/******************************************************************************/
/*                           MODULES USED                                     */
/******************************************************************************/
/******************************************************************************/
/* Global Include */
#include "PlatformTypes.h"           /**< Include Global Data types*/
#include "MSB_DataTypes.h"           /**< Include MSB Data Types */  


/******************************************************************************/
/******************************************************************************/
/*                           DEFINITIONS AND MACROS                           */
/******************************************************************************/
/******************************************************************************/
#define SUPPLY_VOL_CHANNEL				0
#define MOTOR_CUR_CHANNEL				1


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
STATIC uint16_t Hal_SupplyVoltage;
STATIC uint8_t Hal_MsbCommand;
STATIC uint16_t Hal_MotorCurrent;

STATIC uint16_t Hal_MotorDuty;
STATIC uint8_t Hal_MotorEnable;
STATIC uint8_t Hal_MotorDirection;
STATIC uint8_t Hal_MsbStateMessage;
#endif

/******************************************************************************/
/******************************************************************************/
/*                           EXPORTED FUNCTIONS                               */
/******************************************************************************/
/******************************************************************************/

/**< Get and Set fuction to get data from HAL area or to set data to HAL area */

/******************************************************************************/
/**
 * @fn  	  uint16_t Adc_GetData(uint16_t channel)
 * @brief
 * @pre			none
 * @param[in]	uint16_t channel
 * @return	    u16RawAdcValue 10-bit
 * @note @n
 *	-Global data:  @n
 *	-Called by	: SensorSWC @n
 *	-Description:
 *
 */
/******************************************************************************/
uint16_t Adc_GetData(uint16_t channel);

/******************************************************************************/
/**
 * @fn  	  uint8_t Can_GetData(uint16_t signal);
 * @brief
 * @pre			none
 * @param[in]	uint16_t signal
 * @return	    u8RawMsbCommand
 * @note @n
 *	-Global data:  @n
 *	-Called by	: SensorSWC @n
 *	-Description:
 *
 */
/******************************************************************************/
uint8_t Can_GetData(uint16_t signal);

/******************************************************************************/
/**
 * @fn  	  void Can_SetData(uint16_t signal)
 * @brief
 * @pre			none
 * @param		uint16_t signal
 * @return
 * @note @n
 *	-Global data:  @n
 *	-Called by	: ActuatorSWC @n
 *	-Description:
 *
 */
/******************************************************************************/
void Can_SetData(uint16_t signal);

/******************************************************************************/
/**
 * @fn  	  void Pwm_SetData(uint16_t motor_duty)
 * @brief
 * @pre			none
 * @param		[in] uint16_t motor_duty
 * @return	    none
 * @note @n
 *	-Global data: u16ActualMotorDuty @n
 *	-Called by	: ActuatorSWC @n
 *	-Description:
 *
 */
/******************************************************************************/
void Pwm_SetData(uint16_t motor_duty);

/******************************************************************************/
/**
 * @fn  	  void Dio_SetMotorEnable(uint8_t motor_enable)
 * @brief
 * @pre			none
 * @param		[in] motor_enable
 * @return	    none
 * @note @n
 *	-Global data: u8ActualMotorEnable @n
 *	-Called by	: ActuatorSWC @n
 *	-Description:
 *
 */
/******************************************************************************/
void Dio_SetMotorEnable(uint8_t motor_enable);

/******************************************************************************/
/**
 * @fn  	  void Dio_SetMotorDirection(uint8_t motor_dir)
 * @brief
 * @pre			none
 * @param		[in] motor_dir
 * @return	    none
 * @note @n
 *	-Global data: u8ActualMotorDirection @n
 *	-Called by	: ActuatorSWC @n
 *	-Description:
 *
 */
/******************************************************************************/
void Dio_SetMotorDirection(uint8_t motor_dir);

#endif

/******************************************************************************/
/*                                                                            */
/*                            EOF                                             */
/*                                                                            */
/******************************************************************************/

/** @} */
