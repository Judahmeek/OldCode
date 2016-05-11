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
        #self._distance = -1

    def __repr__(self):
        return "<Node: {0}, connects to : {1}>".format(self.name, [x.neighbor.name for x in self.connections])

    def add_connection(self, other):
        self.connections.append(Node.Branch(other, []))
    
    def density(self, degree, requester=None):
        if degree == 1:
            leaves = len(self.connections)
            if requester:
                return (leaves, leaves - 1)
            else:
                return (leaves + 1, leaves)
        if len(self.connections) == 1 and requester:
            return (1, 0)
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

class Tree:
    def __init__(self):
        self.nodes = {}

    def ensure_node(self, value):
        if value not in self.nodes:
            self.nodes[value] = Node(value)
        return self.nodes[value]

    @classmethod
    def density(cls, node):
        return node.density(Node.max_radius)[0]

    @classmethod
    def modified_density(cls, node): #if max_diameter is odd, then we add the leaves of the branch that has the most leafs
        return node.density(Node.max_radius)[0] + max(link.neighbor.density(Node.max_radius, node)[1] for link in node.connections)    

'''hackerrank code
vertices, max_diameter = map(int, raw_input().split())
if max_diameter == 0:
    print vertices - 1
elif max_diameter == 1:
    print vertices - 2
else:
    tree = Tree()
    Node.max_radius = max_diameter / 2
    for i in xrange(vertices - 1):
        Node.link(map(tree.ensure_node, raw_input().split()))

    if max_diameter % 2 == 0:
        print vertices - max(Tree.density(node) for node in tree.nodes.values())
        #to get best_center: max(nodes.values(), key=density)
    else:
        print vertices - max(Tree.modified_density(node) for node in tree.nodes.values())
        #to get best_center: max(nodes.values(), key=modified_density)
'''