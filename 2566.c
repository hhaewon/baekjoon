#include <stdio.h>

int main()
{
    int arr[9][9];
    int max = -1;
    int maxX, maxY;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                maxX = i + 1;
                maxY = j + 1;
            }
        }
    }
    printf("%d\n%d %d", max, maxX, maxY);
}