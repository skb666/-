/*!
  * @file     lq_spi.c
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
#include "lq_spi.h"
  
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
uint8_t  SPI_ReadWriteNByte(uint8_t *txData, uint8_t *rxData, uint8_t len)
{
#if (STC8A== 1)
	SPI_SS_1 = 0;
#else
	SPI_SS_4 = 0;
#endif
	while(len--)
	{
		SPDAT = *txData++;
		SPI_Wait();
		*rxData++ = SPDAT;
	}
#if (STC8A== 1)
	SPI_SS_1 = 1;
#else
	SPI_SS_4 = 1;
#endif
	return 0;
}
  