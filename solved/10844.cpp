#include <iostream>

using namespace std;

#define MOD 1000000000

typedef long long ll;

ll dp[101][10];
int N;
int main()
{
    cin >> N;
    for (int x = 0; x < 10; x++)
    {
        dp[1][x] = 1;
    }
    for (int n = 2; n <= N; n++)
    {
        dp[n][9] = dp[n - 1][8];
        dp[n][0] = dp[n - 1][1];

        for (int x = 1; x <= 8; x++)
        {
            dp[n][x] = (dp[n - 1][x - 1] + dp[n - 1][x + 1]) % MOD;
        }
    }

    ll result = 0;
    for (int i = 1; i <= 9; i++)
    {
        result = (result + dp[N][i]) % MOD;
    }
    cout << result;
}