#include <stdio.h>

int N, M;
int arr[500][500];
int result = -1;

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void solve1()
{
    // - - - -
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j + 3 < M; j++)
        {
            int temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
            result = max(result, temp);
        }
    }
    // -
    // -
    // -
    // -
    for (int i = 0; i + 3 < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];
            result = max(result, temp);
        }
    }
}

void solve2()
{
    // - -
    // - -
    for (int i = 0; i + 1 < N; i++)
    {
        for (int j = 0; j + 1 < M; j++)
        {
            int temp = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
            result = max(result, temp);
        }
    }
}

void solve3()
{
    // -
    // -
    // - -
    for (int i = 0; i + 2 < N; i++)
    {
        for (int j = 0; j + 1 < M; j++)
        {
            int temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];
            result = max(result, temp);
        }
    }
    //   -
    //   -
    // - -
    for (int i = 0; i + 2 < N; i++)
    {
        for (int j = 0; j + 1 < M; j++)
        {
            int temp = arr[i + 2][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
            result = max(result, temp);
        }
    }
    // - -
    // -
    // -
    for (int i = 0; i + 2 < N; i++)
    {
        for (int j = 0; j + 1 < M; j++)
        {
            int temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i][j + 1];
            result = max(result, temp);
        }
    }
    // - -
    //   -
    //   -
    for (int i = 0; i + 2 < N; i++)
    {
        for (int j = 0; j + 1 < M; j++)
        {
            int temp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
            result = max(result, temp);
        }
    }
    // - - -
    // -
    for (int i = 0; i + 1 < N; i++)
    {
        for (int j = 0; j + 2 < M; j++)
        {
            int temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j];
            result = max(result, temp);
        }
    }
    // -
    // - - -
    for (int i = 0; i + 1 < N; i++)
    {
        for (int j = 0; j + 2 < M; j++)
        {
            int temp = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2] + arr[i][j];
            result = max(result, temp);
        }
    }
    // - - -
    //     -
    for (int i = 0; i + 1 < N; i++)
    {
        for (int j = 0; j + 2 < M; j++)
        {
            int temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
            result = max(result, temp);
        }
    }
    //     -
    // - - -
    for (int i = 0; i + 1 < N; i++)
    {
        for (int j = 0; j + 2 < M; j++)
        {
            int temp = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2] + arr[i][j + 2];
            result = max(result, temp);
        }
    }
}

void solve4()
{
    // -
    // - -
    //   -
    for (int i = 0; i + 2 < N; i++)
    {
        for (int j = 0; j + 1 < M; j++)
        {
            int temp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
            result = max(result, temp);
        }
    }
    //   -
    // - -
    // -
    for (int i = 0; i + 2 < N; i++)
    {
        for (int j = 0; j + 1 < M; j++)
        {
            int temp = arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j];
            result = max(result, temp);
        }
    }
    //   - -
    // - -
    for (int i = 0; i + 1 < N; i++)
    {
        for (int j = 0; j + 2 < M; j++)
        {
            int temp = arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j] + arr[i + 1][j + 1];
            result = max(result, temp);
        }
    }
    // - -
    //   - -
    for (int i = 0; i + 1 < N; i++)
    {
        for (int j = 0; j + 2 < M; j++)
        {
            int temp = arr[i][j + 1] + arr[i][j] + arr[i + 1][j + 2] + arr[i + 1][j + 1];
            result = max(result, temp);
        }
    }
}

void solve5()
{
    // - - -
    //   -
    for (int i = 0; i + 1 < N; i++)
    {
        for (int j = 0; j + 2 < M; j++)
        {
            int temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
            result = max(result, temp);
        }
    }
    //   -
    // - - -
    for (int i = 0; i + 1 < N; i++)
    {
        for (int j = 0; j + 2 < M; j++)
        {
            int temp = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2] + arr[i][j + 1];
            result = max(result, temp);
        }
    }
    // -
    // - -
    // -
    for (int i = 0; i + 2 < N; i++)
    {
        for (int j = 0; j + 1 < M; j++)
        {
            int temp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j];
            result = max(result, temp);
        }
    }
    //   -
    // - -
    //   -
    for (int i = 0; i + 2 < N; i++)
    {
        for (int j = 0; j + 1 < M; j++)
        {
            int temp = arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
            result = max(result, temp);
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    solve1();
    solve2();
    solve3();
    solve4();
    solve5();
    printf("%d", result);
}