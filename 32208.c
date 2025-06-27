#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int x, y, z;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        if ((x + y + z) % 2 == 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}