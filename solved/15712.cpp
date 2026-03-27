#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll a, r, n, mod;

// x ^ b
ll fastPower(ll x, ll b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return x % mod;
    }

    ll half = fastPower(x, b / 2) % mod;
    if (b % 2 == 0)
    {
        return (half * half) % mod;
    }
    else
    {
        return ((half * half) % mod * x) % mod;
    }
}

ll geo_sum(ll N)
{
    if (N == 0)
    {

        return 0;
    }
    if (N == 1)
    {
        return 1;
    }
    ll half = geo_sum(N / 2);
    ll power = fastPower(r, N / 2);

    if (N % 2 == 0)
    {
        return (half + (half * power) % mod) % mod;
    }
    else
    {
        return (geo_sum(N - 1) % mod + fastPower(r, N - 1) % mod) % mod;
    }
}

void solve()
{
    cout << ((a % mod) * (geo_sum(n) % mod)) % mod;
}

int main()
{
    cin >> a >> r >> n >> mod;
    solve();
}