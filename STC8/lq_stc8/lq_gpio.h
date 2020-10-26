/*!
  * @file     lq_gpio.h
  *
  * @brief    gpio �����ļ�
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
#ifndef __LQ_GPIO_H
#define __LQ_GPIO_H

#include "stc8.h"

/*========================================================================================*/
/*========================================================================================*/
/*=============================GPIO�ײ� �û��������======================================*/
/*========================================================================================*/
/*========================================================================================*/

/**  
 * GPIO ��ʼ���궨��
 * bitn :�ܽű��
 * ���� PIN0_InitPushPull(5)  //��ʼ��P05 �������ģʽ
 */
#define PIN0_InitStandard(bitn)			P0M1 &= ~(1<<bitn),	P0M0 &= ~(1<<bitn)	/* 00  */
#define PIN0_InitPushPull(bitn)			P0M1 &= ~(1<<bitn),	P0M0 |=  (1<<bitn)	/* 01  */
#define PIN0_InitPureInput(bitn)		P0M1 |=  (1<<bitn),	P0M0 &= ~(1<<bitn)	/* 10  */
#define PIN0_InitOpenDrain(bitn)		P0M1 |=  (1<<bitn),	P0M0 |=  (1<<bitn)	/* 11  */
                                                                     
#define PIN1_InitStandard(bitn)			P1M1 &= ~(1<<bitn),	P1M0 &= ~(1<<bitn)
#define PIN1_InitPushPull(bitn)			P1M1 &= ~(1<<bitn),	P1M0 |=  (1<<bitn)
#define PIN1_InitPureInput(bitn)		P1M1 |=  (1<<bitn),	P1M0 &= ~(1<<bitn)
#define PIN1_InitOpenDrain(bitn)		P1M1 |=  (1<<bitn),	P1M0 |=  (1<<bitn)
                                                                     
#define PIN2_InitStandard(bitn)			P2M1 &= ~(1<<bitn),	P2M0 &= ~(1<<bitn)
#define PIN2_InitPushPull(bitn)			P2M1 &= ~(1<<bitn),	P2M0 |=  (1<<bitn)
#define PIN2_InitPureInput(bitn)		P2M1 |=  (1<<bitn),	P2M0 &= ~(1<<bitn)
#define PIN2_InitOpenDrain(bitn)		P2M1 |=  (1<<bitn),	P2M0 |=  (1<<bitn)
                                                                     
#define PIN3_InitStandard(bitn)			P3M1 &= ~(1<<bitn),	P3M0 &= ~(1<<bitn)
#define PIN3_InitPushPull(bitn)			P3M1 &= ~(1<<bitn),	P3M0 |=  (1<<bitn)
#define PIN3_InitPureInput(bitn)		P3M1 |=  (1<<bitn),	P3M0 &= ~(1<<bitn)
#define PIN3_InitOpenDrain(bitn)		P3M1 |=  (1<<bitn),	P3M0 |=  (1<<bitn)
                                                                     
#define PIN4_InitStandard(bitn)			P4M1 &= ~(1<<bitn),	P4M0 &= ~(1<<bitn)
#define PIN4_InitPushPull(bitn)			P4M1 &= ~(1<<bitn),	P4M0 |=  (1<<bitn)
#define PIN4_InitPureInput(bitn)		P4M1 |=  (1<<bitn),	P4M0 &= ~(1<<bitn)
#define PIN4_InitOpenDrain(bitn)		P4M1 |=  (1<<bitn),	P4M0 |=  (1<<bitn)
                                                                     
#define PIN5_InitStandard(bitn)			P5M1 &= ~(1<<bitn),	P5M0 &= ~(1<<bitn)
#define PIN5_InitPushPull(bitn)			P5M1 &= ~(1<<bitn),	P5M0 |=  (1<<bitn)
#define PIN5_InitPureInput(bitn)		P5M1 |=  (1<<bitn),	P5M0 &= ~(1<<bitn)
#define PIN5_InitOpenDrain(bitn)		P5M1 |=  (1<<bitn),	P5M0 |=  (1<<bitn)
                                                                     
#define PIN6_InitStandard(bitn)			P6M1 &= ~(1<<bitn),	P6M0 &= ~(1<<bitn)
#define PIN6_InitPushPull(bitn)			P6M1 &= ~(1<<bitn),	P6M0 |=  (1<<bitn)
#define PIN6_InitPureInput(bitn)		P6M1 |=  (1<<bitn),	P6M0 &= ~(1<<bitn)
#define PIN6_InitOpenDrain(bitn)		P6M1 |=  (1<<bitn),	P6M0 |=  (1<<bitn)
                                                                     
#define PIN7_InitStandard(bitn)			P7M1 &= ~(1<<bitn),	P7M0 &= ~(1<<bitn)
#define PIN7_InitPushPull(bitn)			P7M1 &= ~(1<<bitn),	P7M0 |=  (1<<bitn)
#define PIN7_InitPureInput(bitn)		P7M1 |=  (1<<bitn),	P7M0 &= ~(1<<bitn)
#define PIN7_InitOpenDrain(bitn)		P7M1 |=  (1<<bitn),	P7M0 |=  (1<<bitn)


#define Pin_InitStandard(N, bitn)		PIN##N##_InitStandard(bitn)	/* 00  */
#define Pin_InitPushPull(N, bitn)		PIN##N##_InitPushPull(bitn)	/* 01  */
#define Pin_InitPureInput(N, bitn)		PIN##N##_InitPureInput(bitn)	/* 10  */
#define Pin_InitOpenDrain(N, bitn)		PIN##N##_InitOpenDrain(bitn)	/* 11  */

#define PIn(N, bitn)                      P##N##bitn


/**  
 * STC8G ϵ��ÿ��GPIO��������һ��4.1K����������  
 * bitn :�ܽű��
 * ���� PIN0_EnablePullUp(5)  //P05 �ܽſ����ڲ�4.1K��������
 */
#define PIN0_EnablePullUp(bitn)       EAXSFR(),P0PU |=  (1<<bitn), EAXRAM()
#define PIN1_EnablePullUp(bitn)       EAXSFR(),P1PU |=  (1<<bitn), EAXRAM()
#define PIN2_EnablePullUp(bitn)       EAXSFR(),P2PU |=  (1<<bitn), EAXRAM()
#define PIN3_EnablePullUp(bitn)       EAXSFR(),P3PU |=  (1<<bitn), EAXRAM()
#define PIN4_EnablePullUp(bitn)       EAXSFR(),P4PU |=  (1<<bitn), EAXRAM()
#define PIN5_EnablePullUp(bitn)       EAXSFR(),P5PU |=  (1<<bitn), EAXRAM()
#define PIN6_EnablePullUp(bitn)       EAXSFR(),P6PU |=  (1<<bitn), EAXRAM()
#define PIN7_EnablePullUp(bitn)       EAXSFR(),P7PU |=  (1<<bitn), EAXRAM()

#define PIN0_DisablePullUp(bitn)       EAXSFR(),P0PU &=  ~(1<<bitn), EAXRAM()
#define PIN1_DisablePullUp(bitn)       EAXSFR(),P1PU &=  ~(1<<bitn), EAXRAM()
#define PIN2_DisablePullUp(bitn)       EAXSFR(),P2PU &=  ~(1<<bitn), EAXRAM()
#define PIN3_DisablePullUp(bitn)       EAXSFR(),P3PU &=  ~(1<<bitn), EAXRAM()
#define PIN4_DisablePullUp(bitn)       EAXSFR(),P4PU &=  ~(1<<bitn), EAXRAM()
#define PIN5_DisablePullUp(bitn)       EAXSFR(),P5PU &=  ~(1<<bitn), EAXRAM()
#define PIN6_DisablePullUp(bitn)       EAXSFR(),P6PU &=  ~(1<<bitn), EAXRAM()
#define PIN7_DisablePullUp(bitn)       EAXSFR(),P7PU &=  ~(1<<bitn), EAXRAM()

#define Pin_EnablePullUp(N, bitn)		PIN##N##_EnablePullUp(bitn)	
#define Pin_DisablePullUp(N, bitn)		PIN##N##_DisablePullUp(bitn)	


/*========================================================================================*/
/*========================================================================================*/
/*==================================GPIO�û�API===========================================*/
/*========================================================================================*/
/*========================================================================================*/

/*
	GPIO��ʼ����Ҫ���� 
	1. ȷ��IO����ģʽ                 
        	PIN_InitPushPull(0, 5)  //��ʼ��P05 �������ģʽ
			
	2. ȷ���Ƿ�����IO��4.1K�������� 
        	PIN_EnablePullUp(0, 5)  //P05 �ܽſ����ڲ�4.1K��������
*/



/*
PnM1    PnM0    I/O �ڹ���ģʽ
0        0      ׼˫��ڣ���ͳ8051�˿�ģʽ����������
                ������ɴ�20mA��������Ϊ270��150��A������������
				
0        1      ���������ǿ����������ɴ�20mA��Ҫ���������裩

1        0      �������루�����Ȳ�������Ҳ���������� ADC�ܽ�ʹ�ø�ģʽ

1        1      ��©����� Open-Drain�����ڲ���������Ͽ�
                ��©ģʽ�ȿɶ��ⲿ״̬Ҳ�ɶ���������ߵ�ƽ��͵�
                ƽ������Ҫ��ȷ���ⲿ״̬����Ҫ��������ߵ�ƽ�������
                �������裬����������ⲿ״̬��Ҳ�����䲻���ߵ�ƽ
*/

/**  
 * GPIO ��ʼ���궨��
 * N    :�ܽ�Port  ���� P20�ܽŵ�PortΪ 2
 * bitn :�ܽű��  ���� P20�ܽŵı��Ϊ 0
 * ���� PIN_InitPushPull(2, 5)  //��ʼ��P25 �������ģʽ
 */                   
#define PIN_InitStandard(N, bitn)		Pin_InitStandard(N, bitn)	/* 00  */
#define PIN_InitPushPull(N, bitn)		Pin_InitPushPull(N, bitn)	/* 01  */
#define PIN_InitPureInput(N, bitn)		Pin_InitPureInput(N, bitn)	/* 10  */
#define PIN_InitOpenDrain(N, bitn)		Pin_InitOpenDrain(N, bitn)	/* 11  */

#define P(N, bitn)                      PIn(N, bitn)


/**  
 * STC8G ϵ��ÿ��GPIO��������һ��4.1K����������  
 * bitn :�ܽű��
 * ���� PIN_EnablePullUp(0, 5)  //P05 �ܽſ����ڲ�4.1K��������
 */
#define PIN_EnablePullUp(N, bitn)       Pin_EnablePullUp(N, bitn)
#define PIN_DisablePullUp(N, bitn)      Pin_DisablePullUp(N, bitn)

/*========================================================================================*/
/*========================================================================================*/
/*==================================GPIO�ⲿ�ж�==========================================*/
/*========================================================================================*/
/*========================================================================================*/

/*
	STC8ֻ��5���ܽ����ⲿ�жϹ��� 
	INT0  �ⲿ�жϹܽ� P32  
	INT1  �ⲿ�жϹܽ� P33 
	INT2  �ⲿ�жϹܽ� P36 
	INT3  �ⲿ�жϹܽ� P37 
	INT4  �ⲿ�жϹܽ� P30 

	GPIO�ⲿ�жϳ�ʼ����Ҫ
	1. ȷ��IO����ģʽ  
	        PIN_InitStandard(3, 2);
			
	2. ȷ���Ƿ�����IO��4.1K��������
			PIN_EnablePullUp(3, 2);
			
	3. ȷ��GPIO �����жϷ�ʽ(INT0 INT1 ���������жϴ�����ʽ INT2 INT3 INT4 ֻ�����½��ش����ж�)
			INT0_Fall();
			
	4. �����ж����ȼ�(�����ж����ȼ� n��Χ�� 0-3  3���ȼ���ߣ����������Ĭ�����ȼ�0) 
			SET_INT0_PRIORITY(1);  //����INT0 �ж����ȼ�
	
	5. �����ж�
			INT0_Enable();
	
	6. ��д�жϷ�������INT2 INT3 INT4 ��Ҫ���жϷ�����������жϱ�־λ��(�жϷ�����Ĭ��д��irq.c��)
			void INT0Tnterrupt()   interrupt    0
			{
				
			}
			
*/

/* T0 T1 ���������жϴ�����ʽ T2 T3 T4 ֻ�����½��ش����ж� */
#define	INT0_Fall()		IT0 = 1		/* INT0 �½����ж�           */
#define	INT0_RiseFall()	IT0 = 0		/* INT0 �½��������ؾ��ж�   */
#define	INT1_Fall()		IT1 = 1		/* INT1 �½����ж�           */
#define	INT1_RiseFall()	IT0 = 0		/* INT1 �½��������ؾ��ж�   */


//                                     7    6    5    4    3     2       1       0      Reset Value
//INT_CLKO:  �ж���ʱ��������ƼĴ���  -   EX4  EX3  EX2   -   T2CLKO  T1CLKO  T0CLKO    0000,0000
#define	INT4_Enable()	INT_CLKO |= (1 << 6)
#define	INT3_Enable()	INT_CLKO |= (1 << 5)	
#define	INT2_Enable()	INT_CLKO |= (1 << 4)	
#define	INT1_Enable()	EX1 = 1
#define	INT0_Enable()	EX0 = 1

#define	INT4_Disable()	INT_CLKO &= ~(1 << 6)
#define	INT3_Disable()	INT_CLKO &= ~(1 << 5)	
#define	INT2_Disable()	INT_CLKO &= ~(1 << 4)	
#define	INT1_Disable()	EX1 = 0
#define	INT0_Disable()	EX0 = 0


//                               7    6       5       4      3    2     1     0      Reset Value
//AUXINTIF:  �����жϱ�־�Ĵ���  -  INT4IF  INT3IF  INT2IF   -   T4IF  T3IF  T2IF    0000,0000
#define	INT4IF	0x40
#define	INT3IF	0x20
#define	INT2IF	0x10


#define	INT4_Clear()	AUXINTIF &= ~INT4IF		/* ������ж�4��־λ ���ֶ���� */
#define	INT3_Clear()	AUXINTIF &= ~INT3IF		/* ������ж�3��־λ ���ֶ���� */
#define	INT2_Clear()	AUXINTIF &= ~INT2IF		/* ������ж�2��־λ ���ֶ���� */
#define	INT1_Clear()	IE1 = 0					/* ������ж�1��־λ Ӳ���Զ���� */
#define	INT0_Clear()	IE0 = 0					/* ������ж�0��־λ Ӳ���Զ���� */


#endif
