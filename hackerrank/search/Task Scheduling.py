import sys
from collections import deque


stack=deque()
stack.cou

input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

def main():
    l=[5,4,3,2,1,5,6,7]
    s=set(l)
    print(s)
    s.add(1)
    s.add(111)
    s.add(-1)
    print(s)
    

main()