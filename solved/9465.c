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
    int T;
    int n;
    int arr[2][100000];
    int dp[2][100000] = {0};
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &n);
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < n; k++)
            {
                scanf("%d", &arr[j][k]);
            }
        }
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        if (n >= 2)
        {
            dp[0][1] = dp[1][0] + arr[0][1];
            dp[1][1] = dp[0][0] + arr[1][1];
        }

        for (int j = 2; j < n; j++)
        {
            dp[0][j] = max(dp[1][j - 2], dp[1][j - 1]) + arr[0][j];
            dp[1][j] = max(dp[0][j - 2], dp[0][j - 1]) + arr[1][j];
        }
        printf("%d\n", max(dp[0][n - 1], dp[1][n - 1]));
    }
}