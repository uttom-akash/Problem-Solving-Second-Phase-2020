from collections import defaultdict

class Graph:
    def __init__(self,vertices):
        self.vertices=vertices
        self.graph=defaultdict(list)
    
    def addEdge(self,u,v,w):
        self.graph[u].append((v,w))
