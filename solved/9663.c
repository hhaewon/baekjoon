#include <stdio.h>

int rows[15] = {0};
int columns[15] = {0};
int visited[15][15] = {0};
int cnt = 0;
int N;

void solve(int index)
{
    if (index == N)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (rows[i] == 0 && columns[j] == 0)
            {
                // printf("%d %d selected\n", i, j);
                visited[i][j] = 1;
                rows[i] = 1;
                columns[j] = 1;
                solve(index + 1);
                rows[i] = 0;
                columns[j] = 0;
                // printf("%d %d removed\n", i, j);
            }
        }
    }
}

int main()
{
    scanf("%d", &N);
    solve(0);
    printf("%d", cnt);
}