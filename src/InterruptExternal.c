/*******************
外部中断
********************/

#include <8052.h>

#define LED1 P2_0
#define LED2 P2_1
#define KEY3 P3_2
#define KEY4 P3_3

int gled_row[8]={0x38,0x7C,0x7E,0x3F,0x3F,0x7E,0x7C,0x38};//LED点阵显示图像的行数据
int gled_col[8]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};//LED点阵显示图像的列数据


void delay_10us(unsigned int ten_us){
	while(ten_us--);
}

void delay_ms(int ms) { 
	int i,j; 
	for(i=ms;i>0;i--) 
		for(j=110;j>0;j--); 
	
}

void exit_init(){
	IT1 = 1; //跳变沿触发方式（下降沿）
	EX0 = 1; //打开INT0的中断允许
	EX1 = 1; //打开INT1的中断允许
	EA = 1; //打开总中断
}


void main() {
	exit_init();

	while (1) {
	}
	
}

void exit_hander() __interrupt (0) //外部中断0中断函数
{
	delay_10us(1000);
	if (KEY3 == 0) {
		LED1 = !LED1;
	}
}

void exit2_hander() __interrupt (2) //外部中断1中断函数
{
	delay_10us(1000);
	if (KEY4 == 0) {
		LED2 = !LED2;
	}
}