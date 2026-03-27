#include <iostream>
#include <queue>
using namespace std;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void solve()
{
    int l;
    cin >> l;
    int x, y, a, b;
    cin >> x >> y;
    cin >> a >> b;

    if (x == a && y == b)
    {
        cout << 0 << "\n";
        return;
    }

    bool visited[300][300] = {0};
    int board[300][300] = {0};
    queue<pair<int, int>> q;
    board[x][y] = 0;
    q.push({x, y});
    visited[x][y] = true;

    while (!board[a][b])
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (0 <= nx && nx < l && 0 <= ny && ny < l && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                board[nx][ny] = board[curX][curY] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << board[a][b] << "\n";
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solve();
    }
}