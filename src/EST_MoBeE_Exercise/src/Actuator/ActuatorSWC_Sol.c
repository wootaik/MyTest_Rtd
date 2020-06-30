/**
 * @defgroup ActuatorSWC ActuatorSWC
 * @{
 */

/******************************************************************************/
/**
 * @file         ActuatorSWC.c
 *
 * @brief        The source of Control software component
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
 *  </pre>
 *
 */
/******************************************************************************/

#ifndef __ACTUATORSWC_C__
#define __ACTUATORSWC_C__

/******************************************************************************/
/******************************************************************************/
/*                           MODULES USED                                     */
/******************************************************************************/
/******************************************************************************/
#include "ActuatorSWC.h"
#include "ControlSWC.h"
#include "SensorSWC.h"
#include "Hal.h"




/******************************************************************************/
/******************************************************************************/
/*                           DEFINITIONS AND MACROS                           */
/******************************************************************************/
/******************************************************************************/


								  
/******************************************************************************/
/******************************************************************************/
/*                           TYPEDEFS AND STRUCTURES                          */
/******************************************************************************/



/******************************************************************************/
/******************************************************************************/
/*                           PROTOTYPES OF LOCAL FUNCTIONS                    */
/******************************************************************************/
/******************************************************************************/



/******************************************************************************/
/******************************************************************************/
/*                           STATIC VARIABLES                                 */
/******************************************************************************/
/******************************************************************************/
STATIC uint16_t u16MotorDuty;
STATIC uint16_t u16MotorVoltage;         /**< Supply voltage to Motor */ 
STATIC uint8_t u8MotorEnable;            /**< Info about whether Enabling or Disabling Motor */ 
STATIC uint8_t u8MotorDirection;         /**< Info about whether rotating in Positive direction or Negative direction */

STATIC enuMsbState_t enuStateMessage;


/******************************************************************************/
/******************************************************************************/
/*                           LOCAL FUNCTIONS                                  */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
/*                           EXPORTED FUNCTIONS                               */
/******************************************************************************/
/******************************************************************************/


void DriveMotor(void)
{
  uint8_t my_error_code;
  int16_t my_belt_tension_ref;
  int16_t my_supply_voltage;
  
  my_error_code = GetErrorCode();
  my_belt_tension_ref = GetBeltTensionRef();
  my_supply_voltage = GetSupplyVoltage();
  
  /**< Error State */
  if(my_error_code != ERROR_CODE_NORMAL)
  {
    u16MotorVoltage = 0;
    u8MotorEnable = MOTOR_DISABLE;
  }
  
  /**< No Error State */
  else
  {
    u8MotorEnable = MOTOR_ENABLE;
    if(my_belt_tension_ref >= 0)
    { 
      u8MotorDirection = POS_DIRECTION;
    }
    else 
    {
      u8MotorDirection = NEG_DIRECTION;
      my_belt_tension_ref = -1 * my_belt_tension_ref;
    }
    u16MotorVoltage = SCALE_MOTOR_VOL_NUM * (my_belt_tension_ref + SCALE_MOTOR_VOL_OFFSET ) / SCALE_MOTOR_VOL_DEN;
  }
  
  u16MotorDuty =(int16_t)( (int32_t)10000* u16MotorVoltage / my_supply_voltage);  /**< Calculation of PwmDuty Output */

  Pwm_SetData(u16MotorDuty);
  Dio_SetMotorEnable(u8MotorEnable);
  Dio_SetMotorDirection(u8MotorDirection);
}
  

void TransmitState(void)
{
	enuStateMessage = GetState();
	Can_SetData(enuStateMessage);
}


void InitActuator(void)
{
  u16MotorDuty = 0;
  u16MotorVoltage = 0;
  u8MotorEnable = 0;
  u8MotorDirection = 0;

  enuStateMessage = STATE_READY;
}


#endif

/******************************************************************************/
/*                                                                            */
/*                            EOF                                             */
/*                                                                            */
/******************************************************************************/

/** @} */
