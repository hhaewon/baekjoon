#include <stdio.h>

typedef long long ll;

ll horizontal[16][16];
ll vertical[16][16];
ll diagonal[16][16];

int arr[16][16];
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    horizontal[0][0] = 0;
    horizontal[0][1] = 1;
    horizontal[1][0] = 0;
    vertical[0][0] = 0;
    vertical[1][0] = 0;
    diagonal[0][0] = 0;
    diagonal[0][1] = 0;
    diagonal[1][0] = 0;

    for (int k = 2; k <= 2 * N - 2; k++)
    {
        for (int i = 0; i <= k; i++)
        {
            int j = k - i;
            horizontal[i][j] = 0;
            diagonal[i][j] = 0;
            vertical[i][j] = 0;
            if (arr[i][j])
            {
                continue;
            }
            if (i >= 1)
            {
                vertical[i][j] = vertical[i - 1][j] + diagonal[i - 1][j];
            }
            if (j >= 1)
            {
                horizontal[i][j] = horizontal[i][j - 1] + diagonal[i][j - 1];
            }
            if (!arr[i][j - 1] && !arr[i - 1][j] && i >= 1 && j >= 1)
            {
                diagonal[i][j] = vertical[i - 1][j - 1] + horizontal[i - 1][j - 1] + diagonal[i - 1][j - 1];
            }
        }
    }
    ll result = vertical[N - 1][N - 1] + horizontal[N - 1][N - 1] + diagonal[N - 1][N - 1];
    printf("%lld", result);
}