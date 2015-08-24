#ifndef DOUBLEOUTPUT
#define DOUBLEOUTPUT

#include "intOutput.c"

void doubleOutput(double num, short precision){
	
	if(num){
		
		--precision;
		int multiplier = 10;
		
		while(precision){
			while(precision % 2 == 0){
				precision /= 2;
				multiplier *= multiplier;
			}
			multiplier *= 10;
			--precision;
		}
	
		if(num < 0){
			putchar('-');
			num *= -1;
		}
		intOutput((int)num);
		putchar('.');
		intOutput((int)((num - (int)num) * multiplier));
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
