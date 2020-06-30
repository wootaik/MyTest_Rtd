/**
 * @defgroup ControlSWC ControlSWC
 * @{
 */

/******************************************************************************/
/**
 * @file         ControlSWC.c
 *
 * @brief        The source of Control software component
 *
 * @version 0.9  @date Jul/03/2008
 * @author       KyeongJin,Lee
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

#ifndef __CONTROLSWC_C__
#define __CONTROLSWC_C__

/******************************************************************************/
/******************************************************************************/
/*                           MODULES USED                                     */
/******************************************************************************/
/******************************************************************************/
#include "ControlSWC.h"
#include "SensorSWC.h"

/******************************************************************************/
/******************************************************************************/
/*                           DEFINITIONS AND MACROS                           */
/******************************************************************************/
/******************************************************************************/


/******************************************************************************/
/******************************************************************************/
/*                           TYPEDEFS AND STRUCTURES                          */
/******************************************************************************/
typedef enum {
	NORMAL_COMMAND,
	UNDEFINED_COMMAND
} state_cmd_t;

typedef enum {
	NORMAL_VOLTAGE,
	UNDER_VOLTAGE,
	OVER_VOLTAGE
} state_vol_t;



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

STATIC uint8_t u8ErrorCode;
STATIC int16_t i16BeltTensionRef;
STATIC enuMsbState_t enuState;



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


uint8_t GetErrorCode(void)
{
	return(u8ErrorCode);
}

int16_t GetBeltTensionRef(void)
{
	return(i16BeltTensionRef);
}

enuMsbState_t GetState(void)
{
	return(enuState);
}


void CheckError(void)
{     
  static state_cmd_t state_cmd = NORMAL_COMMAND;
  static state_vol_t state_vol = NORMAL_VOLTAGE;
  int16_t supply_voltage;
  enuMsbCommand_t msb_command;
  uint8_t error_code = 0U;
  
  supply_voltage = GetSupplyVoltage();
  msb_command = GetCommand();
     
  /**< Undefined command Error state */
  switch (state_cmd)
  {
	case NORMAL_COMMAND: /**< No error in cmd */
		if(msb_command == CMD_UNDEFINED)
		{
			state_cmd = UNDEFINED_COMMAND;
			error_code = error_code | ERROR_CODE_UNDEF_CMD;
		}
		break;
	case UNDEFINED_COMMAND: /**< undefined command error in cmd */
		if(msb_command != CMD_UNDEFINED)
		{
			state_cmd = NORMAL_COMMAND;
			error_code = error_code & ~ERROR_CODE_UNDEF_CMD;
		}
		break;
	default:
		;
		break;
  }

  /**< Supply Voltage Error state */
  switch (state_vol)
  {
	case NORMAL_VOLTAGE: /**< No voltage error */
		if(supply_voltage >= DIAG_VOLT_OVER_UPPER)
		{
			state_vol = OVER_VOLTAGE;
			error_code = error_code | ERROR_CODE_OVER_VOLT;
		}
		else if(supply_voltage <= DIAG_VOLT_UNDER_LOWER)
		{
			state_vol = UNDER_VOLTAGE;
			error_code = error_code | ERROR_CODE_UNDER_VOLT;
		}
		else
		{
			;
		}
		break;
	case OVER_VOLTAGE: /**< Over voltage */
		if(supply_voltage <= DIAG_VOLT_OVER_LOWER)
		{
			state_vol = NORMAL_VOLTAGE;
			error_code = error_code & ~ERROR_CODE_OVER_VOLT;
		}
		break;
	case UNDER_VOLTAGE: /**< Over voltage */
		if(supply_voltage >= DIAG_VOLT_UNDER_UPPER)
		{
			state_vol = NORMAL_VOLTAGE;
			error_code = error_code & ~ERROR_CODE_UNDER_VOLT;
		}
		break;
	default:
		;
		break;
  }
  u8ErrorCode = error_code;
}  

void ControlState(void)
{
	enuMsbState_t my_state = enuState;
	enuMsbCommand_t my_cmd = GetCommand();
	int16_t my_tension = GetBeltTension();

	static int16_t time_out = 0;

	switch (my_state) {

		case STATE_READY:
			i16BeltTensionRef = READY_TENSION;

			if(CMD_BUCKLING == my_cmd)
			{
				my_state = STATE_SLACK_REMOVING;
				time_out = 0;
			}else if(CMD_UNBUCKLING == my_cmd)
			{
				my_state = STATE_BELT_PARKING;
				time_out = 0;
			}else if(CMD_WARNING == my_cmd)
			{
				my_state = STATE_WARNING;
				time_out = 0;
			}else if(CMD_PRETENSION == my_cmd)
			{
				my_state = STATE_PRETENSION;
				time_out = 0;
			}else
			{
				;
			}

			break;

		case STATE_FREEING:
			i16BeltTensionRef = FREEING_TENSION;
			// Freeing time-out
			if(FREEING_TIME < time_out){
				my_state = STATE_READY;
				time_out = 0;
			}else{
				time_out = time_out + CONTROL_STATE_PERIOD;
			}
			break;

		case STATE_RELEASING:
			i16BeltTensionRef = RELEASING_TENSION;
			// Releasing time-out
			if(RELEASING_TIME < time_out){
				my_state = STATE_READY;
				time_out = 0;
			}else{
				time_out = time_out + CONTROL_STATE_PERIOD;
			}

			break;

		case STATE_BELT_PARKING:
			i16BeltTensionRef = BELT_PARKING_TENSION;
			if(BELT_PARKING_COMPLETE_TENSION < my_tension){
				my_state = STATE_FREEING;
				time_out = 0;
			}
			break;

		case STATE_SLACK_REMOVING:
			i16BeltTensionRef = SLACK_REMOVING_TENSION;
			if(SLACK_REMOVING_COMPLETE_TENSION < my_tension){
				my_state = STATE_FREEING;
				time_out = 0;
			}
			break;

		case STATE_WARNING:
			i16BeltTensionRef = WARNING_TENSION;
			// WARNING time-out
			if(WARNING_TIME < time_out){
				my_state = STATE_FREEING;
				time_out = 0;
			}else{
				time_out = time_out + CONTROL_STATE_PERIOD;
			}
			break;

		case STATE_PRETENSION:
			i16BeltTensionRef = PRETENSION_TENSION;
			if(CMD_RELEASING == my_cmd){
				my_state = STATE_RELEASING;
				time_out = 0;
			}else if(CMD_FREEING == my_cmd){
				my_state = STATE_FREEING;
				time_out = 0;
			}

			break;

		default:
			break;
	}

	enuState = my_state;
}

void InitControl(void)
{
	u8ErrorCode = 0;
	i16BeltTensionRef = 0;
	enuState = STATE_READY;
}


#endif

/******************************************************************************/
/*                                                                            */
/*                            EOF                                             */
/*                                                                            */
/******************************************************************************/

/** @} */
