from fractions import Fraction

N = int(input())

m = 1
M = N*N

# 왼쪽 - 오른쪽 +
v = Fraction(0, 1)
V = Fraction(-1, 1)

cnt = 0

while (v < 0 or (v > V)):
    if cnt % 2 == 0:
        nextv = Fraction(1-M, 1+M)*v + Fraction(2*M, 1+M)*V
        nextV = Fraction(2, 1+M)*v - Fraction(1-M, 1+M)*V
        # print(f"{float(v)=} {float(V)=} {float(nextv)=} {float(nextV)=}")
        v = nextv
        V = nextV
    else:
        v = -v
        # print(f"{float(v)=} {float(V)=}")
    cnt += 1
print(cnt)


