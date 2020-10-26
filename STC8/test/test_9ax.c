/*!
  * @file     test_9ax.c
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
#include "test_9ax.h"
#include "lq_9ax.h"
#include "lq_uart.h"
#include "lq_softiic.h"
#include "lq_led.h"
#include "lq_oled.h"


/* �����ⲿ��ʱ���� */
extern void delayms(uint16_t ms);


	
/**
  * @brief    ��ȡ9��ԭʼ���� ����
  *
  * @param    
  *
  * @return   
  *
  * @note     
  *
  * @example  
  *
  * @date     2019/6/12 ������
  */
void Test_9AX()
{
	char  xdata txt[30];
	int  xdata aacx,aacy,aacz;	         //���ٶȴ�����ԭʼ����
	int  xdata gyrox,gyroy,gyroz;        //������ԭʼ����
	int  xdata magx, magy, magz;         //�شż�ԭʼ����
	
    OLED_Init();                          //LCD��ʼ��
    OLED_CLS();                           //LCD����
	IIC_Init(); 
	UART1_InitTimer1P30P31(115200);      //��ʼ������
	OLED_P8x16Str(15,0,"LQ 9AX Test"); 
    printf("\r\nLQ 9AX Test\n");
	
	if(LQ9AX_Init())
    {
        OLED_P8x16Str(0,2,"9AX Test Fail");
        while(1);
    }
	
	while(1)
    {

        FX_8700_GetACCRaw(&aacx,&aacy,&aacz);	  //�õ����ٶȴ���������  
        FX_8700_GetMAGRaw(&magx, &magy, &magz);
        FX_21002_GetRaw(&gyrox, &gyroy, &gyroz);
		
        sprintf((char*)txt,"ax:%06d",aacx);
        OLED_P6x8Str(0,2,txt);
        sprintf((char*)txt,"ay:%06d",aacy);
        OLED_P6x8Str(0,3,txt);
        sprintf((char*)txt,"az:%06d",aacz);
        OLED_P6x8Str(0,4,txt);
        sprintf((char*)txt,"gx:%06d",gyrox);
        OLED_P6x8Str(0,5,txt);
        sprintf((char*)txt,"gy:%06d",gyroy);
        OLED_P6x8Str(0,6,txt);
        sprintf((char*)txt,"gz:%06d",gyroz);
        OLED_P6x8Str(0,7,txt);
        sprintf((char*)txt,"MX:%5d ",magx);  
        OLED_P6x8Str(60,5,txt);
        sprintf((char*)txt,"MY:%5d ",magy);
        OLED_P6x8Str(60,6,txt); 
        sprintf((char*)txt,"MZ:%5d ",magz); 
        OLED_P6x8Str(60,7,txt);

        printf("\r\nAX: %d  ",aacx); 
        printf("\r\nAY: %d  ",aacy);
        printf("\r\nAZ: %d  ",aacz); 
        printf("\r\nGX: %d  ",gyrox);
        printf("\r\nGY: %d  ",gyroy); 
        printf("\r\nGZ: %d  ",gyroz);
        printf("\r\nMX: %d  ",magx);
        printf("\r\nMY: %d  ",magy); 
        printf("\r\nMZ: %d  ",magz);
        delayms(100);
        printf("\r\n*********************\r\n");
    }
	
}
