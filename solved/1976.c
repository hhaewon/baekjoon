#include <stdio.h>

int N, M;

int parents[201];
int plan[1000];

int find(int x)
{
    if (parents[x] == x)
    {
        return x;
    }
    return parents[x] = find(parents[x]);
}

void unionSet(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y)
    {
        return;
    }
    parents[y] = x;
}

int isDisjoint(int x, int y)
{
    x = find(x);
    y = find(y);

    return x != y;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        parents[i] = i;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int temp;
            scanf("%d", &temp);
            if (temp)
            {
                unionSet(i, j);
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &plan[i]);
    }

    int flag = 1;
    for (int i = 0; i < M - 1; i++)
    {
        if (isDisjoint(plan[i], plan[i + 1]))
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}