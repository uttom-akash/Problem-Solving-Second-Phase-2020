def balancedSums(arr):
    length=len(arr)
    psum=[0 for x in range(length+1)]

    for i in range(length):
        psum[i+1]=psum[i]+arr[i]
    
    for i in range(length):
        if psum[i]-psum[0]== psum[length]-psum[i+1]:
            return 'YES'
    return 'NO' 