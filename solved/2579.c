#include <stdio.h>

int dp1[300] = {0}; // 연속 x
int dp2[300] = {0}; // 연속 o

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int N;
    int scores[300];
    int score = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &scores[i]);
    }
    if (N == 1)
    {
        printf("%d", scores[0]);
        return 0;
    }
    if (N == 2)
    {
        printf("%d", scores[0] + scores[1]);
        return 0;
    }
    dp1[0] = scores[0];
    dp1[1] = scores[1];
    dp2[1] = scores[0] + scores[1];
    for (int i = 2; i < N; i++)
    {
        dp1[i] = max(dp1[i - 2], dp2[i - 2]) + scores[i];
        dp2[i] = dp1[i - 1] + scores[i];
    }

    printf("%d", max(dp1[N - 1], dp2[N - 1]));
}
