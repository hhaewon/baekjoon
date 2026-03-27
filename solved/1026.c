#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a, const void *b)
{
    int A = *(int *)a;
    int B = *(int *)b;
    if (A > B)
    {
        return 1;
    }
    else if (A < B)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int cmp2(const void *a, const void *b)
{
    int A = *(int *)a;
    int B = *(int *)b;
    if (A > B)
    {
        return -1;
    }
    else if (A < B)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int A[50];
    int B[50];

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &B[i]);
    }
    qsort(A, N, sizeof(int), cmp1);
    qsort(B, N, sizeof(int), cmp2);

    int result = 0;
    for (int i = 0; i < N; i++)
    {
        result += A[i] * B[i];
    }
    printf("%d", result);
}