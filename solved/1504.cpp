#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

#define MAX_N 800

vector<pair<int, int>> graph[MAX_N + 1]; // 거리, 노드

int N, E;
vector<int> dijkstra(int start)
{
    vector<int> d(N + 1, INT_MAX);
    priority_queue<pair<int, int>> pq; // 거리, 노드
    d[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curDist = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        for (auto &e : graph[curNode])
        {
            int nextNode = e.second;
            int nextDist = curDist + e.first;

            if (nextDist < d[nextNode])
            {
                d[nextNode] = nextDist;
                pq.push({-nextDist, nextNode});
            }
        }
    }

    return d;
}

int main()
{
    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    int v1, v2;
    cin >> v1 >> v2;
    vector<int> d1 = dijkstra(1);
    vector<int> d2 = dijkstra(v1);
    vector<int> d3 = dijkstra(v2);

    int path1UnAvaliable = d1[v1] == INT_MAX || d2[v2] == INT_MAX || d3[N] == INT_MAX;
    int path2UnAvailable = d1[v2] == INT_MAX || d3[v1] == INT_MAX || d2[N] == INT_MAX;

    if (path1UnAvaliable && path2UnAvailable)
    {
        cout << "-1";
    }
    else if (!path1UnAvaliable && path2UnAvailable)
    {
        cout << d1[v1] + d2[v2] + d3[N];
    }
    else if (path1UnAvaliable && !path2UnAvailable)
    {
        cout << d1[v2] + d3[v1] + d2[N];
    }
    else
    {
        cout << min(d1[v1] + d2[v2] + d3[N], d1[v2] + d3[v1] + d2[N]);
    }
}