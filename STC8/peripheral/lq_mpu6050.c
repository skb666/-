/*!
  * @file     LQ_MPU6050.c
  *
  * @brief    MPU6050/ICM20602�����ļ�
  *
  * @company  �����������ܿƼ�
  *
  * @author   LQ-005
  *
  * @note     MPU6050/ICM20602ʹ��IIC����ʱ������оƬID��һ�� ����һ��
  *
  * @version  V1.1  2019/12/06 �Ż�ע�� Doxygen
  *
  * @par URL  http://shop36265907.taobao.com
  *           http://www.lqist.cn
  *
  * @date     2019/10/18 ������
  */ 
#include "lq_mpu6050.h"
#include "lq_uart.h"
#include "lq_softiic.h"



/**
  * @brief    ����ȷ��ʱ
  *
  * @param    ��
  *
  * @return   ��
  *
  * @note     ��
  *
  * @example  delayms_mpu(100);
  *
  * @date     2019/4/22 ����һ
*/
void delayms_mpu(uint16_t ms)
{
	while(ms--)
	{
		uint16_t xdata i = 300;
		while(i--)
		{
			NOP(50);
		}
	}
}


/**
  * @brief    ��ʼ��MPU6050 ���� ICM20602
  *
  * @param    ��
  *
  * @return   0����ʼ���ɹ�   1��ʧ��  
  *
  * @note     ʹ��ǰ�ȳ�ʼ��IIC�ӿ�
  *
  * @see      MPU6050_Init();
  *
  * @date     2019/6/12 ������
  */
uint8_t MPU6050_Init(void)
{
    int xdata res;
    res = MPU_Read_Byte(MPU6050_ADDR,WHO_AM_I);           //��ȡMPU6050��ID
    if(res == MPU6050_ID)                                 //����ID��ȷ
    {
        printf("MPU6050 is OK!\r\n");
    }
    else if(res == 0x12)                                  //ICM20602 ����ID��ȷ
    {
        
        printf("ICM20602 is OK!\r\n");
    }
    else  
    {
        printf("\r\nThe correct IMU was not detected\r\nPlease check the wiring ID=%X\r\n",res);
        return 1;
    }
    
    res = 0;
    res += MPU_Write_Byte(MPU6050_ADDR,MPU_PWR_MGMT1_REG,0X80);//��λMPU6050
    delayms_mpu(100);  //��ʱ100ms
    res += MPU_Write_Byte(MPU6050_ADDR,MPU_PWR_MGMT1_REG,0X00);//����MPU6050
    res += MPU_Set_Gyro_Fsr(3);					        	   //�����Ǵ�����,��2000dps   
    res += MPU_Set_Accel_Fsr(1);					       	   //���ٶȴ�����,��4g
    res += MPU_Set_Rate(1000);						       	   //���ò�����1000Hz
    res += MPU_Write_Byte(MPU6050_ADDR,MPU_CFG_REG,0x02);      //�������ֵ�ͨ�˲���   98hz
    res += MPU_Write_Byte(MPU6050_ADDR,MPU_INT_EN_REG,0X00);   //�ر������ж�
    res += MPU_Write_Byte(MPU6050_ADDR,MPU_USER_CTRL_REG,0X00);//I2C��ģʽ�ر�
    res += MPU_Write_Byte(MPU6050_ADDR,MPU_PWR_MGMT1_REG,0X01);//����CLKSEL,PLL X��Ϊ�ο�
    res += MPU_Write_Byte(MPU6050_ADDR,MPU_PWR_MGMT2_REG,0X00);//���ٶ��������Ƕ�����
    
    if(res == 0)  //����Ĵ�����д��ɹ�
    {
        printf("MPU set is OK!\r\n");
    }
    else return 1;
    
    return 0;
}




/**
  * @brief    ���������ǲ�����Χ
  *
  * @param    fsr:0,��250dps;1,��500dps;2,��1000dps;3,��2000dps
  *
  * @return   0 �����óɹ�  
  *
  * @note     ��
  *
  * @see      MPU_Set_Gyro_Fsr(3);		  //�����Ǵ�����,��2000dps 
  *
  * @date     2019/6/12 ������
  */
uint8_t MPU_Set_Gyro_Fsr(uint8_t fsr)
{
	return MPU_Write_Byte(MPU6050_ADDR,MPU_GYRO_CFG_REG,fsr<<3);
}



/**
  * @brief    ���ü��ٶȼƲ�����Χ
  *
  * @param    fsr:0,��2g;1,��4g;2,��8g;3,��16g
  *
  * @return   0�����óɹ�
  *
  * @note     ��
  *
  * @see      MPU_Set_Accel_Fsr(1);		  //���ٶȴ�����,��4g
  *
  * @date     2019/6/12 ������
  */
uint8_t MPU_Set_Accel_Fsr(uint8_t fsr)
{
	return MPU_Write_Byte(MPU6050_ADDR,MPU_ACCEL_CFG_REG,fsr<<3);
}



/**
  * @brief    �������ֵ�ͨ�˲�
  *
  * @param    lpf:���ֵ�ͨ�˲�Ƶ��(Hz) 
  *
  * @return   0�����óɹ�
  *
  * @note     ��
  *
  * @see      MPU_Set_LPF(100);
  *
  * @date     2019/6/12 ������
  */
uint8_t MPU_Set_LPF(uint16_t lpf)
{
	uint8_t xdata dat=0;
	if(lpf>=188)dat=1;
	else if(lpf>=98)dat=2;
	else if(lpf>=42)dat=3;
	else if(lpf>=20)dat=4;
	else if(lpf>=10)dat=5;
	else dat=6; 
	return MPU_Write_Byte(MPU6050_ADDR,MPU_CFG_REG,dat);//�������ֵ�ͨ�˲���  
}




/**
  * @brief    ���ò�����
  *
  * @param    rate:4~1000(Hz)
  *
  * @return   0�����óɹ�
  *
  * @note     ��
  *
  * @see      MPU_Set_Rate(1000);       	   //���ò�����1000Hz
  *
  * @date     2019/6/12 ������
  */
uint8_t MPU_Set_Rate(uint16_t rate)
{
	uint8_t xdata dat;
	if(rate>1000)rate=1000;
	if(rate<4)rate=4;
	dat=1000/rate-1;
	dat=MPU_Write_Byte(MPU6050_ADDR,MPU_SAMPLE_RATE_REG,dat);	    //�������ֵ�ͨ�˲���
 	return MPU_Set_LPF(rate/2);	                                //�Զ�����LPFΪ�����ʵ�һ��
}



/**
  * @brief    ��ȡ�¶�ֵ
  *
  * @param    ��
  *
  * @return   �¶�ֵ(������100��)
  *
  * @note     ��
  *
  * @see      int16_t temp = MPU_Get_Temperature();
  *
  * @date     2019/6/12 ������
  */
short MPU_Get_Temperature(void)
{
    uint8_t xdata buf[2]; 
    short raw;
	float temp;
	MPU_Read_Len(MPU6050_ADDR,MPU_TEMP_OUTH_REG,2,buf); 
    raw=((uint16_t)buf[0]<<8)|buf[1];  
    temp=21+((double)raw)/333.87;  
    return (short)temp*100;
}





/**
  * @brief    ��ȡ������ֵ
  *
  * @param    gx,gy,gz:������x,y,z���ԭʼ����(������)
  *
  * @return   0����ȡ�ɹ�
  *
  * @note     ��
  *
  * @see      int6_t data[3];
  * @see      MPU_Get_Gyroscope(&data[0], &data[1], &data[2]);
  *
  * @date     2019/6/12 ������
  */
uint8_t MPU_Get_Gyroscope(int *gx,int *gy,int *gz)
{
    uint8_t xdata buf[6],res; 
	res=MPU_Read_Len(MPU6050_ADDR,MPU_GYRO_XOUTH_REG,6,buf);
	if(res==0)
	{
		*gx=((uint16_t)buf[0]<<8)|buf[1];  
		*gy=((uint16_t)buf[2]<<8)|buf[3];  
		*gz=((uint16_t)buf[4]<<8)|buf[5];
	} 	
    return res;
}




/**
  * @brief    ��ȡ���ٶ�ֵ
  *
  * @param    ax,ay,az:������x,y,z���ԭʼ����(������)
  *
  * @return   0����ȡ�ɹ�
  *
  * @note     ��
  *
  * @see      int6_t data[3];
  * @see      MPU_Get_Accelerometer(&data[0], &data[1], &data[2]); 
  *
  * @date     2019/6/12 ������
  */
uint8_t MPU_Get_Accelerometer(int *ax,int *ay,int *az)
{
    uint8_t xdata buf[6],res;  
	res=MPU_Read_Len(MPU6050_ADDR,MPU_ACCEL_XOUTH_REG,6,buf);
	if(res==0)
	{
		*ax=((uint16_t)buf[0]<<8)|buf[1];  
		*ay=((uint16_t)buf[2]<<8)|buf[3];  
		*az=((uint16_t)buf[4]<<8)|buf[5];
	} 	
    return res;
}




/**
  * @brief    ��ȡ ���ٶ�ֵ ���ٶ�ֵ
  *
  * @param    ax,ay,az:������x,y,z���ԭʼ����(������)
  * @param    gx,gy,gz:������x,y,z���ԭʼ����(������)  
  *
  * @return   0����ȡ�ɹ�
  *
  * @note     ��
  *
  * @see      int6_t data[6];
  * @see      ICM_Get_Raw_data(&data[0], &data[1], &data[2],&data[3], &data[4], &data[5]);  
  *
  * @date     2019/6/12 ������
  */
uint8_t MPU_Get_Raw_data(int *ax,int *ay,int *az,int *gx,int *gy,int *gz)
{
    uint8_t xdata buf[14],res;  
	res=MPU_Read_Len(MPU6050_ADDR,MPU_ACCEL_XOUTH_REG,14,buf);
	if(res==0)
	{
		*ax=((uint16_t)buf[0]<<8)|buf[1];  
		*ay=((uint16_t)buf[2]<<8)|buf[3];  
		*az=((uint16_t)buf[4]<<8)|buf[5];
        *gx=((uint16_t)buf[8]<<8)|buf[9];  
		*gy=((uint16_t)buf[10]<<8)|buf[11];  
		*gz=((uint16_t)buf[12]<<8)|buf[13];
	} 	
    return res;
}





/**
  * @brief    IIC ������
  *
  * @param    addr:������ַ 
  * @param    reg :Ҫ��ȡ�ļĴ�����ַ
  * @param    len :Ҫ��ȡ�ĳ���
  * @param    buf :��ȡ�������ݴ洢��
  *
  * @return   0 ����ȡ�ɹ�
  *
  * @note     �ײ����� ��ֲʱ��Ҫ�޸�
  *
  * @see      uint8_t buf[14];  
  * @see      MPU_Read_Len(MPU6050_ADDR,MPU_ACCEL_XOUTH_REG,14,buf);
  *
  * @date     2019/6/12 ������
  */
uint8_t MPU_Read_Len(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf)
{ 
    return IIC_ReadMultByteFromSlave(addr<<1, reg, len, buf);     
}



/**
  * @brief    IIC дһ���Ĵ���
  *
  * @param    addr  :������ַ 
  * @param    reg   :�Ĵ�����ַ
  * @param    value :Ҫд���ֵ
  *
  * @return   0 ����ȡ�ɹ�
  *
  * @note     �ײ����� ��ֲʱ��Ҫ�޸�
  *
  * @see      MPU_Write_Byte(MPU6050_ADDR,MPU_SAMPLE_RATE_REG,1);	
  *
  * @date     2019/6/12 ������
  */
uint8_t MPU_Write_Byte(uint8_t addr,uint8_t reg,uint8_t value)
{
    return IIC_WriteByteToSlave(addr<<1, reg, value);    
}


/**
  * @brief    IIC ��һ���Ĵ���
  *
  * @param    addr  :������ַ 
  * @param    reg   :�Ĵ�����ַ
  *
  * @return   ��ȡ��ֵ
  *
  * @note     �ײ����� ��ֲʱ��Ҫ�޸�
  *
  * @see      MPU_Read_Byte(MPU6050_ADDR,WHO_AM_I);        
  *
  * @date     2019/6/12 ������
  */
uint8_t MPU_Read_Byte(uint8_t addr,uint8_t reg)
{
    uint8_t value[1];
    MPU_Read_Len(addr, reg, 1, value);
    return value[0];
}




