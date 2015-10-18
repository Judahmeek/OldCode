#ifndef DOUBLEOUTPUT
#define DOUBLEOUTPUT

#include "intOutput.c"
#include "../digitSize_i.c"

void doubleOutput(double num, short precision){
	
	if(num){
		
		++precision;
		
		if(num < 0){
			putchar('-');
			num *= -1;
		}
		int temp = (int)num;
		
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
			
		if(digitSize_i(decimal) > --precision){
			intOutput(++temp);
			putchar('.');
			do
				putchar('0');
			while(--precision);
			return;
		}
		
		}else{
			intOutput(temp);
			putchar('.');
			while(--precision)
				putchar('0');
			return;
		}
		intOutput(temp);
		putchar('.');
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
