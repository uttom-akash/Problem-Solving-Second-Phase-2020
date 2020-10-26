def missingNumbers(arr, brr):
    arr.sort()
    brr.sort()
    length=len(brr)
    ans=set()
    j=0
    for i in range(length):
        if j<len(arr) and brr[i]==arr[j]:
            j+=1
        elif brr[i] not in ans :
            ans.add(brr[i])
    return sorted(ans)
