/*!
  * @file     test_ccd.h
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

#ifndef __TEST_CCD_H
#define __TEST_CCD_H

#include "stc8.h"

/**
  * @brief    CCD�ܽų�ʼ��
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note     
  *
  * @example  
  *
  * @date     2020/4/22 ����һ
*/
void CCD_Init(void) ;

/**
  * @brief    CCD�ɼ�����
  *
  * @param    p  ��  ��Ųɼ����ݵ��׵�ַ
  *
  * @return   ��
  *
  * @note     
  *
  * @example  uint16_t ccd_buf[128];
  *           CCD_Collect(ccd_buf); 
  *
  * @date     2020/4/22 
*/
void CCD_Collect(uint16_t *p) ;


/**
  * @brief    ����CCD  OLED��ͼ ���ϱ���λ�� 
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note     
  *
  * @example  
  *
  * @date     2020/4/22 ����һ
*/
void Test_CCD(void);



#endif