/*!
  * @file     test_ccd.c
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
#include "test_ccd.h"

#include "main.h"


#if (STC8A == 1)      //STC8A
#define CCD_AO_CHANNEL     5            //AO��ADCͨ��5  �ܽ�P15

#define CCD_CLK_PORT       1            //CLK��         �ܽ�P13
#define CCD_CLK_PIN        3

#define CCD_SI_PORT        1            //SI��          �ܽ�P14
#define CCD_SI_PIN         4

#define THRESHOLD          1500         //OLED����ʾ�������ֵ   ��Χ0-4095

#else   //STC8H STC8G
#define CCD_AO_CHANNEL     4            //AO��ADCͨ��4  �ܽ�P14

#define CCD_CLK_PORT       1            //CLK��         �ܽ�P15
#define CCD_CLK_PIN        5

#define CCD_SI_PORT        2            //SI��          �ܽ�P23
#define CCD_SI_PIN         3

#define THRESHOLD          888        //OLED����ʾ�������ֵ   ��Χ0-4095  ע��STC8G ADCΪ10λ��

#endif


#define CCD_AO_INIT         ADC_Init(CCD_AO_CHANNEL)
#define CCD_AO_GET(value)   ADC_GetValue(CCD_AO_CHANNEL, value)  
#define CCD_CLK_INIT        PIN_InitPushPull(CCD_CLK_PORT, CCD_CLK_PIN)
#define CCD_SI_INIT         PIN_InitPushPull(CCD_SI_PORT, CCD_SI_PIN)

#define CCD_CLK_H           P(CCD_CLK_PORT, CCD_CLK_PIN) = 1
#define CCD_CLK_L           P(CCD_CLK_PORT, CCD_CLK_PIN) = 0

#define CCD_SI_H            P(CCD_SI_PORT, CCD_SI_PIN)   = 1
#define CCD_SI_L            P(CCD_SI_PORT, CCD_SI_PIN)   = 0



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
void Test_CCD(void)
{
	uint32_t xdata now_time = 0;
	uint16_t xdata ccd_buf[128];
	static uint8_t xdata count = 0;
	uint8_t xdata i = 0;
	uint16_t xdata cnt1;
	
	LED_Init();
    UART1_InitTimer1P30P31(115200);  //��ʼ������
	OLED_Init();
    OLED_CLS();
	CCD_Init();
	TIMER0_InitSys();
	
	OLED_P8x16Str(15,0,"LQ CCD Test"); 
    printf("\r\nLQ CCD Test");
	
	
	while(1)
	{
		if(TIMER0_GetMs() - now_time >= 80)                  
		{
			now_time = TIMER0_GetMs();
			
			/* �ɼ�ccdͼ�� */
			CCD_Collect(ccd_buf);
			
			/* ���͵���λ�� */
//			if(count++%5 == 0)
//			{
//				UART1_PutChar('T');
//				for(i=0; i<128; i++) 
//				{
//					UART1_PutChar((unsigned char)(ccd_buf[i]>>8)); //���͸�8λ
//					UART1_PutChar((unsigned char)ccd_buf[i]);      //���͸ߵ�8λ 
//				}
//			}
			
			/* OLED ��ʾ */
			if(count % 3 == 0)
			{
				cnt1 = 0;
				for(i=0; i<128; i++)
				{
					OLED_Set_Pos(i , 5); 
					if(ccd_buf[i] > THRESHOLD)
						//OLED_WrDat(0xFF);
						;
					else{
						//OLED_WrDat(0x00);
						cnt1++;
					}
				}
				if(cnt1 >= 30)printf("1111111111111111111111111\r\n");
				else printf("0000000000000000000000000000000\r\n");;
				printf("%d\r\n", cnt1);
			}
			
		}
	}
}


/**
  * @brief    CCD��ʱ����
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
void CCD_Delayus(uint8_t us)
{
	uint16_t  i;
	while(us--)
	{
		for(i=0;i<10;i++)
		{
			 ;  
		}  
	}
}

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
void CCD_Init(void) 
{
    CCD_AO_INIT;  
    CCD_CLK_INIT;
    CCD_SI_INIT;
}


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
void CCD_Collect(uint16_t *p) 
{
	unsigned char i;
	unsigned int  temp = 0;

	CCD_SI_H;              //SI  = 1 
	CCD_Delayus(1);
	CCD_CLK_H;             // CLK = 1 
	CCD_Delayus(1);
	CCD_SI_L;              // SI  = 0 
	CCD_Delayus(1);

	for(i=0; i<128; i++) 
	{
		CCD_Delayus(1);
		CCD_CLK_H;         // CLK = 1 
		CCD_Delayus(1);
		CCD_AO_GET(temp);       
		*p++ = temp;     
		CCD_CLK_L;        // CLK = 0 
	}
	CCD_Delayus(1);
	CCD_CLK_H;            // CLK = 1 
	CCD_Delayus(1);
	CCD_CLK_L;            // CLK = 0 
}
