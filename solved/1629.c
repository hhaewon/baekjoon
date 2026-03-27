#include <stdio.h>

int main()
{
    long long int A, B, C;
    long long int arr[32] = {0};
    int n[32] = {0};
    scanf("%lld %lld %lld", &A, &B, &C);

    arr[0] = A % C;
    // printf("arr[0] = %lld\n", arr[0]);
    for (int i = 1; i < 32; i++)
    {
        arr[i] = (arr[i - 1] * arr[i - 1]) % C;
        // printf("i = %d arr[i] = %lld arr[0] = %lld \n", i, arr[i], arr[0]);
    }

    long long int temp = B;
    int j = 0;
    while (temp > 0)
    {
        n[j] = temp % 2;
        temp /= 2;
        j++;
    }

    // printf("%lld\n", arr[0]);

    long long int result = 1;
    for (int i = 0; i < 32; i++)
    {
        // printf("arr[i] = %lld \n", arr[i]);
        if (n[i])
        {
            // printf("%d %d %d\n", i, n[i], arr[i]);
            // printf("arr[i] = %lld i = %d result : %lld %lld %lld\n", arr[i], i, result, result * arr[i], (result * arr[i]) % C);
            result = (result * arr[i]) % C;
        }
    }
    printf("%lld", result);
}
