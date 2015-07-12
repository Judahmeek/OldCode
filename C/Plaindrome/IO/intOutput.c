#include <stdio.h>

unsigned int findMaxPowOf10(int num) {
    int count = 0;
    unsigned int rval = 1;
    while(num / rval) 
        rval *= 10;
    return rval/10;
}

void intOutput(int num){
if(num){
	if(num < 0){
		putchar('-');
		num *= -1;
	}
	unsigned int pow10 = findMaxPowOf10(num);
	
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
