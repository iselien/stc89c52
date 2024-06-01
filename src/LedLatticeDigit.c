/*******************
LED点阵
********************/

#include <8052.h>

#define LED P0

#define SRCLK P3_6
#define RCLK P3_5
#define SER P3_4


int gled_row[8]={0x00,0x7C,0x82,0x82,0x82,0x7C,0x00,0x00};//LED点阵显示数字0的行数据
int gled_col[8]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};//LED点阵显示数字0的列数据


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

	while(1) {

		for (i = 0; i < 8; i++){ //循环8次扫描8行、列
			LED=gled_col[i]; //传送列选数据
			hc595_write_code(gled_row[i]); //传送行选数据
			delay_10us(100); //延时一段时间，等待显示稳定
			hc595_write_code(0x00); //消影
		}
	}
}
