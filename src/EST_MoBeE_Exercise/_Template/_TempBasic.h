/******************************************************************************/
/**
 * @file         _TempBasic.h
 *
 * @brief        Header file for _TempBasic
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

#ifndef BASIC_H
#define BASIC_H

/**
 * @defgroup Basic _TempBasic 
 * @{
 */

/******************************************************************************/
/* HEADER FILES                                                               */
/******************************************************************************/

/**** Standard types & definitions ****/
#include "PlatformTypes.h"

/**** Project types & definitions ****/


/**** Miscellaneous types & definitions ****/


/******************************************************************************/
/* DEFINITIONS AND MACROS                                                     */
/******************************************************************************/


/******************************************************************************/
/* TYPEDEFS AND STRUCTURES                                                    */
/******************************************************************************/

/**** enum type definitions ***************************************************/

/**
 *  @enum eScheStatus
 *	@brief Status of Scheduler
 */
typedef enum eScheStatus
{
  RUNNING = 0,   /**< Running status */
  ELAPSED          /**< Elapsed status */
} eScheStatus_t;

/**** structures type definitions ********************************************/

/**
@struct     sScheTable_t
@brief      Structure containing the current state of the filter.
*/
typedef struct sScheTable
{    
     uint32		u32_period;     /**< Period of task */
     uint32 	u32_offset;     /**< Offset of task */
} sScheTable_t;

/**** extra type definitions ****/

/******************************************************************************/
/* EXPORTED VARIABLES                                                         */
/******************************************************************************/

extern eScheStatus_t Sch_eScheStatus;

/******************************************************************************/
/* EXPORTED FUNCTIONS                                                         */
/******************************************************************************/

/***************************************************************************/
/**
@brief      Initialization of the timer for scheduler
@param[in]  pParam   Pointer to the parameters structure.
@param[out] pState   Pointer to the state structure.
@param[in,out] pi32InBuf Pointer to a buffer for storing input signal
@return     void.
void Sche_InitTimer(const sScheTable_t * pParam,
                               eScheStatus_t * pState,
                               int32_t *pi32InBuf);
 */
void Sche_InitTimer(const sScheTable_t * pParam,
                               eScheStatus_t * pState,
                               int32_t *pi32InBuf);


#endif

/******************************************************************************/
/*                            EOF                                             */
/******************************************************************************/

/** @} */
