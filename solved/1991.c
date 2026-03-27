#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    char value;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

Node *tree[26];

void firstSearch(Node *node)
{
    if (node->value == '.')
    {
        return;
    }
    printf("%c", node->value);
    firstSearch(node->left);
    firstSearch(node->right);
}

void middleSearch(Node *node)
{
    if (node->value == '.')
    {
        return;
    }
    middleSearch(node->left);
    printf("%c", node->value);
    middleSearch(node->right);
}

void secondSearch(Node *node)
{
    if (node->value == '.')
    {
        return;
    }
    secondSearch(node->left);
    secondSearch(node->right);
    printf("%c", node->value);
}

int main()
{
    int N;
    char current, leftChr, rightChr;
    scanf("%d", &N);
    Node *root = (Node *)malloc(sizeof(Node));

    for (int i = 0; i < N; i++)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->value = i + 'A';
        temp->left = (Node *)malloc(sizeof(Node));
        temp->left->value = '.';
        temp->right = (Node *)malloc(sizeof(Node));
        temp->right->value = '.';
        tree[i] = temp;
    }

    // for (int i = 0; i < N; i++)
    // {
    //     printf("%c %c %c\n", tree[i]->value, tree[i]->left->value, tree[i]->right->value);
    // }

    for (int i = 0; i < N; i++)
    {
        scanf(" %c %c %c", &current, &leftChr, &rightChr);
        if (leftChr != '.')
        {
            tree[current - 'A']->left = tree[leftChr - 'A'];
        }
        if (rightChr != '.')
        {
            tree[current - 'A']->right = tree[rightChr - 'A'];
        }
    }
    //
    // for (int i = 0; i < N; i++)
    // {
    //     printf("%c %c %c\n", tree[i]->value, tree[i]->left->value, tree[i]->right->value);
    // }

    firstSearch(tree[0]);
    printf("\n");
    middleSearch(tree[0]);
    printf("\n");
    secondSearch(tree[0]);
    printf("\n");
}