#include <vector>
#include <queue>
#include <iostream>
#include <climits>
using namespace std;

vector<int> dijkstra(int start, int N, vector<pair<int, int>> graph[])
{
    vector<int> dist(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curDist = pq.top().first;  // 거리
        int curNode = pq.top().second; // 인덱스

        pq.pop();
        if (dist[curNode] < curDist)
            continue;

        for (int i = 0; i < graph[curNode].size(); i++)
        {
            int nextNode = graph[curNode][i].first;            // 노드
            int nextDist = curDist + graph[curNode][i].second; // 비용

            if (nextDist < dist[nextNode])
            {
                dist[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }

    return dist;
}

int main()
{
    int N;
    int M;
    int from;
    int to;
    int cost;
    cin >> N;
    cin >> M;
    vector<pair<int, int>> graph[N + 1]; //

    for (int i = 0; i < M; i++)
    {
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }

    int start;
    int end;
    cin >> start >> end;
    vector<int> d = dijkstra(start, N, graph);
    cout << d[end];
}