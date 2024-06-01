/*******************
串口通信
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

void uart_init(int baud){
	TMOD |= 0x20; //设置计数器工作方式2
	SCON = 0x50; //设置为工作方式1
	PCON = 0x80; //波特率加倍
	TH1 = baud; //计数器初始值设置
	TL1 = baud;
	ES = 1; //打开接收中断
	EA = 1; //打开总中断
	TR1 = 1; //打开计数器
}


void main() {
	uart_init(0xFA);

	while (1) {
	}
	
}

void uart() __interrupt (4) //串口通信中断函数
{

	delay_10us(1000);
	LED2 = !LED2;


	char rec_data;

	RI = 0;				//清除接收中断标志位
	rec_data = SBUF;	//存储接收到的数据
	rec_data = 'o';
	SBUF = rec_data;	//将接收到的数据放入到发送寄存器
	while (!TI);		//等待发送数据完成
	TI = 0;				//清除发送完成标志位
}