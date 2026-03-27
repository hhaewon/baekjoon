#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[10001];
int coin[100];
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    for (int i = 0; i <= k; i++)
    {
        dp[i] = -1;
    }

    dp[0] = 0;

    for (int i = 1; i <= k; i++)
    {
        dp[i] = 1e9 + 7;
        for (int j = 0; j < n; j++)
        {
            if (coin[j] <= i && dp[i - coin[j]] != -1)
            {
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
        if (dp[i] == 1e9 + 7)
        {
            dp[i] = -1;
        }
    }

    if (dp[k] == -1)
    {
        cout << -1;
    }
    else
    {
        cout << dp[k];
    }
}