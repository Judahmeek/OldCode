#include "../IO/printTitledShortArray.c"
#include "../shortArrayCompare.c"

int main() {
		short x[] = {3, 2, 2};
		short y[] = {3, 2, 2};
		short arraySize = 3;
		
		if(!shortArrayCompare(x, y, arraySize)){
			printTitledShortArray("Short Arrays: ", x, arraySize, 0);
			printTitledShortArray(" == ", y, arraySize, 0);
			puts(" : Passed");
		}
		else{
			printTitledShortArray("Short Arrays: ", x, arraySize, 0);
			printTitledShortArray(" == ", y, arraySize, 0);
			puts(" : Passed");
		}
	
	return 0;
}
