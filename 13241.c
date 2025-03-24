// 초기화를 하자!
#include <stdio.h>

int main()
{
    long long int A, B;
    long long int q = 0, r = 1;
    scanf("%lld %lld", &A, &B);
    long long int a = A, b = B;
    while (r != 0)
    {
        q = a / b;
        r = a - q * b;
        a = b;
        b = r;
    }
    printf("%lld", A * B / a);
}