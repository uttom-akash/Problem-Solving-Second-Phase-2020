import math

def main():
    for _ in range(int(input())):
        n=int(input())
        s=input()
        count=1
        ar=[]
        for i in range(n-1):
            if(s[i+1]==s[i]):
                count+=1
            else:
                ar.append(count)
                count=1
        if(count>0):
            ar.append(count)
        ct=0
        ans=0
        for i in ar:
            if(i>1):
                ct=max(0,ct-(i-2))
                ans+=1
            else:
                ans+=1
                ct+=1
        ans-=int(math.floor(ct/2))
        print(ans)
      



if __name__ == "__main__":
    main()