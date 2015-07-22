#include "shortOutput.c"
#include "intOutput.c"
#include "../swapInstance.c"

void printSwapInstanceArray (const swapInstance y[], short size){
	putchar('{');
	short i, reducedSize = size - 1;
	for(i = 0; i < reducedSize; ++i){
		putchar(' ');
		intOutput(y[i].stateID);
		putchar('-');
        shortOutput(y[i].index);
		putchar(',');
	}
	putchar(' ');
    intOutput(y[i].stateID);
	putchar('-');
    shortOutput(y[i].index);
	putchar(' ');
    putchar('}');
};
