#include <stdio.h>

int heap[100000];
int heapSize = 0;

void insert(int x)
{
    int i = ++heapSize;
    while (i != 1 && x < heap[i / 2])
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = x;
}

int deleteQueue()
{
    int item = heap[1];
    int parent = 1;
    int child = 2;
    int temp = heap[heapSize--];

    while (child <= heapSize)
    {
        if (child < heapSize && heap[child] > heap[child + 1])
        {
            child++;
        }
        if (temp <= heap[child])
        {
            break;
        }
        else
        {
            heap[parent] = heap[child];
            parent = child;
            child *= 2;
        }
    }

    heap[parent] = temp;
    return item;
}

void printHeap()
{
    for (int i = 1; i <= heapSize; i++)
    {

        printf("%d ", heap[i]);
    }
}

int main()
{
    int N;
    int x;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        if (x == 0)
        {
            if (heapSize == 0)
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n", deleteQueue());
            }
        }
        else
        {
            insert(x);
        }
    }
}