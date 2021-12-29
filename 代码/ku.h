#include <STC89C5xRC.H>
#include <lcd12864.h>

sbit key0 = P1^0;
sbit key1 = P1^1;
sbit key2 = P1^2;
sbit key3 = P1^3;
sbit fmq = P1^5;

unsigned char i;
unsigned char a;
unsigned char code CharCode0[]="WiFi连接成功！";
unsigned char code CharCode2[]="我生病了！    ";
unsigned char code CharCode3[]="失火了！      ";
unsigned char code CharCode4[]="电路故障！    ";
unsigned char code CharCode5[]="其他求助！    ";
unsigned char code CharCode6[]="欢迎使用求助机";

void Uart_Init()	//波特率9600
{
	SCON = 0x40;
	PCON |=0x80;
	TMOD &= 0x0F;	
	TMOD |= 0x20;	
	TL1 = 0xFA;		
	TH1 = 0xFA;	
  RI = 1;
	ET1 = 0;
	TR1 = 1;
	EA = 1;
	ES = 1;
}


void Uart_SendByte(unsigned char Byte)//发数据
{ 
	SBUF = Byte;
	while(TI == 0);
	TI = 0;
  
}


void Delayxms(unsigned int xms)		//@12.000MHz 凑合用
{
	unsigned char i, j;
	while(xms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		xms--; 
	}
}


void SendByte(unsigned char Byte)		//100微秒@12.000MHz
{
	SBUF = Byte;
	while(TI==0);
	TI=0;
  
}

void SendString(char *s)    // 发字符串
{
	while(*s)
	{
		SendByte(*s++);
	}

}

		void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 180;
	j = 73;
	do
	{
		while (--j);
	} while (--i);
}



void receive(void) interrupt 4
{ P14 = 0;
	if(RI)
	{RI=0;
	a=a+1;
  }
	if(a=175)
	{
	
		LCD12864_SetWindow(0, 0);
		while(CharCode0[i]!='\0')
		{
			LCD12864_WriteData(CharCode0[i]);
			i=i+1;
		}
	
  }
}
          
