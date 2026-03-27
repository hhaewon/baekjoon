from fractions import Fraction

N = int(input())
A = [[Fraction('0')] * (N+1) for _ in range(N+1)]
b = [Fraction('0')] * (N+1)

def scala_mul(i, k):
    for j in range(1, N+1):
        A[i][j] *= k
    b[i] *= k


def sum_row(i, j, k):
    for r in range(1, N+1):
        A[j][r] += k * A[i][r]
    b[j] += k * b[i]

for i in range(1, N+1):
    inputs = list(map(int, input().split()))
    for j in range(1, N+1):
        A[i][j] = Fraction(inputs[j-1])
    
    b[i] = Fraction(inputs[N])


for i in range(1, N+1):
    scala_mul(i, 1/A[i][i])
    for j in range(1, N+1):
        if (i==j):
            continue
        sum_row(i, j, -A[j][i])

for i in range(1, N+1):
    print(b[i].numerator, end=" ")




