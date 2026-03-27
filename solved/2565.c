#include <stdio.h>

int arr[501];
int dp[501]; // dp[i] : 0 ~ i까지 최장 길이 증가 부분 수열 길이

int main()
{
    int N;
    scanf("%d", &N);

    // 이걸 왜 i = i로 했었냐 제대로 하자
    for (int i = 1; i <= N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a] = b;
    }
    dp[0] = 0;
    for (int i = 0; i <= 500; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    int max = -1;
    for (int i = 1; i <= 500; i++)
    {
        if (dp[i] > max)
        {
            max = dp[i];
        }
    }
    printf("%d", N - (max - 1));
}