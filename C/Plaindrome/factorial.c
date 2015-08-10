#ifndef FACTORIAL
#define FACTORIAL

int factorial(short x){
	int y = 1;
	while(x > 1){
		y *= x;
		--x;
	}
	return y;
};

#endif //FACTORIAL