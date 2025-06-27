#include <stdio.h>

int main()
{
    int N;
    int scores[300];
    int score = 0;
    int j = -1;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &scores[i]);
    }
    if (N == 3)
    {
        if (scores[1] > scores[0])
        {
            score = scores[1] + scores[2];
            j += 3;
        }
        else
        {
            score = scores[0] + scores[2];
            j += 3;
        }
    }
    while (j < N - 3)
    {
        if (scores[j + 3] > scores[j + 1] + scores[j + 4])
        {
            score += scores[j + 3] + scores[j + 2];
            j += 3;
        }
        else
        {
            score += scores[j + 1] + scores[j + 3];
            j += 3;
        }
    }
    if (N == 1)
    {
        score = scores[0];
    }
    else if (N == 2)
    {
        score = scores[0] + scores[1];
    }
    else
    {
        if (j != N - 1)
        {
            score += scores[N - 1];
        }
    }

    printf("%d", score);
}
