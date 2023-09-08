#include <8052.h>

#define LED P0

#define SRCLK P3_6
#define RCLK P3_5
#define SER P3_4


int hc595_code[8]={0x0f,0x02,0x04,0x08,0x10,0x20,0x40,0x80};


void delay_10us(unsigned int ten_us){
	while(ten_us--);
}

void delay_ms(int ms) { 
	int i,j; 
	for(i=ms;i>0;i--) 
		for(j=110;j>0;j--); 
	
}

void hc595_write_code(int code){
	int i=0;
	for (i = 0; i < 8; i++){
		SER=code>>7;
		code<<=1;
		SRCLK=0;
		delay_10us(1);
		SRCLK=1;
		delay_10us(1);
	}
	RCLK=0;
	delay_10us(1);
	RCLK=1;
}

void main() {
	int i=0;

	LED=0x00;
	while(1) {
		for (i = 0; i < 8; i++){
			hc595_write_code(0x00);
			hc595_write_code(hc595_code[i]);
			delay_ms(500);
		}
	}
}
