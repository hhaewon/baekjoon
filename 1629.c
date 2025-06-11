#include <stdio.h>

int main()
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    A %= C;
    int result = 1;
    int period = 0;
    for (int i = 0; i < B; i++)
    {
        result = (result * A) % C;

        if (result == 1)
        {
            break;
        }
    }

    if (period)
    {
        for (int i = 0; i < B % period; i++)
        {
            result = (result * A) % C;
        }
        printf("%d", result);
    }
    else
    {
        printf("%d", result);
    }
}