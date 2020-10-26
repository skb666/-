/*!
  * @file     LQ_12864.h
  *
  * @brief    OLED����
  *
  * @company  �����������ܿƼ�
  *
  * @author   LQ-005
  *
  * @note     Tab�� 4���ո�
  *
  * @version  V1.1  2019/12/06 �Ż�ע�� Doxygen
  *
  * @Software IAR8.32 or MDK5.28
  *
  * @par URL  http://shop36265907.taobao.com
  *           http://www.lqist.cn
  *
  * @date     2019/11/11 ����һ
  */ 
#ifndef _LQOLED_H
#define _LQOLED_H

#include "stc8.h"

/*!
  * @brief    OLED��ʼ��
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note     ����޸Ĺܽ� ��Ҫ�޸ĳ�ʼ���Ĺܽ� 
  *
  * @see      OLED_Init();
  *
  * @date     2019/6/13 ������
  */
void OLED_Init(void);

/*!
  * @brief    OLEDȫ��
  *
  * @param    ��   
  *
  * @return   ��
  *
  * @note     ��
  *
  * @see      OLED_Fill(); //OLEDȫ�� ���ڼ�⻵��
  *
  * @date     2019/6/13 ������
  */
void OLED_Fill(void);

/*!
  * @brief    OLED����
  *
  * @param    ��  
  *
  * @return   ��
  *
  * @note     ��
  *
  * @see      OLED_CLS(); //����
  *
  * @date     2019/6/13 ������
  */
void OLED_CLS(void);

/*!
  * @brief    ��һ����
  *
  * @param    x  : 0-127 
  * @param    y  : 0-63
  *
  * @return   ��
  *
  * @note     OLED�ǰ��ֽ���ʾ�� һ���ֽ�8λ������8���������ص㣬
  * @note     ���������� OLED_PutPixel(0,0); OLED_PutPixel(0,1); ֻ����ʾ��(0, 1) (0,0)���ڻ���(0,1)ʱ�����
  *
  * @see      OLED_PutPixel(0, 0); //��һ���� ���Ͻ�Ϊ0,0  ���½� 127,63
  *
  * @date     2019/6/13 ������
  */
void OLED_PutPixel(unsigned char x,unsigned char y);

/*!
  * @brief    ���8����
  *
  * @param    x  : 0-127
  * @param    y  : 0-63
  *
  * @return   ��
  *
  * @note     OLED�ǰ��ֽ���ʾ�� һ���ֽ�8λ������8���������ص㣬
  *
  * @see      OLED_ClrDot(0, 0); //���(0,0)-(0,7)8���� ���Ͻ�Ϊ0,0  ���½� 127,63
  *
  * @date     2019/6/13 ������
  */
void OLED_ClrDot(unsigned char x,unsigned char y);

/*!
  * @brief    ������
  *
  * @param    x1  : 0-127   ���Ͻ����꣨x1,y1��
  * @param    y1  : 0-63
  * @param    x2  : 0-127   ���½����꣨x2��y2��
  * @param    y2  : 0-63
  * @param    gif : �Ƿ�������Ч��
  *
  * @return   ��
  *
  * @note     ��
  *
  * @see      OLED_Rectangle(0, 0, 127,62,0);   //���ƾ���
  *
  * @date     2019/6/13 ������
  */
void OLED_Rectangle(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2,unsigned char gif);

/*!
  * @brief    д��һ���׼ASCII�ַ���
  *
  * @param    x  : 0-127   
  * @param    y  : 0-7
  * @param    ch : Ҫ��ʾ���ַ���
  *
  * @return   ��
  *
  * @note     ��
  *
  * @see      OLED_P6x8Str(0,0,"OLED 3.");  //��ʾ�ַ���
  *
  * @date     2019/6/13 ������
  */
void OLED_P6x8Str(unsigned char x,unsigned char y, char ch[]);

/*!
  * @brief    д��һ���׼ASCII�ַ���
  *
  * @param    x  : 0-127   
  * @param    y  : 0-6
  * @param    ch : Ҫ��ʾ���ַ���
  *
  * @return   ��
  *
  * @note     һ���ַ���16  OLED�߶�64  
  *
  * @see      OLED_P8x16Str(0,0,"OLED 3.");  //��ʾ�ַ���
  *
  * @date     2019/6/13 ������
  */
void OLED_P8x16Str(unsigned char x,unsigned char y, char ch[]);

/*!
  * @brief    ��������ַ���
  *
  * @param    x  : 0-127   
  * @param    y  : 0-6
  * @param    ch : Ҫ��ʾ���ַ���
  *
  * @return   ��
  *
  * @note     һ���ַ���16  OLED�߶�64   �ֿ���Ҫ�Լ�����
  *
  * @see      OLED_P14x16Str(0,4,"��������");   //��ʾ����
  *
  * @date     2019/6/13 ������
  */
void OLED_P14x16Str(unsigned char x,unsigned char y, char ch[]);



/*!
  * @brief    ��ʾBMPͼƬ ��� 128��64
  *
  * @param    x0  : 0-127   ���Ͻ����꣨x0,y0��
  * @param    y0  : 0-63
  * @param    wide: 1-127   ͼƬ���
  * @param    high: 1-64    ͼƬ�߶�
  * @param    bmp : Ҫ��ʾ��ͼƬ
  *
  * @return   ��
  *
  * @note     ͼƬ��Ҫ�����ת��
  *
  * @see      OLED_Show_BMP(0, 0, 104, 64, longqiu104x64); //������loge
  *
  * @date     2019/6/13 ������
  */
void OLED_Show_BMP(unsigned char x0,unsigned char y0,unsigned char wide,unsigned char high,const uint8_t * bmp);

/*!
  * @brief    ��ʾ����ͼƬ128��64
  *
  * @param    �� 
  *
  * @return   ��
  *
  * @note     ��
  *
  * @see      OLED_Show_LQLogo();
  *
  * @date     2019/6/13 ������
  */
void OLED_Show_LQLogo(void);



/*!
  * @brief    OLED����
  *
  * @param    cmd ������
  *
  * @return   ��
  *
  * @note     ��
  *
  * @see      �ڲ�����
  *
  * @date     2019/6/13 ������
  */
void OLED_WrCmd(unsigned char cmd);


/*!
  * @brief    OLED��������
  *
  * @param    data ��Ҫ���ĵ�
  *
  * @return   ��
  *
  * @note     ��
  *
  * @see      �ڲ�����
  *
  * @date     2019/6/13 ������
  */
void OLED_WrDat(unsigned char dat);


/*!
  * @brief    OLED���õ�
  *
  * @param    x ������   
  * @param    y ������
  *
  * @return   ��
  *
  * @note     ��
  *
  * @see      �ڲ�����
  *
  * @date     2019/6/13 ������
  */
void OLED_Set_Pos(unsigned char x, unsigned char y);
	


#endif


