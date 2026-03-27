#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> edges[32001];
queue<int> q;
int result[32001];
int degree[32001];
int n, m;

void topologySort()
{
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (q.empty())
        {
            return;
        }
        int x = q.front();
        q.pop();
        result[i] = x;

        for (int i = 0; i < edges[x].size(); i++)
        {
            int y = edges[x][i];

            if (--degree[y] == 0)
            {
                q.push(y);
            }
        }
    }
}

int main()
{
    int a, b;
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        edges[a].push_back(b);
        degree[b]++;
    }

    topologySort();

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
}