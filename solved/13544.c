#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int *tree[MAX_N * 4];
int arr[MAX_N];

void merge(int *a, int *b, int aSzie, int bSize, int *dst)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < aSzie && j < bSize)
    {
        if (a[i] < b[j])
        {
            dst[k++] = a[i++];
        }
        else
        {
            dst[k++] = b[j++];
        }
    }
    while (i < aSzie)
    {
        dst[k++] = a[i++];
    }
    while (j < bSize)
    {
        dst[k++] = b[j++];
    }
}

void init(int start, int end, int node)
{
    if (start == end)
    {
        int *leaf = (int *)malloc(sizeof(int));
        leaf[0] = arr[start];
        tree[node] = leaf;
        return;
    }
    int mid = (start + end) / 2;
    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);
    int *merged = (int *)malloc(sizeof(int) * (end - start + 1));
    merge(tree[node * 2], tree[node * 2 + 1], mid - start + 1, end - mid, merged);
    tree[node] = merged;
}

int lowerBound(int *arr, int size, int value)
{
    int left = 0;
    int right = size;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] <= value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return right;
}

int query(int start, int end, int left, int right, int node, int k)
{
    if (start > right || end < left)
    {
        return 0;
    }
    if (left <= start && end <= right)
    {
        int size = end - start + 1;
        int index = lowerBound(tree[node], size, k);
        return size - index;
    }

    int mid = (start + end) / 2;
    return query(start, mid, left, right, node * 2, k) + query(mid + 1, end, left, right, node * 2 + 1, k);
}

int main()
{
    int N, M, a, b, c;
    int d, e, f;
    int lastAns = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    init(0, N - 1, 1);
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        d = a ^ lastAns;
        e = b ^ lastAns;
        f = c ^ lastAns;
        lastAns = query(0, N - 1, d - 1, e - 1, 1, f);
        printf("%d\n", lastAns);
    }
}