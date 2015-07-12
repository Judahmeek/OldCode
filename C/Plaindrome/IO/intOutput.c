#include <stdio.h>
#include"../findIntLength.c"

void intOutput(int num){
if(num){
	if(num < 0){
		putchar('-');
		num *= -1;
	}
	unsigned int pow10 = findIntLength(num);
	
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
