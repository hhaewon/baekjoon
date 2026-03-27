#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int T;
    char p[100001];
    char input[1000000];
    int arr[100000];
    int n;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%s", p);
        scanf("%d", &n);
        int j;

        getchar();
        if (n != 0)
        {
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
            input[strcspn(input, "]")] = '\0';
            char *input2 = input;
            input2++;
            char *token = strtok(input2, ",");
            j = 0;
            while (token != NULL)
            {
                arr[j++] = atoi(token);
                token = strtok(NULL, ",");
            }
        }
        else
        {
            fgets(input, sizeof(input), stdin);
            j = 0;
        }
        int flipped = -1;
        int start = 0;
        int end = j - 1;
        int error = 0;

        // printf("%d\n", j);
        // for (int k = 0; k < j; k++)
        // {
        //     printf("%d ", arr[k]);
        // }
        // printf("\n");
        for (int k = 0; k < strlen(p); k++)
        {
            if (p[k] == 'R')
            {
                flipped = -flipped;
            }
            else
            {
                if (start > end)
                {
                    printf("error\n");
                    error = 1;
                    break;
                }
                if (flipped == -1)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
        if (!error)
        {
            if (flipped == -1)
            {
                printf("[");
                for (int k = start; k <= end - 1; k++)
                {
                    printf("%d,", arr[k]);
                }
                if (start > end)
                {
                    printf("]\n");
                }
                else
                {
                    printf("%d]\n", arr[end]);
                }
            }
            else
            {
                printf("[");
                for (int k = end; k >= start + 1; k--)
                {
                    printf("%d,", arr[k]);
                }
                if (start > end)
                {
                    printf("]\n");
                }
                else
                {
                    printf("%d]\n", arr[start]);
                }
            }
        }
    }
}