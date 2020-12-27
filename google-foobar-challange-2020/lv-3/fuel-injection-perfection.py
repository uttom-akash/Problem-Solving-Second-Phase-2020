

def solution(numberSt):
    number=int(numberSt)
    ans=0
    while number!=1:
        if number&1 == 0: # 0&1=0
            number >>= 1
        elif number&3 == 1 or number == 3 : # 01&11=1 or 3 
            number-=1
        else :
            number+=1
        ans+=1
    return ans


