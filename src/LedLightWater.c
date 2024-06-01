/*******************
LED流水灯
********************/

#include <8052.h>

#define LED_PORT	P2	//使用宏定义P2端口

/**
 * 延时函数，ten_us=1时，大约延10us
 */
void delay_10us(int ten_us) {
	while (ten_us--);
}

void main() {

   	int i=0;
	LED_PORT=~0x01;
	delay_10us(50000);

	while(1) {
		//方法1：使用移位+循环实现流水灯
		for(i=0;i<8;i++)
		{
			LED_PORT=~(0x01<<i);	//将1右移i位，然后取反将结果赋值到LED_PORT
			delay_10us(50000);
		}
	}		

}