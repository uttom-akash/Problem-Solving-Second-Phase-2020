from collections import deque


def bfs(graph,s,n):
    distances=[-1 for i in range(n+1) ]
    q=deque()
    q.append(s)
    distances[s]=0
    while len(q)>0:
        u=q.popleft()
        for v in graph[u]:
            if distances[v]==-1:
                distances[v]=distances[u]+1
                q.append(v)
    return distances
    

def main():
    testc=int(input())
    while testc>0:
        testc-=1
        n,m=list(map(int,input().split()))
        graph=[[] for i in range(n+1)]
        while m>0:
            m-=1
            u,v=list(map(int,input().split()))
            graph[u].append(v)
            graph[v].append(u)
        s=int(input())
        distances=bfs(graph,s,n)
        
        ans=[]
        for i in range(1,len(distances)):
            d=distances[i]
            if d!=0:
                if d>0:
                    d*=6

                ans.append(d)
        print(*ans)
    
    
main()
