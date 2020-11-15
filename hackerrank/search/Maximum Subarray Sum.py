import sys
import math

input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

def maximumSum(a, m):
    ans=0
    psum=[(0,0)]
    for i in range(len(a)):
        csum=(psum[i][0]+a[i])%m
        psum.append((csum,i+1))
        ans=max(ans,csum)

    psum.sort()

    for i in range(1,len(psum)):
        sumValue,pos=psum[i]
        prevSum,prevPos=psum[i-1]

        if prevPos>pos:
            ans=max(ans,(prevSum-sumValue)%m)

    return ans        

def main():
    print(maximumSum([3,3,9,9,5],7))

main()