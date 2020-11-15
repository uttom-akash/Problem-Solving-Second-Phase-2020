import sys
import math 
input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

def getMod(value):
    mod=1000000007
    return value%mod

def getOdd(value):
    return value if value%2==1 else value-1

def getEven(value):
    return value if value%2==0 else value-1

def main():
    testcase=int(input())
    while testcase>0:
        testcase-=1
        N=int(input())
        A=inputs(int)

        pSum=[[0 for j in range(N+1)] for i in range(3)]
        onePos=-1
        for i in range(N):
            currChoc=A[i]
            pSum[0][i+1]=getMod(pSum[0][i]+getEven(currChoc))
            pSum[1][i+1]=getMod(pSum[0][i]+getOdd(currChoc))
            pSum[2][i+1]=getMod(pSum[0][i]+currChoc)

            if currChoc==1:
                onePos=i

                
        Q=int(input())
        while Q>0:
            Q-=1
            R=int(input())
            ans=0
            if onePos==0:
                res,rem=getMod(math.ceil(R/N)) ,R%N
                if res>1 and rem==1:
                    res-=1
                ans=getMod(res)
            elif onePos==-1 or onePos==N-1:
                res,rem=getMod(R//N),R%N
                ans=getMod(pSum[1][N]*res)
                if rem==0:
                    if pSum[1][N]!=pSum[2][N]:
                        ans=getMod(ans+1)
                else:
                    ans=getMod(ans+pSum[2][rem])
            else :
                res,rem=getMod(R//N),R%N
                ans=getMod(getMod(pSum[1][onePos]+pSum[1][N]-pSum[0][onePos])*res)
                if rem==0:
                    if pSum[1][N]!=pSum[2][N]:
                        ans=getMod(ans+1)
                elif rem-1<=onePos:
                    ans=getMod(ans+pSum[2][rem])
                else :
                    ans=getMod(ans+pSum[1][onePos]+pSum[2][rem]-pSum[0][onePos])

            
            print(ans)



main()