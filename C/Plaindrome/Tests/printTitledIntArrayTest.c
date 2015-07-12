#include "../IO/printTitledIntArray.c"

int main(){
	int x[] = {0, -1, 2};
	fputs("x[]: { 0, -1, 2 } is output as ", stdout);
	printTitledIntArray("x[]: ", x, 3, 0);
	puts("//no newline test");
	return 0;
}
