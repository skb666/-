/*!
  * @file     test_oled.c
  *
  * @brief    oled����
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
#include "lq_oled.h"
#include "test_oled.h"

/* ����ȷ��ʱ */
extern void delayms(uint32_t ms);

/**
  * @brief    OLED ���Ժ���
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note     ��
  *
  * @example  Test_OLED();
  *
  * @date     2019/6/25 ���ڶ�
  */
void Test_OLED(void)
{      
    OLED_Init();                          //LCD��ʼ�� 
    OLED_Show_LQLogo();                   //��ʾLOGO
    delayms(2000);  
    OLED_CLS();       
  
    while (1)
    {  
        OLED_P6x8Str(0,7,"OLED 3.");         //�ַ���
		delayms(1000);
        OLED_Rectangle(0, 0, 127,62,0);      //���ƾ���
        OLED_Rectangle(24,8,88,55,1);
		OLED_Rectangle(32,16,80,47,1);
		OLED_Rectangle(40,24,72,39,1);
        delayms(1000);
        OLED_CLS();                          //����
        
        OLED_P8x16Str(0, 0,"OLED 4.");       //��ʾ�ַ���
        OLED_P14x16Str(0,3,"��������");      //��ʾ����
        OLED_PutPixel(120,60);
        delayms(1000);
        OLED_CLS();                          //����
        
        OLED_Fill();                         //���
        delayms(1000);
        OLED_CLS();                          //���� 
        
        //��ʱ
        delayms(50);
    }
}
