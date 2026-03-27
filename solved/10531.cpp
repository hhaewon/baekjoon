#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>
#include <complex>
#include <string.h>

using cd = std::complex<double>;

#define MAX_SIZE 1 << 20

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
            cd W = inverse ? cd(cos(2 * M_PI / i), sin(2 * M_PI / i)) : cd(cos(-2 * M_PI / i), sin(-2 * M_PI / i));
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
    int N;
    int arr[200000];
    int M;
    int d[200000];

    int logsize = 19;
    int size = (int)pow(2, logsize);
    cd *A = new cd[size];
    cd *C = new cd[size];
    cd *Afft = new cd[size];
    cd *CIfft = new cd[size];
    scanf("%d", &N);
    A[0] = 1;
    for (int i = 1; i < size; i++)
    {
        A[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        A[arr[i]] = 1;
    }
    scanf("%d", &M);
    // printf("M %d\n", M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &d[i]);
    }
    fft(A, size, logsize, Afft, 0);
    for (int i = 0; i < size; i++)
    {
        C[i] = Afft[i] * Afft[i];
    }
    fft(C, size, logsize, CIfft, 1);
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        // printf("d[i] %d\n", d[i]);
        // printf("%d %d\n", i, (int)ceil(CIfft[d[i]].real()));
        int value = (int)round(CIfft[d[i]].real());
        if (value >= 1)
        {
            cnt++;
        }
    }
    printf("%d", cnt);
}