from collections import defaultdict
import sys

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


    def primMST(self,src):
        key=[MAX_INT]*self.vertices
        inMST=[False]*self.vertices
        parent=[-1]*self.vertices
        pq=PriorityQueue(cmp=cmpF)

        pq.push((src,0))
        key[src]=0
        cost=0
        while not pq.isEmpty():
            u=pq.pop()
            inMST[u[0]]=True

            for v in self.graph[u[0]]:
                if inMST[v[0]]==False and key[v[0]]>v[1]:
                    pq.push(v)
                    key[v[0]]=v[1]
                    parent[v[0]]=u[0]
                    cost+=v[1]

        return (parent,cost)


graph = Graph(9) 
graph.addEdge(0, 1, 4) 
graph.addEdge(0, 7, 8) 
graph.addEdge(1, 2, 8) 
graph.addEdge(1, 7, 11) 
graph.addEdge(2, 3, 7) 
graph.addEdge(2, 8, 2) 
graph.addEdge(2, 5, 4) 
graph.addEdge(3, 4, 9) 
graph.addEdge(3, 5, 14) 
graph.addEdge(4, 5, 10) 
graph.addEdge(5, 6, 2) 
graph.addEdge(6, 7, 1) 
graph.addEdge(6, 8, 6) 
graph.addEdge(7, 8, 7) 
parent=graph.primMST(0) 
print(parent[1])
graph.printEdge(parent[0])