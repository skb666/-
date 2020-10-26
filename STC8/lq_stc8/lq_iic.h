/*!
  * @file     lq_iic.h
  *
  * @brief    iic �����ļ�
  *
  * @company  �����������ܿƼ�
  *
  * @author   LQ-005
  *
  * @note     Ӳ��IIC�ٶ�ʵ��ֻ�� 100K
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
  
#ifndef __LQ_IIC_H
#define __LQ_IIC_H
  
#include "reg51.h"
#include "lq_gpio.h"

/* �����ʱ���� */
extern uint8_t xdata iicSendLen;

/* ע�� ����IIC�Ĵ���ʱ ��Ҫ �ȿ��� EAXSFR()  ������ɺ� EAXRAM() */


/*========================================================================================*/
/*========================================================================================*/
/*===========================IIC�ײ����� �û��������=====================================*/
/*========================================================================================*/
/*========================================================================================*/
/* IIC����ʹ�� */
#define    I2c_Enable()             I2CCFG |=  0x80
#define    I2c_Disable()            I2CCFG &= ~0x80
							      
/* IIC����ģʽ */                 
#define    I2c_Master()             I2CCFG |=  0x40
#define    I2c_Slave()              I2CCFG &= ~0x40

/* IIC ʱ��  MAIN_Fosc/2/(div * 2 + 1)  bps ������ */
#define    I2c_SetDiv(bps)          I2CCFG &= 0x3F; //if((MAIN_Fosc/24/bps - 2) > 0x3f) I2CCFG |= 0x3f; else I2CCFG |= (MAIN_Fosc/24/bps - 2);

/* IIC �ж� ʹ�� */
#define    I2c_InterruptEnable()    I2CMSCR |= 0x80
#define    I2c_InterruptDisable()   I2CMSCR &= ~0x80

/* IIC �Զ����� ���Զ����͹��ܱ�ʹ�ܣ��� MCU ִ����ɶ� I2CTXD ���ݼĴ�����д������ I2C ���������Զ�
������ 1010��������Զ��������ݲ����� ACK �źš�*/
#define    I2c_EnableWdta()         I2CMSAUX |= 1

/* ����жϱ�־λ */
#define    I2c_Clear()              I2CMSST &= ~(1<<6)

/* IIC �ȴ�������� */
#define    I2c_Wait()               while (!(I2CMSST & 0x40)); I2CMSST &= ~0x40;

/* ����ACK */
#define    I2c_GetAck()             I2CMSCR = 0x03; I2c_Wait(); 

/* ����ACK    */
#define    I2c_SendAck()            I2CMSST = 0x00; I2CMSCR = 0x05; I2c_Wait()

/* ����NACK    */
#define    I2c_SendNAck()           I2CMSST = 0x01; I2CMSCR = 0x05; I2c_Wait()

/* IIC ����һ������ */
#define    I2c_SendData(n)          I2CTXD = n; I2CMSCR = 0x02; I2c_Wait()

/* IIC ����һ������ ������ACK0 */
#define    I2c_GetData(n)           I2CMSCR = 0x04; I2c_Wait(); n = I2CRXD


/* IIC ��ʼ�ź� */
#define    I2c_Start()                  I2CMSCR = 0x01; I2c_Wait()
									    
/* IIC ֹͣ�ź� */                      
#define    I2c_Stop()                   I2CMSCR = 0x06; I2c_Wait()


/*========================================================================================*/
/*========================================================================================*/
/*===========================     IIC �û�API   ==========================================*/
/*========================================================================================*/
/*========================================================================================*/
/*



*/
/* IIC��ʼ�� SCL SDA  bsp��IIC������ */
#define  IIC_InitP15P14(bps)      P_SW2 &= ~0x30; PIN1_InitStandard(5); PIN1_InitStandard(4); EAXSFR(); I2CCFG = 0; I2c_SetDiv(bps); I2c_Enable() ; I2c_Master();  I2CMSST = 0; EAXRAM()
#define  IIC_InitP25P24(bps)      P_SW2 |= 0x10 ; PIN2_InitStandard(5); PIN2_InitStandard(4); EAXSFR(); I2CCFG = 0; I2c_SetDiv(bps); I2c_Enable() ; I2c_Master();  I2CMSST = 0; EAXRAM()

/* дһ���Ĵ���  
 * addr  �ӻ���ַ  MPU6050Ϊ0xD0
 * reg   �Ĵ���
 * value д��Ĵ���ֵ
*/
#define  IIC_WriteReg(addr, reg, value) {EAXSFR(); I2c_Start(); I2c_SendData(addr); I2c_GetAck(); I2c_SendData(reg);I2c_GetAck();I2c_SendData(value);I2c_GetAck(); I2c_Stop(); EAXRAM();}

/* ��һ���Ĵ���  
 * addr  �ӻ���ַ  MPU6050Ϊ0xD0
 * reg   �Ĵ���
 * value ��ȡ�Ĵ���ֵ
*/
#define  IIC_ReadReg(addr, reg, value) {EAXSFR(); I2c_Start(); I2c_SendData(addr); I2c_GetAck(); I2c_SendData(reg);I2c_GetAck(); I2c_Start();I2c_SendData((addr+1)); I2c_GetAck(); I2c_GetData(value);I2c_GetAck(); I2c_Stop(); EAXRAM();}


/* ��n���Ĵ���  
 * addr  �ӻ���ַ  MPU6050Ϊ0xD0
 * reg   �Ĵ���
 * buff  ��ȡ�Ĵ���ֵ��ŵĻ�����
 * len   ��ȡlen���Ĵ���
*/
void IIC_ReadMultReg(uint8_t addr, uint8_t reg, uint8_t* buff, uint8_t len);



#endif
  