#include <stdio.h>
#include "unity.h"
#include "FltCtrl.h"

fltPiCtrlP_t MyPiCtrlP;

void setUp(void) {
    // set stuff up here
	MyPiCtrlP = (fltPiCtrlP_t) { 1.0, 0.5, 0.5, 0.0, 0.0, 10.0, -10.0, 0U };
}

void tearDown(void) {
    // clean stuff up here
}

void test_fltPiCtrlP(void)
{
	FILE *fp = fopen(".\\test\\data\\FltPiCtrlPResult.csv","w");

	float_t input;
	float_t output;

    // controller struct
	fltPiCtrlP_t my_struct = (fltPiCtrlP_t) { 10.0, 0.5, 0.5, 0.0, 0.0, 30.0, -30.0, 0U };

    fprintf(fp, "idx,  input,  output\n");

    input  = (float_t) 0.0;
    for (int var = 0; var < 10; ++var) {
        output = fltPiCtrlP(input,&my_struct);
        fprintf(fp,"%d,%f,%f\n", var, input, output);
	}

    input  = (float_t) 1.0;
    for (int var = 10; var < 50; ++var) {
        output = fltPiCtrlP(input,&my_struct);
        fprintf(fp,"%d,%f,%f\n", var, input, output);
	}

    input  = (float_t) -2.0;
    for (int var = 50; var < 100; ++var) {
        output = fltPiCtrlP(input,&my_struct);
        fprintf(fp,"%d,%f,%f\n", var, input, output);
	}
    fclose(fp);
}

void test_fltPiCtrlP_POnly(void)
{
	MyPiCtrlP.fltIGain = 0.0;
	MyPiCtrlP.fltIGain_Pre = 0.0;

	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, fltPiCtrlP(1.0, &MyPiCtrlP));
	TEST_ASSERT_FLOAT_WITHIN(0.001, 0.0, MyPiCtrlP.fltUI_Pre);
	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, MyPiCtrlP.fltE_Pre);
	TEST_ASSERT_EQUAL_UINT16(0U, MyPiCtrlP.u16LimitFlag);
}

void test_fltPiCtrlP_IOnly(void)
{
	MyPiCtrlP.fltPGain = 0.0;

	TEST_ASSERT_FLOAT_WITHIN(0.001, 0.5, fltPiCtrlP(1.0, &MyPiCtrlP));
	TEST_ASSERT_FLOAT_WITHIN(0.001, 0.5, MyPiCtrlP.fltUI_Pre);
	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, MyPiCtrlP.fltE_Pre);

	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.5, fltPiCtrlP(1.0, &MyPiCtrlP));
	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.5, MyPiCtrlP.fltUI_Pre);
	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, MyPiCtrlP.fltE_Pre);
}

void test_fltPiCtrlP_UpperLimit(void)
{
	MyPiCtrlP.fltUpperLimit = 10.0;
	MyPiCtrlP.fltUI_Pre = 8.0;

	TEST_ASSERT_FLOAT_WITHIN(0.001, 9.5, fltPiCtrlP(1.0, &MyPiCtrlP));
	TEST_ASSERT_FLOAT_WITHIN(0.001, 8.5, MyPiCtrlP.fltUI_Pre);
	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, MyPiCtrlP.fltE_Pre);
	TEST_ASSERT_EQUAL_UINT16(0U, MyPiCtrlP.u16LimitFlag);

	TEST_ASSERT_FLOAT_WITHIN(0.001, 10.0, fltPiCtrlP(1.0, &MyPiCtrlP));
	TEST_ASSERT_FLOAT_WITHIN(0.001, 9.0, MyPiCtrlP.fltUI_Pre);
	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, MyPiCtrlP.fltE_Pre);
	TEST_ASSERT_EQUAL_UINT16(true, MyPiCtrlP.u16LimitFlag);
}

void test_fltPiCtrlP_LowerLimit(void)
{
	MyPiCtrlP.fltLowerLimit = -10.0;
	MyPiCtrlP.fltUI_Pre = -8.0;

	TEST_ASSERT_FLOAT_WITHIN(0.001, -9.5, fltPiCtrlP(-1.0, &MyPiCtrlP));
	TEST_ASSERT_FLOAT_WITHIN(0.001, -8.5, MyPiCtrlP.fltUI_Pre);
	TEST_ASSERT_FLOAT_WITHIN(0.001, -1.0, MyPiCtrlP.fltE_Pre);
	TEST_ASSERT_EQUAL_UINT16(0U, MyPiCtrlP.u16LimitFlag);

	TEST_ASSERT_FLOAT_WITHIN(0.001, -10.0, fltPiCtrlP(-1.0, &MyPiCtrlP));
	TEST_ASSERT_FLOAT_WITHIN(0.001, -9.0, MyPiCtrlP.fltUI_Pre);
	TEST_ASSERT_FLOAT_WITHIN(0.001, -1.0, MyPiCtrlP.fltE_Pre);
	TEST_ASSERT_EQUAL_UINT16(true, MyPiCtrlP.u16LimitFlag);
}


// not needed when using generate_test_runner.rb
int main(void) {
    test_fltPiCtrlP();

    UNITY_BEGIN();

    RUN_TEST(test_fltPiCtrlP_POnly);
    RUN_TEST(test_fltPiCtrlP_IOnly);
    RUN_TEST(test_fltPiCtrlP_UpperLimit);
    RUN_TEST(test_fltPiCtrlP_LowerLimit);

    return UNITY_END();
}
