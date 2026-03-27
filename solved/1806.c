#include <stdio.h>

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
    int N, S;
    int arr[100000] = {0};
    scanf("%d %d", &N, &S);
    int start = 0;
    int end = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    int partialSum = arr[start];
    int minLength = 100001;
    while (start < N && end < N)
    {
        // printf("[%d, %d] %d\n", start, end, partialSum);
        if (partialSum >= S)
        {
            minLength = min(minLength, end - start + 1);
        }
        if (partialSum < S)
        {
            if (end + 1 < N)
            {
                partialSum += arr[end + 1];
            }
            end++;
        }
        else
        {
            partialSum -= arr[start];
            start++;
        }
    }
    if (minLength == 100001)
    {
        printf("0");
    }
    else
    {
        printf("%d", minLength);
    }
}