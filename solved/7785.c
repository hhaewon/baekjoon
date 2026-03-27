#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *str1, const void *str2)
{
    return strcmp((char *)str2, (char *)str1);
}

char persons[1000001][6];

int main()
{
    int n;
    scanf("%d", &n);
    char dummy[6];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", persons[i]);
        scanf("%s", dummy);
    }
    qsort(persons, n, sizeof(char[6]), compare);

    for (int i = 0; i < n; i++)
    {
        if (!strcmp(persons[i], persons[i + 1]))
        {
            i++;
        }
        else
        {
            printf("%s\n", persons[i]);
        }
    }
    return 0;
}
