
def main():
    test=int(input())
    while test>0:
        test-=1
        num=int(input())
        if num==1 or num==2 or num==4:
            print(-1)
        else :
            rem=num%3
            if rem==0 :
                print(num//3,0,0)
            elif rem==1:
                print((num-7)//3,0,1)
            else :
                print((num-5)//3,1,0)

if __name__=='__main__':
    main()


