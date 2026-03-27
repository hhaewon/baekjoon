#include <stdio.h>

int n, m;

int parents[500000];

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
    parents[find(y)] = find(x);
}

int isDisjoint(int x, int y)
{
    return find(x) != find(y);
}

int main()
{
    scanf("%d %d", &n, &m);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        parents[i] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (isDisjoint(a, b))
        {
            unionSet(a, b);
        }
        else
        {
            result = i;
            break;
        }
    }

    printf("%d", result);
}