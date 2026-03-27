#include <stdio.h>

int arr[101][101] = {0};
int d[101][101] = {0};
int visited[101][101] = {0};
int N, M;

void bfs(int start)
{
    int queue[101];
    int front = 0;
    int end = 0;
    visited[start][start] = 1;
    d[start][start] = 0;
    for (int i = 1; i <= N; i++)
    {
        if (arr[start][i])
        {
            queue[end++] = i;
            d[start][i] = 1;
            visited[start][i] = 1;
        }
    }

    while (front < end)
    {
        int temp = queue[front++];
        for (int i = 1; i <= N; i++)
        {
            if (arr[temp][i] && !visited[start][i])
            {
                queue[end++] = i;
                d[start][i] = d[start][temp] + 1;
                visited[start][i] = 1;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    int x, y;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &x, &y);
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        bfs(i);
    }
    int min = -1;
    int person = -1;
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
        {
            // printf("d[%d][%d] : %d\n", i, j, d[i][j]);
            sum += d[i][j];
        }
        if (min == -1 || sum < min)
        {
            min = sum;
            person = i;
        }
    }

    printf("%d", person);
}
