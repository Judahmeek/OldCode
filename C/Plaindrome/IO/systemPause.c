#ifndef SYSTEMPAUSE
#define SYSTEMPAUSE

#include <stdio.h>

void systemPause(){
printf("Press enter to continue...");
	char input = 0;
	while(input != '\n')
		input = getchar();
};

#endif //SYSTEMPAUSE
