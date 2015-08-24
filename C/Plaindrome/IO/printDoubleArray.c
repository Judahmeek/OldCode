#ifndef PRINTDOUBLEARRAY
#define PRINTDOUBLEARRAY

#include "doubleOutput.c"

void printDoubleArray (const double y[], short precision, short size){
	putchar('{');
	short i, reducedSize = size - 1;
	for(i = 0; i < reducedSize; ++i){
		putchar(' ');
        doubleOutput(y[i], precision);
		putchar(',');
	}
	putchar(' ');
    doubleOutput(y[i],  precision);
	putchar(' ');
    putchar('}');
};

#endif //PRINTDOUBLEARRAY
