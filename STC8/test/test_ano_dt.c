/*!
  * @file     TEST_ANO_DT.c
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
#include "test_ano_dt.h"
#include "ANO_DT.h"
#include "math.h"
#include "lq_uart.h"
#include "lq_led.h"

/** �����ⲿ��ʱ���� */
extern void delayms(uint32_t ms);

/**
  * @brief    �����ϱ�������λ��
  *
  * @param    
  *
  * @return   
  *
  * @note     ���� 5· ������
  *
  * @example  
  *
  * @date     2019/6/17 ����һ
  */
void Test_ANO_DT(void)    
{
    float xdata data1 = 0.0f;
    float xdata data2 = 45.0f; 
    float xdata data3 = 90.0f;   
    float xdata data4 = 135.0f;   
    float xdata data5 = 60.0f;
    code float PI = 3.1415926f;
    
    LED_Init();   

    UART1_InitTimer1P30P31(115200);      //��ʼ������   
   
    while(1)
    {

		ANO_DT_send_int16((int16_t)(sin(data1/180.0f * PI) * 100),
					  (int16_t)(sin(data2/180.0f * PI) * 100),
					  (int16_t)(sin(data3/180.0f * PI) * 100),
					  (int16_t)(sin(data4/180.0f * PI) * 100), 
					  (int16_t)(sin(data5/180.0f * PI) * 100), 
					  0, 
					  0,
					  0);  

         
        delayms(20);
		
        if(data1 > 180.0f) data1 = -180;
        if(data2 > 180.0f) data2 = -180;
        if(data3 > 180.0f) data3 = -180;
        if(data4 > 180.0f) data4 = -180;
        if(data5 > 180.0f) data5 = -180;
        
        data1 += 1;
        data2 += 2;
        data3 += 3;
        data4 += 4;
        data5 += 5;
		
		LED_ColorReverse(green);
    }
}


