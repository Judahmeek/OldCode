https://www.hackerrank.com/challenges/simple-array-sum

/*
Problem Statement

You are given an array of integers of size N. You need to print the sum of the elements of the array.

Input Format 
The first line of the input consists of an integer N. The next line contains N space-separated integers describing the array.

Constraints 
1≤N≤1000 
0≤A[i]≤1000

Output Format 
Output a single value equal to the sum of the elements of the array.

Sample Input

6
1 2 3 4 10 11
Sample Output

31
Explanation 
1+2+3+4+10+11=31
*/

def arraySum (a, b)
    return a+b
end
gets
input = gets.chomp.split.map {|c| c.to_i}
total = 0
input.each do |num|
    total = total + num
end
puts total