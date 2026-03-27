MOD = 1000000007

def matrixMultiply(M, L):
    dst = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                dst[i][j] += M[i][k] * L[k][j];
        dst[i][j] = dst[i][j] % MOD
    return dst
    


def matrixPower(M, n):
    dst = [[0, 0], [0, 0]]

    if (n == 0):
        dst[0][0] = 1
        dst[1][1] = 1
        return dst
    if (n == 1):
        for i in range(2):
            for j in range(2):
                dst[i][j] = M[i][j] % MOD
        return dst
    
    subMatrix = matrixPower(M, n//2)
    if n % 2 == 0:
        dst = matrixMultiply(subMatrix, subMatrix)
        return dst
    else:
        dst = matrixMultiply(matrixMultiply(subMatrix, subMatrix), M)
        return dst

def gcd(a, b):
    if (b == 0):
        return a
    return gcd(b, a%b)


def main():
    B = [[1, 1], [1, 0]]
    A = [[0, 1], [0, 1]]

    n, m = map(int, input().split())
    gcdnm = gcd(n, m)
    temp1 = matrixPower(B, gcdnm-1)
    result = matrixMultiply(temp1, A)
    print(result[1][1] % MOD)

main()