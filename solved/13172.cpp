#include <iostream>
#define MOD 1000000007
using namespace std;

typedef long long ll;

int M;
ll N[10000];
ll S[10000];

ll pow(ll x, ll y)
{
    ll res = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y % 2 == 1)
        {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return res;
}

int main()
{
    cin >> M;
    ll result = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> N[i] >> S[i];
    }
    for (int i = 0; i < M; i++)
    {
        ll invN = pow(N[i], MOD - 2);
        result = (result + (S[i] * invN) % MOD) % MOD;
    }
    cout << result;
}