#include <stdio.h>
#include <stdlib.h>

int nums[8];
int arr[8] = {0};
int N, M;

int compare(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

void solve(int index, int srcIndex)
{
    arr[index] = nums[srcIndex];
    if (index == M - 1)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (nums[i] >= nums[srcIndex])
        {
            solve(index + 1, i);
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
    }
    qsort(nums, N, sizeof(int), compare);

    for (int i = 0; i < N; i++)
    {
        solve(0, i);
    }
}