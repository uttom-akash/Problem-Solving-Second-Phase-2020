import math
import os
import random
import re
import sys
from collections import defaultdict

def cmpF(a,b):
    return True if a[1]<b[1] else False

MAX_INT=sys.maxsize

class PriorityQueue:
    '''
        for asc :
            def cmp(parent,child):
                return True if parent<child else False
        
        for desc:
            def cmp(parent,child):
                return True if parent>child else False

    '''
    def __init__(self,cmp=None):
        self.cmp=cmp
        self.array=[]
        self.size=0

    def handleSizeChange(self):
        self.size=len(self.array)

    def getParent(self,child):
        return (child-1)//2
    
    # if decision is false then swap will happen 
    def compare(self,parentI,childI):
        decision=False
        if self.cmp:
            decision=self.cmp(self.array[parentI],self.array[childI])
        else :
            decision= True if self.array[parentI]<self.array[childI] else False
        return not decision
    
    def swap(self,index1,index2):
        self.array[index1],self.array[index2]=(self.array[index2],self.array[index1])

    def isEmpty(self):
        return True if self.size<=0 else False

    def heapify(self,idx):
        while True:
            smallest=idx
            left=2*idx+1
            right=2*idx+2

            if left<self.size and self.compare(smallest,left):
                smallest=left
            if right<self.size and self.compare(smallest,right):
                smallest=right

            if smallest!=idx:
                self.swap(smallest,idx)
                idx=smallest
            else :
                break 

    def push(self,element):
        self.array.append(element)
        self.handleSizeChange()

        i=self.size-1
        while i!=0 and self.compare(self.getParent(i),i):
            self.swap(self.getParent(i),i)
            i=self.getParent(i)

    def pop(self):
        if self.isEmpty():
            print("Priority Queue is empty!") 
            return None

        self.swap(0,self.size-1)
        obj=self.array.pop()
        self.handleSizeChange()
        self.heapify(0)
        return obj


class Graph:
    def __init__(self,vertices):
        self.vertices=vertices
        self.graph=defaultdict(list)
    
    def addEdge(self,u,v,w):
        self.graph[u].append((v,w))
    
    def printEdge(self,parent):
        for i in range(self.vertices):
            print(i,parent[i])


    def dijkastra(self,src):
        distance=[-1]*self.vertices
        pq=PriorityQueue(cmp=cmpF)

        pq.push((src,0))
        distance[src]=0
        while not pq.isEmpty():
            u=pq.pop()
            for v in self.graph[u[0]]:
                distNow=distance[u[0]]+v[1]
                if distance[v[0]]==-1 or distance[v[0]]>distNow:
                    pq.push(v)
                    distance[v[0]]=distNow

        return distance

def graph(n, edges, start):
    graph=Graph(n)
    seen=dict()
    for e in edges:
        u,v,w=e[0]-1,e[1]-1,e[2]
        p=(u,v)
        p2=(v,u)
        if p in seen:
            seen[p]=min(seen[p],w)
        elif p2 in seen:
            seen[p2]=min(seen[p2],w)
        else :
            seen[p]=w

    for p in seen:
        u,v=p
        w=seen[p]
        graph.addEdge(u,v,w)
        graph.addEdge(v,u,w) 
    distances=graph.dijkastra(start-1)
    return [ distances[i] for i in range(n) if i!=start-1]

input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))
def main():
    n,e=inputs(int)
    edges=[]
    for i in range(e):
        u,v,w=inputs(int)
        edges.append((u,v,w))
    start=int(input())   
    graph(n,edges,start)



main()