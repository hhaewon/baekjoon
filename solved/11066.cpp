#include <stdio.h>
#include <limits.h>

typedef long long ll;

ll min(ll a, ll b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

void solve()
{
    ll dp[501][501] = {0}; // dp[i][j] i ~ j 합칠 때 드는 최소비용
    ll size[501] = {0};    // 0 ~i까지 크기 합
    ll cost[501] = {0};

    ll K;
    scanf("%d", &K);
    for (ll i = 1; i <= K; i++)
    {
        scanf("%d", &cost[i]);
    }
    for (ll i = 1; i <= K; i++)
    {
        dp[i][i] = 0;
    }
    for (ll i = 1; i <= K; i++)
    {
        size[i] = size[i - 1] + cost[i];
    }
    // 길이 l
    for (ll l = 2; l <= K; l++)
    {
        for (ll i = 1; i + l - 1 <= K; i++)
        {
            ll temp = LLONG_MAX;
            ll j = i + l - 1;
            for (ll k = 0; k + 1 < l; k++)
            {
                ll size1 = size[i + k] - size[i - 1];
                ll size2 = size[j] - size[i + k];
                temp = min(temp, dp[i][i + k] + dp[i + k + 1][j] + size1 + size2);
            }
            dp[i][j] = temp;
        }
    }
    printf("%d\n", dp[1][K]);
}

int main()
{
    ll T;
    scanf("%d", &T);
    for (ll i = 0; i < T; i++)
    {
        solve();
    }
}