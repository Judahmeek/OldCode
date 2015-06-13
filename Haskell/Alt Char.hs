{- https://www.hackerrank.com/challenges/alternating-characters
 
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
 
-}

{- This was my first attempt. The code works, but has horrible time complexity.
Attempts to improve complexity through use of foldl' and U.Vector were unsuccessful.
At the time of this exercise, I had yet to find a way of estimating the time complexity
of Haskell code. -}

import Data.List.Split (splitOn)

solve :: (Eq a) => [a] -> Int
solve (x:xs)
    | length xs == 0 = 0
    | x == head xs = 1 + solve xs
    | x /= head xs = solve xs

main = do
    x <- getContents
    let list = drop 1 $ splitOn "\n" x
    putStr $ unlines $ map show $ map (solve) list