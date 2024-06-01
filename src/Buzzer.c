/*******************
蜂鸣器
********************/

#include <8052.h>

#define BEEP P2_5 //将P2.5管脚定义为BEEP

/**
 * 延时函数，ten_us=1时，大约延10us
 */
void delay_10us(int ten_us) {
	while (ten_us--);
}

void main() {

	int i=2000;

	while(1) {
	   	while(i--) { //循环2000次
			BEEP=!BEEP;//产生一定频率的脉冲信号
			delay_10us(100);
		}
		i=0;//清零
		BEEP=0;//关闭蜂鸣器
	}		

}