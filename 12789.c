#include <stdio.h>

typedef struct Stack
{
    int arr[1000];
    int end;
} Stack;

int main()
{
    int N;
    int a;
    Stack currentStack;
    Stack extraStack;
    currentStack.end = 0;
    extraStack.end = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a);
        push(&currentStack, a);
    }
    int x;
    int toPop = 1;
    while (1)
    {
        x = pop(&currentStack);
        if (toPop == x)
        {
            toPop++;
        }
        else
        {
            push(&extraStack, x);
        }
    }
}

void push(Stack *stack, int x)
{
    stack->arr[stack->end++] = x;
}

int pop(Stack *stack)
{
    int x = stack->arr[stack->end - 1];
    stack->arr[stack->end - 1] = 0;
    stack->[end]--;
    return x;
}