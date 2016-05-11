''' https://www.hackerrank.com/contests/world-codesprint-april/challenges/little-alexey-and-sum-of-maximums
Alexey is playing with an array, AA, of nn integers. His friend, Ivan, asks him to calculate the sum of the maximum values for all subsegments of AA.
More formally, he wants Alexey to find F(A)=∑l=1n∑r=ln maxl≤x≤r A[x]F(A)=∑l=1n∑r=ln maxl≤x≤r A[x].

Alexey solved Ivan's challenge faster than expected, so Ivan decides to add another layer of difficulty by having Alexey answer mm queries. The ithith query contains subsegment [Li,Ri][Li,Ri], and he must calculate the sum of maximum values on all subsegments inside subsegment [Li,Ri][Li,Ri].

More formally, for each query ii, Alexey must calculate the following function:

F(A,Li,Ri)=∑l=LiRi∑r=lRimaxl≤x≤r A[x]F(A,Li,Ri)=∑l=LiRi∑r=lRimaxl≤x≤r A[x].

Can you help Alexey solve this problem?

Input Format:
The first line contains 22 space-separated positive integers, nn (the length of array AA) and mm (number of queries), respectively. 
The second line contains nn space-separated integers, a0,a1,…,an−1a0,a1,…,an−1 describing each element ajaj (where 0≤j<n0≤j<n) in array AA. 
Each of the mm subsequent lines contains 22 space-separated positive integers describing the respective values for LiLi and RiRi in query ii (where 0≤i<m0≤i<m).

Output Format:
For each query ii (where 0≤i<m0≤i<m), print its answer on a new line.
'''
class PowerSum:
    def __init__(self, list):
        self.level = [list]
    
    def max(self, pos, distance):
        #print "max", pos, distance
        if distance == 0:
            return self.level[0][pos]
        while len(self.level) <= distance:
            self.level.append({})
        #print pos, "in or not in", self.level[distance]
        if pos not in self.level[distance]:
            self.level[distance][pos] = max(self.max(pos, distance - 1), self.max(pos + 1, distance - 1))
            #print self.level[distance][pos], "= max(", self.max(pos, distance - 1), self.max(pos + 1, distance - 1)
        return self.level[distance][pos]
    
    def sum(self, pos, distance):
        if distance == 0:
            return self.level[0][pos]
        acc = self.max(pos, distance)
        #print "initial:", acc
        #print self.level, pos, distance
        for stop in xrange(1, distance):
            level = distance - stop
            for i in xrange(0, stop + 1):
                #print level, i
                acc += self.level[level][i]
        acc += sum(self.level[0][pos: pos + distance + 1])
        return acc
    
size, queries = map(int, raw_input().split())
calc = PowerSum(map(int, raw_input().split()))
for i in xrange(queries):
    query = map(int, raw_input().split())
    print calc.sum(query[0] - 1, query[1] - query[0])