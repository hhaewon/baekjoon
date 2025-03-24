#include <stdio.h>
#include <string.h>

int S[21];
void add(int x);
void check(int x);
void toggle(int x);
void remove_(int x);
void all();
void empty();

int main()
{
    empty();
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        char command[7];
        int x;
        scanf("%s", command);
        if (!strcmp(command, "add"))
        {
            scanf("%d", &x);
            add(x);
        }
        else if (!strcmp(command, "check"))
        {
            scanf("%d", &x);
            check(x);
        }
        else if (!strcmp(command, "remove"))
        {
            scanf("%d", &x);
            remove_(x);
        }
        else if (!strcmp(command, "toggle"))
        {
            scanf("%d", &x);
            toggle(x);
        }
        else if (!strcmp(command, "empty"))
        {
            empty();
        }
        else
        {
            all();
        }
    }
    return 0;
}

void empty()
{
    for (int i = 1; i <= 20; i++)
    {
        S[i] = 0;
    }
}
void add(int x)
{
    S[x] = 1;
}
void remove_(int x)
{
    S[x] = 0;
}
void check(int x)
{
    printf("%d\n", S[x]);
}
void all()
{
    for (int i = 1; i <= 20; i++)
    {
        S[i] = 1;
    }
}
void toggle(int x)
{
    S[x] = !S[x];
}