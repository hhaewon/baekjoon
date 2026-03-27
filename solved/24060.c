#include <stdio.h>

int saved[100000000];
int cnt = 0;
int temp[500000];
void merge(int A[], int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int t = 0;
    while (i <= mid && j <= end)
    {
        if (A[i] <= A[j])
        {
            temp[t++] = A[i++];
        }
        else
        {
            temp[t++] = A[j++];
        }
    }

    while (i <= mid)
    {
        temp[t++] = A[i++];
    }
    while (j <= end)
    {
        temp[t++] = A[j++];
    }
    i = start;
    t = 0;
    while (i <= end)
    {
        A[i++] = temp[t];
        saved[cnt++] = temp[t];
        t++;
    }
}

void mergeSort(int A[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(A, start, mid);
        mergeSort(A, mid + 1, end);
        merge(A, start, mid, end);
    }
}

int main()
{
    int A[500000];
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    mergeSort(A, 0, N - 1);

    if (cnt >= K)
        printf("%d", saved[K - 1]);
    else
        printf("-1");
}
