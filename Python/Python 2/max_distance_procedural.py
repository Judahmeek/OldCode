'''By finding the center node(s) of the tree, this solution limits density calculations to nodes that are at least max_distance
away from the farthest leaf within the same branch. However, new queries with updated max_distances are unable to take advantage
of the results of previous node density calculations.

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

from collections import namedtuple, deque
from itertools import izip

class Node:
    Branch = namedtuple("Branch", ["neighbor", "density_at_degree", "empty"])
    
    @classmethod
    def link(cls, nodes):
        nodes[0].add_connection(nodes[1])
        nodes[1].add_connection(nodes[0])
        
    def __init__(self, tree, name):
        self.name = name
        self.tree = tree
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
        if node.tree.max_diameter % 2 == 0:
            return sum(node._density) + 1 + len(node.connections)
        return sum(node._density[:node.tree._mr_minus_one - 1])\
                + 1 + len(node.connections) + max(x.density_at_degree[-1]\
                if len(x.density_at_degree) == node.tree.mr_minus_one\
                else 0 for x in node.connections)

    def density_as_branch(self, target):
        if len(self.connections) == 1:
            return []
        as_branch = [0] * min(len(self._density) + 1, self.tree.mr_minus_one)
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

class Tree:

    def __init__(self):
        self.nodes = {}
        self.dirty = False
    
    def set_max_distance(self, value):
        self.max_diameter = value
        self.max_radius = (value + 1) / 2
        self.mr_minus_one = cls._max_radius - 1

    def ensure_node(self, value):
        if value not in self.nodes:
            self.nodes[value] = Node(self, value)
        return self.nodes[value]

    def clean_nodes(self):
        for node in nodes:
            for index, link in enumerate(node.connections)
                node.connections[index] = Node.Branch(link.neighbor, [], True)
            node.empty_paths = len(node.connections)
        self.dirty = False

    def valid_centers(self, max_distance):
        if max_distance == 2:
            return self.nodes.values()

        if self.dirty:
            self.clean_nodes()
        self.dirty = True
        self.set_max_distance(max_distance)
        
        def fast_del(llst, i):
            llst[i], llst[-1] = llst[-1], llst[i]
            llst.pop()

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
                    break
                else:
                    paths[path_index] = next_node
            for i in xrange(len(merged_paths)):
                fast_del(paths, merged_paths.pop())

        Path = namedtuple("Path", ["current", "last"])
        paths = deque([Path(completed_nodes[0], None)])

        while len(paths) > 0:
            path = paths.popleft()
            for link in path.current.connections:
                if link.neighbor == path.last or len(link.neighbor._density) < self.mr_minus_one:
                    continue
                link.neighbor.set_branch_density(path.current, path.current.density_as_branch(link.neighbor))
                paths.append(Path(link.neighbor, path.current))
                completed_nodes.append(link.neighbor)
        return completed_nodes

        
'''Hackerrank code
vertices, max_diameter = map(int, raw_input().split())
if max_distance == 0:
    return nodes
if max_distance == 1:
    return nodes - 1

for i in xrange(nodes - 1):
    Node.link(map(tree.ensure_node, raw_input().split()))
'''

edges = [[1, 2],[1, 3],[1, 4],[1, 5],[1, 6],[7, 2],[8, 2],[9, 2],[3, 10],
[3, 11],[4, 12],[4, 13],[14, 5],[15, 6],[16, 7],[17, 7],[18, 8],[19, 9],[10, 20],
[11, 21],[13, 22],[13, 23],[13, 24],[13, 25],[13, 26],[14, 27],[14, 28],[14, 29],
[15, 30],[15, 31],[31, 36],[31, 37],[12, 32],[12, 33],[12, 34],[35, 26]]

for edge in edges:
    Node.link(map(tree.ensure_node, edge))

tree = Tree()

'''Hackerrank code
print len(tree.nodes) - max(Node.density(node) for node in tree.valid_centers(max_distance))
#to get the center node: max(tree.valid_centers(max_distance), key=Node.density)
'''
