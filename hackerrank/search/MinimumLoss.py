import sys

sys.setrecursionlimit(10**6)
input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

result=sys.maxsize

def divNConq(arr,lo,hi):
    if lo>=hi:
        return 
    
    mid=(lo+hi)//2
    divNConq(arr,lo,mid)
    divNConq(arr,mid+1,hi)
    
    global result
    i,j=lo,mid+1
    temp=[0 for x in range(hi-lo+5)]
    for k in range(hi-lo+1):
        if i>mid :
            temp[k]=arr[j]
            j+=1
        elif j>hi :
            temp[k]=arr[i]
            i+=1
        elif arr[i]>arr[j]:
            result=min(result,arr[i]-arr[j])
            temp[k]=arr[i]
            i+=1
        else :
            temp[k]=arr[j]
            j+=1
    
    for k in range(lo,hi+1):
        arr[k]=temp[k-lo]



def main():
    n=int(input())
    arr=inputs(int)

    divNConq(arr,0,n-1)
    print(result)

main()    
