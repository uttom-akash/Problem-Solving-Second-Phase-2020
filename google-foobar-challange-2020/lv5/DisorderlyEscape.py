from math import factorial
from fractions import gcd
from collections import Counter


def conjugacy_cls(partition, n):
    n_fact = factorial(n)
    freq = Counter(partition).items()

    for key, frq in freq:
        n_fact //= (key**frq)*factorial(frq)
    return n_fact


def partition_number(n):
    partition = [n]
    yield partition

    while True:

        remV = 0
        while partition and partition[-1] == 1:
            remV += partition.pop()

        if not partition:
            break

        partition[-1] -= 1
        remV += 1

        while partition[-1] < remV:
            partition.append(partition[-1])
            remV -= partition[-1]

        partition.append(remV)

        yield partition


def solution(w, h, s):
    grid = 0
    for ipw in partition_number(w):
        for iph in partition_number(h):
            m = conjugacy_cls(ipw, w)*conjugacy_cls(iph, h)
            esum = 0
            for i in ipw:
                for j in iph:
                    esum += gcd(i, j)

            grid += m*(s**esum)

    grid //= (factorial(w)*factorial(h))

    return grid


print(solution(2, 3, 4))
