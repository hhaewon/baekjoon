#include <stdio.h>

int parents[1000001];

int n, m;
int op, a, b;

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
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++)
    {
        parents[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &op, &a, &b);
        if (op == 0)
        {
            unionSet(a, b);
        }
        else
        {
            int result = !isDisjoint(a, b);
            if (result)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
}