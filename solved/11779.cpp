#include <iostream>
#include <queue>
#include <vector>
#define MAX 1e9 + 7
using namespace std;

typedef pair<int, int> p;

int n, m;
int start, dstNode;
vector<p> graph[1001];
int par[1001];
int path[1000];

vector<int> dijstra()
{
    vector<int> dst(n + 1, MAX);
    priority_queue<p> pq;
    dst[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curNode = pq.top().second;
        int curDist = -pq.top().first;
        pq.pop();

        if (curDist > dst[curNode])
        {
            continue;
        }

        for (auto &e : graph[curNode])
        {
            int nxtNode = e.first;
            int nxtDist = curDist + e.second;

            if (nxtDist < dst[nxtNode])
            {
                dst[nxtNode] = nxtDist;
                par[nxtNode] = curNode;
                pq.push({-nxtDist, nxtNode});
            }
        }
    }

    return dst;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> m;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    cin >> start;
    cin >> dstNode;
    vector<int> d = dijstra();

    int node = dstNode;
    int i = 0;
    while (node != 0)
    {
        path[i] = node;
        node = par[node];
        i++;
    }

    cout << d[dstNode] << "\n";
    cout << i << "\n";
    for (int j = i - 1; j >= 0; j--)
    {
        cout << path[j] << " ";
    }
}