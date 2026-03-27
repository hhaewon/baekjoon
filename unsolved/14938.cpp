#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10000

int n, m, r;
int dist[101][101];
int item[101];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> item[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = MAX;
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        dist[a][b] = min(dist[a][b], l);
        dist[b][a] = min(dist[b][a], l);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] <= m)
            {
                temp += item[j];
            }
        }
        result = max(temp, result);
    }
    cout << result;
}