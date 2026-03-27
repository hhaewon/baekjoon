#include <stdio.h>

#define MAX_N 100000
typedef long long ll;

ll arr[MAX_N];
ll tree[MAX_N * 4];
ll lazy[MAX_N * 4] = {0};

int init(int start, int end, int node)
{
    if (start == end)
    {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void lazyUpdate(int start, int end, int node)
{
    if (lazy[node] != 0)
    {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int start, int end, int left, int right, int node, ll diff)
{
    lazyUpdate(start, end, node);
    if (start > right || end < left)
    {

        return;
    }
    if (left <= start && end <= right)
    {
        tree[node] += (end - start + 1) * diff;
        if (start != end)
        {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, left, right, node * 2, diff);
    update(mid + 1, end, left, right, node * 2 + 1, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int start, int end, int node, int left, int right)
{
    lazyUpdate(start, end, node);
    if (start > right || end < left)
    {
        return 0;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

int main()
{
    int N, M, a, b, c, x;
    ll k;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
    }
    scanf("%d", &M);
    init(0, N - 1, 1);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            scanf("%d %d %lld", &b, &c, &k);
            update(0, N - 1, b - 1, c - 1, 1, k);
            break;
        case 2:
            scanf("%d", &x);
            printf("%lld\n", query(0, N - 1, 1, x - 1, x - 1));
        }
    }
}