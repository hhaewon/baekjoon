#include <stdio.h>

int arr[500][500];
int heights[257] = {0};

int main()
{
    int N, M, B, temp, needblocks, ownblocks;
    int min = 256 * 500 * 500 * 2;
    int maxHeight = -1;
    scanf("%d %d %d", &N, &M, &B);
    // printf("N:%d M:%d\n", N, M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &arr[i][j]);
            heights[arr[i][j]]++;
        }
    }

    for (int height = 0; height <= 256; height++)
    {
        needblocks = 0;
        ownblocks = B;
        temp = 0;

        for (int i = height + 1; i <= 256; i++)
        {
            temp += 2 * heights[i] * (i - height);
            ownblocks += heights[i] * (i - height);
        }
        for (int i = 0; i < height; i++)
        {
            needblocks += heights[i] * (height - i);
        }

        if (needblocks > ownblocks)
        {
            continue;
        }
        temp += needblocks;

        if (temp <= min)
        {
            min = temp;
            maxHeight = height;
        }
    }

    printf("%d %d", min, maxHeight);
}