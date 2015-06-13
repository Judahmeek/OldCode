/* https://www.hackerrank.com/contests/interfacecse-codedash/challenges/counter-game

Problem Statement
Louise and Richard play a game. They have a counter set to N. Louise gets the first turn and the turns alternate thereafter. In the game, they perform the following operations.

If N is not a power of 2, reduce the counter by the largest power of 2 less than N.
If N is a power of 2, reduce the counter by half of N.
The resultant value is the new N which is again used for subsequent operations.
The game ends when the counter reduces to 1, i.e., N == 1, and the last person to make a valid move wins.

Given N, your task is to find the winner of the game.

Update If they set counter to 1, Richard wins, because its Louise' turn and she cannot make a move.

Input Format 
The first line contains an integer T, the number of testcases. 
T lines follow. Each line contains N, the initial number set in the counter.

Constraints
1 ≤ T ≤ 10 
1 ≤ N ≤ 264 - 1

Note: Range of N is larger than long long int, consider using unsigned long long int.

Output Format
For each test case, print the winner's name in a new line. So if Louise wins the game, print "Louise". Otherwise, print "Richard". (Quotes are for clarity)

Sample Input
1
6

Sample Output
Richard

Explanation

As 6 is not a power of 2, Louise reduces the largest power of 2 less than 6 i.e., 4, and hence the counter reduces to 2.
As 2 is a power of 2, Richard reduces the counter by half of 2 i.e., 1. Hence the counter reduces to 1.
As we reach the terminating condition with N == 1, Richard wins the game.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned long long int binSearch(unsigned long long int x, unsigned long long  int a[], int l, int h){
    int middle=(l+h)/2;
    if(l==h)
        return 1;
    else if(l + 1 == h){
        return a[l];
    }else if(x == a[middle]){
        return a[middle];
    }else if(x > a[middle]){
        return binSearch(x, a, middle, h);
    }else if(x < a[middle]){
        return binSearch(x, a, l, middle);
    }else
        return -1;
};

int main() {
    unsigned long long int a[64];
    a[0] = 2;
    for(int i = 1, j = 0; i < 63; ++i, ++j)
        a[i] = a[j]*2;
    a[63] = 18446744073709551615;
    int cases, count;
    scanf("%d",&cases);
    unsigned long long int target;
    for(int o = 0; o<cases; ++o){
        count = 0;
        scanf("%llu",&target);
        while(target != 1){
            if(target % 2 == 0){
                target /= 2;
            }else{
                target -= binSearch(target, a, 0, 63);               
            }++count;
        }
        if(count % 2 == 0)
            puts("Richard");
        else
            puts("Louise");
    }
    return 0;
}