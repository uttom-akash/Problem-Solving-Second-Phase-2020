import sys
input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

ttow=[
        "zero", 
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "quarter",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "twenty one",
        "twenty two",
        "twenty three",
        "twenty four",
        "twenty five",
        "twenty six",
        "twenty seven",
        "twenty eight",
        "twenty nine",
        "half"
    ]


def main():
    global ttow
    exactHour='o\' clock'
    pastMin='past'
    toMin='to'

    h=int(input())
    m=int(input())
    
    timeWord=''
    if m==0:
        timeWord=ttow[h]+' '+exactHour
    elif m>30:
        timeWord=ttow[60-m]+' '+toMin+' '+ttow[h]
    else:
        timeWord=ttow[m]+' '+pastMin+' '+ttow[h]
    print(timeWord)

main()

