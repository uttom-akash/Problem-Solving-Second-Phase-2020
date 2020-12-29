input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))


import sys
from collections import defaultdict,deque
sys.setrecursionlimit(10**6)

class Graph:
    def __init__(self,vertices):
        self.vertices=vertices
        self.graph=defaultdict(list)
        self.visited=[False for i in range(vertices+1)]
        self.ans=0

    def addEdge(self,u,v):
        self.graph[u].append(v)

    def isVisited(self,node):
        return self.visited[node]

    def dfs(self,u):
        self.visited[u]=True
        nParentNodes=1
        for v in self.graph[u]:
            if not self.visited[v]:
                nNodes=self.dfs(v)
                if nNodes%2==0:
                    self.ans+=1
                else :
                    nParentNodes+=nNodes
        return nParentNodes



def evenForest(t_nodes, t_edges, t_from, t_to):
    graph=Graph(t_nodes)
    for i in range(t_edges):
        u,v=t_from[i],t_to[i]
        u,v=u-1,v-1
        graph.addEdge(u,v)
        graph.addEdge(v,u)
    graph.dfs(0)
    return graph.ans

def main():
   
    n,m=inputs(int)
    tfrom,tto=[],[]
    for i in range(m):
        u,v=inputs(int)
        tfrom.append(u)
        tto.append(v)

    cost = evenForest(n,m,tfrom,tto)
    print(cost)

main()
