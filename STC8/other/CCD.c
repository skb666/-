#include "main.h"

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
