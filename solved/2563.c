#include <stdio.h>

int main()
{
    int arr[101][101] = {0};
    int n;
    int x, y;
    int cnt = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);

        for (int j = y + 1; j <= y + 10; j++)
        {
            for (int k = x + 1; k <= x + 10; k++)
            {
                arr[j][k] = 1;
            }
        }
    }

    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            if (arr[i][j])
            {
                cnt += 1;
            }
        }
    }
    printf("%d", cnt);
}