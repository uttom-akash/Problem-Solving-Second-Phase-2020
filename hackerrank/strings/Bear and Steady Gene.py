import sys
input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))


def steadyGene(gene,n):
    psum=[[0 for j in range(n+1)] for i in range(4)]

    for i in range(n):
        for j in range(4):
            psum[j][i+1]+=psum[j][i]
        
        if gene[i]=='A':
            psum[0][i+1]+=1
        elif gene[i]=='G':
            psum[1][i+1]+=1
        elif gene[i]=='C':
            psum[2][i+1]+=1
        else:
            psum[3][i+1]+=1
    exactAmount=n//4

    i,j,ans=0,0,n
    while j<=n:
        passed,k=True,0
        while k<4:
            overflow=psum[k][n]-exactAmount
            flowInRange=psum[k][j]-psum[k][i]
            if flowInRange<overflow:
                passed=False
                break
            k+=1
        
        if passed:
            ans=min(ans,j-i)
            i+=1
            if i>j:
                j=i
        else :
            j+=1
    return ans
        


def main():
    n=40
    gene='TGATGCCGTCCCCTCAACTTGAGTGCTCCTAATGCGTTGC'
    #     1234567891234567891234567891234567891234  
    steadyGene(gene,n)
main()


# TTAATTAA
# 12345678

# n/4 => 8/4=2

# A=4 -- 2  
# G=0 ++ 2
# C=0 ++ 2
# T=4 -- 2 

# replace = 4


