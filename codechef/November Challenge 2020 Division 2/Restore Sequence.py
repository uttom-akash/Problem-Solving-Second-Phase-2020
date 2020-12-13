import sys
input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

def sieve(n):  
    primes = [True]*(n+5) 
    primes[0]= False
    primes[1]= False
    for x in range(4,n+1,2):
        primes[x]=False

    p = 3
    while (p * p <= n):     
        if (primes[p] == True):   
            for i in range(p * p, n + 1, 2*p): 
                primes[i] = False
        p += 2
    primeList=[]
    for i in range(n+1):
        if primes[i]:
            primeList.append(i)
    return primeList


def main():
    primesList=sieve(4000000)
    print(primesList[-1])
    testcase=int(input())
    while testcase>0:
        testcase-=1
        n=int(input())
        b=inputs(int)
        a=[1 for i in range(n)]

        pIndex=0
        for ai in range(n):
            bi=b[ai]-1
            if a[bi]!=1:
                a[ai]=a[bi]
                continue

            if a[ai]==1:
                a[ai]=primesList[pIndex]
                if bi!=ai:
                    a[bi]*=primesList[pIndex]
                pIndex+=1
        print(*a)   

main()


    