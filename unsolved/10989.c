#include <stdio.h>

int main()
{
    int arr[10001] = {
        0,
    };
    int N;
    scanf("%d", &N);
    int temp;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        arr[temp]++;
    }
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            printf("%d\n", i);
        }
    }
}