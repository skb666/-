/*!
  * @file     test_led.c
  *
  * @brief    led����
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
#include "lq_led.h"
#include "test_led.h"

/* ����ȷ��ʱ */
extern void delayms(uint32_t ms);


  
  
 /**
  * @brief    ����LED��
  *
  * @param    
  *
  * @return   
  *
  * @note     
  *
  * @example  
  *
  * @date     2019/6/4 ���ڶ�
  */
 
  
void Test_LED(void)
{
    LED_Init();   
    while (1)
    {          
		uint8_t xdata i;

		LED_Color(red);     //���
		delayms(1000);
		
		LED_Color(green);   //�̵�
		delayms(1000);
		
		LED_Color(blue);    //����
		delayms(1000);
		
		LED_Color(violet);  //�ϵ�
		delayms(1000);
		
		LED_Color(yellow);  //�Ƶ�
		delayms(1000);
		
		LED_Color(cyan);    //���
		delayms(1000);
		
		LED_Color(white);   //�׵�
		delayms(1000);
		
		LED_Color(black);   //�ص�
		delayms(1000);

		for( i = 0; i < 20; i++)
		{
			LED_ColorReverse(red);     //�����˸
			delayms(100);
		}		

		for( i = 0; i < 20; i++)
		{
			LED_ColorReverse(green);   //�̵���˸
			delayms(100);
		}		

		for( i = 0; i < 20; i++)
		{
			LED_ColorReverse(blue);    //������˸
			delayms(100);
		}		

		for( i = 0; i < 20; i++)
		{
			LED_ColorReverse(violet);  //�ϵ���˸
			delayms(100);
		}		

		for( i = 0; i < 20; i++)
		{
			LED_ColorReverse(yellow);  //�Ƶ���˸
			delayms(100);
		}		

		for( i = 0; i < 20; i++)
		{
			LED_ColorReverse(cyan);    //�����˸
			delayms(100);
		}				

		for( i = 0; i < 20; i++)
		{
			LED_ColorReverse(white);   //�׵���˸
			delayms(100);
		}
    }
}

