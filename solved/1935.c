#include <stdio.h>
#include <string.h>
#define MAX 1000

int N;
int nums[30];

typedef struct Stack
{
    double items[MAX];
    int top;
} Stack;

double full(Stack *s)
{
    return s->top == MAX - 1;
}

int empty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, double data)
{
    if (full(s))
    {
        return;
    }
    s->items[++s->top] = data;
}

double pop(Stack *s)
{
    if (empty(s))
    {
        return -1;
    }
    return s->items[s->top--];
}

void printStack(Stack *s)
{
    printf("Stack (top : %d): ", s->top);
    if (empty(s))
    {
        printf("\n");
        return;
    }
    for (int i = 0; i < s->top; i++)
    {
        printf("%f - ", s->items[i]);
    }
    printf("%f\n", s->items[s->top]);
}

// 후위표기식 계산

double eval(char *expr)
{
    int length = strlen(expr);
    Stack s;
    s.top = -1;
    char ch;
    for (int i = 0; i < length; i++)
    {
        ch = expr[i];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            double num2 = pop(&s);
            double num1 = pop(&s);
            switch (ch)
            {
            case '+':
                push(&s, num1 + num2);
                break;
            case '-':
                push(&s, num1 - num2);
                break;
            case '*':
                push(&s, num1 * num2);
                break;
            case '/':
                push(&s, num1 / num2);
                break;
            }
        }
        else
        {
            push(&s, nums[ch - 'A']);
        }
    }

    return pop(&s);
}

void solve()
{
    char expr[200];
    scanf("%d", &N);
    scanf("%s", expr);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
    }
    printf("%.2f", eval(expr));
}

int main()
{
    solve();
}