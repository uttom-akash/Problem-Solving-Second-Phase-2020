def icecreamParlor(m, arr):
    subtractArr=[]
    valueMapper={}
    length=len(arr)

    for i in range(length):
        x=arr[i]
        subtractArr.append(m-x)
        if x not in valueMapper:
            valueMapper[x]=[]
        valueMapper[x].append(i)

    for i in range(length):
        y=subtractArr[i]
        if y in valueMapper:
            valueList=valueMapper[y]
            yI=valueList.pop()

            if i!=yI:
                return [i,yI]
        



def main():
    m = int(input())
    n = int(input())
    arr = list(map(int, input().rstrip().split()))
    result = icecreamParlor(m, arr)
    print(result)

if __name__ == "__main__":
    main()