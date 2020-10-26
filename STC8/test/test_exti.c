/*!
  * @file     test_exti.c
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
#include "test_exti.h"
#include "lq_gpio.h"
#include "lq_led.h"
/**
  * @brief    ���Թܽ��ⲿ�ж�   
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note     STC8ֻ��5���ܽ����ⲿ�жϹ��� �����뿴lq_gpio.h
  *
  * @example  
  *
  * @date     2019/4/22 ����һ
*/
void Test_EXTI()
{
	LED_Init();
	
	/* P37��ʼ�� �����ڲ��������� */
	PIN_InitStandard(3, 7);
	PIN_EnablePullUp(3, 7);
	
	/* ���� P37 �ж����ȼ� */
	SET_INT0_PRIORITY(2);
	
	/* ʹ���½����ж� */
	INT3_Enable();
	
	/* �жϷ����� ��irq.c�� ��תLED */
	while(1)
	{
		
	}
	
}
