def graphGenerator(graph_nodes,graph_from, graph_to):
    graph=[[] for i in range(graph_nodes+2)]

    for i in range(len(graph_from)):
        u,v=graph_from[i],graph_to[i]
        graph[u].append(v)
        graph[v].append(u)

    return graph


def bfs(start,graph,graph_nodes,ids,id):
    visited=[-1 for i in range(graph_nodes+2)]
    queue=[]

    queue.append(start)
    visited[start]=0

    while len(queue)>0:
        u=queue.pop(0)

        for v in graph[u]:
            if visited[v]<0:
                if ids[v-1]==id:
                    return visited[u]+1
                else :
                    visited[v]=visited[u]+1
    return 10^9


def findShortest(graph_nodes, graph_from, graph_to, ids, val):
    graph=graphGenerator(graph_nodes,graph_from,graph_to)
    ans=10^9

    for i in range(graph_nodes):
        if ids[i]==val:
            ans=min(ans,bfs(i+1,graph,graph_nodes,ids,id))
    
    return -1 if ans == 10^9 else ans
    