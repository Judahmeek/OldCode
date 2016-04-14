'''
A small frog wants to get to the other side of a pond.
The frog is initially located on one bank of the pond (position 0) and wants to get to the other bank (position X).
The frog can jump any (integer) distance between 1 and D. If X > D then the frog cannot jump right across the pond.
Luckily, there are leaves falling from a tree onto the surface of the pond, and the frog can jump onto and from the leaves.

You are given a zero-indexed array A consisting of N integers.
This array represents falling leaves. Initially there are no leaves. A[K] represents the position where a leaf will fall in second K.
The goal is to find the earliest time when the frog can get to the other side of the pond.
The frog can jump from and to positions 0 and X (the banks of the pond) and every position with a leaf.
'''
from collections import namedtuple
def min_time_to_other_shore(falling_leaves, other_shore, max_jump):
    if max_jump >= other_shore:
        return 0
    other_shore = other_shore - max_jump
    leaves = {}
    for time, position in enumerate(falling_leaves):
        if position in leaves:
            if leaves[position] > time:
                leaves[position] = time
        else:
            leaves[position] = time
    print leaves
    current_position, max_time = 0, 0
    Leaf = namedtuple("Leaf", ['time', 'position'])
    while current_position < other_shore:
        next_leaf = Leaf(time=len(falling_leaves), position=None)
        no_possible_jumps = True
        for jump in xrange(max_jump, 0, -1):
            possible_jump = current_position + jump
            if possible_jump in leaves:
                if leaves[possible_jump] <= max_time:
                    current_position = possible_jump
                    break
                else:
                    if leaves[possible_jump] < next_leaf.time:
                        no_possible_jumps = False
                        print leaves[possible_jump], "<", next_leaf.time
                        next_leaf = Leaf(leaves[possible_jump], possible_jump)
                        print "So next_leaf now", next_leaf
        if current_position != possible_jump:
            if no_possible_jumps:
                return -1
            max_time, current_position = next_leaf
    return max_time
    

print "First:", min_time_to_other_shore([1,7,3,9,5,11,4],13,2) #Expected result: 5
print "Second:", min_time_to_other_shore([10,5,7,2,4,11,8,6,3,12,9,1], 13, 3) #3
print "Third:", min_time_to_other_shore([9,3,4,10,5,8,2,7,11,6,12,1,13], 14, 3) #8
print "Fourth:", min_time_to_other_shore([3,5,8,2,4,9,3,5,2,6,3,7,5,2], 11, 2) #9
print "Fifth:", min_time_to_other_shore([2,9,5,12,4,7], 14, 2)#not enough leaves
