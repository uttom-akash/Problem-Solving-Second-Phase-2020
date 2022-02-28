from collections import deque
import math

inf = 1000000000

class Graph:
    def __init__(self, graph):
        self.graph = graph 
        self.row = len(graph)

    def bfs(self, source, sink, parent):
        visited = [False] * self.row
        queue = deque()

        queue.append(source)
        visited[source] = True

        while queue:
            u = queue.popleft()

            for v, rflow in enumerate(self.graph[u]):
                if (visited[v] == False) and (rflow > 0):
                    queue.append(v)
                    visited[v] = True
                    parent[v] = u

        return visited[sink]

    def edmonds_karp(self, ssource, ssink):

        parent = [-1] * self.row

        max_flow = 0
        while self.bfs(ssource, ssink, parent):

            path_flow = inf
            v = ssink
            while v != ssource:
                u = parent[v]
                path_flow = min(path_flow, self.graph[u][v])
                v = parent[v]

            max_flow += path_flow

            v = ssink
            while v != ssource:
                u = parent[v]
                self.graph[u][v] -= path_flow
                self.graph[v][u] += path_flow
                v = parent[v]

        return max_flow


def solution(entrances, exits, path):
    nodes = len(path)
    graph = path 

    graph.append([ 0 for _ in range(nodes)])
    graph.append([ 0 for _ in range(nodes)])
    nodes=nodes + 2

    for i in range(nodes):
        graph[i].append(0)
        graph[i].append(0)
    

    for src in entrances:
        graph[nodes-2][src]=inf
    
    for ex in exits:
        graph[ex][nodes-1]=inf


    G = Graph(graph=graph)

    maxSafeBunny = G.edmonds_karp(nodes-2,nodes-1)

    return maxSafeBunny


ans = solution([0], [3], [[0, 7, 0, 0], [0, 0, 6, 0], [0, 0, 0, 8], [9, 0, 0, 0]])
print(ans)
    