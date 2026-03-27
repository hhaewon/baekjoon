#include <stdio.h>

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
    int arr[500][500];
    scanf("%d", &N);
    int dp[500][500];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    dp[0][0] = arr[0][0];
    int result = -1;
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = dp[i - 1][0] + arr[i][0];
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
        }
        dp[i][i] = dp[i - 1][i - 1] + arr[i][i];
    }

    for (int i = 0; i < N; i++)
    {
        result = max(result, dp[N - 1][i]);
    }
    printf("%d", result);
}