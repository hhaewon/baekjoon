#include <stdio.h>

typedef struct Queue
{
    int arr[10000];
    int first;
    int end;
} Queue;

int main()
{
    int n;
}

void initQueue(Queue *queue)
{
    queue->first = 0;
    queue->end = 0;
};
void push(Queue *queue, int x)
{
    queue->arr[queue->end++] = x;
}
int pop(Queue *queue)
{
    return queue->arr[queue->first++];
}