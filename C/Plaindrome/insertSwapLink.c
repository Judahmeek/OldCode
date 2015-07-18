#include "insertSwap.c"

void insertSwapLink(swapInstance* beforeSwap, int resultID, swapInstance* afterSwap, int stateID, short index){
	insertSwap(beforeSwap, resultID, index);
	insertSwap(afterSwap, stateID, index);
}
