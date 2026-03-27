#include <vector>
#include <iostream>
#include <climits>
#include <queue>

using namespace std;

#define MAX_NODES 20000

vector<pair<int, int>> graph[MAX_NODES + 1]; // 거리, 노드
int V, E, K;

vector<int> dijkstra(int start)
{
    vector<int> d(V + 1, INT_MAX);
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
                pq.push({-d[nextNode], nextNode});
            }
        }
    }

    return d;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E;
    cin >> K;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }

    vector<int> d = dijkstra(K);
    for (int i = 1; i <= V; i++)
    {
        if (d[i] == INT_MAX)
        {
            printf("INF\n");
        }
        else
        {
            printf("%d\n", d[i]);
        }
    }
}