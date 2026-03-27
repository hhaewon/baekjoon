#include <stdio.h>

int A[1000];
int dp[1000];
int N;
int max = -1;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    dp[0] = 1;
    for (int i = 1; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j <= i; j++)
        {
            if (A[j] < A[i] && (dp[j] + 1 > dp[i]))
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    int max = -1;
    for (int i = 0; i < N; i++)
    {
        if (dp[i] > max)
        {
            max = dp[i];
        }
    }
    printf("%d", max);
}