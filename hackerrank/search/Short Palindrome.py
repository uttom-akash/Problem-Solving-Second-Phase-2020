import sys


input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

def main():
    s=input()

    dp=[[[[0 for l in range(30) ]  for k in range(30)] for j in range(30) ] for i in range(30)]
    print(dp)


main()