#include <stdio.h>
#include <stdlib.h>

struct Number
{
    int val;
    int pos;
    int compress;
};
typedef struct Number Number;

int compare(const void *number1, const void *number2);

int flag = 0;
int main()
{
    int n;
    scanf("%d", &n);
    Number *numbers = (Number *)calloc(n, sizeof(Number));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i].val);
        numbers[i].pos = i;
    }
    qsort(numbers, n, sizeof(Number), compare);
    numbers[0].compress = 0;
    for (int i = 1; i < n; i++)
    {
        if (numbers[i].val == numbers[i - 1].val)
        {
            numbers[i].compress = numbers[i - 1].compress;
        }
        else
        {
            numbers[i].compress = numbers[i - 1].compress + 1;
        }
    }
    flag = 1;
    qsort(numbers, n, sizeof(Number), compare);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i].compress);
    }
    return 0;
}

int compare(const void *number1, const void *number2)
{
    Number *num1 = (Number *)number1;
    Number *num2 = (Number *)number2;
    if (flag == 0)
    {
        if (num1->val > num2->val)
        {
            return 1;
        }
        else if (num1->val < num2->val)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (num1->pos > num2->pos)
        {
            return 1;
        }
        else if (num1->pos < num2->pos)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}