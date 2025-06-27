#include <stdio.h>

int main()
{
    long long int arr[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5};
    for (int i = 9; i <= 100; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 5];
    }

    int T;
    int N;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        printf("%lld\n", arr[N]);
    }
}