#include <stdio.h>
#include <malloc.h>

void merge(int *arr1, int size1, int *arr2, int size2, int *dst)
{
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] <= arr2[j])
        {
            dst[k++] = arr1[i++];
        }
        else
        {
            dst[k++] = arr2[j++];
        }
    }

    while (i < size1)
    {
        dst[k++] = arr1[i++];
    }
    while (j < size2)
    {
        dst[k++] = arr2[j++];
    }
}

void mergeSort(int *src, int size, int *dst)
{
    if (size == 1)
    {
        dst[0] = src[0];
        return;
    }
    int *arr1 = (int *)malloc(sizeof(int) * (size / 2));
    int *arr2 = (int *)malloc(sizeof(int) * (size - size / 2));
    mergeSort(src, size / 2, arr1);
    mergeSort(src + (size / 2), size - size / 2, arr2);
    merge(arr1, size / 2, arr2, size - size / 2, dst);
}

int main()
{
    int *arr;
    int N;
    scanf("%d", &N);
    arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    int *dst = (int *)malloc(sizeof(int) * N);
    mergeSort(arr, N, dst);
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", dst[i]);
    }
}