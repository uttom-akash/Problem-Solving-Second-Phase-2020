

def dfs(graph,data,currNode):
    global subTreeSum,parent
    
    subTreeSum[currNode]=data[currNode-1]
    rootSum=0

    for v in graph[currNode]:
        if parent[currNode]!=v:
            parent[v]=currNode
            rootSum+=dfs(graph,data,v)
    
    subTreeSum[currNode]+=rootSum
    return subTreeSum[currNode]


def cutTheTree(data, edges):
    global subTreeSum,parent

    n=len(data)
    graph=[[] for i in range(n+1)]
    subTreeSum=[0 for i in range(n+1)]
    parent=[-1 for i in range(n+1)]

    for u,v in edges:
        graph[u].append(v)
        graph[v].append(u)
    
    totalSum=dfs(graph,data,1)
    ans=sys.maxsize
    
    for u,v in edges:
        if parent[u]==v:
            tree2=subTreeSum[u]
        else :
            tree2=subTreeSum[v]
        tree1=totalSum-tree2

        abs_diff=abs(tree1-tree2)
        ans=min(ans,abs_diff)
    
    return ans

def main():
    n=int(input())
    data=inputs(int)
    edges=[]
    for i in range(n-1):
        u,v=inputs(int)
        edges.append((u,v))
    print(cutTheTree(data,edges))

main()