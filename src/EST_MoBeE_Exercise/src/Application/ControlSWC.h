/**
 * @defgroup ControlSWC ControlSWC
 * @{
 */

/******************************************************************************/
/**
 * @file         ControlSWC.h
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

#ifndef __CONTROLSWC_H__
#define __CONTROLSWC_H__

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
#define DIAG_VOLT_UNDER_LOWER 930         /**< [0.01V] The limit value to enter into Under voltage error */
#define DIAG_VOLT_UNDER_UPPER 970         /**< The limit value to exit from Under voltage error */
#define DIAG_VOLT_OVER_LOWER  1630        /**< The limit value to exit from Over voltage error */
#define DIAG_VOLT_OVER_UPPER  1670        /**< The limit value to enter into Over voltage error */

#define	ERROR_CODE_NORMAL	  	0x00
#define	ERROR_CODE_UNDEF_CMD  	0x01        /**< Undefined command error bit-mask */
#define ERROR_CODE_OVER_VOLT   	0x02        /**< Over voltage error bit-mask */
#define	ERROR_CODE_UNDER_VOLT  	0x04        /**< Under voltage error bit-mask */

#define READY_TENSION					0		/**< [0.01N] */
#define FREEING_TENSION					-2000
#define RELEASING_TENSION				-2000
#define BELT_PARKING_TENSION			2000
#define BELT_PARKING_COMPLETE_TENSION	2000
#define SLACK_REMOVING_TENSION			2000
#define SLACK_REMOVING_COMPLETE_TENSION	2000
#define WARNING_TENSION					8000
#define PRETENSION_TENSION				15000

#define FREEING_TIME			200		/**< [mSec] */
#define	RELEASING_TIME			600
#define WARNING_TIME			600
#define CONTROL_STATE_PERIOD	10

/******************************************************************************/
/******************************************************************************/
/*                           TYPEDEFS AND STRUCTURES                          */
/******************************************************************************/
/******************************************************************************/

typedef enum
{
	STATE_READY  			= 0,
	STATE_FREEING			= 1,
	STATE_RELEASING			= 2,
	STATE_BELT_PARKING		= 3,
	STATE_SLACK_REMOVING	= 4,
	STATE_WARNING			= 5,
	STATE_PRETENSION		= 6
} enuMsbState_t;



/******************************************************************************/
/******************************************************************************/
/*                           EXPORTED VARIABLES                               */
/******************************************************************************/
/******************************************************************************/
#ifdef DEBUG
extern uint8_t u8ErrorCode;
extern int16_t i16BeltTensionRef;
extern enuMsbState_t enuState;
#endif

/******************************************************************************/
/******************************************************************************/
/*                           EXPORTED FUNCTIONS                               */
/******************************************************************************/
/******************************************************************************/

/*Interface ==================================================================*/

/******************************************************************************/
/**
 * @name		GetErrorCode(void)
 * @brief
 * @pre			none
 * @param
 * @return		ErrorCode
 * @note @n
 *	-Global data: s16SupplyVoltageActual @n
 *	-Called by: none
 *	-Description:
 *		bit7: Not defined
 *		bit6: Not defined
 *		bit5: Not defined
 *		bit4: Not defined
 *		bit3: Not defined
 *		bit2: ERROR_CODE_UNDER_VOLT
 *		bit1: ERROR_CODE_OVER_VOLT
 *		bit0: ERROR_CODE_UNDEF_CMD
 */
/******************************************************************************/
uint8_t GetErrorCode(void);

int16_t GetBeltTensionRef(void);

enuMsbState_t GetState(void);

/******************************************************************************/
/**
 * @name		CheckError
 * @brief		Check error of supply voltage and command data
 * @pre			none
 * @param		commandActual, s16SupplyVoltageActual, enuCommandActual,
 *          DIAG_VOLT_OVER_UPPER, DIAG_VOLT_OVER_LOWER,
 *          DIAG_VOLT_UNDER_UPPER, DIAG_VOLT_UNDER_LOWER,
 * @return	u8ErrorCode
 * @note @n
 *	-Global data: s16SupplyVoltageActual @n
 *	-Called by: none
 *	-Description: Check Error of supply voltage and command data,
 *                and prevent MSB's operating in error states
 */
/******************************************************************************/
void CheckError(void);

void ControlState(void);

void InitControl(void);

#endif

/******************************************************************************/
/*                                                                            */
/*                            EOF                                             */
/*                                                                            */
/******************************************************************************/

/** @} */
