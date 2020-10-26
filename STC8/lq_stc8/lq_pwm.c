/*!
  * @file     lq_pwm.c
  *
  * @brief    pwm�����ļ�
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


#include "lq_pwm.h"

/* pwm API��lq_pwm.h�� */




/* STC8G  */
#if (STC8G == 1)

/** PWM ����ʱ���� */
uint16_t xdata PWM_Period[6];

#elif (STC8A == 1)

/** PWM ����ʱ���� */
uint16_t xdata PWM_Period;

#elif (STC8H == 1)

/** PWM ����ʱ���� */
uint16_t xdata PWM_Period[3];


#endif


