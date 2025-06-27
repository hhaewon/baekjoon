#include <stdio.h>

int flag = 0;
int min = -1;
long long int A, B;

void solve(long long int n, long long int num, int type)
{
    if (num >= B)
    {
        if (num == B)
        {
            if (!flag || min > n)
            {
                min = n;
            }
            flag = 1;
        }
        return;
    }

    if (type == 0)
    {
        solve(n + 1, num * 2, 0);
        solve(n + 1, num * 2, 1);
    }
    else
    {
        solve(n + 1, 10 * num + 1, 0);
        solve(n + 1, 10 * num + 1, 1);
    }
}

int main()
{
    scanf("%lld %lld", &A, &B);
    solve(0, A, 0);
    solve(0, A, 1);

    if (!flag)
    {
        printf("-1");
    }
    else
    {
        printf("%d", min + 1);
    }
}