#include <stdio.h>

int arr[128][128];
int white = 0;
int blue = 0;

void func(int y, int x, int size)
{
    int flag = 0;

    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (arr[y][x] != arr[i][j])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }

    if (!flag)
    {
        if (arr[y][x])
        {
            blue++;
        }
        else
        {
            white++;
        }
        return;
    }

    int nextSize = size / 2;
    func(y, x, nextSize);
    func(y, x + nextSize, nextSize);
    func(y + nextSize, x, nextSize);
    func(y + nextSize, x + nextSize, nextSize);
}

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

    func(0, 0, N);
    printf("%d\n%d", white, blue);
}