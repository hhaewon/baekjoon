#include <stdio.h>
#define MAX_N 1000000

typedef long long ll;

ll arr[MAX_N];
ll tree[MAX_N * 4];

ll init(int start, int end, int node)
{
    if (start == end)
    {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll query(int start, int end, int left, int right, int node)
{
    if (start > right || end < left)
    {
        return 0;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return query(start, mid, left, right, node * 2) + query(mid + 1, end, left, right, node * 2 + 1);
}

void update(int start, int end, int index, int node, ll diff)
{
    if (index < start || index > end)
    {
        return;
    }
    tree[node] += diff;
    if (start == end)
    {
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, index, node * 2, diff);
    update(mid + 1, end, index, node * 2 + 1, diff);
}

int main()
{
    int N, M;
    int a, b, c, d;
    ll e;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        arr[i] = 0;
    }
    init(0, N - 1, 1);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &a);
        switch (a)
        {
        case 0:
            scanf("%d %d", &b, &c);
            if (b <= c)
            {
                printf("%lld\n", query(0, N - 1, b - 1, c - 1, 1));
            }
            else
            {

                printf("%lld\n", query(0, N - 1, c - 1, b - 1, 1));
            }
            break;
        case 1:
            scanf("%d %lld", &d, &e);
            update(0, N - 1, d - 1, 1, e - arr[d - 1]);
            arr[d - 1] = e;
        }
    }
}