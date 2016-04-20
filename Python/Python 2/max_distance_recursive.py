'''Although this solution does use memoization, this solution is suboptimal because it requires a density calculation from
ALL nodes of the tree, even leafs. New queries with updated max_distances are able to take advantage of previous query caches

https://www.hackerrank.com/challenges/far-vertices

You are given a tree that has N vertices and N-1 edges. Your task is to mark as small number of vertices as possible, such that,
the maximum distance between two unmarked vertices is less than or equal to K. Output this value. Distance between two vertices
i and j is defined as the minimum number of edges you have to pass in order to reach vertex i from vertex j.

Input Format 
The first line of input contains two integers N and K. The next N-1 lines contain two integers (ui,vi) each, where 1 <= ui,vi <= N.
Each of these lines specifies an edge. N is no more than 100. K is less than N.

Output Format 
Print an integer that denotes the result of the test.
'''

test_one = [[1,2],[2,3],[3,4],[2,0],[3,5],[4,6]]

from collections import namedtuple

class Node:
    Branch = namedtuple("Branch", ["neighbor", "density_at_degree"])
    
    @classmethod
    def link(cls, nodes):
        nodes[0].add_connection(nodes[1])
        nodes[1].add_connection(nodes[0])
        
    def __init__(self, name):
        self.name = name
        self.connections = []
        self._distance = -1

    def __repr__(self):
        return "<Node: {0}, connects to : {1}>".format(self.name, [x.neighbor.name for x in self.connections])

    def add_connection(self, other):
        self.connections.append(Node.Branch(other, []))
    
    def density(self, degree, requester=None):
        if len(self.connections) == 1:
            return (1, 1)
        if degree == 1:
            leaves = len(self.connections)
            if requester:
                return (leaves, leaves - 1)
            else:
                return (leaves + 1, leaves)
        lesser_degree = degree - 2
        density, leaves = 1, 0
        for link in self.connections:
            if link.neighbor == requester:
                continue
            while degree > len(link.density_at_degree):
                link.density_at_degree.append(None)
            if not link.density_at_degree[lesser_degree]:
                link.density_at_degree[lesser_degree] = link.neighbor.density(degree - 1, self)
            density = density + link.density_at_degree[lesser_degree][0]
            leaves = leaves + link.density_at_degree[lesser_degree][1]
        return (density, leaves)

nodes = {}

'''Hackerrank code
vertices, max_diameter = map(int, raw_input().split())
if max_diameter == 0:
    return vertices - 1
if max_diameter == 1:
    return vertices - 2
Node.max_radius = max_diameter / 2
'''# Remember to provide initialize Node.max_radius a value when testing


edges = [[1, 2],[1, 3],[1, 4],[1, 5],[1, 6],[7, 2],[8, 2],[9, 2],[3, 10],
[3, 11],[4, 12],[4, 13],[14, 5],[15, 6],[16, 7],[17, 7],[18, 8],[19, 9],[10, 20],
[11, 21],[13, 22],[13, 23],[13, 24],[13, 25],[13, 26],[14, 27],[14, 28],[14, 29],
[15, 30],[15, 31],[31, 36],[31, 37],[12, 32],[12, 33],[12, 34],[35, 26]]


def ensure_node(value):
    if value not in nodes:
        nodes[value] = Node(value)
    return nodes[value]

'''Hackerrank code
for i in xrange(vertices - 1):
    Node.link(map(ensure_node, raw_input().split()))
'''
for edge in edges:
    Node.link(map(ensure_node, edge))

def density(node):
    return node.density(Node.max_radius)[0]

def modified_density(node): #if maxdiameter is odd, then we add the leaves of the branch that has the most leafs
    return node.density(Node.max_radius)[0] + max(link.neighbor.density(Node.max_radius, node)[1] for link in node.connections)

'''Hackerrank code
if max_diameter % 2 == 0:
    print vertices - max(density(node) for node in nodes.values())
    #to get best_center: max(nodes.values(), key=density)
else:
    print vertices - max(modified_density(node) for node in nodes.values())
    #to get best_center: max(nodes.values(), key=modified_density)
'''
