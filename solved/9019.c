#include <stdio.h>
#include <string.h>

void bfs(int A, int B, char *output)
{
    char d[10000][100] = {0};
    int visited[10000] = {0};
    int queue[10000];
    int front = 0;
    int rear = 0;
    queue[rear++] = A;
    visited[A] = 1;
    int i = 0;
    while (front < rear && !visited[B])
    {
        int temp = queue[front++];

        int value1 = (temp * 2) % 10000;
        int value2 = (temp - 1 + 10000) % 10000;
        int value3 = (temp % 1000) * 10 + temp / 1000;
        int value4 = (temp / 10) + (temp % 10) * 1000;

        // printf("i : %d, %d %d %d %d %d\n", i++, temp, value1, value2, value3, value4);
        if (!visited[value1])
        {
            visited[value1] = 1;
            queue[rear++] = value1;
            strcpy(d[value1], d[temp]);
            strcat(d[value1], "D");
        }
        if (!visited[value2])
        {
            visited[value2] = 1;
            queue[rear++] = value2;
            strcpy(d[value2], d[temp]);
            strcat(d[value2], "S");
        }
        if (!visited[value3])
        {
            visited[value3] = 1;
            queue[rear++] = value3;
            strcpy(d[value3], d[temp]);
            strcat(d[value3], "L");
        }
        if (!visited[value4])
        {
            visited[value4] = 1;
            queue[rear++] = value4;
            strcpy(d[value4], d[temp]);
            strcat(d[value4], "R");
        }
    }
    strcpy(output, d[B]);
}

int main()
{
    int T;
    int A, B;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &A, &B);
        char result[100];
        bfs(A, B, result);
        printf("%s\n", result);
    }
}