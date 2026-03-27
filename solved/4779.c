#include <stdio.h>

int power(int x, int y)
{
    int result = 1;
    for (int i = 0; i < y; i++)
    {
        result *= x;
    }
    return result;
}

int cantor(int start, int x, int size)
{
    // printf("stat %d, x %d, size %d\n", start, x, size);
    if (size == 0)
    {
        return 1;
    }

    if (start + size <= x && x < start + 2 * size)
    {
        return 0;
    }
    else
    {
        if (start <= x && x < start + size)
        {
            return cantor(start, x, size / 3);
        }
        else if (start + 2 * size <= x < start + 3 * size)
        {
            return cantor(start + 2 * size, x, size / 3);
        }
    }
}

int main()
{
    int N;
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 0; i < power(3, N); i++)
        {
            if (cantor(0, i, power(3, N - 1)))
            {
                printf("-");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}