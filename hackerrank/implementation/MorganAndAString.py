import sys
input=sys.stdin.readline
inputs=lambda converter: list(map(converter,input().split()))

def getCleanString(s):
    if s[-1]=='\n':
        s=s[:-1]
    return s

def main():
    testc=int(input())
    while testc>0:
        testc-=1
        s1=getCleanString(input())
        s2=getCleanString(input())
        s3=""
        
        l1,l2=len(s1),len(s2)
        i,j=0,0
        while i<l1 or j<l2:
            if i==l1:
                s3+=s2[j]
                j+=1
            elif j==l2:
                s3+=s1[i]
                i+=1
            elif ord(s1[i])<ord(s2[j]):
                s3+=s1[i]
                i+=1
            elif ord(s1[i])>ord(s2[j]):
                s3+=s2[j]
                j+=1
            else :
                k=0
                while i+k<l1 and j+k<l2 and ord(s1[i+k])==ord(s2[j+k]):
                    k+=1
                first=False
                if i+k==l1:
                    first=True
                elif j+k<l2 and ord(s1[i+k])<ord(s2[j+k]):
                    first=True
                ii,jj=i,j
                while ii<i+k or jj<j+k:
                    if ii==i+k:
                        s3+=s2[jj]
                        jj+=1
                    elif jj==j+k:
                        s3+=s1[ii]
                        ii+=1
                    elif ord(s1[ii])<ord(s2[jj]):
                        s3+=s1[ii]
                        ii+=1
                    elif ord(s1[ii])>ord(s2[jj]):
                        s3+=s2[jj]
                        jj+=1
                    else :
                        if first :
                            s3+=s1[ii]
                            ii+=1
                        else :
                            s3+=s2[jj]
                            jj+=1
                i,j=ii,jj

                
        print(s3)

main()

