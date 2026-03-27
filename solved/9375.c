#include <stdio.h>
#include <string.h>

int T, n, size;
typedef struct Cloth
{
    char name[21];
    int count;
} Cloth;

Cloth clothes[30];

void add(char kind[21])
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(clothes[i].name, kind) == 0)
        {
            clothes[i].count++;
            return;
        }
    }
    strcpy(clothes[size].name, kind);
    clothes[size].count = 1;
    size++;
}

main()
{
    scanf("%d", &T);
    char name[21];
    char kind[21];
    int result = 1;
    for (int i = 0; i < T; i++)
    {
        size = 0;
        result = 1;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%s %s", name, kind);
            add(kind);
        }
        // for (int j = 0; j < size; j++)
        // {
        //     printf("%s %d\n", clothes[j].name, clothes[j].count);
        // }
        for (int j = 0; j < size; j++)
        {
            result *= clothes[j].count + 1;
        }
        result -= 1;
        printf("%d\n", result);
    }
}