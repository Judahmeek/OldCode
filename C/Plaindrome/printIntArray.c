#include "intOutput.c"

void printIntArray (const int y[], short size){
	putchar('{');
	short i, reducedSize = size - 1;
	for(i = 0; i < reducedSize; ++i){
		putchar(' ');
        intOutput(y[i]);
		putchar(',');
	}
	putchar(' ');
    intOutput(y[i]);
	putchar(' ');
    putchar('}');
};
