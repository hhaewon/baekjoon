#include <stdio.h>

int arr[8] = {0};
int N, M;

void solve(int index, int prev)
{
    arr[index] = prev;
    if (index == M - 1)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = prev; i <= N; i++)
    {
        solve(index + 1, i);
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        solve(0, i);
    }
}