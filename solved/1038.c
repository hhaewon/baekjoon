#include <stdio.h>

int cnt = -2;
long long result = -1;

int N;
void solve(int n, int prev, int index, long long x)
{
    // printf("%d %d %d %d %d\n", n, prev, index, x, cnt);
    if (index == n)
    {

        // printf("+ %d %d %d %d %d\n", n, prev, index, x, cnt);
        if (cnt == N)
        {
            result = x;
        }
        cnt++;
        return;
    }

    for (int i = 0; i < prev; i++)
    {
        solve(n, i, index + 1, 10 * x + i);
        if (result != -1)
        {
            return;
        }
    }
}

int main()
{
    scanf("%d", &N);
    if (N == 0)
    {
        printf("0");
        return 0;
    }
    cnt++;

    for (int i = 0; i <= 10; i++)
    {
        solve(i, 10, 0, 0);
        if (result != -1)
        {
            printf("%lld", result);
            return 0;
        }
        // cnt = 0;
    }
    printf("-1");
}