/***************************************************************************/
/**
 * @file     	.c
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

#include "PlatformTypes.h"
#include <stdio.h>


float_t Hysteresis(float_t fltIn){
    float_t   fltUpperThreshold = 1.0;
    float_t   fltLowerThreshold = -1.0;
    float_t   fltUpperOutput = 5.0;
    float_t   fltLowerOutput= -5.0;
    static float_t   fltHystState = 0.0;
    float_t  flt_temp;

    flt_temp = (fltIn < fltUpperThreshold) ? fltHystState : fltUpperOutput ;

    fltHystState = (fltIn <= fltLowerThreshold) ? fltLowerOutput : flt_temp ;

    return(fltHystState);
}
int main(void)
{
	float_t out[10] = {0.0} ;
	float_t in[10] = { 0.0, 2.0, 3.0, 0.0, -0.5, -1.0, -1.1, 0.5, 1.1, 2.0};

	for (int var = 0; var < 10; ++var) {
		out[var] = Hysteresis(in[var]);
		printf(" in = %4.2f ===> out = %4.2f\n", in[var], out[var]);
	}

    return(0);
}

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}


/* End of file */

