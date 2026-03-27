#include <stdio.h>
#include <string.h>

int size = 0;
char arr[100000][21] = {0};

int calc()
{
    int stringCnt[100000] = {0};
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        if (!stringCnt[i])
        {
            stringCnt[i] = 1;
            result++;
        }
        else
        {
            continue;
        }
        for (int j = i + 1; j < size; j++)
        {
            if (stringCnt[j])
            {
                continue;
            }
            if (!strcmp(arr[i], arr[j]))
            {
                stringCnt[j] = 1;
                result++;
            }
        }
    }
    return result;
}

int main()
{
    int N;
    char name[21];
    int cnt = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%s", name);

        if (!strcmp(name, "ENTER"))
        {
            cnt += calc();
            size = 0;
            continue;
        }

        strcpy(arr[size++], name);
    }
    cnt += calc();
    printf("%d", cnt);
}