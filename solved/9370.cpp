#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define x first
#define y second
#define MAX 1e9 + 7
using namespace std;

typedef pair<int, int> p;

int n, m, t;

vector<int> dijstra(int start, vector<p> graph[])
{
    vector<int> dist(n + 1, MAX);
    priority_queue<p> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curNode = pq.top().y;
        int curDist = -pq.top().x;
        pq.pop();

        if (dist[curNode] < curDist)
        {
            continue;
        }

        for (auto &e : graph[curNode])
        {
            int nxtNode = e.x;
            int nxtDist = curDist + e.y;

            if (nxtDist < dist[nxtNode])
            {
                dist[nxtNode] = nxtDist;
                pq.push({-nxtDist, nxtNode});
            }
        }
    }

    return dist;
}

void solve()
{
    vector<p> graph[2001];
    int dstCandi[100];
    int distDstCandi[100];
    int s, g, h;
    int a, b, d;
    int dst;
    cin >> n >> m >> t;
    cin >> s >> g >> h;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> d;
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }
    for (int i = 0; i < t; i++)
    {
        cin >> dstCandi[i];
    }
    sort(dstCandi, dstCandi + t);
    vector<int> d1 = dijstra(s, graph);
    vector<int> d2 = dijstra(g, graph);
    vector<int> d3 = dijstra(h, graph);
    for (int i = 0; i < t; i++)
    {
        dst = dstCandi[i];
        distDstCandi[i] = min(d1[g] + d2[h] + d3[dst], d1[h] + d3[g] + d2[dst]);
    }
    for (int i = 0; i < t; i++)
    {
        if (distDstCandi[i] == d1[dstCandi[i]])
        {
            cout << dstCandi[i] << " ";
        }
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solve();
    }
}
