#include <stdio.h>
#include <string.h>

int number[50];
int minus[50];
char str[51];

int sum(int left, int right)
{
    int result = 0;
    for (int i = left; i <= right; i++)
    {
        result += number[i];
    }
    return result;
}

int main()
{
    scanf("%s", str);
    int length = strlen(str);
    int j = 0;
    int k = 0;
    int temp = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '+')
        {
            number[k++] = temp;
            temp = 0;
        }
        else if (str[i] == '-')
        {
            number[k++] = temp;
            minus[j++] = k - 1;
            temp = 0;
        }
        else
        {
            temp = 10 * temp + (str[i] - '0');
        }
    }
    number[k++] = temp;

    // for (int i = 0; i < k; i++)
    // {
    //     printf("%d ", number[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < j; i++)
    // {
    //     printf("%d ", minus[i]);
    // }

    // printf("\n");
    if (j == 0)
    {
        printf("%d", sum(0, k - 1));
        return 0;
    }

    int result = sum(0, minus[0]);
    int i = 1;
    while (i <= j - 1)
    {
        result -= sum(minus[i - 1] + 1, minus[i]);
        i++;
    }
    result -= sum(minus[j - 1] + 1, k - 1);
    printf("%d", result);
}
