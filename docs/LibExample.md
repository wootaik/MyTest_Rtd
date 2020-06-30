---
title: LibExample.md
author: Wootaik Lee (wootaik@gmail.com)  
date: 2020-03-01
---

# 라이브러리 예제

## 시작하는 질문

* 좋은 예를 보면서 모방하여 연습하는 것이 좋은 학습방법이라는데..... 좋은 예는 어디에 있을까?



------



## References

* NONE



**[Example Code]**

* IntMath lib: C 라이브러리 예제 
    * 모듈화를 위한 코드 템플릿에서 설명
    * `i16Abs()`, `i16Add()`,`i16AbsSat()`,  `i16AddSat()`
* UserLib : 기능 라이브러리 예제 

    * C 변수와 함수의 Scope 와 Life-time 에서 설명
    * `Hyst()`, `Ramp()`

* FltCtrl Lib

    * Demo: `fltIirFilter1()`,  `fltPiCtrlP()`,  `fltLut1D()`
    * Exercise: `fltMaFilter()`,  `fltPiCtrlR()`

**[강의 영상]**

*   [Library의 종류와 구성 방법](https://drive.google.com/file/d/1gVnXNs8KRiqGDg8t6w-JIFtPp9CJYGEU/view?usp=sharing)

## Experiment & Exercise

**[자료]**

* EST_Module_Exercise/markdown/Design_Ctrl.pdf

**[Code]**

* EST_Module_Exercise/src/
    * FltCtrl.c, .h
* EST_Module_Exercise/test/
    * test_fltIirFilter1.c
    * test_fltMaFilter.c
    * test_fltPiCtrlP.c
    * test_fltPiCtrlR.c
    * test_Lut1D.c

**[강의영상]**

* IIR Filter
    * [IIR Filter 설계](https://drive.google.com/file/d/10tPIrYRqRq-_P1twnlc2eTfAt1QJoaoc/view?usp=sharing)
    * [IIR Filter 구현](https://drive.google.com/file/d/1bZh3sAO5qEPVEt7DPI0PJd3X2SgHl8yp/view?usp=sharing)
    * [IIR Filter 시험](https://drive.google.com/file/d/1e9TmYn7BW3ZTdpmnbq_MTiwre7zCyKVK/view?usp=sharing)
* PI Controller (Parallel form)
    * [PI Controller (Parallel form) 설계](https://drive.google.com/file/d/1ze03PQcIVrx_ydV-ibdUz6FIG3P6cWnZ/view?usp=sharing)
    * [PI Controller (Parallel form) 구현](https://drive.google.com/file/d/1Ylanp82TT6PWTUoKjne5hCviVnUA-brA/view?usp=sharing)
    * [PI Controller (Parallel form) 시험](https://drive.google.com/file/d/1XA5kqUH1D6MLr3wja-AhG79FEYVIjA-v/view?usp=sharing)
* _To do 1차원 Look-up 함수 설계, 구현, 시험_

**[Exercise 설명 - 구현 실습]**

* Moving Average Filter의 설계, 시험
    * [Moving Average Filter의 설계](https://drive.google.com/file/d/1d959Pb2HUTEmRw4gG7QCuKgQQnuo0Fb0/view?usp=sharing) 
    * [Moving Average Filter의 시험](https://drive.google.com/file/d/1JLEXuN7i-pCw7uEetKfPLKL6I6VqTYv2/view?usp=sharing) 
    * [Moving Average Filter의 구현](https://drive.google.com/file/d/1rK--JKYZ5Ot1B0GDz50P2y5W1a_R6Cg7/view?usp=sharing) 
* PI Controller (Recurrent form)
    * [PI Controller (Recurrent form) 설계](https://drive.google.com/file/d/1lPDFCBqV5RFrpv1YJEXoTmmj9hkhU5hf/view?usp=sharing)
    * [PI Controller (Recurrent form) 시험](https://drive.google.com/file/d/1ONq3sQ-2LW4ln5kqlAeNJhRFz1S3v3fq/view?usp=sharing)
    * [PI Controller (Recurrent form) 구현](https://drive.google.com/file/d/1sfIzOOrPMEjW_bBUiGTA-Frg-h5QefgI/view?usp=sharing)



------



## Objectives

* 모듈화 방법의 한가지로 라이브러리를 만드는 방법을 익힌다.



## 라이브러리 ?

* 라이브러리는 소프트웨어 재사용의 가장 일반적이며 효율적인 형태
* 라이브러리 활용의 장점
    * 소프트웨어의 재사용
    * 시험 커버리지를 높일 수 있다.
    * 문서화 노력을 줄일 수 있다.
* 기능라이브러리와 C 라이브러리로 구분할 수 있다.



### C 라이브러리

**[특징]**

* 기능이 작고 간단하며 정적데이터가 필요 없는 경우

* 공통으로 여러 곳에서 사용되어진다.

* CPU/컴파일러의 특별한 특징을 은닉할 수 있다. => CPU 특징적인 기능과 구문을 추상화하여 사용

[Example] IntMath library



### 기능라이브러리

**[특징]**

* 동작이 복잡하고 크다. 그리고 여러 곳에서 사용되어진다. => 공통으로 추출함으로 ROM 사용을 줄일 수 있다.
* 표준 C 언어로만 프로그래밍 한다. 즉 PC 시스템에서도 수행할 수 있다.
* 정적인 데이터를 가질 수 있고, 이 경우 사용할 때마다 개별 인스턴스를 사용하도록 한다.

[Example] UserLib library



* 정적 데이터를 사용하는 경우 주의 사항

    * 정적인 변수는 모듈별로 선언되어지지, 함수별로 선언되지 않음
    * 복수개의 정적변수를 활용하는 함수를 설계하고자 할 경우 개별 인스턴스를 선언하여 사용
    - 함수에 인스턴스를 전달하는 매개변수를 포함하여야 함

    

## [예제] C 라이브러리: 정수 연산 IntMath 라이브러리 모듈

### Objective

* C 라이브러리의 특징을 이해하고 
* 재사용 가능한 함수들을 모아 라이브러리로 만들 수 있다.

### 필요한 지식

* 정수의 범위와 Overflow, Underflow 이해하기
* 매크로 함수를 만들고 활용하기

### 참고자료

* Design_IntMath.pdf

### Exercise

`_GivenIntMath.c` 파일을 참고해서 IntMath 라이브러리 모듈(즉 `IntMath.h`, `IntMath.c` 파일)을 만들어 본다.

* _GivenIntMath.c 의 각 함수의 동작은 모두 완벽하게 구현되어 있다. 학습용으로 참고하기 바랍니다.
* Unity를 사용해서 단위시험을 하도록 구성되어 있다. `test_IntMath.c` 파일을 참고하세요.



**[_GivenIntMath.c]** 코드의 일부

```c
#include "PlatformTypes.h"
#include <stdio.h>

#define I16Add(x, y) (int16_t) ( ((int16_t) x) + ((int16_t) y) )

int16_t I16Abs(int16_t x)
{
    return (int16_t) ((x<0) ? -(x) : (x) );
}


int16_t I16AbsSat(int16_t x)
{
    int32_t y;
    y = (int32_t) x < 0 ? -(int32_t) x : (int32_t) x;
    y = (y == -((int32_t) INT16_MIN)) ? (int32_t) INT16_MAX : y;
    return (int16_t) y;
}


int16_t I16AddSat(int16_t x, int16_t y)
{
    int32_t z;
    z = (int32_t) x + (int32_t) y;

    z = (z> (int32_t)INT16_MAX) ? (int32_t) INT16_MAX : z;
    z = (z< (int32_t)INT16_MIN) ? (int32_t) INT16_MIN : z;

    return (int16_t) z;
}

// 중간 생략 ---------------------------------------------

int main(void)
{
	// I16Abs()
	printf("I16Abs() Results\n");
	printf("I16Abs(%d) == %d\n", 32767, I16Abs(32767));
	printf("I16Abs(%d) == %d\n", -32767, I16Abs(-32767));
	printf("I16Abs(%d) == %d\n", 32768, I16Abs(32768));
	printf("I16Abs(%d) == %d\n", -32769, I16Abs(-32769));

	// I16AbsSat()
	printf("I16AbsSat() Results\n");
	printf("I16AbsSat(%d) == %d\n", 32767, I16AbsSat(32767));
	printf("I16AbsSat(%d) == %d\n", -32767, I16AbsSat(-32767));
	printf("I16AbsSat(%d) == %d\n", 32768, I16AbsSat(32768));
	printf("I16AbsSat(%d) == %d\n", -32769, I16AbsSat(-32769));

	// I16Add()
	printf("I16Add() Results\n");
	printf("I16Add(%d, %d) == %d\n", 32766, 1, I16Add(32766, 1));
	printf("I16Add(%d, %d) == %d\n", -32767, -1, I16Add(-32767, -1));
	printf("I16Add(%d, %d) == %d\n", 32766, 2, I16Add(32766, 2));
	printf("I16Add(%d, %d) == %d\n", -32767, -2, I16Add(-32767, -2));

	// I16AddSat()
	printf("I16AddSat() Results\n");
	printf("I16AddSat(%d, %d) == %d\n", 32766, 1, I16AddSat(32766, 1));
	printf("I16AddSat(%d, %d) == %d\n", -32767, -1, I16AddSat(-32767, -1));
	printf("I16AddSat(%d, %d) == %d\n", 32766, 2, I16AddSat(32766, 2));
	printf("I16AddSat(%d, %d) == %d\n", -32767, -2, I16AddSat(-32767, -2));

	return(0);
}

// 이하 생략 -----------------------------------------------------
```





## [예제] 기능라이브러리: UserLib 라이브러리 모듈

### Objective

* 기능 라이브러리의 특징을 이해하고 
* 재사용 가능한 함수들을 모아 라이브러리로 만들 수 있다.

### 필요한 지식

* 상태기계로 표현하고 구현하기
* 설정 정보와 상태 정보를 추출하고 구분

### 참고자료

* Design_UserLib.pdf

### Exercise

`_GivenHysteresis.c` , `_GivenRamp.c` 파일을 참고해서 UserLib 모듈(즉 `UserLib.h`, `UserLib.c` 파일)을 만들어 본다.

* `Hysteresis()`, `Ramp()`  함수의 동작은 모두 완벽하게 구현되어 있다. 학습용으로 참고하기 바랍니다.
* Design_UserLib.pdf 파일의 정보를 참고하여 
    * 함수의 Prototype과 구조체 변수의 구성을 확인하세요.
* Unity를 사용해서 단위시험을 하도록 구성되어 있다. `test_UserLib.c` 파일을 참고하세요.
    * UserLib.h 를 인클루드하고
    * 시험에 필요한 자료형을 선언하고 있습니다.
    * 전형적인 라이브러리 함수의 활용예입니다.
* 상태기계로 구현된 Ramp함수의 예가 `RampStateMachine()`에 있습니다. 학습에 활용하도록 하세요.



**[_GivenHysteresis.c]**

```c
#include "PlatformTypes.h"
#include <stdio.h>


float_t Hysteresis(float_t fltIn){
    float_t   fltUpperThreshold = 1.0;
    float_t   fltLowerThreshold = -1.0;
    float_t   fltUpperOutput = 5.0;
    float_t   fltLowerOutput= -5.0;
    static float_t   fltHystState = 0.0;
    float_t  flt_temp;

    flt_temp = (fltIn < fltUpperThreshold) ? fltHystState : fltUpperOutput ;

    fltHystState = (fltIn <= fltLowerThreshold) ? fltLowerOutput : flt_temp ;

    return(fltHystState);
}
int main(void)
{
	float_t out[10] = {0.0} ;
	float_t in[10] = { 0.0, 2.0, 3.0, 0.0, -0.5, -1.0, -1.1, 0.5, 1.1, 2.0};

	for (int var = 0; var < 10; ++var) {
		out[var] = Hysteresis(in[var]);
		printf(" in = %4.2f ===> out = %4.2f\n", in[var], out[var]);
	}

    return(0);
}

```



**[_GivenRamp.c]**

```c
#include <stdio.h>
#include <stdlib.h>
#include "PlatformTypes.h"

float_t Ramp(float_t fltIn)
{

	static float_t   fltState = 0.0;
	float_t   fltIncrement = 1.0;
	float_t   fltDecrement = -1.0;

	float_t  flt_temp;
    float_t  flt_temp_inc;
    float_t  flt_temp_dec;

    flt_temp_inc = fltState + fltIncrement;
    flt_temp_dec = fltState + fltDecrement;

    flt_temp = (fltState <= fltIn) ? flt_temp_inc : flt_temp_dec;

    fltState = ((flt_temp_inc >= fltIn) && (flt_temp_dec <= fltIn))  ?
                            fltIn : flt_temp;
    return(fltState);

}

int main(void)
{
	float_t in[10] = {3.0, 3.0, 3.0, 3.5, 3.5, -1.0, -1.0, -1.0, -0.5, -1.0};
	float_t out[10] = {0.0} ;

	for (int var = 0; var < 10; ++var) {
		out[var] = Ramp(in[var]);
//		out[var] = RampStateMachine(in[var]);
		printf(" in = %4.2f ===> out = %4.2f\n", in[var], out[var]);
	}
    return(0);
}

```

**[_GivenRamp.c RampStateMachine()]** 상태기계로 구현한 Ramp 함수 _(참고용)_

```c
float_t RampStateMachine(float_t fltIn)
{

	typedef enum {
		STEADY = 0,
		INCREASING,
		DECREASING
	} RampState_t;


	float_t   fltIncrement = 1.0;
	float_t   fltDecrement = -1.0;
	static float_t	  fltOut = 0.0;
	static RampState_t enuRampState = STEADY;

	float_t flt_temp_inc = fltOut + fltIncrement;
	float_t flt_temp_dec = fltOut + fltDecrement;

	switch (enuRampState) {
		case STEADY:
			if(fltIn > flt_temp_inc){
				enuRampState = INCREASING;
				fltOut = flt_temp_inc;
			}else if(fltIn < flt_temp_dec){
				enuRampState = DECREASING;
				fltOut = flt_temp_dec;
			}else{
				fltOut = fltIn;
			}

			break;
		case INCREASING:
			if(fltIn < flt_temp_inc){
				enuRampState = STEADY;
				fltOut = fltIn;
			}else{
				fltOut = flt_temp_inc;
			}
			break;
		case DECREASING:
			if(fltIn > flt_temp_dec){
				enuRampState = STEADY;
				fltOut = fltIn;
			}else{
				fltOut = flt_temp_dec;
			}
			break;
		default:
			break;
	}

	return(fltOut);
}
```







## [예제] 기능라이브러리: FltCtrl 라이브러리 모듈

### Objective

* 제어와 신호처리에 필요한 함수들을 라이브러리로 만들 수 있다.

### 필요한 지식

* PID 제어 
* IIR Filter

### 참고자료

* Design_Ctrl.pdf

### Exercise

`FltCtrl.h` `FltCtrl.c` 파일을 완성해 보자

* `fltIirFilter1()`의 내용을 참고해서 `fltMaFilter()`를 완성
    * `test_FltCtrl_fltIirFilter1.c`와 `test_FltCtrl_fltMaFilter.c` 참고

* `fltPiCtrlP()`의 내용을 참고해서 `fltPiCtrlR()`를 완성
    * `test_FltCtrl_fltPiCtrlP.c`와 `test_FltCtrl_fltPiCtrlR.c` 참고
* `fltLut1D()` 학습
    * `test_FltCtrl_fltLut1D.c` 참고





