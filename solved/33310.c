#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int t;
    scanf("%d", &t);
    int l, r;
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &l, &r);
        if (l == 1 && r == 1)
        {
            printf("1\n");
        }
        else
        {
            printf("%d\n", r - l);
        }
    }
}