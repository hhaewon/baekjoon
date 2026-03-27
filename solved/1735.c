#include <stdio.h>

int gcd(int A, int B)
{
    int a = A, b = B;
    int q = 0, r = 1;
    while (r != 0)
    {
        q = a / b;
        r = a - b * q;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int A = a * d + b * c;
    int B = b * d;
    printf("%d %d", A / gcd(A, B), B / gcd(A, B));
    return 0;
}