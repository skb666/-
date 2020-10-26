/*!
  * @file     lq_iic.c
  *
  * @brief    iic �����ļ�
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

#include "lq_iic.h"

/* �����ʱ���� */
uint8_t xdata iicSendLen = 0;


/* ��n���Ĵ���  
 * addr  �ӻ���ַ  MPU6050Ϊ0xD0
 * reg   �Ĵ���
 * buff  ��ȡ�Ĵ���ֵ��ŵĻ�����
 * len   ��ȡlen���Ĵ���
*/
void IIC_ReadMultReg(uint8_t addr, uint8_t reg, uint8_t* buff, uint8_t len)
{
	uint8_t xdata temp = 0;
	EAXSFR();
	I2c_Start();
	I2c_SendData(addr);
	I2c_GetAck(); 
	I2c_SendData(reg);
	I2c_GetAck(); 
	I2c_Start();
	I2c_SendData((addr+1));
	I2c_GetAck(); 
	for(iicSendLen = 0; iicSendLen < len; iicSendLen++)
	{
		I2c_GetData(temp);
		I2c_GetAck(); 
		*(buff + iicSendLen) = temp;
	}
	I2c_Stop();
	EAXRAM();
}

