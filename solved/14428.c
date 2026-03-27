#include <stdio.h>

#define MAX_N 100000

int arr[MAX_N];
int tree[MAX_N * 4]; // min index
int N, M, a, b, c;

int init(int start, int end, int node)
{
    if (start == end)
    {
        return tree[node] = start;
    }

    int mid = (start + end) / 2;
    int leftIndex = init(start, mid, node * 2);
    int rightIndex = init(mid + 1, end, node * 2 + 1);
    if (arr[leftIndex] < arr[rightIndex])
    {
        return tree[node] = leftIndex;
    }
    else if (arr[leftIndex] > arr[rightIndex])
    {
        return tree[node] = rightIndex;
    }
    else
    {
        if (leftIndex <= rightIndex)
        {
            return tree[node] = leftIndex;
        }
        else
        {
            return tree[node] = rightIndex;
        }
    }
}

int query(int start, int end, int left, int right, int node)
{
    if (left > right)
    {
        return -1;
    }
    if (start > right || end < left)
    {
        return -1;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;
    int leftIndex = query(start, mid, left, right, node * 2);
    int rightIndex = query(mid + 1, end, left, right, node * 2 + 1);
    if (leftIndex == -1)
    {
        return rightIndex;
    }
    if (rightIndex == -1)
    {
        return leftIndex;
    }
    if (arr[leftIndex] < arr[rightIndex])
    {
        return leftIndex;
    }
    else if (arr[leftIndex] > arr[rightIndex])
    {
        return rightIndex;
    }
    else
    {
        if (leftIndex <= rightIndex)
        {
            return leftIndex;
        }
        else
        {
            return rightIndex;
        }
    }
}

void update(int start, int end, int index, int node, int value)
{
    if (index < start || index > end)
    {
        return;
    }

    if (start == end)
    {
        return;
    }

    int leftIndex = query(0, N - 1, start, index - 1, 1);
    int rightIndex = query(0, N - 1, index + 1, end, 1);
    int minIndex;
    if (leftIndex == -1 && rightIndex != -1)
    {
        minIndex = rightIndex;
    }
    else if (rightIndex == -1 && leftIndex != -1)
    {
        minIndex = leftIndex;
    }
    else
    {
        if (arr[leftIndex] < arr[rightIndex])
        {
            minIndex = leftIndex;
        }
        else if (arr[leftIndex] > arr[rightIndex])
        {
            minIndex = rightIndex;
        }
        else
        {
            if (leftIndex <= rightIndex)
            {
                minIndex = leftIndex;
            }
            else
            {
                minIndex = rightIndex;
            }
        }
    }

    if (value < arr[minIndex])
    {
        tree[node] = index;
    }
    else if (value > arr[minIndex])
    {
        tree[node] = minIndex;
    }
    else
    {
        if (index <= minIndex)
        {
            tree[node] = index;
        }
        else
        {
            tree[node] = minIndex;
        }
    }
    int mid = (start + end) / 2;
    update(start, mid, index, node * 2, value);
    update(mid + 1, end, index, node * 2 + 1, value);
}

int main()
{
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
        // for (int j = 1; j <= 4 * N; j++)
        // {
        //     printf("%d : %d\n", j, tree[j]);
        // }
        switch (a)
        {
        case 1:
            update(0, N - 1, b - 1, 1, c);
            arr[b - 1] = c;
            break;
        case 2:
            printf("%d\n", query(0, N - 1, b - 1, c - 1, 1) + 1);
        }
    }
}