#include <stdio.h>

#define MAX_N 100000
#define MAX_NUM 1000000000

int arr[MAX_N];
int tree[MAX_N * 4];

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int init(int start, int end, int node)
{
    if (start == end)
    {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int query(int start, int end, int left, int right, int node)
{
    if (start > right || end < left)
    {
        return MAX_NUM + 1;
    }

    if (left <= start && end <= right)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return min(query(start, mid, left, right, node * 2), query(mid + 1, end, left, right, node * 2 + 1));
}

int main()
{
    int N, M;
    int a, b;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    init(0, N - 1, 1);

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", query(0, N - 1, a - 1, b - 1, 1));
    }
}