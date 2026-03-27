#include <iostream>

#define MAX_SIZE 3000

using namespace std;

int graph[MAX_SIZE + 1][MAX_SIZE + 1];
int d[MAX_SIZE + 1][MAX_SIZE + 1];
int weakness[MAX_SIZE + 1];

int N;

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

void bfs(int start)
{
    int visited[MAX_SIZE + 1] = {0};
    int queue[MAX_SIZE];
    int front = 0;
    int end = 0;
    queue[end++] = start;

    visited[start] = 1;
    d[start][start] = 0;
    while (front < end)
    {
        int temp = queue[front++];

        for (int i = 1; i <= N; i++)
        {
            if (graph[temp][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                d[start][i] = d[start][temp] + 1;
                queue[end++] = i;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    int wins[MAX_SIZE + 1] = {0};
    for (int i = 1; i <= N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++)
        {
            if (str[j] == 'W')
            {

                wins[i]++;
            }
        }
    }

    int gosu = 0;
    int maxWins = -1;
    for (int i = 1; i <= N; i++)
    {
        if (wins[i] > maxWins)
        {
            gosu = i;
            maxWins = wins[i];
        }
    }
    if (maxWins == N - 1)
    {
        printf("1 %d", gosu);
    }
    else
    {
        printf("2 %d", gosu);
    }
}