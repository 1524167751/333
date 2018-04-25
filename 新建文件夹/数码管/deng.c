#include<at89x51.h>
unsigned char code segdata[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
char time;
void delay(void)
{
   unsigned char i,j;
   for(i=4;i>0;i--)
     for(j=250;j>0;j--);
}
main()
{
   time=0;
   EA=1;
   EX0=1;
   IT0=1;
   EX1=1;
   IT1=1;
   while(1)
   {
     P2=0xfd;
	 P0=segdata[time/10];
	 delay();
	 P2=0xfe;
	 P0=segdata[time%10];
	 delay();
	}
}

void int0(void) interrupt 0 using 0
{
   time++;
   if(time>99)
   {
      time=0;
	}
}

void int1(void) interrupt 2 using 1
{
    time--;
	if(time<0)
	{  
	   time=0;
	}
}