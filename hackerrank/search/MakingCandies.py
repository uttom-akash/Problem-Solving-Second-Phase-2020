import sys
import math

input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

def minimumPasses(m, w, p, n):
    candy = 0
    invest = 0
    spend = sys.maxsize
    while candy < n:
        passes = (p - candy) // (m * w)
        if passes <= 0:
            mw = (candy // p) + m + w
            half = math.ceil(mw / 2)
            if m > w:
                m = max(m, half)
                w = mw - m
            else:
                w = max(w, half)
                m = mw - w
            candy %= p
            passes = 1
        candy += passes * m * w
        invest += passes
        spend = min(spend, invest + math.ceil((n - candy) / (m * w)))
    return min(invest, spend)
        

def main():
    print(minimumPasses(3,1,2,12))

main()