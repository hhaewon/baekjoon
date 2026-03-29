#include <bits/stdc++.h>
using namespace std;

int N, M, K;
string arr[2001];
int board[2001][2001];
int KS;
int black[2001][2001]; // 처음 검은색
int minLength = 1e9;

// black 기준
bool correct(int i, int j, int x, int y)
{
    if ((x + y) % 2 == 0)
    {
        return arr[i + x][j + y] == 'B';
    }
    else
    {
        return arr[i + x][j + y] == 'W';
    }
}

int main()
{
    cin >> N >> M >> K;
    KS = K * K;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (((i + j) % 2 == 0 && arr[i][j - 1] == 'B') || ((i + j) % 2 == 1 && arr[i][j - 1] == 'W'))
            {
                black[i][j] = black[i - 1][j] + black[i][j - 1] - black[i - 1][j - 1];
            }
            else
            {
                black[i][j] = black[i - 1][j] + black[i][j - 1] - black[i - 1][j - 1] + 1;
            }
            // cout << i << " " << j << " " << black[i][j] << "\n";
        }
    }

    for (int i = 1; i + K - 1 <= N; i++)
    {
        for (int j = 1; j + K - 1 <= M; j++)
        {
            int x = black[i + K - 1][j + K - 1] - black[i - 1][j + K - 1] - black[i + K - 1][j - 1] + black[i - 1][j - 1];
            minLength = min(min(minLength, x), KS - x);
        }
    }

    cout << minLength;
}

// 2차원 누적합 공식대로 가자.