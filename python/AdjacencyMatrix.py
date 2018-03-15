#! /usr/bin/env python
# -*- coding: UTF-8 -*-

import numpy as np

class AdjacencyMatrix(object):
    
    def __init__(self, vertices=0, edges=set()):
        self.adjacency = np.matrix(np.zeros((vertices, vertices)))#[[0 for i in range(0, vertices)] for j in range(0, vertices)]
        self.visited = [False] * vertices
        for e in edges:
            self.add_edge(e)

    def __str__(self):
        s = ""
        for i in range(0, len(self.adjacency)):
            s += '\t'.join(map(str, self.adjacency[i])) + '\n'
        return s
    
    def clean_visited(self):
        self.visited = [0] * len(self.visited)
    
    def add_edge(self, edge=None):
        """Add an edge to the graph. The parameter should be a tuple (src, dest, weight)."""
        src, dest, weight = edge
        try:
            self.adjacency[src-1][dest-1] = weight
        except:
            print "Could not add edge (%d, %d)." % (src, dest)
        
    def remove_edge(self, edge=None):
        """Remove an edge of the graph.The parameter should be tuple (src, dest)"""
        self.add_edge(edge + (0,))
    
    def successors(self, vertex=0):
        return [i+1 for i, j in enumerate(self.adjacency[vertex-1]) if j != 0]
    
    def predecessors(self, vertex=0):
        return [i+1 for i, j in enumerate(zip(*self.adjacency)[vertex-1]) if j != 0]
    
    def path(self, source, destination, search='dfs'):
        
        #print "Checking %d to %d" % (source, destination)
        if source == destination:
            self.clean_visited()
            return [destination]
        
        self.visited[source-1] = True
        succ = self.successors(source)
        if len(succ) == 0:
            return None
        else:
            for i in succ:
                if self.visited[i-1]:
                    #print "Uh oh, cycle detected..."
                    continue
                res = a.path(i, destination, search)
                if res:
                    return [source] + res
            return None
    
    def shortest_path(self, source, destination, search='dijkstra'):
        print "lel"
        
                
        
a = AdjacencyMatrix(5, {(1, 2, 3.0)})
a.add_edge((2, 3, 4.0))
a.add_edge((3, 1, 2.0))
a.add_edge((2, 4, 3.0))
a.add_edge((4, 5, 2.0))
print a.path(1, 5)
print a.path(3, 1)
