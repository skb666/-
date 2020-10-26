/*!
  * @file     lq_timer.c
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

#include "lq_timer.h"



/* ��ʱ��API���� �� lq_timer.h �� */



/* ��TIMER0 ����ʱ��ʱ ���ʱ��Ƭ���� */
volatile uint32_t xdata s_timerCounter = 0;



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
void TIMER0_InitSys(void)
{
	TIMER0_Init(1000);
	
	s_timerCounter = 0;
}


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
uint32_t TIMER0_GetUs(void)
{
	volatile uint16_t xdata value = 0;
	volatile uint8_t xdata timer0L = 0;
	do
	{
		value    = TH0;
		timer0L  = TL0;
	}while(value != TH0);
	value = value << 8 | timer0L;

	return (uint32_t)((s_timerCounter*1000) + ((value - 63536) >> 1));
}


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
uint32_t TIMER0_GetMs(void)
{
	volatile uint16_t xdata value = 0;
	volatile uint8_t xdata timer0L = 0;
	do
	{
		value    = TH0;
		timer0L  = TL0;
	}while(value != TH0);
	value = value << 8 | timer0L;
	
	return (uint32_t)(s_timerCounter);
}


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
void TIMER0_DelayUs(uint32_t us)
{
	volatile uint32_t xdata sysTick = 0;
	sysTick = TIMER0_GetUs(); 
	
	while((TIMER0_GetUs() - sysTick) <= us);
}


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
void TIMER0_DelayMs(uint32_t ms)
{
	while(ms--)
	{
		TIMER0_DelayUs(1000);
	}
}
