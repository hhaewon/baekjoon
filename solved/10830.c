#include <stdio.h>

int A[5][5];
int N;

void matrixMultiply(int M[5][5], int L[5][5], int dst[5][5])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dst[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                dst[i][j] += M[i][k] * L[k][j];
            }
            dst[i][j] = dst[i][j] % 1000;
        }
    }
}

void matrixPower(int M[5][5], long long int n, int dst[5][5])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dst[i][j] = 0;

    if (n == 0)
    {
        for (int i = 0; i < N; i++)
        {
            dst[i][i] = 1;
        }
        return;
    }
    if (n == 1)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                dst[i][j] = M[i][j] % 1000;
            }
        }
        return;
    }
    int subMatrix[5][5] = {0};
    int temp[5][5] = {0};
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
    long long int B;
    int dst[5][5] = {0};
    scanf("%d %lld", &N, &B);
    // int result[5][5];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    matrixPower(A, B, dst);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", dst[i][j]);
        }
        printf("\n");
    }
}