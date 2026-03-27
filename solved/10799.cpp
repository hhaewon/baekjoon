#include <stdio.h>

int main()
{
    char string[100000];
    int leftnum = 0;
    int result = 0;
    scanf("%s", string);
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '(')
        {
            leftnum++;
        }
        else
        {
            if (string[i - 1] == '(')
            {
                leftnum--;
                result += leftnum;
            }
            else
            {
                result++;
                leftnum--;
            }
        }
    }
    printf("%d", result);
}