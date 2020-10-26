/*!
  * @file     lq_uart.c
  *
  * @brief    uart �����ļ�
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
#include "lq_uart.h"

/* �����ݴ涨ʱ����װ��ֵ */
volatile uint16_t  xdata timerReload = 0;

/* ����æ��־λ */
volatile uint8_t   xdata uart1Busy = 0;
volatile uint8_t   xdata uart2Busy = 0;
volatile uint8_t   xdata uart3Busy = 0;
volatile uint8_t   xdata uart4Busy = 0;

/* printf �ض��� */
char putchar(char c)//�ض���
{
	UART1_PutChar(c);  //ʹ��printf����ʱ�����  ���������޸�
	return c;
}


/*!
  * @brief    ��ӡ��֪���ȵ�����
  * 
  * @param    buff  �� Ҫ��ӡ���ַ�����ַ    
  * @param    len   �� Ҫ��ӡ�ĳ���
  *
  * @return   ��
  *
  * @note     ʹ��ǰ���ȳ�ʼ����Ӧ����
  *
  * @see      UART1_PutBuff("123456789",5);//ʵ�ʷ���5���ֽڡ�1����2����3����4����5��    
  *
  * @date     2019/10/21 ����һ
  */
void UART1_PutBuff(uint8_t *buff, uint16_t len) 
{
	uint16_t xdata temp = 0;
	for(temp = 0; temp < len; temp++)
	{
		UART1_PutChar(*(buff+temp));
	}  
}   

/*!
  * @brief    ��ӡ��֪���ȵ�����
  * 
  * @param    buff  �� Ҫ��ӡ���ַ�����ַ    
  * @param    len   �� Ҫ��ӡ�ĳ���
  *
  * @return   ��
  *
  * @note     ʹ��ǰ���ȳ�ʼ����Ӧ����
  *
  * @see      UART2_PutBuff("123456789",5);//ʵ�ʷ���5���ֽڡ�1����2����3����4����5��    
  *
  * @date     2019/10/21 ����һ
  */
void UART2_PutBuff(uint8_t *buff, uint16_t len) 
{
	uint16_t xdata temp = 0;
	for(temp = 0; temp < len; temp++)
	{
		UART2_PutChar(*(buff+temp));
	}  
}   

/*!
  * @brief    ��ӡ��֪���ȵ�����
  * 
  * @param    buff  �� Ҫ��ӡ���ַ�����ַ    
  * @param    len   �� Ҫ��ӡ�ĳ���
  *
  * @return   ��
  *
  * @note     ʹ��ǰ���ȳ�ʼ����Ӧ����
  *
  * @see      UART3_PutBuff("123456789",5);//ʵ�ʷ���5���ֽڡ�1����2����3����4����5��    
  *
  * @date     2019/10/21 ����һ
  */
void UART3_PutBuff(uint8_t *buff, uint16_t len) 
{
	uint16_t xdata temp = 0;
	for(temp = 0; temp < len; temp++)
	{
		UART3_PutChar(*(buff+temp));
	}  
}   


/*!
  * @brief    ��ӡ��֪���ȵ�����
  * 
  * @param    buff  �� Ҫ��ӡ���ַ�����ַ    
  * @param    len   �� Ҫ��ӡ�ĳ���
  *
  * @return   ��
  *
  * @note     ʹ��ǰ���ȳ�ʼ����Ӧ����
  *
  * @see      UART4_PutBuff("123456789",5);//ʵ�ʷ���5���ֽڡ�1����2����3����4����5��    
  *
  * @date     2019/10/21 ����һ
  */
void UART4_PutBuff(uint8_t *buff, uint16_t len) 
{
	uint16_t xdata temp = 0;
	for(temp = 0; temp < len; temp++)
	{
		UART4_PutChar(*(buff+temp));
	}  
}   

/*!
  * @brief    ���ڴ�ӡ�ַ���
  *
  * @param    str   �� Ҫ��ӡ���ַ�����ַ 
  *
  * @return   ��
  *
  * @note     ʹ��ǰ���ȳ�ʼ����Ӧ����
  *
  * @see      UART1_PutStr("123456789"); //����9���ֽ�      
  *
  * @date     2019/10/21 ����һ
  */
void UART1_PutStr(uint8_t *str) 
{
	while(*str)
	{
		UART1_PutChar(*str++);
	}
}     

/*!
  * @brief    ���ڴ�ӡ�ַ���
  *
  * @param    str   �� Ҫ��ӡ���ַ�����ַ 
  *
  * @return   ��
  *
  * @note     ʹ��ǰ���ȳ�ʼ����Ӧ����
  *
  * @see      UART2_PutStr("123456789"); //����9���ֽ�      
  *
  * @date     2019/10/21 ����һ
  */
void UART2_PutStr(uint8_t *str) 
{
	while(*str)
	{
		UART2_PutChar(*str++);
	}
} 

/*!
  * @brief    ���ڴ�ӡ�ַ���
  *
  * @param    str   �� Ҫ��ӡ���ַ�����ַ 
  *
  * @return   ��
  *
  * @note     ʹ��ǰ���ȳ�ʼ����Ӧ����
  *
  * @see      UART3_PutStr("123456789"); //����9���ֽ�      
  *
  * @date     2019/10/21 ����һ
  */
void UART3_PutStr(uint8_t *str) 
{
	while(*str)
	{
		UART3_PutChar(*str++);
	}
} 

/*!
  * @brief    ���ڴ�ӡ�ַ���
  *
  * @param    str   �� Ҫ��ӡ���ַ�����ַ 
  *
  * @return   ��
  *
  * @note     ʹ��ǰ���ȳ�ʼ����Ӧ����
  *
  * @see      UART4_PutStr("123456789"); //����9���ֽ�      
  *
  * @date     2019/10/21 ����һ
  */
void UART4_PutStr(uint8_t *str) 
{
	while(*str)
	{
		UART4_PutChar(*str++);
	}
} 





