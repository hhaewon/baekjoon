#include <stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE][MAX_SIZE][MAX_SIZE]; // x, y, z
int visited[MAX_SIZE][MAX_SIZE][MAX_SIZE] = {0};
int queue[MAX_SIZE * MAX_SIZE * MAX_SIZE][3];
int front = 0;
int end = 0;
int M, N, H;

int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

void push(int x, int y, int z)
{
    queue[end][0] = x;
    queue[end][1] = y;
    queue[end][2] = z;
    end++;
}

void pop(int dst[3])
{
    dst[0] = queue[front][0];
    dst[1] = queue[front][1];
    dst[2] = queue[front][2];
    front++;
}

int isEmpty()
{
    return front == end;
}

int isValid(int x, int y, int z)
{
    return 0 <= x && x < M && 0 <= y && y < N && 0 <= z && z < H;
}

void bfs()
{
    int temp[3];
    int x, y, z, nx, ny, nz;
    while (!isEmpty())
    {
        pop(temp);
        x = temp[0];
        y = temp[1];
        z = temp[2];

        for (int i = 0; i < 6; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            nz = z + dz[i];

            if (isValid(nx, ny, nz) && !visited[nx][ny][nz] && arr[nx][ny][nz] == 0)
            {
                visited[nx][ny][nz] = 1;
                arr[nx][ny][nz] = arr[x][y][z] + 1;
                push(nx, ny, nz);
            }
        }
    }
}

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

int main()
{
    scanf("%d %d %d", &M, &N, &H);

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                scanf("%d", &arr[k][j][i]);
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < H; k++)
            {
                if (arr[i][j][k] == 1)
                {
                    push(i, j, k);
                    visited[i][j][k] = 1;
                }
            }
        }
    }

    bfs();

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < H; k++)
            {
                if (arr[i][j][k] == 0)
                {
                    printf("-1");
                    return 0;
                }
            }
        }
    }
    int ans = -1;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < H; k++)
            {
                if (arr[i][j][k] != -1)
                {
                    ans = max(ans, arr[i][j][k]);
                }
            }
        }
    }
    printf("%d", ans - 1);
}