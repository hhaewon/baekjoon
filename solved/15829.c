#include <stdio.h>

long long int r = 31;
long long int M = 1234567891;

long long int poww(long long int r, long long int n)
{
    long long int result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= r;
        result %= M;
    }
    return result;
}

int main()
{
    int L;
    char string[51];
    long long int sum = 0;
    scanf("%d", &L);
    scanf("%s", string);
    for (int i = 0; i < L; i++)
    {
        sum += ((string[i] - 'a' + 1) * poww(r, i)) % M;
    }
    sum = sum % M;
    printf("%lld", sum);
}