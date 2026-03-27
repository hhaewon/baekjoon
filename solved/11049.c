#include <stdio.h>

int main()
{
    int dim[501];
    int dp[501][501];
    int N;
    int r, c;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &r, &c);
        dim[i] = r;
        dim[i + 1] = c;
    }

    for (int i = 0; i < N; i++)
    {
        dp[i][i] = 0;
    }

    for (int length = 2; length <= N; length++)
    {
        for (int i = 0; i + length - 1 < N; i++)
        {
            int end = i + length - 1;
            dp[i][end] = -1;
            for (int k = i; k <= end; k++)
            {
                int temp = dp[i][k] + dp[k + 1][end] + dim[i] * dim[k + 1] * dim[end + 1];
                if (dp[i][end] == -1 || temp < dp[i][end])
                {
                    dp[i][end] = temp;
                }
            }
        }
    }
    printf("%d", dp[0][N - 1]);
}