import sys
input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

def getComputedInterval(x,y,last,S,N):
    L=(x+S*last-1)%N
    R=(y+S*last-1)%N

    return (L,R) if L<=R else (R,L)

def main():
    N,Q,S=inputs(int)
    H=inputs(int)
    pSum=[]

    mxSat=1
    dp=[1 for i in range(N)]
    for i in range(N-1,-1,-1):
        j=i+1
        lastH=H[i]
        tSat=1
        while j<N:
            curH=H[j]
            if lastH<curH:
                tSat+=dp[j]
                break
            j+=1
        dp[i]=tSat
        mxSat=max(mxSat,tSat)


    for i in range(0,N):
        midAns=1
        lastH=H[i]
        j=i+1
        pSum.append([])
        pSum[i].append(midAns)
        while j<N:
            currH=H[j]
            if lastH<currH:
                midAns+=1
                lastH=currH
            pSum[i].append(midAns)
            j+=1
        
    last=0
    while Q>0:
        Q-=1
        x,y=inputs(int)
        L,R=getComputedInterval(x,y,last,S,N)

        ans=1
        for i in range(L,R+1):
            ans=max(pSum[i][R-i],ans)
        last=ans
        print(ans) 

main()