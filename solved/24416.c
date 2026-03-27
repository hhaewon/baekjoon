#include <stdio.h>

int main()
{
    int dp[41];
    dp[1] = 1;
    dp[2] = 1;
    int n;
    scanf("%d", &n);
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    printf("%d %d", dp[n], n - 2);
}