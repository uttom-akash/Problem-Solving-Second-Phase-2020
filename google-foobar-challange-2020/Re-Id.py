
def getPrimeStr(primes,n):
    primeStr=''
    for p in range(n + 1): 
        if primes[p]: 
            primeStr+=str(p) 
    
    return primeStr
  

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

    return getPrimeStr(primes,n)


def solution(n):
    primeStr=sieve(20500)
    return primeStr[n:n+5]




if __name__=='__main__': 
    solution(0) 
    solution(3) 