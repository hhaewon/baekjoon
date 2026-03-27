#include <iostream>
#include <algorithm>

#define MAX 10000000

using namespace std;
int costs[1000][3];
int dp[1000][3];
int result = MAX;

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
    }
    for (int i = 0; i < 3; i++)
    {
        dp[0][0] = MAX;
        dp[0][1] = MAX;
        dp[0][2] = MAX;

        dp[0][i] = costs[0][i];
        for (int j = 1; j < N - 1; j++)
        {
            dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + costs[j][0];
            dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + costs[j][1];
            dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + costs[j][2];
        }

        if (i != 0)
        {
            result = min(result, costs[N - 1][0] + min(dp[N - 2][1], dp[N - 2][2]));
        }

        if (i != 1)
        {
            result = min(result, costs[N - 1][1] + min(dp[N - 2][0], dp[N - 2][2]));
        }

        if (i != 2)
        {
            result = min(result, costs[N - 1][2] + min(dp[N - 2][1], dp[N - 2][0]));
        }
    }

    cout << result;
}