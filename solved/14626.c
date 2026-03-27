#include <stdio.h>

int main()
{
    char string[14];
    int arr[13] = {0};
    int markedIndex = 0;
    scanf("%s", string);
    int sum = 0;
    for (int i = 0; i < 13; i++)
    {
        if (string[i] != '*')
        {
            arr[i] = string[i] - '0';
        }
        else
        {
            markedIndex = i;
            arr[i] = -1;
        }
    }
    for (int i = 0; i < 13; i++)
    {
        if (arr[i] == -1)
        {
            continue;
        }
        if (i % 2 == 0)
        {
            sum += arr[i];
        }
        else
        {
            sum += arr[i] * 3;
        }
    }
    if (markedIndex % 2 == 0)
    {
        for (int j = 0; j <= 9; j++)
        {
            if ((j + sum) % 10 == 0)
            {
                printf("%d", j);
                break;
            }
        }
    }
    else
    {
        for (int j = 0; j <= 9; j++)
        {
            if ((3 * j + sum) % 10 == 0)
            {
                printf("%d", j);
                break;
            }
        }
    }
}