#include <stdio.h>

#define MAX_N 1000000

long long int arr[MAX_N];
long long int tree[MAX_N * 4];
long long int lazy[MAX_N * 4] = {0};

long long int init(int start, int end, int node)
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

void update(int start, int end, int node, int left, int right, long long int diff)
{
    lazyUpdate(start, end, node);
    if (right < start || left > end)
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
    update(start, mid, node * 2, left, right, diff);
    update(mid + 1, end, node * 2 + 1, left, right, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long int partialSum(int start, int end, int node, int left, int right)
{
    lazyUpdate(start, end, node);
    if (end < left || right < start)
    {
        return 0;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return partialSum(start, mid, node * 2, left, right) + partialSum(mid + 1, end, node * 2 + 1, left, right);
}

int main()
{
    int N, M, K, a, b, c;
    long long int d;
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
    }
    init(0, N - 1, 1);

    for (int i = 0; i < M + K; i++)
    {
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            scanf("%d %d %lld", &b, &c, &d);
            update(0, N - 1, 1, b - 1, c - 1, d);
            break;
        case 2:
            scanf("%d %d", &b, &c);
            printf("%lld\n", partialSum(0, N - 1, 1, b - 1, c - 1));
        }
    }
}