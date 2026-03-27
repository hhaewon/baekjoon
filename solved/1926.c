#include <stdio.h>

int arr[500][500];
int visited[500][500] = {0};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int maxArea = 0;
int cnt = 0;
int n, m;
int area = 0;

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int isValid(int x, int y)
{
    return 0 <= x && x < m && 0 <= y && y < n;
}

void dfs(int x, int y)
{
    area++;
    visited[y][x] = 1;
    int nx, ny;
    for (int i = 0; i < 4; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];

        if (isValid(nx, ny) && arr[ny][nx] == 1 && !visited[ny][nx])
        {
            dfs(nx, ny);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && arr[i][j] == 1)
            {
                dfs(j, i);
                cnt++;
                maxArea = max(maxArea, area);
                area = 0;
            }
        }
    }

    printf("%d\n%d", cnt, maxArea);
}