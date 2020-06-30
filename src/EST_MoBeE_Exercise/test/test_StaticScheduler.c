#include "unity.h"
#include "StaticScheduler.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();

    StaticScheduler_Init();

    for (int16_t loop_cnt = 0; loop_cnt < 100; ++loop_cnt) {
    	StaticScheduler_Loop();
    	CallBack1ms();
	}


    return UNITY_END();
}
