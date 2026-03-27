#include <stdio.h>

int main()
{
    int a, b, c;
    int max = 0;

    scanf("%d %d %d", &a, &b, &c);

    if (a > max)
    {
        max = a;
    }
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }

    if (a + b + c - max - 1 > max)
    {
        printf("%d\n", a + b + c);
    }
    else
    {
        printf("%d\n", a + b + c - max + a + b + c - max - 1);
    }

    return 0;
}