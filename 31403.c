#include <stdio.h>
#include <math.h>

int main()
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    int n = floor(log10((double)B));
    printf("%d\n%d", A + B - C, (int)(ceil(pow(10.0, n + 1))) * A + B - C);
    return 0;
}