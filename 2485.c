#include <stdio.h>

long long int gcd(long long int A, long long int B)
{
    long long int a = A, b = B;
    long long int q = 0, r = 1;
    while (r != 0)
    {
        q = a / b;
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n;
    long long int distances[100000];
    long long int totalGcd = 0;
    long long int cnt = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &distances[i]);
    }
    totalGcd = distances[1] - distances[0];

    for (int i = 1; i < n - 1; i++)
    {
        totalGcd = gcd(totalGcd, distances[i + 1] - distances[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        cnt += (distances[i + 1] - distances[i]) / totalGcd - 1;
    }
    printf("%lld", cnt);
    return 0;
}