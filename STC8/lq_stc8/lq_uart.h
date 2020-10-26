/*!
  * @file     lq_uart.h
  *
  * @brief    uart �����ļ�
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
#ifndef __LQ_UART_H
#define __LQ_UART_H

#include "stc8.h"
#include "intrins.h"
#include "lq_timer.h"
#include "lq_gpio.h"
#include "stdio.h"

/* �����ݴ涨ʱ����װ��ֵ */
extern volatile uint16_t  xdata timerReload;

/* ����æ��־λ */
extern volatile uint8_t   xdata uart1Busy;
extern volatile uint8_t   xdata uart2Busy;
extern volatile uint8_t   xdata uart3Busy;
extern volatile uint8_t   xdata uart4Busy;


/*========================================================================================*/
/*========================================================================================*/
/*===========================UART�ײ����� �û��������===================================*/
/*========================================================================================*/
/*========================================================================================*/

/* UART 8λ���� ����ģʽ */
#define Uart1_8Bit()        SM0 = 0, SM1 = 1
#define Uart1_9Bit()        SM0 = 1, SM1 = 1
#define Uart2_8Bit()        S2CON &= ~0x80
#define Uart2_9Bit()        S2CON |=  0x80
#define Uart3_8Bit()        S3CON &= ~0x80
#define Uart3_9Bit()        S3CON |=  0x80
#define Uart4_8Bit()        S4CON &= ~0x80
#define Uart4_9Bit()        S4CON |=  0x80

/* UART ����ʹ�� */
#define	Uart1_RxEnable()		REN = 1
#define	Uart1_RxDisable()		REN = 0
#define	Uart2_RxEnable()		S2CON |=  (1<<4)
#define	Uart2_RxDisable()		S2CON &= ~(1<<4)
#define	Uart3_RxEnable()		S3CON |=  (1<<4)
#define	Uart3_RxDisable()		S3CON &= ~(1<<4)
#define	Uart4_RxEnable()		S4CON |=  (1<<4)
#define	Uart4_RxDisable()		S4CON &= ~(1<<4)

/* UART ������ɱ�־ */
#define UART1_TxIsOk()          TI
#define UART2_TxIsOk()          (S2CON & 2) != 0
#define UART3_TxIsOk()          (S3CON & 2) != 0
#define UART4_TxIsOk()          (S4CON & 2) != 0

/* UART ������ɱ�־ */
#define UART1_RxIsOk()          RI
#define UART2_RxIsOk()          (S2CON & 1) != 0
#define UART3_RxIsOk()          (S3CON & 1) != 0
#define UART4_RxIsOk()          (S4CON & 1) != 0

/* UART ��������жϱ�־λ */
#define Uart1_TxClear()         TI = 0
#define Uart2_TxClear()         S2CON &= ~(1<<1)
#define Uart3_TxClear()         S3CON &= ~(1<<1)
#define Uart4_TxClear()         S4CON &= ~(1<<1)

/* UART ���÷����жϱ�־λ */
#define Uart1_TxSet()         TI = 1
#define Uart2_TxSet()         S2CON |= (1<<1)
#define Uart3_TxSet()         S3CON |= (1<<1)
#define Uart4_TxSet()         S4CON |= (1<<1)

/* UART ��������жϱ�־λ */
#define Uart1_RxClear()         RI = 0
#define Uart2_RxClear()         S2CON &= ~1
#define Uart3_RxClear()         S3CON &= ~1
#define Uart4_RxClear()         S4CON &= ~1

/* UART �����ж� */
#define	Uart1_InturruptEnable()		ES     =  1			/* ����1�����ж�									 */
#define	Uart1_InturruptDisable()	ES     =  0			/* ����1��ֹ�ж�                                     */
#define	Uart2_InturruptEnable()		IE2   |=  1			/* ����2�����ж�									 */
#define	Uart2_InturruptDisable()	IE2   &= ~1			/* ����2��ֹ�ж�                                     */
#define	Uart3_InturruptEnable()		IE2   |=  (1<<3)	/* ����3�����ж�									 */
#define	Uart3_InturruptDisable()	IE2   &= ~(1<<3)	/* ����3��ֹ�ж�                                     */
#define	Uart4_InturruptEnable()		IE2   |=  (1<<4)	/* ����4�����ж�									 */
#define	Uart4_InturruptDisable()	IE2   &= ~(1<<4)	/* ����4��ֹ�ж�                                     */

/* UART �����ʷ�����ѡ�� */
#define Uart1_UseTimer1()	AUXR  &= ~0x01
#define Uart1_UseTimer2()	AUXR  |=  0x01
#define Uart3_UseTimer2()	S3CON &= ~(1<<6)
#define Uart3_UseTimer3()	S3CON |=  (1<<6)
#define Uart4_UseTimer2()	S4CON &= ~(1<<6)
#define Uart4_UseTimer4()	S4CON |=  (1<<6)

#if (STC8A == 1)

/* UART1 �ܽ�ѡ�� RX TX*/
#define Uart1_UseP30P31()	P_SW1 &= 0x3f,                PIN3_InitPushPull(0),  PIN3_InitPushPull(1)
#define Uart1_UseP36P37()	P_SW1 &= 0x3f, P_SW1 |= 0x40, PIN3_InitPushPull(6),  PIN3_InitPushPull(7)
#define Uart1_UseP16P17()	P_SW1 &= 0x3f, P_SW1 |= 0x80, PIN1_InitPushPull(6),  PIN1_InitPushPull(7)
#define Uart1_UseP43P44()	P_SW1 &= 0x3f, P_SW1 |= 0xc0, PIN4_InitPushPull(3),  PIN4_InitPushPull(4)

/* UART2 �ܽ�ѡ�� RX TX*/
#define Uart2_UseP10P11()	P_SW2 &= 0xfe               , PIN1_InitPushPull(0),  PIN1_InitPushPull(1)
#define Uart2_UseP40P42()	P_SW2 &= 0xfe, P_SW2 |= 0x01, PIN4_InitPushPull(0),  PIN4_InitPushPull(2)

/* UART3 �ܽ�ѡ�� RX TX*/
#define Uart3_UseP00P01()	P_SW2 &= 0xfd               , PIN0_InitPushPull(0),  PIN0_InitPushPull(1)
#define Uart3_UseP50P51()	P_SW2 &= 0xfd, P_SW2 |= 0x02, PIN5_InitPushPull(0),  PIN5_InitPushPull(1)

/* UART4 �ܽ�ѡ�� RX TX*/
#define Uart4_UseP02P03()	P_SW2 &= 0xfb               , PIN0_InitPushPull(2),  PIN0_InitPushPull(3)
#define Uart4_UseP52P53()	P_SW2 &= 0xfb, P_SW2 |= 0x04, PIN5_InitPushPull(2),  PIN5_InitPushPull(3)

#else

/* UART1 �ܽ�ѡ�� RX TX*/
#define Uart1_UseP30P31()	P_SW1 &= 0x3f,                PIN3_InitStandard(0),  PIN3_InitStandard(1)
#define Uart1_UseP36P37()	P_SW1 &= 0x3f, P_SW1 |= 0x40, PIN3_InitStandard(6),  PIN3_InitStandard(7)
#define Uart1_UseP16P17()	P_SW1 &= 0x3f, P_SW1 |= 0x80, PIN1_InitStandard(6),  PIN1_InitStandard(7)
#define Uart1_UseP43P44()	P_SW1 &= 0x3f, P_SW1 |= 0xc0, PIN4_InitStandard(3),  PIN4_InitStandard(4)

/* UART2 �ܽ�ѡ�� RX TX*/
#define Uart2_UseP10P11()	P_SW2 &= 0xfe               , PIN1_InitStandard(0),  PIN1_InitStandard(1)
#define Uart2_UseP46P47()	P_SW2 &= 0xfe, P_SW2 |= 0x01, PIN4_InitStandard(6),  PIN4_InitStandard(7)

/* UART3 �ܽ�ѡ�� RX TX*/
#define Uart3_UseP00P01()	P_SW2 &= 0xfd               , PIN0_InitStandard(0),  PIN0_InitStandard(1)
#define Uart3_UseP50P51()	P_SW2 &= 0xfd, P_SW2 |= 0x02, PIN5_InitStandard(0),  PIN5_InitStandard(1)

/* UART4 �ܽ�ѡ�� RX TX*/
#define Uart4_UseP02P03()	P_SW2 &= 0xfb               , PIN0_InitStandard(2),  PIN0_InitStandard(3)
#define Uart4_UseP52P53()	P_SW2 &= 0xfb, P_SW2 |= 0x04, PIN5_InitStandard(2),  PIN5_InitStandard(3)

#endif

/* ���㶨ʱ���Զ�װ��ֵ timer    bpsΪ������ */
#define Get_Baud(timer, bps)     timer = 65536 - MAIN_Fosc/(4*bps)

/* ���ö�ʱ�� */
#define Timer0_SetBaud(bps)    Get_Baud(timerReload, bps), Timer0_AsTimer(),Timer0_1T(), Timer0_16bitAutoReload(),Timer0_InterruptDisable(),T0_Load(timerReload),Timer0_Run()
#define Timer1_SetBaud(bps)    Get_Baud(timerReload, bps), Timer1_AsTimer(),Timer1_1T(), Timer1_16bitAutoReload(),Timer1_InterruptDisable(),T1_Load(timerReload),Timer1_Run()
#define Timer2_SetBaud(bps)    Get_Baud(timerReload, bps), Timer2_AsTimer(),Timer2_1T(), Timer2_InterruptDisable(),T2_Load(timerReload),Timer2_Run()
#define Timer3_SetBaud(bps)    Get_Baud(timerReload, bps), Timer3_AsTimer(),Timer3_1T(), Timer3_InterruptDisable(),T3_Load(timerReload),Timer3_Run()
#define Timer4_SetBaud(bps)    Get_Baud(timerReload, bps), Timer4_AsTimer(),Timer4_1T(), Timer4_InterruptDisable(),T4_Load(timerReload),Timer4_Run()


/*========================================================================================*/
/*========================================================================================*/
/*=====================================UART �û� API =====================================*/
/*========================================================================================*/
/*========================================================================================*/

/*
	���ڳ�ʼ�� 
	1. ѡ��Ҫʹ�õ�UART �� TIMER
		UART1_InitTimer1P30P31(115200);   //��ʼ��UART1 ʹ��TIMER1��Ϊ�����ʷ����� P30 P31��ΪRX TX  ����������Ϊ115200
	
	2. �����ж����ȼ�(�����ж����ȼ� n��Χ�� 0-3  3���ȼ���ߣ����������Ĭ�����ȼ�0)
		SET_UART1_PRIORITY(1);
		
	3. ��д�жϷ�����(�жϷ�����Ĭ��д��irq.c��)
		void UART1_Interrupt()  interrupt 4
		{
			if(UART1_TxIsOk())
			{
				// ����һ���ַ�����ж�
				
				uart1Busy = 0;     //������ڷ��ͱ�־
				Uart1_TxClear();   //����жϱ�־λ
			}
			if(UART1_RxIsOk())
			{
				// ����һ���ַ�����ж�
				
				Uart1_RxClear();   //����жϱ�־λ
			}
		}
*/


/* ��ʼ�� UART1 ʹ�ö�ʱ��1��Ϊ�����ʷ����� ʹ��P30��ΪRx P31��ΪTx */
#define UART1_InitTimer1P30P31(bps)  Uart1_8Bit(), Uart1_RxEnable(), Uart1_UseTimer1(), Uart1_UseP30P31(), Timer1_SetBaud(bps),Uart1_InturruptEnable()
#define UART1_InitTimer1P36P37(bps)  Uart1_8Bit(), Uart1_RxEnable(), Uart1_UseTimer1(), Uart1_UseP36P37(), Timer1_SetBaud(bps),Uart1_InturruptEnable()
#define UART1_InitTimer1P16P17(bps)  Uart1_8Bit(), Uart1_RxEnable(), Uart1_UseTimer1(), Uart1_UseP16P17(), Timer1_SetBaud(bps),Uart1_InturruptEnable()
#define UART1_InitTimer1P43P44(bps)  Uart1_8Bit(), Uart1_RxEnable(), Uart1_UseTimer1(), Uart1_UseP43P44(), Timer1_SetBaud(bps),Uart1_InturruptEnable()
                                                                                                         
#define UART1_InitTimer2P30P31(bps)  Uart1_8Bit(), Uart1_RxEnable(), Uart1_UseTimer2(), Uart1_UseP30P31(), Timer2_SetBaud(bps),Uart1_InturruptEnable()
#define UART1_InitTimer2P36P37(bps)  Uart1_8Bit(), Uart1_RxEnable(), Uart1_UseTimer2(), Uart1_UseP36P37(), Timer2_SetBaud(bps),Uart1_InturruptEnable()
#define UART1_InitTimer2P16P17(bps)  Uart1_8Bit(), Uart1_RxEnable(), Uart1_UseTimer2(), Uart1_UseP16P17(), Timer2_SetBaud(bps),Uart1_InturruptEnable()
#define UART1_InitTimer2P43P44(bps)  Uart1_8Bit(), Uart1_RxEnable(), Uart1_UseTimer2(), Uart1_UseP43P44(), Timer2_SetBaud(bps),Uart1_InturruptEnable()

#define UART2_InitTimer2P10P11(bps)  Uart2_8Bit(), Uart2_RxEnable(), Uart2_UseTimer2(), Uart2_UseP10P11(), Timer2_SetBaud(bps),Uart2_InturruptEnable()
#if (STC8A == 1)  //STC8A ����2 �ܽź�STC8G/8H��ͬ
#define UART2_InitTimer2P40P42(bps)  Uart2_8Bit(), Uart2_RxEnable(), Uart2_UseTimer2(), Uart2_UseP40P42(), Timer2_SetBaud(bps),Uart2_InturruptEnable()
#else
#define UART2_InitTimer2P46547(bps)  Uart2_8Bit(), Uart2_RxEnable(), Uart2_UseTimer2(), Uart2_UseP46P47(), Timer2_SetBaud(bps),Uart2_InturruptEnable()
#endif

#define UART3_InitTimer2P00P01(bps)  Uart3_8Bit(), Uart3_RxEnable(), Uart3_UseTimer2(), Uart3_UseP00P01(), Timer2_SetBaud(bps),Uart3_InturruptEnable()
#define UART3_InitTimer2P50P51(bps)  Uart3_8Bit(), Uart3_RxEnable(), Uart3_UseTimer2(), Uart3_UseP50P51(), Timer2_SetBaud(bps),Uart3_InturruptEnable()

#define UART3_InitTimer3P00P01(bps)  Uart3_8Bit(), Uart3_RxEnable(), Uart3_UseTimer3(), Uart3_UseP00P01(), Timer3_SetBaud(bps),Uart3_InturruptEnable()
#define UART3_InitTimer3P50P51(bps)  Uart3_8Bit(), Uart3_RxEnable(), Uart3_UseTimer3(), Uart3_UseP50P51(), Timer3_SetBaud(bps),Uart3_InturruptEnable()

#define UART4_InitTimer2P02P03(bps)  Uart4_8Bit(), Uart4_RxEnable(), Uart4_UseTimer2(), Uart4_UseP02P03(), Timer2_SetBaud(bps),Uart4_InturruptEnable()
#define UART4_InitTimer2P52P53(bps)  Uart4_8Bit(), Uart4_RxEnable(), Uart4_UseTimer2(), Uart4_UseP52P53(), Timer2_SetBaud(bps),Uart4_InturruptEnable()

#define UART4_InitTimer4P02P03(bps)  Uart4_8Bit(), Uart4_RxEnable(), Uart4_UseTimer4(), Uart4_UseP02P03(), Timer4_SetBaud(bps),Uart4_InturruptEnable()
#define UART4_InitTimer4P52P53(bps)  Uart4_8Bit(), Uart4_RxEnable(), Uart4_UseTimer4(), Uart4_UseP52P53(), Timer4_SetBaud(bps),Uart4_InturruptEnable()

/* ����һ���ַ� ch */
#define UART1_PutChar(ch)            while (uart1Busy);  uart1Busy = 1;  SBUF = ch; while (uart1Busy);
#define UART2_PutChar(ch)            while (uart2Busy);  uart2Busy = 1;  S2BUF = ch; while (uart1Busy);
#define UART3_PutChar(ch)            while (uart3Busy);  uart3Busy = 1;  S3BUF = ch; while (uart1Busy);
#define UART4_PutChar(ch)            while (uart4Busy);  uart4Busy = 1;  S4BUF = ch; while (uart1Busy);
#define Uart_PutChar(n, ch)          UART##n##_PutChar(ch)

/**
 *  ����n ����һ���ַ� ch
 */
#define UART_PutChar(n, ch)          Uart_PutChar(n, ch)

/* ����һ���ַ� ch */
#define UART1_GetChar(ch)            ch = SBUF
#define UART2_GetChar(ch)            ch = S2BUF
#define UART3_GetChar(ch)            ch = S3BUF
#define UART4_GetChar(ch)            ch = S4BUF
#define Uart_GetChar(n, ch)          UART##n##_GetChar(ch)

/**
 *  ����n ����һ���ַ� ch
 */
#define UART_GetChar(n, ch)          Uart_GetChar(n, ch)


/*!
  * @brief    ��ӡ��֪���ȵ�����
  * 
  * @param    buff  �� Ҫ��ӡ���ַ�����ַ    
  * @param    len   �� Ҫ��ӡ�ĳ���
  *
  * @return   ��
  *
  * @note     ʹ��ǰ���ȳ�ʼ����Ӧ����
  *
  * @see      UART1_PutBuff("123456789",5);//ʵ�ʷ���5���ֽڡ�1����2����3����4����5��    
  *
  * @date     2019/10/21 ����һ
  */
void UART1_PutBuff(uint8_t *buff, uint16_t len);
void UART2_PutBuff(uint8_t *buff, uint16_t len);
void UART3_PutBuff(uint8_t *buff, uint16_t len);
void UART4_PutBuff(uint8_t *buff, uint16_t len);

/*!
  * @brief    ���ڴ�ӡ�ַ���
  *
  * @param    str   �� Ҫ��ӡ���ַ�����ַ 
  *
  * @return   ��
  *
  * @note     ʹ��ǰ���ȳ�ʼ����Ӧ����
  *
  * @see      UART1_PutStr("123456789"); //����9���ֽ�      
  *
  * @date     2019/10/21 ����һ
  */
void UART1_PutStr(uint8_t *str);
void UART2_PutStr(uint8_t *str);
void UART3_PutStr(uint8_t *str);
void UART4_PutStr(uint8_t *str);




#endif
