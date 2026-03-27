#include <stdio.h>

int isPrime(int x)
{
    if (x == 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int N;
    scanf("%d", &N);
    int primes[304000];
    int numPrime = 0;
    for (int i = 2; i <= N; i++)
    {
        if (isPrime(i))
        {
            primes[numPrime++] = i;
        }
    }
    int start = 0;
    int end = 0;
    int partialSum = 2;
    int cnt = 0;

    // printf("primes : ");
    // for (int i = 0; i < numPrime; i++)
    // {
    //     printf("%d ", primes[i]);
    // }
    // printf("\n");

    while (end < numPrime)
    {
        // printf("%d %d %d\n", start, end, partialSum);
        if (partialSum == N)
        {
            cnt++;
        }

        if (partialSum >= N)
        {
            start++;
            partialSum = partialSum - primes[start - 1];
        }
        else
        {
            end++;
            partialSum = partialSum + primes[end];
        }
    }
    printf("%d", cnt);
}