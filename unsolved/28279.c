#include <stdio.h>
#include <string.h>

#define SIZE 1000000

int N;
int deque[SIZE]; // front~ end-1까지
int front = 0;
int end = 0;
int qsize = 0;

void push_back(int x)
{
    deque[end] = x;
    end = (end + 1) % SIZE;
    qsize++;
}

void push_front(int x)
{
    front = (front - 1 + SIZE) % SIZE;
    deque[front] = x;
    qsize++;
}

int empty()
{
    return front == end;
}

int pop_front()
{
    if (empty())
    {
        return -1;
    }
    else
    {
        int result = deque[front];
        front = (front + 1) % SIZE;
        qsize--;
        return result;
    }
}

int pop_back()
{
    if (empty())
    {
        return -1;
    }
    else
    {
        int result = deque[(end - 1 + SIZE) % SIZE];
        end = (end - 1 + SIZE) % SIZE;
        qsize--;
        return result;
    }
}

int size()
{
    return qsize;
}

int ffront()
{
    if (empty())
    {
        return -1;
    }
    else
    {
        return deque[front];
    }
}

int back()
{
    if (empty())
    {
        return -1;
    }
    return deque[(end - 1 + SIZE) % SIZE];
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int op;
        int x;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &x);
            push_front(x);
        }
        else if (op == 2)
        {
            scanf("%d", &x);
            push_back(x);
        }
        else if (op == 3)
        {
            printf("%d\n", pop_front());
        }
        else if (op == 4)
        {
            printf("%d\n", pop_back());
        }
        else if (op == 5)
        {

            printf("%d\n", size());
        }
        else if (op == 6)
        {

            printf("%d\n", empty());
        }
        else if (op == 7)
        {

            printf("%d\n", ffront());
        }
        else
        {
            printf("%d\n", back());
        }
    }
}