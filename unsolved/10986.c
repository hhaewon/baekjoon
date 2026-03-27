#include <stdio.h>

typedef long long ll;
#define MAX_N 1000000

ll arr[MAX_N + 1];
ll sums[MAX_N + 1];
ll cnts[1000];
ll M;

ll comb(ll n)
{
    return n * (n - 1) / 2;
}

int main()
{
    ll N, cnt = 0;
    scanf("%lld %lld", &N, &M);
    sums[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]);
        sums[i] = (sums[i - 1] + arr[i]) % M;
        cnts[sums[i]]++;
    }
    cnt += cnts[0];
    for (int i = 0; i < M; i++)
    {
        cnt += comb(cnts[i]);
    }
    printf("%lld", cnt);
}
