#include <stdio.h>

int arr[1000];

int dpIncreaing[1000]; // dp[i] : i를 포함했을 때 0~i까지 최장 길이 증가 부분수열
int dpDecresing[1000]; // dp[i] : i를 포함했을 때 N-1~i까지 최장 길이 증가 부분수열

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
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    dpIncreaing[0] = 1;
    dpDecresing[N - 1] = 1;
    for (int i = 1; i < N; i++)
    {
        dpIncreaing[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dpIncreaing[j] + 1 > dpIncreaing[i])
            {
                dpIncreaing[i] = dpIncreaing[j] + 1;
            }
        }
    }
    for (int i = N - 2; i >= 0; i--)
    {
        dpDecresing[i] = 1;
        for (int j = N - 1; j > i; j--)
        {
            if (arr[i] > arr[j] && dpDecresing[j] + 1 > dpDecresing[i])
            {
                dpDecresing[i] = dpDecresing[j] + 1;
            }
        }
    }

    int result = -1;
    for (int i = 0; i < N; i++)
    {
        result = max(result, dpIncreaing[i] + dpDecresing[i] - 1);
    }
    printf("%d", result);
}