#include <stdio.h>

int arr[1000];
int N, K;

void insertionSort(int lst[], int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] < key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, N);
    printf("%d", arr[K - 1]);
}