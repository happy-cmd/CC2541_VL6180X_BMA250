#include <iocc2541.h>
#include <softi2c.h>
#include "vl6180x_i2c.h"
#include "bma250.h"


uint8 distance=0;
uint8 data_staus=0, data_id;
uint16 light;

/****************************************************************************
* ��    ��: InitCLK()
* ��    ��: ����ϵͳʱ��Դ
* ��ڲ���: ��
* ���ڲ���: ��
****************************************************************************/
void InitCLK()
{
    CLKCONCMD &= ~0x40;             //����ϵͳʱ��ԴΪ32MHZ����
    while(CLKCONSTA & 0x40);        //�ȴ������ȶ�Ϊ32M
    CLKCONCMD &= ~0x47;             //����ϵͳ��ʱ��Ƶ��Ϊ32MHZ   
}


int main( void )
{
    short aacx[2],aacy[2],aacz[2];	    //���ٶȴ�����ԭʼ����
    InitCLK();                      //����ϵͳʱ��Դ    
    IIC_Init();   
    VL6180X_Init();
    BMA250_Init();
    while(1)
    {   
        data_id = Check_BMA250_ID();  // 0x03
        BMA250_Get_Acceleration(aacx, aacy, aacz);
        distance = RangePollingRead();
        DelayMS(5);
      
    }
}

