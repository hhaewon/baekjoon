#include <stdio.h>

void push(int);
int pop();
int size();
int isEmpty();
int top();

int arr[1000000];
int end = 0;
int main()
{
    int N;
    scanf("%d", &N);
    int a, b;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a);
        if (a == 1)
        {
            scanf("%d", &b);
            push(b);
        }
        else if (a == 2)
        {
            printf("%d\n", pop());
        }
        else if (a == 3)
        {
            printf("%d\n", size());
        }
        else if (a == 4)
        {
            printf("%d\n", isEmpty());
        }
        else if (a == 5)
        {
            printf("%d\n", top());
        }
    }
}

void push(int x)
{
    arr[end++] = x;
}

int pop()
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {
        int x = arr[end - 1];
        arr[end - 1] = 0;
        end--;
        return x;
    }
}

int size()
{
    return end;
}

int isEmpty()
{
    return end == 0;
}

int top()
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {
        return arr[end - 1];
    }
}