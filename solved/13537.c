#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100000

int arr[MAX_N];
int *tree[MAX_N * 4];

int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

void merge(int *a, int *b, int aSize, int bSize, int *dst)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (0 <= i && i < aSize && 0 <= j && j < bSize)
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
    while (0 <= i && i < aSize)
    {
        dst[k++] = a[i++];
    }
    while (0 <= j && j < bSize)
    {
        dst[k++] = b[j++];
    }
}

void init(int start, int end, int node)
{
    if (start == end)
    {
        tree[node] = (int *)malloc(sizeof(int));
        tree[node][0] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    int *merged = (int *)malloc(sizeof(int) * (end - start + 1));
    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);
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
    // printf("%d %d %d %d %d %d %d\n", start, end, left, right, node, tree[node], k);
    if (start > right || end < left)
    {
        return 0;
    }
    if (left <= start && end <= right)
    {
        int size = end - start + 1;
        int lowerBoundIndex = lowerBound(tree[node], end - start + 1, k);
        return size - lowerBoundIndex;
    }

    if (start == end)
    {
        if (tree[node][0] > k)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int mid = (start + end) / 2;
    return query(start, mid, left, right, node * 2, k) + query(mid + 1, end, left, right, node * 2 + 1, k);
}

int main()
{
    int N, M;
    scanf("%d", &N);
    int a, b, c;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    init(0, N - 1, 1);
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", query(0, N - 1, a - 1, b - 1, 1, c));
    }
}