#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *parent;
    int value;
} Node;

Node *arr[100001];
int visited[100001] = {0};
int *adj[100001];
int adjSize[100001] = {0};
int adjIndex[100001] = {0};
int edges[100000][2];

void dfs(Node *parentNode, Node *node)
{
    int value = node->value;
    node->parent = parentNode;
    visited[value] = 1;
    int nextValue;
    for (int i = 0; i < adjSize[value]; i++)
    {
        nextValue = adj[value][i];
        if (!visited[nextValue])
        {
            dfs(node, arr[nextValue]);
        }
    }
}

int main()
{
    int x, y;
    int N;
    scanf("%d", &N);

    Node root;
    root.value = 1;
    arr[1] = &root;
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &x, &y);
        adjSize[x]++;
        adjSize[y]++;
        edges[i][0] = x;
        edges[i][1] = y;
    }

    for (int i = 1; i <= N; i++)
    {
        adj[i] = (int *)malloc(sizeof(int) * adjSize[i]);
    }

    for (int i = 1; i <= N; i++)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->value = i;
        // printf("i : %d, value : %d\n", i, temp->value);
        arr[i] = temp;
    }

    for (int i = 0; i < N - 1; i++)
    {
        x = edges[i][0];
        y = edges[i][1];
        adj[x][adjIndex[x]++] = y;
        adj[y][adjIndex[y]++] = x;
    }

    // printf("adj arr\n");
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 0; j < adjSize[i]; j++)
    //     {
    //         printf("%d ", adj[i][j]);
    //     }
    //     printf("\n");
    // }

    dfs(NULL, &root);

    for (int i = 2; i <= N; i++)
    {
        printf("%d\n", arr[i]->parent->value);
    }
}