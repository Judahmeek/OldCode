#include <stdio.h>

void printShortArray (const char* x, const short y[], short size){
	fputs(x, stdout);
	short i;
	for(i = 0; i < size; ++i)
        printf("%d ", y[i]);
    puts("");
};

void printIntArray (const char* x, const int y[], short size){
	fputs(x, stdout);
	short i;
	for(i = 0; i < size; ++i)
        printf("%d ", y[i]);
    puts("");
};
