/*!
  * @file     test_uart.c
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
#include "test_uart.h"
#include "lq_uart.h"
#include "stdio.h"
#include "stc8.h"

/* ����ȷ��ʱ */
extern void delayms(uint32_t ms);

/**
  * @brief    ���Դ���   
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note     
  *
  * @example  
  *
  * @date     2019/4/22 ����һ
*/
void Test_UART()
{
	uint8_t xdata uartSendData = 10;
	uint32_t xdata u32Data = 1000;
	
	UART1_InitTimer1P30P31(115200);  //��ʼ������
	
	UART3_InitTimer2P50P51(115200);  //��ʼ������

	while(1)
	{
		printf("uart1 ��ӡ�� ע�� uart��ʼ��������ʱ ��ʹ��stc8.h�е� MAIN_Fosc \r\n");    //printf �����lq_uart.c �е�putchar() ���� ����޸�printf��Ӧ�Ĵ��� ���޸�putchar() ��������
		printf("MAIN_Fosc ����Ҫ��ISP����е�ʱ��Ƶ�ʱ���һ�� ������ܻ����� \r\n");
		
		printf("ע���ӡuint8_t ����ʱ �� %d \r\n", (int)uartSendData);
		printf("ע���ӡuint32_t ����ʱ �� %ld \r\n", u32Data);
		
		delayms(100);

		UART3_PutStr("MAIN_Fosc ����Ҫ��ISP����е�ʱ��Ƶ�ʱ���һ�� ������ܻ����� \r\n");

		UART3_PutStr("\r\n");
		
		UART1_PutStr("MAIN_Fosc ����Ҫ��ISP����е�ʱ��Ƶ�ʱ���һ�� ������ܻ����� \r\n");

		UART1_PutStr("\r\n");
	}
	
}