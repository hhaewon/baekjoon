#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> weights[101]; // 무게, 가치
int dp[1000001][101] = {0};  // dp[x][y] 물건 limit : x, 1~y 고려

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> weights[i].first;
        cin >> weights[i].second;
    }

    for (int j = 0; j <= N; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i <= K; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= K; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (weights[j].first > i)
            {
                dp[i][j] = dp[i][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - weights[j].first][j - 1] + weights[j].second);
            }
        }
    }

    cout << dp[K][N];
}