#include <stdio.h>

typedef long long ll;

int main()
{
    int N;
    ll d[100000];
    ll price[100000];
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%lld", &d[i]);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &price[i]);
    }

    int start = 0;
    int i = 1;
    ll tempD = 0;
    ll result = 0;

    while (i < N)
    {
        if (price[start] < price[i])
        {
            tempD += d[i - 1];
        }
        else
        {
            // printf("%d %d %d\n", start, i, price[start] * (tempD + d[i - 1]));
            result += price[start] * (tempD + d[i - 1]);
            start = i;
            tempD = 0;
        }
        i++;
    }
    result += price[start] * tempD;
    printf("%lld", result);
}