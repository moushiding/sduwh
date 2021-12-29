#ifndef __LCD12864_H
#define __LCD12864_H

//---����ͷ�ļ�---//

#include <STC89C5xRC.H>
//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

//---���ʹ�û�ͼģʽ�������---//

//#define LCD12864_PICTURE

//---����ʹ�õ�IO��---//

#define LCD12864_DATAPORT P0	  //����IO��

sbit LCD12864_RS  =  P2^2;             //����������Ĵ���ѡ������ 
sbit LCD12864_RW  =  P2^3;             //Һ����/д����
sbit LCD12864_EN  =  P2^4;             //Һ��ʹ�ܿ���
sbit LCD12864_PSB =  P2^1;             //��/����ʽ����
sbit LCD12864_RST =  P2^0;			   //��λ��


//---����ȫ�ֺ���---//
void LCD12864_Delay1ms(uint c);
uchar LCD12864_Busy(void);
void LCD12864_WriteCmd(uchar cmd);
void LCD12864_WriteData(uchar dat);
void LCD12864_Init();
void LCD12864_ClearScreen(void);
void LCD12864_SetWindow(uchar x, uchar y);

#endif
