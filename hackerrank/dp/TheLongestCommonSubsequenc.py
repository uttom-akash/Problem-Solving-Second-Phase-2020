import sys
input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

def getlcs(lcs,n,m,a,b):
    i,j=n,m
    ans=[]
    while i!=0 and j!=0:

        if i>0 and j>0 :
            if lcs[i][j]==lcs[i-1][j-1]+1 and a[i-1]==b[j-1]:
                ans.append(a[i-1])
                i,j=i-1,j-1
            elif lcs[i][j-1]>lcs[i-1][j]:
                i,j=i,j-1
            else :
                i,j=i-1,j
        elif i>0 :
            i,j=i-1,j
        else :
            i,j=i,j-1
    ans.reverse()
    return ans


def longestCommonSubsequence(n,m,a, b):
    lcs=[[0 for j in range(m+1) ] for i in range(n+1)]
    for i in range(n+1):
        for j in range(m+1):
            if i==0 or j==0 :
                lcs[i][j]=0
            elif a[i-1]==b[j-1]:
                lcs[i][j]=lcs[i-1][j-1]+1
            else :
                lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j])
    return getlcs(lcs,n,m,a,b)    

def main():
    n,m=inputs(int)
    a=inputs(int)
    b=inputs(int)
    print(longestCommonSubsequence(n,m,a,b))


main()