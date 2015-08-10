#ifndef INSERTSWAPLINK
#define INSERTSWAPLINK

#include "insertSwap.c"

void insertSwapLink(swap* beforeSwap, int resultID, swap* afterSwap, int stateID, short index){
	insertSwap(beforeSwap, resultID, index);
	insertSwap(afterSwap, stateID, index);
}

#endif //INSERTSWAPLINK
