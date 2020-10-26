/*!
  * @file     lq_pwm.h
  *
  * @brief    pwm�����ļ�
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

#ifndef __LQ_PWM_H
#define __LQ_PWM_H

#include "stc8.h"
#include "lq_gpio.h"

/** PWM ռ�ձ����ֵ */
#define PWM_DUTY_MAX    10000.0f


/* STC8H  */
#if (STC8H == 1)

/*========================================================================================*/
/*========================================================================================*/
/*=========================STC8H PWM�ײ����� �û��������=================================*/
/*========================================================================================*/
/*========================================================================================*/

/** PWM ����ʱ���� */
extern uint16_t xdata PWM_Period[3];

/* ʹ��PWM ͨ�� */
#define Pwm0_Enable()        EAXSFR();  PWM1_CCMR1 = 0x68; PWM1_ENO |= (1<< 0); PWM1_BKR = 0x80; PWM1_CR1 = 0x01; EAXRAM();   
#define Pwm1_Enable()        EAXSFR();  PWM1_CCMR2 = 0x68; PWM1_ENO |= (1<< 2); PWM1_BKR = 0x80; PWM1_CR1 = 0x01; EAXRAM();  
#define Pwm2_Enable()        EAXSFR();  PWM1_CCMR3 = 0x68; PWM1_ENO |= (1<< 4); PWM1_BKR = 0x80; PWM1_CR1 = 0x01; EAXRAM();  
#define Pwm3_Enable()        EAXSFR();  PWM1_CCMR4 = 0x68; PWM1_ENO |= (1<< 6); PWM1_BKR = 0x80; PWM1_CR1 = 0x01; EAXRAM();  
#define Pwm4_Enable()        EAXSFR();  PWM2_CCMR1 = 0x68; PWM2_ENO |= (1<< 0); PWM2_BKR = 0x80; PWM2_CR1 = 0x01; EAXRAM();  
#define Pwm5_Enable()        EAXSFR();  PWM2_CCMR2 = 0x68; PWM2_ENO |= (1<< 2); PWM2_BKR = 0x80; PWM2_CR1 = 0x01; EAXRAM();  
#define Pwm6_Enable()        EAXSFR();  PWM2_CCMR3 = 0x68; PWM2_ENO |= (1<< 4); PWM2_BKR = 0x80; PWM2_CR1 = 0x01; EAXRAM();  
#define Pwm7_Enable()        EAXSFR();  PWM2_CCMR4 = 0x68; PWM2_ENO |= (1<< 6); PWM2_BKR = 0x80; PWM2_CR1 = 0x01; EAXRAM();  


/* ����PWMn ʱ��  MAIN_Fosc/(div+1)  div��Χ 0-65535*/
#define PWM_SetClk(n, div)            EAXSFR();  PWM##n##_PSCRH = (div)/256;  PWM##n##_PSCRL = (div)%256;; EAXRAM();        

/* ����PWMn ���� clk Ϊ����ʱ���� */
#define PWM_SetPeriod(n, clk)         EAXSFR();  PWM##n##_ARRH = (clk)/256;PWM##n##_ARRL = (clk)%256; PWM_Period[n] = clk; EAXRAM();

/* ����PWM ͨ������ */
#define PWM_SetPolarity(n)            EAXSFR();  PWM##n##_CCER1 = 0x55;PWM##n##_CCER2 = 0x55; EAXRAM();

/* ����PWM ����� */
#define Pwm00_SetIO()                 PIN_InitStandard(1, 0);  EAXSFR();  PWM1_PS |= (0 << 0); EAXRAM();
#define Pwm01_SetIO()                 PIN_InitStandard(2, 0);  EAXSFR();  PWM1_PS |= (1 << 0); EAXRAM();
#define Pwm02_SetIO()                 PIN_InitStandard(6, 0);  EAXSFR();  PWM1_PS |= (2 << 0); EAXRAM();
#define Pwm10_SetIO()                 PIN_InitStandard(1, 2);  EAXSFR();  PWM1_PS |= (0 << 2); EAXRAM();
#define Pwm11_SetIO()                 PIN_InitStandard(2, 2);  EAXSFR();  PWM1_PS |= (1 << 2); EAXRAM();
#define Pwm12_SetIO()                 PIN_InitStandard(6, 2);  EAXSFR();  PWM1_PS |= (2 << 2); EAXRAM();
#define Pwm20_SetIO()                 PIN_InitStandard(1, 4);  EAXSFR();  PWM1_PS |= (0 << 4); EAXRAM();
#define Pwm21_SetIO()                 PIN_InitStandard(2, 4);  EAXSFR();  PWM1_PS |= (1 << 4); EAXRAM();
#define Pwm22_SetIO()                 PIN_InitStandard(6, 4);  EAXSFR();  PWM1_PS |= (2 << 4); EAXRAM();
#define Pwm30_SetIO()                 PIN_InitStandard(1, 6);  EAXSFR();  PWM1_PS |= (0 << 6); EAXRAM();
#define Pwm31_SetIO()                 PIN_InitStandard(2, 6);  EAXSFR();  PWM1_PS |= (1 << 6); EAXRAM();
#define Pwm32_SetIO()                 PIN_InitStandard(6, 6);  EAXSFR();  PWM1_PS |= (2 << 6); EAXRAM();
#define Pwm40_SetIO()                 PIN_InitStandard(2, 0);  EAXSFR();  PWM2_PS |= (0 << 0); EAXRAM();
#define Pwm41_SetIO()                 PIN_InitStandard(1, 7);  EAXSFR();  PWM2_PS |= (1 << 0); EAXRAM();
#define Pwm42_SetIO()                 PIN_InitStandard(0, 0);  EAXSFR();  PWM2_PS |= (2 << 0); EAXRAM();
#define Pwm50_SetIO()                 PIN_InitStandard(2, 1);  EAXSFR();  PWM2_PS |= (0 << 2); EAXRAM();
#define Pwm51_SetIO()                 PIN_InitStandard(5, 4);  EAXSFR();  PWM2_PS |= (1 << 2); EAXRAM();
#define Pwm52_SetIO()                 PIN_InitStandard(0, 1);  EAXSFR();  PWM2_PS |= (2 << 2); EAXRAM();
#define Pwm60_SetIO()                 PIN_InitStandard(2, 2);  EAXSFR();  PWM2_PS |= (0 << 4); EAXRAM();
#define Pwm61_SetIO()                 PIN_InitStandard(3, 3);  EAXSFR();  PWM2_PS |= (1 << 4); EAXRAM();
#define Pwm62_SetIO()                 PIN_InitStandard(0, 2);  EAXSFR();  PWM2_PS |= (2 << 4); EAXRAM();
#define Pwm70_SetIO()                 PIN_InitStandard(2, 3);  EAXSFR();  PWM2_PS |= (0 << 6); EAXRAM();
#define Pwm71_SetIO()                 PIN_InitStandard(3, 4);  EAXSFR();  PWM2_PS |= (1 << 6); EAXRAM();
#define Pwm72_SetIO()                 PIN_InitStandard(0, 3);  EAXSFR();  PWM2_PS |= (2 << 6); EAXRAM();

#define pwm0_setDuty(duty)                 EAXSFR();  PWM1_CCR1 =  ((float)(duty)/PWM_DUTY_MAX)*PWM_Period[1];  EAXRAM();
#define pwm1_setDuty(duty)                 EAXSFR();  PWM1_CCR2 =  ((float)(duty)/PWM_DUTY_MAX)*PWM_Period[1];  EAXRAM();
#define pwm2_setDuty(duty)                 EAXSFR();  PWM1_CCR3 =  ((float)(duty)/PWM_DUTY_MAX)*PWM_Period[1];  EAXRAM();
#define pwm3_setDuty(duty)                 EAXSFR();  PWM1_CCR4 =  ((float)(duty)/PWM_DUTY_MAX)*PWM_Period[1];  EAXRAM();
#define pwm4_setDuty(duty)                 EAXSFR();  PWM2_CCR1 =  ((float)(duty)/PWM_DUTY_MAX)*PWM_Period[2];  EAXRAM();
#define pwm5_setDuty(duty)                 EAXSFR();  PWM2_CCR2 =  ((float)(duty)/PWM_DUTY_MAX)*PWM_Period[2];  EAXRAM();
#define pwm6_setDuty(duty)                 EAXSFR();  PWM2_CCR3 =  ((float)(duty)/PWM_DUTY_MAX)*PWM_Period[2];  EAXRAM();
#define pwm7_setDuty(duty)                 EAXSFR();  PWM2_CCR4 =  ((float)(duty)/PWM_DUTY_MAX)*PWM_Period[2];  EAXRAM();


#define Pwm_SetDuty(n, channel, duty)                   pwm##channel##_setDuty(duty)


#define Pwm_Init(n, channel, frequency, duty)           Pwm##channel##n##_SetIO();\
														if(channel > 3)  {PWM_SetClk(2, 15);  PWM_SetPeriod(2, MAIN_Fosc/16/frequency);PWM_SetPolarity(2);Pwm_SetDuty(n, channel, duty);Pwm##channel##_Enable();}\
														else             {PWM_SetClk(1, 15);  PWM_SetPeriod(1, MAIN_Fosc/16/frequency);PWM_SetPolarity(1);Pwm_SetDuty(n, channel, duty);Pwm##channel##_Enable();}\
														


/*========================================================================================*/
/*========================================================================================*/
/*==============================STC8H PWM �û�API ========================================*/
/*========================================================================================*/
/*========================================================================================*/

/*
	STC8H8 һ��2��PWMģ�� ÿ��PWMģ��������4·Ƶ����ͬ��PWM��  ÿ·PWM����ӳ���ڲ�ͬ�ܽ��ϣ���ѡһ��
	
	channel          n = 0                    n = 1                   n = 2                    
	                                                                                 
	   0              P1_0                     P2_0                    P6_0          
	   1              P1_2                     P2_2                    P6_2          
	   2              P1_4                     P2_4                    P6_4          
	   3              P1_6                     P2_6                    P6_6          
	                                                                                 
	   4              P2_0                     P1_7                    P0_0          
	   5              P2_1                     P5_4                    P0_1          
	   6              P2_2                     P3_3                    P0_2          
	   7              P2_3                     P3_4                    P0_3           
	
*/

/* ����PWMn ͨ��channelռ�ձ�
 * n        : PWMӳ��   STC8H����Χ 0-2 
 * channel  ��PWMͨ��   ��Χ 0-7   ע��ǰ4��ͨ��Ϊһ��PWMģ�飬���ĸ�ͨ��Ϊһ��PWMģ�飬ÿ��PWMģ��ֻ����һ��Ƶ��
 * duty     ��PWMռ�ձ� ��Χ 0 - PWM_DUTY_MAX
 */
#define PWM_SetDuty(n, channel, duty)          Pwm_SetDuty(n, channel, duty)


/* PWM ��ʼ�� 
 * n        : PWMӳ��   STC8H����Χ 0-2  
 * channel  ��PWMͨ��   ��Χ 0-7   ע��ǰ4��ͨ��Ϊһ��PWMģ�飬���ĸ�ͨ��Ϊһ��PWMģ�飬ÿ��PWMģ��ֻ����һ��Ƶ��
 * frequency��PWMƵ��   
 * duty     ��PWMռ�ձ� ��Χ 0 - PWM_DUTY_MAX
 */
#define PWM_Init(n, channel, frequency, duty)   Pwm_Init(n, channel, frequency, duty)




/* STC8G  */
#elif (STC8G == 1)

/** PWM ����ʱ���� */
extern uint16_t xdata PWM_Period[6];
/*========================================================================================*/
/*========================================================================================*/
/*=========================STC8G PWM�ײ����� �û��������=================================*/
/*========================================================================================*/
/*========================================================================================*/


/* ʹ�� PWMģ��  n ��Χ 0-5 */
#define Pwm_Enable(n)           PWMSET |= (1 << n)
#define Pwm_Disable(n)          PWMSET &= ~(1 << n)

/* PWM ʹ���ж� */
#define Pwm0_EnableInterrupt()   PWMCFG01 |= (1 << 2)
#define Pwm0_DisableInterrupt()  PWMCFG01 &= ~(1 << 2)
#define Pwm1_EnableInterrupt()   PWMCFG01 |= (1 << 6)
#define Pwm1_DisableInterrupt()  PWMCFG01 &= ~(1 << 6)
#define Pwm2_EnableInterrupt()   PWMCFG23 |= (1 << 2)
#define Pwm2_DisableInterrupt()  PWMCFG23 &= ~(1 << 2)
#define Pwm3_EnableInterrupt()   PWMCFG23 |= (1 << 6)
#define Pwm3_DisableInterrupt()  PWMCFG23 &= ~(1 << 6)
#define Pwm4_EnableInterrupt()   PWMCFG45 |= (1 << 2)
#define Pwm4_DisableInterrupt()  PWMCFG45 &= ~(1 << 2)
#define Pwm5_EnableInterrupt()   PWMCFG45 |= (1 << 6)
#define Pwm5_DisableInterrupt()  PWMCFG45 &= ~(1 << 6)



/* PWM ����жϱ�־λ */
#define Pwm0_Clear()             PWMCFG01 &= ~(1 << 3)
#define Pwm1_Clear()             PWMCFG01 &= ~(1 << 7)
#define Pwm2_Clear()             PWMCFG23 &= ~(1 << 3)
#define Pwm3_Clear()             PWMCFG23 &= ~(1 << 7)
#define Pwm4_Clear()             PWMCFG45 &= ~(1 << 3)
#define Pwm5_Clear()             PWMCFG45 &= ~(1 << 7)


/* PWM ��ʼ���� */
#define Pwm0_Start()              PWMCFG01 |= (1 << 0)
#define Pwm0_Stop()               PWMCFG01 &= ~(1 << 0)
#define Pwm1_Start()              PWMCFG01 |= (1 << 4)
#define Pwm1_Stop()               PWMCFG01 &= ~(1 << 4)
#define Pwm2_Start()              PWMCFG23 |= (1 << 0)
#define Pwm2_Stop()               PWMCFG23 &= ~(1 << 0)
#define Pwm3_Start()              PWMCFG23 |= (1 << 4)
#define Pwm3_Stop()               PWMCFG23 &= ~(1 << 4)
#define Pwm4_Start()              PWMCFG45 |= (1 << 0)
#define Pwm4_Stop()               PWMCFG45 &= ~(1 << 0)
#define Pwm5_Start()              PWMCFG45 |= (1 << 4)
#define Pwm5_Stop()               PWMCFG45 &= ~(1 << 4)


/* PWM ʹ���ж� */
#define PWM_EnableInterrupt(n)   Pwm##n##_EnableInterrupt()
#define PWM_DisableInterrupt(n)  Pwm##n##_DisableInterrupt()


/* PWM ����жϱ�־λ */
#define PWM_Clear(n)             Pwm##n##_Clear()


/* PWM ��ʼ���� */
#define PWM_Start(n)              Pwm##n##_Start()
#define PWM_Stop(n)               Pwm##n##_Stop()


/* ����PWMn ʱ��  MAIN_Fosc/(div+1)  div��Χ 0-15*/
#define PWM_SetClk(n, div)            EAXSFR();  PWM##n##CKS &= ~0xff;  PWM##n##CKS |= div ; EAXRAM();        

/* ����PWMn ���� clk Ϊ����ʱ���� */
#define PWM_SetPeriod(n, clk)         EAXSFR();  PWM##n##C = (clk); PWM_Period[n] = clk; EAXRAM();


/* ����PWMn ͨ��ʹ�� һ��PWMģ����8��ͨ�� */
#define PWM_EnableChannel(n, channel) EAXSFR();  PWM##n##channel##CR |= 0x80; EAXRAM();



#define Pwm_SetDuty(n, channel, duty) EAXSFR();  PWM##n##channel##T2 = 0; PWM##n##channel##T1 = ((float)(duty)/PWM_DUTY_MAX)*PWM_Period[n];  EAXRAM();


#define Pwm_Init(n, channel, frequency, duty)    PIN_InitStandard(n, channel); Pwm_Enable(n); PWM_DisableInterrupt(n); PWM_SetClk(n, 15); PWM_SetPeriod(n, MAIN_Fosc/16/frequency); PWM_SetDuty(n, channel, duty);  PWM_EnableChannel(n, channel); PWM_Start(n);



/*========================================================================================*/
/*========================================================================================*/
/*==============================STC8G PWM �û�API ========================================*/
/*========================================================================================*/
/*========================================================================================*/

/*
	STC8G2 һ��6��PWMģ�� ÿ��PWMģ��������8·Ƶ����ͬ��PWM��
	
	PWM00  P0_0         PWM10  P1_0        PWM20  P2_0       PWM30  P3_0        PWM40  P4_0        PWM50  P5_0
	PWM01  P0_1         PWM11  P1_1        PWM21  P2_1       PWM31  P3_1        PWM41  P4_1        PWM51  P5_1
	PWM02  P0_2         PWM12  P1_2        PWM22  P2_2       PWM32  P3_2        PWM42  P4_2        PWM52  P5_2
	PWM03  P0_3         PWM13  P1_3        PWM23  P2_3       PWM33  P3_3        PWM43  P4_3        PWM53  P5_3
	PWM04  P0_4         PWM14  P1_4        PWM24  P2_4       PWM34  P3_4        PWM44  P4_4        PWM54  P5_4
	PWM05  P0_5         PWM15  P1_5        PWM25  P2_5       PWM35  P3_5        PWM45  P4_5        PWM55  P5_5
	PWM06  P0_6         PWM16  P1_6        PWM26  P2_6       PWM36  P3_6        PWM46  P4_6        PWM56  P5_6
	PWM07  P0_7         PWM17  P1_7        PWM27  P2_7       PWM37  P3_7        PWM47  P4_7        PWM57  P5_7     
	
*/



/* ����PWMn ͨ��channelռ�ձ�
 * n        : PWMģ��   STC8G����Χ 0-5 
 * channel  ��PWMͨ��   ��Χ 0-7
 * duty     ��PWMռ�ձ� ��Χ 0 - PWM_DUTY_MAX
 */
#define PWM_SetDuty(n, channel, duty)          Pwm_SetDuty(n, channel, duty)


/* PWM ��ʼ�� 
 * n        : PWMģ��   STC8G����Χ 0-5  
 * channel  ��PWMͨ��   ��Χ 0-7
 * frequency��PWMƵ��   ע�� STC8G2 һ��6��PWMģ�� ÿ��PWMģ��������8·Ƶ����ͬ��PWM��
 * duty     ��PWMռ�ձ� ��Χ 0 - PWM_DUTY_MAX
 */
#define PWM_Init(n, channel, frequency, duty)   Pwm_Init(n, channel, frequency, duty)



#elif (STC8A == 1)



/*========================================================================================*/
/*========================================================================================*/
/*=========================STC8A PWM�ײ����� �û��������=================================*/
/*========================================================================================*/
/*========================================================================================*/
/** PWM ����ʱ���� */
extern uint16_t xdata PWM_Period;

/* PWM����������ж� ����жϱ�־λ */
#define PWM_Clear()             PWMCFG &= ~0x80

/* ʹ�� PWMģ��  n ��Χ 0-5 */
#define Pwm_Start()             PWMCR |= (1 << 7)
#define Pwm_Stop()              PWMCR &= ~(1 << 7)

/* PWM ʹ�ܼ���������ж� */
#define PWM_EnableInterrupt()   PWMCR |= (1 << 6)
#define PWM_DisableInterrupt()  PWMCR &= ~(1 << 6)


/* ����PWMn ʱ��  MAIN_Fosc/(div+1)  div��Χ 0-15*/
#define PWM_SetClk(div)            EAXSFR();  PWMCKS &= ~0xff;  PWMCKS |= div ; EAXRAM();        

/* ����PWM  ���� clk Ϊ����ʱ���� */
#define PWM_SetPeriod(clk)         EAXSFR();  PWMC = (clk); PWM_Period = clk; EAXRAM();


/* ����PWM ͨ��ʹ�� һ��PWMģ����8��ͨ�� */
#define PWM_EnableChannel(channel) EAXSFR();  PWM##channel##CR |= 0x80; EAXRAM();

/* ����PWM ͨ���˿�ӳ�� */
#define PWM_SetChannelMap(channel, map)   EAXSFR(); PWM##channel##CR &= (3 << 3); if(map == 2){ PIN2_InitPushPull(channel);PWM##channel##CR |= 0;} if(map == 1){ PIN1_InitPushPull(channel); PWM##channel##CR |= (1<<3);}if(map == 6){ PIN6_InitPushPull(channel); PWM##channel##CR |= (2<<3); }   EAXRAM();


#define Pwm_SetDuty(n, channel, duty)     EAXSFR();  PWM##channel##T2 = 0; PWM##channel##T1 = ((float)(duty)/PWM_DUTY_MAX)*PWM_Period;  EAXRAM();


#define Pwm_Init(n, channel, frequency, duty)    PWM_SetChannelMap(channel, n); PWM_DisableInterrupt(); PWM_SetClk(15); PWM_SetPeriod(MAIN_Fosc/16/frequency); PWM_SetDuty(n, channel, duty) ;  PWM_EnableChannel(channel); Pwm_Start();




/*========================================================================================*/
/*========================================================================================*/
/*================================STC8A PWM �û�API ======================================*/
/*========================================================================================*/
/*========================================================================================*/

/*
	
	STC8A  һ��1��PWMģ�� �������8·Ƶ����ͬ��PWM��  ��8·PWMÿ·����ӳ���������ܽ����� ����ѡȡһ���ܽŽ��г�ʼ��
	
	channel     n = 2     n = 1    n = 6
	
	PWM00       P2_0      P1_0     P6_0  
	PWM01       P2_1      P1_1     P6_1
	PWM02       P2_2      P1_2     P6_2
	PWM03       P2_3      P1_3     P6_3
	PWM04       P2_4      P1_4     P6_4
	PWM05       P2_5      P1_5     P6_5
	PWM06       P2_6      P1_6     P6_6
	PWM07       P2_7      P1_7     P6_7
	
*/



/* ����PWMn ͨ��channelռ�ձ�
 * n        : PWMģ��   STC8A����Χ 2 �� 1 �� 6  
 * channel  ��PWMͨ��   ��Χ 0-7
 * duty     ��PWMռ�ձ� ��Χ 0 - PWM_DUTY_MAX
 */
#define PWM_SetDuty(n, channel, duty)          Pwm_SetDuty(n, channel, duty)


/* PWM ��ʼ�� 
 * n        : PWMģ��   STC8A����Χ 2 �� 1 �� 6  
 * channel  ��PWMͨ��   ��Χ 0-7
 * frequency��PWMƵ��   ע�� STC8A PWMģ��ֻ�������8·Ƶ����ͬ��PWM��
 * duty     ��PWMռ�ձ� ��Χ 0 - PWM_DUTY_MAX
 */
#define PWM_Init(n, channel, frequency, duty)   Pwm_Init(n, channel, frequency, duty)

#endif







#endif
