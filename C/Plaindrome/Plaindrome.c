#include <stdio.h>
#include <stdlib.h>

int adjustForSkippedRows (const int* palList, short numPalindrome, int state){
	
	short low = -1, high = numPalindrome, middle = numPalindrome/2;
	while(high - low != 1){
    	if(palList[middle] - state > 0){
    		high = middle;
    		middle = (high - low)/2 + low;
		} else {
    		low = middle;
    		middle = (high - low)/2 + low;
		}
	}
	return state - high;
};

int factorial(short x){
	int y = 1;
	while(x > 1){
		y *= x;
		--x;
	}
	return y;
};

int arrayFactorial(const short x[], short size, short startingIndex, short minus){
	short i = startingIndex;
	int total = factorial(x[i++] - minus);
	while(i < size){
		total *= factorial(x[i++]);
	}
	return total;
};

void AverageAbsorbingStateResults (double** matrix, int rows, int columns, int targetState){
	int j;
	double total = 0;
	for (j = rows; j < columns; ++j)
		total += matrix[targetState][j];

	printf("%.4f", total);
};

void invertMatrix (double** matrix, int rows, int columns, int* targetState){
	
	int i, j, pivot, max, stopPivot = rows - 1, subtractor, rowAbove;
	double* tempPtr;
	for (pivot = 0; pivot < stopPivot; ++pivot){
		max = pivot;
		
		for(i = pivot + 1; i < rows; ++i){
			if(abs(matrix[i][pivot]) > abs(matrix[max][pivot])){
				max = i;
			}
		}
		if(*targetState == max)
			*targetState = pivot;
		else if (*targetState == pivot)
			*targetState = max;
		
		if(max != pivot){
			tempPtr = matrix[pivot];
			matrix[pivot] = matrix[max];
			matrix[max] = tempPtr;
		}
		for(i = pivot + 1; i < rows; ++i){
			for(j = pivot + 1; j < columns; ++j){
				matrix[i][j] = matrix[i][j] - matrix[pivot][j] * (matrix[i][pivot] / matrix[pivot][pivot]);
			}
			matrix[i][pivot] = 0;
		}
	}
	for(; pivot > 0; --pivot){
		rowAbove = pivot - 1;
		if(matrix[pivot][pivot] != 1){
			for(i = rows; i < columns; ++i)
				matrix[pivot][i] /= matrix[pivot][pivot];
			matrix[pivot][pivot] = 1;
		}
		for(subtractor = pivot; subtractor < rows; ++subtractor){
			if(matrix[rowAbove][subtractor] != 0)
				for(i = rows; i < columns; ++i)
					matrix[rowAbove][i] -= matrix[subtractor][i] * matrix[rowAbove][subtractor];
			matrix[rowAbove][subtractor] = 0;
		}
	}
	for(i = rows; i < columns; ++i)
		matrix[pivot][i] /= matrix[pivot][pivot];
	matrix[pivot][pivot] = 1;
};

void promotionSignature (const short freq[], short freqSize, int result[], short resultSize, short startingIndex){
	short i, j = 0, k = 0;
	while(freq[j] == 0){
			++j;
	}
	
	short remainingDigits = resultSize - startingIndex;
	
	for(i = 0; i < startingIndex; ++i){
		result[i] = -1;
	}
	
	for(; i < resultSize; ++i){
		result[i] = factorial(remainingDigits) / arrayFactorial(freq, freqSize, j, k);
		if(!result[i])
			++result[i];
		++k;
		while(k == freq[j]){
			++j;
			k = 0;
		}
		--remainingDigits;
	}
};

void steps2state(const short freq[], short freqSize, short result[], short stateSize, int steps){
	short sigSize = stateSize - 1;
	int sig[sigSize];
	short i = 0, j = 0, target = 0;
	
	short copy[freqSize];
	for(i = 0; i < freqSize; ++i)
		copy[i] = freq[i];
	
	--copy[0];
	promotionSignature(copy, freqSize, sig, sigSize, 0);
	
    for(i = 0; i < sigSize; ++i){
    	while( steps >= sig[i]){
    		steps -= sig[i];
    		++copy[target];
    		++target;
			if(target == freqSize)
				target = 0;
			while(copy[target] == 0){
				++target;
				if(target == freqSize)
					target = 0;
			}
    		--copy[target];
			
			promotionSignature(copy, freqSize, sig, sigSize, i);
		}
		j = 0;
		while(copy[j] == 0){
			++j;
		}
		result[i] = target;
		target = j;
		--copy[j];
	}
	result[sigSize] = target;
};

int state2steps(const short freq[], short freqSize, short state[], short stateSize){
	
	short copy[freqSize];
	short i = 0;
	for(i = 0; i < freqSize; ++i){
		copy[i] = freq[i];
	}
	--copy[0];
	
	short zeroState[stateSize];
	steps2state(freq, freqSize, zeroState, stateSize, 0);
	
	int steps = 0;
	short sigSize = stateSize - 1;
	int sig[sigSize];
	promotionSignature(copy, freqSize, sig, sigSize, 0);
	
	for(i = 0; i < sigSize;){
		if(state[i] == zeroState[i]){
			--copy[zeroState[++i]];
		} else {
			steps += sig[i];
			++copy[zeroState[i]];
    		++zeroState[i];
			while(copy[zeroState[i]] == 0){
				++zeroState[i];
			}
    		--copy[zeroState[i]];
			promotionSignature(copy, freqSize, sig, sigSize, i);
			
			short k = i, l, m;
			for(l = 0; l < freqSize; ++l){
				for(m = 0; m < copy[l]; ++m){
					zeroState[++k] = l;
				}
			}
		}
	}
	return steps;
};

void insertSwapLink(int* beforeSwapPtr, int* resultIDPtr, int* afterSwapPtr, int* stateIDPtr){
	*beforeSwapPtr = *resultIDPtr;
	*afterSwapPtr = *stateIDPtr;
};

short arraySum (const short x[], short size){
	int total = 0;
	short i;
	for(i = 0; i < size; ++i){
		total += x[i];
	}
	return total;
};

void bufferSignature(const short freq[], const short freqSize, const short state[], const short sigSize, short result[]){
	short i, j = 0;
	
	short copy[freqSize];
	for(i = 0; i < freqSize; ++i){
		copy[i] = freq[i];
	}
	
	short total = 0;
	for(i = 0; i < sigSize; ++i){
		total += arraySum (copy, freqSize) - copy[state[j]];
		result[i] = total;
		--copy[state[j]];
		++j;
	}
};

void skipNonStateChangingSwaps(short* state, short stateSize, short* swapRecordIndexPtr, short bufferSignatureRow[], short* lowIndexPtr, short* highIndexPtr){
	do {
		if(*swapRecordIndexPtr >= bufferSignatureRow[*lowIndexPtr]){
			++*lowIndexPtr;
			*highIndexPtr = *lowIndexPtr + 1;
		}else
			++*highIndexPtr;
	} while (state[*lowIndexPtr] == state[*highIndexPtr]);
};

void scanSwapRecord(short* state, short stateSize, int swapRow[], short* swapRecordIndexPtr, short bufferSignatureRow[], short* lowIndexPtr, short* highIndexPtr, short tscs){
	while(swapRow[*swapRecordIndexPtr] != -1 && *swapRecordIndexPtr < tscs){
		++*swapRecordIndexPtr;
		skipNonStateChangingSwaps(state, stateSize, swapRecordIndexPtr, bufferSignatureRow, lowIndexPtr, highIndexPtr);
	}
};

int** initializeSwapRecord(const short freq[], short freqSize, short stateSize, int totalStates, int tscs){
	
	int stateID, i;
	short sigSize = stateSize - 1;
	short bufferSig[totalStates][sigSize];
	short states[totalStates][stateSize];
	
	int** swapRecord = (int **)malloc(sizeof(int *) * totalStates);
    swapRecord[0] = (int *)malloc(sizeof(int) * totalStates * tscs);
    for(i = 0; i < totalStates; ++i)
        swapRecord[i] = (*swapRecord + tscs * i);
    
	for(stateID = 0; stateID < totalStates; ++stateID){ //Initializing
		steps2state(freq, freqSize, states[stateID], stateSize, stateID);
		bufferSignature(freq, freqSize, states[stateID], sigSize, bufferSig[stateID]);
		for(i = 0; i < tscs; ++i){
			swapRecord[stateID][i] = -1;
		}
	}
	
	short lowIndex, highIndex, swapRecordIndex, swapStateBuffer, partnerSwapIndex, j;
	short swapState[stateSize];
	for(stateID = 0; stateID < totalStates; ++stateID){
	
    	swapRecordIndex = 0, lowIndex = 0, highIndex = 1;
    	
    	while (states[stateID][lowIndex] == states[stateID][highIndex]){
    		if(swapRecordIndex >= bufferSig[stateID][lowIndex]){
				++lowIndex;
				highIndex = lowIndex + 1;
			}else
				++highIndex;
		}
    	
    	scanSwapRecord(states[stateID], stateSize, swapRecord[stateID], &swapRecordIndex, bufferSig[stateID], &lowIndex, &highIndex, tscs);
    	
    	while(swapRecordIndex < tscs){
			for(j = 0; j < stateSize; ++j)
				swapState[j] = states[stateID][j];
			
			swapState[lowIndex] = states[stateID][highIndex];
			swapState[highIndex] = states[stateID][lowIndex];
			
			swapStateBuffer = 0;
			for(j = lowIndex + 1; j < highIndex; ++j)
				if(swapState[lowIndex] != swapState[j])
					++swapStateBuffer;
			int partnerID = state2steps(freq, freqSize, swapState, stateSize);
			
			if(lowIndex == 0)
				partnerSwapIndex = swapStateBuffer;
			else
				partnerSwapIndex = bufferSig[partnerID][lowIndex - 1] + swapStateBuffer;
			
			insertSwapLink(&swapRecord[stateID][swapRecordIndex], &partnerID, &swapRecord[partnerID][partnerSwapIndex], &stateID);
			++swapRecordIndex;
			skipNonStateChangingSwaps(states[stateID], stateSize, &swapRecordIndex, bufferSig[stateID], &lowIndex, &highIndex);
			scanSwapRecord(states[stateID], stateSize, swapRecord[stateID], &swapRecordIndex, bufferSig[stateID], &lowIndex, &highIndex, tscs);
		}
	}
	return swapRecord;
};

double** prepareFundamentalMatrix(int** swapRecord, int totalStates, int tscs, int* palList, short numPalindrome, int posSwaps){
	
	int i;
	int swapsThatMaintainState = (posSwaps - tscs);
	double stmsPercentageOfPosSwaps = (double)swapsThatMaintainState/(double)posSwaps;
	double singleSwapsPercentageOfPosSwaps = 1.0/(double)posSwaps;
	double identityMatrixMinusSTMSPOPS = 1.0 - stmsPercentageOfPosSwaps;
	double identityMatrixMinusSSPOPS = -singleSwapsPercentageOfPosSwaps;
	
	int rows = totalStates - numPalindrome;
	int columns = rows * 2;
	double** matrix = (double **)malloc(rows * sizeof(double *));
	matrix[0] = (double *)calloc(rows * columns, sizeof(double));
	for(i = 0; i < rows; ++i)
		matrix[i] = (matrix[0] + columns * i);
	
	int j = 0;
	short swapRecordIndex;
	for(i = 0; i < rows; ++i, ++j){
    	
        while(swapRecord[j][0] == -tscs)
        	++j;
        
        matrix[i][adjustForSkippedRows(palList, numPalindrome, j)] = identityMatrixMinusSTMSPOPS;
        matrix[i][adjustForSkippedRows(palList, numPalindrome, j) + rows] = 1.0;
        
		if(swapRecord[j][0] < 0)
			swapRecordIndex = -swapRecord[j][0];
		else
			swapRecordIndex = 0;
		
        for(; swapRecordIndex < tscs; ++swapRecordIndex)
        	matrix[i][adjustForSkippedRows(palList, numPalindrome, swapRecord[j][swapRecordIndex])] = identityMatrixMinusSSPOPS;
	}
	return matrix;
};

int* palindromeList(const short freq[], short freqHalf[], short freqSize, short stateSize, short numPalindrome){
	
	int* list = (int*)malloc(numPalindrome * sizeof(int));
	
	short i, j, halfSize = stateSize / 2, size = stateSize - 1;
	short state[stateSize];
	if(stateSize % 2 != 0){
		state[halfSize] = freqSize - 1;
	}
	
	for(i = 0; i < numPalindrome; ++i){
		
		steps2state(freqHalf, freqSize, state, halfSize, i);
		for(j = 0; j < halfSize; ++j)
			state[size - j] = state[j];
		
		list[i] = state2steps(freq, freqSize, state, stateSize);
	}
	
	return list;
};

void sanitizeSwapRecord(int** swapRecord, int totalStates, const int* palList, short numPalindrome, int tscs){
	
	int i, k, l, m;
	int *palindrome, *partner;
	for(i = 0; i < numPalindrome; ++i){
		palindrome = swapRecord[palList[i]];
		for(k = 0; k < tscs; ++k){
			partner = swapRecord[palindrome[k]];
			for(l = 0; l < tscs; ++l){
				for(m = 0; m < numPalindrome; ++m){
					if(partner[l] == palList[m]){
						if(partner[0] > 0){
							partner[l] = partner[0];
							partner[0] = -1;
						} else {
							partner[l] = partner[partner[0] * -1];
							--partner[0];
						}
					}
				}
			}
		}
		palindrome[0] = -tscs;
	}
};

int main() {
    short cases, o;
    scanf("%hd",&cases);
    getchar();
    for(o = 0; o<cases; ++o){
        const short SIZE = 26;
        short i,c = 0,memLimit = 8, stateSize = 0;
        short* freq = (short*)calloc(SIZE, sizeof(short));
        short* inputState = (short*)malloc(sizeof(short) * memLimit);
        while(c != '\n'){
            c = getchar();
            if(c >= 'a' && c <= 'z'){
                c -= 'a';
                inputState[stateSize] = c;
                ++stateSize;
                if(stateSize > memLimit){
                    memLimit *= 2;
                    void* reallocResult = realloc(inputState, sizeof(short) * memLimit);
                    if(!reallocResult){
                        short* temp = (short*)malloc(sizeof(short) * memLimit);
                        for(i = 0; i<stateSize; ++i)
                            temp[i] = inputState[i];
                        inputState = temp;
                    } else
                        inputState = (short*) reallocResult;
                }
                ++freq[c];
            }
        }

        short odd = 0, freqSize = 0, oddValue;
        for(i = 0; i<SIZE; ++i){
            if(freq[i] > 0){
                ++freqSize;
            }
        }

        if(freqSize < 2)
            puts("0.0000");
        else{

            short newFreq[freqSize];
            c = -1;
            for(i = 0; i<SIZE; ++i){
                if(freq[i] > 0){
                    if(freq[i] % 2 != 0){
                        ++odd;
                        newFreq[freqSize - 1] = freq[i];
                        freq[i] = freqSize - 1;
                    } else {
                        newFreq[++c] = freq[i];
                        freq[i] = c;
                    }
                }
            }

            for(i = 0; i<stateSize; ++i){
                inputState[i] = freq[inputState[i]];
            }

            free(freq);

            int inputStateID = state2steps(newFreq, freqSize, inputState, stateSize);

            short tscs = 0;
            for(i = 0; i < freqSize; ++i){
                tscs += newFreq[i] * (stateSize - newFreq[i]);
            }
            tscs /= 2;

            int totalStates = factorial(stateSize)/arrayFactorial(newFreq, freqSize, 0, 0);
            int posSwaps = stateSize * (stateSize - 1) / 2;

            short freqHalf[freqSize];
            for(i = 0; i < freqSize; ++i){
                freqHalf[i] = newFreq[i] / 2;
            }
            short numPalindrome = factorial(stateSize/2)/arrayFactorial(freqHalf, freqSize, 0, 0);

            int rows = totalStates - numPalindrome;
            int columns = rows * 2;

            int* palList = palindromeList(newFreq, freqHalf, freqSize, stateSize, numPalindrome);
            int** swapRecord = initializeSwapRecord(newFreq, freqSize, stateSize, totalStates, tscs);
            sanitizeSwapRecord(swapRecord, totalStates, palList, numPalindrome, tscs);
            double** MarkovMatrix = prepareFundamentalMatrix(swapRecord, totalStates, tscs, palList, numPalindrome, posSwaps);
            inputStateID = adjustForSkippedRows(palList, numPalindrome, inputStateID);
            invertMatrix(MarkovMatrix, rows, columns, &inputStateID);
            AverageAbsorbingStateResults(MarkovMatrix, rows, columns, inputStateID);
        }
    }
    return 0;
}

