---
title: ReadMe
author: 이우택 (wootaik@changwon.ac.kr)  
date: 2020 04 01
---

## Architecture 설계와 Module 개발 방법 



## Prerequisite

이 강좌는 C 언어에 대한 기본적인 이해와 활용 능력을 전제로 하고 있습니다.



기본 환경으로 Eclipse 와 MinGW를 사용하고 있습니다.

환경 설치와 관련해서는 다음의 링크를 참고하여 환경을 준비하여 주시기 바랍니다.

* [MinGW, Eclipse 의 설치와 활용](https://drive.google.com/open?id=1FkhYFFAEmGat5U7Kgm_GGp6buNXcvpAE)

    [강의 영상]

    *   [MngGW와 Eclipse 설치 및 확인](https://drive.google.com/file/d/14SHD8eoIiCZvUsSrb5ktnx6DXgHRYQKM/preview)
    * [Build, Debug & Execute in eclipse](https://drive.google.com/file/d/1_m_x13QxEMPcEFXvXC1crUasRlZ_fiPA/preview)



임베디드 프로그래밍을 할 때에 포인터와 구조체의 이해는 매우 중요합니다. 기초가 부족하다고 생각되시는 분은 다음의 강좌로 이해도를 높이시기 바랍니다.

* [Pointer Explained](https://drive.google.com/open?id=1cKt-nrCICur0RolgPjs3Vnoqht87TLCC)

    [강의 영상]

    *   [포인터 설명과 실습](https://drive.google.com/file/d/1SD4caT_NLkwG2wqNwux-GBdDW4dwzni2/preview)


* [Structure Explained](https://drive.google.com/open?id=1oL-zrpJo9GTqf-EiNhd8paEi6IkrKi-v)

    [강의 영상]

    *   [Structure Basics](https://drive.google.com/file/d/18W6ENEpPz5X-rA4iCAkLgZIH6goEMcFg/preview)
    *   [Coordinate Conversion Example](https://drive.google.com/file/d/18B8Skja7U-RaXfz3F6xayb7oO0HLz983/preview)
    *   [eclipse 에서 실습하기](https://drive.google.com/file/d/1BXBUFGQ6lefWss_g_PxaST56gI6CcHuk/preview)
    *   [Multiple file 로 프로그래밍하기](https://drive.google.com/file/d/1Rbf-45qO6XynkK2U5VySJ1r9r4-wuqzO/preview)



------



## ToC



### **Part I** 모듈화 설계 및 구현 방법

**[Example Project]**

* [EST_Module_Exercise.zip](https://drive.google.com/open?id=1lqG-vVjvRZo1ia-wUIrsnUuGds661ot6)

    

* [객체지향 프로그래밍: 모듈화 프로그래밍이란?](./ModularProgramming.md)

    **[강의 영상]**

    * [객체지향 프로그래밍이란?](https://drive.google.com/file/d/1WJAGiKlqxzWe2TsnW8NSQY8y_lNfE7ik/preview)

    * [모듈화 설계 방법](https://drive.google.com/file/d/1OR9xyQEB8eNbtNHmGtTy9i8KALeAXLLf/preview)



* [모듈화를 위한 코드 템플릿](./ModuleCodeTemplate.md)

    **[강의 영상]**

    * [모듈화 구현 방법과 코드 템플릿](https://drive.google.com/file/d/11rVY1j5vhZt9zHR8E1VLFXA4SAGprZQY/preview)
    * [모듈 만들기 Exercise 설명](https://drive.google.com/file/d/1QYOnF08XWJvdkABWVE9Sf0g4pirsXp8O/preview)

    **[실습 영상]**

    * [Integer 연산 관련 예제 설명](https://drive.google.com/file/d/1e6H5nBCv2Hr_9nlxSbGhaSilG7oD3L3M/preview)
    * [Integer 연산 라이브러리 모듈 만들기](https://drive.google.com/file/d/1Gdlr70y65__ydx5UpZb2CCx_o_fc99rI/preview)

    

* [헤더파일의 인클루드 구조](./Includes.md)

	**[강의 영상]**

    * [Include 구조 설계 방법](https://drive.google.com/open?id=1-domEgxfBXBaHZnovtcVfTGlC3kO2-Jg)
    * [include 구조: MinGW32 C99  활용시](https://drive.google.com/open?id=1gE4JBr8AJUy6y6WT4skKjXE3aX6dkyXQ)

    

* [C 변수와 함수의 scope 와 life-time](ScopeLifeTime.md)

    **[강의 영상]**

    * [변수와 함수의 Scope와 Life-time](https://drive.google.com/open?id=1Y-L_W4hO0vLT9yQR3Q05qlEDkmSkV19g)

    * [변수와 관련된 좀 더 깊이있는 이야기](https://drive.google.com/open?id=171N17Bor3TZMEzyfJSEumDBqrUyH-oXL)

    **[실습 영상]**

    * [Unity 간략 설명](https://drive.google.com/file/d/11w7y53zlyKFL466XA88T4Xuesxvpwp14/preview) 
    * [Hystersis 함수 설명과 모듈화 하기](https://drive.google.com/file/d/1nBxdQqpYLkiaClMd5ebEZ0ipYS9XPibe/preview)
    * [Ramp 함수 설명과 모듈화 하기](https://drive.google.com/file/d/1BAkADshPkg4o5BVYhVW0te5E7m1qa3Pk/preview)

    


* [라이브러리 예제](LibExample.md)

    **[강의 영상]**

    *   [Library의 종류와 구성 방법](https://drive.google.com/file/d/1gVnXNs8KRiqGDg8t6w-JIFtPp9CJYGEU/view?usp=sharing)
    
    **[실습 영상]**
    
    * IIR Filter
        * [IIR Filter 설계](https://drive.google.com/file/d/10tPIrYRqRq-_P1twnlc2eTfAt1QJoaoc/view?usp=sharing)
        * [IIR Filter 구현](https://drive.google.com/file/d/1bZh3sAO5qEPVEt7DPI0PJd3X2SgHl8yp/view?usp=sharing)
        * [IIR Filter 시험](https://drive.google.com/file/d/1e9TmYn7BW3ZTdpmnbq_MTiwre7zCyKVK/view?usp=sharing)
	* PI Controller (Parallel form)
        * [PI Controller (Parallel form) 설계](https://drive.google.com/file/d/1ze03PQcIVrx_ydV-ibdUz6FIG3P6cWnZ/view?usp=sharing)
        * [PI Controller (Parallel form) 구현](https://drive.google.com/file/d/1Ylanp82TT6PWTUoKjne5hCviVnUA-brA/view?usp=sharing)
        * [PI Controller (Parallel form) 시험](https://drive.google.com/file/d/1XA5kqUH1D6MLr3wja-AhG79FEYVIjA-v/view?usp=sharing)
    * _To do 1차원 Look-up 함수 설계, 구현, 시험_
    
    **[연습 영상]**
    
    * Moving Average Filter의 설계, 시험
        * [Moving Average Filter의 설계](https://drive.google.com/file/d/1d959Pb2HUTEmRw4gG7QCuKgQQnuo0Fb0/view?usp=sharing) 
        * [Moving Average Filter의 시험](https://drive.google.com/file/d/1JLEXuN7i-pCw7uEetKfPLKL6I6VqTYv2/view?usp=sharing) 
        * [Moving Average Filter의 구현](https://drive.google.com/file/d/1rK--JKYZ5Ot1B0GDz50P2y5W1a_R6Cg7/view?usp=sharing) 
    * PI Controller (Recurrent form)
        * [PI Controller (Recurrent form) 설계](https://drive.google.com/file/d/1lPDFCBqV5RFrpv1YJEXoTmmj9hkhU5hf/view?usp=sharing)
        * [PI Controller (Recurrent form) 시험](https://drive.google.com/file/d/1ONq3sQ-2LW4ln5kqlAeNJhRFz1S3v3fq/view?usp=sharing)
        * [PI Controller (Recurrent form) 구현](https://drive.google.com/file/d/1sfIzOOrPMEjW_bBUiGTA-Frg-h5QefgI/view?usp=sharing)
    
    
    

### PART II Embedded Control System을 위한 SW Architecture 설계

**[Example Project]**

* [EST_MoBeE_Excercise.zip](https://drive.google.com/file/d/1lqG-vVjvRZo1ia-wUIrsnUuGds661ot6/view?usp=sharing)



* [소프트웨어 구조와 프래임워크](./ArchFramework.md)  - 상위설계
  
    **[강의 영상]**
    
    * [SW 구조로 얻을 수 있는 장점](https://drive.google.com/file/d/16YGYYwft4EZqYiwkK8qQ4c6kd0SyQ_VS/view?usp=sharing)
    * [하드웨어 추상화 계층과 운영체계 추상화 계층](https://drive.google.com/file/d/1hl8litHF3RJydke84yXvOuQRacX2Gqlv/view?usp=sharing)
    * [물리계층, 실행 프래임워크, 그리고 라이브러리](https://drive.google.com/file/d/1KMc9GU6T__c0KBvnHtZf-5BgIdjTnwT8/view?usp=sharing)
    
    **[실습 영상]**
    
    * [요구사항 정리](https://drive.google.com/file/d/1W8jICtiDo7aHKQMBWXFh4SWfrkXKnaKb/view?usp=sharing) (Optional)
    * [시스템 요구사항 명세화](https://drive.google.com/file/d/1nIabKiyQcJyHFxzXwLu0v2TCQ1c568Bm/view?usp=sharing) (Optional)
    * [소프트웨어 상위 레벨 설계](https://drive.google.com/file/d/1zn5YwPK3NtXopJgbsLcntMGEYePr1zJp/view?usp=sharing)
    * [소프트웨어 상위레벨 설계에 따른 파일 관리](https://drive.google.com/file/d/1cIMAFbdryAcBhyWxMcE25PqJjqTNFruh/view?usp=sharing)
    * [SensorSWC 구조 구현](https://drive.google.com/file/d/1GbUsAzfDfclbmBjXYV9R_iBT0SZR93Zy/view?usp=sharing)
    * [ApplicationSWC 와 ActuatorSWC 구조 분석](https://drive.google.com/file/d/1h5ZXgE6YqYwHa2Ez2xnHFSWZSa9O7Cby/view?usp=sharing)



* [마이크로컨트롤러용 소프트웨어의 구조적 특징](uControllerFeatures.md) - 하위설계, HAL과의 연결
  
    **[강의 영상]**
    
    * [Microcontroller의 구조](https://drive.google.com/file/d/1D1VFABJH4zWb031hw-VDt5dw-gjW92uR/view?usp=sharing)
    * [외부 사건 처리 방법](https://drive.google.com/file/d/1x7fhCXcEFfXJKDLNpNPsPjsXrvMKH1xl/view?usp=sharing)
    
    **[실습 영상]**
    
    * [단위 시험을 위한 환경 구축 방법, Mock-Up](https://drive.google.com/file/d/10gO9lK0jw1aAgqJw7ju03JiklemCVP72/view?usp=sharing)
* [SensorSWC - MeasureBeltTension 코드 분석](https://drive.google.com/file/d/1TG-dEI4hs295DwqyH2d9HCwKuL7tGVla/view?usp=sharing)
  
  **[연습 영상]**
  
  * [SensorSWC, ActuatorSWC 기능 구현](https://drive.google.com/file/d/1Xv3SXLclULKAxrZFZQZeoZzU7Iec1QxF/view?usp=sharing)
  
  
  
* [동작과 자료, 그리고 트리거](BehaviorDataTrigger.md) - 하위설계, App 설계
  
    **[강의 영상]**
    
    * [동작과 데이타, 그리고 객체](https://drive.google.com/file/d/14gFxS0aSWmVONhztlyz6i_wZp4oXDOPm/view?usp=sharing)
    * [함수 호출과 Trigger](https://drive.google.com/file/d/136bfiHLitqsFWcfTevOgf5w3nH1wceDj/view?usp=sharing)
    * [예제 구조의 설명](https://drive.google.com/file/d/1UB_1T2RAbZmQppbTW-moeRvr3H53u-_Y/view?usp=sharing)
    
    **[실습 영상]**
    
    * [ApplicationSWC - CheckError() 코드 분석](https://drive.google.com/file/d/1SMjbWbwfOgLRU_9zAPUJWQNW1crwuw8l/view?usp=sharing)
    
    **[연습영상]**
    
    * [ApplicationSWC - ControlState() 기능 구현](https://drive.google.com/file/d/1RjPTgTF0p1qORD9A3TpgLJGT3wFTv9tU/view?usp=sharing)
    
    


* [운영체계와 스케쥴링](StaticSche.md) - OS Integration
  
    **[강의 영상]**
    
    * [Task와 Scheduler](https://drive.google.com/file/d/1Um0yAoTekPtPTO52jJGZB3hv0qRuKHF4/view?usp=sharing) (in XMC Tutorial)
    * [Interrupt와 Scheduler](https://drive.google.com/file/d/1kV4IVsf8exh7cg4LM5M9tuRNK6El1AcS/view?usp=sharing) (in XMC Tutorial)
    * [Static Cyclic Scheduler](https://drive.google.com/file/d/1_O12IdvWccj77IUbqQTeJ8hzNS_9RYZb/view?usp=sharing) (in XMC Tutorial)
    * [Scheduler의 종류](https://drive.google.com/file/d/1S1Xegr5t-4RDMNKtxcPJABejRFy2HMha/view?usp=sharing)
    * [자료의 공유시 발생하는 문제들](https://drive.google.com/file/d/1cUXXhU1qqHe1qoDGYlkt85rhDuEYktRr/view?usp=sharing)
    
    **[실습 영상]**
    
    * [Static Cyclic Scheduler in PC](https://drive.google.com/file/d/1VpzXCs1oLRT8HLWzDq0wp6b2N8x8cOAa/view?usp=sharing)
    * [실시간 설계와 구현](https://drive.google.com/file/d/1e3UP8xnKlQLtfmoxvE8S_VcDxsnzWFaI/view?usp=sharing)



