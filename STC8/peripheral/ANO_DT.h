/*!
  * @file     ANO_DT.h
  *
  * @brief    ������λ������
  *
  * @company  ����
  *
  * @author   ����
  *
  * @note     ��
  *
  * @version  V1.1  2019/12/06 �Ż�ע�� Doxygen
  *
  * @Software IAR8.32 or MDK5.28
  *
  * @par URL  http://shop36265907.taobao.com
  *           http://www.lqist.cn
  *
  * @date     2019/10/18 ������
  */ 
#ifndef __ANO_DT_H
#define __ANO_DT_H

#include "stc8.h"

/*!
  * @brief    ����λ�����ͷ���8��int16_t����
  *
  * @param    data1 - data8  �� ���͸���λ����ʾ����
  *
  * @return   ��
  *
  * @note     ��
  *
  * @see      ANO_DT_send_int16(1, 2, 3, 0, 0, 0, 0, 0);
  *
  * @date     2019/5/28 ���ڶ�
  */
void ANO_DT_send_int16(int16_t data1, int16_t data2, int16_t data3, int16_t data4, int16_t data5, int16_t data6, int16_t data7, int16_t data8);






	
#endif

