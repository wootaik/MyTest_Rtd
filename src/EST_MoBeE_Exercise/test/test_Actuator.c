#include "unity.h"
#include "ActuatorSWC.h"
#include "ControlSWC.h"
#include "SensorSWC.h"
#include "Hal.h"

void setUp(void) {
    // set stuff up here
	i16SupplyVoltage = 1200; //12[V]
}

void tearDown(void) {
    // clean stuff up here
}

void test_InitActuator_Dummy(void)
{
	InitActuator();
	TEST_ASSERT_EQUAL_UINT16(0, u16MotorVoltage);
	TEST_ASSERT_EQUAL_UINT16(0, u16MotorDuty);
	TEST_ASSERT_EQUAL_UINT8(0, u8MotorEnable);
	TEST_ASSERT_EQUAL_UINT8(0, u8MotorDirection);
	TEST_ASSERT_EQUAL_UINT(STATE_READY, enuStateMessage);
}

void test_DriveMotor_Dummy(void)
{
	// Error
	u8ErrorCode = ERROR_CODE_OVER_VOLT;
	i16BeltTensionRef = 2000;
	DriveMotor();
	TEST_ASSERT_EQUAL_UINT8(MOTOR_DISABLE, u8MotorEnable);
	TEST_ASSERT_EQUAL_UINT16(0, u16MotorVoltage);
	TEST_ASSERT_EQUAL_UINT16(0, u16MotorDuty);

	// Normal 0N 10A 3.75V 3.75/12*10000
	u8ErrorCode = ERROR_CODE_NORMAL;
	i16BeltTensionRef = 0;
	DriveMotor();
	TEST_ASSERT_EQUAL_UINT8(MOTOR_ENABLE, u8MotorEnable);
	TEST_ASSERT_EQUAL_UINT8(POS_DIRECTION, u8MotorDirection);
	TEST_ASSERT_EQUAL_UINT16(375, u16MotorVoltage);
	TEST_ASSERT_EQUAL_UINT16((10000*375)/1200, u16MotorDuty);

	// Normal 75N 20A 7.5V 7.5/12*10000
	u8ErrorCode = ERROR_CODE_NORMAL;
	i16BeltTensionRef = 7500;
	DriveMotor();
	TEST_ASSERT_EQUAL_UINT8(MOTOR_ENABLE, u8MotorEnable);
	TEST_ASSERT_EQUAL_UINT8(POS_DIRECTION, u8MotorDirection);
	TEST_ASSERT_EQUAL_UINT16(750, u16MotorVoltage);
	TEST_ASSERT_EQUAL_UINT16((10000*750)/1200, u16MotorDuty);

	// Normal 150N 30A 15*3/4V 15*3/4*10000
	u8ErrorCode = ERROR_CODE_NORMAL;
	i16BeltTensionRef = 15000;
	DriveMotor();
	TEST_ASSERT_EQUAL_UINT8(MOTOR_ENABLE, u8MotorEnable);
	TEST_ASSERT_EQUAL_UINT8(POS_DIRECTION, u8MotorDirection);
	TEST_ASSERT_EQUAL_UINT16(1500*3/4, u16MotorVoltage);
	TEST_ASSERT_EQUAL_UINT16((10000*1500*3/4)/1200, u16MotorDuty);

}

void test_TransmitState_Dummy(void)
{
	enuState = STATE_BELT_PARKING;
	TransmitState();
	TEST_ASSERT_EQUAL_INT(STATE_BELT_PARKING, Hal_MsbStateMessage);

	enuState = STATE_RELEASING;
	TransmitState();
	TEST_ASSERT_EQUAL_INT(STATE_RELEASING, Hal_MsbStateMessage);
}



// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_InitActuator_Dummy);
    RUN_TEST(test_DriveMotor_Dummy);
    RUN_TEST(test_TransmitState_Dummy);

    return UNITY_END();
}
