/*!
  * @file     TEST_KEY.c
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
#include "test_key.h"
#include "lq_key.h"
#include "lq_led.h"


/** �����ⲿ��ʱ���� */
extern void delayms(uint32_t ms);


/**
  * @brief    ���԰���
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note     ��
  *
  * @see      Test_KEY();
  *
  * @date     2019/6/4 ���ڶ�
  */
void Test_KEY(void)
{ 
    LED_Init();
    KEY_Init(); 
    while (1)
    {  
        switch(KEY_Read(1))  
        {
            case 1:
                LED_Color(red);     
                break;           
            case 2:      
                LED_Color(green);   
                break;
            case 3:      
                LED_Color(blue);    
                break;
            default:
                LED_Color(white);   
                break;
        }

        delayms(50);
    }
}