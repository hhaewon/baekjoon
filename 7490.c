#include <stdio.h>
#include <stdlib.h>

int toPrints[10][10000] = {0};
int *thisPrint;
int i = 0;
int N;
int cnt;

int flip(int a)
{
    int result = 0;
    while (a > 0)
    {
        result = result * 10 + a % 10;
        a /= 10;
    }
    return result;
}

int static compare(const void *first, const void *second)
{
    if (*(int *)first < *(int *)second)
        return 1;
    else if (*(int *)first > *(int *)second)
        return -1;
    else
        return 0;
}

int concat(int a, int b)
{
    int i = b;
    int result = a;
    while (i > 0)
    {
        result *= 10;
        i /= 10;
    }
    result = result + b;
    return result;
}

void func(int last, int concats, int op, int toEqual, int toPrint)
{
    if (last == 1)
    {
        if (concats == toEqual)
        {
            toPrints[i][cnt++] = toPrint;
        }
        return;
    }

    int newConcats = concat(last - 1, concats);

    if (last == 2)
    {
        if (op == 2)
        {
            func(last - 1, last - 1, 2, toEqual - concats, toPrint * 10 + 3);
        }
        else if (op == 1)
        {

            func(last - 1, newConcats, 2, toEqual, toPrint * 10 + 3);
        }
        else
        {
            func(last - 1, last - 1, 2, toEqual + concats, toPrint * 10 + 3);
        }
        return;
    }
    if (op == 2)
    {
        func(last - 1, last - 1, 2, toEqual - concats, toPrint * 10 + 2);
        func(last - 1, last - 1, 1, toEqual - concats, toPrint * 10 + 3);
        func(last - 1, last - 1, 0, toEqual - concats, toPrint * 10 + 1);
    }
    else if (op == 1)
    {

        func(last - 1, newConcats, 2, toEqual, toPrint * 10 + 2);
        func(last - 1, newConcats, 1, toEqual, toPrint * 10 + 3);
        func(last - 1, newConcats, 0, toEqual, toPrint * 10 + 1);
    }
    else
    {
        func(last - 1, last - 1, 2, toEqual + concats, toPrint * 10 + 2);
        func(last - 1, last - 1, 1, toEqual + concats, toPrint * 10 + 3);
        func(last - 1, last - 1, 0, toEqual + concats, toPrint * 10 + 1);
    }
}

// op 2 : +, op 3 : 빈칸, op 1 : -
int main()
{
    int T;
    scanf("%d", &T);

    for (i = 0; i < T; i++)
    {
        if (i > 0)
        {
            printf("\n");
        }
        cnt = 0;
        scanf("%d", &N);
        func(N, N, 2, 0, 2);
        func(N, N, 1, 0, 3);
        func(N, N, 0, 0, 1);
        thisPrint = toPrints[i];

        for (int j = 0; j < cnt; j++)
        {
            thisPrint[j] = flip(thisPrint[j] / 10);
        }

        qsort(thisPrint, cnt, sizeof(int), compare);
        for (int j = 0; j < cnt; j++)
        {
            int ops[10] = {0};
            int temp = thisPrint[j];
            for (int k = N - 1; k >= 1; k--)
            {
                ops[k] = temp % 10;
                temp /= 10;
            }
            for (int k = 1; k < N; k++)
            {

                printf("%d", k);
                if (ops[k] == 2)
                {
                    printf("+");
                }
                else if (ops[k] == 3)
                {
                    printf(" ");
                }
                else
                {
                    printf("-");
                }
            }
            printf("%d\n", N);
        }
    }

    return 0;
}