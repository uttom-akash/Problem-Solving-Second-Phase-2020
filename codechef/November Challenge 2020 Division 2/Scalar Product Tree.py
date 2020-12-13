import sys
from collections import deque
input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

def getMod(value):
    mod=2**32
    return value%mod

def dfs(graph,s,N):
    stack=deque()
    stack.append(s)
    parent=[ -1 for i in range(N)]

    while len(stack)>0:
        u=stack.pop()
        for v in graph[u]:
            if parent[u]!=v:
                parent[v]=u
                stack.append(v)
    return parent


def main():
    N,Q=inputs(int)
    Ws=inputs(int)
    graph=[[] for i in range(N)]

    e=N-1
    while e>0:
        e-=1
        u,v=inputs(int)
        u,v=u-1,v-1
        graph[u].append(v)
        graph[v].append(u)
    
    parent=dfs(graph,0,N)

    while Q>0:
        Q-=1
        u,v=inputs(int)
        u,v=u-1,v-1
        ans=getMod(Ws[u]*Ws[v])
        while True:
            u,v=parent[u],parent[v]
            if u==-1 or v==-1:
                break
            ans=getMod(ans+getMod(Ws[u]*Ws[v]))
        print(ans)

main()