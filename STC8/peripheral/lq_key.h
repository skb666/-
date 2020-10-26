/*!
  * @file     LQ_KEY.h
  *
  * @brief    ���������ļ�
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
  * @date     2019/10/18 ������
  */ 
#ifndef __LQ_KEY_H
#define __LQ_KEY_H

#include "LQ_GPIO.h"

#if (STC8A == 1)

/* �����ܽŶ��� */   
#define KEY0_PORT       4            /*!<  @brief    ���� ��port  */
#define KEY0_PIN        1            /*!<  @brief    ���� ��Pin   */
												
#define KEY1_PORT       4            /*!<  @brief    ���� ��port  */
#define KEY1_PIN        2            /*!<  @brief    ���� ��Pin   */
													
#define KEY2_PORT       2            /*!<  @brief    ���� ��port  */
#define KEY2_PIN        7            /*!<  @brief    ���� ��Pin   */

#else

/* �����ܽŶ��� */   
#define KEY0_PORT       2            /*!<  @brief    ���� ��port  */
#define KEY0_PIN        0            /*!<  @brief    ���� ��Pin   */
												
#define KEY1_PORT       5            /*!<  @brief    ���� ��port  */
#define KEY1_PIN        2            /*!<  @brief    ���� ��Pin   */
													
#define KEY2_PORT       5            /*!<  @brief    ���� ��port  */
#define KEY2_PIN        3            /*!<  @brief    ���� ��Pin   */

#endif

/**
  * @brief    ��ʼ������ĸ���ϵİ���
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note     ����IO��LQ_KEY.h��ͨ���궨��ѡ��
  *
  * @see      KEY_Init();
  *
  * @date     2019/6/4 ���ڶ�
  */
void KEY_Init(void);


/**
  * @brief    ��ȡ����״̬
  *
  * @param    mode�� 0����֧��������;   1��֧��������;
  *
  * @return   0���ް�������  1��KEY0����  2:KEY1����  3:KEY2����
  *
  * @note     ʹ��ǰ���ȳ�ʼ������
  *
  * @see      uint8_t key_flag = KEY_Read(0);
  *
  * @date     2019/6/4 ���ڶ�
  */
uint8_t KEY_Read(uint8_t mode);







#endif