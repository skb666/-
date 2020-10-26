/*!
  * @file     LQ_KEY.c
  *
  * @brief    ���������ļ�
  *
  * @company  �����������ܿƼ�
  *
  * @author   LQ-005
  *
  * @note     ��
  *
  * @version  V1.1  2019/12/06 �Ż�ע�� Doxygen
  *
  * @par URL  http://shop36265907.taobao.com
  *           http://www.lqist.cn
  *
  * @date     2019/10/18 ������
  */ 
#include "lq_key.h"
#include "lq_gpio.h"

/** �����ⲿ��ʱ���� */
extern void delayms(uint32_t ms);




/**
  * @brief    ��ʼ������ĸ���ϵİ���
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note     ����IO��LQ_KEY.h��ͨ���궨��ѡ��
  *
  * @see      KEY_Init();
  *
  * @date     2019/6/4 ���ڶ�
  */
void KEY_Init(void)
{  
    /* ������������ */
    PIN_InitStandard(KEY0_PORT,  KEY0_PIN);
    PIN_InitStandard(KEY1_PORT,  KEY1_PIN);
    PIN_InitStandard(KEY2_PORT,  KEY2_PIN); 
	
	PIN_EnablePullUp(KEY0_PORT,  KEY0_PIN);
	PIN_EnablePullUp(KEY1_PORT,  KEY1_PIN);
	PIN_EnablePullUp(KEY2_PORT,  KEY2_PIN); 
}


/**
  * @brief    ��ȡ����״̬
  *
  * @param    mode�� 0����֧��������;   1��֧��������;
  *
  * @return   0���ް�������  1��KEY0����  2:KEY1����  3:KEY2����
  *
  * @note     ʹ��ǰ���ȳ�ʼ������
  *
  * @see      uint8_t key_flag = KEY_Read(0);
  *
  * @date     2019/6/4 ���ڶ�
  */
uint8_t KEY_Read(uint8_t mode)
{
    static uint8_t xdata key_up=1;     //�����ɿ���־
    if(mode==1) 
    {
        key_up=1;      //֧������
    }
    if(key_up && (P(KEY0_PORT,  KEY0_PIN)==0 || P(KEY1_PORT,  KEY1_PIN)==0 || P(KEY2_PORT,  KEY2_PIN)==0))
    {
        delayms(10);   //����
        key_up=0;
        if(P(KEY0_PORT,  KEY0_PIN)==0)      
        {
            return 1;
        }
        
        else if(P(KEY1_PORT,  KEY1_PIN)==0) 
        {
            return 2;    
        }
        
        else if(P(KEY2_PORT,  KEY2_PIN)==0) 
        {
            return 3;    
        }
        
    }
    if(P(KEY0_PORT,  KEY0_PIN)==1 && P(KEY1_PORT,  KEY1_PIN)==1 && P(KEY2_PORT,  KEY2_PIN)==1) 
    {
        key_up=1;   
    }
    return 0;   //�ް�������
    
}








