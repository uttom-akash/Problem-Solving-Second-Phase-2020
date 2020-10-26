
def solution(l):
    ans,length=0,len(l)            

    for j in range(1,length-1):
        mid=l[j]
        countL,countR=0,0
        for i in range(j):
            if mid%l[i]==0:
                countL+=1
    
        for k in range(j+1,length):
            if l[k]%mid==0:
                countR+=1
        ans+=(countL*countR)
    return ans
    
def main():
    l=[1,2,4,8,16,32]
    print(solution(l))

if __name__ == "__main__":
    main()