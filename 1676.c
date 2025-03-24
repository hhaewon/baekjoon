#include <stdio.h>

int main()
{
    int N;
    int nFive;
    scanf("%d", &N);
    nFive = N / 5 + N / 25 + N / 125;
    printf("%d", nFive);
}