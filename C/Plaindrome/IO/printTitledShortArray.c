#ifndef PRINTTITLEDSHORTARRAY
#define PRINTTITLEDSHORTARRAY

#include "printShortArray.c"

void printTitledShortArray (const char* x, const short y[], short size, _Bool newline){
	fputs(x, stdout);
	printShortArray (y, size);
	if(newline)
    	putchar('\n');
};

#endif //PRINTTITLEDSHORTARRAY