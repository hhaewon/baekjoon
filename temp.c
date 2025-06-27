#include <stdio.h>

int concat(int a, int b)
{
    int i = b;
    int result = a;
    while (i > 0)
    {
        result = result * 10;
        i /= 10;
    }
    result = result + b;
    return result;
}

int main()
{
    int a = 10;
    int b = 508;
    printf("%d", concat(a, b));
}