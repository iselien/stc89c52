/*******************
静态显示第一位数码管
********************/

#include <8052.h>

#define NIXIE_TUBE P0 //使用宏定义数码管段码口
#define LSA P2_2
#define LSB P2_3
#define LSC P2_4

int nixie_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07, 0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void main() {
	NIXIE_TUBE=nixie_code[5]; //显示数字5
	while(1) {
	}
}
