#include <iostream>
#define MAX 500
using namespace std;

int M, N;
int board[MAX][MAX];
int dp[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void go(int x, int y)
{
    // cout << x << " " << y << "\n";
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < M && 0 <= ny && ny < N && board[nx][ny] < board[x][y])
        {
            if (!visited[nx][ny])
            {
                go(nx, ny);
                dp[x][y] += dp[nx][ny];
            }
            else
            {
                dp[x][y] += dp[nx][ny];
            }
        }
    }

    visited[x][y] = true;
}

int main()
{
    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    visited[M - 1][N - 1] = true;
    dp[M - 1][N - 1] = 1;
    go(0, 0);
    cout << dp[0][0];
}