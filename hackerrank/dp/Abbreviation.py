import math
import os
import random
import re
import sys


def abbreviation(a, b):
    la,lb =len(a),len(b)
    dp=[[False for j in range(lb+1)] for i in range(la+1)]
    dp[0][0]=True

    for i in range(la):
        for j in range(lb):
            if dp[i][j]:
                if a[i].upper()==b[j]:
                    dp[i+1][j+1]=True
                if a[i].islower():
                    dp[i+1][j]=True
        print(dp)
    
    if dp[la][lb]:
        return 'YES'
    else :
        return 'NO'

def main():
    a = input()
    b = input()
    
    result = abbreviation(a, b)
    print(result)

if __name__ == "__main__":
    main()

