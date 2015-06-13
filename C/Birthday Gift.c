/* https://www.hackerrank.com/contests/interfacecse-codedash/challenges/birthday-gift

Problem Statement
Fibsieve had a fantabulous (yes, it's an actual word) birthday party this year. He had so many gifts that he was actually thinking of not having a party next year.
Among these gifts there was an N x N glass chessboard that had a light in each of its cells. When the board was turned on a distinct cell would light up every second, and then go dark.
The cells would light up in the sequence shown in the diagram. Each cell is marked with the second in which it would light up. Follow the link to view diagram
https://docs.google.com/file/d/0B23qM-WDdPv_SlpOVWRCUHlnQWs/edit
The numbers in the grids stand for the time when the corresponding cell lights up
In the first second the light at cell (1, 1) would be on. And in the 5th second the cell (3, 1) would be on. Now, Fibsieve is trying to predict which cell will light up at a certain time (given in seconds). Assume that N is large enough.

Input
Input starts with an integer T (≤ 200), denoting the number of test cases.
Each case will contain an integer S (1 ≤ S ≤ 1015) which stands for the time.

Output
For each case you have to print the case number and two numbers (x, y), the column and the row number.

Example:

input:
3
8
20
25

Output:
Case 1: 2 3
Case 2: 5 4
Case 3: 1 5

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int cases;
    scanf("%d",&cases);
    for(int o = 0; o<cases; ++o){
        int time, d = 0, x = 1;
        scanf("%d",&time);
        while(x < time){
            ++d; //if odd, go left
            x += 2 * d;
        }
        time -= x - d;
        printf("Case %d: ", o + 1);
        if(d % 2 == 0){ //even
            if(time >= 0)
                printf("%d %d", d + 1, time + 1);
            else
                printf("%d %d", d, 0 - time);
        }
        else{
            if(time >= 0)
                printf("%d %d", time + 1, d + 1);
            else
                printf("%d %d", 0 - time, d);
        }
        putchar('\n');
    }
    return 0;
}