#include <stdio.h>

int result[10]; // 1, 2, 3, 5, 6, 7, 8, 9, 0
int a, b;
int remain = 0;
int main()
{
    int N;
    scanf("%d", &N);
    int n = N;
    int i = 1;
    while (n > 0)
    {
        a = n / 10;
        b = n % 10;
        if (b != 0)
        {
            for (int j = 0; j < 10; j++)
            {
                result[j] += i * a;
            }
            for (int j = 0; j < b - 1; j++)
            {
                result[j] += i;
            }
            result[b % 10 - 1] += (remain + 1);
        }
        else
        {
            for (int j = 0; j < 9; j++)
            {
                result[j] += i * a;
            }
            if (i != 1)
            {
                result[9] += i * (a - 1) + remain + 1;
            }
            else
            {
                result[9] += i * a;
            }
        }
        remain = remain + b * i;
        n = n / 10;
        i *= 10;
    }

    printf("%d ", result[9]);
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", result[i]);
    }
}