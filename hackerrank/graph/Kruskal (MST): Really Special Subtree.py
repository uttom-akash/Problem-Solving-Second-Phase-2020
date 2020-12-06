from collections import defaultdict
from functools import cmp_to_key
class Graph: 
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []
        self.parent = []
        self.rank = []
        for node in range(self.V):
            self.parent.append(node)
            self.rank.append(0)
 
    def addEdge(self, u, v, w):
        self.graph.append([u, v, w])
 
    def find(self, i):
        if self.parent[i] == i:
            return i
        self.parent[i]=self.find(self.parent[i])
        return self.parent[i]

    def union(self, x, y):
        xroot = self.find(x)
        yroot = self.find(y)
        if xroot==yroot:
            return False

        if self.rank[xroot] < self.rank[yroot]:
            self.parent[xroot] = yroot
        elif self.rank[xroot] > self.rank[yroot]:
            self.parent[yroot] = xroot
        else:
            self.parent[yroot] = xroot
            self.rank[xroot] += 1
        
        return True
    
    def comp(self,item1,item2):
        if item1[2]==item2[2]:
            sum1=sum(item1)
            sum2=sum(item2)
            return sum1-sum2
        else :
            item1[2]-item2[2]   

    def KruskalMST(self):
 
        result = []
        minimumCost = 0
        e = 0
        self.graph = sorted(self.graph, 
                            key=cmp_to_key(self.comp))
 
        for u, v, w in self.graph:
            noCycle=self.union(u,v)
            if noCycle:
                e+=1
                result.append((u, v, w))
                minimumCost+=w
            if e >= self.V - 1:
                break
        
        