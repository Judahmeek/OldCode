#ifndef PRINTTITLEDINTARRAY
#define PRINTTITLEDINTARRAY

#include "printIntArray.c"

void printTitledIntArray (const char* x, const int y[], short size, _Bool newline){
	fputs(x, stdout);
	printIntArray (y, size);
    if(newline)
    	putchar('\n');
};

#endif //PRINTTITLEDINTARRAY