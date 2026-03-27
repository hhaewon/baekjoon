#include <stdio.h>

int main()
{
    int x1, y1, x2, y2, x3, y3;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);
    int result = (x2 - x1) * (y1 - y3) + (x3 - x1) * (y2 - y1);

    if (result < 0)
    {
        printf("1");
    }
    else if (result > 0)
    {
        printf("-1");
    }
    else
    {
        printf("0");
    }
}