#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> children[10001];

int n;

int getMaxDistance(int root)
{
    if (children[root].empty())
    {
        return 0;
    }

    int result = 0;
    for (auto &child : children[root])
    {
        result = max(result, child.second + getMaxDistance(child.first));
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    int p, c, w;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> c >> w;
        children[p].push_back({c, w});
    }

    vector<int> distance;

    for (auto &child : children[1])
    {
        distance.push_back(child.second + getMaxDistance(child.first));
    }
    sort(distance.begin(), distance.end(), greater<>());
    if (distance.size() == 1)
    {
        cout << distance[0];
    }
    else
    {
        cout << distance[0] + distance[1];
    }
}