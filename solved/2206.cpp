#include <iostream>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
vector<string> board(1000);
int visited[1000][1000][2] = {0};

bool isValid(int x, int y);

int bfs()
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    visited[0][0][0] = 1;
    q.push({{0, 0}, 1});
    visited[0][0][1] = 1;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int broken = q.front().second;
        q.pop();

        if (visited[N - 1][M - 1][1])
        {
            return visited[N - 1][M - 1][1];
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!isValid(nx, ny))
            {
                continue;
            }

            if (board[nx][ny] == '0' && !visited[nx][ny][broken])
            {
                visited[nx][ny][broken] = visited[x][y][broken] + 1;
                q.push({{nx, ny}, broken});
            }
            else if (board[nx][ny] == '1' && broken == 0)
            {
                visited[nx][ny][1] = visited[x][y][0] + 1;
                q.push({{nx, ny}, 1});
            }
        }
    }

    return -1;
}

bool isValid(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < M;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    cout << bfs();
}