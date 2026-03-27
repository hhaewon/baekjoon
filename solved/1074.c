#include <stdio.h>

typedef struct Node
{
    int x;
    int y;
    int size;
} Node;

int N = 0, r = 0, c = 0;
int power2(int);

int main()
{
    scanf("%d %d %d", &N, &r, &c);
    Node arr[16];
    int end = 0;
    int cnt = 0;
    arr[0].x = 0;
    arr[0].y = 0;
    arr[0].size = power2(N - 1);

    int x;
    int y;
    int size;

    for (int i = 0; i < N + 1; i++)
    {
        x = arr[end].x;
        y = arr[end].y;
        size = arr[end].size;
        if (x <= c && c < x + size && y <= r && r < y + size)
        {
            arr[end + 1].x = x;
            arr[end + 1].y = y;
        }
        else if (x + size <= c && c < x + 2 * size && y <= r && r < y + size)
        {
            arr[end + 1].x = x + size;
            arr[end + 1].y = y;
            cnt += size * size;
        }
        else if (x <= c && c < x + size && y + size <= r && r < y + 2 * size)
        {
            arr[end + 1].x = x;
            arr[end + 1].y = y + size;
            cnt += 2 * size * size;
        }
        else
        {
            arr[end + 1].x = x + size;
            arr[end + 1].y = y + size;
            cnt += 3 * size * size;
        }
        arr[end + 1].size = size / 2;
        end++;
    }
    printf("%d", cnt);
    return 0;
};

int power2(int x)
{
    int result = 1;
    for (int i = 0; i < x; i++)
    {
        result = result * 2;
    }
    return result;
}