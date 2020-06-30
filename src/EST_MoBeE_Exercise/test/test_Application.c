#include "unity.h"
#include "ControlSWC.h"
#include "SensorSWC.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_GetErrorCode_Dummy(void)
{
	u8ErrorCode = ERROR_CODE_OVER_VOLT;
	TEST_ASSERT_EQUAL_UINT8(ERROR_CODE_OVER_VOLT, GetErrorCode());
	u8ErrorCode = ERROR_CODE_UNDER_VOLT;
	TEST_ASSERT_EQUAL_UINT8(ERROR_CODE_UNDER_VOLT, GetErrorCode());
	u8ErrorCode = ERROR_CODE_UNDEF_CMD;
	TEST_ASSERT_EQUAL_UINT8(ERROR_CODE_UNDEF_CMD, GetErrorCode());
}

void test_GetBeltTensionRef_Dummy(void)
{
	i16BeltTensionRef = 0x5555;
	TEST_ASSERT_EQUAL_INT16(0x5555, GetBeltTensionRef());
}

void test_GetState_Dummy(void)
{
	enuState = STATE_RELEASING;
	TEST_ASSERT_EQUAL_INT(STATE_RELEASING, GetState());
	enuState = STATE_WARNING;
	TEST_ASSERT_EQUAL_INT(STATE_WARNING, GetState());
}

void test_CheckError_Normal2Over2Normal(void)
{
	enuCommand = CMD_FREEING;
	i16SupplyVoltage = 1300;

	/* Normal */
	i16SupplyVoltage = DIAG_VOLT_OVER_LOWER - 100;
	CheckError();
	TEST_ASSERT_EQUAL_UINT8(0, u8ErrorCode);

	/* Normal -> Bet. OVER_LOWER & OVER_UPPER */
	i16SupplyVoltage = (DIAG_VOLT_OVER_LOWER + DIAG_VOLT_OVER_UPPER)/2 ;
	CheckError();
	TEST_ASSERT_EQUAL_UINT8(0, u8ErrorCode);

	/* Bet. OVER_LOWER & OVER_UPPER -> OVER*/
	i16SupplyVoltage = DIAG_VOLT_OVER_UPPER + 100 ;
	CheckError();
	TEST_ASSERT_EQUAL_UINT8(ERROR_CODE_OVER_VOLT, u8ErrorCode);

	/* Over -> Normal */
	i16SupplyVoltage = DIAG_VOLT_OVER_LOWER - 100;
	CheckError();
	TEST_ASSERT_EQUAL_UINT8(0, u8ErrorCode);

}

void test_CheckError_Normal2Under2Normal(void)
{
	enuCommand = CMD_FREEING;
	i16SupplyVoltage = 1300;

	/* Normal */
	i16SupplyVoltage = DIAG_VOLT_UNDER_UPPER + 100;
	CheckError();
	TEST_ASSERT_EQUAL_UINT8(0, u8ErrorCode);

	/* Normal -> Bet. UNDER_LOWER & UNDER_UPPER */
	i16SupplyVoltage = (DIAG_VOLT_UNDER_LOWER + DIAG_VOLT_UNDER_UPPER)/2 ;
	CheckError();
	TEST_ASSERT_EQUAL_UINT8(0, u8ErrorCode);

	/* Bet. UNDER_LOWER & UNDER_UPPER -> UNDER*/
	i16SupplyVoltage = DIAG_VOLT_UNDER_LOWER - 100 ;
	CheckError();
	TEST_ASSERT_EQUAL_UINT8(ERROR_CODE_UNDER_VOLT, u8ErrorCode);

	/* Normal */
	i16SupplyVoltage = DIAG_VOLT_UNDER_UPPER + 100;
	CheckError();
	TEST_ASSERT_EQUAL_UINT8(0, u8ErrorCode);

}

void test_CheckError_Normal2UndefCmd2Normal(void)
{
	enuCommand = CMD_FREEING;
	i16SupplyVoltage = 1300;

	/* Normal */
	enuCommand = CMD_RELEASING;
	CheckError();
	TEST_ASSERT_EQUAL_UINT8(0, u8ErrorCode);

	/* Normal -> UNDEFINED_CMD */
	enuCommand = CMD_UNDEFINED;
	CheckError();
	TEST_ASSERT_EQUAL_UINT8(ERROR_CODE_UNDEF_CMD, u8ErrorCode);

	/* UNDEFINED_CMD -> Normal */
	enuCommand = CMD_UNBUCKLING;
	CheckError();
	TEST_ASSERT_EQUAL_UINT8(0, u8ErrorCode);


}
void test_ControlState_Ready2BeltParking(void)
{
	enuState = STATE_READY;

	enuCommand = CMD_UNBUCKLING;
	i16BeltTension = 0x5555;

	ControlState();
	TEST_ASSERT_EQUAL_INT(STATE_BELT_PARKING, GetState());
	ControlState();
	TEST_ASSERT_EQUAL_INT16(BELT_PARKING_TENSION, GetBeltTensionRef());
}

void test_ControlState_Ready2SlackRemoving(void)
{
	enuState = STATE_READY;

	enuCommand = CMD_BUCKLING;
	i16BeltTension = 0x5555;

	ControlState();
	TEST_ASSERT_EQUAL_INT(STATE_SLACK_REMOVING, GetState());
	ControlState();
	TEST_ASSERT_EQUAL_INT16(SLACK_REMOVING_TENSION , GetBeltTensionRef());
}

void test_ControlState_Ready2Pretension(void)
{
	enuState = STATE_READY;

	enuCommand = CMD_PRETENSION;
	i16BeltTension = 0x5555;

	ControlState();
	TEST_ASSERT_EQUAL_INT(STATE_PRETENSION, GetState());
	ControlState();
	TEST_ASSERT_EQUAL_INT16(PRETENSION_TENSION , GetBeltTensionRef());
}

void test_ControlState_Ready2Warning(void)
{
	enuState = STATE_READY;

	enuCommand = CMD_WARNING;
	i16BeltTension = 0x5555;

	ControlState();
	TEST_ASSERT_EQUAL_INT(STATE_WARNING, GetState());
	ControlState();
	TEST_ASSERT_EQUAL_INT16(WARNING_TENSION , GetBeltTensionRef());
}

void test_ControlState_SlackRemoving2Freeing(void)
{
	enuState = STATE_SLACK_REMOVING;

	/* 무반응 시험*/
	enuCommand = CMD_BUCKLING;
	i16BeltTension = SLACK_REMOVING_COMPLETE_TENSION - 100;
	ControlState();
	TEST_ASSERT_EQUAL_INT(STATE_SLACK_REMOVING, GetState());
	ControlState();
	TEST_ASSERT_EQUAL_INT16(SLACK_REMOVING_TENSION , GetBeltTensionRef());

	/* 반응 반응*/
	i16BeltTension = SLACK_REMOVING_COMPLETE_TENSION + 100;
	ControlState();
	TEST_ASSERT_EQUAL_INT(STATE_FREEING, GetState());
	ControlState();
	TEST_ASSERT_EQUAL_INT16(FREEING_TENSION , GetBeltTensionRef());
}

void test_ControlState_BeltParking2Freeing(void)
{
	enuState = STATE_BELT_PARKING;

	/* 무반응 시험*/
	enuCommand = CMD_UNBUCKLING;
	i16BeltTension = BELT_PARKING_COMPLETE_TENSION - 100;
	ControlState();
	TEST_ASSERT_EQUAL_INT16(BELT_PARKING_TENSION , GetBeltTensionRef());
	TEST_ASSERT_EQUAL_INT(STATE_BELT_PARKING, GetState());

	/* 반응 반응*/
	i16BeltTension = BELT_PARKING_COMPLETE_TENSION + 100;
	ControlState();
	TEST_ASSERT_EQUAL_INT(STATE_FREEING, GetState());
	ControlState();
	TEST_ASSERT_EQUAL_INT16(FREEING_TENSION , GetBeltTensionRef());
}

void test_ControlState_Releasing2Ready(void)
{
	enuState = STATE_RELEASING;
	i16BeltTension = 0x5555;

	/* 무반응 시험*/
	enuCommand = CMD_RELEASING;
	for (int var = 0; var < (RELEASING_TIME/CONTROL_STATE_PERIOD); var++) {
		ControlState();
		TEST_ASSERT_EQUAL_INT(STATE_RELEASING, GetState());
	}
	/* 반응 반응*/
	ControlState();
	TEST_ASSERT_EQUAL_INT(STATE_READY, GetState());
	ControlState();
	TEST_ASSERT_EQUAL_INT16(READY_TENSION , GetBeltTensionRef());

}

void test_ControlState_Pretension2Releasing(void)
{
	enuState = STATE_PRETENSION;

	enuCommand = CMD_RELEASING;
	i16BeltTension = 0x5555;

	ControlState();
	TEST_ASSERT_EQUAL_INT(STATE_RELEASING, GetState());
	ControlState();
	TEST_ASSERT_EQUAL_INT16(RELEASING_TENSION , GetBeltTensionRef());
}

void test_ControlState_Pretension2Freeing(void)
{
	enuState = STATE_PRETENSION;

	enuCommand = CMD_FREEING;
	i16BeltTension = 0x5555;

	ControlState();
	TEST_ASSERT_EQUAL_INT(STATE_FREEING, GetState());
	ControlState();
	TEST_ASSERT_EQUAL_INT16(FREEING_TENSION , GetBeltTensionRef());
}

void test_ControlState_Warning2Freeing(void)
{
	enuState = STATE_WARNING;
	i16BeltTension = 0x5555;

	/* 무반응 시험*/
	enuCommand = CMD_WARNING;
	for (int var = 0; var < (WARNING_TIME/CONTROL_STATE_PERIOD); var++) {
		ControlState();
		TEST_ASSERT_EQUAL_INT(STATE_WARNING, GetState());
	}
	/* 반응 시험*/
	ControlState();
	TEST_ASSERT_EQUAL_INT(STATE_FREEING, GetState());
	ControlState();
	TEST_ASSERT_EQUAL_INT16(FREEING_TENSION , GetBeltTensionRef());

}

void test_ControlState_Freeing2Ready(void)
{
	enuState = STATE_FREEING;
	i16BeltTension = 0x5555;

	/* 무반응 시험*/
	enuCommand = CMD_FREEING;
	for (int var = 0; var < (FREEING_TIME/CONTROL_STATE_PERIOD); var++) {
		ControlState();
		TEST_ASSERT_EQUAL_INT(STATE_FREEING, GetState());
	}
	/* 반응 시험*/
	ControlState();
	TEST_ASSERT_EQUAL_INT(STATE_READY, GetState());
	ControlState();
	TEST_ASSERT_EQUAL_INT16(READY_TENSION , GetBeltTensionRef());

}


void test_InitControl_Dummy(void)
{
	InitControl();
	TEST_ASSERT_EQUAL_UINT8(0, GetErrorCode());
	TEST_ASSERT_EQUAL_INT16(0, GetBeltTensionRef());
	TEST_ASSERT_EQUAL_INT(0, GetState());
}



// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_GetErrorCode_Dummy);
    RUN_TEST(test_GetBeltTensionRef_Dummy);
    RUN_TEST(test_GetState_Dummy);

    RUN_TEST(test_CheckError_Normal2Over2Normal);
    RUN_TEST(test_CheckError_Normal2Under2Normal);
    RUN_TEST(test_CheckError_Normal2UndefCmd2Normal);

    RUN_TEST(test_ControlState_Ready2BeltParking);
    RUN_TEST(test_ControlState_Ready2SlackRemoving);
    RUN_TEST(test_ControlState_Ready2Pretension);
    RUN_TEST(test_ControlState_Ready2Warning);
    RUN_TEST(test_ControlState_SlackRemoving2Freeing);
    RUN_TEST(test_ControlState_BeltParking2Freeing);
    RUN_TEST(test_ControlState_Releasing2Ready);
    RUN_TEST(test_ControlState_Pretension2Releasing);
    RUN_TEST(test_ControlState_Pretension2Freeing);
    RUN_TEST(test_ControlState_Warning2Freeing);
    RUN_TEST(test_ControlState_Freeing2Ready);

    RUN_TEST(test_InitControl_Dummy);

    return UNITY_END();
}
