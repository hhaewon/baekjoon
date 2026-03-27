#include <stdio.h>

#define MAX_N 100000
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

void update(int start, int end, int index, int node, ll value)
{
    if (index < start || index > end)
    {
        return;
    }
    tree[node] = tree[node] - arr[index] + value;
    if (start == end)
    {
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, index, node * 2, value);
    update(mid + 1, end, index, node * 2 + 1, value);
}

int main()
{
    int N, Q;
    int x, y, a;
    ll b;
    scanf("%d %d", &N, &Q);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
    }
    init(0, N - 1, 1);

    for (int i = 0; i < Q; i++)
    {
        scanf("%d %d %d %lld", &x, &y, &a, &b);
        if (x <= y)
        {

            printf("%lld\n", query(0, N - 1, x - 1, y - 1, 1));
        }
        else
        {

            printf("%lld\n", query(0, N - 1, y - 1, x - 1, 1));
        }
        update(0, N - 1, a - 1, 1, b);
        arr[a - 1] = b;
    }
}