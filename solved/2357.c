#include <stdio.h>

#define MAX_N 100000
#define MAX_NUM 1000000000

int arr[MAX_N];
int tree[MAX_N * 4][2];

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

int max(int a, int b)
{
    if (a < b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int *init(int start, int end, int node)
{
    if (start == end)
    {
        tree[node][0] = arr[start];
        tree[node][1] = arr[start];
        return tree[node];
    }

    int mid = (start + end) / 2;
    int *left = init(start, mid, node * 2);
    int *right = init(mid + 1, end, node * 2 + 1);
    tree[node][0] = min(left[0], right[0]);
    tree[node][1] = max(left[1], right[1]);
    return tree[node];
}

int minQuery(int start, int end, int left, int right, int node)
{
    if (start > right || end < left)
    {
        return MAX_NUM + 1;
    }

    if (left <= start && end <= right)
    {
        return tree[node][0];
    }

    int mid = (start + end) / 2;
    return min(minQuery(start, mid, left, right, node * 2), minQuery(mid + 1, end, left, right, node * 2 + 1));
}

int maxQuery(int start, int end, int left, int right, int node)
{
    if (start > right || end < left)
    {
        return -1;
    }

    if (left <= start && end <= right)
    {
        return tree[node][1];
    }

    int mid = (start + end) / 2;
    return max(maxQuery(start, mid, left, right, node * 2), maxQuery(mid + 1, end, left, right, node * 2 + 1));
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
        printf("%d %d\n", minQuery(0, N - 1, a - 1, b - 1, 1), maxQuery(0, N - 1, a - 1, b - 1, 1));
    }
}