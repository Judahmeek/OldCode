#ifndef INSERTSWAPLINK
#define INSERTSWAPLINK

void insertSwapLink(int* beforeSwapPtr, int* resultIDPtr, int* afterSwapPtr, int* stateIDPtr){
	*beforeSwapPtr = *resultIDPtr;
	*afterSwapPtr = *stateIDPtr;
};

#endif //INSERTSWAPLINK
