/***************************************************************************/
/**
 * @file     	FltCtrl.c
 *
 * @brief       Source file for FltCtr;
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

/******************************************************************************
| Includes
-----------------------------------------------------------------------------*/
#include "FltCtrl.h"

/******************************************************************************
| External declarations
-----------------------------------------------------------------------------*/

/******************************************************************************
| Defines and macros            (scope: module-local)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Typedefs and structures       (scope: module-local)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Global variable definitions   (scope: module-exported)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Global variable definitions   (scope: module-local)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Function prototypes           (scope: module-local)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Function implementations      (scope: module-local)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Function implementations      (scope: module-exported)
-----------------------------------------------------------------------------*/

float fltIirFilter1(float flt_in, fltIir_t * pParam)
{
    register float flt_m1;
    register float flt_m2;
    register float flt_m3;
    register float flt_acc;

    /*
     * Implemented equation:
     * y(k) = b0*x(k) + b1*x(k-1) - a1*y(k-1)
     *
     * Calculation steps:
     * m1   = b0*x(k)
     * m2   = b1*x(k-1)
     * m3   = a1*y(k-1)
     * acc  = m1 + (m2 - m3)
     * y(k) = acc
     */

    // m1   = b0*x(k)
    flt_m1 = pParam->flt_b0 * flt_in;

    // m2   = b1*x(k-1)
    flt_m2 = pParam->flt_b1 * pParam->flt_in_buffer[0];

    // m3   = a1*y(k-1)
    flt_m3 = pParam->flt_a1 * pParam->flt_acc_buffer[0];

    // acc  = m1+m2-m3
    flt_acc = flt_m1 + (flt_m2 - flt_m3);

    // Storing filter states in the buffer
    pParam->flt_in_buffer[0]   = flt_in;
    pParam->flt_acc_buffer[0]  = flt_acc;

    // Returning internal accumulator
    return(flt_acc);

}

float fltMaFilter(float flt_in, fltMa_t * pParam)
{
	register float flt_y;


	return(flt_y);
}

float fltPiCtrlP(float error, fltPiCtrlP_t * pParam)
{
	register float p_term;
	register float i_term;
	register float u;

	/*
	 * Calc P-term
	 * Calc I-term
	 * Check Limit & Set LimitFlag
	 * Store I-term to UI_Pre
	 * Store Err to E_Pre
	 */

	p_term = pParam->fltPGain * error;

	i_term = pParam->fltUI_Pre
			+ pParam->fltIGain * error + pParam->fltIGain_Pre * pParam->fltE_Pre;

	u = p_term + i_term;
	if(u > pParam->fltUpperLimit)
	{
		u = pParam->fltUpperLimit;
		i_term =   u - p_term;
		pParam->u16LimitFlag = true;
	}
	else if (u < pParam->fltLowerLimit)
	{
		u = pParam->fltLowerLimit;
		i_term =  u - p_term;
		pParam->u16LimitFlag = true;
	}
	else
	{
		pParam->u16LimitFlag = false;
	}

	pParam->fltUI_Pre = i_term;
	pParam->fltE_Pre = error;

	return(u);
}

float fltPiCtrlR(float error, fltPiCtrlR_t * pParam)
{
	register float u;



	return(u);
}


float fltLut1D(int16_t i16_in, fltLut1D_t * pParam)
{
	register float y;
	register float y1;
	register float y2;
	register int16_t idx;
	register float remainder;

	/* Calc i16_idx
	 * Check i16_idx within range
	 * Calc remainder
	 * Calc y and return
	 */
	idx = (int16_t)((i16_in - pParam->i16_i2x_offset)/pParam->flt_i2x_slope);
	if ((idx<=0) && (i16_in <= pParam->i16_i2x_offset))
	{
		idx = 0;
		remainder = 0.0;
		y = *(pParam->flt_tbl_ptr + idx);
	}else if (idx>=(pParam->i16_num_of_elements -1))
	{
		idx = pParam->i16_num_of_elements -1;
		remainder = 0.0;
		y = *(pParam->flt_tbl_ptr + idx);
	}else
	{
		remainder = (float)i16_in - (idx * pParam->flt_i2x_slope + pParam->i16_i2x_offset);
		y1 = *(pParam->flt_tbl_ptr + idx);
		y2 = *(pParam->flt_tbl_ptr + idx +1);
		y = y1 + (y2-y1)/pParam->flt_i2x_slope * remainder;
	}

	pParam->i16_idx = idx;
	pParam->flt_remainder = remainder;

	return(y);
}

/* End of file */

