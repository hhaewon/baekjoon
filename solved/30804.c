#include <stdio.h>

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
    int arr[200000];
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int start = 0;
    int end = 0;
    int usingFruits[10] = {0}; // 개수,
    int kind = 1;
    int maxFruitNum = 0;
    usingFruits[arr[start]]++;
    while (start < N && end < N)
    {
        if (kind <= 2)
        {
            maxFruitNum = max(maxFruitNum, end - start + 1);
        }

        if (kind == 1)
        {
            if (end + 1 < N && arr[end] != arr[end + 1])
            {
                usingFruits[arr[end + 1]]++;
                end++;
                kind++;
            }
            else
            {
                usingFruits[arr[end + 1]]++;
                end++;
            }
        }
        else if (kind == 2)
        {
            if (end + 1 < N)
            {
                if (usingFruits[arr[end + 1]])
                {
                    usingFruits[arr[end + 1]]++;
                    end++;
                }
                else
                {
                    usingFruits[arr[end + 1]]++;
                    end++;
                    kind++;
                }
            }
            else
            {
                end++;
            }
        }
        else
        {
            if (usingFruits[arr[start]] >= 2)
            {
                usingFruits[arr[start]]--;
                start++;
            }
            else
            {
                usingFruits[arr[start]]--;
                kind--;
                start++;
            }
        }
    }
    printf("%d", maxFruitNum);
}