/*!
  * @file     test_pwm.c
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
#include "test_pwm.h"
#include "lq_pwm.h"

/* ����ȷ��ʱ */
extern void delayms(uint32_t ms);

#if (STC8A == 1)

/**
  * @brief    ����STC8A ĸ�� PWM  �ӿ� 
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note      
  *
  * @see      
  *
  * @date     2020/4/1 ����һ
  */
void Test_PWM(void)
{
	char xdata duty = 0;
	
	PWM_Init(2, 0, 12500, 0);
	PWM_Init(2, 1, 12500, 0);
	PWM_Init(2, 2, 12500, 0);
	PWM_Init(2, 3, 12500, 0);
	
	
	while(1)
	{
		
		if(duty > 0)
		{
			PWM_SetDuty(2, 0, 0);
			PWM_SetDuty(2, 1, duty * 1000);
			PWM_SetDuty(2, 2, 0);
			PWM_SetDuty(2, 3, duty * 1000);
		}
		else
		{
			PWM_SetDuty(2, 0, -duty * 1000);
			PWM_SetDuty(2, 1, 0);
			PWM_SetDuty(2, 2, -duty * 1000);
			PWM_SetDuty(2, 3, 0);
		}
		
		
		
		duty ++;
		
		if(duty > 5)
		{
			duty = -5;
		}
		
		delayms(1000);
	}
	
}


#else


/**
  * @brief    ����STC8H ĸ�� PWM  �ӿ� 
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note      
  *
  * @see      
  *
  * @date     2020/4/1 ����һ
  */
void Test_PWM(void)
{
	char xdata duty = 0;
	
	PWM_Init(0, 0, 12500, 0);   //��ʼ�� P10
	PWM_Init(1, 1, 12500, 0);   //��ʼ�� P22
	PWM_Init(1, 2, 12500, 0);   //��ʼ�� P24
	PWM_Init(1, 3, 12500, 0);   //��ʼ�� P26
	
	
	while(1)
	{
		
		if(duty > 0)
		{
			PWM_SetDuty(0, 0, 0);
			PWM_SetDuty(1, 1, duty * 1000);
			PWM_SetDuty(1, 2, 0);
			PWM_SetDuty(1, 3, duty * 1000);
		}
		else
		{
			PWM_SetDuty(0, 0, -duty * 1000);
			PWM_SetDuty(1, 1, 0);
			PWM_SetDuty(1, 2, -duty * 1000);
			PWM_SetDuty(1, 3, 0);
		}
		
		
		
		duty ++;
		
		if(duty > 5)
		{
			duty = -5;
		}
		
		delayms(1000);
	}
	
}
#endif
