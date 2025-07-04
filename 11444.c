#include <stdio.h>

int fastMultiple(long long int a, long long int b)
{
    if (b == 1)
    {
        return a;
    }
    if (b == 0)
    {
        return 0;
    }

    if (b % 2 == 0)
    {
        return 2 * fastMultiple(a, b / 2) % 1000000007;
    }
    else
    {
        return (2 * fastMultiple(a, b / 2) + a) % 1000000007;
    }
}

void matrixMultiply(long long int M[2][2], long long int L[2][2], long long int dst[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            dst[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                dst[i][j] += fastMultiple(M[i][k], L[k][j]);
            }
            dst[i][j] = dst[i][j] % 1000000007;
        }
    }
}

void matrixPower(long long int M[2][2], long long int n, long long int dst[2][2])
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            dst[i][j] = 0;

    if (n == 0)
    {
        for (int i = 0; i < 2; i++)
        {
            dst[i][i] = 1;
        }
        return;
    }
    if (n == 1)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                dst[i][j] = M[i][j] % 1000000007;
            }
        }
        return;
    }
    long long int subMatrix[2][2] = {0};
    long long int temp[2][2] = {0};
    matrixPower(M, n / 2, subMatrix);
    if (n % 2 == 0)
    {
        matrixMultiply(subMatrix, subMatrix, dst);
        return;
    }
    if (n % 2 == 1)
    {

        matrixMultiply(subMatrix, subMatrix, temp);
        matrixMultiply(temp, M, dst);
        return;
    }
}

int main()
{
    long long int B[2][2] = {{1, 1}, {1, 0}};
    long long int A1[2][2] = {0, 1, 0, 1};
    long long int temp[2][2] = {0};
    long long int result[2][2] = {0};

    long long int n;
    scanf("%lld", &n);
    if (n == 1)
    {
        printf("1");
    }
    else
    {
        matrixPower(B, n - 1, temp);
        matrixMultiply(temp, A1, result);
        printf("%lld", result[1][1]);
    }
}