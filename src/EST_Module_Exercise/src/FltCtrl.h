/***************************************************************************/
/**
 * @file     	FltCtrl.h
 *
 * @brief       Header file for IntCtrl
 *
 * @version     1.00
 * @date        Feb/18/2020
 * @warning
 * @note
 * <pre>
 * ---------------------------------------------------------------------------
 *               R E V I S I O N   H I S T O R Y
 * ---------------------------------------------------------------------------
 *   Date        Version  Author  Description
 *  ----------   -------  ------  --------------------------------------------
 *  2020-02-18   1.00             - Creation Release
 * </pre>
 *
 */
/******************************************************************************/

#ifndef FLT_CTRL_H_
#define FLT_CTRL_H_

/**
 * @defgroup FltCtrl FltCtrl
 * @{
 */

/******************************************************************************/
/* HEADER FILES                                                               */
/******************************************************************************/

/**** Standard types & definitions ****/
#include "PlatformTypes.h"

/**** Project types & definitions ****/

/**** Miscellaneous types & definitions ****/


/******************************************************************************
| Defines and macros            (scope: exported)
-----------------------------------------------------------------------------*/
#define FLT_IIR_FILTER1_DEFAULT {0.0,0.0,0.0,{0.0},{0.0}}
#define FLT_MA_FILTER_DEFAULT {0.0,8}
#define FLT_PI_CTRL_P_DEFAULT {0.0, 0.0, 0.0, 0.0, 0.0, HUGE_VALF, -HUGE_VALF, 0U}
#define FLT_PI_CTRL_R_DEFAULT {0.0, 0.0, 0.0, 0.0, HUGE_VALF, -HUGE_VALF, 0U}
#define FLT_LUT_1D_DEFAULT {1.0, 0, NULL, 8, 0, 0.0}

/* Type casting */

/******************************************************************************
| Typedefs and structures       (scope: exported)
-----------------------------------------------------------------------------*/
typedef struct{
	float flt_b0;		/*!< b0 coefficient of IIR1 filter float */
	float flt_b1;		/*!< b1 coefficient of IIR1 filter float */
	float flt_a1;		/*!< a1 coefficient of IIR1 filter float*/
	float flt_in_buffer[1]; /*!< input buffer of IIR1 filter */
	float flt_acc_buffer[1];/*!< internal accumulator buffer */
} fltIir_t;

typedef struct{
    float flt_acc;
    int16_t	i16_length;
} fltMa_t;

typedef struct{
	float 	fltPGain; 		/*!< K_p */
	float	fltIGain;		/*!< K_i * T_s / 2*/
	float 	fltIGain_Pre; 	/*!< K_i * T_s / 2*/
	float	fltUI_Pre;		/*!< u_i[k-1] */
	float 	fltE_Pre;		/*!< e[k-1] */
	float 	fltUpperLimit;
	float 	fltLowerLimit;
	uint16_t	u16LimitFlag;	/*! Set if u[k] is out of range */
} fltPiCtrlP_t;

typedef struct{
	float		fltEGain;		/*!< Gain for e[k] */
	float 		fltEGain_Pre;	/*!< Gain for e[k-1] */
	float		fltU_Pre;		/*!< u[k-1] */
	float 		fltE_Pre;		/*!< e[k-1] */
	float 		fltUpperLimit;
	float 		fltLowerLimit;
	uint16_t	u16LimitFlag;	/*! Set if u[k] is out of range */
} fltPiCtrlR_t;

typedef struct{
    float		flt_i2x_slope;		/*!< slope */
    int16_t 	i16_i2x_offset;		/*!< offset */
    float*		flt_tbl_ptr;		/*!< pointer to table */
    int16_t 	i16_num_of_elements;/*!< Number of elements */
    int16_t 	i16_idx;			/*!< index */
    float 		flt_remainder;		/*!< remainder */
} fltLut1D_t;

/******************************************************************************
| Exported Variables
-----------------------------------------------------------------------------*/


/******************************************************************************
| Exported function prototypes
-----------------------------------------------------------------------------*/

/***************************************************************************/
/**
@brief      This function implements Direct Form I first order IIR filter.

@param[in]  flt_in input value of float_t
@param[in]  pParam structure pointer for IirFilter1

@return     filtered value of flt_in

@note
*/
float fltIirFilter1(float flt_in, fltIir_t * pParam);

/***************************************************************************/
/**
@brief      This function implements Recursive Form of Moving average filter.

@param[in]  flt_in input value of float_t
@param[in/out]  pParam structure pointer for MaFilter

@return     filtered value of flt_in

@note
*/
float fltMaFilter(float flt_in, fltMa_t * pParam);

/***************************************************************************/
/**
@brief      PI Controller in Parallel Form

@param[in]  error input value of float_t
@param[in/out]  pParam structure pointer for PiCtrlP

@return     controller output of error

@note
*/
float fltPiCtrlP(float error, fltPiCtrlP_t * pParam);

/***************************************************************************/
/**
@brief      PI Controller in Recurrent Form

@param[in]  error input value of float_t
@param[in/out]  pParam structure pointer for PiCtrlR

@return     controller output of error

@note
*/
float fltPiCtrlR(float error, fltPiCtrlR_t * pParam);

/***************************************************************************/
/**
@brief      Look-up Table 1D

@param[in]  input value of int16_t
@param[in/out]  pParam structure pointer for fltLut1D

@return     interpolation value of input

@note
*/
float fltLut1D(int16_t i16_in, fltLut1D_t * pParam);


#endif /* FLT_CTRL_H_ */

/** @} */
