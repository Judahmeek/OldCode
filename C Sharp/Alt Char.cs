/*

 https://www.hackerrank.com/challenges/alternating-characters
 
Problem Statement

Shashank likes strings in which consecutive characters are different. For example, he likes ABABA, while he doesn't like ABAA. Given a string containing characters A and B only, he wants to change it into a string he likes. To do this, he is allowed to delete the characters in the string.

Your task is to find the minimum number of required deletions.

Input Format

The first line contains an integer T, i.e. the number of test cases. 
The next T lines contain a string each.

Output Format

For each test case, print the minimum number of deletions required.

Constraints

1≤T≤10 
1≤ length of string ≤105
Sample Input

5
AAAA
BBBBB
ABABABAB
BABABA
AAABBB

Sample Output

3
4
0
0
4

Explanation

AAAA ⟹ A, 3 deletions
BBBBB ⟹ B, 4 deletions
ABABABAB ⟹ ABABABAB, 0 deletions
BABABA ⟹ BABABA, 0 deletions
AAABBB ⟹ AB, 4 deletions

*/

// I left the default hackerrank using statements. Had this been development code, I would have restricted using statements to minimize chances of namespace collisions.

using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    static void Main(String[] args) {
        int sent = Convert.ToInt32(Console.ReadLine());
        for( ; sent > 0; sent-=1){
            String target = Console.ReadLine();
            int count = 0;
            int length = target.Length - 1;
            for(int i = 0; i<length; ++i){
                if(target[i] == target[i + 1])
                    ++count;
            }
            Console.WriteLine(count);
        }
    }
}