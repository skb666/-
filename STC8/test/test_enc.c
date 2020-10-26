/*!
  * @file     test_enc.c
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
#include "test_enc.h"
#include "lq_enc.h"
#include "lq_uart.h"
#include "stdio.h"
#include "lq_led.h"
#include "lq_oled.h"

/* ����ȷ��ʱ */
extern void delayms(uint32_t ms);
#if (STC8A == 1)

/* STC8A����������ܽ� */
#define ENC1_DIR_PORT     0
#define ENC1_DIR_INDEX    7

#define ENC2_DIR_PORT     5
#define ENC2_DIR_INDEX    2
#else

/* STC8H����������ܽ� */
#define ENC1_DIR_PORT     0
#define ENC1_DIR_INDEX    5

#define ENC2_DIR_PORT     4
#define ENC2_DIR_INDEX    7

#endif
/**
  * @brief    ���Դ����������   
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note      
  *
  * @example  
  *
  * @date     2019/4/22 ����һ
*/
void Test_ENC()
{
	uint8_t xdata txt[32];
	int xdata encValue1 = 0, encValue2 = 0;
	UART1_InitTimer1P30P31(115200);
	LED_Init();
	OLED_Init();
	
	TIMER3_EncInit();   //��ʼ����ʱ��3  ��P04�ܽ� �������
	TIMER4_EncInit();   //��ʼ����ʱ��4  ��P06�ܽ� �������
	
	/* ��ʼ�� ����������ܽ� */	
	PIN_InitStandard(ENC1_DIR_PORT, ENC1_DIR_INDEX);	
	PIN_InitStandard(ENC2_DIR_PORT, ENC2_DIR_INDEX); 
	
	
	while(1)
	{
		/* ��ȡ����ֵ */
		TIMER3_GetValue(encValue1);
		
		/* ����ܽ�Ϊ�͵�ƽ ��ת */
		if(!P(ENC1_DIR_PORT, ENC1_DIR_INDEX))
		{
			encValue1 = -encValue1;
		}
		
		/* ��ȡ����ֵ */
		TIMER4_GetValue(encValue2);
		
		/* ����ܽ�Ϊ�͵�ƽ ��ת */
		if(!P(ENC2_DIR_PORT, ENC2_DIR_INDEX))
		{
			encValue2 = -encValue2;
		}
		
		printf("value1: %d \r\n", encValue1);
		printf("value2: %d \r\n", encValue2);
		
		sprintf(txt, "value1: %5d", encValue1);   
		OLED_P6x8Str(0, 0, txt);                //OLED��ʾ
		
		sprintf(txt, "value2: %5d", encValue2);   
		OLED_P6x8Str(0, 1, txt);                //OLED��ʾ
		
		delayms(10);
		
		
		
	}
	

}
