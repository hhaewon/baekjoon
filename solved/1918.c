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

int prec(char op)
{
    switch (op)
    {
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
}

void printInfixToPostfix(char *expr)
{
    int length = strlen(expr);
    char ch;
    char temp;
    Stack s;
    s.top = -1;
    for (int i = 0; i < length; i++)
    {
        ch = expr[i];
        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/':

            while (!emtpy(&s) && prec(peak(&s)) >= prec(ch))
            {
                printf("%c", pop(&s));
            }
            push(&s, ch);
            break;
        case '(':
            push(&s, '(');
            break;
        case ')':
            temp = pop(&s);
            while (temp != '(')
            {
                printf("%c", temp);
                temp = pop(&s);
            }
            break;
        default:
            printf("%c", ch);
            break;
        }
    }
    while (!emtpy(&s))
    {
        printf("%c", pop(&s));
    }
}

void solve()
{
    char expr[200];
    scanf("%s", expr);
    printInfixToPostfix(expr);
}

int main()
{
    solve();
}