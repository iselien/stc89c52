#include <stdio.h>


void text_display(){
	int i=0;
	for(i=0;i<8;i++){
		//位选择
		switch(i){
			case 0: printf("0\n"); break;
			case 1: printf("1\n"); break;
			case 2: printf("2\n"); break;
			case 3: printf("3\n"); break;
			case 4: printf("4\n"); break;
			case 5: printf("5\n"); break;
			case 6: printf("6\n"); break;
			case 7: printf("7\n"); break;
		}

        // printf("aaa: %d\n", 7-i);

		// switch(7-i)//位选
		// {
		// 	case 0: printf("a\n"); break;
		// }

		// LSC=0; LSB=1; LSA=0;
		// TEXT=text_code[i];
		// delay_10us(200);
		// TEXT=0x00;
	}
}

int main() {
    text_display();
	return 0;
}
