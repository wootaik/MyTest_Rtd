#include <stdio.h>
#include "unity.h"
#include "FltCtrl.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_fltIirFilter1(void)
{
	FILE *fp = fopen(".\\test\\data\\FltIirFilter1Result.csv","w");

	float_t input;
	float_t output;

	fltIir_t my_iir = FLT_IIR_FILTER1_DEFAULT;

    // filter coefficients
    my_iir.flt_b0           = (float_t)  0.091 ;
    my_iir.flt_b1           = (float_t)  0.0 ;
    my_iir.flt_a1           = (float_t) -0.909 ;

    fprintf(fp, "idx,  input,  output\n");

    input  = (float_t) 0.0;
    for (int var = 0; var < 5; ++var) {
        output = fltIirFilter1(input,&my_iir);
        fprintf(fp,"%d,%f,%f\n", var, input, output);
	}

    input  = (float_t) 1000.0;
    for (int var = 5; var < 50; ++var) {
        output = fltIirFilter1(input,&my_iir);
        fprintf(fp,"%d,%f,%f\n", var, input, output);
	}

    input  = (float_t) -1000.0;
    for (int var = 50; var < 100; ++var) {
        output = fltIirFilter1(input,&my_iir);
        fprintf(fp,"%d,%f,%f\n", var, input, output);
	}
    fclose(fp);
}

// not needed when using generate_test_runner.rb
int main(void) {
    test_fltIirFilter1();
}
