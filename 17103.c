#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int T = 0;
    int cnt = 0;
    int numbers[100];
    int max = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < T; i++)
    {
        if (max < numbers[i])
        {
            max = numbers[i];
        }
    }
    int *array = (int *)calloc(max, sizeof(int));
    for (int i = 2; i < max; i++)
    {
        if (array[i] == 0)
        {
            for (int j = 2; i * j < max; j++)
            {
                array[i * j] = 1;
            }
        }
    }
    for (int i = 0; i < T; i++)
    {
        cnt = 0;
        for (int j = 2; j <= numbers[i] / 2; j++)
        {
            if (array[j] == 0 && array[numbers[i] - j] == 0)
            {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}