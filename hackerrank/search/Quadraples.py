import sys

input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

def beautifulQuadruples(a, b, c, d):
    a,b,c,d=sorted([a,b,c,d])

    max_xor=2*d+1
    mapper=[[0 for j in range(max_xor)] for i in range(c+2)]
    pairs=[0]*(c+2)

    for i in range(1,a+1):
        for j in range(i,b+1):
            mapper[j][i^j]+=1
            pairs[j]+=1

    for j in range(max_xor):
        for i in range(1,c+2):
            mapper[i][j]+=mapper[i-1][j]
          
    for i in range(1,c+2):
        pairs[i]=pairs[i-1]+pairs[i]

    ans=0
    for k in range(1,c+1):
        for l in range(k,d+1):
            totalLeftPairs=pairs[k]
            totalMachedPairs=mapper[k][k^l]

            ans+=totalLeftPairs-totalMachedPairs

    return ans

def main():
    print(beautifulQuadruples(1,2,3,4))

main()