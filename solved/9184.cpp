#include <iostream>

using namespace std;

int dp[21][21][21];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i <= 20; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            dp[0][i][j] = 1;
            dp[i][j][0] = 1;
            dp[i][0][j] = 1;
        }
    }

    for (int a = 1; a <= 20; a++)
    {
        for (int b = 1; b <= 20; b++)
        {
            for (int c = 1; c <= 20; c++)
            {
                if (a < b && b < c)
                {
                    dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
                }
                else
                {
                    dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];
                }
            }
        }
    }

    int a, b, c;
    cin >> a >> b >> c;
    while (!(a == -1 && b == -1 && c == -1))
    {
        if (a <= 0 || b <= 0 || c <= 0)
        {

            cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << "\n";
        }
        else if (a > 20 || b > 20 || c > 20)
        {
            cout << "w(" << a << ", " << b << ", " << c << ") = " << dp[20][20][20] << "\n";
        }
        else
        {
            cout << "w(" << a << ", " << b << ", " << c << ") = " << dp[a][b][c] << "\n";
        }

        cin >> a >> b >> c;
    }
}