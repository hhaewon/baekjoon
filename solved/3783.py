from decimal import Decimal, getcontext, ROUND_DOWN, ROUND_HALF_UP
import sys

input = sys.stdin.readline

T = int(input())

getcontext().prec = 170
for i in range(T):
    a = Decimal(int(input()))
    result = a ** (Decimal('1') / Decimal('3'))
    result = round(result, 101)
    result = Decimal(result) .quantize(
        Decimal('.0000000000'),
        rounding=ROUND_DOWN
    )
    print(result)
    



