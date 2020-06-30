#include <stdio.h>
#include "unity.h"
#include "FltCtrl.h"

#define MY_TBL_SIZE 8
fltLut1D_t MyLut1D;
float MyTbl[MY_TBL_SIZE] = {-1.0, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

void setUp(void) {
    // set stuff up here
	MyLut1D = (fltLut1D_t) { 10.0, -25, MyTbl, MY_TBL_SIZE, 0, 0.0};
}

void tearDown(void) {
    // clean stuff up here
}

void test_fltLut1D_NearLower(void)
{
	TEST_ASSERT_FLOAT_WITHIN(0.001, -0.5, fltLut1D(-20.0, &MyLut1D));
	TEST_ASSERT_FLOAT_WITHIN(0.001, -0.9, fltLut1D(-24.0, &MyLut1D));
}

void test_fltLut1D_NearUpper(void)
{
	TEST_ASSERT_FLOAT_WITHIN(0.001, 5.5, fltLut1D(40.0, &MyLut1D));
	TEST_ASSERT_FLOAT_WITHIN(0.001, 5.9, fltLut1D(44.0, &MyLut1D));
}

void test_fltLut1D_UpperLimit(void)
{
	TEST_ASSERT_FLOAT_WITHIN(0.001, 6.0, fltLut1D(45.0, &MyLut1D));
	TEST_ASSERT_FLOAT_WITHIN(0.001, 6.0, fltLut1D(50.0, &MyLut1D));
	TEST_ASSERT_FLOAT_WITHIN(0.001, 6.0, fltLut1D(60.0, &MyLut1D));
}

void test_fltLut1D_LowerLimit(void)
{
	TEST_ASSERT_FLOAT_WITHIN(0.001, -1.0, fltLut1D(-25.0, &MyLut1D));
	TEST_ASSERT_FLOAT_WITHIN(0.001, -1.0, fltLut1D(-30.0, &MyLut1D));
	TEST_ASSERT_FLOAT_WITHIN(0.001, -1.0, fltLut1D(-50.0, &MyLut1D));
}


// not needed when using generate_test_runner.rb
int main(void) {
//	printf("fltLut1D = %f  ",fltLut1D(-30.0, &MyLut1D));
//	printf("idx = %d, remainder = %f \n",MyLut1D.i16_idx, MyLut1D.flt_remainder);

	UNITY_BEGIN();

    RUN_TEST(test_fltLut1D_NearLower);
    RUN_TEST(test_fltLut1D_NearUpper);
    RUN_TEST(test_fltLut1D_UpperLimit);
    RUN_TEST(test_fltLut1D_LowerLimit);

    return UNITY_END();
}
