#include <stdio.h>

int main()
{
    int n = 0;
    int former_index = 0;
    char str[100];
    int flag = 0;
    scanf("%d", &n);
    int cnt = n;
    while (n--)
    {
        str[0] = '\0';
        scanf("%s", str);
        flag = 0;

        for (int i = 0; str[i] != '\0'; i++)
        {
            former_index = i;
            for (int j = i + 1; str[j] != '\0'; j++)
            {
                if (str[i] == str[j])
                {
                    if (former_index + 1 != j)
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        former_index = j;
                    }
                }
            }
            if (flag == 1)
            {
                cnt--;
                break;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}