#include "unity.h"
#include "SensorSWC.h"
#include "Hal.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_GetSupplyVoltage_Dummy(void)
{
	i16SupplyVoltage = 0xAAAA;
	TEST_ASSERT_EQUAL_INT16(0xAAAA, GetSupplyVoltage());
}

void test_GetCommand_Dummy(void)
{
	enuCommand = CMD_FREEING;
	TEST_ASSERT_EQUAL_INT(CMD_FREEING, GetCommand());
}

void test_GetBeltTension_Dummy(void)
{
	i16BeltTension = 15000;
	TEST_ASSERT_EQUAL_INT16(15000, GetBeltTension());
}

void test_MeasureSupplyVoltage_Dummy(void)
{
	Hal_SupplyVoltage = 1023;
	MeasureSupplyVoltage();
	TEST_ASSERT_EQUAL_INT16(1023*3, GetSupplyVoltage());
}

void test_ReceiveCommand_Dummy(void)
{
	Hal_MsbCommand = CMD_BUCKLING;
	ReceiveCommand();
	TEST_ASSERT_EQUAL_INT(CMD_BUCKLING, GetCommand());

	Hal_MsbCommand = CMD_WARNING;
	ReceiveCommand();
	TEST_ASSERT_EQUAL_INT(CMD_WARNING, GetCommand());
}

void test_MeasureBeltTension_Dummy(void)
{
	// 5A -> 0N
	Hal_MotorCurrent = (uint16_t)(1024*0.12*5 /5);
	MeasureBeltTension();
	TEST_ASSERT_INT16_WITHIN(100, 500, i16MotorCurrent);
	TEST_ASSERT_INT16_WITHIN(750, 0, GetBeltTension());

	// 10A -> 0N
	Hal_MotorCurrent = (uint16_t)(1024*0.12*10 /5);
	MeasureBeltTension();
	TEST_ASSERT_INT16_WITHIN(100, 1000, i16MotorCurrent);
	TEST_ASSERT_INT16_WITHIN(750, 0, GetBeltTension());

	// 20A -> 75N
	Hal_MotorCurrent = (uint16_t)(1024*0.12*20 /5);
	MeasureBeltTension();
	TEST_ASSERT_INT16_WITHIN(100, 2000, i16MotorCurrent);
	TEST_ASSERT_INT16_WITHIN(750, 7500, GetBeltTension());

	// 30A -> 150N
	Hal_MotorCurrent = (uint16_t)(1024*0.12*30 /5);
	MeasureBeltTension();
	TEST_ASSERT_INT16_WITHIN(100, 3000, i16MotorCurrent);
	TEST_ASSERT_INT16_WITHIN(750, 15000, GetBeltTension());
}

void test_InitSensor_Dummy(void)
{
	InitSensor();
	TEST_ASSERT_EQUAL_INT16(0, GetSupplyVoltage());
	TEST_ASSERT_EQUAL_INT(0, GetCommand());
	TEST_ASSERT_EQUAL_INT16(0, GetBeltTension());
}


// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_GetSupplyVoltage_Dummy);
    RUN_TEST(test_GetCommand_Dummy);
    RUN_TEST(test_GetBeltTension_Dummy);

    RUN_TEST(test_MeasureSupplyVoltage_Dummy);
    RUN_TEST(test_ReceiveCommand_Dummy);
    RUN_TEST(test_MeasureBeltTension_Dummy);
    RUN_TEST(test_InitSensor_Dummy);

    return UNITY_END();
}
