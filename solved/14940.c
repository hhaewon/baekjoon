#include <stdio.h>
#define QUEUE_SIZE 1000000
void enqueue(int x, int y);
int *dequeue();
int empty();
int isValid(int, int);

int queue[QUEUE_SIZE][2] = {0};
int maze[1000][1000] = {0};
int visitied[1000][1000] = {0};
int dist[1000][1000] = {0};
int front = 0;
int end = 0;

int n, m;

int main()
{
    int goalPos[2];

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &maze[i][j]);

            if (maze[i][j] == 2)
            {
                goalPos[0] = i;
                goalPos[1] = j;
            }
        }
    }

    enqueue(goalPos[1], goalPos[0]);
    dist[goalPos[0]][goalPos[1]] = 0;
    visitied[goalPos[0]][goalPos[1]] = 1;
    int *temp;
    int tempX, tempY;
    while (!empty())
    {
        temp = dequeue();
        tempX = temp[1];
        tempY = temp[0];
        // printf("temp (%d, %d) dist=%d visitied=%d\n ", tempY, tempX, dist[tempX][tempY], visitied[tempY][tempX]);

        if (isValid(tempX + 1, tempY) && !visitied[tempY][tempX + 1])
        {
            dist[tempY][tempX + 1] = dist[tempY][tempX] + 1;
            enqueue(tempX + 1, tempY);
            visitied[tempY][tempX + 1] = 1;
        }
        if (isValid(tempX - 1, tempY) && !visitied[tempY][tempX - 1])
        {
            dist[tempY][tempX - 1] = dist[tempY][tempX] + 1;
            enqueue(tempX - 1, tempY);
            visitied[tempY][tempX - 1] = 1;
        }
        if (isValid(tempX, tempY + 1) && !visitied[tempY + 1][tempX])
        {
            dist[tempY + 1][tempX] = dist[tempY][tempX] + 1;
            enqueue(tempX, tempY + 1);
            visitied[tempY + 1][tempX] = 1;
        }
        if (isValid(tempX, tempY - 1) && !visitied[tempY - 1][tempX])
        {
            dist[tempY - 1][tempX] = dist[tempY][tempX] + 1;
            enqueue(tempX, tempY - 1);
            visitied[tempY - 1][tempX] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visitied[i][j])
            {
                printf("%d ", dist[i][j]);
            }
            else
            {
                if (maze[i][j] == 0)
                {
                    printf("0 ");
                }
                else
                {
                    printf("-1 ");
                }
            }
        }
        printf("\n");
    }
}

void enqueue(int x, int y)
{
    int element[2] = {y, x};
    queue[end][0] = element[0];
    queue[end][1] = element[1];
    end++;
}
int *dequeue()
{
    return queue[front++];
}
int empty()
{
    return front == end;
}

int isValid(int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n && maze[y][x] == 1;
}