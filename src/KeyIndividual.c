/*******************
独立按键
********************/

#include <8052.h>

#define LED1 P2_0 //将P2.0管脚定义为LED1

#define KEY1 P3_1
#define KEY2 P3_0
#define KEY3 P3_2
#define KEY4 P3_3

#define KEY1_PRESS 1 
#define KEY2_PRESS 2 
#define KEY3_PRESS 3 
#define KEY4_PRESS 4 
#define KEY_UNPRESS 0 

void delay_10us(unsigned int ten_us){
	while(ten_us--);
}

int key_scan(int mode){
	static int key = 1;

	if(mode) key = 1; //连续扫描按键
	if(key==1 && (KEY1==0 || KEY2==0 || KEY3==0 || KEY4==0)){ //任意键按下
		delay_10us(1000);//消抖
		key=0;
		if(KEY1==0){
			return KEY1_PRESS;
		}else if(KEY2==0){
			return KEY2_PRESS;
		}else if(KEY3==0){
			return KEY3_PRESS;
		}else if(KEY4==0){
			return KEY4_PRESS;
		}
	}else if (KEY1==1 && KEY2==1 && KEY3==1 && KEY4==1) { //无按键按下
		key=1;
	}
	return KEY_UNPRESS;
}

int main() {
	int key = 0;
	while(1) {
		key=key_scan(0);
		if (key==KEY1_PRESS) {
			LED1=!LED1;	
		}
	}
	return 0;
}
