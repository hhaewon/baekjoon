#include <stdio.h>
#define MAX_NUM 50000

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i * i <= MAX_NUM; i++)
    {
        if (i * i == n)
        {
            printf("1");
            return 0;
        }
    }

    for (int i = 1; i * i <= MAX_NUM; i++)
    {
        for (int j = 1; i * i + j * j <= MAX_NUM; j++)
        {
            if (i * i + j * j == n)
            {
                printf("2");
                return 0;
            }
        }
    }

    for (int i = 1; i * i <= MAX_NUM; i++)
    {
        for (int j = 1; i * i + j * j <= MAX_NUM; j++)
        {
            for (int k = 1; i * i + j * j + k * k <= MAX_NUM; k++)
            {
                if (i * i + j * j + k * k == n)
                {
                    printf("3");
                    return 0;
                }
            }
        }
    }

    printf("4");
}