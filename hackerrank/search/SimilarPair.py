#!/bin/python3

import os
import sys
sys.setrecursionlimit(10**9)

def bitQuery(biTree,index):
    res=0
    while index > 0 :
        res+=biTree[index]
        index-=(index & -index)
    return res
    
def biUpdate(biTree,index,value):
    length=len(biTree)
    while index < length:
        biTree[index]+=value
        index+=(index & -index)
    

def dfs(graph,biTree,n,u,k,visited):
    visited[u]=True
    similarPairs=bitQuery(biTree,min(u+k,n))-bitQuery(biTree,max(0,u-k-1))
    biUpdate(biTree,u,1)
    
    for v in graph[u]:
        if visited[v]==False:
            similarPairs+=dfs(graph,biTree,n,v,k,visited)
    
    biUpdate(biTree,u,-1)
    return similarPairs
    
def similarPair(n, k, edges):
    deg=[0 for i in range(n+1)]
    biTree=[0 for i in range(n+1)]
    graph=[[] for i in range(n+1)]
    visited=[False for i in range(n+1)]
    
    for edge in edges:
        u,v=edge
        graph[u].append(v)
        deg[v]+=1
    root=0    
    for i in range(1,n+1):
        if deg[i]==0:
            root=i
            break
    res=dfs(graph,biTree,n,root,k,visited) 
    return res 
        

if __name__ == '__main__':
    nk = input().split()
    n = int(nk[0])
    k = int(nk[1])
    edges = []
    for _ in range(n-1):
        edges.append(list(map(int, input().rstrip().split())))

    result = similarPair(n, k, edges)
    print(str(result) + '\n')