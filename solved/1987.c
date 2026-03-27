#include <stdio.h>

int arr[20][20];
int ds[20][20] = {0};
int visited[20][20] = {0};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int R, C;

int isValid(int x, int y)
{
    return (x >= 0 && x < R && y >= 0 && y < C);
}

int isVisitedAlphabet(int visitedAlphabet, int n)
{
    return (visitedAlphabet >> n) & 1;
}

int binaryprint(int num)
{
    // 이진수 출력
    for (int i = 25; i >= 0; --i)
    { // 8자리 숫자까지 나타냄
        int result = (num >> i) & 1;
        printf("%d", result);
    }
}
int toggleVisitedAlphabet(int visitedAlphabet, int n)
{
    return visitedAlphabet | (1 << n);
}

void dfs(int x, int y, int d, int visitedAlphabet)
{
    // printf("%d %d %d %d\n", x, y, d, arr[x][y]);
    visited[x][y] = 1;
    visitedAlphabet = toggleVisitedAlphabet(visitedAlphabet, arr[x][y]);
    if (ds[x][y] < d)
    {
        ds[x][y] = d;
    }

    for (int i = 0; i < 4; i++)
    {
        // printf("alvisited %d vsited %d\n", visitedAlphabet[arr[x + dx[i]][y + dy[i]]], visited[x + dx[i]][y + dy[i]]);
        if (isValid(x + dx[i], y + dy[i]) && !isVisitedAlphabet(visitedAlphabet, arr[x + dx[i]][y + dy[i]]) && !visited[x + dx[i]][y + dy[i]])
        {
            dfs(x + dx[i], y + dy[i], d + 1, visitedAlphabet);
            visited[x + dx[i]][y + dy[i]] = 0;
        }
    }
}

int main()
{
    scanf("%d %d", &R, &C);
    char temp;
    char dummy;
    int max = -1;
    for (int i = 0; i < R; i++)
    {
        scanf("%c", &dummy);
        for (int j = 0; j < C; j++)
        {
            scanf("%c", &temp);
            arr[i][j] = temp - 'A';
        }
    }
    dfs(0, 0, 1, 0);
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (max < ds[i][j])
            {
                max = ds[i][j];
            }
        }
    }
    printf("%d", max);
}