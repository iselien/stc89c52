#include <8052.h>

#define TEXT P0
#define LSA P2_2
#define LSB P2_3
#define LSC P2_4

int text_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07, 0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void delay_10us(unsigned int ten_us){
	while(ten_us--);
}

void text_display(){
	int i=0;
	for(i=0;i<8;i++){
		//位选择
		switch(i){
			case 0: LSC=1; LSB=1; LSA=1; break;
			case 1: LSC=1; LSB=1; LSA=0; break;
			case 2: LSC=1; LSB=0; LSA=1; break;
			case 3: LSC=1; LSB=0; LSA=0; break;
			case 4: LSC=0; LSB=1; LSA=1; break;
			case 5: LSC=0; LSB=1; LSA=0; break;
			case 6: LSC=0; LSB=0; LSA=1; break;
			case 7: LSC=0; LSB=0; LSA=0; break;
		}
		TEXT=text_code[i];
		delay_10us(100);
		TEXT=0x00;
	}
}

void main() {
	while(1) {
		//静态显示单个字符
		// TEXT=text_code[3];
		//动态显示多个字符
		text_display();
	}
}
