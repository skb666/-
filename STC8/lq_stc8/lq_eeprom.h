/*!
  * @file     lq_eeprom.h
  *
  * @brief    eeprom �����ļ�
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
#ifndef __LQ_EEPROM_H
#define __LQ_EEPROM_H

#include "stc8.h"


/*========================================================================================*/
/*========================================================================================*/
/*===============================EEPROM�ײ� �û��������==================================*/
/*========================================================================================*/
/*========================================================================================*/

/* ����EEPROM��ַ */
#define		Iap_LoadAddr(n)					IAP_ADDRH = (n) / 256,	IAP_ADDRL = (n) % 256

/* eeprom ��ȡ ���� �������� */
#define     Iap_ReadEepromCmd()             IAP_CMD = 1
#define     Iap_WriteEepromCmd()            IAP_CMD = 2
#define     Iap_EraseEepromCmd()            IAP_CMD = 3

/* �������� */
#define     Iap_TrigCmd()                   IAP_TRIG = 0x5a; IAP_TRIG = 0xa5;

/* EEPROM����ʧ�ܱ�־λ */
#define     Iap_IsOK()                      (IAP_CONTR & 0x10) == 0

/* �����λ EEPROM����ʧ�ܱ�־λֻ���Ը�λ����*/
#define     Iap_Rst()                        IAP_CONTR |= 0x20

/* �����λ���Ƿ����ISP */
#define     Iap_EnterISP()                   IAP_CONTR |= 0x40

/* EEPROMʹ�� */
#define     Iap_Enable()                     IAP_CONTR = 0x80
#define     Iap_Disable()                    IAP_CONTR &= ~0x80

/* EEPROM �����ȴ�ʱ�� */
#define     Iap_SetTPS()                     IAP_TPS = MAIN_Fosc/1000000UL

/* EEPROM �ر� */
#define     Iap_Idle()                     {IAP_CONTR = 0;\
											IAP_CMD = 0;\
											IAP_TRIG = 0;\
											IAP_ADDRH = 0x80;\
											IAP_ADDRL = 0;}
/*========================================================================================*/
/*========================================================================================*/
/*==================================EEPROM�û�API===========================================*/
/*========================================================================================*/
/*========================================================================================*/

/* EEPROM ��������  addr ����������ַ STC8H8K64��ַ��Χ 0 - ISP������õ�EEPROM��С */
#define     EEPROM_Erase(addr)      Iap_Enable();Iap_SetTPS();Iap_EraseEepromCmd();Iap_LoadAddr(addr);Iap_TrigCmd();_nop_();Iap_Idle();

/* EEPROM дһ���ֽ�   
 * addr   Ҫд��ĵ�ַ  STC8H8K64��ַ��Χ 0 - ISP������õ�EEPROM��С 
 * dat    Ҫд������    һ���ֽ�
 */											
#define     EEPROM_Write(addr, dat)	Iap_Enable();Iap_SetTPS();Iap_WriteEepromCmd();Iap_LoadAddr(addr);IAP_DATA = dat;Iap_TrigCmd();_nop_();Iap_Idle();									

/* EEPROM ��һ���ֽ�   
 * addr   Ҫ��ȡ�ĵ�ַ  STC8H8K64��ַ��Χ 0 - ISP������õ�EEPROM��С 
 * dat    ��ȡ����      һ���ֽ�
 */											
#define     EEPROM_Read(addr, dat)  Iap_Enable();Iap_SetTPS();Iap_ReadEepromCmd();Iap_LoadAddr(addr);Iap_TrigCmd();_nop_();dat = IAP_DATA;Iap_Idle();


#endif
