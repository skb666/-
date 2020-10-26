/*!
  * @file     test_eeprom.c
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
#include "stdio.h"
#include "test_eeprom.h"
#include "lq_uart.h"
#include "lq_eeprom.h"


/**
  * @brief    �����ڲ�EEPROM  
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note     ע��  оƬ�ڲ�EEPROM��С ��ISP����������� �ӵ�ַ0x0000��ʼ  
  *
  * @example  
  *
  * @date     2019/4/22 ����һ
*/
void Test_EEPROM()
{
	uint8_t xdata i = 0;
	
	/* ��� eeprom ��ȡ����ֵ */
	uint8_t pdata u8rData[8];
	uint32_t pdata u32rData[8];
	float pdata frData[8];
	
	/* ��� eeprom ��Ҫд���ֵ */
	uint8_t xdata u8wData[8];
	uint32_t xdata u32wData[8];
	float xdata fwData[8];
	
	/* ���ڳ�ʼ�� ������ӡ */
	UART1_InitTimer1P30P31(115200);
	
	/* ע�� д��֮ǰ��Ҫ�Ȳ��� */
	EEPROM_Erase(0x0000);   //��������
	
	/* ��д��ֵ���и�ֵ */
	for(i = 0; i < 8; i++)
	{
		u8wData[i]  = 3 * i;
		u32wData[i] = 30 * i;
		fwData[i]   = 3.5f * i;
	}
	
	/* д��u8 */
	for(i = 0; i < 8; i++)
	{
		EEPROM_Write(0x0000 + i, u8wData[i]);
	}
	
	/* д��u32 */
	for(i = 0; i < sizeof(u32wData); i++)
	{
		EEPROM_Write(0x0008 + i, ((uint8_t *)u32wData)[i]);
	}
	
	/* д��float */
	for(i = 0; i < sizeof(fwData); i++)
	{
		EEPROM_Write(0x0040 + i, ((uint8_t *)fwData)[i]);
	}
	
	/* ��ȡu8 */
	for(i = 0; i < 8; i++)
	{
		EEPROM_Read(0x0000 + i, u8rData[i]);
	}
	
	/* ��ȡu32 */
	for(i = 0; i < sizeof(u32wData); i++)
	{
		EEPROM_Read(0x0008 + i, ((uint8_t *)u32rData)[i]);
	}
	
	/* ��ȡfloat */
	for(i = 0; i < sizeof(fwData); i++)
	{
		EEPROM_Read(0x0040 + i, ((uint8_t *)frData)[i]);
	}

	/* �Ƚ�д��Ͷ�ȡ */
	for(i = 0; i < 8; i++)
	{
		if(u8rData[i] != u8wData[i])
		{
			printf(" u8 error : %d \r\n", (int)u8rData[i]);
			printf(" eeprom ��д���� \r\n");
		}else{
			printf("%d\r\n", (int)u8rData[i]);
		}
	}

	/* �Ƚ�д��Ͷ�ȡ */
	for(i = 0; i < 8; i++)
	{
		if(u32rData[i] != u32wData[i])
		{
			printf(" u32 error : %ld \r\n", u32rData[i]);
			printf(" eeprom ��д���� \r\n");
		}else{
			printf("%ld\r\n", u32rData[i]);
		}
	}

	/* �Ƚ�д��Ͷ�ȡ */
	for(i = 0; i < 8; i++)
	{
		if(frData[i] != fwData[i])
		{
			printf(" float error : %f \r\n", frData[i]);
			printf(" eeprom ��д���� \r\n");
		}else{
			printf("%f\r\n", frData[i]);
		}
	}
	
	printf(" eeprom ���Խ��� \r\n");
}

