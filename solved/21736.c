#include <stdio.h>

int N, M;
int cnt = 0;
char arr[600][601];
int visited[600][600] = {0};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int isValid(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < M && arr[x][y] != 'X';
}

void dfs(int x, int y)
{
    if (arr[x][y] == 'P')
    {
        cnt++;
    }
    visited[x][y] = 1;
    int nx, ny;
    for (int i = 0; i < 4; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (!visited[nx][ny] && isValid(nx, ny))
        {
            dfs(nx, ny);
        }
    }
}

int main()
{
    int startX, startY;

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 'I')
            {
                startX = i;
                startY = j;
            }
        }
    }

    dfs(startX, startY);
    if (cnt)
    {
        printf("%d", cnt);
    }
    else
    {
        printf("TT");
    }
}