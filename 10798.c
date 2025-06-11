#include <stdio.h>

int main()
{
    char arr[5][15] = {0};
    char temp;
    int j = 0;

    for (int i = 0; i < 5; i++)
    {
        j = 0;
        temp = getchar();
        while (temp != '\n')
        {
            arr[i][j++] = temp;
            temp = getchar();
        }
    }

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[j][i] != '\0')
            {
                printf("%c", arr[j][i]);
            }
        }
    }
}