#include "arraySum.c"

void bufferSignature(const short freq[], const short freqSize, const short state[], const short stateSize, short result[]){
	short i, j = 0;
	
	short copy[freqSize];
	for(i = 0; i < freqSize; ++i){
		copy[i] = freq[i];
	}
	
	short total = 0;
	for(i = 0; i < stateSize; ++i){
		result[i] = total;
		total += arraySum (copy, freqSize) - copy[state[j]];
		--copy[state[j]];
		++j;
	}
}
