import sys
import math
input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

def main():
    testcase=int(input())
    while testcase>0:
        testcase-=1
        n=int(input())
        ci=inputs(int)
        
        totalMin=sum(ci)
        dp=[False for i in range(totalMin+1)]
        dp[0]=True
        for i in range(n):
            for j in range(totalMin,0,-1):
                if j>=ci[i] and dp[j-ci[i]]:
                    dp[j]=True
        
        ans=sys.maxsize
        for i in range(totalMin,0,-1):
            if dp[i]:
                ans=min(ans,max(i,totalMin-i))   

        print(ans)


main()