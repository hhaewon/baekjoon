#include <stdio.h>

int main()
{
    int N, T, P;
    int arr[6];
    int A = 0;
    scanf("%d", &N);
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d", &T, &P);
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] % T == 0)
        {
            A += arr[i] / T;
        }
        else
        {
            A += arr[i] / T + 1;
        }
    }
    printf("%d\n", A);
    printf("%d %d", N / P, N % P);
}