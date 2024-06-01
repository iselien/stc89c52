/*******************
LED闪烁
********************/

#include <8052.h>

#define LED1 P2_0 //将P2.0管脚定义为LED1

/**
 * 延时函数，ten_us=1时，大约延10us
 */
void delay_10us(int ten_us) {
	while (ten_us--);
}

void main() {
	while(1) {
		LED1=0;	//点亮
		delay_10us(50000); //大约延时450ms
		LED1=1;	//熄灭
		delay_10us(50000); 	
	}
}