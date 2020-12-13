import sys
from collections import deque
input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))


def bfs(ladders,snakes):
    roll=[-1]*105
    queue=deque()
    queue.append(1)
    roll[1]=0
    while queue:
        u=queue.popleft()
        for dice in range(6):
            dice+=1
            v=u+dice
            if v>100:
                break
            if ladders[v]!=-1:
                v=ladders[v]
            if snakes[v]!=-1:
                v=snakes[v]
            if roll[v]==-1:
                roll[v]=roll[u]+1
                queue.append(v)
            if roll[100]!=-1:
                return roll[100]
    return roll[100]
    

def main():
    testcase=int(input())
    while testcase>0:
        testcase-=1
        n=int(input())
        ladders,snakes=[-1]*105,[-1]*105
        for i in range(n):
            u,v=inputs(int)
            ladders[u]=v
        m=int(input())
        for i in range(m):
            u,v=inputs(int)
            snakes[u]=v
        minMove=bfs(ladders,snakes)
        # return minMove
        

main()
