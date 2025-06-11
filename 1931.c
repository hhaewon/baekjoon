#include <stdio.h>
#include <stdlib.h>

typedef struct Coord
{
    int start;
    int end;
} Coord;

int maxNumber(int, int);

int N;
Coord arr[100000];

int compare(const void *a, const void *b)
{
    int start1 = ((Coord *)a)->start;
    int end1 = ((Coord *)a)->end;
    int start2 = ((Coord *)b)->start;
    int end2 = ((Coord *)b)->end;
    if (start1 < start2)
    {
        return -1;
    }
    else if (start1 > start2)
    {
        return 1;
    }
    else
    {
        if (end1 < end2)
        {
            return -1;
        }
        else if (end1 > end2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    int x = 0;
    int y = 0;
    int maxY = 0;
    int max = 0;
    int temp = 0;
    int cnt = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &x, &y);
        arr[i].start = x;
        arr[i].end = y;
        if (y > maxY)
        {
            maxY = y;
        }
    }
    int *dp = (int *)calloc(maxY + 1, sizeof(int)); // i이상에서의 최대
    for (int i = 0; i < N; i++)
    {
        if (arr[i].start == arr[i].end)
        {
            dp[arr[i].start]++;
        }
    }

    for (int i = maxY; i >= 0; i--)
    {
        max = 0;
        for (int j = i; j <= maxY; j++)
        {
            temp = dp[j];
            // printf("temp : %d\n", temp);
            for (int k = 0; k < N; k++)
            {
                // printf("i, j : %d, %d\n", i, j);
                if (i <= arr[k].start && arr[k].end <= j && arr[k].start != arr[k].end)
                {
                    // printf("k : %d\n", k);
                    temp++;
                }
            }
            if (max < temp)
            {
                max = temp;
            }
            // printf("tt");
        }
        dp[i] = max;
    }
    //    qsort(arr, N, sizeof(Coord), compare);
    // for (int i = 0; i < N; i++
    // {
    //     printf("%d %d\n", arr[i].start, arr[i].end);
    // }
    //    int max = maxNumber(0, 0);
    printf("%d", dp[0]);
}

// int maxNumber(int x, int startIndex)
//{
//     int max = 0;
//     int temp = 0;
//     int cnt = 0;
//     for (int i = startIndex; i < N; i++)
//     {
//         if (x <= arr[i].start)
//         {
//             temp = maxNumber(arr[i].end, i + 1) + 1;
//             if (temp > max)
//             {
//                 max = temp;
//             }
//             cnt++;
//         }
//     }
//     if (cnt == 0)
//     {
//         return 0;
//     }
//     else
//     {
//         return max;
//     }
// }