/*!
  * @file     test_adc.c
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
#include "test_adc.h"
#include "lq_adc.h"
#include "lq_uart.h"
#include "stdio.h"
#include "lq_led.h"
#include "lq_oled.h"

/* ����ȷ��ʱ */
extern void delayms(uint32_t ms);

/* STC8A ĸ��ADC���Ժ��� */
#if (STC8A == 1)

/**
  * @brief    ����ADC  
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note     ADC�ܽ����ղ�Ϊ0 
  *
  * @example  
  *
  * @date     2019/4/22 ����һ
*/
void Test_ADC()
{
	uint8_t xdata txt[32];
	int xdata adcValue = 0;
	UART1_InitTimer1P30P31(115200);
	LED_Init();
	OLED_Init();

	ADC_Init(8);
	ADC_Init(9);
	ADC_Init(10);
	ADC_Init(11);
	ADC_Init(0);
	ADC_Init(1);
	ADC_Init(13);
	
	while(1)
	{
		LED_ColorReverse(green);
		
		ADC_GetValue(8, adcValue);             //��ȡADCֵ, ע���ӦADCͨ��
		sprintf(txt, "P00: %04d", adcValue);    
		OLED_P6x8Str(0, 0, txt);                //OLED��ʾ
		printf("P00: %d \r\n", adcValue);       //���ڴ�ӡ
		
		
		ADC_GetValue(9, adcValue);            
		sprintf(txt, "P01: %04d", adcValue);
		OLED_P6x8Str(0, 1, txt);
		printf("P01: %d \r\n", adcValue);
		
		
		ADC_GetValue(10, adcValue);
		sprintf(txt, "P02: %04d", adcValue);
		OLED_P6x8Str(0, 2, txt);
		printf("P02: %d \r\n", adcValue);
		
		
		ADC_GetValue(11, adcValue);
		sprintf(txt, "P03: %04d", adcValue);
		OLED_P6x8Str(0, 3, txt);
		printf("P03: %d \r\n", adcValue);
		
		
		ADC_GetValue(0, adcValue);
		sprintf(txt, "P10: %04d", adcValue);
		OLED_P6x8Str(0, 4, txt);
		printf("P10: %d \r\n", adcValue);
		
		
		ADC_GetValue(1, adcValue);             //��ȡADCֵ, ע���ӦADCͨ��
		sprintf(txt, "P11: %04d", adcValue);   
		OLED_P6x8Str(0, 5, txt);                //OLED��ʾ
		printf("P11: %d \r\n", adcValue);       //���ڴ�ӡ
		
		
		ADC_GetValue(13, adcValue);             //��ȡADCֵ, ע���ӦADCͨ��
		sprintf(txt, "P05: %04d", adcValue);   
		OLED_P6x8Str(0, 6, txt);                //OLED��ʾ
		printf("P05: %d \r\n", adcValue);       //���ڴ�ӡ
		

		
		
		delayms(500);                           //��ֹ��ӡ̫��
	}
	
}


#else


/**
  * @brief    ����ADC  
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note     ADC�ܽ����ղ�Ϊ0 
  *
  * @example  
  *
  * @date     2019/4/22 ����һ
*/
void Test_ADC()
{
	uint8_t xdata txt[32];
	int xdata adcValue = 0;
	UART1_InitTimer1P30P31(115200);
	LED_Init();
	OLED_Init();

	ADC1_Init();
	ADC3_Init();
	ADC8_Init() ;
	ADC9_Init() ;
	ADC10_Init();
	ADC11_Init();
	
	while(1)
	{
		LED_ColorReverse(green);
		
		ADC_GetValue(1, adcValue);             //��ȡADCֵ, ע���ӦADCͨ��
		sprintf(txt, "P11: %4d", adcValue);   
		OLED_P6x8Str(0, 0, txt);                //OLED��ʾ
		printf("P11: %d \r\n", adcValue);       //���ڴ�ӡ
		
		
		ADC_GetValue(3, adcValue);
		sprintf(txt, "P13: %4d", adcValue);
		OLED_P6x8Str(0, 1, txt);
		printf("P13: %d \r\n", adcValue);
		
		
		ADC_GetValue(8, adcValue);
		sprintf(txt, "P00: %4d", adcValue);
		OLED_P6x8Str(0, 2, txt);
		printf("P00: %d \r\n", adcValue);
		
		
		ADC_GetValue(9, adcValue);
		sprintf(txt, "P01: %4d", adcValue);
		OLED_P6x8Str(0, 3, txt);
		printf("P01: %d \r\n", adcValue);
		
		
		ADC_GetValue(10, adcValue);
		sprintf(txt, "P02: %4d", adcValue);
		OLED_P6x8Str(0, 4, txt);
		printf("P02: %d \r\n", adcValue);
		
		
		ADC_GetValue(11, adcValue);
		sprintf(txt, "P03: %4d", adcValue);
		OLED_P6x8Str(0, 5, txt);
		printf("P03: %d \r\n", adcValue);
		
		delayms(500);                           //��ֹ��ӡ̫��
	}
	
}

#endif
