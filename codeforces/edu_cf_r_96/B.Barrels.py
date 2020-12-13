
intInput = lambda:list(map(int,input().split()))

def main():
    test=int(input())
    while test>0:
        test-=1
        n,k=intInput()
        nums=intInput()
        print(sum(sorted(nums,reverse=True)[0:min(k+1,n)]))

    
if __name__ == '__main__':
    main()

