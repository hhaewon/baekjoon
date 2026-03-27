#include <stdio.h>
#include <stdlib.h>

int N;
int arr[100000][2] = {0};
int dp[100000] = {0};

int compare(const void *a, const void *b)
{
    const int *rowA = (const int *)a;
    const int *rowB = (const int *)b;

    if (rowA[1] < rowB[1])
    {
        return -1;
    }
    else if (rowA[1] > rowB[1])
    {
        return 1;
    }
    else
    {
        return rowA[0] - rowB[0];
    }
}

int main()
{
    int cnt = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    qsort(arr, N, 2 * sizeof(int), compare);
    int nEnd = arr[0][0];
    for (int i = 0; i < N; i++)
    {
        if (arr[i][0] >= nEnd)
        {
            cnt++;
            nEnd = arr[i][1];
        }
    }

    printf("%d", cnt);
}