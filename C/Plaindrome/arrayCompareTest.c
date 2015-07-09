#include <stdio.h>
#include "arrayCompare.c"

int main() {
	{
	short x[] = {3, 2, 2};
	short y[] = {3, 2, 2};
	short arraySize = 3;
	
	if(!shortArrayCompare(x, y, arraySize))
		puts("Short Arrays: {3, 2, 2} == {3, 2, 2} : Passed");
	else
		puts("Short Arrays: {3, 2, 2} == {3, 2, 2} : Failed");
	}
	
	{
	int x[] = {3, 2, 2};
	int y[] = {3, 2, 2};
	short arraySize = 3;
	
	if(!intArrayCompare(x, y, arraySize))
		puts("Int Arrays: {3, 2, 2} == {3, 2, 2} : Passed");
	else
		puts("Int Arrays: {3, 2, 2} == {3, 2, 2} : Failed");
	}
	
	return 0;
}
