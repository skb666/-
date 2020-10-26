/*!
  * @file     lq_timer.h
  *
  * @brief    ��ʱ�� �����ļ�
  *
  * @company  �����������ܿƼ�
  *
  * @author   LQ-005
  *
  * @note     ��
  *
  * @version  V1.0
  *
  * @par URL  http://shop36265907.taobao.com
  *           http://www.lqist.cn
  *
  * @email    chiusir@163.com
  *
  * @date     2020��3��20��
  */
#ifndef __LQ_TIMER_H
#define __LQ_TIMER_H

#include "stc8.h"

/* ��TIMER0 ����ʱ��ʱ ���ʱ��Ƭ���� */
extern volatile uint32_t xdata s_timerCounter;


/*========================================================================================*/
/*========================================================================================*/
/*===========================Timer�ײ����� �û��������===================================*/
/*========================================================================================*/
/*========================================================================================*/

//====================================
#define		Timer0_16bitAutoReload()	TMOD &= ~0x03					/* 16λ�Զ���װ	*/
#define		Timer0_16bit()				TMOD  = (TMOD & ~0x03) | 0x01	/* 16λ         */
#define		Timer0_8bitAutoReload()		TMOD  = (TMOD & ~0x03) | 0x02	/* 8λ�Զ���װ	*/
#define		Timer0_16bitAutoRL_NoMask()	TMOD |=  0x03		/* 16λ�Զ���װ���������ж�	*/
#define 	Timer0_Run()	 			TR0 = 1				/* ����ʱ��0����			*/
#define 	Timer0_Stop()	 			TR0 = 0				/* ��ֹ��ʱ��0����			*/
#define		Timer0_Gate_INT0_P32()		TMOD |=  (1<<3)		/* ʱ��0���ⲿINT0�ߵ�ƽ����ʱ���� */
#define		Timer0_AsTimer()			TMOD &= ~(1<<2)		/* ʱ��0������ʱ��	*/
#define		Timer0_AsCounter()			TMOD |=  (1<<2)		/* ʱ��0����������	*/
#define		Timer0_AsCounterP34()		TMOD |=  (1<<2)		/* ʱ��0����������	*/
#define 	Timer0_1T()					AUXR |=  (1<<7)		/* Timer0 clodk = fo	*/
#define 	Timer0_12T()				AUXR &= ~(1<<7)		/* Timer0 clodk = fo/12	12��Ƶ,	default	*/
#define		Timer0_CLKO_Enable()		INT_CLKO |=  1	    /* ���� T0 ���������T0(P3.5)�������Fck0 = 1/2 T0 ����ʣ�T0����1T��12T��	*/
#define		Timer0_CLKO_Disable()		INT_CLKO &= ~1
#define		Timer0_CLKO_Enable_P34()	INT_CLKO |=  1		/* ���� T0 ���������T0(P3.5)�������Fck0 = 1/2 T0 ����ʣ�T0����1T��12T��	*/
#define		Timer0_CLKO_Disable_P34()	INT_CLKO &= ~1
#define 	Timer0_InterruptEnable()	ET0 = 1				/* ����Timer1�ж�.*/
#define 	Timer0_InterruptDisable()	ET0 = 0				/* ��ֹTimer1�ж�.*/

#define		T0_Load(n)					TH0 = (n) / 256,	TL0 = (n) % 256
#define		T0_Load_us_1T(n)			Timer0_AsTimer(),Timer0_1T(), Timer0_16bitAutoReload(),TH0=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL0=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T0_Load_us_12T(n)			Timer0_AsTimer(),Timer0_12T(),Timer0_16bitAutoReload(),TH0=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL0=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T0_Frequency_1T_P35(n)		ET0=0,Timer0_AsTimer(),Timer0_1T(),Timer0_16bitAutoReload(),TH0=(65536-(n/2+MAIN_Fosc/2)/(n))/256,TL0=(65536-(n/2+MAIN_Fosc/2)/(n))%256,INT_CLKO |= bit0,TR0=1		/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T0_Frequency_12T_P35(n)		ET0=0,Timer0_AsTimer(),Timer0_12T(),Timer0_16bitAutoReload(),TH0=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL0=(65536-(n/2+MAIN_Fosc/24)/(n))%256,INT_CLKO |= bit0,TR0=1	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define		Timer1_16bitAutoReload()	TMOD &= ~0x30					/* 16λ�Զ���װ	*/
#define		Timer1_16bit()				TMOD  = (TMOD & ~0x30) | 0x10	/* 16λ			*/
#define		Timer1_8bitAutoReload()		TMOD  = (TMOD & ~0x30) | 0x20	/* 8λ�Զ���װ	*/
#define 	Timer1_Run()	 			TR1 = 1				/* ����ʱ��1����			*/
#define 	Timer1_Stop()	 			TR1 = 0				/* ��ֹ��ʱ��1����			*/
#define		Timer1_Gate_INT1_P33()		TMOD |=  (1<<7)		/* ʱ��1���ⲿINT1�ߵ�ƽ����ʱ����	*/
#define		Timer1_AsTimer()			TMOD &= ~(1<<6)		/* ʱ��1������ʱ��			*/
#define		Timer1_AsCounter()			TMOD |=  (1<<6)		/* ʱ��1����������			*/
#define		Timer1_AsCounterP35()		TMOD |=  (1<<6)		/* ʱ��1����������			*/
#define 	Timer1_1T()					AUXR |=  (1<<6)		/* Timer1 clodk = fo		*/
#define 	Timer1_12T()				AUXR &= ~(1<<6)		/* Timer1 clodk = fo/12	12��Ƶ,	default	*/
#define		Timer1_CLKO_Enable()		INT_CLKO |=  2			/* ���� T1 ���������T1(P3.4)�������Fck1 = 1/2 T1 ����ʣ�T1����1T��12T��	*/
#define		Timer1_CLKO_Disable()		INT_CLKO &= ~2
#define		Timer1_CLKO_Enable_P35()	INT_CLKO |=  2			/* ���� T1 ���������T1(P3.4)�������Fck1 = 1/2 T1 ����ʣ�T1����1T��12T��	*/
#define		Timer1_CLKO_Disable_P35()	INT_CLKO &= ~2
#define 	Timer1_InterruptEnable()	ET1 = 1				/* ����Timer1�ж�.	*/
#define 	Timer1_InterruptDisable()	ET1 = 0				/* ��ֹTimer1�ж�.	*/

#define		T1_Load(n)					TH1 = (n) / 256,	TL1 = (n) % 256
#define		T1_Load_us_1T(n)			Timer1_AsTimer(),Timer1_1T(), Timer1_16bitAutoReload(),TH1=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL1=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T1_Load_us_12T(n)			Timer1_AsTimer(),Timer1_12T(),Timer1_16bitAutoReload(),TH1=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL1=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T1_Frequency_1T_P34(n)		ET1=0,Timer1_AsTimer(),Timer1_1T(),Timer1_16bitAutoReload(),TH1=(65536-(n/2+MAIN_Fosc/2)/(n))/256,TL1=(65536-(n/2+MAIN_Fosc/2)/(n))%256,INT_CLKO |= bit1,TR1=1		/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T1_Frequency_12T_P34(n)		ET1=0,Timer1_AsTimer(),Timer1_12T(),Timer1_16bitAutoReload(),TH1=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL1=(65536-(n/2+MAIN_Fosc/24)/(n))%256,INT_CLKO |= bit1,TR1=1	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define 	Timer2_Run()	 			AUXR |=  (1<<4)	/* ����ʱ��2����	*/
#define 	Timer2_Stop()	 			AUXR &= ~(1<<4)	/* ��ֹ��ʱ��2����	*/
#define		Timer2_AsTimer()			AUXR &= ~(1<<3)	/* ʱ��2������ʱ��	*/
#define		Timer2_AsCounter()			AUXR |=  (1<<3)	/* ʱ��2����������	P1.2Ϊ�ⲿ���� */
#define		Timer2_AsCounterP12()		AUXR |=  (1<<3)	/* ʱ��2����������	P1.2Ϊ�ⲿ���� */
#define 	Timer2_1T()					AUXR |=  (1<<2)	/* Timer0 clock = fo	*/
#define 	Timer2_12T()				AUXR &= ~(1<<2)	/* Timer0 clock = fo/12	12��Ƶ,	default	*/
#define		Timer2_CLKO_Enable()		INT_CLKO |=  4		/* ���� T2 ���������T1(P3.0)�������Fck2 = 1/2 T2 ����ʣ�T2����1T��12T��	*/
#define		Timer2_CLKO_Disable()		INT_CLKO &= ~4
#define		Timer2_CLKO_Enable_P30()	INT_CLKO |=  4		/* ���� T2 ���������T1(P3.0)�������Fck2 = 1/2 T2 ����ʣ�T2����1T��12T��	*/
#define		Timer2_CLKO_Disable_P30()	INT_CLKO &= ~4
#define 	Timer2_InterruptEnable()	IE2  |=  (1<<2)	/* ����Timer2�ж�.	*/
#define 	Timer2_InterruptDisable()	IE2  &= ~(1<<2)	/* ��ֹTimer2�ж�.	*/

#define		T2_Load(n)					TH2 = (n) / 256,	TL2 = (n) % 256
#define		T2_Load_us_1T(n)			Timer2_AsTimer(),Timer2_1T(), TH2=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL2=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T2_Load_us_12T(n)			Timer2_AsTimer(),Timer2_12T(),TH2=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL2=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T2_Frequency_1T_P30(n)		Timer2_InterruptDisable(),Timer2_AsTimer(),Timer2_1T(), TH2=(65536-(n/2+MAIN_Fosc/2)/(n))/256, TL2=(65536-(n/2+MAIN_Fosc/2)/(n))%256, Timer2_CLKO_Enable_P30(),Timer2_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T2_Frequency_12T_P30(n)		Timer2_InterruptDisable(),Timer2_AsTimer(),Timer2_12T(),TH2=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL2=(65536-(n/2+MAIN_Fosc/24)/(n))%256,Timer2_CLKO_Enable_P30(),Timer2_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define 	Timer3_Run()	 			T4T3M |=  (1<<3)	/* ����ʱ��3����	*/
#define 	Timer3_Stop()	 			T4T3M &= ~(1<<3)	/* ��ֹ��ʱ��3����	*/
#define		Timer3_AsTimer()			T4T3M &= ~(1<<2)	/* ʱ��3������ʱ��	*/
#define		Timer3_AsCounter()			T4T3M |=  (1<<2)	/* ʱ��3����������, P0.4Ϊ�ⲿ����	*/
#define		Timer3_AsCounterP04()		T4T3M |=  (1<<2)	/* ʱ��3����������, P0.4Ϊ�ⲿ����	*/
#define 	Timer3_1T()					T4T3M |=  (1<<1)	/* 1Tģʽ	*/
#define 	Timer3_12T()				T4T3M &= ~(1<<1)	/* 12Tģʽ,	default	*/
#define		Timer3_CLKO_Enable()		T4T3M |=  1			/* ����T3���������T3(P0.5)�������Fck = 1/2 T2 ����ʣ�T2����1T��12T��	*/
#define		Timer3_CLKO_Disable()		T4T3M &= ~1			/* ��ֹT3���������T3(P0.5)�����	*/
#define		Timer3_CLKO_Enable_P05()	T4T3M |=  1			/* ����T3���������T3(P0.5)�������Fck = 1/2 T2 ����ʣ�T2����1T��12T��	*/
#define		Timer3_CLKO_Disable_P05()	T4T3M &= ~1			/* ��ֹT3���������T3(P0.5)�����	*/
#define 	Timer3_InterruptEnable()	IE2  |=  (1<<5)		/* ����Timer3�ж�.	*/
#define 	Timer3_InterruptDisable()	IE2  &= ~(1<<5)		/* ��ֹTimer3�ж�.	*/

#define		T3_Load(n)					TH3 = (n) / 256,	TL3 = (n) % 256
#define		T3_Load_us_1T(n)			Timer3_AsTimer(),Timer3_1T(), TH3=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL3=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T3_Load_us_12T(n)			Timer3_AsTimer(),Timer3_12T(),TH3=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL3=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T3_Frequency_1T_P04(n)		Timer3_InterruptDisable(),Timer3_AsTimer(),Timer3_1T(), TH3=(65536-(n/2+MAIN_Fosc/2)/(n))/256, TL3=(65536-(n/2+MAIN_Fosc/2)/(n))%256, Timer3_CLKO_P04_Enable,Timer3_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T3_Frequency_12T_P04(n)		Timer3_InterruptDisable(),Timer3_AsTimer(),Timer3_12T(),TH3=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL3=(65536-(n/2+MAIN_Fosc/24)/(n))%256,Timer3_CLKO_P04_Enable,Timer3_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define 	Timer4_Run()	 			T4T3M |=  (1<<7)	/* ����ʱ��4����	*/
#define 	Timer4_Stop()	 			T4T3M &= ~(1<<7)	/* ��ֹ��ʱ��4����	*/
#define		Timer4_AsTimer()			T4T3M &= ~(1<<6)	/* ʱ��4������ʱ��  */
#define		Timer4_AsCounter()			T4T3M |=  (1<<6)	/* ʱ��4����������, P0.6Ϊ�ⲿ����	*/
#define		Timer4_AsCounterP06()		T4T3M |=  (1<<6)	/* ʱ��4����������, P0.6Ϊ�ⲿ����	*/
#define 	Timer4_1T()					T4T3M |=  (1<<5)	/* 1Tģʽ	*/
#define 	Timer4_12T()				T4T3M &= ~(1<<5)	/* 12Tģʽ,	default	*/
#define		Timer4_CLKO_Enable()		T4T3M |=  (1<<4)	/* ����T4���������T4(P0.7)�������Fck = 1/2 T2 ����ʣ�T2����1T��12T��	*/
#define		Timer4_CLKO_Disable()		T4T3M &= ~(1<<4)	/* ��ֹT4���������T4(P0.7)�����	*/
#define		Timer4_CLKO_Enable_P07()	T4T3M |=  (1<<4)	/* ����T4���������T4(P0.7)�������Fck = 1/2 T2 ����ʣ�T2����1T��12T��	*/
#define		Timer4_CLKO_Disable_P07()	T4T3M &= ~(1<<4)	/* ��ֹT4���������T4(P0.7)�����	*/
#define 	Timer4_InterruptEnable()	IE2  |=  (1<<6)		/* ����Timer4�ж�.	*/
#define 	Timer4_InterruptDisable()	IE2  &= ~(1<<6)		/* ��ֹTimer4�ж�.	*/

#define		T4_Load(n)					TH4 = (n) / 256,	TL4 = (n) % 256
#define		T4_Load_us_1T(n)			Timer4_AsTimer(),Timer4_1T(), TH4=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL4=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T4_Load_us_12T(n)			Timer4_AsTimer(),Timer4_12T(),TH4=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL4=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T4_Frequency_1T_P06(n)		Timer4_InterruptDisable(),Timer4_AsTimer(),Timer4_1T(), TH4=(65536-(n/2+MAIN_Fosc/2)/(n))/256, TL4=(65536-(n/2+MAIN_Fosc/2)/(n))%256, Timer4_CLKO_P06_Enable(),Timer4_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T4_Frequency_12T_P06(n)		Timer4_InterruptDisable(),Timer4_AsTimer(),Timer4_12T(),TH4=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL4=(65536-(n/2+MAIN_Fosc/24)/(n))%256,Timer4_CLKO_P06_Enable(),Timer4_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
//====================================================================================================================



/*========================================================================================*/
/*========================================================================================*/
/*=====================================Timer �û� API ====================================*/
/*========================================================================================*/
/*========================================================================================*/

/*
	STC8��5����ʱ��  �����API���������� ��ʼ����ʱ�������ж� 


	TIMER�жϳ�ʼ����Ҫ
	1. �����ж����ȼ�(�����ж����ȼ� n��Χ�� 0-3  3���ȼ���ߣ����������Ĭ�����ȼ�0) 
	        SET_TIMER0_PRIORITY(2);    //����TIMER0 �ж����ȼ�			 
	
	2. �����ж�
			TIMER0_Init(10000);        //����TIMER0 10000us �ж�һ��
	
	3. ��д�жϷ�������T2 T3 T4 ��Ҫ���жϷ�����������жϱ�־λ��(�жϷ�����Ĭ��д��irq.c��)
			void TIMER0Tnterrupt()   interrupt    1
			{
				
			}
			
*/

/* us���ʱʱ�䣺65535/(ϵͳʱ��(MAIN_Fosc)/12)  ��ϵͳʱ��24Mhzʱ ���ʱʱ�䣺32767us */
#define     TIMER0_Init(us)             T0_Load_us_12T(us), Timer0_Run(), Timer0_InterruptEnable()
#define     TIMER1_Init(us)             T1_Load_us_12T(us), Timer1_Run(), Timer1_InterruptEnable()
#define     TIMER2_Init(us)             T2_Load_us_12T(us), Timer2_Run(), Timer2_InterruptEnable()
#define     TIMER3_Init(us)             T3_Load_us_12T(us), Timer3_Run(), Timer3_InterruptEnable()
#define     TIMER4_Init(us)             T4_Load_us_12T(us), Timer4_Run(), Timer4_InterruptEnable()
#define     Timer_Init(n, us)           TIMER##n##_Init(us)
/**
 * ��ʼ����ʱ�� �����жϹ���
 * n : ��ʱ��N
 * us: ��ʱʱ��  
 */
#define     TIMER_Init(n, us)           Timer_Init(n, us)


#define	    T4IF	0x04
#define	    T3IF	0x02
#define	    T2IF	0x01

/** ����жϱ�־λ T0 T1�����ֶ���� */
#define     TIMER0_Clear()
#define     TIMER1_Clear()
#define     TIMER2_Clear()              AUXINTIF &= ~T2IF		/* ����жϱ�־λ ���ֶ���� */
#define     TIMER3_Clear()              AUXINTIF &= ~T3IF		/* ����жϱ�־λ ���ֶ���� */
#define     TIMER4_Clear()              AUXINTIF &= ~T4IF		/* ����жϱ�־λ ���ֶ���� */




/**
  * @brief    TIMER0 ����ϵͳʱ��  ��ʼ�������ʹ�þ�ȷ��ʱ�ͳ����ʱ�����ܺ���
  *
  * @param    �� 
  *
  * @return   ��
  *
  * @note     ��ʹ��TIMER0_GetUs(); TIMER0_GetMs(); ����ʱ �����Ƚ��г�ʼ��  ע��ʱ�ӱ���24Mhz
  *
  * @see      TIMER0_InitSys();   
  *
  * @date     2020/3/12 
  */
void TIMER0_InitSys(void);


/**
  * @brief    TIMER0 ����ϵͳʱ��ʱ  ��ȡ��ǰʱ�� us
  *
  * @param    �� 
  *
  * @return   ��ǰ us��
  *
  * @note     ��ʹ��TIMER0_GetUs(); ����ʱ �����Ƚ��г�ʼ��  ע��ʱ�ӱ���24Mhz
  *
  * @see      uint32_t sysTick = TIMER0_GetUs();   
  *
  * @date     2020/3/12 
  */
uint32_t TIMER0_GetUs(void);


/**
  * @brief    TIMER0 ����ϵͳʱ��ʱ  ��ȡ��ǰʱ�� ms
  *
  * @param    �� 
  *
  * @return   ��ǰ ms��
  *
  * @note     ��ʹ��TIMER0_GetMs(); ����ʱ �����Ƚ��г�ʼ��  ע��ʱ�ӱ���24Mhz
  *
  * @see      uint32_t sysTick = TIMER0_GetMs();   
  *
  * @date     2020/3/12 
  */
uint32_t TIMER0_GetMs(void);


/**
  * @brief    TIMER0 ����ϵͳʱ��ʱ  ��ʱ���� us
  *
  * @param    ��ʱʱ�� us 
  *
  * @return   ��
  *
  * @note     ��ʹ��TIMER0_DelayUs(); ����ʱ �����Ƚ��г�ʼ��  ע��ʱ�ӱ���24Mhz
  *
  * @see      TIMER0_DelayUs(1000);   
  *
  * @date     2020/3/12 
  */
void TIMER0_DelayUs(uint32_t us);


/**
  * @brief    TIMER0 ����ϵͳʱ��ʱ  ��ʱ���� ms
  *
  * @param    ��ʱʱ�� ms 
  *
  * @return   ��
  *
  * @note     ��ʹ��TIMER0_DelayMs(); ����ʱ �����Ƚ��г�ʼ��  ע��ʱ�ӱ���24Mhz
  *
  * @see      TIMER0_DelayMs(1000);   
  *
  * @date     2020/3/12 
  */
void TIMER0_DelayMs(uint32_t ms);


#endif
