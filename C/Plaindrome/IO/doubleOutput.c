#ifndef DOUBLEOUTPUT
#define DOUBLEOUTPUT

#include "intOutput.c"

void doubleOutput(double num, short precision){
	
	if(num){
		
		++precision;
		
		if(num < 0){
			putchar('-');
			num *= -1;
		}
		intOutput((int)num);
		putchar('.');
		
		num -= (int)num;
		int decimal = 0;
		short c;
		
		for(c = 0; c < precision; ++c){
			num *= 10;
			decimal = decimal * 10 + (int)num;
			num -= (int)num;
		}
		if(decimal){
			if(decimal % 10 > 4)
				decimal += 10;
			decimal /= 10;
		}else{
			--precision;
			while(--precision){
			putchar('0');
			}
		}
		intOutput(decimal);
	}
	else{
		putchar('0');
		putchar('.');
		while(precision){
			putchar('0');
			--precision;
		}
	}
}

#endif //DOUBLEOUTPUT
