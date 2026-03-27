#include <iostream>
#include <deque>
#include <vector>

#define MAX 10001

using namespace std;

int N, M;
int arr[100][100];
int dist[100][100];
deque<pair<int, int>> dq;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve()
{
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = temp[j] - '0';
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dist[i][j] = MAX;
        }
    }
    dist[0][0] = 0;
    dq.push_back({0, 0});

    while (!dq.empty())
    {
        pair<int, int> cur = dq.front();
        int x = cur.first;
        int y = cur.second;
        dq.pop_front();

        if (x == M - 1 && y == N - 1)
        {
            cout << dist[N - 1][M - 1];
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < M && 0 <= ny && ny < N)
            {
                if (arr[ny][nx] == 1 && dist[ny][nx] > dist[y][x] + 1)
                {
                    dist[ny][nx] = dist[y][x] + 1;
                    dq.push_back({nx, ny});
                }
                if (arr[ny][nx] == 0 && dist[ny][nx] > dist[y][x])
                {
                    dist[ny][nx] = dist[y][x];
                    dq.push_front({nx, ny});
                }
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    solve();
}