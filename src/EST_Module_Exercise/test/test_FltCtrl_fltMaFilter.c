#include <stdio.h>
#include "unity.h"
#include "FltCtrl.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_fltMaFilter(void)
{
	FILE *fp = fopen(".\\test\\data\\FltMaFilterResult.csv","w");

	float_t input;
	float_t output;

	fltMa_t my_ma = FLT_MA_FILTER_DEFAULT;

    // filter coefficients
    my_ma.flt_acc           = (float_t)  0.0 ;
    my_ma.i16_length        = (int16_t)  16 ;

    fprintf(fp, "idx,  input,  output\n");

    input  = (float_t) 0.0;
    for (int var = 0; var < 5; ++var) {
        output = fltMaFilter(input,&my_ma);
        fprintf(fp,"%d,%f,%f\n", var, input, output);
	}

    input  = (float_t) 1000.0;
    for (int var = 5; var < 50; ++var) {
        output = fltMaFilter(input,&my_ma);
        fprintf(fp,"%d,%f,%f\n", var, input, output);
	}

    input  = (float_t) -1000.0;
    for (int var = 50; var < 100; ++var) {
        output = fltMaFilter(input,&my_ma);
        fprintf(fp,"%d,%f,%f\n", var, input, output);
	}
    fclose(fp);
}

// not needed when using generate_test_runner.rb
int main(void) {
    test_fltMaFilter();
}
