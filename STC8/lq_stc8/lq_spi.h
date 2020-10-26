/*!
  * @file     lq_spi.h
  *
  * @brief    spi �����ļ�
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
  
#ifndef __LQ_SPI_H
#define __LQ_SPI_H
  
#include "stc8.h"
#include "lq_gpio.h"

/*========================================================================================*/
/*========================================================================================*/
/*===========================SPI�ײ����� �û��������=====================================*/
/*========================================================================================*/
/*========================================================================================*/
//sfr SPCTL  = 0xCE;	SPI���ƼĴ���
//   7       6       5       4       3       2       1       0    	Reset Value
//	SSIG	SPEN	DORD	MSTR	CPOL	CPHA	SPR1	SPR0		0x00

#define	SPI_SSIG_None()		SPCTL |=  (1<<7)		/* 1: ����SS��	*/
#define	SPI_SSIG_Enable()	SPCTL &= ~(1<<7)		/* 0: SS�����ھ������ӻ�	*/
#define	SPI_Enable()		SPCTL |=  (1<<6)		/* 1: ����SPI	*/
#define	SPI_Disable()		SPCTL &= ~(1<<6)		/* 0: ��ֹSPI	*/
#define	SPI_LSB_First()		SPCTL |=  (1<<5)		/* 1: LSB�ȷ�	*/
#define	SPI_MSB_First()		SPCTL &= ~(1<<5)		/* 0: MSB�ȷ�	*/
#define	SPI_Master()		SPCTL |=  (1<<4)		/* 1: ��Ϊ����	*/
#define	SPI_Slave()			SPCTL &= ~(1<<4)		/* 0: ��Ϊ�ӻ�	*/
#define	SPI_SCLK_NormalH()	SPCTL |=  (1<<3)		/* 1: ����ʱSCLKΪ�ߵ�ƽ	*/
#define	SPI_SCLK_NormalL()	SPCTL &= ~(1<<3)		/* 0: ����ʱSCLKΪ�͵�ƽ	*/
#define	SPI_PhaseH()		SPCTL |=  (1<<2)		/* 1: ������ SCLK ��ǰʱ������������ʱ���ز���	*/
#define	SPI_PhaseL()		SPCTL &= ~(1<<2)		/* 0: ���� SS �ܽ�Ϊ�͵�ƽ������һλ���ݲ��� SCLK �ĺ�ʱ���ظı����ݣ�ǰʱ���ز������ݣ����� SSIG�� 0	*/
#define	SPI_Speed(n)		SPCTL = (SPCTL & ~3) | (n)	/*�����ٶ�, 0 -- fosc/4, 1 -- fosc/8, 2 -- fosc/16, 3 -- fosc/32	*/
                                                
//sfr SPSTAT  = 0xCD;	//SPI״̬�Ĵ���
//   7       6      5   4   3   2   1   0    	Reset Value
//	SPIF	WCOL	-	-	-	-	-	-
#define	SPIF	0x80		/* SPI������ɱ�־��д��1��0��*/
#define	WCOL	0x40		/* SPIд��ͻ��־��д��1��0��  */
/* ����жϱ�־λ */
#define     SPI_Clear()             SPSTAT |= SPIF

/* SPI �ȴ�������� */
#define     SPI_Wait()              while (!(SPSTAT & 0x80)); SPSTAT = 0xc0;

#define		SPI_USE_P12P13P14P15()	P_SW1 &= ~0x0c,	PIN1_InitStandard(2), PIN1_InitStandard(3), PIN1_InitStandard(4), PIN1_InitStandard(5)				/* ��SPI�л���P12(SS) P13(MOSI) P14(MISO) P15(SCLK)(�ϵ�Ĭ��)��*/
#define		SPI_USE_P22P23P24P25()	P_SW1 &= ~0x0c, P_SW1 |= (1<<3),	  PIN2_InitStandard(2), PIN2_InitStandard(3), PIN2_InitStandard(4), PIN2_InitStandard(5)	/* ��SPI�л���P22(SS) P23(MOSI) P24(MISO) P25(SCLK)��*/
#define		SPI_USE_P54P40P41P43()	P_SW1 &= ~0x0c, P_SW1 |= (1<<4),	  PIN5_InitStandard(4), PIN4_InitStandard(0), PIN4_InitStandard(1), PIN4_InitStandard(3)	/* ��SPI�л���P54(SS) P40(MOSI) P41(MISO) P43(SCLK)��*/
#define		SPI_USE_P35P34P33P32()	P_SW1 |= 0x0c ,	PIN3_InitStandard(5), PIN3_InitStandard(4), PIN3_InitStandard(3), PIN3_InitStandard(2)              /* ��SPI�л���P35(SS) P34(MOSI) P33(MISO) P32(SCLK)��*/

//							7     6     5    4    3    2    1     0    Reset Value
//sfr IE2       = 0xAF;		-     -     -    -    -    -   ESPI  ES2   0000,0000B	//Auxiliary Interrupt   
#define		SPI_INT_ENABLE()		IE2 |=  2	/* ����SPI�ж�		*/
#define		SPI_INT_DISABLE()		IE2 &= ~2	/* ��ֹSPI�ж�		*/









/*========================================================================================*/
/*========================================================================================*/
/*===================================SPI �û�API =========================================*/
/*========================================================================================*/
/*========================================================================================*/

/*��ʼ�� SPI   bspΪSPI�ٶ� �����ٶ�, 0 -- MAIN_Fosc/4, 1 -- MAIN_Fosc/8, 2 -- MAIN_Fosc/16, 3 -- MAIN_Fosc/32	
  * @param      mode            0: CLK����ʱ��Ϊ�͵�ƽ �ڵ�һ��CLK������ ��������
  * @param      mode            1: CLK����ʱ��Ϊ�͵�ƽ �ڵڶ���CLK������ ��������
  * @param      mode            2: CLK����ʱ��Ϊ�ߵ�ƽ �ڵ�һ��CLK������ ��������
  * @param      mode            3: CLK����ʱ��Ϊ�ߵ�ƽ �ڵڶ���CLK������ �������� */
#define     SPI_InitP12P13P14P15(bsp, mode)   SPI_USE_P12P13P14P15();SPI_SSIG_None();SPI_Enable();SPI_INT_DISABLE();SPI_MSB_First();SPI_Master();if(mode/2 == 1){SPI_SCLK_NormalH();} else {SPI_SCLK_NormalL();}if(mode%2 == 1) SPI_PhaseH(); else SPI_PhaseL();SPI_Speed(bsp);SPI_SS_1 = 0;
#define     SPI_InitP22P23P24P25(bsp, mode)   SPI_USE_P22P23P24P25();SPI_SSIG_None();SPI_Enable();SPI_INT_DISABLE();SPI_MSB_First();SPI_Master();if(mode/2 == 1){SPI_SCLK_NormalH();} else {SPI_SCLK_NormalL();}if(mode%2 == 1) SPI_PhaseH(); else SPI_PhaseL();SPI_Speed(bsp);SPI_SS_2 = 0;
#if (STC8A != 1)  //STC8A SPIû����������ܽ�
#define     SPI_InitP54P40P41P43(bsp, mode)   SPI_USE_P54P40P41P43();SPI_SSIG_None();SPI_Enable();SPI_INT_DISABLE();SPI_MSB_First();SPI_Master();if(mode/2 == 1){SPI_SCLK_NormalH();} else {SPI_SCLK_NormalL();}if(mode%2 == 1) SPI_PhaseH(); else SPI_PhaseL();SPI_Speed(bsp);SPI_SS_3 = 0;
#endif
#define     SPI_InitP35P34P33P32(bsp, mode)   SPI_USE_P35P34P33P32();SPI_SSIG_None();SPI_Enable();SPI_INT_DISABLE();SPI_MSB_First();SPI_Master();if(mode/2 == 1){SPI_SCLK_NormalH();} else {SPI_SCLK_NormalL();}if(mode%2 == 1) SPI_PhaseH(); else SPI_PhaseL();SPI_Speed(bsp);SPI_SS_4 = 0;


/**
  * @brief    SPI��дN���ֽ�
  *
  * @param    txData  ��  д���buff
  * @param    rxData  ��  ������buff
  * @param    len     ��  ����
  *
  * @return   ��
  *
  * @note     ��
  *
  * @see      uint8_t tbuff[2], rbuff[2];
  * @see      SPI_ReadWriteNByte(tbuff, rbuff, 2); //ʹ��SPI ��д�����ֽ� 
  *
  * @date     2019/6/3 ����һ
  */
uint8_t  SPI_ReadWriteNByte(uint8_t *txData, uint8_t *rxData, uint8_t len);

#endif
