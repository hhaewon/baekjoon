#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
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

int abs(int x)
{
    if (x > 0)
    {
        return x;
    }
    else
    {
        return -x;
    }
}

int min(int a, int b)
{
    if (a < b)
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
    int arr[100000];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), cmp);
    int minValue = -1;
    int x, y;

    int start = 0;
    int end = N - 1;
    while (start < end)
    {
        int value = arr[start] + arr[end];
        if (minValue == -1 || abs(value) < minValue)
        {
            x = arr[start];
            y = arr[end];
            minValue = abs(value);
        }
        if (value > 0)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    printf("%d %d", x, y);
}