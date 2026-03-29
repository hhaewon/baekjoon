#include <bits/stdc++.h>
using namespace std;

int N, M, K;
string arr[2000];
int board[2000][2000]; // 1 : black, -1 : white

int white[2000][2000]; // 처음 하얀색
int black[2000][2000]; // 처음 검은색
int minLength = 1e9;

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++)
        {
            if (i + j % 2 == 0)
            {
                if (arr[i][j] == 'B')
                {
                    black[0][0]++;
                }
                else
                {
                    white[0][0]++;
                }
            }
            else
            {
                if (arr[i][j] == 'W')
                {
                    black[0][0]++;
                }
                else
                {
                    white[0][0]++;
                }
            }
        }
    }

    for (int j = 1; j + K < M; j++)
    {
        black[0][j] = white[0][0];
        white[0][j] = black[0][0];

        for (int k = 0; k < K; k++)
        {
            if ((k + j - 1) % 2 == 0)
            {
                if (arr[k][j - 1] == 'B')
                {
                    white[0][j]--;
                }
                else
                {
                    black[0][j]--;
                }
            }
            else
            {
                if (arr[k][j - 1] == 'W')
                {
                    white[0][j]--;
                }
                else
                {
                    black[0][j]--;
                }
            }
        }

        for (int k = 0; k < K; k++)
        {
            if ((k + j - 1) % 2 == 0)
            {
                if (arr[k][j - 1] == 'B')
                {
                    white[0][j]++;
                }
                else
                {
                    black[0][j]++;
                }
            }
            else
            {
                if (arr[k][j - 1] == 'W')
                {
                    white[0][j]++;
                }
                else
                {
                    black[0][j]++;
                }
            }
        }
    }

    for (int i = 1; i + K < N; i++)
    {
        black[i][0] = white[i - 1][0];
        white[i][0] = black[i - 1][0];

        for (int k = 0; k < K; k++)
        {
            if ((i + k - 1) % 2 == 0)
            {
                if (arr[i + k - 1][0] == 'B')
                {
                    white[i][0]--;
                }
                else
                {
                    black[i][0]--;
                }
            }
            else
            {
                if (arr[i + k - 1][0] == 'W')
                {
                    white[i][0]--;
                }
                else
                {
                    black[i][0]--;
                }
            }
        }

        for (int k = 0; k < K; k++)
        {
            if ((i + k + K - 2) % 2 == 0)
            {
                if (arr[i + k - 1][K - 1] == 'B')
                {
                    white[i][0]++;
                }
                else
                {
                    black[i][0]++;
                }
            }
            else
            {
                if (arr[i + k - 1][K - 1] == 'W')
                {
                    white[i][0]++;
                }
                else
                {
                    black[i][0]++;
                }
            }
        }

        for (int j = 0; j < K; j++)
        {
            if (i + j % 2 == 0)
            {
                if (arr[i][j] == 'B')
                {
                    black[0][0]++;
                }
                else
                {
                    white[0][0]++;
                }
            }
            else
            {
                if (arr[i][j] == 'W')
                {
                    black[0][0]++;
                }
                else
                {
                    white[0][0]++;
                }
            }
        }
    }
}