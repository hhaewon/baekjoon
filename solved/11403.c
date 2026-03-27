#include <stdio.h>

// 방향이 있는 그래프도 있다.

int adj[100][100];
int visited[100][100] = {0};

int N;

void dfs(int start, int x)
{
    visited[start][x] = 1;

    for (int i = 0; i < N; i++)
    {
        if (adj[x][i] && !visited[start][i])
        {
            dfs(start, i);
        }
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (adj[i][j] && !visited[i][j])
            {
                dfs(i, j);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", visited[i][j]);
        }
        printf("\n");
    }
}