#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
vector<int> graph[100001];
bool visited[100001];
int order[100001];
int n = 1;

void dfs(int node)
{
    visited[node] = true;
    order[node] = n;
    n++;

    sort(graph[node].begin(), graph[node].end(), greater<int>());
    for (auto &v : graph[node])
    {
        if (!visited[v])
        {
            dfs(v);
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
    dfs(R);

    for (int i = 1; i <= N; i++)
    {
        cout << order[i] << "\n";
    }
}