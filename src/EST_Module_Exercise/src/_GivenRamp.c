/*
 * GivenRamp.c
 *
 *  Created on: 2020. 2. 16.
 *      Author: Wootaik Lee
 */

#include <stdio.h>
#include <stdlib.h>
#include "PlatformTypes.h"

float_t RampStateMachine(float_t fltIn)
{

	typedef enum {
		STEADY = 0,
		INCREASING,
		DECREASING
	} RampState_t;


	float_t   fltIncrement = 1.0;
	float_t   fltDecrement = -1.0;
	static float_t	  fltOut = 0.0;
	static RampState_t enuRampState = STEADY;

	float_t flt_temp_inc = fltOut + fltIncrement;
	float_t flt_temp_dec = fltOut + fltDecrement;

	switch (enuRampState) {
		case STEADY:
			if(fltIn > flt_temp_inc){
				enuRampState = INCREASING;
				fltOut = flt_temp_inc;
			}else if(fltIn < flt_temp_dec){
				enuRampState = DECREASING;
				fltOut = flt_temp_dec;
			}else{
				fltOut = fltIn;
			}

			break;
		case INCREASING:
			if(fltIn < flt_temp_inc){
				enuRampState = STEADY;
				fltOut = fltIn;
			}else{
				fltOut = flt_temp_inc;
			}
			break;
		case DECREASING:
			if(fltIn > flt_temp_dec){
				enuRampState = STEADY;
				fltOut = fltIn;
			}else{
				fltOut = flt_temp_dec;
			}
			break;
		default:
			break;
	}

	return(fltOut);
}

float_t Ramp(float_t fltIn)
{

	static float_t   fltState = 0.0;
	float_t   fltIncrement = 1.0;
	float_t   fltDecrement = -1.0;

	float_t  flt_temp;
    float_t  flt_temp_inc;
    float_t  flt_temp_dec;

    flt_temp_inc = fltState + fltIncrement;
    flt_temp_dec = fltState + fltDecrement;

    flt_temp = (fltState <= fltIn) ? flt_temp_inc : flt_temp_dec;

    fltState = ((flt_temp_inc >= fltIn) && (flt_temp_dec <= fltIn))  ?
                            fltIn : flt_temp;
    return(fltState);

}

int main(void)
{
	float_t in[10] = {3.0, 3.0, 3.0, 3.5, 3.5, -1.0, -1.0, -1.0, -0.5, -1.0};
	float_t out[10] = {0.0} ;

	for (int var = 0; var < 10; ++var) {
		out[var] = Ramp(in[var]);
//		out[var] = RampStateMachine(in[var]);
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
