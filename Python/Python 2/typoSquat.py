'''
Given the following parameters:
n: an integer representing the number of additional domains a customer is willing to purchase
domain: a string containing a top level domain. Example: "example.com"

Return: a integer representing the maximum number of typo sets that can be protected by the customer
Where: a typo set is a set of all the variants of domain which result from a set number of adjacent alphanumeric character swaps
Example: typo_set(1) = ["xeample.com", "eaxmple.com", "exmaple.com", "exapmle.com", "examlpe.com", "exampel.com", "example.ocm", "example.cmo"]
'''

from collections import deque

def typoSquat(n, domain):
    posSwaps = {domain:None}
    queue = deque()
    queue.append((domain, 0))
    old, n = 1, n + 1
    flag = False
    if len(posSwaps) == n:
        flag = True
    while old <= n:
        print old, n
        victim, level = queue.popleft()
        for i in range(len(domain) - 1):
            if victim[i] == victim[i + 1] or victim[i] == '.' or victim[i + 1] == '.':
                continue
            swap = victim[:i] + victim[i + 1] + victim[i] + victim[i + 2:]
            if not swap in posSwaps:
                queue.append((swap, level + 1))
                posSwaps[swap] = None
                if flag:
                    print "found more swaps past n"
                    return level
                if len(posSwaps) == n:
                    flag = True
        if old == len(posSwaps):
            print "n is greater than or equal to all possible swaps"
            return -1
        old = len(posSwaps)
