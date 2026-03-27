#include <stdio.h>
#include <math.h>

int is_prime(long long int n)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }
    for (long long i = 2; i <= (long long int)floor(sqrt(1.0 * n)); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    long long int n;
    long long int number;
    scanf("%lld", &n);
    for (long long int i = 0; i < n; i++)
    {
        scanf("%lld", &number);
        for (long long int j = number;; j++)
        {
            if (is_prime(j))
            {
                printf("%lld\n", j);
                break;
            }
        }
    }
    return 0;
}