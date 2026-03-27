#include <bits/stdc++.h>
using namespace std;

int visited[200001][2]; // 최단거리, 방법 가지 수

int N, K;

void bfs()
{
    queue<int> q;
    visited[N][0] = 0;
    visited[N][1] = 1;
    q.push(N);

    while (!q.empty())
    {
        int x = q.front();
        int nt = visited[x][0] + 1;
        int way = visited[x][1];
        q.pop();

        if (visited[K][1] && nt != visited[K][0])
        {
            break;
        }

        if (x + 1 <= 200000)
        {
            if (!visited[x + 1][1])
            {
                visited[x + 1][0] = nt;
                visited[x + 1][1] = way;
                q.push(x + 1);
            }
            else if (nt == visited[x + 1][0])
            {
                visited[x + 1][1] += way;
            }
        }
        if (x - 1 >= 0)
        {
            if (!visited[x - 1][1])
            {
                visited[x - 1][0] = nt;
                visited[x - 1][1] = way;
                q.push(x - 1);
            }
            else if (nt == visited[x - 1][0])
            {
                visited[x - 1][1] += way;
            }
        }
        if (2 * x < 200000)
        {
            if (!visited[2 * x][1])
            {
                visited[2 * x][0] = nt;
                visited[2 * x][1] = way;
                q.push(2 * x);
            }
            else if (nt == visited[2 * x][0])
            {
                visited[2 * x][1] += way;
            }
        }
    }

    cout << visited[K][0] << "\n"
         << visited[K][1];
}
int main()
{
    cin >> N >> K;
    bfs();
}

// 여기서도 dx배열 활용