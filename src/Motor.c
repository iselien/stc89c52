#include <8052.h>

#define DC_MOTOR P1_0
#define DC_MOTOR_RUN_TIME 50

void delay_10us(unsigned int ten_us){
	while(ten_us--);
}

void delay_ms(int ms) { 
	int i,j; 
	for(i=ms;i>0;i--) 
		for(j=110;j>0;j--); 
	
}

void main() {
	DC_MOTOR=1;
	delay_ms(DC_MOTOR_RUN_TIME);
	DC_MOTOR=0;
}
