#include <stdio.h>

int main()
{
    int N = 0;
    int cnt = 0;
    scanf("%d", &N);
    while (cnt * cnt <= N)
    {
        cnt++;
    }
    printf("%d", cnt - 1);
}