

def main():
    test=int(input())
    while test>0 :
        test-=1
        n=int(input())

        print(2)
        print(n,n-1)
        for i in range(n-2,0,-1):
            print(i+2,i)

if __name__ == "__main__":
    main()