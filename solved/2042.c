#include <stdio.h>

#define MAX_N 1000000

long long int arr[MAX_N];
long long int tree[MAX_N * 4];

long long int init(int start, int end, int node)
{
    if (start == end)
    {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long int partialSum(int start, int end, int node, int left, int right)
{
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

void update(int start, int end, int node, int index, long long int diff)
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
    update(start, mid, node * 2, index, diff);
    update(mid + 1, end, node * 2 + 1, index, diff);
}

int main()
{
    int N, M, K, a, b;
    long long int c;
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
    }
    init(0, N - 1, 1);

    for (int i = 0; i < M + K; i++)
    {
        scanf("%d %d %lld", &a, &b, &c);
        switch (a)
        {
        case 1:
            update(0, N - 1, 1, b - 1, c - arr[b - 1]);
            arr[b - 1] = c;
            break;
        case 2:
            printf("%lld\n", partialSum(0, N - 1, 1, b - 1, c - 1));
        }
    }
}