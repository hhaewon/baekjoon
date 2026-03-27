#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int arr[10000];
    int sortedArr[10000];
    int first;
    int end;
    int size;
    int targetIndex;
} Queue;

Queue initQueue(int targetIndex, int n);
void push(Queue *, int);
int pop(Queue *);
void sort(Queue *);

int main()
{
    int T;
    int n, m;
    int x;
    int temp;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &n, &m);
        Queue queue = initQueue(m, n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &x);
            push(&queue, x);
        }
        sort(&queue);
        for (int i = 0; i < n; i++)
        {
            int j = queue.first;
            temp = pop(&queue);
            while (temp != queue.sortedArr[i])
            {
                if (j == queue.targetIndex)
                {
                    push(&queue, temp);
                    queue.targetIndex = queue.end - 1;
                }
                else
                {
                    push(&queue, temp);
                }
                j++;
                temp = pop(&queue);
            }
            if (j == queue.targetIndex)
            {
                printf("%d\n", i + 1);
                break;
            }
        }
    }
}

Queue initQueue(int targetIndex, int n)
{
    Queue queue;
    queue.first = 0;
    queue.end = 0;
    queue.targetIndex = targetIndex;
    queue.size = n;
    for (int i = 0; i < n; i++)
    {
        queue.arr[i] = 0;
    }
    return queue;
};
void push(Queue *queue, int x)
{
    queue->arr[queue->end++] = x;
}
int pop(Queue *queue)
{
    return queue->arr[queue->first++];
}

int compare(const void *first, const void *second)
{
    if (*(int *)first > *(int *)second)
        return -1;
    else if (*(int *)first < *(int *)second)
        return 1;
    else
        return 0;
}

void sort(Queue *queue)
{
    for (int i = 0; i < queue->size; i++)
    {
        queue->sortedArr[i] = queue->arr[i];
    }
    qsort(queue->sortedArr, queue->size, sizeof(int), compare);
}