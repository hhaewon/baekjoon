#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isNum(char str[9])
{
    return strcmp(str, "FizzBuzz") && strcmp(str, "Buzz") && strcmp(str, "Fizz");
}

const char *toFizzBuzz(int x)
{
    if (x % 3 == 0 && x % 5 == 0)
    {
        return "FizzBuzz";
    }
    else if (x % 3 == 0)
    {
        return "Fizz";
    }
    else if (x % 5 == 0)
    {
        return "Buzz";
    }
    else
    {
        static char buffer[10];
        sprintf(buffer, "%d", x);
        return buffer;
    }
}
int main()
{
    char a[9];
    char b[9];
    char c[9];

    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", c);
    if (isNum(a))
    {
        printf("%s", toFizzBuzz(atoi(a) + 3));
    }
    else if (isNum(b))
    {
        printf("%s", toFizzBuzz(atoi(b) + 2));
    }
    else
    {
        printf("%s", toFizzBuzz(atoi(c) + 1));
    }
}