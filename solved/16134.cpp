#include <iostream>
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll mpow(ll x, ll y)
{
    x = x % MOD;
    ll res = 1;
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

ll fact(ll n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return (n * fact(n - 1)) % MOD;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    ll N, R;
    cin >> N >> R;
    ll result = (fact(N) * mpow(fact(R), MOD - 2) % MOD) * mpow(fact(N - R), MOD - 2) % MOD;
    cout << result;
}