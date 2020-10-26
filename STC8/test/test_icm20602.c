/*!
  * @file     test_mpu6050.c
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
#include "test_icm20602.h"
#include "lq_icm20602.h"
#include "lq_uart.h"
#include "lq_spi.h"
#include "lq_led.h"
#include "lq_oled.h"


/* �����ⲿ��ʱ���� */
extern void delayms(uint16_t ms);


	
/**
  * @brief    ��ȡICM20602ԭʼ���� ����
  *
  * @param    
  *
  * @return   
  *             STC8G/8H              STC8A
  * @note    GND  ---  GND         GND  ---  GND
  *          VCC  ---  5V          VCC  ---  5V
  *          SCL  ---  P32         SCL  ---  P15
  *          SDA  ---  P34         SDA  ---  P13
  *          SA   ---  P33         SA   ---  P14
  *          CS   ---  P35         CS   ---  P12
  *
  * @example  
  *
  * @date     2019/6/12 ������
  */
void Test_ICM20602()
{
	char  xdata txt[30];
	int  xdata aacx,aacy,aacz;	         //���ٶȴ�����ԭʼ����
	int  xdata gyrox,gyroy,gyroz;        //������ԭʼ����
	
    OLED_Init();                          //LCD��ʼ��
    OLED_CLS();                           //LCD����
#if (STC8A== 1)
	SPI_InitP12P13P14P15(0, 3);          //SPI��ʼ�� �ٶ� MAIN_Fosc/4   CLK����ʱ��Ϊ�ߵ�ƽ �ڵڶ���CLK������ ��������
#else
	SPI_InitP35P34P33P32(0, 3);          //SPI��ʼ�� �ٶ� MAIN_Fosc/4   CLK����ʱ��Ϊ�ߵ�ƽ �ڵڶ���CLK������ ��������
	
#endif
	UART1_InitTimer1P30P31(115200);      //��ʼ������
	OLED_P8x16Str(15,0,"LQ 20602 Test"); 
    printf("\r\nLQ 20602 Test \r\n");
	
	if(ICM20602_Init())
    {
        OLED_P8x16Str(15,2,"20602 Test Fail");
		printf("\r\n20602 Test Fail \r\n");
        while(1);
    }
	
	while(1)
    {

        ICM_Get_Raw_data(&aacx,&aacy,&aacz,&gyrox,&gyroy,&gyroz);	//�õ����ٶȴ���������  
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

        printf("\r\nAX: %d  ",aacx); 
        printf("\r\nAY: %d  ",aacy);
        printf("\r\nAZ: %d  ",aacz); 
        printf("\r\nGX: %d  ",gyrox);
        printf("\r\nGY: %d  ",gyroy); 
        printf("\r\nGZ: %d  ",gyroz);
        delayms(100);
        printf("\r\n*********************\r\n");
    }
	
}
