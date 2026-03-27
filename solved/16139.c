#include <stdio.h>
#include <string.h>
#define L 200000

char str[L + 1];
int q;
int s[26][L + 1];
int idx;
char a;
int l;
int r;

int main()
{
    scanf("%s", str);
    scanf("%d", &q);

    for (int j = 0; j < strlen(str); j++)
    {
        idx = str[j] - 'a';
        for (int i = 0; i < 26; i++)
        {
            if (idx == i)
            {
                s[i][j + 1] = s[i][j] + 1;
            }
            else
            {
                s[i][j + 1] = s[i][j];
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        scanf(" %c %d %d", &a, &l, &r);
        idx = a - 'a';
        printf("%d\n", s[idx][r + 1] - s[idx][l]);
    }

    return 0;
}