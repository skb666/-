/*!
  * @file     test_timer.c
  *
  * @brief    STC8
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
#include "test_timer.h"
#include "lq_timer.h"
#include "lq_led.h"



/**
  * @brief    ���Զ�ʱ���ж�   
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note     
  *
  * @example  
  *
  * @date     2020/4/1 
*/
void Test_TIMER()
{
	uint32_t xdata msysTick = 0;
	uint32_t xdata msysTime = 0;
	TIMER0_InitSys();
	LED_Init();
	
	while(1)
	{
		/* �ж� 500 ms �Ƿ��ȥ */
		msysTime = TIMER0_GetUs() - msysTick;
		if(msysTime > 500000UL)
		{
			msysTick = TIMER0_GetUs();
			
			LED_ColorReverse(red);
		}
	}
	
}
