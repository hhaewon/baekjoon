from decimal import Decimal, ROUND_UP, getcontext

getcontext().prec = 150



PI = Decimal("3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679")


def cos(x):
    if abs(x) > PI * 2: return cos(x % (PI * 2))
    if abs(x) > 1: return pow(cos(x/2), 2) - pow(sin(x/2), 2)
    ans = 0
    fac = 1
    for n in range(100):
        if n % 2 == 1:
            ans -= x ** (2*n) / fac
        else:
            ans += x ** (2*n) / fac
        fac *= (2 * n + 1) * (2 * n + 2)
    return ans

def sin(x : Decimal) -> Decimal:  
    if abs(x) > PI * 2: return sin(x % (PI * 2))
    if abs(x) > 1: return 2*sin(x/2) * cos(x/2)
    ans = Decimal('0')
    fac = Decimal('1')
    for n in range(100):
        if n % 2 == 1:
            ans -= x **(2*n+1)/ fac
        else:
            ans += x ** (2*n+1) / fac
        fac *= (2 * n + 2) * (2 * n + 3)

    return ans

A, B, C = map(int, input().split())
A, B, C = map(Decimal, [A, B, C])

def f(x : Decimal):
    return A*x + B * sin(x)  - C


left = Decimal(0)
right = Decimal(200000)
err = Decimal('1e-20')
mid = Decimal('0')
while (right-left>err):
    mid = (left+right)/2

    if (f(left) * f(mid) > 0):
        left = mid;
    else:
        right = mid

print(mid.quantize(Decimal('.000000'), rounding=ROUND_UP))

