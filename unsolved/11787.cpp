#include <iostream>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int fastMultiple(ll a, ll b)
{
    if (b == 1)
    {
        return a;
    }
    if (b == 0)
    {
        return 0;
    }

    if (b % 2 == 0)
    {
        return 2 * fastMultiple(a, b / 2) % MOD;
    }
    else
    {
        return (2 * fastMultiple(a, b / 2) + a) % MOD;
    }
}

void matrixMultiply(ll M[2][2], ll L[2][2], ll dst[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            dst[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                dst[i][j] += fastMultiple(M[i][k], L[k][j]);
            }
            dst[i][j] = dst[i][j] % MOD;
        }
    }
}

void matrixPower(ll M[2][2], ll n, ll dst[2][2])
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            dst[i][j] = 0;

    if (n == 0)
    {
        for (int i = 0; i < 2; i++)
        {
            dst[i][i] = 1;
        }
        return;
    }
    if (n == 1)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                dst[i][j] = M[i][j] % MOD;
            }
        }
        return;
    }
    ll subMatrix[2][2] = {0};
    ll temp[2][2] = {0};
    matrixPower(M, n / 2, subMatrix);
    if (n % 2 == 0)
    {
        matrixMultiply(subMatrix, subMatrix, dst);
        return;
    }
    if (n % 2 == 1)
    {

        matrixMultiply(subMatrix, subMatrix, temp);
        matrixMultiply(temp, M, dst);
        return;
    }
}

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    ll B[2][2] = {{1, 1}, {1, 0}};
    ll A[2][2] = {0, 1, 0, 1};
    ll temp[2][2] = {0};
    ll result[2][2] = {0};

    ll m, n;
    cin >> m >> n;
    ll gcdmn = gcd(m, n);
    matrixPower(B, gcdmn - 1, temp);
    matrixMultiply(temp, A, result);
    cout << result[1][1] % MOD;
}