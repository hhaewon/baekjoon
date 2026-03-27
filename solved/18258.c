#include <stdio.h>
#include <string.h>

int N;
int queue[2000000]; // front~ end-1까지
int front = 0;
int end = 0;
int qsize = 0;

void push(int x)
{
    queue[end++] = x;
}

int empty()
{
    return front == end;
}

int pop()
{
    if (empty())
    {
        return -1;
    }
    else
    {
        return queue[front++];
    }
}

int size()
{
    return end - front;
}

int ffront()
{
    if (empty())
    {
        return -1;
    }
    else
    {
        return queue[front];
    }
}

int back()
{
    if (empty())
    {
        return -1;
    }
    return queue[end - 1];
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        char op[6];
        int temp;
        scanf("%s", op);

        if (!strcmp(op, "push"))
        {
            scanf("%d", &temp);
            push(temp);
        }
        else if (!strcmp(op, "pop"))
        {
            printf("%d\n", pop());
        }
        else if (!strcmp(op, "size"))
        {
            printf("%d\n", size());
        }
        else if (!strcmp(op, "empty"))
        {
            printf("%d\n", empty());
        }
        else if (!strcmp(op, "front"))
        {
            printf("%d\n", ffront());
        }
        else if (!strcmp(op, "back"))
        {
            printf("%d\n", back());
        }
    }
}