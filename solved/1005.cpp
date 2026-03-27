#include <bits/stdc++.h>
using namespace std;

int T, N, K, W;
int D[1001];
int dp[1001] = {0};

void dfs(vector<bool> &visited, vector<int> g[1000], int v, queue<int> &q)
{
    visited[v] = true;
    for (auto &u : g[v])
    {
        if (!visited[u])
        {
            dfs(visited, g, u, q);
        }
    }
    q.push(v);
}

void solve()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> D[i];
    }

    vector<int> g[1001];
    vector<bool> visited(N + 1);
    queue<int> q;

    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        g[y].push_back(x);
    }
    cin >> W;
    dfs(visited, g, W, q);
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        // cout << i << "\n";
        dp[i] = D[i];
        for (int j = 0; j < g[i].size(); j++)
        {
            dp[i] = max(D[i] + dp[g[i][j]], dp[i]);
        }
        // cout << dp[i] << "\n";
    }
    cout << dp[W] << "\n";
}

int main()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solve();
    }
}