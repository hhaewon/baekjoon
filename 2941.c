#include <stdio.h>

int main()
{
    char str[101];
    scanf("%s", str);
    int length = 0;
    int cnt = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    cnt = length;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == 'c' && str[i + 1] == '=')
        {
            cnt--;
        }
        else if (str[i] == 'c' && str[i + 1] == '-')
        {
            cnt--;
        }
        else if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=')
        {
            cnt -= 2;
        }
        else if (str[i] == 'd' && str[i + 1] == '-')
        {
            cnt--;
        }
        else if (str[i] == 'l' && str[i + 1] == 'j')
        {
            cnt--;
        }
        else if (str[i] == 'n' && str[i + 1] == 'j')
        {
            cnt--;
        }
        else if (str[i] == 's' && str[i + 1] == '=')
        {
            cnt--;
        }
        else if (str[i] == 'z' && str[i + 1] == '=' && (i == 0 || str[i - 1] != 'd'))
        {
            cnt--;
        }
    }
    printf("%d\n", cnt);
    return 0;
}