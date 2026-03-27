#include <stdio.h>

#define MAX 1000000
#define MAX_NUM 1000000007
typedef long long ll;

ll arr[MAX];
ll tree[MAX * 4];
ll nonZereoTree[MAX * 4];
int N, M, K;

ll init(int start, int end, int node)
{
    if (start == end)
    {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[node] = (init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1)) % MAX_NUM;
}

ll partialMul(int start, int end, int left, ll right, int node)
{
    if (end < left || right < start)
    {
        return 1;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return (partialMul(start, mid, left, right, node * 2) * partialMul(mid + 1, end, left, right, node * 2 + 1)) % MAX_NUM;
}

void update(int start, int end, int node, int index, ll value)
{
    if (index < start || index > end)
    {
        return;
    }
    tree[node] = ((partialMul(0, N - 1, start, index - 1, 1) * partialMul(0, N - 1, index + 1, end, 1)) % MAX_NUM) * value % MAX_NUM;
    if (start == end)
    {
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, value);
    update(mid + 1, end, node * 2 + 1, index, value);
}

int main()
{
    int a, b;
    ll c;
    ll num;
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
            update(0, N - 1, 1, b - 1, c);
            arr[b - 1] = c;
            break;
        case 2:
            printf("%lld\n", partialMul(0, N - 1, b - 1, c - 1, 1));
        }
    }
}