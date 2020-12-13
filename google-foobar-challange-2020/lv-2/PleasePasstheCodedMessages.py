def get_min_intersaction(l,c1,c2):
    intersect=set(l) & c1
    if not intersect :
        intersect=set(l) & c2
    return  min(intersect)

def solution(nums):
    nums.sort(reverse=True)
    valueSum=sum(nums)
    rem=valueSum%3

    rem_1={1,4,7}
    rem_2={2,5,8}

    while rem>0 and len(nums)>0:
        remov= 0
        if rem==1:
            remov=get_min_intersaction(nums,rem_1,rem_2)
        else :
            remov=get_min_intersaction(nums,rem_2,rem_1)

        valueSum-=remov
        rem=valueSum%3
        nums.remove(remov)

    
    if len(nums)>0 :
        return int(''.join(str(x) for x in nums))
    else :
        return 0

if __name__ == "__main__":
    print(solution([1,1,1,1,2,2]))
    print(solution([3, 1, 4, 1, 5, 9]))
    print(solution([]))
    print(solution([9, 9, 9, 9,0]))