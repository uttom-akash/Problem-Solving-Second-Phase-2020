import sys
input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

def power(x, y, p) : 
    res = 1     
    x = x % p  

    if (x == 0) : 
        return 0
    
    while (y > 0) :   
        if ((y & 1) == 1) : 
            res = (res * x) % p 
        y = y >> 1  
        x = (x * x) % p  
    return res 


def main():
    testcase=input(int)
    while testcase>0:
        testcase-=1
        N=input(int)
        Wheels=inputs(int)


main()