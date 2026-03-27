#include <stdio.h>
#include <string.h>

char str1[41];
char str2[41];
int dp[41][41] = {0};

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    scanf("%s", str1);
    scanf("%s", str2);
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    char result[41][41][41] = {0};

    for (int i = 1; i <= length1; i++)
    {
        for (int j = 1; j <= length2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                strcpy(result[i][j], result[i - 1][j - 1]);
                int length = strlen(result[i][j]);
                result[i][j][length] = str1[i - 1];
                result[i][j][length + 1] = '\0';
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                    strcpy(result[i][j], result[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    strcpy(result[i][j], result[i][j - 1]);
                }
            }
        }
    }
    printf("%s", result[length1][length2]);
}