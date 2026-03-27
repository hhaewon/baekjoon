#include <stdio.h>

int heap[100001] = {0};
int size = 0;

void insert(int key)
{
    heap[size + 1] = key;
    int i = size + 1;
    while (1 < i && heap[i / 2] < heap[i])
    {
        int temp = heap[i / 2];
        heap[i / 2] = heap[i];
        heap[i] = temp;
        i = i / 2;
    }
    size++;
}

int deleteHeap()
{
    int result = heap[1];
    int i = 1;
    heap[1] = heap[size];
    while ((i * 2 <= size && heap[i * 2] > heap[i]) || (i * 2 + 1 <= size && heap[i * 2 + 1] > heap[i]))
    {
        if (heap[i * 2] && heap[i * 2 + 1])
        {
            if (heap[i * 2] > heap[i * 2 + 1])
            {
                int temp = heap[i];
                heap[i] = heap[i * 2];
                heap[i * 2] = temp;
                i = i * 2;
            }
            else
            {
                int temp = heap[i];
                heap[i] = heap[i * 2 + 1];
                heap[i * 2 + 1] = temp;
                i = i * 2 + 1;
            }
        }
        else if (heap[i * 2])
        {
            int temp = heap[i];
            heap[i] = heap[i * 2];
            heap[i * 2] = temp;
            i = i * 2;
        }
        else
        {
            int temp = heap[i];
            heap[i] = heap[i * 2 + 1];
            heap[i * 2 + 1] = temp;
            i = i * 2 + 1;
        }
    }
    size--;
    return result;
}

void printHeap()
{
    for (int i = 1; i <= size; i++)
    {
        printf("heap[%d]: %d, ", i, heap[i]);
    }
    printf("\n");
}

int main()
{
    int N, x;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        if (x == 0)
        {
            if (size == 0)
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n", deleteHeap());
            }
        }
        else
        {
            insert(x);
        }
        // printHeap();
    }
}