#include <stdio.h>

int main()
{
    int arr[8];
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &arr[i]);
    }
    int flagAscending = 1;
    int flagDescending = 1;
    for (int i = 0; i < 8; i++)
    {
        if (i + 1 != arr[i])
        {
            flagAscending = 0;
        }
        if (i + 1 != 9 - arr[i])
        {
            flagDescending = 0;
        }
    }
    if (flagAscending)
    {
        printf("ascending\n");
    }
    else if (flagDescending)
    {
        printf("descending\n");
    }
    else
    {
        printf("mixed\n");
    }
}