#include <stdio.h>
#include <stdlib.h>

#define LOGN 18
#define TREE_SIZE 100001

typedef struct Node
{
    struct Node **parents;
    int value;
    int depth;
} Node;

Node *tree[TREE_SIZE];
int *adj[TREE_SIZE];
int edges[TREE_SIZE][2];
int adjSize[TREE_SIZE] = {0};
int adjIndex[TREE_SIZE] = {0};

int findCommonAncestor(Node *a, Node *b)
{
    Node *aPointer = a;
    Node *bPointer = b;
    // printf("a %d b %d\n depth : %d %d", aPointer->value, bPointer->value, aPointer->depth, bPointer->depth);

    int i = LOGN - 1;
    if (aPointer->depth > bPointer->depth)
    {
        while (aPointer->depth > bPointer->depth)
        {
            if (aPointer->parents[i]->depth >= bPointer->depth)
            {
                aPointer = aPointer->parents[i];
            }
            i--;
        }
    }
    else if (aPointer->depth < bPointer->depth)
    {
        while (aPointer->depth < bPointer->depth)
        {
            if (aPointer->depth <= bPointer->parents[i]->depth)
            {
                // printf("i : %d\n", i);
                bPointer = bPointer->parents[i];
            }
            i--;
        }
    }

    i = LOGN - 1;
    // printf("a : %d, b : %d\n", aPointer->value, bPointer->value);
    while (aPointer != bPointer)
    {
        // printf("i : %d, %d %d\n", i, aPointer->parents[i]->value, bPointer->parents[i]->value);
        if (i == 0 || (aPointer->parents[i] != bPointer->parents[i] && aPointer->parents[i + 1] == bPointer->parents[i + 1]))
        {
            aPointer = aPointer->parents[i];
            bPointer = bPointer->parents[i];
            i++;
        }
        i--;
    }
    return aPointer->value;
}

void dfs(Node *parentNode, Node *node)
{
    // printf("parentNode %d, node %d\n", parentNode->value, node->value);
    node->parents[0] = parentNode;
    node->depth = parentNode->depth + 1;
    int i = 1;

    while (i < LOGN)
    {
        // printf("node : %d, i : %d parents[i-1] : %d, parents[i-1][i-1] : %d\n", node->value, i, node->parents[i - 1]->value, node->parents[i - 1]->parents[i - 1]->value);
        node->parents[i] = node->parents[i - 1]->parents[i - 1];
        i++;
    }
    int value = node->value;
    for (int i = 0; i < adjSize[value]; i++)
    {
        if (tree[adj[value][i]]->parents[0] == NULL && adj[value][i] != 1)
        {
            dfs(node, tree[adj[value][i]]);
        }
    }
}

int main()
{
    int N, M;
    scanf("%d", &N);
    int x, y;
    for (int i = 1; i <= N; i++)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->value = i;
        temp->parents = (Node **)calloc(LOGN, sizeof(Node *));
        temp->depth = 0;
        tree[i] = temp;
    }
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &x, &y);
        edges[i][0] = x;
        edges[i][1] = y;
        adjSize[x]++;
        adjSize[y]++;
    }
    for (int i = 1; i <= N; i++)
    {
        adj[i] = (int *)malloc(sizeof(int) * adjSize[i]);
    }

    for (int i = 0; i < N - 1; i++)
    {
        x = edges[i][0];
        y = edges[i][1];
        adj[x][adjIndex[x]++] = y;
        adj[y][adjIndex[y]++] = x;
    }

    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 0; j < adjSize[i]; j++)
    //     {
    //         printf("%d ", adj[i][j]);
    //     }
    //     printf("\n");
    // // }
    Node *emptyNode = (Node *)malloc(sizeof(Node));
    emptyNode->depth = -1;
    emptyNode->parents = (Node **)calloc(LOGN, sizeof(Node *));
    emptyNode->value = -1;
    for (int i = 0; i < LOGN; i++)
    {
        emptyNode->parents[i] = emptyNode;
    }
    dfs(emptyNode, tree[1]);

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &x, &y);
        printf("%d\n", findCommonAncestor(tree[x], tree[y]));
    }
}