#ifndef PRINTSWAPARRAY
#define PRINTSWAPARRAY

#include "shortOutput.c"
#include "intOutput.c"
#include "../swap.c"

void printSwapArray (const swap y[], short size){
	putchar('{');
	short i, reducedSize = size - 1;
	for(i = 0; i < reducedSize; ++i){
		putchar(' ');
		intOutput(y[i].partnerID);
		putchar('-');
        shortOutput(y[i].index);
		putchar(',');
	}
	putchar(' ');
    intOutput(y[i].partnerID);
	putchar('-');
    shortOutput(y[i].index);
	putchar(' ');
    putchar('}');
};

#endif //PRINTSWAPARRAY