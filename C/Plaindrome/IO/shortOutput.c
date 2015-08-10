#ifndef SHORTOUTPUT
#define SHORTOUTPUT

#include <stdio.h>
#include"../maxPowerOf10_s.c"

void shortOutput(short num){
if(num){
	if(num < 0){
		putchar('-');
		num *= -1;
	}
	unsigned short pow10 = maxPowerOf10_s(num);
	
		while(pow10) {
		    unsigned short digit = num / pow10;
		    putchar(digit + '0');
		    num -= digit * pow10;
		    pow10 /= 10;
		}
}
else
	putchar('0');
}

#endif //SHORTOUTPUT