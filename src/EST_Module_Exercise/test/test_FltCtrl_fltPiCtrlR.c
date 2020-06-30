#include <stdio.h>
#include "unity.h"
#include "FltCtrl.h"

fltPiCtrlR_t MyPiCtrlR;

void setUp(void) {
    // set stuff up here
	// Kp = 1, KiTs/2 = 0.5
	MyPiCtrlR = (fltPiCtrlR_t) { 1.5, -0.5, 0.0, 0.0, 10.0, -10.0, 0U };
}

void tearDown(void) {
    // clean stuff up here
}

void test_fltPiCtrlR(void)
{
	FILE *fp = fopen(".\\test\\data\\FltPiCtrlRResult.csv","w");

	float_t input;
	float_t output;

    // controller struct
	// Kp = 1, KiTs/2 = 0.5
	fltPiCtrlR_t my_struct = (fltPiCtrlR_t) { 1.5, -0.5, 0.0, 0.0, 10.0, -10.0, 0U };

    fprintf(fp, "idx,  input,  output\n");

    input  = (float_t) 0.0;
    for (int var = 0; var < 10; ++var) {
        output = fltPiCtrlR(input,&my_struct);
        fprintf(fp,"%d,%f,%f\n", var, input, output);
	}

    input  = (float_t) 1.0;
    for (int var = 10; var < 50; ++var) {
        output = fltPiCtrlR(input,&my_struct);
        fprintf(fp,"%d,%f,%f\n", var, input, output);
	}

    input  = (float_t) -1.0;
    for (int var = 50; var < 100; ++var) {
        output = fltPiCtrlR(input,&my_struct);
        fprintf(fp,"%d,%f,%f\n", var, input, output);
	}
    fclose(fp);
}

void test_fltPiCtrlR_POnly(void)
{
	// Kp = 1, KiTs/2 = 0.0
	MyPiCtrlR.fltEGain = 1.0;
	MyPiCtrlR.fltEGain_Pre = -1.0;
	MyPiCtrlR.fltU_Pre = 0.0;

	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, fltPiCtrlR(1.0, &MyPiCtrlR));
	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, MyPiCtrlR.fltU_Pre);
	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, MyPiCtrlR.fltE_Pre);
	TEST_ASSERT_EQUAL_UINT16(0U, MyPiCtrlR.u16LimitFlag);

	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, fltPiCtrlR(1.0, &MyPiCtrlR));
	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, MyPiCtrlR.fltU_Pre);
	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, MyPiCtrlR.fltE_Pre);
	TEST_ASSERT_EQUAL_UINT16(0U, MyPiCtrlR.u16LimitFlag);
}

void test_fltPiCtrlR_IOnly(void)
{
	// Kp = 0, KiTs/2 = 1.0
	MyPiCtrlR.fltEGain = 1.0;
	MyPiCtrlR.fltEGain_Pre = 1.0;
	MyPiCtrlR.fltU_Pre = 0.0;

	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, fltPiCtrlR(1.0, &MyPiCtrlR));
	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, MyPiCtrlR.fltU_Pre);
	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, MyPiCtrlR.fltE_Pre);

	TEST_ASSERT_FLOAT_WITHIN(0.001, 3.0, fltPiCtrlR(1.0, &MyPiCtrlR));
	TEST_ASSERT_FLOAT_WITHIN(0.001, 3.0, MyPiCtrlR.fltU_Pre);
	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, MyPiCtrlR.fltE_Pre);
}

void test_fltPiCtrlR_UpperLimit(void)
{
	// Kp = 1, KiTs/2 = 0.5
	MyPiCtrlR.fltU_Pre = 8.0;

	TEST_ASSERT_FLOAT_WITHIN(0.001, 9.5, fltPiCtrlR(1.0, &MyPiCtrlR));
	TEST_ASSERT_FLOAT_WITHIN(0.001, 9.5, MyPiCtrlR.fltU_Pre);
	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, MyPiCtrlR.fltE_Pre);
	TEST_ASSERT_EQUAL_UINT16(0U, MyPiCtrlR.u16LimitFlag);

	TEST_ASSERT_FLOAT_WITHIN(0.001, 10.0, fltPiCtrlR(1.0, &MyPiCtrlR));
	TEST_ASSERT_FLOAT_WITHIN(0.001, 10.0, MyPiCtrlR.fltU_Pre);
	TEST_ASSERT_FLOAT_WITHIN(0.001, 1.0, MyPiCtrlR.fltE_Pre);
	TEST_ASSERT_EQUAL_UINT16(true, MyPiCtrlR.u16LimitFlag);
}

void test_fltPiCtrlR_LowerLimit(void)
{
	// Kp = 1, KiTs/2 = 0.5
	MyPiCtrlR.fltU_Pre = -8.0;

	TEST_ASSERT_FLOAT_WITHIN(0.001, -9.5, fltPiCtrlR(-1.0, &MyPiCtrlR));
	TEST_ASSERT_FLOAT_WITHIN(0.001, -9.5, MyPiCtrlR.fltU_Pre);
	TEST_ASSERT_FLOAT_WITHIN(0.001, -1.0, MyPiCtrlR.fltE_Pre);
	TEST_ASSERT_EQUAL_UINT16(0U, MyPiCtrlR.u16LimitFlag);

	TEST_ASSERT_FLOAT_WITHIN(0.001, -10.0, fltPiCtrlR(-1.0, &MyPiCtrlR));
	TEST_ASSERT_FLOAT_WITHIN(0.001, -10.0, MyPiCtrlR.fltU_Pre);
	TEST_ASSERT_FLOAT_WITHIN(0.001, -1.0, MyPiCtrlR.fltE_Pre);
	TEST_ASSERT_EQUAL_UINT16(true, MyPiCtrlR.u16LimitFlag);
}


// not needed when using generate_test_runner.rb
int main(void) {
    test_fltPiCtrlR();

    UNITY_BEGIN();

    RUN_TEST(test_fltPiCtrlR_POnly);
    RUN_TEST(test_fltPiCtrlR_IOnly);
    RUN_TEST(test_fltPiCtrlR_UpperLimit);
    RUN_TEST(test_fltPiCtrlR_LowerLimit);

    return UNITY_END();
}
