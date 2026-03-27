#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;

#define MAX 100000000
int dist[101][101];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {

                dist[i][j] = 100000000;
            }
            else
            {
                dist[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == MAX)
            {
                cout << "0 ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }
}