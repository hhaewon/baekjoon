#include <stdio.h>

int arr[100][100];
int sums[100][100];

int main()
{
    int N, M;
    int x1, y1, x2, y2;
    int X1, Y1, X2, Y2;
    int sum = 0;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
            if (i == 0 && j == 0)
            {
                sums[i][j] = arr[i][j];
            }
            else if (i == 0 && j != 0)
            {
                sums[i][j] = sums[i][j - 1] + arr[i][j];
            }
            else if (i != 0 && j == 0)
            {
                sums[i][j] = sums[i - 1][j] + arr[i][j];
            }
            else
            {
                sums[i][j] = sums[i][j - 1] + sums[i - 1][j] - sums[i - 1][j - 1] + arr[i][j];
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        X1 = x1 - 1;
        Y1 = y1 - 1;
        X2 = x2 - 1;
        Y2 = y2 - 1;
        if (X1 == 0 && Y1 == 0)
        {
            sum = sums[X2][Y2];
        }
        else if (X1 == 0 && Y1 != 0)
        {
            sum = sums[X2][Y2] - sums[X2][Y1 - 1];
        }
        else if (X1 != 0 && Y1 == 0)
        {
            sum = sums[X2][Y2] - sums[X1 - 1][Y2];
        }
        else
        {
            sum = sums[X2][Y2] - sums[X1 - 1][Y2] - sums[X2][Y1 - 1] + sums[X1 - 1][Y1 - 1];
        }
        printf("%d\n", sum);
    }
}
