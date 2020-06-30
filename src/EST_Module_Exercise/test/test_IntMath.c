#include "unity.h"
#include "IntMath.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

/* I16Abs( ) =================*/
void test_I16Abs_WithInRange(void) {
    TEST_ASSERT_EQUAL_INT16(32767, I16Abs(32767));
    TEST_ASSERT_EQUAL_INT16(32767, I16Abs(-32767));
}

void test_I16Abs_Overflow(void) {
    TEST_ASSERT_EQUAL_INT16(-32768, I16Abs(32768));
}

void test_I16Abs_Underflow(void) {
    TEST_ASSERT_EQUAL_INT16(32767, I16Abs(-32769));
}

/* I16AbsSat( ) ====================*/
void test_I16AbsSat_WithInRange(void) {
    TEST_ASSERT_EQUAL_INT16(32767, I16AbsSat(32767));
    TEST_ASSERT_EQUAL_INT16(32767, I16AbsSat(-32767));
}

void test_I16AbsSat_Overflow(void) {
    TEST_ASSERT_EQUAL_INT16(32767, I16AbsSat(32768));
}

void test_I16AbsSat_Underflow(void) {
    TEST_ASSERT_EQUAL_INT16(32767, I16AbsSat(-32769));
}

/* I16Add( ) ===================*/
void test_I16Add_WithInRange(void) {
    TEST_ASSERT_EQUAL_INT16(32767, I16Add(32766, 1));
    TEST_ASSERT_EQUAL_INT16(-32768, I16Add(-32767, -1));
}

void test_I16Add_Overflow(void) {
    TEST_ASSERT_EQUAL_INT16(-32768, I16Add(32766, 2));
}

void test_I16Add_Underflow(void) {
    TEST_ASSERT_EQUAL_INT16(32767, I16Add(-32767, -2));
}

/* I16AddSat( ) ===================*/
void test_I16AddSat_WithInRange(void) {
    TEST_ASSERT_EQUAL_INT16(32767, I16AddSat(32766, 1));
    TEST_ASSERT_EQUAL_INT16(-32768, I16AddSat(-32767, -1));
}

void test_I16AddSat_Overflow(void) {
    TEST_ASSERT_EQUAL_INT16(32767, I16AddSat(32766, 2));
}

void test_I16AddSat_Underflow(void) {
    TEST_ASSERT_EQUAL_INT16(-32768, I16AddSat(-32767, -2));
}

/* I32Abs( ) =================*/
void test_I32Abs_WithInRange(void) {
    TEST_ASSERT_EQUAL_INT32(0x7FFFFFFF, I32Abs(0x7FFFFFFF));
    TEST_ASSERT_EQUAL_INT32(0x7FFFFFFF, I32Abs(-0x7FFFFFFF));
}

void test_I32Abs_Overflow(void) {
    TEST_ASSERT_EQUAL_INT32(-0x80000000, I32Abs(0x80000000));
}

void test_I32Abs_Underflow(void) {
    TEST_ASSERT_EQUAL_INT32(0x7FFFFFFF, I32Abs(-0x80000001));
}

/* I32AbsSat( ) ====================*/
void test_I32AbsSat_WithInRange(void) {
    TEST_ASSERT_EQUAL_INT32(0x7FFFFFFF, I32AbsSat(0x7FFFFFFF));
    TEST_ASSERT_EQUAL_INT32(0x7FFFFFFF, I32AbsSat(-0x7FFFFFFF));
}

void test_I32AbsSat_Overflow(void) {
    TEST_ASSERT_EQUAL_INT32(0x7FFFFFFF, I32AbsSat(0x80000000));
}

void test_I32AbsSat_Underflow(void) {
    TEST_ASSERT_EQUAL_INT32(0x7FFFFFFF, I32AbsSat(-0x80000000));
}

/* I32Add( ) ===================*/
void test_I32Add_WithInRange(void) {
    TEST_ASSERT_EQUAL_INT32(0x7FFFFFFF, I32Add(0x7FFFFFFE, 1));
    TEST_ASSERT_EQUAL_INT32(-0x80000000, I32Add(-0x7FFFFFFF, -1));
}

void test_I32Add_Overflow(void) {
    TEST_ASSERT_EQUAL_INT32(-0x80000000, I32Add(0x7FFFFFFE, 2));
}

void test_I32Add_Underflow(void) {
    TEST_ASSERT_EQUAL_INT32(0x7FFFFFFF, I32Add(-0x7FFFFFFF, -2));
}

/* I32AddSat( ) ===================*/
void test_I32AddSat_WithInRange(void) {
    TEST_ASSERT_EQUAL_INT32(0x7FFFFFFF, I32AddSat(0x7FFFFFFE, 1));
    TEST_ASSERT_EQUAL_INT32(-0x80000000, I32AddSat(-0x7FFFFFFF, -1));
}

void test_I32AddSat_Overflow(void) {
    TEST_ASSERT_EQUAL_INT32(0x7FFFFFFF, I32AddSat(0x7FFFFFFE, 2));
}

void test_I32AddSat_Underflow(void) {
    TEST_ASSERT_EQUAL_INT32(-0x80000000, I32AddSat(-0x7FFFFFFF, -2));
}


// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_I16Abs_WithInRange);
    RUN_TEST(test_I16Abs_Overflow);
    RUN_TEST(test_I16Abs_Underflow);

    RUN_TEST(test_I16AbsSat_WithInRange);
    RUN_TEST(test_I16AbsSat_Overflow);
    RUN_TEST(test_I16AbsSat_Underflow);

    RUN_TEST(test_I16Add_WithInRange);
    RUN_TEST(test_I16Add_Overflow);
    RUN_TEST(test_I16Add_Underflow);

    RUN_TEST(test_I16AddSat_WithInRange);
    RUN_TEST(test_I16AddSat_Overflow);
    RUN_TEST(test_I16AddSat_Underflow);

    RUN_TEST(test_I32Abs_WithInRange);
    RUN_TEST(test_I32Abs_Overflow);
    RUN_TEST(test_I32Abs_Underflow);

    RUN_TEST(test_I32AbsSat_WithInRange);
    RUN_TEST(test_I32AbsSat_Overflow);
    RUN_TEST(test_I32AbsSat_Underflow);

    RUN_TEST(test_I32Add_WithInRange);
    RUN_TEST(test_I32Add_Overflow);
    RUN_TEST(test_I32Add_Underflow);

    RUN_TEST(test_I32AddSat_WithInRange);
    RUN_TEST(test_I32AddSat_Overflow);
    RUN_TEST(test_I32AddSat_Underflow);

    return UNITY_END();
}
