import sys
input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

def didPassTest(k,j,i,sheets,blocked):
    if j<i:
        j,i=i,j    
    score=k+1-(j-i)-(sheets[j]-sheets[i])
    if score>0 and blocked[j]-blocked[i]==0:
        return True
    else :
        return False

    
def main():
    testcase=int(input())
    while testcase>0:
        testcase-=1
        n,k=inputs(int)
        s=input()

        sheets=[0 for i in range(n+1)]
        blocks=[0 for i in range(n+1)]

        for i in range(n):
            sheets[i+1]=sheets[i]
            blocks[i+1]=blocks[i]
            if s[i]==':':
                sheets[i+1]+=1
            if s[i]=='X':
                blocks[i+1]+=1
        
        LMI,LII,ans=0,0,0
        visited=[False for i in range(n)]
        for i in range(n):
            if s[i]=='M':
                while LII<i:
                    if s[LII]=='I' and visited[LII]==False and didPassTest(k,i,LII,sheets,blocks):
                        ans+=1
                        visited[i],visited[LII]=True,True
                        break
                    LII+=1
            elif s[i]=='I':
                while LMI<i:
                    if s[LMI]=='M' and visited[LMI]==False and didPassTest(k,i,LMI,sheets,blocks):
                        ans+=1
                        visited[i],visited[LMI]=True,True
                        break
                    LMI+=1
        print(ans)


main()