#include <stdio.h>
#include <stdlib.h>

int minHeap[100001];
int size = 0;

void insert(int x)
{
    int i = ++size;
    while (i > 1 && x < minHeap[i / 2])
    {
        minHeap[i] = minHeap[i / 2];
        i = i / 2;
    }
    minHeap[i] = x;
}

int heapDelete()
{
    int result = minHeap[1];
    int temp = minHeap[size--];

    int parent = 1;
    int child = 2;

    while (child <= size)
    {
        if (minHeap[child + 1] < minHeap[child])
        {
            child++;
        }
        if (child > size)
        {
            break;
        }
        if (temp > minHeap[child])
        {
            minHeap[child / 2] = minHeap[child];
            child = child * 2;
        }
    }

    minHeap[child / 2] = temp;
    return result;
}

int main()
{
    int N;
    int arr[100000];
    int result = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        insert(arr[i]);
    }

    while (size >= 2)
    {
        int x = heapDelete();
        int y = heapDelete();
        // printf("%d %d\n", x, y);
        result += x + y;
        insert(x + y);
    }
    printf("%d", result);
}