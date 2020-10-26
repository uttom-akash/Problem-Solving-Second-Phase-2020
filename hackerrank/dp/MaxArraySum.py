
def maxSubsetSum(arr):
    n=len(arr)
    dp=[[0 for x in range(n+5)] for y in range(2)]
    
    for i in range(1,n+1):
        dp[0][i]=max(dp[0][i-1],dp[1][i-1])
        dp[1][i]=dp[0][i-1]+arr[i-1]
    
    return max(dp[0][n],dp[1][n])

def main():
    n = int(input())
    arr = list(map(int, input().rstrip().split()))

    print(maxSubsetSum(arr))

if __name__ == "__main__":
    main()