//�����������
#include <STC89C5xRC.H>
#include <ku.h>
#include <lcd12864.h>




void main()
	{
	
	   LCD12864_Init();
	   Uart_Init();	  //��ʼ��
	   Delayxms(300);
	 
	    SendString("AT\r\n");
		  Delayxms(100);
		
		  SendString("AT+CWMODE=3\r\n");//AT����esp32��Ӧ��wifi����ģʽ
	    Delayxms(100);//esp���� OK
	
	    SendString("AT+CWJAP=");//at�������Ӷ�Ӧ����
	    SendByte(0x22);
	    SendString("test");//��������wifi��id
	    SendByte(0x22);
	    SendString(",");
	    SendByte(0x22);
	    SendString("wasd1234");//��������wifi����
	    SendByte(0x22);
	    SendString("\r\n");
	    Delayxms(300);
			
      SendString("AT+CWJAP?\r\n");
	    
		  //��������ݷ����ж�wifi���������
		 
	   Delayxms(300);
		 fmq=0;
		 Delayxms(200);
		 fmq=1;
		 Delayxms(300);
     fmq=0;
		 Delayxms(200);
		 fmq=1;
		 Delayxms(300);
     fmq=0;
		 Delayxms(200);
		 fmq=1;
		 Delayxms(300);//������
			
	
		
		  while(1)
		{
			 if(key0==0) 
			 {
				 i=0;
				 fmq=0;
				 Delayxms(200);
			   fmq=1;
				 
				LCD12864_SetWindow(0, 0);
		while(CharCode2[i]!='\0')
		{
			LCD12864_WriteData(CharCode2[i]);
			i=i+1;
		}
			
		
				 
				}
      
				if(key1==0) 
			 {   
				 i=0;
				 fmq=0;
	
				 Delayxms(200);
			  fmq=1;
				 
				 LCD12864_SetWindow(0, 0);
		 
		while(CharCode3[i]!='\0')
		{
			LCD12864_WriteData(CharCode3[i]);
			i=i+1;
		}
			
		}
		
				
	     
				if(key2==0) 
			 {
				 i=0;
				 fmq=0;
		
				 Delayxms(200);
			   fmq=1;
				 
				 LCD12864_SetWindow(0, 0);
	    while(CharCode4[i]!='\0')
		{
			LCD12864_WriteData(CharCode4[i]);
			i=i+1;
			 }
			
		}
				 
				
	    
				if(key3==0) 
			 {
				 i=0;
				 fmq=0;
			
				 Delayxms(200);
			   fmq=1;
				 
				 LCD12864_SetWindow(0, 0);
	
		   while(CharCode5[i]!='\0')
		{
			LCD12864_WriteData(CharCode5[i]);
		i=i+1;
			 }
			
		}
				 
	}
}
