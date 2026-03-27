#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int A = *(int *)a;
    int B = *(int *)b;

    if (A > B)
    {
        return 1;
    }
    else if (A < B)
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
    int arr[100000];
    int x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp);
    scanf("%d", &x);
    int cnt = 0;
    int start = 0;
    int end = n - 1;
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d\n", arr[i]);
    // }
    while (start < end)
    {
        if (arr[start] + arr[end] == x)
        {
            cnt++;
        }

        if (arr[start] + arr[end] < x)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    printf("%d", cnt);
}