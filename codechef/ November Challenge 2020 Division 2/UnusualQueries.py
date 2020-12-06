import sys
input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))
from collections import defaultdict

        
def main():
    d1=defaultdict({'work': ['fulltime','partime','intership','volunteer'], 
    'thing': ['science', 'grammar', 'universe', 'unicorn']})

    d2={'working': ['fulltime','partime','intership','volunteer','working']}
    d1['working']=d1.pop('work')
    print(d1)

main()