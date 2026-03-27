#include <stdio.h>
#define MAX_N 100

int arr[MAX_N][MAX_N];
int visited1[MAX_N][MAX_N] = {0};
int visited2[MAX_N][MAX_N] = {0};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N;

int isValid(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < N;
}

void dfs1(int x, int y)
{
    visited1[y][x] = 1;
    int value = arr[y][x];
    int nx, ny;
    for (int i = 0; i < 4; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];

        if (isValid(nx, ny) && !visited1[ny][nx] && arr[ny][nx] == value)
        {
            dfs1(nx, ny);
        }
    }
}

void dfs2(int x, int y)
{
    visited2[y][x] = 1;
    int value = arr[y][x];
    int nx, ny;
    for (int i = 0; i < 4; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];

        if (isValid(nx, ny) && !visited2[ny][nx] && (arr[ny][nx] == value || arr[ny][nx] == 0 && value == 1 || arr[ny][nx] == 1 && value == 0))
        {
            dfs2(nx, ny);
        }
    }
}

int main()
{
    char temp[MAX_N + 1];
    int cnt1 = 0;
    int cnt2 = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", temp);
        for (int j = 0; j < N; j++)
        {
            if (temp[j] == 'R')
            {
                arr[i][j] = 0;
            }
            else if (temp[j] == 'G')
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited1[i][j])
            {
                dfs1(j, i);
                cnt1++;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited2[i][j])
            {
                dfs2(j, i);
                cnt2++;
            }
        }
    }
    printf("%d %d", cnt1, cnt2);
}