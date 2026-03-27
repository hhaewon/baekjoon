#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_N 100000

typedef struct Node
{
    char url[21];
    char password[21];
} Node;

Node arr[MAX_N];

int N, M;
void find(char url[21])
{
    int left = 0;
    int right = N - 1;
    while (1)
    {
        int mid = (left + right) / 2;
        // printf("%s %s %d %d %d\n", arr[mid].url, url, strcmp(arr[mid].url, url), left, right);
        if (strcmp(arr[mid].url, url) < 0)
        {
            left = mid + 1;
        }
        else if (strcmp(arr[mid].url, url) > 0)
        {
            right = mid - 1;
        }
        else
        {
            printf("%s\n", arr[mid].password);
            return;
        }
    }
}

int compare(const void *first, const void *second)
{
    Node *a = (Node *)first;
    Node *b = (Node *)second;
    return strcmp(a->url, b->url);
}

int main()
{
    char url[21];
    char password[21];
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", arr[i].url);
        scanf("%s", arr[i].password);
    }
    qsort(arr, N, sizeof(Node), compare);
    for (int i = 0; i < M; i++)
    {
        scanf("%s", url);
        find(url);
    }
}