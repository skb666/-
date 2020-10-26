/*!
  * @file     irq.c
  *
  * @brief    �жϷ�����
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
#include "main.h"

/* STC8H�жϱ�
�ж�Դ    �ж�����    ����    ���ȼ�����    ���ȼ�    �ж�����λ    �ж�����λ
INT0       0003H        0      PX0PX0H      0/1/2/3       IE0          EX0
Timer0     000BH        1      PT0,PT0H     0/1/2/3     TF0            ET0
INT1       0013H        2      PX1,PX1H     0/1/2/3     IE1            EX1
Timer1     001BH        3      PT1,PT1H     0/1/2/3     TF1            ET1
UART1      0023H        4      PS,PSH       0/1/2/3     RI || TI       ES
ADC        002BH        5      PADC,PADCH   0/1/2/3     ADC_FLAG       EADC
LVD        0033H        6      PLVD,PLVDH   0/1/2/3     LVDF           ELVD
PCA        003BH        7      PPCA,PPCAH   0/1/2/3     CCF1           ECCF1
UART2      0043H        8      PS2,PS2H     0/1/2/3     S2RI || S2TI   ES2
SPI        004BH        9      PSPI,PSPIH   0/1/2/3     SPIF           ESPI
INT2       0053H        10                  0           INT2IF         EX2
INT3       005BH        11                  0           INT3IF         EX3
Timer2     0063H        12                  0           T2IF           ET2
INT4       0083H        16     PX4,PX4H     0/1/2/3     INT4IF         EX4
UART3      008BH        17     PS3,PS3H     0/1/2/3     S3RI || S3TI   ES3
UART4      0093H        18     PS4,PS4H     0/1/2/3     S4RI || S4TI   ES4
Timer3     009BH        19                  0           T3IF           ET3
Timer4     00A3H        20                  0           T4IF           ET4
CMP        00ABH        21     PCMP,PCMPH   0/1/2/3     CMPIF          PIE|NIE
I2C        00C3H        24     PI2C,PI2CH   0/1/2/3     RXIF           ERXI
USB        00CBH        25     PUSB,PUSBH   0/1/2/3     USB Events     EUSB
PWM1       00D3H        26     PPWM1,PPWM1H 0/1/2/3     PWM1_SR        PWM1_IER
PWM2       00DDH        27     PPWM2,PPWM2H 0/1/2/3     PWM2_SR        PWM2_IER
*/

// volatile float xdata a[3],w[3],angle[3],T;
extern void delayms(uint32_t ms);
volatile uint8_t xdata sign0 = 0, sign_k = 0;
volatile int xdata L_V = 0, R_V = 0;

/* �ⲿ�ж�0 �жϷ����� */
void INT0Tnterrupt()   interrupt    0
{
	/* �û����� */
	if(INT0){
		if(R_B){
			R_V++;
		}else{
			R_V--;
		}
	}else{
		if(R_B){
			R_V--;
		}else{
			R_V++;
		}
	}
}

/* �ⲿ�ж�1 �жϷ����� */
void INT1Tnterrupt()   interrupt    2
{
	/* �û����� */
	if(INT1){
		if(R_A){
			R_V--;
		}else{
			R_V++;
		}
	}else{
		if(R_A){
			R_V++;
		}else{
			R_V--;
		}
	}
}

/* �ⲿ�ж�2 �жϷ����� */
void INT2Tnterrupt()   interrupt    10
{
	/* �û����� */
	INT2_Clear();
}

/* �ⲿ�ж�3 �жϷ����� */
void INT3Tnterrupt()   interrupt    11
{
	/* �û����� */
	INT3_Clear();
}

/* �ⲿ�ж�4 �жϷ����� */
void INT4Tnterrupt()   interrupt    16
{
	/* �û����� */
	sign_k = 1;
	INT4_Clear();
}

volatile uint32_t xdata msysTick = 0;
volatile uint32_t xdata msysTime = 0;
/* ��ʱ��0 �жϷ����� */
void TIMER0_Tnterrupt() interrupt    1
{
	/* �û����� */
	s_timerCounter++;
	msysTime = TIMER0_GetUs() - msysTick;
	if(msysTime > 5000UL){			// 5ms
		msysTick = TIMER0_GetUs();
		sign0 = 1;
	}
}

/* ��ʱ��1 �жϷ����� */
void TIMER1_Tnterrupt() interrupt    3
{
	/* �û����� */
	
}

/* ��ʱ��2 �жϷ����� */
void TIMER2_Tnterrupt() interrupt    12
{
	/* �û����� */
	TIMER2_Clear();
}

volatile uint32_t xdata tim3 = 0;
/* ��ʱ��3 �жϷ����� */
void TIMER3_Tnterrupt() interrupt    19
{
	/* �û����� */
	TIMER3_Clear();
}

/* ��ʱ��4 �жϷ����� */
void TIMER4_Tnterrupt() interrupt    20
{
	/* �û����� */
	TIMER4_Clear();
}

/* UART1 �жϷ����� */
void UART1_Interrupt()  interrupt 4
{
	if(UART1_TxIsOk())
	{
		// ����һ���ַ�����ж�
		/* �û����� */
		
		uart1Busy = 0;     //������ڷ��ͱ�־
		Uart1_TxClear();   //����жϱ�־λ
	}
	if(UART1_RxIsOk())
	{
		// ����һ���ַ�����ж�
		/* �û����� */
		
		Uart1_RxClear();   //����жϱ�־λ
	}
}

/* UART2 �жϷ����� */
void UART2_Interrupt()  interrupt 8
{
	if(UART2_TxIsOk())
	{
		// ����һ���ַ�����ж�
		/* �û����� */
		
		uart2Busy = 0;     //������ڷ��ͱ�־
		Uart2_TxClear();   //����жϱ�־λ
	}
	if(UART2_RxIsOk())
	{
		// ����һ���ַ�����ж�
		/* �û����� */
		
		Uart2_RxClear();   //����жϱ�־λ
	}
}

volatile uint8_t xdata bt_ch[60],cnt=0;
float xdata rx_float[13];
int xdata rx_int[2];
uint8_t f_sw=0;

/* UART3 �жϷ����� */
void UART3_Interrupt()  interrupt 17
{
	if(UART3_TxIsOk())
	{
		// ����һ���ַ�����ж�
		/* �û����� */
		
		uart3Busy = 0;     //������ڷ��ͱ�־
		Uart3_TxClear();   //����жϱ�־λ
	}
	if(UART3_RxIsOk())
	{
		// ����һ���ַ�����ж�
		/* �û����� */

		UART3_GetChar(bt_ch[cnt]);
		if(cnt == 0 && bt_ch[0] != 0xa5){
			Uart3_RxClear();
			return;
		}else{
			cnt++;
			if(cnt == 60){
				cnt=0;
				if(bt_ch[0] == 0xa5 && bt_ch[59] == 0x5a){
					f_sw = bt_ch[1];
					UnPacket(sizeof(int), 2, bt_ch+2, (void *)rx_int);
					UnPacket(sizeof(float), 13, bt_ch+6, (void *)rx_float);
					EEPROM_W_SW = f_sw&0x01;
					EEPROM_R_SW = f_sw&0x02;
					Stand_SW 	= f_sw&0x04;
					Speed_SW 	= f_sw&0x08;
					Turn_SW 	= f_sw&0x10;
					ADC_SW 		= f_sw&0x20;
					Stop_Sign 	= f_sw&0x40;
					RK_Sign 	= f_sw&0x80;
					Stand_Set 	= rx_float[0];
					Stand_P 	= rx_float[1];
					Stand_D 	= rx_float[2];
					Speed_New 	= rx_float[3];
					Speed_P 	= rx_float[4];
					Speed_I 	= rx_float[5];
					Turn_Set 	= rx_float[6];
					Turn_P 		= rx_float[7];
					Turn_D 		= rx_float[8];
					ADC_H_Set 	= rx_int[0];
					ADC_H_P 	= rx_float[9];
					ADC_H_D 	= rx_float[10];
					ADC_Set 	= rx_int[1];
					ADC_P 		= rx_float[11];
					ADC_D 		= rx_float[12];
				}
			}
		}
		
		Uart3_RxClear();   //����жϱ�־λ
	}
}

//volatile unsigned char xdata Re_buf[11],counter=0;
/* UART1 �жϷ����� */
void UART4_Interrupt()  interrupt 18
{
	if(UART4_TxIsOk())
	{
		// ����һ���ַ�����ж�
		/* �û����� */
		
		uart4Busy = 0;     //������ڷ��ͱ�־
		Uart4_TxClear();   //����жϱ�־λ
	}
	if(UART4_RxIsOk())
	{
		// ����һ���ַ�����ж�
		/* �û����� */
		
//		UART4_GetChar(Re_buf[counter]);
//		if(counter==0&&Re_buf[0]!=0x55){
//			Uart4_RxClear();
//			return;
//		}else{
//			counter++;
//			if(counter==11){
//				counter=0;
//				if(Re_buf[0]==0x55){
//					switch(Re_buf[1]){
//					case 0x51:
//						a[0] = ((short)(Re_buf[3]<<8| Re_buf[2]))/32768.0*16;
//						a[1] = ((short)(Re_buf[5]<<8| Re_buf[4]))/32768.0*16;
//						a[2] = ((short)(Re_buf[7]<<8| Re_buf[6]))/32768.0*16;
//						T = ((short)(Re_buf [9]<<8| Re_buf [8]))/340.0+36.25;
//						break;
//					case 0x52:
//						w[0] = ((short)(Re_buf[3]<<8| Re_buf[2]))/32768.0*2000;
//						w[1] = ((short)(Re_buf[5]<<8| Re_buf[4]))/32768.0*2000;
//						w[2] = ((short)(Re_buf[7]<<8| Re_buf[6]))/32768.0*2000;
//						T = ((short)(Re_buf[9]<<8| Re_buf[8]))/340.0+36.25;
//						break;
//					case 0x53:
//						angle[0] = ((short)(Re_buf[3]<<8| Re_buf[2]))/32768.0*180;
//						angle[1] = ((short)(Re_buf[5]<<8| Re_buf[4]))/32768.0*180;
//						angle[2] = ((short)(Re_buf[7]<<8| Re_buf[6]))/32768.0*180;
//						T = ((short)(Re_buf[9]<<8| Re_buf[8]))/340.0+36.25;
//						break;
//					}
//				}
//			}
//		}
		
		Uart4_RxClear();   //����жϱ�־λ
	}
}

/* ��ʱ��1 �жϷ����� */
void ADC_Tnterrupt() interrupt    5
{
	/* �û����� */
	ADC_Clear();           //����жϱ�־λ
}

/* �����жϷ�������������Ҫ ��������� */
void PCA_Isr() interrupt 7
{
	if(CCF1){
		if(L_A && L_B){
			L_V--;
		}else if(L_A && 0==L_B){
			L_V++;
		}
		if(0==L_A && L_B){
			L_V++;
		}else if(0==L_A && 0==L_B){
			L_V--;
		}
		CCF1 = 0;
	}
	if(CCF2){
		if(L_B && L_A){
			L_V++;
		}else if(L_B && 0==L_A){
			L_V--;
		}
		if(0==L_B && L_A){
			L_V--;
		}else if(0==L_B && 0==L_A){
			L_V++;
		}
		CCF2 = 0;
	}
}

