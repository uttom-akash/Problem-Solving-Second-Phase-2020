import sys
input=sys.stdin.readline
intArr=lambda : list(map(int,input().split()))

def main():
    test=int(input())

    while test>0:
        test-=1
        n,m=intArr()

        ltoR,ttoB=[],[]
        mapper={}
        
        for i in range(n):
            ltoR.append(intArr())
            x=ltoR[i][0]
            mapper[x]=i

        for i in range(m):
            b=intArr()
            if b[0] in mapper :
                ttoB=b

        for i in range(n):
            topE=ttoB[i]
            corRi=mapper[topE]
            print(*ltoR[corRi])


if __name__ == "__main__":
    main()

