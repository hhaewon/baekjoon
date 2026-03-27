#include <stdio.h>

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    if (N > K)
    {
        printf("%d", N - K);
    }
    else if (N == K)
    {
        printf("0");
    }
    else
    {
        int time = 0;
        while (N != K)
        {
            // printf("%d %d\n", N, K);
            if (N < K)
            {
                if (K % 2 == 0)
                {
                    if (K / 2 >= N || N - K / 2 < K - N)
                    {

                        K /= 2;
                    }
                    else
                    {
                        K--;
                        time++;
                    }
                }
                else
                {
                    K--;
                    time++;
                }
            }
            else
            {
                K += 1;
                time++;
            }
        }
        printf("%d", time);
    }
}