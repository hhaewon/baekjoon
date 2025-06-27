#include <stdio.h>
#include <string.h>

char flipedResult[1001];
void flip(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        flipedResult[i] = string[strlen(string) - i - 1];
    }
}

int solve(char *a, char *b)
{
    int flag = 1;
    int l = strlen(a);
    int L = strlen(b);
    int maxIndex = -1;
    int indexs[1000] = {0};
    int count = 0;

    for (int i = 0; i <= L - l; i++)
    {
        flag = 1;
        for (int j = i; j < i + l; j++)
        {
            if (a[j - i] != b[j])
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            indexs[count++] = i;
        }
    }
    if (count == -1)
    {
        return 0;
    }
    for (int j = 0; j < count; j++)
    {

        int rightA = 0;
        int rightB = 0;
        int leftA = 0;
        int leftB = 0;

        for (int i = 0; i < indexs[j]; i++)
        {
            if (b[i] == 'A')
            {
                leftA++;
            }
            else
            {
                leftB++;
            }
        }
        for (int i = indexs[j] + l; i < L; i++)
        {
            if (b[i] == 'A')
            {
                rightA++;
            }
            else
            {
                rightB++;
            }
        }
        printf("lA %d lB %d rA %d rB %d\n", leftA, leftB, rightA, rightB);
        if ((leftB == rightB + 1 || leftB == rightB) && ((leftA && b[indexs[j] - 1] == 'B') || !leftA))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char S[1001];
    char T[1001];
    scanf("%s %s", S, T);
    char newS[1001];
    flip(S);
    strcpy(newS, flipedResult);
    strcat(newS, "B");
    printf("%d", solve(S, T) || solve(newS, T));
}