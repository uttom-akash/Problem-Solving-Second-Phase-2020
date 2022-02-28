
from decimal import localcontext, Decimal


def sqrt_in_dec(num):
    return Decimal(num).sqrt()


def apply_BS(n,r,s):
    if n == 0:
        return 0

    B_rn = int(r * n)
    B_rns = int(Decimal(B_rn) / s)

    return (B_rn * (B_rn + 1)) / 2 - apply_BS(B_rns,r,s) - B_rns * (B_rns + 1)
    


def solution(str_n):
    n = Decimal(str_n)

    with localcontext() as context:
        context.prec = 101

        r = sqrt_in_dec(2)
        s = Decimal(2) + sqrt_in_dec(2)

        ans = str(int(apply_BS(n,r,s)))
        return ans


s=solution('5')
print(s)