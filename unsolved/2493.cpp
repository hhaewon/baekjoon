#include <stdio.h>

#define MAX 500000

typedef struct
{
    int index;
    int data;
} Item;

typedef struct Stack
{
    Item items[MAX];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void pushStack(Stack *s, int index, int data)
{
    if (isFull(s))
    {
        return;
    }
    Item item = {index, data};
    s->items[++s->top] = item;
}

Item popStack(Stack *s)
{
    if (isEmpty(s))
    {
        Item dummyItem = {-1, -1};
        return dummyItem;
    }
    return s->items[s->top--];
}

Item peak(Stack *s)
{
    if (isEmpty(s))
    {
        Item dummyItem = {-1, -1};
        return dummyItem;
    }
    return s->items[s->top];
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int N;
int heights[MAX];
int maxHeights[MAX];
int results[MAX];
Stack s;

int main()
{

    initStack(&s);
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (isEmpty(&s))
        {
            printf("0 ");
            continue;
        }
        if (peak(&s).data > temp)
        {
            printf("%d", peak(&s).index);
            pushStack(&s, i, temp);
        }
        else
        {
            while (peak(&s).data < temp)
            {
                popStack(&s);
            }
        }
    }
