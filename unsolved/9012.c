#include <stdio.h>
#include <string.h>
#define MAX 1000

typedef struct
{
    char items[MAX];
    int top;
} Stack;

int full(Stack *s)
{
    return s->top == MAX - 1;
}
int emtpy(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, char data)
{
    if (full(s))
    {
        return;
    }
    s->items[++s->top] = data;
}

char peak(Stack *s)
{
    return s->items[s->top];
}

char pop(Stack *s)
{
    if (emtpy(s))
    {
        return '\0';
    }
    return s->items[s->top--];
}

void initStack(Stack *s)
{
    s->top = -1;
}
int solve()
{
    char expr[100];
    scanf("%s", expr);
    int length = strlen(expr);
    char ch;
    Stack s;
    initStack(&s);
    for (int i = 0; i < length; i++)
    {
        ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(&s, ch);
        }
        else
        {
            if (emtpy(&s))
            {
                return 0;
            }
            pop(&s);
        }
    }
    if (!emtpy(&s))
    {
        return 0;
    }
    return 1;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        if (solve())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}