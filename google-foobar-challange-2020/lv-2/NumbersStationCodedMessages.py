
def getPrefixSum(l):
    psum=[0]*(len(l)+5)
    psum[0]=0
    for i in range(len(l)):
        psum[i+1]=psum[i]+l[i]
    
    return psum

def solution(l, t):
    psum=getPrefixSum(l)
    left=right=0
    length=len(l)

    while right<length:
        target=psum[right+1]-psum[left]
        if target == t :
            return [left,right]
        elif target < t:
            right+=1
        else: 
            left+=1

        right=max(left,right)     
    
    return [-1,-1]



if __name__ == "__main__":
    print(solution([1, 2, 3, 4], 15))