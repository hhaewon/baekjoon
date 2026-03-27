#include <iostream>

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

pair<ll, ll> exEuclid(ll a, ll b)
{
    ll s0 = 1;
    ll s1 = 0;
    ll t0 = 0;
    ll t1 = 1;
    ll r0 = a;
    ll r1 = b;
    ll q;
    ll temp;
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
    return {s0, t0};
}

int main()
{
    ll N, A;
    cin >> N >> A;
    cout << N - A;
    if (gcd(N, A) != 1)
    {
        cout << " " << "-1";
    }
    else
    {
        pair<ll, ll> result = exEuclid(A, N);
        cout << " " << (result.first + N) % N;
    }
}