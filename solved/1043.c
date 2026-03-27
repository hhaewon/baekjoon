#include <stdio.h>

int arr[50][51] = {0};
int people[51] = {0};
int visited[50][51] = {0};
int truthIndexs[50][2] = {0};
int truthPartyCnt = 0;

void dfs(int x, int y)
{
    visited[x][y] = 1;
    people[y] = 1;
    // printf("x %d, y %d\n", x, y);
    for (int i = 0; i < 50; i++)
    {
        if (arr[i][y] && !visited[i][y])
        {
            dfs(i, y);
        }
    }

    for (int i = 1; i <= 50; i++)
    {
        if (arr[x][i] && !visited[x][i])
        {
            dfs(x, i);
        }
    }
}

int main()
{
    int N, M;
    int L;
    int temp;
    int flag = 1;
    int result = 0;
    scanf("%d %d", &N, &M);
    scanf("%d", &L);

    for (int i = 0; i < L; i++)
    {
        scanf("%d", &temp);
        people[temp] = 1;
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &L);
        for (int j = 1; j <= L; j++)
        {
            scanf("%d", &temp);
            arr[i][temp] = 1;
            if (people[temp] == 1 && (truthPartyCnt == 0 || truthIndexs[truthPartyCnt - 1][0] != i))
            {
                truthIndexs[truthPartyCnt++][0] = i;
                truthIndexs[truthPartyCnt - 1][1] = temp;
            }
        }
    }

    for (int i = 0; i < truthPartyCnt; i++)
    {
        dfs(truthIndexs[i][0], truthIndexs[i][1]);
    }

    for (int i = 0; i < M; i++)
    {
        flag = 1;
        for (int j = 1; j <= 50; j++)
        {
            if (arr[i][j] && people[j] == 1)
            {
                // printf("i %d j %d people[arr[i][j]] %d\n", i, j, people[arr[i][j]]);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            // printf("i %d\n", i);
            result++;
        }
    }
    // printf("%d truthPartyCnt %d M %d", result, truthPartyCnt, M);
    printf("%d", result);
}