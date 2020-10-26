
df_agents=[]
sp_agents=[]
cost=[]
dp=[[-1 for x in range(100002)]*4002]
n=0

intArrayInput=lambda : [int(x) for x in input().split()]

def rec(pos,icost,pa):
    if pos>=n:
        return icost 
    if dp[pos][icost] !=-1 :
        return dp[pos][icost]
    c_cost=1000000

    if pa<=sp_agents[pos]:
        c_cost=min(c_cost,rec(pos+1,icost+cost[pos],sp_agents[pos]))
    if pa<=df_agents[pos]:
        c_cost=min(c_cost,rec(pos+1,icost,df_agents[pos]))
    
    dp[pos][c_cost]=1
    return dp[pos][c_cost]

def cleanup():
    dp=[[-1 for x in range(100002)]*4002]
    n=int(input())
    df_agents=intArrayInput()
    sp_agents=intArrayInput()
    cost=intArrayInput()
    

def main():
    test=int(input())
    while test>0:
        test-=1
        cleanup()
        print(rec(0,0,-1))
        

if __name__ == "__main__":
    main()

#Night@Visitor