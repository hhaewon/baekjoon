#include <stdio.h>

#define SIZE 100

int jumping[SIZE + 1] = {0};
int d[SIZE + 1] = {0};
int N, M;
int queue[SIZE * 1];
int front = 0;
int rear = 0;

void bfs()
{
    queue[rear++] = 1;
    d[1] = 0;
    int temp;
    while (front != rear)
    {
        int cur = queue[front++];

        for (int i = 1; i <= 6; i++)
        {
            int nx = cur + i;
            if (nx > 100)
            {
                break;
            }

            if (jumping[nx] != 0)
            {
                nx = jumping[nx];
            }

            if (d[nx] == -1)
            {
                d[nx] = d[cur] + 1;
                queue[rear++] = nx;
            }
        }
    }
}

int main()
{
    int x, y;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N + M; i++)
    {
        scanf("%d %d", &x, &y);
        jumping[x] = y;
    }
    for (int i = 1; i <= SIZE; i++)
    {
        d[i] = -1;
    }
    bfs();
    printf("%d", d[100]);
}