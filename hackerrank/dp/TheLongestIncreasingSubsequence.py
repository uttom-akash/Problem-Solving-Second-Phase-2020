from bisect import bisect_left
import sys
input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

def lis(n,l):
    least,length=[0]*(n+5),0
    least[0]=-10
    
    for i in range(n):
        pos=bisect_left(least,l[i],0,length+1)
        length=max(pos,length)
        least[pos]=l[i]
    
    return length

def main():
    n=int(input())
    l=[]
    for i in range(n):
        a=int(input())
        l.append(a)

    print(lis(n,l))

main()