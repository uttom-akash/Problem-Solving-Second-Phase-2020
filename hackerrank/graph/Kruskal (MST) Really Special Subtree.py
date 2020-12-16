from functools import cmp_to_key
import sys

sys.setrecursionlimit(10**6)
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
        decision=0
        if item1[2]==item2[2]:
            sum1=sum(item1)
            sum2=sum(item2)
            decision = sum1-sum2
        else :
            decision = item1[2]-item2[2]
        
        return decision   

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
        return minimumCost


input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))
        
def main():
    nodes,edges=inputs(int)
    graph=Graph(nodes)
    for i in range(edges):
        u,v,w=inputs(int)
        u,v=u-1,v-1
        graph.addEdge(u,v,w)

    totalWeight=graph.KruskalMST()
    print(totalWeight)

main()
