#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 2001

long long p[MAX_N * 2];
long long dp[MAX_N * 2][MAX_N * 2];
int opt[MAX_N * 2][MAX_N * 2];
int n;

long long min(long long a, long long b)
{
    return a < b ? a : b;
}

int main()
{
    scanf("%d", &n);

    int *r = (int *)malloc(sizeof(int) * n);
    int *c = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &r[i], &c[i]);
    }

    if (n == 1)
    {
        printf("0\n");
        free(r);
        free(c);
        return 0;
    }

    // Create the dimension array p for linear chain multiplication
    // To handle the circular nature, we duplicate the chain
    for (int i = 0; i < n; i++)
    {
        p[i] = r[i];
    }
    p[n] = c[n - 1];

    // Duplicate the chain to handle circularity
    for (int i = 0; i < n; i++)
    {
        p[n + 1 + i] = r[i];
    }
    p[2 * n] = c[n - 1];

    int m = 2 * n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = 0;
        }
        opt[i][i] = i;
    }

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i < m - len + 1; i++)
        {
            int j = i + len - 1;
            long long min_val = LLONG_MAX;
            int best_k = -1;

            int k_start = opt[i][j - 1];
            int k_end = opt[i + 1][j];

            for (int k = k_start; k <= k_end; k++)
            {
                if (k >= i && k < j)
                {
                    long long current_cost = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                    if (current_cost < min_val)
                    {
                        min_val = current_cost;
                        best_k = k;
                    }
                }
            }
            dp[i][j] = min_val;
            opt[i][j] = best_k;
        }
    }

    long long result = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        result = min(result, dp[i][i + n - 1]);
    }

    printf("%lld\n", result);

    free(r);
    free(c);

    return 0;
}