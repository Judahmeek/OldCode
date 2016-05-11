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
        return sum(node._density[:node.tree.mr_minus_one - 1])\
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
        self.mr_minus_one = self.max_radius - 1

    def ensure_node(self, value):
        if value not in self.nodes:
            self.nodes[value] = Node(self, value)
        return self.nodes[value]

    def clean_nodes(self):
        for key in self.nodes:
            node = self.nodes[key]
            for index, link in enumerate(node.connections):
                node.connections[index] = Node.Branch(link.neighbor, [], True)
            node.empty_paths = len(node.connections)
            node._density = []
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
        paths = [node for node in self.nodes.values() if len(node.connections) == 1]

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
vertices, max_distance = map(int, raw_input().split())
if max_distance == 0:
    print vertices - 1
elif max_distance == 1:
    print vertices - 2
else:
    tree = Tree()
    for i in xrange(vertices - 1):
        Node.link(map(tree.ensure_node, raw_input().split()))
    print len(tree.nodes) - max(Node.density(node) for node in tree.valid_centers(max_distance))
'''
'''Idle test code'''
edges = [['78', '17'], ['6', '94'], ['1', '21'], ['50', '20'], ['2', '52'], ['27', '51'], ['9', '8'], ['63', '9'], ['17', '79'], ['56', '70'], ['57', '96'], ['37', '61'], ['98', '57'], ['82', '23'], ['39', '65'], ['9', '81'], ['63', '88'], ['47', '24'], ['60', '64'], ['85', '37'], ['37', '99'], ['16', '36'], ['48', '89'], ['41', '51'], ['19', '82'], ['94', '78'], ['86', '22'], ['94', '42'], ['65', '72'], ['20', '49'], ['33', '66'], ['93', '14'], ['1', '71'], ['53', '91'], ['86', '45'], ['82', '58'], ['23', '13'], ['12', '34'], ['4', '5'], ['76', '35'], ['60', '66'], ['8', '26'], ['39', '92'], ['39', '32'], ['46', '10'], ['45', '57'], ['73', '52'], ['64', '74'], ['67', '30'], ['80', '83'], ['46', '97'], ['50', '65'], ['21', '17'], ['25', '60'], ['90', '84'], ['2', '94'], ['11', '92'], ['44', '81'], ['47', '31'], ['21', '3'], ['88', '12'], ['27', '43'], ['27', '56'], ['46', '52'], ['17', '62'], ['39', '69'], ['28', '13'], ['16', '90'], ['4', '59'], ['38', '18'], ['7', '47'], ['81', '15'], ['76', '19'], ['7', '68'], ['58', '77'], ['6', '67'], ['4', '68'], ['83', '95'], ['87', '20'], ['71', '99'], ['30', '36'], ['27', '18'], ['96', '53'], ['50', '40'], ['55', '44'], ['10', '64'], ['54', '53'], ['41', '9'], ['7', '48'], ['29', '40'], ['93', '31'], ['77', '69'], ['60', '100'], ['48', '18'], ['95', '11'], ['35', '46'], ['4', '1'], ['75', '58'], ['53', '62']]
max_distance = 25

tree = Tree()
for edge in edges:
    Node.link(map(tree.ensure_node, edge))
print len(tree.nodes) - max(Node.density(node) for node in tree.valid_centers(max_distance))
#to get the center node: max(tree.valid_centers(max_distance), key=Node.density)

