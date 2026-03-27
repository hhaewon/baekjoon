#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, R;
vector<int> graph[100001];
bool visited[100001];
int order[100001];
int n = 1;

void bfs(int start)
{
    visited[start] = true;
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        order[u] = n;
        n++;
        q.pop();
        sort(graph[u].begin(), graph[u].end(), greater<int>());
        for (auto &v : graph[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    cin >> N >> M >> R;
    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs(R);

    for (int i = 1; i <= N; i++)
    {
        cout << order[i] << "\n";
    }
}