#include <stdio.h>
#include "unity.h"
#include "IntCtrl.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_I16IirFilter1(void)
{
	FILE *fp = fopen(".\\test\\data\\I16IirFilter1Result.csv","w");
//	FILE *fp = fopen("I16IirFilter1Result.csv","w");

	int16_t i16Input;
	int16_t i16Output;

	i16Iir_t my_iir = I16_IIR_FILTER1_DEFAULT;

    // filter coefficients
    my_iir.i16B0           = (int16_t) ( 0.1 * 0x7FFF); //FRAC16(0.1);
    my_iir.i16B1           = (int16_t) ( 0.0 * 0x7FFF); //FRAC16(0.0);
    my_iir.i16A1           = (int16_t) (-0.9 * 0x7FFF); //FRAC16(-0.9);

    fprintf(fp, "idx,  input,  output\n");

    i16Input  = (int16_t) 00;
    for (int var = 0; var < 5; ++var) {
        i16Output = I16IirFilter1(i16Input,&my_iir);
        fprintf(fp,"%d,%d,%d\n", var, i16Input, i16Output);
	}

    i16Input  = (int16_t) 1000;
    for (int var = 5; var < 50; ++var) {
        i16Output = I16IirFilter1(i16Input,&my_iir);
        fprintf(fp,"%d,%d,%d\n", var, i16Input, i16Output);
	}

    i16Input  = (int16_t) -1000;
    for (int var = 50; var < 100; ++var) {
        i16Output = I16IirFilter1(i16Input,&my_iir);
        fprintf(fp,"%d,%d,%d\n", var, i16Input, i16Output);
	}
    fclose(fp);
}

// not needed when using generate_test_runner.rb
int main(void) {
    test_I16IirFilter1();
}
