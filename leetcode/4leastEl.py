import queue as Q

def main():
    nums = [5, 9, 3, 6, 2, 1, 3, 2, 7, 5]
    least4=set()

    for n in nums:
        least4.put(n)
        print(least4)
        if least4.qsize()>4:
            print(least4.pop())


main()