#include <8052.h>

#define TEXT P0
#define KEY_MATRIX P1
#define LSA P2_2
#define LSB P2_3
#define LSC P2_4

int text_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07, 0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void delay_10us(unsigned int ten_us){
	while(ten_us--);
}

int matrix_scan(){
	int key_value=0;
	KEY_MATRIX=0xf7;
	if (KEY_MATRIX!=0xf7){
		delay_10us(1000);
		switch (KEY_MATRIX){
			case 0x77: key_value=1; break;
			case 0xb7: key_value=5; break;
			case 0xd7: key_value=9; break;
			case 0xe7: key_value=13; break;
		}
	}
	while(KEY_MATRIX!=0xf7);

	KEY_MATRIX=0xfb;
	if (KEY_MATRIX!=0xfb){
		delay_10us(1000);
		switch (KEY_MATRIX){
			case 0x7b: key_value=2; break;
			case 0xbb: key_value=6; break;
			case 0xdb: key_value=10; break;
			case 0xeb: key_value=14; break;
		}
	}
	while(KEY_MATRIX!=0xfb);
	
	KEY_MATRIX=0xfd;
	if (KEY_MATRIX!=0xfd){
		delay_10us(1000);
		switch (KEY_MATRIX){
			case 0x7d: key_value=3; break;
			case 0xbd: key_value=7; break;
			case 0xdd: key_value=11; break;
			case 0xed: key_value=15; break;
		}
	}
	while(KEY_MATRIX!=0xfd);
	
	KEY_MATRIX=0xfe;
	if (KEY_MATRIX!=0xfe){
		delay_10us(1000);
		switch (KEY_MATRIX){
			case 0x7e: key_value=4; break;
			case 0xbe: key_value=8; break;
			case 0xde: key_value=12; break;
			case 0xee: key_value=16; break;
		}
	}
	while(KEY_MATRIX!=0xfe);

	return key_value;
}

void main() {
	int key=0;
	while(1) {
		key=matrix_scan();
		if (key!=0) {
			TEXT=text_code[key];
		}
	}
}
