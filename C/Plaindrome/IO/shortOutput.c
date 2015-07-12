#include <stdio.h>

unsigned short findMaxPowOf10(short num) {
    int count = 0;
    unsigned short rval = 1;
    while(num / rval) 
        rval *= 10;
    return rval/10;
}

void shortOutput(short num){
if(num){
	if(num < 0){
		putchar('-');
		num *= -1;
	}
	unsigned short pow10 = findMaxPowOf10(num);
	
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
