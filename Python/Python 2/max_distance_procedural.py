'''
https://www.hackerrank.com/challenges/far-vertices

You are given a tree that has N vertices and N-1 edges. Your task is to mark as small number of vertices as possible, such that, the maximum distance between two unmarked vertices is less than or equal to K. Output this value. Distance between two vertices i and j is defined as the minimum number of edges you have to pass in order to reach vertex i from vertex j.

Input Format 
The first line of input contains two integers N and K. The next N-1 lines contain two integers (ui,vi) each, where 1 <= ui,vi <= N. Each of these lines specifies an edge. 
N is no more than 100. K is less than N.

Output Format 
Print an integer that denotes the result of the test.
'''

from collections import namedtuple, deque
from itertools import izip

class Node:
    Branch = namedtuple("Branch", ["neighbor", "density_at_degree", "empty"])

    @classmethod #I would have used @property here,
    #but found out that doesn't work. According to StackOverflow,
    #getting a @property effect for class variables is complicated. xD
    def max_diameter(cls, value):
        cls._max_diameter = value
        cls._max_radius = (value + 1) / 2
        cls._mr_minus_one = cls._max_radius - 1
    
    @classmethod
    def link(cls, nodes):
        nodes[0].add_connection(nodes[1])
        nodes[1].add_connection(nodes[0])
        
    def __init__(self, name):
        self.name = name
        self.connections = []
        self._density = []
        self.empty_paths = 0

    def __repr__(self):
        return "<Node: {0}, connects to : {1}>".format(self.name, [x.neighbor.name for x in self.connections])

    def add_connection(self, other):
        self.connections.append(Node.Branch(other, [], True))
        self.empty_paths = self.empty_paths + 1

    def empty_path(self):
        for link in self.connections:
            if link.empty:
                return link.neighbor

    def set_branch_density(self, node, density):
        for i in range(len(self.connections)):
            if self.connections[i].neighbor == node:
                self.connections[i] = Node.Branch(node, density, False)
                self.empty_paths = self.empty_paths - 1
                self._density = [a + b for a, b in izip(self._density, density)]
                self._density.extend(density[len(self._density):])
                break

    @classmethod
    def density(cls, node):
        if cls._max_diameter % 2 == 0:
            return sum(node._density) + 1 + len(node.connections)
        return sum(node._density[:cls._mr_minus_one - 1])\
                + 1 + len(node.connections) + max(x.density_at_degree[-1]\
                if len(x.density_at_degree) == cls._mr_minus_one\
                else 0 for x in node.connections)

    def density_as_branch(self, target):
        if len(self.connections) == 1:
            return []
        as_branch = [0] * min(len(self._density) + 1, Node._mr_minus_one)
        as_branch[0] = len(self.connections) - 1
        for i in xrange(1, len(as_branch)):
            as_branch[i] = self._density[i - 1]
        for link in self.connections:
            if link.neighbor == target:
                if link.density_at_degree != []:
                    dad_len = len(link.density_at_degree)
                    for i in xrange(1, dad_len):
                        as_branch[i] = as_branch[i] - link.density_at_degree[i - 1]
                    if dad_len < len(as_branch):
                        as_branch[dad_len] = as_branch[dad_len] - link.density_at_degree[-1]
                break
        return as_branch

nodes = {}
'''Hackerrank code
vertices, max_diameter = map(int, raw_input().split())
if max_distance == 0:
    return nodes
if max_distance == 1:
    return nodes - 1
'''

edges = [[1, 2],[1, 3],[1, 4],[1, 5],[1, 6],[7, 2],[8, 2],[9, 2],[3, 10],
[3, 11],[4, 12],[4, 13],[14, 5],[15, 6],[16, 7],[17, 7],[18, 8],[19, 9],[10, 20],
[11, 21],[13, 22],[13, 23],[13, 24],[13, 25],[13, 26],[14, 27],[14, 28],[14, 29],
[15, 30],[15, 31],[31, 36],[31, 37],[12, 32],[12, 33],[12, 34],[35, 26]]

Node.max_diameter(3)

def ensure_node(value):
    if value not in nodes:
        nodes[value] = Node(value)
    return nodes[value]

'''Hackerrank code
for i in xrange(nodes - 1):
    Node.link(map(ensure_node, raw_input().split()))
'''

for edge in edges:
    Node.link(map(ensure_node, edge))

if Node._max_diameter == 2:
    print vertices - max(len(node.connections) for node in nodes.values())

def toss(seq, i):
    seq[i], seq[-1] = seq[-1], seq[i]
    seq.pop()

completed_nodes, merged_paths = [], []
paths = [node for node in nodes.values() if len(node.connections) == 1]

while len(completed_nodes) == 0:
    for path_index,start in enumerate(paths):
        next_node = start.empty_path()
        start_density = start.density_as_branch(next_node)
        next_node.set_branch_density(start, start_density)
        if next_node.empty_paths > 1:
            merged_paths.append(path_index)
        elif next_node.empty_paths == 0:
            completed_nodes.append(next_node)
        else:
            paths[path_index] = next_node
    for i in xrange(len(merged_paths)):
        toss(paths, merged_paths.pop())

Path = namedtuple("Path", ["current", "last"])

if len(completed_nodes) == 2:
    paths = deque([Path(completed_nodes[0], completed_nodes[1]),
                  Path(completed_nodes[1], completed_nodes[0])])
else:
    paths = deque([Path(completed_nodes[0], None)])

while len(paths) > 0:
    path = paths.popleft()
    for link in path.current.connections:
        if link.neighbor == path.last or len(link.neighbor._density) < Node._mr_minus_one:
            continue
        link.neighbor.set_branch_density(path.current, path.current.density_as_branch(link.neighbor))
        paths.append(Path(link.neighbor, path.current))
        completed_nodes.append(link.neighbor)

'''Hackerrank code
print vertices - max(Node.density(node) for node in completed_nodes)
#to get best_center: max(completed_nodes, key=Node.density)
'''
