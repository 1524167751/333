

#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器
#include<intrins.h>		//因为要用到左右移函数，所以加入这个头文件

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

#define led P2	   //将P2口定义为led 后面就可以使用led代替P2口


void delay(u16 i)
{
	while(i--);	
}

/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void main()
{
	u8 i;
	led=0xfe;
	delay(50000); //大约延时450ms	
	while(1)
	{	
/*		for(i=0;i<8;i++)
		{
			P2=~(0x01<<i);	 //将1右移i位，然后将结果取反赋值到P2口
			delay(50000); //大约延时450ms
		}
*/		
		for(i=0;i<7;i++)	 //将led左移一位
		{
			led=_crol_(led,1);
			delay(50000); //大约延时450ms	
		}
		for(i=0;i<7;i++)	//将led右移一位
		{
			led=_cror_(led,1);
			delay(50000); //大约延时450ms	
		}	
	}		
}
