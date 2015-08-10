#include <stdio.h>
#include"../maxPowerOf10_i.c"

void intOutput(int num){
if(num){
	if(num < 0){
		putchar('-');
		num *= -1;
	}
	unsigned int pow10 = maxPowerOf10_i(num);
	
		while(pow10) {
		    unsigned int digit = num / pow10;
		    putchar(digit + '0');
		    num -= digit * pow10;
		    pow10 /= 10;
		}
}
else
	putchar('0');
}
