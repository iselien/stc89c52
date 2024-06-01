/*******************
定时器中断
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

void timer0_init(){
	TMOD |= 0x01; //选择为定时器0模式，工作方式1
	TH0 = 0xFC; //给定时器赋初值，定时1ms
	TL0 = 0x18;
	ET0 = 1; //打开定时器0中断允许
	TR0 = 1; //打开定时器

	TMOD |= 0x10; //选择为定时器1模式，工作方式1
	TH1 = 0xFC; //给定时器赋初值，定时1ms
	TL1 = 0x18;
	ET1 = 1; //打开定时器1中断允许
	TR1 = 1; //打开定时器

	EA = 1; //打开总中断
}


void main() {
	timer0_init();

	while (1) {
	}
	
}

void timer0() __interrupt (1) //定时器0中断函数
{
	static int i;
	TH0 = 0xFC;
	TL0 = 0x18;
	i++;
	if(i == 1000){
		i = 0;
		LED1 = !LED1;
	}
}

void timer1() __interrupt (3) //定时器0中断函数
{
	static int i;
	TH1 = 0xFC;
	TL1 = 0x18;
	i++;
	if(i == 500){
		i = 0;
		LED2 = !LED2;
	}
}