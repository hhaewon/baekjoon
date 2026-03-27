#include <stdio.h>

int heap[100001] = {0};
int size = 0;

int abs(int x)
{
    if (x >= 0)
    {
        return x;
    }
    else
    {
        return -x;
    }
}

int up(int i, int j)
{
    return (abs(heap[i]) < abs(heap[j]) || (abs(heap[i]) == abs(heap[j]) && heap[i] < heap[j]));
}

void insert(int key)
{
    heap[size + 1] = key;
    int i = size + 1;
    while (1 < i && up(i, i / 2))
    {
        int temp = heap[i / 2];
        heap[i / 2] = heap[i];
        heap[i] = temp;
        i = i / 2;
    }
    size++;
}

int heapDelete()
{
    int result = heap[1];
    heap[1] = heap[size];
    int i = 1;
    while ((i * 2 <= size && up(i * 2, i)) || (i * 2 + 1 <= size && up(i * 2 + 1, i)))
    {
        int temp = heap[i];
        if (i * 2 <= size && i * 2 + 1 <= size)
        {
            if (up(i * 2, i * 2 + 1))
            {
                heap[i] = heap[i * 2];
                heap[i * 2] = temp;
                i = i * 2;
            }
            else
            {
                heap[i] = heap[i * 2 + 1];
                heap[i * 2 + 1] = temp;
                i = i * 2 + 1;
            }
        }
        else if (i * 2 <= size)
        {
            heap[i] = heap[i * 2];
            heap[i * 2] = temp;
            i = i * 2;
        }
        else
        {
            heap[i] = heap[i * 2 + 1];
            heap[i * 2 + 1] = temp;
            i = i * 2 + 1;
        }
    }

    size--;
    return result;
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
                printf("%d\n", heapDelete());
            }
        }
        else
        {
            insert(x);
        }
    }
}