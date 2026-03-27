#include <stdio.h>

int sum[1025][1025] = {0};

int main()
{
    int N, M;
    int temp;
    int x1, y1, x2, y2;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &temp);
            if (j != 0)
            {
                sum[i + 1][j + 1] = sum[i + 1][j] + temp;
            }
            else
            {
                sum[i + 1][j + 1] = sum[i][N] + temp;
                sum[i + 1][j] = sum[i][N];
            }
        }
    }

    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= N; j++)
    //     {
    //         printf("%d ", sum[i][j]);
    //     }
    //     printf("\n");
    // }
    int result;
    for (int i = 0; i < M; i++)
    {
        result = 0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int j = x1; j <= x2; j++)
        {
            result += sum[j][y2] - sum[j][y1 - 1];
        }
        printf("%d\n", result);
    }
}