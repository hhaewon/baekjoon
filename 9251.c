#include <stdio.h>
#include <string.h>

char str1[1001];
char str2[1001];
int dp[1001][1001] = {0};
int indexindex[26] = {0};

int main()
{
    int temp;
    scanf("%s", str1);
    scanf("%s", str2);
    int length1 = strlen(str1);
    int length2 = strlen(str2);

    for (int i = 0; i < length1; i++)
    {
        for (int j = 0; j < length2; j++)
        {
            if (str1[i] == str2[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                if (dp[i + 1][j] > dp[i][j + 1])
                {

                    dp[i + 1][j + 1] = dp[i + 1][j];
                }
                else
                {

                    dp[i + 1][j + 1] = dp[i][j + 1];
                }
            }
        }
    }
    printf("%d", dp[length1][length2]);
}