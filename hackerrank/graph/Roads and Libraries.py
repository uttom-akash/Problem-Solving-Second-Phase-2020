import sys
input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

from collections import defaultdict,deque

class Graph:
    def __init__(self,vertices):
        self.vertices=vertices
        self.graph=defaultdict(list)
        self.visited=[False for i in range(vertices)]

    def addEdge(self,u,v):
        self.graph[u].append(v)

    def isVisited(self,node):
        return self.visited[node]

    def bfs(self,src):
        q=deque()
        q.append(src)
        self.visited[src]=True
        node=0
        while len(q)>0:
            u=q.popleft()
            node+=1
            for v in self.graph[u]:
                if not self.visited[v]:
                    q.append(v)
                    self.visited[v]=True
        return node



def getRoadConstCost(node,roadCost):
    return (node-1)*roadCost

def roadsAndLibraries(n, c_lib, c_road, cities):
    graph=Graph(n)
    for edge in cities:
        u,v=edge
        u,v=u-1,v-1
        graph.addEdge(u,v)
        graph.addEdge(v,u)
    
    forest=[]
    for u in range(n):
        if not graph.isVisited(u):
            nodes=graph.bfs(u)
            forest.append(nodes)
    ans=0
    for treeInForest in forest:
        onlyRoadCost=getRoadConstCost(treeInForest,c_road)
        onlyLibraryCost=treeInForest*c_lib
        ans+=min(onlyLibraryCost,onlyRoadCost+c_lib)
    return ans

def main():
    testC=int(input())
    while testC>0:
        testC-=1
        n,m,c_lib,c_road=inputs(int)
        cities=[]
        for i in range(m):
            u,v=inputs(int)
            cities.append((u,v))
        cost= roadsAndLibraries(n,c_lib,c_road,cities)
        print(cost)

main()
