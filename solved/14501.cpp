#include <bits/stdc++.h>
using namespace std;

int N;
int T[16];
int P[16];
int dp[16]; // i일 포함 이전까지 최대 수익.

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j + T[j] - 1 > i)
            {
                continue;
            }
            dp[i] = max(dp[i], dp[j - 1] + P[j]);
        }
    }
    cout << dp[N];
}