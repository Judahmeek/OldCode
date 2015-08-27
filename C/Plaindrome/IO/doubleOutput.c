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
		
		double remainder = (num - (int)num);
		num -= (int)num;
		int decimal = 0;
		while(precision){
			num *= 10;
			decimal = decimal * 10 + (int)num;
			printf("\ndecimal: %d\n", decimal);
			num -= (int)num;
			--precision;
		}
		if(decimal){
			if(decimal % 10 > 4)
				decimal += 10;
			else
				decimal -= 10;
			decimal /= 10;
		}
		if(!decimal){
			while(precision){
			putchar('0');
			--precision;
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
