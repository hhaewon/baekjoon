#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a, num2 = *(int *)b;
    if (num1 > num2)
    {
        return 1;
    }
    else if (num1 < num2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    int arr[300000];
    int sum = 0;
    scanf("%d", &n);
    int limit = (int)round(n * 0.15);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    for (int i = limit; i < n - limit; i++)
    {
        sum += arr[i];
    }
    if (n == 0)
    {
        printf("0");
    }
    else
    {
        printf("%d", (int)round(((double)sum) / (n - 2 * limit)));
    }
}