#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <complex.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1 << 21
typedef double complex cd;

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int reverseBit(int x, int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        n = n << 1;
        n |= (x & 1);
        x = x >> 1;
    }
    return n;
}

void fft(cd *src, int size, int logsize, cd *dst, int inverse)
{
    for (int i = 0; i < size; i++)
    {
        int j = reverseBit(i, logsize);
        dst[j] = src[i];
    }

    for (int i = 2; i <= size; i = i * 2)
    {
        for (int j = 0; j < size; j += i)
        {
            cd W = inverse ? cos(2 * M_PI / i) + I * sin(2 * M_PI / i) : cos(-2 * M_PI / i) + I * sin(-2 * M_PI / i);
            cd w = 1;
            for (int k = 0; k < i / 2; k++)
            {
                cd even = dst[j + k];
                cd odd = dst[j + k + i / 2];
                dst[j + k] = even + w * odd;
                dst[j + k + i / 2] = even - w * odd;
                w *= W;
            }
        }
    }

    if (inverse)
    {
        for (int i = 0; i < size; i++)
        {
            dst[i] /= size;
        }
    }
}

int main()
{
    char *Astr = (char *)malloc(MAX_SIZE + 1);
    char *Bstr = (char *)malloc(MAX_SIZE + 1);
    int base = 1000;
    scanf("%s %s", Astr, Bstr);
    int length1 = strlen(Astr);
    int length2 = strlen(Bstr);
    int logsize = ceil(log2(length1 / 2 + length2 / 2 + 1));
    int size = (int)pow(2, logsize);
    cd *A = (cd *)calloc(size, sizeof(cd));
    cd *B = (cd *)calloc(size, sizeof(cd));
    cd *C = (cd *)malloc(sizeof(cd) * size);
    cd *Afft = (cd *)malloc(sizeof(cd) * size);
    cd *Bfft = (cd *)malloc(sizeof(cd) * size);
    cd *CIfft = (cd *)malloc(sizeof(cd) * size);
    int *result = (int *)malloc(sizeof(int) * size);
    // printf("%d %d\n", length1, length2);
    // printf("ls : %d\n", logsize);
    if (length1 == 1 && length2 == 1)
    {
        printf("%d", (Astr[0] - '0') * (Bstr[0] - '0'));
        return 0;
    }
    // printf("size : %d\n", size);
    // printf("A : %s B : %s\n", Astr, Bstr);

    if (length1 % 2 == 1)
    {
        for (int i = 0; length1 - i - 2 >= 0; i += 2)
        {
            // printf("A %d %lf\n", i, (double)((Astr[length1 - i - 2] - '0') * 10 + (Astr[length1 - i - 1] - '0')));
            A[i / 2] = (double)((Astr[length1 - i - 2] - '0') * 10 + (Astr[length1 - i - 1] - '0')) / base;
        }
        A[length1 / 2] = (double)(Astr[0] - '0') / base;

        // for (int i = length1 / 2 + 1; i < size; i++)
        // {
        //     A[i] = 0;
        // }
    }
    else
    {
        for (int i = 0; length1 - i - 2 >= 0; i += 2)
        {
            // printf("A %d %lf\n", i, (double)((Astr[length1 - i - 2] - '0') * 10 + (Astr[length1 - i - 1] - '0')));
            A[i / 2] = (double)((Astr[length1 - i - 2] - '0') * 10 + (Astr[length1 - i - 1] - '0')) / base;
        }

        // for (int i = length1 / 2; i < size; i++)
        // {
        //     A[i] = 0;
        // }
    }

    if (length2 % 2 == 1)
    {
        for (int i = 0; length2 - i - 2 >= 0; i += 2)
        {
            // printf("B %d %lf\n", i, (double)((Bstr[length2 - i - 2] - '0') * 10 + (Bstr[length2 - i - 1] - '0')));

            B[i / 2] = (double)((Bstr[length2 - i - 2] - '0') * 10 + (Bstr[length2 - i - 1] - '0')) / base;
        }
        B[length2 / 2] = (double)(Bstr[0] - '0') / base;

        // for (int i = length2 / 2 + 1; i < size; i++)
        // {
        //     B[i] = 0;
        // }
    }
    else
    {
        for (int i = 0; length2 - i - 2 >= 0; i += 2)
        {
            // printf("B %d %lf\n", i, (double)((Bstr[length2 - i - 2] - '0') * 10 + (Bstr[length2 - i - 1] - '0')));

            B[i / 2] = (double)((Bstr[length2 - i - 2] - '0') * 10 + (Bstr[length2 - i - 1] - '0')) / base;
        }

        // for (int i = length2 / 2; i < size; i++)
        // {
        //     B[i] = 0;
        // }
    }
    // printf("A : ");
    // for (int i = 0; i < size; i++)
    // {
    //     printf("%lf ", creal(A[i]));
    // }
    // printf("\n");
    // printf("B : ");
    // for (int i = 0; i < size; i++)
    // {
    //     printf("%lf ", creal(B[i]));
    // }
    // printf("\n");
    fft(A, size, logsize, Afft, 0);
    fft(B, size, logsize, Bfft, 0);
    for (int i = 0; i < size; i++)
    {
        C[i] = Afft[i] * Bfft[i];
    }
    fft(C, size, logsize, CIfft, 1);
    // for (int i = 0; i < size; i++)
    // {
    //     printf("%lf ", creal(CIfft[i]));
    // }

    int carry = 0;
    int len = 0;
    for (int i = 0; i < size; i++)
    {
        long long int temp = round(creal(CIfft[i] * base * base)) + carry;
        carry = temp / base;
        result[i] = temp % base;
    }
    len = size;
    while (carry)
    {
        result[len] = carry % base;
        carry = carry / base;
        len++;
    }

    int flag = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (flag && result[i] == 0)
        {
            continue;
        }
        for (int j = base / 10; j >= 1; j /= 10)
        {
            if (result[i] / j == 0 && !flag)
            {
                printf("0");
            }
            else
            {
                flag = 0;
                break;
            }
        }
        printf("%d", result[i]);
        flag = 0;
    }
}