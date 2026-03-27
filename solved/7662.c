#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

typedef struct Node
{
    int value;
    int index;
} Node;

typedef struct MaxHeap
{
    int size;
    Node **heap;
} MaxHeap;

typedef struct MinHeap
{
    int size;
    Node **heap;
} MinHeap;

void maxHeapInsert(MaxHeap *maxHeap, Node *node)
{
    int i = ++maxHeap->size;
    while (1 < i && maxHeap->heap[i / 2]->value < node->value)
    {
        maxHeap->heap[i] = maxHeap->heap[i / 2];
        i = i / 2;
    }
    maxHeap->heap[i] = node;
}

void maxHeapDelete(MaxHeap *maxHeap)
{
    int parent = 1;
    int child = 2;
    Node *temp = maxHeap->heap[maxHeap->size--];

    while (child <= maxHeap->size)
    {
        if (child < maxHeap->size && maxHeap->heap[child]->value < maxHeap->heap[child + 1]->value)
        {
            child++;
        }

        if (temp->value >= maxHeap->heap[child]->value)
        {
            break;
        }
        maxHeap->heap[parent] = maxHeap->heap[child];
        parent = child;
        child *= 2;
    }
    maxHeap->heap[parent] = temp;
}

void minHeapInsert(MinHeap *minHeap, Node *node)
{
    int i = ++minHeap->size;
    while (1 < i && minHeap->heap[i / 2]->value > node->value)
    {
        minHeap->heap[i] = minHeap->heap[i / 2];
        i = i / 2;
    }
    minHeap->heap[i] = node;
}

void minHeapDelete(MinHeap *minHeap)
{
    int parent = 1;
    int child = 2;
    Node *temp = minHeap->heap[minHeap->size--];

    while (child <= minHeap->size)
    {
        if (child < minHeap->size && minHeap->heap[child]->value > minHeap->heap[child + 1]->value)
        {
            child++;
        }

        if (temp->value <= minHeap->heap[child]->value)
        {
            break;
        }
        minHeap->heap[parent] = minHeap->heap[child];
        parent = child;
        child *= 2;
    }
    minHeap->heap[parent] = temp;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int k;
        char op;
        int n;
        MaxHeap maxHeap;
        MinHeap minHeap;
        maxHeap.heap = (Node **)malloc(sizeof(Node *) * MAX_SIZE);
        minHeap.heap = (Node **)malloc(sizeof(Node *) * MAX_SIZE);
        int *visited = (int *)malloc(sizeof(int) * MAX_SIZE);
        maxHeap.size = 0;
        minHeap.size = 0;

        scanf("%d", &k);
        // printf("dd");
        for (int i = 0; i < k; i++)
        {
            scanf(" %c %d", &op, &n);
            if (op == 'I')
            {
                Node *newNode = (Node *)malloc(sizeof(Node));
                newNode->value = n;
                newNode->index = i;
                maxHeapInsert(&maxHeap, newNode);
                minHeapInsert(&minHeap, newNode);
                visited[i] = 0;
            }
            else
            {
                if (maxHeap.size == 0)
                {
                    continue;
                }
                if (n == 1)
                {
                    while (maxHeap.size != 0 && visited[maxHeap.heap[1]->index])
                    {
                        maxHeapDelete(&maxHeap);
                    }
                    if (maxHeap.size != 0)
                    {
                        Node *maxNode = maxHeap.heap[1];
                        visited[maxHeap.heap[1]->index] = 1;
                        maxHeapDelete(&maxHeap);
                    }
                }
                else
                {
                    while (minHeap.size != 0 && visited[minHeap.heap[1]->index])
                    {
                        minHeapDelete(&minHeap);
                    }
                    if (minHeap.size != 0)
                    {

                        Node *minNode = minHeap.heap[1];
                        visited[minHeap.heap[1]->index] = 1;
                        minHeapDelete(&minHeap);
                    }
                }
            }
        }

        while (maxHeap.size != 0 && visited[maxHeap.heap[1]->index])
        {
            maxHeapDelete(&maxHeap);
        }
        while (minHeap.size != 0 && visited[minHeap.heap[1]->index])
        {
            minHeapDelete(&minHeap);
        }
        if (maxHeap.size == 0 || minHeap.size == 0)
        {
            printf("EMPTY\n");
        }
        else
        {
            printf("%d %d\n", maxHeap.heap[1]->value, minHeap.heap[1]->value);
        }
    }
}