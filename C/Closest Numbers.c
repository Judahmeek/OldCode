/* https://www.hackerrank.com/contests/interfacecse-codedash/challenges/closest-numbers

Problem Statement
Sorting is often useful as the first step in many different tasks. The most common task is to make finding things easier, but there are other uses, as well.

Challenge 
Given a list of unsorted integers, A={a1,a2,…,aN}, can you find the pair of elements that have the smallest absolute difference between them? If there are multiple pairs, find them all.

Input Format 
The first line of input contains a single integer, N, representing the length of array A. 
In the second line, there are N space-separated integers, a1,a2,…,aN, representing the elements of array A.

Output Format 
Output the pairs of elements with the smallest difference. If there are multiple pairs, output all of them in ascending order, all on the same line (consecutively) with just a single space between each pair of numbers. If there's a number which lies in two pair, print it two times (see the sample case #3 for explanation).

Constraints
2≤N≤200000
−107≤ai≤107
ai≠aj,where 1≤i<j≤N

Sample Input #1
10
-20 -3916237 -357920 -3620601 7374819 -7330761 30 6246457 -6461594 266854
 
Sample Output #1
-20 30

Explanation 
(30) - (-20) = 50, which is the smallest difference.

Sample Input #2
12
-20 -3916237 -357920 -3620601 7374819 -7330761 30 6246457 -6461594 266854 -520 -470 

Sample Output #2
-520 -470 -20 30
Explanation 
(-470) - (-520) = 30 - (-20) = 50, which is the smallest difference.

Sample Input #3
4
5 4 3 2

Sample Output #3
2 3 3 4 4 5

Explanation 
Here, the minimum difference will be 1. So valid pairs are (2, 3), (3, 4), and (4, 5). So we have to print 2 once, 3 and 4 twice each, and 5 once.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void siftDown(int *a, int root, int end){

    while(root * 2 + 1 <= end){
        int child = root * 2 + 1;
        int swap = root;

        if(a[swap] < a[child])
            swap = child;
        if(child+1 <= end && a[swap] < a[child+1])
            swap = child + 1;
        if(swap == root)
            return;
        else{
            int temp = a[root];
	        a[root] = a[swap];
	        a[swap] = temp;
            root = swap;
        }
    }
};

void heapify(int *a, int count){
    int start = floor ((count - 2) / 2);
    
    while(start >= 0){
        siftDown(a, start, count - 1);
        start = start - 1;
    }
};

void heapsort(int *a, int count){
    heapify(a, count);
    int end = count - 1;
    while (end > 0){
        int temp = a[end];
	    a[end] = a[0];
	    a[0] = temp;
        end = end - 1;
        siftDown(a, 0, end);
    }
};

int main() {
    int size, diff, mark = 0, i = 0;
    int MinDiff = 20000001;
    scanf("%d",&size);
    int duce = size*2;
    int a[size];
    int res[duce];
    while (scanf("%d", &a[i++]) == 1)
        /* empty loop */ ;
    heapsort(a, size);
    for(int i = 1; i<size; ++i){
        diff = a[i] - a[i-1];
        if(diff < MinDiff){
            mark = 2;
            res[0] = a[i-1];
            res[1] = a[i];
            MinDiff = diff;
        }
        else if(diff == MinDiff){
            res[mark++] = a[i-1];
            res[mark++] = a[i];
        }
    }
    printf("%d", res[0]);
    for(int i = 1; i<mark; ++i){
        printf(" %d", res[i]);
    }
    return 0;
}