/*!
  * @file     LQ_SOFTIIC.h
  *
  * @brief    ģ��IIC�����ļ�
  *
  * @company  �����������ܿƼ�
  *
  * @author   LQ-005
  *
  * @note     ��
  *
  * @version  V1.1  2019/12/06 �Ż�ע�� Doxygen
  *
  * @par URL  http://shop36265907.taobao.com
  *           http://www.lqist.cn
  *
  * @date     2019/10/23 ������
  */ 
#ifndef __LQ_SOFTIIC_H
#define __LQ_SOFTIIC_H

#include "lq_gpio.h"

/* ע�� IIC���߹涨��IIC����ʱ SCL��SDA��Ϊ�ߵ�ƽ ����ⲿ������һ������������ */
/* ģ�� IIC��Ҫע�⣬IIC��ַ����һλ ����MPU6050 ģ����ǵ�ַ 0xD0 */
/* �뻻�ñ��IO ֱ���޸ĺ궨�� SOFT_IIC_SCL_PIN �� SOFT_IIC_SDA_PIN ���� */

#if (STC8A == 1)
#define SOFT_IIC_SCL_PORT  2
#define SOFT_IIC_SCL_PIN   5   /*!< P25  ��Ϊ SCL */

#define SOFT_IIC_SDA_PORT  2
#define SOFT_IIC_SDA_PIN   4   /*!< P24  ��Ϊ SDA */

#else
#define SOFT_IIC_SCL_PORT  1
#define SOFT_IIC_SCL_PIN   0   /*!< P15  ��Ϊ SCL */

#define SOFT_IIC_SDA_PORT  1
#define SOFT_IIC_SDA_PIN   1   /*!< P14  ��Ϊ SDA */

#endif

#define SDA_OUT            PIN_InitPushPull(SOFT_IIC_SDA_PORT, SOFT_IIC_SDA_PIN);
#define SDA_IN             PIN_InitPureInput(SOFT_IIC_SDA_PORT, SOFT_IIC_SDA_PIN);

#define IIC_SCL_INIT   PIN_InitOpenDrain(SOFT_IIC_SCL_PORT, SOFT_IIC_SCL_PIN);    PIN_EnablePullUp(SOFT_IIC_SCL_PORT, SOFT_IIC_SCL_PIN); 
#define IIC_SDA_INIT   PIN_InitOpenDrain(SOFT_IIC_SDA_PORT, SOFT_IIC_SDA_PIN);    PIN_EnablePullUp(SOFT_IIC_SDA_PORT, SOFT_IIC_SDA_PIN); 

#define IIC_SCL_H      P(SOFT_IIC_SCL_PORT, SOFT_IIC_SCL_PIN) = 1;
#define IIC_SCL_L      P(SOFT_IIC_SCL_PORT, SOFT_IIC_SCL_PIN) = 0;

#define IIC_SDA_H      P(SOFT_IIC_SDA_PORT, SOFT_IIC_SDA_PIN) = 1;
#define IIC_SDA_L      P(SOFT_IIC_SDA_PORT, SOFT_IIC_SDA_PIN) = 0;

#define IIC_SDA_READ   P(SOFT_IIC_SDA_PORT, SOFT_IIC_SDA_PIN)


/*---------------------------------------------------------------
            IIC�ڲ�����
----------------------------------------------------------------*/		 
void IIC_Start(void);			        //����IIC��ʼ�ź�
void IIC_Stop(void);	  	            //����IICֹͣ�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
void IIC_NAck(void);				    //IIC������ACK�ź�
uint8_t IIC_WaitAck(void); 		        //IIC�ȴ�ACK�ź�
void IIC_SendByte(uint8_t data_t);        //IIC����һ���ֽ�
uint8_t IIC_ReadByte(uint8_t ack);       //IIC��ȡһ���ֽ�


/*---------------------------------------------------------------
            IIC�û�����
----------------------------------------------------------------*/
/*!
  * @brief    ģ��IIC��ʼ��
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note     ��
  *
  * @see      IIC_Init();  //ģ��IIC��ʼ�� IIC�ܽ���LQ_SOFTIIC.h�ж���
  *
  * @date     2019/10/23 ������
  */
void IIC_Init(void);                    

/*!
  * @brief    ģ��IIC��ȡָ���豸 ָ���Ĵ�����һ��ֵ
  *
  * @param    I2C_Addr  Ŀ���豸��ַ
  * @param    reg       Ŀ��Ĵ���
  * @param    buf       ��Ŷ����ֽ�
  *
  * @return   1ʧ�� 0�ɹ�
  *
  * @note     ��
  *
  * @see      uint8_t data;  
  * @see      IIC_ReadByteFromSlave(0xD0, 0x75, &data);   //�� IIC��ַΪ 0xD0������MPU6050���Ĵ���0x75
  *
  * @date     2019/10/23 ������
  */	
uint8_t IIC_ReadByteFromSlave(uint8_t I2C_Addr,uint8_t reg,uint8_t *buf);

/*!
  * @brief    ģ��IIC��ȡָ���豸 ָ���Ĵ�����n��ֵ
  *
  * @param    dev       Ŀ���豸��ַ
  * @param    reg       Ŀ��Ĵ���
  * @param    length    ��ȡ����
  * @param    data      ��Ŷ�������
  *
  * @return   1ʧ�� 0�ɹ�
  *
  * @note     ��
  *
  * @see      uint8_t data[14];  
  * @see      IIC_ReadByteFromSlave(0xD0, 0X3B, 14, &data);   //�� 14���ֽ�
  *
  * @date     2019/10/23 ������
  */
uint8_t IIC_ReadMultByteFromSlave(uint8_t dev, uint8_t reg, uint8_t length, uint8_t *data_t);

/*!
  * @brief    ģ��IICдָ���豸 ָ���Ĵ�����һ��ֵ
  *
  * @param    I2C_Addr  Ŀ���豸��ַ
  * @param    reg       Ŀ��Ĵ���
  * @param    data      д�������
  *
  * @return   1ʧ�� 0�ɹ�
  *
  * @note     ��
  *
  * @see      IIC_ReadByteFromSlave(0xD0, 0X6B, 0X80);   //IIC��ַΪ 0xD0������MPU6050���Ĵ���0x6B д��0x80
  *
  * @date     2019/10/23 ������
  */
uint8_t IIC_WriteByteToSlave(uint8_t I2C_Addr,uint8_t reg,uint8_t buf);

/*!
  * @brief    ģ��IICдָ���豸 ָ���Ĵ�����n��ֵ
  *
  * @param    dev       Ŀ���豸��ַ
  * @param    reg       Ŀ��Ĵ���
  * @param    length    д�볤��
  * @param    data      ���д������
  *
  * @return   1ʧ�� 0�ɹ�
  *
  * @note     ��
  *
  * @see      IIC_WriteMultByteToSlave(0xD0, 0X6B, 1, 0X80);   //��Ĵ���0x6Bд��0x80
  *
  * @date     2019/10/23 ������
  */
uint8_t IIC_WriteMultByteToSlave(uint8_t dev, uint8_t reg, uint8_t length, uint8_t* data_t);

#endif
