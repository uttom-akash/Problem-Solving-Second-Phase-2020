intArr=lambda : [ int(x) for x in input().split()]

def main():
    test=int(input())

    while test>0:
        test-=1
        n=int(input())
        half=n//2
        a=intArr()
        a.reverse()

        for i in range(n):
            x=a[i]
            if i<half:
                print(-x,end=' ')
            else :
                print(x,end=' ')
        print()





if __name__ == "__main__":
    main()