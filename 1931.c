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
    scanf("%d", &N);
    int x = 0;
    int y = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &x, &y);
        arr[i].start = x;
        arr[i].end = y;
    }
    qsort(arr, N, sizeof(Coord), compare);
    // for (int i = 0; i < N; i++)
    // {
    //     printf("%d %d\n", arr[i].start, arr[i].end);
    // }
    int max = maxNumber(0, 0);
    printf("%d", max);
}

int maxNumber(int x, int startIndex)
{
    int max = 0;
    int temp = 0;
    int cnt = 0;
    for (int i = startIndex; i < N; i++)
    {
        if (x <= arr[i].start)
        {
            temp = maxNumber(arr[i].end, i + 1) + 1;
            if (temp > max)
            {
                max = temp;
            }
            cnt++;
        }
    }
    if (cnt == 0)
    {
        return 0;
    }
    else
    {
        return max;
    }
}