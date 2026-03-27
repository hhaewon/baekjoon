#include <bits/stdc++.h>
using namespace std;

int dp[10001][2]; // 전 거, 지금
int coin[100];

int n, k;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    for (int i = 0; coin[0] * i <= k; i++)
    {
        dp[coin[0] * i][0] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[j][1] = 0;
            for (int l = 0; coin[i] * l <= j; l++)
            {
                dp[j][1] += dp[j - l * coin[i]][0];
            }
        }
        for (int j = 0; j <= k; j++)
        {
            dp[j][0] = dp[j][1];
        }
    }

    cout << dp[k][0];
}