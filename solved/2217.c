#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
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

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int N;
    int ropes[100000];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &ropes[i]);
    }
    qsort(ropes, N, sizeof(int), cmp);
    int maxWeight = -1;
    for (int k = 1; k <= N; k++)
    {
        maxWeight = max(maxWeight, ropes[k - 1] * k);
    }
    printf("%d", maxWeight);
}