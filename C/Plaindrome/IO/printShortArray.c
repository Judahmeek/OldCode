#ifndef PRINTSHORTARRAY
#define PRINTSHORTARRAY

#include "shortOutput.c"

void printShortArray (const short y[], short size){
	putchar('{');
	short i, reducedSize = size - 1;
	for(i = 0; i < reducedSize; ++i){
		putchar(' ');
        shortOutput(y[i]);
		putchar(',');
	}
	putchar(' ');
    shortOutput(y[i]);
	putchar(' ');
    putchar('}');
};

#endif //PRINTSHORTARRAY