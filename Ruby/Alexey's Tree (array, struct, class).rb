=begin
https://www.hackerrank.com/contests/codestorm/challenges/little-alexeys-tree

Problem Statement

Little Alexey was playing with trees while studying powerful tree algorithms.

Recently, he discovered a tree with n vertices. On each edge, there's a lowercase English letter written on it.

If we concatenate all the letters on the path from vertex u to vertex v, we can write some word. Little Alexey is interested in the largest lexicographical words.

For every vertex u, find a vertex v to create a string that is lexicographically largest by concatenating all the letters on the path from u to v. If the vertices are lexicographically the same size, find the one with the largest number.

Input Format

On the first line, you are given a single positive integer n: the number of vertices in the tree. Each of the next n−1 lines contains space-separated positive integers ai, bi and a character ci, that describes an edge between ai and bi with ci written on the edge.

Constraints

1≤n≤2⋅104
1≤ai,bi≤n
ci is a lowercase English letter

Output Format

Print n space-separated positive integers: the answer for the task.

Sample Input 1

4
1 2 a
2 3 a
3 4 b
Sample Output 1

4 4 4 1
Sample Input 2

9
1 2 b
2 3 a
2 4 c
1 6 c
6 5 d
6 7 c
1 9 d
9 8 e
Sample Output 2

8 4 4 8 8 5 5 5 8
Explanation

Let's look at the first sample. A way between 1 and 4 corresponds to string ′aab′. A way between 2 and 4 corresponds to ′ab′. A way between 3 and 4 corresponds to ′b′. A way between 4 and 1 corresponds to ′baa′. It's easy to see that these paths are the lexicographically largest.

This solution doesn't properly solve the given problem, but I kept it because I prefer it's emergent qualities.
=end

class Vertex

    Data = Struct.new(:number, :preference, :secondary, :strength, :secondaryStrength, :connections)

    def initialize(num)
        @data = Data.new(num, 0, 0, 'a', 'a', 0)
    end
    
    attr_accessor :data
    
    def isLeaf?
        @data.connections == 1
    end
    
    def addBranch(addition, letter)
        if @data.connections == 0
            @data.connections = 1
            @data.preference = addition
            @data.strength = letter
        else
            @data.connections = @data.connections + 1
            if letter > @data.strength or (@data.strength == letter and addition > @data.preference)
                @data.secondary = @data.preference
                @data.secondaryStrength = @data.strength
                @data.preference = addition
                @data.strength = letter
            elsif letter > @data.secondaryStrength or (@data.secondaryStrength == letter and addition > @data.secondary)
                @data.secondary = addition
                @data.secondaryStrength = letter
            end
        end
    end
    
    def followPath(verti)
        i = @data.preference
        from = @data.number
        until verti[i].isLeaf?
            unless verti[i].data.preference == from
                from = i
                i = verti[i].data.preference
            else
                from = i
                i = verti[i].data.secondary
            end
        end
        return i
    end
end

treeSize = gets.to_i
verti = []
connectionNum = [0] * treeSize
for i in 0..treeSize
    verti << Vertex.new(i)
end
for i in 1...treeSize
    input = gets.chomp.split
    input[0] = input[0].to_i
    input[1] = input[1].to_i
    verti[input[0]].addBranch(input[1], input[2])
    verti[input[1]].addBranch(input[0], input[2])
end
puts verti.map{ |v| v.followPath(verti) if v.data.number > 0 }.join(" ").strip!