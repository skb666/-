/*!
  * @file     lq_adc.h
  *
  * @brief    adc �����ļ�
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

#ifndef __LQ_ADC_H__
#define __LQ_ADC_H__

#include "stc8.h"
#include "intrins.h"
#include "lq_gpio.h"


/*========================================================================================*/
/*========================================================================================*/
/*===========================ADC�ײ����� �û��������===================================*/
/*========================================================================================*/
/*========================================================================================*/

//ADC ���⹦�ܼĴ���
//sfr ADC_CONTR   =   0xbc;
#define ADC_POWER   0x80
#define ADC_START   0x40
#define ADC_FLAG    0x20
//sfr ADC_RES     =   0xbd;
//sfr ADC_RESL    =   0xbe;
//sfr ADCCFG      =   0xde;
#define ADC_RESFMT  0x20

/* ���� ADC ����� ADC_RES ���ADCת�������8λ   ADC_RESL ��λ���ʣ�½�� */
#define Adc_Left            ADCCFG  &= ~ADC_RESFMT

/* ���� ADC �Ҷ��� ADC_RESL ���ADCת�������8λ  ADC_RES  ��λ���ʣ�½��*/
#define Adc_Right           ADCCFG  |= ADC_RESFMT

/* ���� ADC ʱ��  ADCʱ�� = ϵͳʱ��/2/(Div+1)   Div��Χ 0-15 */
#define Adc_SetDiv(Div)     ADCCFG  &= 0xf0, ADCCFG |= Div

/* ��ADCģ���Դ */
#define Adc_Power()         ADC_CONTR = ADC_POWER 

/* ����ADCģ�� */
#define Adc_InitConfig()    Adc_Right, Adc_SetDiv(0), Adc_Power() 

/* ����ADCת��ͨ��*/
#define Adc_SetChannel(channel) ADC_CONTR &= 0xf0, ADC_CONTR |= channel

/* ����ADCת�� */
#define Adc_Start()         ADC_CONTR |= 0x40

/* ADC�ж�ʹ�� */
#define Adc_EnableInterrupt()  EADC = 1

/* ADC�жϹر� */
#define Adc_DisableInterrupt() EADC = 0

/* ��� ADC�жϱ�־λ*/
#define ADC_Clear()            ADC_CONTR &= ~(1<<5)

/*========================================================================================*/
/*========================================================================================*/
/*===========================ADC �û�API =================================================*/
/*========================================================================================*/
/*========================================================================================*/
/*
	SCT8H ��15��ADCͨ�� ÿ��ͨ����Ӧ�ܽ�����
	0     P1.0          8  P0.0
    1     P1.1          9  P0.1
    2     P5.4          10 P0.2
    3     P1.3          11 P0.3
    4     P1.4          12 P0.4
    5     P1.5          13 P0.5
    6     P1.6          14 P0.6
    7     P1.7          15 �����ڲ� 1.19V
	
	SCT8G/STC8A ��15��ADCͨ�� ÿ��ͨ����Ӧ�ܽ�����
	0     P1.0          8  P0.0
    1     P1.1          9  P0.1
    2     P1.2          10 P0.2
    3     P1.3          11 P0.3
    4     P1.4          12 P0.4
    5     P1.5          13 P0.5
    6     P1.6          14 P0.6
    7     P1.7          15 �����ڲ� 1.19V
	
	ע�� STC8A��STC8H8Ϊ12λADC  8GΪ10λADC
	
	��ȡADCͨ��ֵ
	1. ADCͨ����ʼ��
		ADC0_Init();    //��ʼ��P10ΪADCͨ��
		
	2. ��ȡADCͨ��ֵ
		uint16_t xdata adcValue = 0;
		ADC_GetValue(0, adcValue);
*/

/* ��ʼ��ADC ͨ�� */
#define ADC0_Init()         PIN1_InitPureInput(0), Adc_InitConfig()
#define ADC1_Init()         PIN1_InitPureInput(1), Adc_InitConfig()
#if (STC8H == 1)
#define ADC2_Init()         PIN5_InitPureInput(4), Adc_InitConfig()
#else
#define ADC2_Init()         PIN1_InitPureInput(2), Adc_InitConfig()
#endif
#define ADC3_Init()         PIN1_InitPureInput(3), Adc_InitConfig()
#define ADC4_Init()         PIN1_InitPureInput(4), Adc_InitConfig()
#define ADC5_Init()         PIN1_InitPureInput(5), Adc_InitConfig()
#define ADC6_Init()         PIN1_InitPureInput(6), Adc_InitConfig()
#define ADC7_Init()         PIN1_InitPureInput(7), Adc_InitConfig()
#define ADC8_Init()         PIN0_InitPureInput(0), Adc_InitConfig()
#define ADC9_Init()         PIN0_InitPureInput(1), Adc_InitConfig()
#define ADC10_Init()        PIN0_InitPureInput(2), Adc_InitConfig()
#define ADC11_Init()        PIN0_InitPureInput(3), Adc_InitConfig()
#define ADC12_Init()        PIN0_InitPureInput(4), Adc_InitConfig()
#define ADC13_Init()        PIN0_InitPureInput(5), Adc_InitConfig()
#define ADC14_Init()        PIN0_InitPureInput(6), Adc_InitConfig()

#define Adc_Init(channel)   ADC##channel##_Init()

/**
 * ��ʼ��ADCͨ��ֵ 
 * channel : ADCͨ��
 */
#define ADC_Init(channel)   Adc_Init(channel)

/**
 * ��ȡADCͨ��ֵ 
 * channel : ADCͨ��
 * value   : ���ͨ��ֵ
 */
#define ADC_GetValue(channel, value)       {Adc_SetChannel(channel);\
											Adc_Start();\
											_nop_();\
											_nop_();\
											while (!(ADC_CONTR & 0x20));\
											ADC_CONTR &= ~0x20;\
											value = ADC_RES<<8 | ADC_RESL;}


#endif 
