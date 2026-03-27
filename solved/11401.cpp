#include <iostream>
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll pow(ll x, ll y)
{
    ll res = 1;
    x = x % MOD;
    while (y)
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

ll fact(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return (n * fact(n - 1)) % MOD;
}

int main()
{
    ll N, K;
    cin >> N >> K;

    ll res = fact(N);
    ll toMul = (fact(K) * fact(N - K)) % MOD;
    toMul = pow(toMul, MOD - 2);
    res = (res * toMul) % MOD;
    cout << res;
}