/***************************************************************************/
/**
 * @file     	_GivenIntMath.c
 *
 * @brief       Source file for IntMath
 *
 * @version     1.00
 * @date        Feb/18/2010
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

/******************************************************************************
| Includes
-----------------------------------------------------------------------------*/
#include "PlatformTypes.h"
#include <stdio.h>

#define I16Add(x, y) (int16_t) ( ((int16_t) x) + ((int16_t) y) )
#define I32Add(x, y) (int32_t) ( ((int32_t) x) + ((int32_t) y) )


int16_t I16Abs(int16_t x)
{
    return (int16_t) ((x<0) ? -(x) : (x) );
}


int16_t I16AbsSat(int16_t x)
{
    int32_t y;
    y = (int32_t) x < 0 ? -(int32_t) x : (int32_t) x;
    y = (y == -((int32_t) INT16_MIN)) ? (int32_t) INT16_MAX : y;
    return (int16_t) y;
}


int16_t I16AddSat(int16_t x, int16_t y)
{
    int32_t z;
    z = (int32_t) x + (int32_t) y;

    z = (z> (int32_t)INT16_MAX) ? (int32_t) INT16_MAX : z;
    z = (z< (int32_t)INT16_MIN) ? (int32_t) INT16_MIN : z;

    return (int16_t) z;
}


int32_t I32Abs(int32_t x)
{
    return (x<0) ? -x : x ;
}


int32_t I32AbsSat(int32_t x)
{
    int32_t y;

    y = (x < 0) ? -x : x;
    y = (y == INT32_MIN) ? INT32_MAX : y;

    return y;
}

int32_t I32AddSat(int32_t x, int32_t y)
{
    int32_t z;
    int32_t sat_max, sat_min;

    z = x + y;

    sat_max = ~(x|y) & z;
    sat_min = x & y & ~z;

    z = (sat_min < 0) ? INT32_MIN : z;
    z = (sat_max < 0) ? INT32_MAX : z;

    return z;
}

int main(void)
{
	// I16Abs()
	printf("I16Abs() Results\n");
	printf("I16Abs(%d) == %d\n", 32767, I16Abs(32767));
	printf("I16Abs(%d) == %d\n", -32767, I16Abs(-32767));
	printf("I16Abs(%d) == %d\n", 32768, I16Abs(32768));
	printf("I16Abs(%d) == %d\n", -32769, I16Abs(-32769));

	// I16AbsSat()
	printf("I16AbsSat() Results\n");
	printf("I16AbsSat(%d) == %d\n", 32767, I16AbsSat(32767));
	printf("I16AbsSat(%d) == %d\n", -32767, I16AbsSat(-32767));
	printf("I16AbsSat(%d) == %d\n", 32768, I16AbsSat(32768));
	printf("I16AbsSat(%d) == %d\n", -32769, I16AbsSat(-32769));

	// I16Add()
	printf("I16Add() Results\n");
	printf("I16Add(%d, %d) == %d\n", 32766, 1, I16Add(32766, 1));
	printf("I16Add(%d, %d) == %d\n", -32767, -1, I16Add(-32767, -1));
	printf("I16Add(%d, %d) == %d\n", 32766, 2, I16Add(32766, 2));
	printf("I16Add(%d, %d) == %d\n", -32767, -2, I16Add(-32767, -2));

	// I16AddSat()
	printf("I16AddSat() Results\n");
	printf("I16AddSat(%d, %d) == %d\n", 32766, 1, I16AddSat(32766, 1));
	printf("I16AddSat(%d, %d) == %d\n", -32767, -1, I16AddSat(-32767, -1));
	printf("I16AddSat(%d, %d) == %d\n", 32766, 2, I16AddSat(32766, 2));
	printf("I16AddSat(%d, %d) == %d\n", -32767, -2, I16AddSat(-32767, -2));



	return(0);
}

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}


/* End of file */

