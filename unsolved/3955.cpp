#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll solve(ll a, ll b)
{
    ll r0 = a;
    ll r1 = b;
    ll s0 = 1;
    ll s1 = 0;
    ll t0 = 0;
    ll t1 = 1;
    ll temp;
    ll q;
    while (r1)
    {
        q = r0 / r1;
        temp = r0;
        r0 = r1;
        r1 = temp - q * r1;
        temp = s0;
        s0 = s1;
        s1 = temp - q * s1;
        temp = t0;
        t0 = t1;
        t1 = temp - q * t1;
    }

    return t0;
}

int main()
{
    ll t, K, C;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        cin >> K >> C;
        if (gcd(K, C) != 1)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        ll y0 = solve(K, C);
        if (y0 < 0)
        {
            ll k = (-y0 + K - 1) / K;
            y0 += k * K;
        }
        if (y0 > 1e9)
        {
            cout << "IMPOSSIBLE\n";
        }
        else
        {
            cout << y0 << "\n";
        }
    }
}